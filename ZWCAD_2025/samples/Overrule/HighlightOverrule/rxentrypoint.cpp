#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "HighlightOverrule.h"

static CHighlightOverrule* s_g_highlightOverrule = nullptr;

void removeHighlightOverrule()
{
	if (s_g_highlightOverrule)
	{
		AcRxOverrule::removeOverrule(AcDbLine::desc(), s_g_highlightOverrule);
		AcRxOverrule::removeOverrule(AcDbCircle::desc(), s_g_highlightOverrule);
		AcRxOverrule::setIsOverruling(false);

		delete s_g_highlightOverrule;
		s_g_highlightOverrule = nullptr;
	}
}

void addHighlightOverrule()
{
	removeHighlightOverrule();

	s_g_highlightOverrule = new CHighlightOverrule;
	AcRxOverrule::addOverrule(AcDbLine::desc(), s_g_highlightOverrule);
	AcRxOverrule::addOverrule(AcDbCircle::desc(), s_g_highlightOverrule);
	AcRxOverrule::setIsOverruling(true);
}
void initApp()
{ 
	acedRegCmds->addCommand(_T("HIGHLIGHTOVERRULE_COMMANDS"), _T("addHighlightOverrule"), _T("addHighlightOverrule"), ACRX_CMD_MODAL, addHighlightOverrule);
	acedRegCmds->addCommand(_T("HIGHLIGHTOVERRULE_COMMANDS"), _T("removeHighlightOverrule"), _T("removeHighlightOverrule"), ACRX_CMD_MODAL, removeHighlightOverrule);
}

void unloadApp()
{ 
	removeHighlightOverrule();
	acedRegCmds->removeGroup(_T("HIGHLIGHTOVERRULE_COMMANDS"));
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


