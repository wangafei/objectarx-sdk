#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "EdReactor.h"

void initApp();
void unloadApp();

void AddEditorReactor();
void RemoveEditorReactor();

void initApp()
{ 
	EdReactor::rxInit();
	acrxBuildClassHierarchy();
	acedRegCmds->addCommand(_T("EDITORREACTOR_COMMANDS"), _T("AddEditorReactor"), _T("AddEditorReactor"), ACRX_CMD_MODAL, AddEditorReactor);
	acedRegCmds->addCommand(_T("EDITORREACTOR_COMMANDS"), _T("RemoveEditorReactor"), _T("RemoveEditorReactor"), ACRX_CMD_MODAL, RemoveEditorReactor);
}


void unloadApp()
{ 
	RemoveEditorReactor();

	deleteAcRxClass(EdReactor::desc());
	acedRegCmds->removeGroup(_T("EDITORREACTOR_COMMANDS"));
}

static EdReactor* s_g_editorreactor = nullptr;

void AddEditorReactor()
{
	if (!s_g_editorreactor)
	{
		s_g_editorreactor = new EdReactor();
		acedEditor->addReactor(s_g_editorreactor);
		acutPrintf(_T("\nEdReactor is on..."));
	}
}

void RemoveEditorReactor()
{
	if(s_g_editorreactor)
	{
		acedEditor->removeReactor(s_g_editorreactor);
		delete s_g_editorreactor;
		s_g_editorreactor = NULL;
		acutPrintf(_T("\nEdReactor is off..."));
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


