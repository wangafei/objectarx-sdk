#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "ObjectOverrule.h"
#include "dbents.h"

void initApp();
void unloadApp();

static CPolyLineOverrule* s_g_polylineOverrule = NULL;

void RemoveObjOverrule()
{
	if (s_g_polylineOverrule)
	{
		AcRxOverrule::removeOverrule(AcDbPolyline::desc(), s_g_polylineOverrule);
		AcRxOverrule::setIsOverruling(false);
		delete s_g_polylineOverrule;
		s_g_polylineOverrule = NULL;
	}
}

void AddObjOverruleCanCopy()
{
	RemoveObjOverrule();
	s_g_polylineOverrule = new CPolyLineOverrule(true);
	AcRxOverrule::addOverrule(AcDbPolyline::desc(), s_g_polylineOverrule, false);
	AcRxOverrule::setIsOverruling(true);
}

void AddObjOverruleCanNotCopy()
{
	RemoveObjOverrule();
	s_g_polylineOverrule = new CPolyLineOverrule(false);
	AcRxOverrule::addOverrule(AcDbPolyline::desc(), s_g_polylineOverrule, false);
	AcRxOverrule::setIsOverruling(true);
}

void initApp()
{ 
	acedRegCmds->addCommand(_T("OBJECTOVERRULE_COMMANDS"), _T("RemoveObjOverrule"), _T("RemoveObjOverrule"), ACRX_CMD_MODAL, RemoveObjOverrule);
	acedRegCmds->addCommand(_T("OBJECTOVERRULE_COMMANDS"), _T("AddObjOverruleCanCopy"), _T("AddObjOverruleCanCopy"), ACRX_CMD_MODAL, AddObjOverruleCanCopy);
	acedRegCmds->addCommand(_T("OBJECTOVERRULE_COMMANDS"), _T("AddObjOverruleCanNotCopy"), _T("AddObjOverruleCanNotCopy"), ACRX_CMD_MODAL, AddObjOverruleCanNotCopy);
}

void unloadApp()
{ 
	RemoveObjOverrule();
	acedRegCmds->removeGroup(_T("OBJECTOVERRULE_COMMANDS"));
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


