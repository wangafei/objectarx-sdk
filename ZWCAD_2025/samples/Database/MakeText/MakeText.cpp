#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "dbapserv.h"
#include "dbsymtb.h"
#include "dbents.h"
#include "AcApDMgr.h"

void initApp();
void unloadApp();

void TextSample();
void MTextSample();
void TextStyleSample();

void initApp()
{ 
	acedRegCmds->addCommand(_T("MAKETEXT_COMMANDS"), _T("TextSample"), _T("TextSample"), ACRX_CMD_MODAL, TextSample);
	acedRegCmds->addCommand(_T("MAKETEXT_COMMANDS"), _T("MTextSample"), _T("MTextSample"), ACRX_CMD_MODAL, MTextSample);
	acedRegCmds->addCommand(_T("MAKETEXT_COMMANDS"), _T("TextStyleSample"), _T("TextStyleSample"), ACRX_CMD_MODAL, TextStyleSample);
}


void unloadApp()
{ 
	acedRegCmds->removeGroup(_T("MAKETEXT_COMMANDS"));
}


AcDbObjectId AppendEntityToModelSpace(AcDbEntity* pEntity)
{
	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBlockTable, AcDb::kForRead);
	AcDbBlockTableRecord *pBlockTableRecord;

	pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord, AcDb::kForWrite);
	AcDbObjectId entId;
	pBlockTableRecord->appendAcDbEntity(entId, pEntity);
	pBlockTable->close();
	pBlockTableRecord->close();
	return entId;
}

void TextSample()
{
	AcDbTextStyleTable* pTbl = NULL;
	Acad::ErrorStatus es = acdbHostApplicationServices()->workingDatabase()->getTextStyleTable(pTbl, AcDb::kForWrite);
	if (Acad::eOk != es)
	{
		return;
	}
	AcDbTextStyleTableRecord* pRec = NULL;
	es = pTbl->getAt(_T("Standard"), pRec, AcDb::kForWrite);
	if (Acad::eOk != es)
	{
		return;
	}
	pTbl->close();

	AcDbText* pText = new AcDbText();
	pText->setPosition(AcGePoint3d(0, 0, 0));
	pText->setHeight(50);
	pText->setRotation(0);
	pText->setTextString(_T("TextSapmle"));
	pText->setHorizontalMode(AcDb::kTextLeft);
	pText->setVerticalMode(AcDb::kTextTop);
	pText->setTextStyle(pRec->objectId());
	AppendEntityToModelSpace(pText);
	pRec->close();
	pText->close();
}

void MTextSample()
{
	AcDbTextStyleTable* pTbl = NULL;
	Acad::ErrorStatus es = acdbHostApplicationServices()->workingDatabase()->getTextStyleTable(pTbl, AcDb::kForRead);
	if (Acad::eOk != es)
	{
		return;
	}
	AcDbTextStyleTableRecord* pRec = NULL;
	es = pTbl->getAt(_T("Standard"), pRec, AcDb::kForRead);
	if (Acad::eOk != es)
	{
		return;
	}
	pTbl->close();

	AcDbMText* pMText = new AcDbMText();
	pMText->setContents(_T("MTextSample"));
	pMText->setTextStyle(pRec->objectId());
	pMText->setLocation(AcGePoint3d(0, 50, 0));
	pMText->setTextHeight(50);
	pMText->setRotation(0);
	pMText->setAttachment(ZcDbMText::kMiddleLeft);
	pMText->setWidth(200);
	pMText->setHeight(100);
	AppendEntityToModelSpace(pMText);
	pRec->close();
	pMText->close();
}

void TextStyleSample()
{
	AcDbDatabase* pDb = curDoc()->database();
	AcDbTextStyleTable* pTextStyleTable = NULL;
	pDb->getTextStyleTable(pTextStyleTable, AcDb::kForRead);
	if (pTextStyleTable && pTextStyleTable->has(_T("new TextStyle")))
	{
		AcDbTextStyleTableIterator* pIter = NULL;
		pTextStyleTable->newIterator(pIter);
		AcDbTextStyleTableRecord* pRecord = NULL;
		for (pIter->start(); !pIter->done(); pIter->step())
		{
			pIter->getRecord(pRecord, AcDb::kForWrite);
			if (pRecord)
			{
				AcString strName;
				pRecord->getName(strName);
				if (strName == _T("new TextStyle"))
				{
					pRecord->setName(_T("Mod TextStyle"));
					pRecord->setFileName(_T("simplex"));
					pRecord->setBigFontFileName(_T(""));
					pRecord->setTextSize(5);
				}
			}
			pRecord->close();
		}
	}
	else
	{
		AcDbTextStyleTableRecord* pRecord = new AcDbTextStyleTableRecord();
		pRecord->setName(_T("new TextStyle"));
		pRecord->setFileName(_T("txt"));
		pRecord->setBigFontFileName(_T("GBCBIG"));
		pRecord->setTextSize(10);
		pTextStyleTable->upgradeOpen();
		pTextStyleTable->add(pRecord);
		pRecord->close();
	}
	pTextStyleTable->close();
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


