// SimplePalette.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "SimpleBar.h"

CSimpleBar* gpBar = NULL;

static void doIt()
{
  if (gpBar)
  {
    gpBar->ShowPane(TRUE, FALSE, TRUE);
  }
  else
  {
    acedInitGet(0, L"Float Dock");
    ACHAR result[132] = {0};
    int rc = acedGetKword(L"\nFloat or Docking?", result);
    bool bFloat = true;
    if (rc == RTNONE)
    {
      bFloat = true;
    }
    else if (rc != RTNORM)
    {
      return;
    }
    else
    {
      bFloat = _wcsicmp(result, L"Float") == 0;
    }

    CSize sizeDefault(200, 450);
    CRect rcDefault(CPoint(150,200), sizeDefault);

    gpBar = new CSimpleBar;
    gpBar->SetMinSize(sizeDefault);

    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_SIZE_DYNAMIC | CBRS_GRIPPER;
    if (bFloat)
    {
      dwStyle |= CBRS_FLOATING;
    }
    else
    {
      dwStyle |= CBRS_RIGHT;
    }
    
    gpBar->Create(L"Simple", dwStyle,
      rcDefault, acedGetAcadFrame());
    gpBar->EnableDocking(CBRS_ALIGN_LEFT | CBRS_ALIGN_RIGHT | CBRS_ALIGN_BOTTOM);
    if (bFloat)
    {
      gpBar->FloatPane(rcDefault, DM_SHOW, true);
    }
    else
    {
      acedGetAcadFrame()->DockPane(gpBar);
    }
  }
}

void initApp()
{
  acedRegCmds->addCommand(_T("ASDK_SAMPLES_SIMPLEPALETTE"),
    _T("ASDK_SIMPLEPALETTE"), _T("SIMPLEPALETTE"), ACRX_CMD_MODAL,
    doIt);
}


void unloadApp()
{
  acedRegCmds->removeGroup(_T("ASDK_SAMPLES_SIMPLEPALETTE"));

  if (gpBar)
  {
    gpBar->DestroyWindow();
    delete gpBar;
    gpBar = NULL;
  }
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