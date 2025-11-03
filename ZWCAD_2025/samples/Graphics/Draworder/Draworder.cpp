#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "sorttab.h"
#include "dbobjptr.h"
#include "dbapserv.h"
#include "migrtion.h"
#include "adscodes.h"

void initApp();
void unloadApp();

Acad::ErrorStatus getSortentsTable(AcDbSortentsTable*& pSortTab);
Acad::ErrorStatus moveBelow(AcDbObjectIdArray& arr, AcDbObjectIdArray& arrRef);
Acad::ErrorStatus moveAbove(AcDbObjectIdArray& arr, AcDbObjectIdArray& arrRef);
Acad::ErrorStatus moveToTop(AcDbObjectIdArray& arr);
Acad::ErrorStatus moveToBottom(AcDbObjectIdArray& arr);
void draworderCmd();

void initApp()
{ 
	acedRegCmds->addCommand(_T("DRAWORDER_COMMANDS"), _T("DraworderExample"), _T("DraworderExample"), ACRX_CMD_MODAL, draworderCmd);
}

void unloadApp()
{ 
	acedRegCmds->removeGroup(_T("DRAWORDER_COMMANDS"));
}

Acad::ErrorStatus getSortentsTable(AcDbSortentsTable*& pSortTab)
{
	Acad::ErrorStatus es;
	AcDbBlockTableRecordPointer pBlockTableRecord(ACDB_MODEL_SPACE, acdbCurDwg(), AcDb::kForRead);
	if ((es = pBlockTableRecord.openStatus()) == Acad::eOk)
	{
		es = pBlockTableRecord->getSortentsTable(pSortTab, AcDb::kForWrite, true);
	}
	return es;
}

Acad::ErrorStatus moveBelow(AcDbObjectIdArray& arr, AcDbObjectIdArray& arrRef)
{
	if (arr.isEmpty() || arrRef.isEmpty())
		return Acad::eInvalidInput;
	AcDbSortentsTable* pSortTable = NULL;
	Acad::ErrorStatus es = getSortentsTable(pSortTable);
	if (es == Acad::eOk)
	{
		for (int i = 0; i < arrRef.length(); i++)
		{
			AcDbObjectId idRef = arrRef[i];
			if (idRef.isNull())
				continue;
			es = pSortTable->moveBelow(arr, idRef);
		}
		pSortTable->close();
	}
	return es;
}

Acad::ErrorStatus moveAbove(AcDbObjectIdArray& arr, AcDbObjectIdArray& arrRef)
{
	if (arr.isEmpty() || arrRef.isEmpty())
		return Acad::eInvalidInput;
	AcDbSortentsTable* pSortTable = NULL;
	Acad::ErrorStatus es = getSortentsTable(pSortTable);
	if (es == Acad::eOk)
	{
		// The acedSSGet selection set entities are arranged in descending order by handles, 
		// and the AcDbSortentsTable is arranged in ascending order.
		arrRef.reverse();
		for (int i = 0; i < arrRef.length(); i++)
		{
			AcDbObjectId idRef = arrRef[i];
			if (idRef.isNull())
				continue;
			es = pSortTable->moveAbove(arr, idRef);
		}
		pSortTable->close();
	}
	return es;
}

Acad::ErrorStatus moveToTop(AcDbObjectIdArray& arr)
{
	if (arr.isEmpty())
		return Acad::eInvalidInput;
	AcDbSortentsTable* pSortTable = NULL;
	Acad::ErrorStatus es = getSortentsTable(pSortTable);
	if (es == Acad::eOk)
	{
		es = pSortTable->moveToTop(arr);
		pSortTable->close();
	}
	return es;
}

Acad::ErrorStatus moveToBottom(AcDbObjectIdArray& arr)
{
	if (arr.isEmpty())
		return Acad::eInvalidInput;
	AcDbSortentsTable* pSortTable = NULL;
	Acad::ErrorStatus es = getSortentsTable(pSortTable);
	if (es == Acad::eOk)
	{
		es = pSortTable->moveToBottom(arr);
		pSortTable->close();
	}
	return es;
}

int getObjectIdArray(AcDbObjectIdArray& objIds, const ads_name ssname)
{
	Adesk::Int32 len = 0;
	AcDbObjectId objId;
	ads_name entName;
	int nRet = acedSSLength(ssname, &len);
	if (nRet != RTNORM)
		return nRet;
	for (int i = 0; i < len; i++)
	{
		if ((nRet = acedSSName(ssname, i, entName)) != RTNORM)
			return nRet;
		if ((nRet = acdbGetObjectId(objId, entName)) != Acad::eOk)
			return nRet;
		objIds.append(objId);
	}
	return RTNORM;
}

int getSelEntities(AcDbObjectIdArray& idsArray, TCHAR* mode, void* ptr)
{
	ads_name selSet;
	int nRet = acedSSGet(mode, ptr, NULL, NULL, selSet);
	if (nRet != RTNORM)
		return nRet;
	nRet = getObjectIdArray(idsArray, selSet);
	acedSSFree(selSet);
	return nRet;
}

void draworderCmd()
{
	AcDbObjectIdArray arrObjs;
	TCHAR keyWord[10];
	TCHAR* prompt1[2] = { _T("\nSelect the entity(s) you want to change the draw order: "), _T("") };
	TCHAR* prompt2[2] = { _T("\nSelect the reference entity: "), _T("") };
	getSelEntities(arrObjs, _T(":$"), prompt1);
	if (arrObjs.length() == 0)
		return;
	acedInitGet(0, _T("A U F B"));
	int retVal = acedGetKword(_T("Input Options [Above(A)/Below(U)/Top(F)/Bottom(B)] <Bottom>: "), keyWord);
	if (retVal == RTNORM)
	{
		if (_tcscmp(keyWord, _T("A")) == 0)
		{
			AcDbObjectIdArray arrTarget;
			getSelEntities(arrTarget, _T(":$"), prompt2);
			moveAbove(arrObjs, arrTarget);
		}
		else if (_tcscmp(keyWord, _T("U")) == 0)
		{
			AcDbObjectIdArray arrTarget;
			getSelEntities(arrTarget, _T(":$"), prompt2);
			moveBelow(arrObjs, arrTarget);
		}
		else if (_tcscmp(keyWord, _T("F")) == 0)
		{
			moveToTop(arrObjs);
		}
		else if (_tcscmp(keyWord, _T("B")) == 0)
		{
			moveToBottom(arrObjs);
		}
	}
	else if (retVal == RTCAN)
		return;
	else if (retVal = RTNONE)
		moveToBottom(arrObjs);
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


