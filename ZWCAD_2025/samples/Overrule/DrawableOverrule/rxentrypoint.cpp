#include "pch.h"
#include "adsmigr.h"
#include "adsdef.h"
#include "adscodes.h"
#include "acestext.h"
#include "acedads.h"
#include "CMyLineOverrule.h"

void initapp()
{
	acedRegCmds->addCommand(cmd_group_name, _T("AddDrawableOverrule"), _T("AddDrawableOverrule"), ACRX_CMD_MODAL, AddDrawableOverrule);
	acedRegCmds->addCommand(cmd_group_name, _T("RemoveDrawableOverrule"), _T("RemoveDrawableOverrule"), ACRX_CMD_MODAL, RemoveDrawableOverrule);

	CMyLineOverrule::rxInit();
	acrxBuildClassHierarchy();
}

void unloadapp()
{
	RemoveDrawableOverrule();
	deleteAcRxClass(CMyLineOverrule::desc());
	acedRegCmds->removeGroup(cmd_group_name);
}


extern "C" AcRx::AppRetCode zcrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
{
	switch (msg)
	{
		case AcRx::kInitAppMsg:
		{
			acrxDynamicLinker->unlockApplication(appId);
			acrxDynamicLinker->registerAppMDIAware(appId);
			initapp();
		}
		break;
		case AcRx::kUnloadAppMsg:
		{
			unloadapp();
		}
		break;
		default:
			break;
	}
	return AcRx::kRetOK;
}



#ifdef _WIN64
#pragma comment(linker, "/export:zcrxEntryPoint,PRIVATE")
#pragma comment(linker, "/export:zcrxGetApiVersion,PRIVATE")
#else // WIN32
#pragma comment(linker, "/export:_zcrxEntryPoint,PRIVATE")
#pragma comment(linker, "/export:_zcrxGetApiVersion,PRIVATE")
#endif

