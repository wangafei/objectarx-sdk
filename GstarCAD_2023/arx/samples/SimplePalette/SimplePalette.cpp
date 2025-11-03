/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// SimplePalette.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "CSimpleBar.h"

CSimpleBar* gpBar = NULL;

static void doIt()
{
	if (gpBar)
	{
		acedGetAcadFrame()->ShowControlBar(gpBar, TRUE, FALSE);
	}
	else
	{
		acedInitGet(0, L"Float Dock");
		ACHAR result[132] = { 0 };
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

		CSize sizeDefault(400, 450);
		CRect rcDefault(CPoint(150, 200), sizeDefault);

		gpBar = new CSimpleBar;

		DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_SIZE_DYNAMIC | CBRS_GRIPPER;
		if (bFloat)
		{
			dwStyle |= CBRS_FLOATING;
		}
		else
		{
			dwStyle |= CBRS_LEFT;
		}

		gpBar->Create(L"Simple", dwStyle, rcDefault, acedGetAcadFrame());
		gpBar->SetAutoRollup(FALSE);
		gpBar->EnableDocking(CBRS_ALIGN_LEFT | CBRS_ALIGN_RIGHT | CBRS_ALIGN_BOTTOM);
		if (bFloat)
		{
			acedGetAcadFrame()->FloatControlBar(gpBar, CPoint(100, 100), CBRS_ALIGN_TOP);
		}
		else
		{
			acedGetAcadFrame()->DockControlBar(gpBar, AFX_IDW_DOCKBAR_RIGHT);
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