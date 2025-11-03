#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "dbapserv.h"
#include "dbdict.h"
#include "dbobjptr.h"
#include "MyObject.h"

void initApp();
void unloadApp();

void CreateDictionary();
void IteratorDictionary();

void initApp()
{ 
	MyObject::rxInit();
	acrxBuildClassHierarchy();
	acedRegCmds->addCommand(_T("CUSOBJECT_COMMANDS"), _T("CreateDict"), _T("CreateDict"), ACRX_CMD_MODAL, CreateDictionary);
	acedRegCmds->addCommand(_T("CUSOBJECT_COMMANDS"), _T("IteratorDict"), _T("IteratorDict"), ACRX_CMD_MODAL, IteratorDictionary);
}

void unloadApp()
{ 
	deleteAcRxClass(MyObject::desc());
	acedRegCmds->removeGroup(_T("CUSOBJECT_COMMANDS"));
}

void CreateDictionary()
{
	AcDbDictionary *pNamedobj;
	acdbHostApplicationServices()->workingDatabase()->getNamedObjectsDictionary(pNamedobj, AcDb::kForWrite);

	AcDbDictionary *pDict;
	if (pNamedobj->getAt(_T("CUSTOM_DICT"), (AcDbObject*&)pDict, AcDb::kForWrite) == Acad::eKeyNotFound)
	{
		pDict = new AcDbDictionary;
		AcDbObjectId DictId;
		pNamedobj->setAt(_T("CUSTOM_DICT"), pDict, DictId);
	}
	pNamedobj->close();

	if (pDict)
	{
		MyObject *pObj1 = new MyObject(1.11);
		MyObject *pObj2 = new MyObject(2.22);

		AcDbObjectId rId1, rId2;
		pDict->setAt(_T("OBJ1"), pObj1, rId1);
		pDict->setAt(_T("OBJ2"), pObj2, rId2);

		pObj1->close();
		pObj2->close();
		pDict->close();
	}
}

void IteratorDictionary()
{
	AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();

	AcDbDictionaryPointer pNamedobj;
	pNamedobj.open(pDb->namedObjectsDictionaryId(), AcDb::kForRead);

	if (pNamedobj.openStatus() == Acad::eOk)
	{
		AcDbObjectId dictId;
		Acad::ErrorStatus es = pNamedobj->getAt(_T("CUSTOM_DICT"), dictId);

		if (es == Acad::eOk)
		{
			AcDbDictionaryPointer pDict(dictId, AcDb::kForRead);

			if (pDict.openStatus() == Acad::eOk)
			{
				AcDbDictionaryIterator* pDictIter = pDict->newIterator();

				double val;
				MyObject *pMyCl = NULL;
				for (; !pDictIter->done(); pDictIter->next())
				{
					es = pDictIter->getObject((AcDbObject*&)pMyCl, AcDb::kForRead);
					if (es == Acad::eOk)
					{
						pMyCl->getData(val);
						pMyCl->close();
						acutPrintf(_T("\nvalue = %f"), val);
					}
				}
				delete pDictIter;
			}
		}
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


