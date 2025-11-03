#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "GripOverrule.h"
#include "dbents.h"

static CGripOverrule* s_g_lineOverrule = NULL;

void RemoveGripOverrule()
{
	if (s_g_lineOverrule)
	{
		AcRxOverrule::removeOverrule(AcDbLine::desc(), s_g_lineOverrule);
		AcRxOverrule::setIsOverruling(false);
		delete s_g_lineOverrule;
		s_g_lineOverrule = NULL;
	}
}

void AddGripOverrule()
{
	RemoveGripOverrule();

	s_g_lineOverrule = new CGripOverrule();
	AcRxOverrule::addOverrule(AcDbLine::desc(), s_g_lineOverrule, false);
	AcRxOverrule::setIsOverruling(true);
}

void initApp()
{ 
	acedRegCmds->addCommand(_T("GRIPOVERRULE_COMMANDS"), _T("AddGripOverrule"), _T("AddGripOverrule"), ACRX_CMD_MODAL, AddGripOverrule);
	acedRegCmds->addCommand(_T("GRIPOVERRULE_COMMANDS"), _T("RemoveGripOverrule"), _T("RemoveGripOverrule"), ACRX_CMD_MODAL, RemoveGripOverrule);
}

void unloadApp()
{ 
	RemoveGripOverrule();
	acedRegCmds->removeGroup(_T("GRIPOVERRULE_COMMANDS"));
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
