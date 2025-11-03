//

#include "stdafx.h"



#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include <dbents.h>
#include <dbapserv.h>
#include "adscodes.h"

void initApp();
void unloadApp();
void drawLine();
void ModLine();
void EraseLine();

void initApp()
{	
	acedRegCmds->addCommand(_T("DRAWLINE_COMMANDS"),
							_T("DLine"),
							_T("DLine"),
							ACRX_CMD_TRANSPARENT,
							drawLine);
	acedRegCmds->addCommand(_T("DRAWLINE_COMMANDS"),
		_T("ModLine"),
		_T("ModLine"),
		ACRX_CMD_TRANSPARENT,
		ModLine);
	acedRegCmds->addCommand(_T("DRAWLINE_COMMANDS"),
		_T("EraseLine"),
		_T("EraseLine"),
		ACRX_CMD_TRANSPARENT,
		EraseLine);
}

void unloadApp()
{ 
	acedRegCmds->removeGroup(_T("DRAWLINE_COMMANDS"));
}

void drawLine()
{ 
	AcGePoint3d startPt(4.0, 2.0, 0.0);
	AcGePoint3d endPt(10.0, 7.0, 0.0);
	AcDbLine *pLine = new AcDbLine(startPt, endPt);

	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable, AcDb::kForRead);

	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord,	AcDb::kForWrite);
	pBlockTable->close();

	AcDbObjectId lineId;
	pBlockTableRecord->appendAcDbEntity(lineId, pLine);

	pBlockTableRecord->close();
	pLine->close();
}

// ModLine
void ModLine()
{
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	if (pDb == NULL)
	{
		return;
	}

	AcDbBlockTable* pBlockTable = NULL;
	if (pDb->getSymbolTable(pBlockTable, AcDb::kForRead) != Acad::eOk)
	{
		return;
	}

	AcDbBlockTableRecord* pBlockRec = NULL;
	if (pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockRec, AcDb::kForRead) != Acad::eOk)
	{
		pBlockTable->close();
		return;
	}

	AcDbBlockTableRecordIterator * pIterator = NULL;
	pBlockRec->newIterator(pIterator);
	pBlockRec->close();
	pBlockTable->close();

	for (; !pIterator->done(); pIterator->step())
	{
		AcDbEntity * pEntity = NULL;
		Acad::ErrorStatus esGet = pIterator->getEntity(pEntity, AcDb::kForWrite);
		if (esGet != Acad::eOk)
		{
			return;
		}

		if (!pEntity->isKindOf(AcDbLine::desc()))
		{
			pEntity->close();
			return;
		}

		AcDbLine* pLine = (AcDbLine*)pEntity;
		pLine->setStartPoint(AcGePoint3d(0, 100, 0));
		pLine->setEndPoint(AcGePoint3d(100, 0, 0));

		pEntity->close();
	}
}

// EraseLine
void EraseLine()
{
	AcDbObjectId oId;
	ads_name ent;
	ads_point pt;
	if (acedEntSel(_T("\nSelect AcDbLine:"), ent, pt) != RTNORM)
	{
		return;
	}
	acdbGetObjectId(oId, ent);

	AcDbEntity* pEnt = nullptr;
	if (Acad::eOk != acdbOpenObject(pEnt, oId, AcDb::kForWrite))
		return;

	if (!pEnt->isKindOf(AcDbLine::desc()))
	{
		pEnt->close();
		return;
	}

	pEnt->erase();
	pEnt->close();
}

extern "C" AcRx::AppRetCode
zcrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxRegisterAppMDIAware(pkt);
		initApp();
		break;
	case AcRx::kUnloadAppMsg:
		unloadApp();
		break;
	default:
		break;
	}
	return AcRx::kRetOK;
}
