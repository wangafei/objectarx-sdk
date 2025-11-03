#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "TransformOverrule.h"
#include "dbents.h"

void initApp();
void unloadApp();

static CTransformOverrule* s_g_TransformOverrule = NULL;

void RemoveTransformOverrule()
{
	if (s_g_TransformOverrule)
	{
		AcRxOverrule::removeOverrule(AcDbPolyline::desc(), s_g_TransformOverrule);
		AcRxOverrule::setIsOverruling(false);
		delete s_g_TransformOverrule;
		s_g_TransformOverrule = NULL;
	}
}

void AddTransformOverrule()
{
	RemoveTransformOverrule();

	s_g_TransformOverrule = new CTransformOverrule();
	AcRxOverrule::addOverrule(AcDbPolyline::desc(), s_g_TransformOverrule, false);
	AcRxOverrule::setIsOverruling(true);
}

void initApp()
{ 
	acedRegCmds->addCommand(_T("TRANSFORMOVERRULE_COMMANDS"), _T("RemoveTransformOverrule"), _T("RemoveTransformOverrule"), ACRX_CMD_MODAL, RemoveTransformOverrule);
	acedRegCmds->addCommand(_T("TRANSFORMOVERRULE_COMMANDS"), _T("AddTransformOverrule"), _T("AddTransformOverrule"), ACRX_CMD_MODAL, AddTransformOverrule);
}


void unloadApp()
{ 
	RemoveTransformOverrule();
	acedRegCmds->removeGroup(_T("TRANSFORMOVERRULE_COMMANDS"));
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


