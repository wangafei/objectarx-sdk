/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#include <rxdlinkr.h>
#include <aced.h>
#include <adslib.h>


void doIt()
{
  acutPrintf(ACRX_T("\nHello World."));
}

void initApp()
{
  acedRegCmds->addCommand(ACRX_T("ASDK_SAMPLES_HELLOWORLD"),
    ACRX_T("ASDK_HELLOWORLD"), ACRX_T("HELLOWORLD"), ACRX_CMD_MODAL,
    doIt);
}


void unloadApp()
{
  acedRegCmds->removeGroup(ACRX_T("ASDK_SAMPLES_HELLOWORLD"));
}


#if defined(__linux__)
#ifndef __declspec_dllexport
#define __declspec_dllexport      __attribute__ ((__visibility__("default")))
#endif

extern "C" AcRx::AppRetCode __declspec_dllexport acrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
#else
extern "C" AcRx::AppRetCode __declspec(dllexport) acrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
#endif
{
  switch(msg) {
  case AcRx::kInitAppMsg:
    acrxDynamicLinker->unlockApplication(appId);
    acrxDynamicLinker->registerAppMDIAware(appId);
    initApp();
    break;
  case AcRx::kUnloadAppMsg:
    unloadApp();
  }
  return AcRx::kRetOK;
}
