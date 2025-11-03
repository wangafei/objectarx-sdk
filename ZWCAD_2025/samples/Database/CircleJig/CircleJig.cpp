#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "CDrawCircleJig.h"
#include "dbapserv.h"

void initApp();
void unloadApp();
void CircleJig();

void initApp()
{ 
	acedRegCmds->addCommand(_T("CIRCLEJIG_COMMANDS"), _T("CircleJig"), _T("CircleJig"), ACRX_CMD_MODAL, CircleJig);
}


void unloadApp()
{ 
	acedRegCmds->removeGroup(_T("CIRCLEJIG_COMMANDS"));
}


void CircleJig()
{
	AcGeVector3d x = acdbHostApplicationServices()->workingDatabase()->ucsxdir();
	AcGeVector3d y = acdbHostApplicationServices()->workingDatabase()->ucsydir();
	AcGeVector3d normalVec = x.crossProduct(y);
	normalVec.normalize();

	CDrawCircleJig* pJig = new CDrawCircleJig(normalVec);
	if (!pJig)
	{
		return;
	}

	pJig->doIt();

	delete pJig;
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


