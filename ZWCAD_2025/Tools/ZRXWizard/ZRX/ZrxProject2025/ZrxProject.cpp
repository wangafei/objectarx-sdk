// $projectname$.cpp : Defines the initialization routines for the DLL.
//
$if$ ($mfcdll$ == 2)
#include "pch.h"
#include "framework.h"
#include "AcExtensionModule.h"

// Define the sole extension module object.
// Now you can use the CAcModuleResourceOverride class in your application to switch to the correct resource instance.
AC_IMPLEMENT_EXTENSION_MODULE($projectname$DLL)

// DLL Entry Point
extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH) 
	{
		$projectname$DLL.AttachInstance(hInstance);
	}
	else if (dwReason == DLL_PROCESS_DETACH) 
	{
		$projectname$DLL.DetachInstance();
	}
	return 1;
}
$else$
#include "pch.h"
#include "framework.h"
#include "$projectname$.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// C$projectname$App

BEGIN_MESSAGE_MAP(C$projectname$App, CWinApp)
END_MESSAGE_MAP()


// C$projectname$App construction

C$projectname$App::C$projectname$App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only C$projectname$App object

C$projectname$App theApp;


// C$projectname$App initialization

BOOL C$projectname$App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
$endif$