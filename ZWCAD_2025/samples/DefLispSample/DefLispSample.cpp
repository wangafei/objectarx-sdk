#include "stdafx.h"
#include <rxregsvc.h>
#include "adsmigr.h"
#include "adsdef.h"
#include "adscodes.h"
#include "acestext.h"
#include "acedads.h"
#include "acutads.h"
#include "acdbads.h"

int showhellocmd(struct resbuf *rb);
int rectArea(struct resbuf *rb);

void initapp()
{
	// Add your code here.
}

void unloadapp()
{
	// Add your code here.
}

int showhellocmd(struct resbuf *rb)
{
	ads_printf(_T("\nshowhellocmd"));
	ads_retvoid();
	return RTNORM;
}

ads_real calReArea(ads_point pt1, ads_point pt2)
{
	// acedCommand(RTSTR, _T("RECTANG"), RTPOINT, pt1, RTPOINT, pt2, RTNONE);
	acutPrintf(_T("\nRectangPoint1(%g,%g,%g),RectangPoint2(%g,%g,%g)"), pt1[X], pt1[Y], pt1[Z], pt2[X], pt2[Y], pt2[Z]);
	acutPrintf(_T("\nRectang Area: "));
	return fabs((pt1[X] - pt2[X])*(pt1[Y] - pt2[Y]));
}

// Input (rectarea (getpoint "The first point:\n") (getpoint "The corner point:\n")) or (rectarea '(0 0 0) '(100 100 0)) to call the lisp function.
//
int rectArea(struct resbuf *rb)
{
	ads_point adsPtArr[2] = { 0 };

	if (NULL == rb)
		return RTERROR;

	struct resbuf *rbTmp = nullptr;
	int i = 0;
	for (i = 0, rbTmp = rb; i < 2 && rbTmp != NULL; i++, rbTmp = rbTmp->rbnext)
	{
		if (rbTmp->restype == RT3DPOINT)
		{
			adsPtArr[i][X] = rbTmp->resval.rpoint[X];
			adsPtArr[i][Y] = rbTmp->resval.rpoint[Y];
			adsPtArr[i][Z] = rbTmp->resval.rpoint[Z];
		}
		else if (rbTmp->restype == RTPOINT)
		{
			adsPtArr[i][X] = rbTmp->resval.rpoint[X];
			adsPtArr[i][Y] = rbTmp->resval.rpoint[Y];
			adsPtArr[i][Z] = 0.0;
		}
		else
		{
			TCHAR szErr[256] = { 0 };
			swprintf_s(szErr, 256, _T("%s parameter should be 2D point or 3D point!"), i == 0 ? _T("First") : _T("Second"));
			acdbFail(szErr);
			return RTERROR;
		}
	}
	if (i < 2)
	{
		acdbFail(_T("Missing parameters!"));
		return RTERROR;
	}

	acedRetReal(calReArea(adsPtArr[0], adsPtArr[1]));

	return RTNORM;
}


#define ELEMENTS(array) (sizeof(array)/sizeof((array)[0]))

struct func_entry { TCHAR *func_name; int(*func) (struct resbuf *); };

struct func_entry func_table[] = {
	{_T("rectArea"), rectArea},
	{_T("c:showhello"), showhellocmd},
};

int funcload()
{
	for (int i = 0; i < ELEMENTS(func_table); i++)
	{
		if (!acedDefun(func_table[i].func_name, i))
			return RTERROR;
	}

	return RTNORM;
}

int funcunLoad()
{
	for (int i = 0; i < ELEMENTS(func_table); i++)
	{
		if (!acedUndef(func_table[i].func_name, i))
			return RTERROR;
	}

	return RTNORM;
}

int dofunc()
{
	struct resbuf* rb = NULL;
	int val = 0;

	if ((val = acedGetFunCode()) < 0 || val >= ELEMENTS(func_table))
	{
		acdbFail(_T("Received nonexistent function code."));
		return RTERROR;
	}
	rb = acedGetArgs();
	val = (*func_table[val].func)(rb);
	acutRelRb(rb);
	return val;
}

extern "C" AcRx::AppRetCode zcrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
{
	switch (msg)
	{
	case AcRx::kInitAppMsg:
	{
		acrxDynamicLinker->unlockApplication(appId);
		acrxDynamicLinker->registerAppMDIAware(appId);
		initapp();
	}
	break;
	case AcRx::kUnloadAppMsg:
	{
		unloadapp();
		funcunLoad();
	}
	break;

	case AcRx::kLoadDwgMsg:
	{
		funcload();
	}
	break;
	case AcRx::kUnloadDwgMsg:
	{
		// Add your code here.
	}
	break;
	case AcRx::kInvkSubrMsg:
	{
		dofunc();
	}
	break;

	default:
		break;
	}
	return AcRx::kRetOK;
}



#ifdef _WIN64
#pragma comment(linker, "/export:zcrxEntryPoint,PRIVATE")
#pragma comment(linker, "/export:zcrxGetApiVersion,PRIVATE")
#else // WIN32
#pragma comment(linker, "/export:_zcrxEntryPoint,PRIVATE")
#pragma comment(linker, "/export:_zcrxGetApiVersion,PRIVATE")
#endif

