#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "dbents.h"
#include "dbapserv.h"
#include "adscodes.h"

#define _PI 3.14159265358979323846
struct BlkRefParam
{
	TCHAR szBlockName[1024] = { 0 };
	AcGePoint3d ptPos = AcGePoint3d(0, 0, 0);
	double dRotation = 0.0;
	double dScale = 1.0;
	bool bAddAttDef = false;
};
void initApp();
void unloadApp();
AcDbObjectId createBlock(TCHAR* szBlockName);
void getSelEntArray(AcDbObjectIdArray& objIds);
void appendEntityToBlock(TCHAR* szBlockName, AcDbObjectIdArray& objIds);
void insertBlock(struct BlkRefParam blkRefParam);
void createBlockTest1();
void createBlockTest2();
void insertBlockTest();

void initApp()
{ 
	acedRegCmds->addCommand(_T("INSERTBLOCK_COMMANDS"), _T("createBlockTest1"), _T("createBlockTest1"), ACRX_CMD_MODAL, createBlockTest1);
	acedRegCmds->addCommand(_T("INSERTBLOCK_COMMANDS"), _T("createBlockTest2"), _T("createBlockTest2"), ACRX_CMD_MODAL, createBlockTest2);
	acedRegCmds->addCommand(_T("INSERTBLOCK_COMMANDS"), _T("insertBlockTest"), _T("insertBlockTest"), ACRX_CMD_MODAL, insertBlockTest);
}


void unloadApp()
{ 
	acedRegCmds->removeGroup(_T("INSERTBLOCK_COMMANDS"));
}


AcDbObjectId createBlock(TCHAR* szBlockName)
{
	AcDbDatabase* pDatabase = acdbHostApplicationServices()->workingDatabase();

	AcDbBlockTable* pBlockTable = NULL;
	AcDbBlockTableRecord* pBlockTableRecord = NULL;
	AcDbObjectId newRecId;
	pDatabase->getBlockTable(pBlockTable, AcDb::kForRead);

	if (pBlockTable->has(szBlockName))
	{
		pBlockTable->getAt(szBlockName, pBlockTableRecord, AcDb::kForWrite);
		if (!pBlockTableRecord)
		{
			pBlockTable->close();
			return newRecId;
		}

		newRecId = pBlockTableRecord->objectId();

		AcDbBlockTableRecordIterator* pIter = NULL;
		pBlockTableRecord->newIterator(pIter);

		for (; !pIter->done(); pIter->step())
		{
			AcDbEntity* pEnt = NULL;
			pIter->getEntity(pEnt, AcDb::kForWrite);
			if (pEnt)
			{
				pEnt->erase();
				pEnt->close();
			}
		}
		delete pIter;
	}
	else
	{
		pBlockTableRecord = new AcDbBlockTableRecord();
		pBlockTableRecord->setName(szBlockName);
		pBlockTable->upgradeOpen();
		pBlockTable->add(newRecId, pBlockTableRecord);
	}

	pBlockTable->close();
	pBlockTableRecord->close();

	return newRecId;
}

void getSelEntArray(AcDbObjectIdArray& objIds)
{
	ads_name selSet;
	TCHAR* prompt[2] = { _T("Select some entities:"),_T("") };
	int nRet = acedSSGet(_T(":$"), prompt, NULL, NULL, selSet);
	if (nRet != RTNORM)
		return;

	Adesk::Int32 len = 0;
	AcDbObjectId objId;
	ads_name entName;
	nRet = acedSSLength(selSet, &len);
	if (nRet != RTNORM)
	{
		acedSSFree(selSet);
		return;
	}
	for (int i = 0; i < len; i++)
	{
		acedSSName(selSet, i, entName);
		if (acdbGetObjectId(objId, entName) != Acad::eOk)
			continue;
		objIds.append(objId);
	}
	acedSSFree(selSet);
}

