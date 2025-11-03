#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "adscodes.h"
#include "geassign.h"
#include "gemat3d.h"

void initApp();
void unloadApp();
void entMakeTest();
void entModTest();

void initApp()
{ 
	acedRegCmds->addCommand(_T("ENTMAKE_COMMANDS"), _T("entMakeTest"), _T("entMakeTest"), ACRX_CMD_MODAL, entMakeTest);
	acedRegCmds->addCommand(_T("ENTMAKE_COMMANDS"), _T("entModTest"), _T("entModTest"), ACRX_CMD_MODAL, entModTest);
}


void unloadApp()
{ 
	acedRegCmds->removeGroup(_T("ENTMAKE_COMMANDS"));
}

void entMakeTest()
{
	int nRet = 0;
	AcGePoint3d ptStart(0, 0, 0);
	AcGePoint3d ptEnd(1000, 1000, 0);
	AcGePoint3d ptCtr(500, 500, 0);
	double rad = 200.0;

	resbuf* pRbLine = acutBuildList(
		RTDXF0, _T("LINE"),
		100, _T("AcDbLine"),
		100, _T("AcDbEntity"),
		10, asDblArray(ptStart),
		11, asDblArray(ptEnd),
		62, 1,
		RTNONE);
	nRet = acdbEntMake(pRbLine);
	if (nRet != RTNORM)
		acutPrintf(_T("\nEntMake Failed! ErrorCode = %d"), nRet);
	acutRelRb(pRbLine);

	resbuf* pRbCircle = acutBuildList(
		RTDXF0, _T("CIRCLE"),
		100, _T("AcDbCircle"),
		100, _T("AcDbEntity"),
		10, asDblArray(ptCtr),
		40, rad,
		62, 1,
		RTNONE);
	nRet = acdbEntMake(pRbCircle);
	if (nRet != RTNORM)
		acutPrintf(_T("\nEntMake Failed! ErrorCode = %d"), nRet);
	acutRelRb(pRbCircle);
}

void entModTest()
{
	int nRet = 0;
	ads_name sSet;
	TCHAR* prompts[2] = { _T("Select entities:"), _T("") };
	nRet = acedSSGet(_T(":$"), prompts, NULL, NULL, sSet);
	if (nRet != RTNORM)
		return;

	int32_t sLen = 0;
	nRet = acedSSLength(sSet, &sLen);

	AcGeMatrix3d mat(AcGeMatrix3d::kIdentity);
	mat(0, 0) = 0.5;
	mat(1, 1) = 0.5;
	mat(2, 2) = 0.5;
	mat(0, 3) = 500;
	mat(1, 3) = 500;

	for (int i = 0; i < sLen; i++)
	{
		ads_name entName;
		ads_ssname(sSet, i, entName);

		TCHAR szType[20] = { 0 };
		AcGePoint3d ptDXF10, ptDXF11;
		double rad = 0.0;

		resbuf* pRbEnt = acdbEntGet(entName);  
		resbuf* pRbEntTail = pRbEnt;
		while (pRbEntTail&&pRbEntTail->rbnext)
		{
			if (pRbEntTail->restype == 0)
				_tcscpy(szType, pRbEntTail->resval.rstring);
			if (pRbEntTail->restype == 10)
				ptDXF10 = { pRbEntTail->resval.rpoint[X],pRbEntTail->resval.rpoint[Y],pRbEntTail->resval.rpoint[Z] };
			if (pRbEntTail->restype == 11)
				ptDXF11 = { pRbEntTail->resval.rpoint[X],pRbEntTail->resval.rpoint[Y],pRbEntTail->resval.rpoint[Z] };
			if (pRbEntTail->restype == 40)
				rad = pRbEntTail->resval.rreal;

			pRbEntTail = pRbEntTail->rbnext;
		}

		resbuf* pRbHead = acutNewRb(-1);
		ads_name_set(entName, pRbHead->resval.rlname);

		resbuf* pRbEntMod = NULL;
		if (_tcscmp(szType, _T("LINE")) == 0)
		{
			pRbEntMod = acutBuildList(
				10, asDblArray(ptDXF10.transformBy(mat)),
				11, asDblArray(ptDXF11.transformBy(mat)),
				62, 2,
				RTNONE);
		}
		else if (_tcscmp(szType, _T("CIRCLE")) == 0)
		{
			pRbEntMod = acutBuildList(
				10, asDblArray(ptDXF10.transformBy(mat)),
				40, rad*0.5,
				62, 2,
				RTNONE);
		}

		if (pRbEntTail)
			pRbEntTail->rbnext = pRbEntMod;

		nRet = acdbEntMod(pRbEnt);
		if (nRet != RTNORM)
			acutPrintf(_T("\nEntMod Failed! ErrorCode = %d"), nRet);
		nRet = acdbEntUpd(pRbEnt->resval.rlname);
		if (nRet != RTNORM)
			acutPrintf(_T("\nEntUpd Failed! ErrorCode = %d"), nRet);

		acutRelRb(pRbEnt);
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


