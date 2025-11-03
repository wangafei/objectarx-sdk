#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "adscodes.h"
#include "acestext.h"
#include "dbsymtb.h"
#include "dbents.h"
#include "dbapserv.h"
#include "dbidmap.h"
#include "lngtrans.h"
#include "dbltrans.h"

void initApp();
void unloadApp();

void RefEdit();

void initApp()
{ 
	acedRegCmds->addCommand(_T("TRANSACTION_COMMANDS"), _T("Test_LongTransRefEdit"), _T("Test_LongTransRefEdit"), ACRX_CMD_MODAL, RefEdit);
}

void unloadApp()
{ 
	acedRegCmds->removeGroup(_T("TRANSACTION_COMMANDS"));
}

void RefEdit()
{
	AcDbObjectId objectId;

	// Choose external dwg file
	//
	struct resbuf* res = acutNewRb(RTSTR);
	if (RTNORM != acedGetFileNavDialog(_T("Choose the dwg file"), NULL, _T("dwg"), NULL, 0, &res) || !res)
	{
		acutPrintf(_T("\nPlease select a drawing."));
		return;
	}

	// Read database
	//
	ACHAR filename[MAX_PATH];
	if (RTNORM != acedFindFile(res->resval.rstring, filename, MAX_PATH))
	{
		acutRelRb(res);
		return;
	}
	acutRelRb(res);

	Acad::ErrorStatus es = Acad::eOk;
	AcDbDatabase* db = new AcDbDatabase(FALSE);
	if (Acad::eOk != (es = db->readDwgFile(filename)))
	{
		acutPrintf(_T("\nFailed to open drawing, error: %s"), acadErrorStatusText(es));
		delete db;
		db = NULL;
		return;
	}

	// Get all the circles in the dwg and add them to the array
	//
	AcDbObjectIdArray objIdArray;
	AcDbBlockTable* pBlockTable = NULL;
	AcDbBlockTableRecord* pBlockTableRecord = NULL;

	if (Acad::eOk != (es = db->getBlockTable(pBlockTable, AcDb::kForRead)))
	{
		delete db;
		db = NULL;
		return;
	}

	if (Acad::eOk != (es = pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord, AcDb::kForRead)))
	{
		pBlockTable->close();
		delete db;
		db = NULL;
		return;
	}

	pBlockTable->close();

	AcDbBlockTableRecordIterator* pIter = NULL;
	pBlockTableRecord->newIterator(pIter);
	for (pIter->start(); pIter && !pIter->done(); pIter->step())
	{
		AcDbEntity* pEnt = NULL;

		if (Acad::eOk == (es = pIter->getEntity(pEnt, AcDb::kForWrite)))
		{
			if (pEnt->isKindOf(AcDbCircle::desc()))
			{
				objIdArray.append(pEnt->objectId());
			}
			pEnt->close();
		}
	}
	delete pIter;
	pBlockTableRecord->close();

	if (objIdArray.isEmpty())
	{
		acutPrintf(_T("\nThere is no circle object in this drawing. You must select a drawing containing a circle."));
		delete db;
		db = NULL;
		return;
	}

	// Current databse
	AcDbBlockTable* pThisBlockTable = NULL;
	acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pThisBlockTable, AcDb::kForRead);
	AcDbBlockTableRecord* pRecord = NULL;
	pThisBlockTable->getAt(ACDB_MODEL_SPACE, pRecord, AcDb::kForRead);
	pThisBlockTable->close();
	AcDbObjectId objId = pRecord->objectId();
	pRecord->close();

	// Create long transaction
	AcDbIdMapping idMapping;
	AcDbObjectId transId;
	es = acapLongTransactionManagerPtr()->checkOut(transId, objIdArray, objId, idMapping);

	// Modify property of entity
	int colorindex = 0;
	if (acedGetInt(_T("\nEnter the color you want to change to(default 0):"), &colorindex) != RTNORM)
	{
		delete db;
		db = NULL;
		return;
	}

	AcDbObject* pObj = NULL;
	if (acdbOpenObject(pObj, transId, AcDb::kForRead) == Acad::eOk)
	{
		AcDbLongTransaction* pLongTranscation = AcDbLongTransaction::cast(pObj);
		if (pLongTranscation != NULL)
		{
			AcDbLongTransWorkSetIterator* pWorkIter = NULL;
			pLongTranscation->newWorkSetIterator(pWorkIter);

			// set color
			for (pWorkIter->start(); !pWorkIter->done(); pWorkIter->step())
			{
				AcDbEntity* pEntity = NULL;
				acdbOpenAcDbEntity(pEntity, pWorkIter->objectId(), AcDb::kForWrite);
				pEntity->setColorIndex(colorindex);
				pEntity->close();
			}
			delete pWorkIter;
		}
		pObj->close();
	}

	// Pause to show this change
	ACHAR str[32] = { 0 };
	acedGetString(0, _T("\nCheck the circle after changing the color and press Enter to return"), str);

	// Put the entity back into the original database
	es = acapLongTransactionManagerPtr()->checkIn(transId, idMapping);

	es = db->saveAs(filename);

	delete db;
	db = NULL;
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


