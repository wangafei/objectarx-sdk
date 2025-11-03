#include "pch.h"
#include "adsmigr.h"
#include "adsdef.h"
#include "adscodes.h"
#include "acestext.h"
#include "acedads.h"
#include "AcExtensionModule.h"
#include "SampleDlg.h"
#include "rxmfcapi.h"

extern HWND adsw_acadMainWnd();

AC_IMPLEMENT_EXTENSION_MODULE(theArxDLL);

void DispEntInfoMFC();
SampleDlg *pDialog = NULL;
void closeDialog()
{
	if (pDialog == NULL)
	{
		return;
	}

	BOOL bRet = pDialog->DestroyWindow();
	if (bRet)
	{
		pDialog = NULL;
	}
}

void initapp()
{
	acedRegCmds->addCommand(cmd_group_name, _T("DispEntInfoMFC"), _T("DispEntInfoMFC"), ACRX_CMD_MODAL, DispEntInfoMFC);
}

void unloadapp()
{
	closeDialog();
	acedRegCmds->removeGroup(cmd_group_name);
}

void DispEntInfoMFC()
{
	if (pDialog == NULL)
	{
		pDialog = new SampleDlg(acedGetAcadFrame());
		pDialog->Create(IDD_DIALOG1);
		pDialog->ShowWindow(SW_SHOW);
	}
	else
	{
		pDialog->ShowWindow(SW_SHOW);
	}
}

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		theArxDLL.AttachInstance(hInstance);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		theArxDLL.DetachInstance();
	}
	return 1;   // ok
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
		case AcRx::kLoadDwgMsg:
		{
			// Add your code here.
		}
		break;
		case AcRx::kUnloadDwgMsg:
		{
			// Add your code here.
		}
		break;
		case AcRx::kInvkSubrMsg:
		{
			// Add your code here.
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