void appendEntityToBlock(TCHAR* szBlockName, AcDbObjectIdArray& objIds)
{
	AcDbObjectId btRecId;
	Acad::ErrorStatus es(Acad::eOk);
	btRecId = createBlock(szBlockName);
	if (btRecId.isNull())
		return;
	AcDbDatabase* pDatabase = acdbHostApplicationServices()->workingDatabase();
	AcDbBlockTable* pBlockTable = NULL;
	es = pDatabase->getBlockTable(pBlockTable, AcDb::kForWrite);
	AcDbBlockTableRecord* pBlockTableRecord = NULL;
	es = pBlockTable->getAt(szBlockName, pBlockTableRecord, AcDb::kForWrite);
	AcDbExtents extAll;
#if 0 
	AcDbIdMapping idMap;
	AcDbIdPair idPair;
	AcDbObjectId srcId;
	AcDbObjectId cloneId;
	AcDbIdMappingIter mapIter(idMap);
	es = pDatabase->deepCloneObjects(objIds, btRecId, idMap);
	for (mapIter.start(); !mapIter.done(); mapIter.next())
	{
		mapIter.getMap(idPair);
		if (!idPair.isCloned() || !idPair.isPrimary())
			continue;
		srcId = idPair.key();
		cloneId = idPair.value();
		if (cloneId.isNull() || srcId.isErased())
			continue;
		AcDbEntity* pSrcEntity = NULL;
		AcDbEntity* pCloneEntity = NULL;

		acdbOpenAcDbEntity(pSrcEntity, srcId, AcDb::kForWrite);
		acdbOpenAcDbEntity(pCloneEntity, cloneId, AcDb::kForWrite);

		AcDbExtents curExt;
		pCloneEntity->getGeomExtents(curExt);
		extAll.addExt(curExt);

		pSrcEntity->erase();
		if (pSrcEntity)
			pSrcEntity->close();
		if (pCloneEntity)
			pCloneEntity->close();
	}
#else
	for (int i = 0; i < objIds.length(); i++)
	{
		AcDbEntity* pSubEnt = NULL;
		if (Acad::eOk == acdbOpenAcDbEntity(pSubEnt, objIds[i], AcDb::kForWrite))
		{
			pSubEnt->erase();
			AcDbEntity* pEnt = AcDbEntity::cast(pSubEnt->clone());
			AcDbExtents curExt;
			pEnt->getGeomExtents(curExt);
			extAll.addExt(curExt);
			pBlockTableRecord->appendAcDbEntity(pEnt);
			pEnt->close();
		}
		if (pSubEnt)
			pSubEnt->close();
	}
#endif

	AcGePoint3d ptMinExt(extAll.minPoint());
	AcGePoint3d ptMaxExt(extAll.maxPoint());
	AcGePoint3d ptCenter(ptMinExt.x / 2 + ptMaxExt.x / 2, ptMinExt.y / 2 + ptMaxExt.y / 2, ptMinExt.z / 2 + ptMaxExt.z / 2);
	pBlockTableRecord->setOrigin(ptMinExt);

	AcDbAttributeDefinition* pAttDef = new AcDbAttributeDefinition();
	pAttDef->setAlignmentPoint(ptMinExt);
	pAttDef->setTag(_T("AttTag"));
	pAttDef->setTextString(_T("AAAAA"));
	pAttDef->setColorIndex(1);
	pAttDef->setHeight(ptMinExt.distanceTo(ptMaxExt) / 10);
	pAttDef->setPosition(ptCenter);
	pBlockTableRecord->appendAcDbEntity(pAttDef);
	pAttDef->close();

	pBlockTableRecord->close();

	//Add to ModelSpace
	AcDbBlockTableRecord* pMSBlockTableRecord = NULL;
	AcDbObjectId recId;

	es = pBlockTable->getAt(szBlockName, recId);
	es = pBlockTable->getAt(ACDB_MODEL_SPACE, pMSBlockTableRecord, AcDb::kForWrite);

	AcDbBlockReference* pBlkRef = new AcDbBlockReference();
	pBlkRef->setDatabaseDefaults();
	pBlkRef->setBlockTableRecord(recId);
	pBlkRef->setPosition(pBlockTableRecord->origin());

	//You can traverse the BlockTableTecord to get AcDbAttributeDefinition
	AcDbAttribute* pAtt = new AcDbAttribute();
	pAtt->setPropertiesFrom(pAttDef);
	pAtt->setAlignmentPoint(pAttDef->alignmentPoint());
	pAtt->setTag(pAttDef->tag());
	pAtt->setTextString(pAttDef->textString());
	pAtt->setColorIndex(pAttDef->colorIndex());
	pAtt->setHeight(pAttDef->height());
	pAtt->setPosition(pAttDef->position());
	pBlkRef->appendAttribute(pAtt);
	pAtt->close();

	es = pMSBlockTableRecord->appendAcDbEntity(recId, pBlkRef);

	if (pBlockTable)
		pBlockTable->close();

	pMSBlockTableRecord->close();
	pBlkRef->close();
}

