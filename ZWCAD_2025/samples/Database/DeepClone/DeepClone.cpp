#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "adscodes.h"
#include "dbapserv.h"
#include "dbsymtb.h"
#include "dbidmap.h"
#include "acestext.h"
#include "migrtion.h"

void initApp();
void unloadApp();

void DeepCloneDiffOwnerObjects();
void wblockSample();
void wblockCloneObjectsSample();

void initApp()
{ 
	acedRegCmds->addCommand(_T("DEEPCLONE_COMMANDS"), _T("DeepCloneDiffOwnerObjects"), _T("DeepCloneDiffOwnerObjects"), ACRX_CMD_MODAL, DeepCloneDiffOwnerObjects);
	acedRegCmds->addCommand(_T("DEEPCLONE_COMMANDS"), _T("wblockSample"), _T("wblockSample"), ACRX_CMD_MODAL, wblockSample);
	acedRegCmds->addCommand(_T("DEEPCLONE_COMMANDS"), _T("wblockCloneObjectsSample"), _T("wblockCloneObjectsSamples"), ACRX_CMD_MODAL, wblockCloneObjectsSample);
}

void unloadApp()
{ 
	acedRegCmds->removeGroup(_T("DEEPCLONE_COMMANDS"));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Deepclone sample

void DeepCloneDiffOwnerObjects()
{
	ads_name sssetMS, sssetPS;
	AdInt32 lengthMS = 0, lengthPS = 0;
	const ACHAR* promptPtrs1[2] = { _T("\nSelect entities to clone(clone to the model space): ") , _T("") };
	const ACHAR* promptPtrs2[2] = { _T("\nSelect entities to clone(clone to the paper space): "), _T("") };

	if (RTNORM != acedSSGet(_T(":$"), promptPtrs1, NULL, NULL, sssetMS))
		return;
	acedSSLength(sssetMS, &lengthMS);

	if (RTNORM != acedSSGet(_T(":$"), promptPtrs2, NULL, NULL, sssetPS))
		return;
	acedSSLength(sssetPS, &lengthPS);

	AcDbObjectId ownerId = AcDbObjectId::kNull;
	AcDbObjectIdArray idListMS;
	for (int i = 0; i < lengthMS; i++)
	{
		ads_name ent;
		acedSSName(sssetMS, i, ent);
		AcDbObjectId objId;
		acdbGetObjectId(objId, ent);

		AcDbObject* pObj = NULL;
		acdbOpenObject(pObj, objId, AcDb::kForRead);
		if (pObj->ownerId() == ownerId)
		{
			idListMS.append(objId);
		}
		else if (i == 0)
		{
			ownerId = pObj->ownerId();
			idListMS.append(objId);
		}
		pObj->close();
	}
	acedSSFree(sssetMS);

	ownerId = AcDbObjectId::kNull;
	AcDbObjectIdArray idListPS;
	for (int i = 0; i < lengthPS; i++)
	{
		ads_name ent;
		acedSSName(sssetPS, i, ent);
		AcDbObjectId objId;
		acdbGetObjectId(objId, ent);

		AcDbObject* pObj = NULL;
		acdbOpenObject(pObj, objId, AcDb::kForRead);
		if (pObj->ownerId() == ownerId)
		{
			idListPS.append(objId);
		}
		else if (i == 0)
		{
			ownerId = pObj->ownerId();
			idListPS.append(objId);
		}
		pObj->close();
	}
	acedSSFree(sssetPS);

	AcDbBlockTable* pBlockTable = NULL;
	acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable, AcDb::kForRead);
	AcDbObjectId modelSpaceId, paperSpaceId;
	pBlockTable->getAt(ACDB_MODEL_SPACE, modelSpaceId);
	pBlockTable->getAt(ACDB_PAPER_SPACE, paperSpaceId);
	pBlockTable->close();

	AcDbIdMapping idMap;
	acdbHostApplicationServices()->workingDatabase()->deepCloneObjects(idListMS, modelSpaceId, idMap);
	acdbHostApplicationServices()->workingDatabase()->deepCloneObjects(idListPS, paperSpaceId, idMap);

	AcDbIdMappingIter iter(idMap);
	for (iter.start(); !iter.done(); iter.next())
	{
		AcDbIdPair idPair;
		iter.getMap(idPair);
		if (!idPair.isCloned())
		{
			continue;
		}

		acutPrintf(_T("\nID of object£º%Ld"), idPair.value().asOldId());
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Wblock samples

void getMsEnts(AcDbDatabase* pDb, AcDbObjectIdArray& ids)
{
	AcDbBlockTable* pTbl = NULL;
	pDb->getBlockTable(pTbl, AcDb::kForRead);
	if (pTbl)
	{
		AcDbBlockTableRecord* pBtr = NULL;
		pTbl->getAt(ACDB_MODEL_SPACE, pBtr, AcDb::kForRead);
		if (pBtr)
		{
			AcDbBlockTableRecordIterator* pItr = NULL;
			pBtr->newIterator(pItr);
			if (pItr)
			{
				for (pItr->start(); !pItr->done(); pItr->step())
				{
					AcDbObjectId id;
					if (Acad::eOk == pItr->getEntityId(id))
					{
						ids.append(id);
					}
				}
				delete pItr;
				pItr = NULL;
			}
			pBtr->close();
		}
		pTbl->close();
	}
}

void wblockSample()
{
	// step1: choose dwg to wblock
	resbuf* rb = acutNewRb(RTSTR);
	if (RTNORM != acedGetFileD(_T("Choose the dwg file"), NULL, _T("dwg"), 0, rb))
	{
		return;
	}
	ACHAR result[MAX_PATH];
	if (RTNORM == acedFindFile(rb->resval.rstring, result))
	{
		AcDbDatabase* pDb = new AcDbDatabase(false, true); // should use null database, or wblock returns ePermanentlyErased
		Acad::ErrorStatus es = pDb->readDwgFile(result);

		// step2: Get the entity set in model space
		AcDbObjectIdArray ids;
		getMsEnts(pDb, ids);

		// step3: wblock to the target db
		AcDbDatabase* pDestDb = NULL;
		es = pDb->wblock(pDestDb, ids, AcGePoint3d::kOrigin);
		if (es == Acad::eOk)
		{
			acutPrintf(_T("\n%d entities are imported."), ids.length());
		}
		else
		{
			delete pDb;
			delete pDestDb;
			acutRelRb(rb);
			acutPrintf(_T("\nError: %s"), acadErrorStatusText(es));
			return;
		}

		// step4: save the target db as dwg file
		CString strToDwgFilePath;
		TCHAR szDocPath[MAX_PATH] = { 0 };
		SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, szDocPath);
		strToDwgFilePath.Format(_T("%s\\TestWblock.dwg"), szDocPath);  // C:\Users\...\Documents\TestWblock.dwg

		es = pDestDb->saveAs(strToDwgFilePath);
		if (es != Acad::eOk)
		{
			acutPrintf(_T("\nSave faild, error: %s"), acadErrorStatusText(es));
		}
		else
		{
			acutPrintf(_T("\nThe new dwg path: %s"), strToDwgFilePath.GetString());
		}

		delete pDb;
		delete pDestDb;
	}
	acutRelRb(rb);
}

void wblockCloneObjectsSample()
{
	AcDbBlockTable* pTbl = NULL;
	acdbCurDwg()->getBlockTable(pTbl, AcDb::kForRead);
	if (pTbl)
	{
		AcDbObjectId msId;
		pTbl->getAt(ACDB_MODEL_SPACE, msId);
		pTbl->close();

		resbuf* rb = acutNewRb(RTSTR);
		if (RTNORM != acedGetFileD(_T("Choose the dwg file"), NULL, _T("dwg"), 0, rb))
		{
			return;
		}
		ACHAR result[MAX_PATH];
		if (RTNORM == acedFindFile(rb->resval.rstring, result))
		{
			AcDbDatabase* pDb = new AcDbDatabase();
			pDb->readDwgFile(result);

			// Get entity set in model space
			AcDbObjectIdArray ids;
			getMsEnts(pDb, ids);

			// wblockCloneObjects to current db
			AcDbIdMapping idMap;
			Acad::ErrorStatus es = acdbCurDwg()->wblockCloneObjects(ids, msId, idMap, AcDb::kDrcReplace);
			if (es == Acad::eOk)
			{
				acutPrintf(_T("\n%d entities are imported."), ids.length());
			}
			else
			{
				acutPrintf(_T("\nError: %s"), acadErrorStatusText(es));
			}

			delete pDb;
			pDb = NULL;
		}
		acutRelRb(rb);
	}

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


