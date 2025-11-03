#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "Pipe.h"
#include "DBUtils.h"
#include "dbobjptr.h"
#include "geassign.h"
#include "adscodes.h"

void initApp();
void unloadApp();
void CreatePipe();

void initApp()
{ 
	Pipe::rxInit();
	acrxBuildClassHierarchy();
	acedRegCmds->addCommand(_T("MYPIPE_COMMANDS"), _T("CreatePipe"), _T("CreatePipe"), ACRX_CMD_MODAL, CreatePipe);
}


void unloadApp()
{ 
	deleteAcRxClass(Pipe::desc());
	acedRegCmds->removeGroup(_T("MYPIPE_COMMANDS"));
}


void CreatePipe()
{
	AcGePoint3d startPnt;
	acedInitGet(RSG_NONULL, NULL);

	if (acedGetPoint(NULL, _T("\nSpecify the start point: "), asDblArray(startPnt)) != RTNORM)
		return;

	AcGePoint3d endPnt;
	acedInitGet(RSG_NONULL, NULL);

	if (acedGetPoint(NULL, _T("\nSpecify the end Point"), asDblArray(endPnt)) != RTNORM)
		return;

	AcDbObjectPointer<Pipe> pEnt;
	pEnt.create();
	pEnt->SetStartPoint(startPnt);
	pEnt->SetEndPoint(endPnt);
	pEnt->SetDiameter(200);

	AddToCurrentSpaceAndClose(pEnt.object());
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