void insertBlock(struct BlkRefParam blkRefParam)
{
	TCHAR* szBlockName = blkRefParam.szBlockName;
	AcGePoint3d ptPos = blkRefParam.ptPos;
	double dRotation = blkRefParam.dRotation;
	double dScale = blkRefParam.dScale;

	Acad::ErrorStatus es;
	AcDbDatabase* pDatabase = acdbHostApplicationServices()->workingDatabase();

	AcDbBlockTable* pBlockTable = NULL;
	AcDbBlockTableRecord* pMSBlockTableRecord = NULL;
	AcDbObjectId newBlkRecId;
	es = pDatabase->getBlockTable(pBlockTable, AcDb::kForWrite);

	if (!pBlockTable->has(szBlockName))
	{
		acutPrintf(_T("\nThe Block doesn't exist!"));
		pBlockTable->close();
		return;
	}

	es = pBlockTable->getAt(szBlockName, newBlkRecId);
	es = pBlockTable->getAt(ACDB_MODEL_SPACE, pMSBlockTableRecord, AcDb::kForWrite);
	pBlockTable->close();

	AcDbBlockReference* pBlkRef = new AcDbBlockReference();
	pBlkRef->setDatabaseDefaults();
	pBlkRef->setBlockTableRecord(newBlkRecId);
	pBlkRef->setPosition(ptPos);
	pBlkRef->setRotation(dRotation);
	pBlkRef->setScaleFactors(dScale);

	AcDbBlockTableRecord* pNewBlkRec = NULL;
	es = pBlockTable->getAt(szBlockName, pNewBlkRec, AcDb::kForRead);

	if (pNewBlkRec->hasAttributeDefinitions())
	{
		AcDbBlockTableRecordIterator* pNewRecIter = NULL;
		pNewBlkRec->newIterator(pNewRecIter);
		for (; !pNewRecIter->done(); pNewRecIter->step())
		{
			AcDbEntity* pEnt = NULL;
			pNewRecIter->getEntity(pEnt, AcDb::kForRead);
			if (!pEnt)
				continue;
			if (pEnt->isKindOf(AcDbAttributeDefinition::desc()))
			{
				AcGeMatrix3d matBlkRefTrans = pBlkRef->blockTransform();
				AcDbAttributeDefinition* pAttDef = AcDbAttributeDefinition::cast(pEnt);

				AcDbAttribute* pAtt = new AcDbAttribute();
				pAtt->setAttributeFromBlock(pAttDef, matBlkRefTrans);

				pBlkRef->appendAttribute(pAtt);
				pAtt->close();
			}
		}
		delete pNewRecIter;
	}
	pNewBlkRec->close();

	if (blkRefParam.bAddAttDef)
	{
		//Special AcDbAttribute, Only in BlockReference, not in BlockTableRecord
		AcDbAttribute* pAttOnlyInRef = new AcDbAttribute();
		pAttOnlyInRef->setAlignmentPoint(pMSBlockTableRecord->origin());
		pAttOnlyInRef->setTag(_T("OnlyInRef"));
		pAttOnlyInRef->setTextString(_T("OnlyInRef"));
		pAttOnlyInRef->setHeight(30);
		pBlkRef->appendAttribute(pAttOnlyInRef);
		pAttOnlyInRef->close();
	}

	es = pMSBlockTableRecord->appendAcDbEntity(newBlkRecId, pBlkRef);

	pMSBlockTableRecord->close();
	pBlkRef->close();
}

