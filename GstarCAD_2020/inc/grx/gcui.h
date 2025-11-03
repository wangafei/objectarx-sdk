#ifndef _gcui_h
#define _gcui_h


#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// Note: _GCUI_BUILD should be defined only when building the DLL.

#ifdef  _GCUI_BUILD
#  define   GCUI_PORT  __declspec(dllexport)
#else
#  define   GCUI_PORT  __declspec(dllimport)
#endif

/////////////////////////////////////////////////////////////////////////////
// Initialize the extension DLL, register the classes, etc
// Call this exported function from your Dll or Executable once
// - an ideal location is the InitInstance() member function 

void GCUI_PORT InitGcUiDLL();

/////////////////////////////////////////////////////////////////////////////

HINSTANCE GCUI_PORT GcUiAppResourceInstance ();
LPCTSTR GCUI_PORT GcUiContextHelpFileName();
BOOL GCUI_PORT GcUiEnableToolTips ();
BOOL GCUI_PORT GcUiFindContextHelpFullPath (
    LPCTSTR fileName, CString& fullPath
);
BOOL GCUI_PORT GcUiIsInputPending ();
CWnd GCUI_PORT * GcUiMainWindow ();
void GCUI_PORT GcUiRootKey (CString& rootKey);

#include "gcuiButton.h"
#include "gcuiDialogWorksheet.h"
#include "gcuiDialog.h"
#include "gcuiTabCtrl.h"

typedef CGdUiRegistryAccess         CGcUiRegistryAccess;
typedef CGdUiRegistryDeleteAccess   CGcUiRegistryDeleteAccess;
typedef CGdUiRegistryWriteAccess    CGcUiRegistryWriteAccess;
typedef CGcUiTabChildDialog         CGcUiTabExtension;

/////////////////////////////////////////////////////////////////////////////

//#include "gced.h"
#include "dbmain.h"

#include "gcuiDock.h"
#include "gcuiEdit.h"
#include "gcuiHeaderCtrl.h"
#include "gcuiListBox.h"
#include "gcuiListCtrl.h"

#include "gcuiComboBox.h"

#include "gcuiString.h"

#include "gcuiPathname.h"

#include "gcuiNavDialog.h"

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif

//////////////////////////////////////////////////////////////////////////////
