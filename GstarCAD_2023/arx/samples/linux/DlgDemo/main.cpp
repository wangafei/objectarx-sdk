/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//

#include <rxdlinkr.h>
#include <aced.h>
#include <adslib.h>
#include "demodialog.h"

void* gcedGetGcadDwgView();

void demo_dialog()
{
  auto hWnd = gcedGetGcadDwgView();
  if (hWnd == NULL)
    return;

  CGcQtDemoDialogWidget dlg((QWidget*)hWnd);

  if (QDialog::Accepted == dlg.doModal())
  {

  }
  
}

void initApp()
{
  acedRegCmds->addCommand(ACRX_T("ASDK_SAMPLES_DEMODIALOG"),
    ACRX_T("ASDK_DEMODIALOG"), ACRX_T("DEMODIALOG"), ACRX_CMD_MODAL,
    demo_dialog);
}


void unloadApp()
{
  acedRegCmds->removeGroup(ACRX_T("ASDK_SAMPLES_DEMODIALOG"));
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
  switch (msg) {
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