void createBlockTest1()
{
	AcDbDatabase* pDatabase = acdbHostApplicationServices()->workingDatabase();

	Acad::ErrorStatus es;
	AcDbBlockTable* pBlockTable = NULL;
	AcDbBlockTableRecord* pBlockTableRecord = NULL;

	TCHAR szBlock1[20] = _T("szBlock1");

	es = pDatabase->getBlockTable(pBlockTable, AcDb::kForWrite);

	if (pBlockTable->has(szBlock1))
	{
		pBlockTable->close();
		acutPrintf(_T("\nBlock already exist!"));
		return;
	}
	else
	{
		pBlockTableRecord = new AcDbBlockTableRecord();
		pBlockTableRecord->setName(szBlock1);
		pBlockTableRecord->setOrigin(AcGePoint3d(1000, 1000, 0));
		pBlockTable->add(pBlockTableRecord);

		AcDbCircle* pCircle = new AcDbCircle(AcGePoint3d(1000, 1000, 0), AcGeVector3d::kZAxis, 200);
		pBlockTableRecord->appendAcDbEntity(pCircle);
		pCircle->close();

		AcDbLine* pLine1 = new AcDbLine(AcGePoint3d(1000, 750, 0), AcGePoint3d(1000, 1250, 0));
		pBlockTableRecord->appendAcDbEntity(pLine1);
		pLine1->close();

		AcDbLine* pLine2 = new AcDbLine(AcGePoint3d(750, 1000, 0), AcGePoint3d(1250, 1000, 0));
		pBlockTableRecord->appendAcDbEntity(pLine2);
		pLine2->close();

		AcDbBlockTableRecord* pMSBlockTableRecord = NULL;
		es = pBlockTable->getAt(ACDB_MODEL_SPACE, pMSBlockTableRecord, AcDb::kForWrite);
		pBlockTable->close();

		AcDbBlockReference* pBlkRef = new AcDbBlockReference();
		pBlkRef->setDatabaseDefaults();
		pBlkRef->setBlockTableRecord(pBlockTableRecord->objectId());
		pBlkRef->setPosition(pBlockTableRecord->origin());
		pBlkRef->setScaleFactors(1.0);
		pBlkRef->setRotation(0.0);

		es = pMSBlockTableRecord->appendAcDbEntity(pBlkRef);
		pMSBlockTableRecord->close();

		pBlkRef->close();
		pBlockTableRecord->close();
	}
}

void createBlockTest2()
{
	TCHAR* szBlock2 = _T("szBlock2");
	AcDbObjectIdArray objIds;
	getSelEntArray(objIds);
	if (objIds.length() == 0)
	{
		acutPrintf(_T("\nNo Entity selected!"));
		return;
	}
	appendEntityToBlock(szBlock2, objIds);
}

void insertBlockTest()
{
	BlkRefParam blkRefParam;

	TCHAR szBlockName[1024] = { 0 };
	acedGetString(0, _T("Enter Block Name:"), szBlockName);
	_tcscpy(blkRefParam.szBlockName, szBlockName);

	ads_point ptPos = { 0,0,0 };
	acedGetPoint(NULL, _T("Pick insert position:"), ptPos);
	blkRefParam.ptPos = AcGePoint3d(ptPos[X], ptPos[Y], ptPos[Z]);

	double dRotation = 0.0;
	acedGetReal(_T("Enter Rotation factor:"), &dRotation);
	blkRefParam.dRotation = dRotation;

	double dScale = 1.0;
	acedGetReal(_T("Enter Scale factor:"), &dScale);
	blkRefParam.dScale = dScale;

	insertBlock(blkRefParam);
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


