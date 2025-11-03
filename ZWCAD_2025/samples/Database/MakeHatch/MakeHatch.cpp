#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "dbhatch.h"
#include "dbcurve.h"
#include "dbsymtb.h"
#include <vector>
#include <map>
#include "adscodes.h"
#include "AcApDMgr.h"

void initApp();
void unloadApp();

void CreateHatchTest();

void initApp()
{ 
	// Only apply to the annular boundaries of common center and the boundaries do not intersect each other,
	// because the boundary type of the hatch is determinded by the area size in the example.
	acedRegCmds->addCommand(_T("MAKEHATCH_COMMANDS"), _T("CreateHatchTest"), _T("CreateHatchTest"), ACRX_CMD_MODAL, CreateHatchTest);
}


void unloadApp()
{ 
	acedRegCmds->removeGroup(_T("MAKEHATCH_COMMANDS"));
}


int SelectEntities(AcDbObjectIdArray & entIdArray)
{
	ads_name ss;
	int ret = acedSSGet(NULL, NULL, NULL, NULL, ss);
	if (ret == RTNORM)
	{
		Adesk::Int32 len = 0;
		acedSSLength(ss, &len);
		for (int i = 0; i < len; i++)
		{
			ads_name ent;
			AcDbObjectId entId;
			acedSSName(ss, i, ent);
			acdbGetObjectId(entId, ent);
			if (entId.isValid())
			{
				entIdArray.append(entId);
			}
		}
		acedSSFree(ss);
	}
	return ret;
}

Acad::ErrorStatus AppendToModalSpace(AcDbDatabase* db, AcDbEntity* ent, AcDbObjectId& oid)
{
	if (!db)
		return Acad::eNoDatabase;
	if (!ent)
		return Acad::eNullObjectPointer;

	Acad::ErrorStatus stats = Acad::eOk;
	AcDbBlockTable* pBlockTable = NULL;
	stats = db->getBlockTable(pBlockTable, AcDb::kForRead);
	if (pBlockTable)
	{
		AcDbBlockTableRecord* pBTR = NULL;
		stats = pBlockTable->getAt(ACDB_MODEL_SPACE, pBTR, AcDb::kForWrite);
		pBlockTable->close();
		pBlockTable = NULL;
		if (pBTR)
		{
			stats = pBTR->appendAcDbEntity(oid, ent);
			pBTR->close();
		}
	}
	return stats;
}

void CreateHatchTest()
{
	AcDbObjectIdArray ids, idsRet;
	if (RTNORM != SelectEntities(ids) || ids.length() == 0)
		return;

	std::map<AcDbObjectId, double> idsMap;
	for (int i = 0; i < ids.length(); i++)
	{
		AcDbEntity *pEnt = nullptr;
		double dArea = 0.0;
		Acad::ErrorStatus es = acdbOpenAcDbEntity(pEnt, ids[i], AcDb::kForRead);
		((AcDbCurve*)pEnt)->getArea(dArea);

		idsMap.insert(std::pair<AcDbObjectId, double>(ids[i], dArea));
		pEnt->close();
	}

	std::vector<std::pair<AcDbObjectId, double>> vec;
	for (std::map<AcDbObjectId, double>::iterator iter = idsMap.begin(); iter != idsMap.end(); iter++)
		vec.push_back(std::pair<AcDbObjectId, double>(iter->first, iter->second));
	// Same type, boundary sorted by area
	std::sort(vec.begin(), vec.end(), [](std::pair<AcDbObjectId, double>&a, std::pair<AcDbObjectId, double>&b) {return a.second < b.second; });

	AcDbHatch *pHatch = new AcDbHatch();
	pHatch->setNormal(AcGeVector3d::kZAxis);
	pHatch->setElevation(0.0);
	pHatch->setAssociative(Adesk::kTrue);
	pHatch->setPattern(AcDbHatch::kPreDefined, _T("SOLID"));
	acedInitGet(NULL, _T("N O I"));
	TCHAR szRet[32] = { 0 };
	acedGetKword(_T("Style type [Normal(N)/Outer(O)/Ignore(I)]:"), szRet);
	if (_tcscmp(_T("N"), szRet) == 0)
		pHatch->setHatchStyle(AcDbHatch::kNormal);
	else if (_tcscmp(_T("O"), szRet) == 0)
		pHatch->setHatchStyle(AcDbHatch::kOuter);
	else if (_tcscmp(_T("I"), szRet) == 0)
		pHatch->setHatchStyle(AcDbHatch::kIgnore);

	int nDep = 0;
	std::vector<std::pair<AcDbObjectId, double>>::iterator iter = vec.begin();
	for (; iter != vec.end(); iter++)
	{
		if (nDep == vec.size() - 1)  // The outermost boundary
		{
			AcDbObjectIdArray arrExternalId;
			arrExternalId.append(iter->first);
			pHatch->appendLoop(AcDbHatch::kExternal, arrExternalId);
		}
		else if (nDep == vec.size() - 2) // The boundary of the penultimate outer layer
		{
			AcDbObjectIdArray arrOutermostId;
			arrOutermostId.append(iter->first);
			pHatch->appendLoop(AcDbHatch::kOutermost, arrOutermostId);
		}
		else
		{
			AcDbObjectIdArray arrDefaultId;
			arrDefaultId.append(iter->first);
			pHatch->appendLoop(AcDbHatch::kDefault, arrDefaultId);
		}
		nDep++;
	}

	pHatch->evaluateHatch();
	AcDbObjectId newId;
	AppendToModalSpace(curDoc()->database(), pHatch, newId);
	pHatch->close();
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


