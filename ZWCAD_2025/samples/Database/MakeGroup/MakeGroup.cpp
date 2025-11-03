#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "dbdict.h"
#include "dbgroup.h"
#include <set>
#include "adscodes.h"

void initApp();
void unloadApp();
void getSelectEntitiesArray(AcDbObjectIdArray& objIds);
void groupTest();
void unGroupTest();

void initApp()
{ 
	acedRegCmds->addCommand(_T("MAKEGROUP_COMMANDS"), _T("groupTest"), _T("groupTest"), ACRX_CMD_MODAL, groupTest);
	acedRegCmds->addCommand(_T("MAKEGROUP_COMMANDS"), _T("unGroupTest"), _T("unGroupTest"), ACRX_CMD_MODAL, unGroupTest);
}


void unloadApp()
{ 
	acedRegCmds->removeGroup(_T("MAKEGROUP_COMMANDS"));
}


void getSelectEntitiesArray(AcDbObjectIdArray& objIds)
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
void groupTest()
{
	Acad::ErrorStatus es;
	AcDbDictionary *pGroupDict;
	acdbHostApplicationServices()->workingDatabase()->getGroupDictionary(pGroupDict, AcDb::kForWrite);

	bool bIsAnonymous = false;
	bIsAnonymous = AfxMessageBox(_T("Create a anonymous group?"), MB_YESNO | MB_ICONWARNING) == IDYES;
	TCHAR *szGroupName = bIsAnonymous ? _T("*") : NULL;

	if (!bIsAnonymous)
	{
		TCHAR szTemp[256] = { 0 };
		int nRet = acedGetString(0, _T("Enter group name:"), szTemp);

		if (RTNORM != nRet || _tcscmp(szTemp, _T("")) == 0)
		{
			pGroupDict->close();
			return;
		}

		szGroupName = szTemp;

		if (pGroupDict->has(szGroupName))
		{
			acutPrintf(_T("\nThe group already exist!"));
			pGroupDict->close();
			return;
		}
	}

	AcDbObjectIdArray objIds;
	getSelectEntitiesArray(objIds);
	if (!objIds.length())
	{
		acutPrintf(_T("\nNo entity!"));
		pGroupDict->close();
		return;
	}

	AcDbObjectId groupId;
	AcDbGroup *pGroup = new AcDbGroup();

	if (bIsAnonymous)
		pGroup->setDescription(_T("This is a anonymous group"));
	else
		pGroup->setDescription(_T("This is a normal group"));

	es = pGroupDict->setAt(szGroupName, pGroup, groupId);
	pGroupDict->close();

	for (int i = 0; i < objIds.length(); i++)
	{
		if (!objIds[i].isNull())
			pGroup->append(objIds[i]);
	}

	//Invalid setting before append.
	if (bIsAnonymous)
		pGroup->setAnonymous();

	pGroup->close();
}
void unGroupTest()
{
	AcDbObjectIdArray objIds;
	getSelectEntitiesArray(objIds);
	if (!objIds.length())
	{
		acutPrintf(_T("\nNo entity!"));
		return;
	}

	AcDbDictionary *pGroupDict = NULL;
	Acad::ErrorStatus es;
	acdbHostApplicationServices()->workingDatabase()->getGroupDictionary(pGroupDict, AcDb::kForWrite);

	std::set<AcDbObjectId> groupIdSet;
	std::set<AcDbObjectId> groupEraseSet;
	AcDbDictionaryIterator *pDicIter = NULL;
	pDicIter = pGroupDict->newIterator();
	for (; !pDicIter->done(); pDicIter->next())
	{
		groupIdSet.insert(pDicIter->objectId());
	}
	delete pDicIter;

	for (int i = 0; i < objIds.length(); i++)
	{
		AcDbEntity *pEnt = NULL;
		es = acdbOpenAcDbEntity(pEnt, objIds[i], AcDb::kForRead);

		int nEntNum = 0;
		AcDbObjectId groupEraseId;
		std::set<AcDbObjectId>::iterator iter = groupIdSet.begin();
		for (; iter != groupIdSet.end(); iter++)
		{
			AcDbGroup *pTempGroup = NULL;
			es = acdbOpenObject(pTempGroup, *iter, AcDb::kForRead);
			if (pTempGroup->has(pEnt) && pTempGroup->numEntities() > nEntNum)
			{
				nEntNum = pTempGroup->numEntities();
				groupEraseId = pTempGroup->objectId();
			}
			pTempGroup->close();
		}
		if (groupEraseId.isValid())
			groupEraseSet.insert(groupEraseId);

		//If the object has more than one reader, then the open status is not changed 
		//and Adesk::eHadMultipleReaders is returned
		pEnt->close();
	}

	std::set<AcDbObjectId>::iterator iter = groupEraseSet.begin();
	for (; iter != groupEraseSet.end(); iter++)
	{
		AcDbGroup *pGroupErase = NULL;
		es = acdbOpenObject(pGroupErase, *iter, AcDb::kForWrite);

		es = pGroupErase->erase();
		pGroupErase->close();
	}

	pGroupDict->close();
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


