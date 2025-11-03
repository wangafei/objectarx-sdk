#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "PropertiesOverrule.h"
#include "dbents.h"

void initApp();
void unloadApp();

static CPropertiesOverrule* s_g_PropertiesOverrule = NULL;

void RemovePropertiesOverrule()
{
	if (s_g_PropertiesOverrule)
	{
		AcRxOverrule::removeOverrule(AcDbLine::desc(), s_g_PropertiesOverrule);
		AcRxOverrule::setIsOverruling(false);
		delete s_g_PropertiesOverrule;
		s_g_PropertiesOverrule = NULL;
	}
}

void AddPropertiesOverrule()
{
	RemovePropertiesOverrule();

	s_g_PropertiesOverrule = new CPropertiesOverrule();
	AcRxOverrule::addOverrule(AcDbLine::desc(), s_g_PropertiesOverrule, false);
	AcRxOverrule::setIsOverruling(true);
}

void initApp()
{ 
	// 1.Execute command "AddPropertiesOverrule"
	// 2.Draw some lines and execute command "List"
	acedRegCmds->addCommand(_T("PROPERTIESOVERRULE_COMMANDS"), _T("RemovePropertiesOverrule"), _T("RemovePropertiesOverrule"), ACRX_CMD_MODAL, RemovePropertiesOverrule);
	acedRegCmds->addCommand(_T("PROPERTIESOVERRULE_COMMANDS"), _T("AddPropertiesOverrule"), _T("AddPropertiesOverrule"), ACRX_CMD_MODAL, AddPropertiesOverrule);
}

void unloadApp()
{ 
	RemovePropertiesOverrule();
	acedRegCmds->removeGroup(_T("PROPERTIESOVERRULE_COMMANDS"));
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


