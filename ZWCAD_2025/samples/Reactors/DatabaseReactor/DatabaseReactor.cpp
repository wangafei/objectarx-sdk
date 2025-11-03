#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "DBReactor.h"
#include "dbapserv.h"

void initApp();
void unloadApp();

void AddDBReactor();
void RemoveReactor();

static DBReactor* g_dbReactor = NULL;

void initApp()
{ 
	DBReactor::rxInit();
	acrxBuildClassHierarchy();
	acedRegCmds->addCommand(_T("DATABASEREACTOR_COMMANDS"), _T("AddDBReactor"), _T("AddDBReactor"), ACRX_CMD_MODAL, AddDBReactor);
	acedRegCmds->addCommand(_T("DATABASEREACTOR_COMMANDS"), _T("RemoveReactor"), _T("RemoveReactor"), ACRX_CMD_MODAL, RemoveReactor);
}


void unloadApp()
{ 
	RemoveReactor();

	deleteAcRxClass(DBReactor::desc());
	acedRegCmds->removeGroup(_T("DATABASEREACTOR_COMMANDS"));
}


void AddDBReactor()
{
	if (g_dbReactor == NULL)
	{
		g_dbReactor = new DBReactor();
		acdbHostApplicationServices()->workingDatabase()->addReactor(g_dbReactor);
	}
	else
	{
		acdbHostApplicationServices()->workingDatabase()->addReactor(g_dbReactor);
	}
}

void RemoveReactor()
{
	if (g_dbReactor != NULL)
	{
		acdbHostApplicationServices()->workingDatabase()->removeReactor(g_dbReactor);
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


