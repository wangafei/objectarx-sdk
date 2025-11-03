#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "adscodes.h"
#include "dbxrecrd.h"
#include "dbdict.h"

void initApp();
void unloadApp();

void AddXRecord();
void ModXRecord();
void DelXRecord();

void initApp()
{ 
	acedRegCmds->addCommand(_T("XRECORD_COMMANDS"), _T("AddXRecord"), _T("AddXRecord"), ACRX_CMD_MODAL, AddXRecord);
	acedRegCmds->addCommand(_T("XRECORD_COMMANDS"), _T("ModXRecord"), _T("ModXRecord"), ACRX_CMD_MODAL, ModXRecord);
	acedRegCmds->addCommand(_T("XRECORD_COMMANDS"), _T("DelXRecord"), _T("DelXRecord"), ACRX_CMD_MODAL, DelXRecord);
}

void unloadApp()
{ 
	acedRegCmds->removeGroup(_T("XRECORD_COMMANDS"));
}

void AddXRecord()
{
	ads_name en;
	ads_point pt;
	if (acedEntSel(_T("\nSelect the entity: "), en, pt) != RTNORM)
	{
		return;
	}
	AcDbObjectId entId;
	Acad::ErrorStatus es = acdbGetObjectId(entId, en);

	AcDbObjectId xRecordId;
	AcDbDictionary* pDict = NULL;
	AcDbObject* pObj = NULL;
	if (Acad::eOk != (es = acdbOpenObject(pObj, entId, AcDb::kForWrite)))
	{
		return;
	}

	AcDbObjectId dictObjId = pObj->extensionDictionary();
	if (dictObjId == NULL)
	{
		es = pObj->createExtensionDictionary();
		dictObjId = pObj->extensionDictionary();
	}
	pObj->close();

	if (Acad::eOk == (es = acdbOpenObject(pDict, dictObjId, AcDb::kForWrite)))
	{
		AcDbXrecord* pXRecord = new AcDbXrecord();

		if (Acad::eOk == (es = pDict->setAt(_T("XRecord"), pXRecord, xRecordId)))
		{
			pDict->close();

			struct resbuf* pRb = NULL;
			pRb = acutBuildList(AcDb::kDxfText, _T("hello"),
				AcDb::kDxfInt32, 2,
				AcDb::kDxfReal, 3.14,
				RTNONE);
			es = pXRecord->setFromRbChain(*pRb);
			pXRecord->close();
			acutRelRb(pRb);
		}
		else
		{
			delete pXRecord;
			pXRecord = NULL;
		}
	}
}

void ModXRecord()
{
	ads_name en;
	ads_point pt;
	if (acedEntSel(_T("\nSelect the entity: "), en, pt) != RTNORM)
	{
		return;
	}
	AcDbObjectId entId;
	Acad::ErrorStatus es = acdbGetObjectId(entId, en);

	AcDbObject* pObj = NULL;
	if (Acad::eOk != acdbOpenObject(pObj, entId, AcDb::kForWrite))
	{
		return;
	}

	AcDbObjectId dictObjId = pObj->extensionDictionary();
	pObj->close();
	if (dictObjId == NULL)
	{
		acutPrintf(_T("\nThe entity has not the extension dictionary."));
		return;
	}
	AcDbDictionary* pDict = NULL;
	AcDbXrecord* pXRecord = NULL;
	if (Acad::eOk != acdbOpenObject(pDict, dictObjId, AcDb::kForWrite))
	{
		return;
	}

	pDict->getAt(_T("XRecord"), pXRecord, AcDb::kForWrite);
	pDict->close();
	if (pXRecord)
	{
		struct resbuf* pRb;
		pRb = acutBuildList(AcDb::kDxfText, _T("Mod"),
			AcDb::kDxfInt32, 1,
			AcDb::kDxfReal, 6.28,
			RTNONE);
		pXRecord->setFromRbChain(*pRb);
	}
	else
	{
		acutPrintf(_T("\nThe entity has not the extension data."));
	}
	pXRecord->close();
}

void DelXRecord()
{
	ads_name en;
	ads_point pt;
	if (acedEntSel(_T("\nSelect the entity: "), en, pt) != RTNORM)
	{
		return;
	}
	AcDbObjectId entId;
	Acad::ErrorStatus es = acdbGetObjectId(entId, en);

	AcDbObject* pObj = NULL;
	if (Acad::eOk != acdbOpenObject(pObj, entId, AcDb::kForWrite))
	{
		return;
	}

	AcDbObjectId dictObjId = pObj->extensionDictionary();
	pObj->close();
	if (dictObjId == NULL)
	{
		acutPrintf(_T("\nThe entity has not the extension dictionary"));
		return;
	}

	AcDbDictionary* pDict = NULL;
	es = acdbOpenObject(pDict, dictObjId, AcDb::kForWrite);
	if (Acad::eOk == es && pDict)
	{
		if (pDict->has(_T("XRecord")))
		{
			pDict->remove(_T("XRecord"));
			acutPrintf(_T("\nThe extension dictionary \"XRecord\" has been deleted."));
		}
		else
		{
			acutPrintf(_T("\nThe extension dictionary \"XRecord\" does not exist."));
		}
		pDict->close();
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


