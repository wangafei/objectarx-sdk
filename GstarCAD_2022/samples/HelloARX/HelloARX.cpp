#include <oaidl.h>
#include <aced.h>
#include <adslib.h>
#include "tchar.h"


void doIt()
{
  acutPrintf(_T("\nHello World."));
}

void initApp()
{
  acedRegCmds->addCommand(_T("ASDK_SAMPLES_HELLOWORLD"),
    _T("ASDK_HELLOWORLD"), _T("HELLOWORLD"), ACRX_CMD_MODAL,
    doIt);
}


void unloadApp()
{
  acedRegCmds->removeGroup(_T("ASDK_SAMPLES_HELLOWORLD"));
}


extern "C" AcRx::AppRetCode
  acrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
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
