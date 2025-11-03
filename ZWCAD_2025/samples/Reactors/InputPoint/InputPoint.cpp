#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "ZwInputPointMonitor.h"
#include "ZwInputPointFilter.h"
#include <set>
#include "AcApDMgr.h"

void initApp();
void unloadApp();

ZwInputPointMonitor inputPointMonitor;
std::set<AcDbObjectId> nstKeyPtEntIdSet;
void addInputPointFilter();
void removeInputPointFilter();

ZwInputPointFilter inputPointFilter;
void addInputPointMonitor();
void removeInputPointMonitor();

void initApp()
{ 
	acedRegCmds->addCommand(_T("INPUTPOINT_COMMANDS"), _T("addInputPointMonitor"), _T("addInputPointMonitor"), ACRX_CMD_MODAL, addInputPointMonitor);
	acedRegCmds->addCommand(_T("INPUTPOINT_COMMANDS"), _T("removeInputPointMonitor"), _T("removeInputPointMonitor"), ACRX_CMD_MODAL, removeInputPointMonitor);
	acedRegCmds->addCommand(_T("INPUTPOINT_COMMANDS"), _T("addInputPointFilter"), _T("addInputPointFilter"), ACRX_CMD_MODAL, addInputPointFilter);
	acedRegCmds->addCommand(_T("INPUTPOINT_COMMANDS"), _T("removeInputPointFilter"), _T("removeInputPointFilter"), ACRX_CMD_MODAL, removeInputPointFilter);
}


void unloadApp()
{ 
	removeInputPointMonitor();
	removeInputPointFilter();
	acedRegCmds->removeGroup(_T("INPUTPOINT_COMMANDS"));
}


void addInputPointMonitor()
{
	curDoc()->inputPointManager()->addPointMonitor(&inputPointMonitor);
	acutPrintf(_T("The Inputpointmonitor has added!\n"));
}
void removeInputPointMonitor()
{
	curDoc()->inputPointManager()->removePointMonitor(&inputPointMonitor);
	acutPrintf(_T("The Inputpointmonitor has removed!\n"));
}

void addInputPointFilter()
{
	inputPointFilter.enableChange(IDOK == AfxMessageBox(_T("Do you need to change the point?"), MB_OKCANCEL));
	curDoc()->inputPointManager()->registerPointFilter(&inputPointFilter);
	acutPrintf(_T("The Inputpointfilter has added!\n"));
}

void removeInputPointFilter()
{
	if (NULL != curDoc()->inputPointManager()->currentPointFilter())
	{
		curDoc()->inputPointManager()->revokePointFilter();
		acutPrintf(_T("The Inputpointfilter has removed!\n"));
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


