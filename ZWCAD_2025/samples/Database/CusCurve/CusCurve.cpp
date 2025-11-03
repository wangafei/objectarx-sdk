#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "dbapserv.h"
#include "dbsymtb.h"
#include "geassign.h"
#include "adscodes.h"
#include "MyCurveEnt.h"
#include "MyJig.h"

void initApp();
void unloadApp();

void CreateMyCurveJig();
void CreateMyCurve();

void initApp()
{ 
	CMyCurve::rxInit();
	acrxBuildClassHierarchy();
	acedRegCmds->addCommand(_T("CUSCURVE_COMMANDS"), _T("CreateMyCurveJig"), _T("CreateMyCurveJig"), ACRX_CMD_MODAL, CreateMyCurveJig);
	acedRegCmds->addCommand(_T("CUSCURVE_COMMANDS"), _T("CreateMyCurve"), _T("CreateMyCurve"), ACRX_CMD_MODAL, CreateMyCurve);
}


void unloadApp()
{ 
	deleteAcRxClass(CMyCurve::desc());
	acedRegCmds->removeGroup(_T("CUSCURVE_COMMANDS"));
}

Acad::ErrorStatus AddToModelSpace(AcDbEntity *pEnt)
{
	AcDbBlockTable *pBlockTable = NULL;
	AcDbBlockTableRecord *pBlockTableRecord = NULL;
	AcDbObjectId entId;
	Acad::ErrorStatus es;

	if (Acad::eOk == (es = acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBlockTable, AcDb::kForRead)))
	{
		if (Acad::eOk == (es = pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord, AcDb::kForWrite)))
		{
			es = pBlockTableRecord->appendAcDbEntity(entId, pEnt);
			pBlockTableRecord->close();
		}

		pBlockTable->close();
	}
	return es;
}

void CreateMyCurveJig()
{
	ads_point pt;
	acedGetPoint(NULL, _T("Specify the center point: "), pt);

	int num = 0;
	while (num <= 0)
	{
		acedGetInt(_T("Enter a positive integer: "), &num);
	}

	CMyJig jig;
	jig.doIt(asPnt3d(pt), num);
}

void CreateMyCurve()
{
	ads_point pt1;
	if (RTNORM != acedGetPoint(NULL, _T("Specify the center point: "), pt1))
		return;

	ads_point pt2;
	if (RTNORM != acedGetPoint(NULL, _T("Specify the end point£º"), pt2))
		return;

	CMyCurve* mycurve = new CMyCurve(asPnt3d(pt1), asPnt3d(pt2), 25);
	if (Acad::eOk == AddToModelSpace(mycurve))
	{
		mycurve->close();
	}
	else
	{
		delete mycurve;
		mycurve = NULL;
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


