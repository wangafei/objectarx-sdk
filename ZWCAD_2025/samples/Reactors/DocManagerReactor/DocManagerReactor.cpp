#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "DocManReactor.h"

void initApp();
void unloadApp();

void AddDocManReactor();
void RemoveDocManReactor();

static DocManReactor* g_DocManReactor = NULL;

void initApp()
{ 
	DocManReactor::rxInit();
	acrxBuildClassHierarchy();
	acedRegCmds->addCommand(_T("DOCMANAGERREACTOR_COMMANDS"), _T("AddDocManReactor"), _T("AddDocManReactor"), ACRX_CMD_MODAL, AddDocManReactor);
	acedRegCmds->addCommand(_T("DOCMANAGERREACTOR_COMMANDS"), _T("RemoveDocManReactor"), _T("RemoveDocManReactor"), ACRX_CMD_MODAL, RemoveDocManReactor);
}


void unloadApp()
{ 
	RemoveDocManReactor();
	deleteAcRxClass(DocManReactor::desc());
	acedRegCmds->removeGroup(_T("DOCMANAGERREACTOR_COMMANDS"));
}


void AddDocManReactor()
{
	if (g_DocManReactor == NULL)
	{
		g_DocManReactor = new DocManReactor();
		acDocManager->addReactor(g_DocManReactor);
	}
	else
	{
		acDocManager->addReactor(g_DocManReactor);
	}
}

void RemoveDocManReactor()
{
	if (g_DocManReactor != NULL)
	{
		acDocManager->removeReactor(g_DocManReactor);
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


