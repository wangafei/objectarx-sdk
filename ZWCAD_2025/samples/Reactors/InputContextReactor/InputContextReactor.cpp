#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "acdocman.h"
#include "InputContextRec.h"

void initApp();
void unloadApp();

void AddReactor();
void RemoveReactor();

static InputContextRec* g_InputContextReactor = NULL;

void initApp()
{ 
	acedRegCmds->addCommand(_T("INPUTCONTEXTREACTOR_COMMANDS"), _T("AddReactor"), _T("AddReactor"), ACRX_CMD_MODAL, AddReactor);
	acedRegCmds->addCommand(_T("INPUTCONTEXTREACTOR_COMMANDS"), _T("RemoveReactor"), _T("RemoveReactor"), ACRX_CMD_MODAL, RemoveReactor);
}


void unloadApp()
{ 
	if (g_InputContextReactor != NULL)
	{
		AcApDocumentIterator* pIt = acDocManager->newAcApDocumentIterator();
		for (; !pIt->done(); pIt->step())
		{
			pIt->document()->inputPointManager()->removeInputContextReactor(g_InputContextReactor);
		}
		delete pIt;
		pIt = NULL;
	}
	acedRegCmds->removeGroup(_T("INPUTCONTEXTREACTOR_COMMANDS"));
}


void AddReactor()
{
	if (g_InputContextReactor == NULL)
	{
		g_InputContextReactor = new InputContextRec();
		acDocManager->curDocument()->inputPointManager()->addInputContextReactor(g_InputContextReactor);
	}
	else
	{
		acDocManager->curDocument()->inputPointManager()->addInputContextReactor(g_InputContextReactor);
	}
}

void RemoveReactor()
{
	if (g_InputContextReactor != NULL)
	{
		acDocManager->curDocument()->inputPointManager()->removeInputContextReactor(g_InputContextReactor);
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


