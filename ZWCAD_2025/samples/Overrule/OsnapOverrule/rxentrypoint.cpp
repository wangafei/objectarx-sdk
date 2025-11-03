#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "OsnapOverrule.h"
#include "dbents.h"

static COsnapOverrule* s_g_OsnapOverrule = NULL;

void initApp();
void unloadApp();

void RemoveOsnapOverrule()
{
	if (s_g_OsnapOverrule)
	{
		AcRxOverrule::removeOverrule(AcDbLine::desc(), s_g_OsnapOverrule);
		AcRxOverrule::setIsOverruling(false);
		delete s_g_OsnapOverrule;
		s_g_OsnapOverrule = NULL;
	}
}

void AddOsnapOverrule()
{
	RemoveOsnapOverrule();

	s_g_OsnapOverrule = new COsnapOverrule();
	AcRxOverrule::addOverrule(AcDbLine::desc(), s_g_OsnapOverrule, false);
	AcRxOverrule::setIsOverruling(true);
}

void initApp()
{ 
	acedRegCmds->addCommand(_T("OBJECTOVERRULE_COMMANDS"), _T("RemoveOsnapOverrule"), _T("RemoveOsnapOverrule"), ACRX_CMD_MODAL, RemoveOsnapOverrule);
	acedRegCmds->addCommand(_T("OBJECTOVERRULE_COMMANDS"), _T("AddOsnapOverrule"), _T("AddOsnapOverrule"), ACRX_CMD_MODAL, AddOsnapOverrule);
}


void unloadApp()
{ 
	RemoveOsnapOverrule();
	acedRegCmds->removeGroup(_T("OBJECTOVERRULE_COMMANDS"));
}


void helloWorld()
{ 
	acutPrintf(_T("\nHello World!"));
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


