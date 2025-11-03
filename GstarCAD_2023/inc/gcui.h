/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gcui_h
#define _gcui_h

#if _MSC_VER >= 1000
#pragma once
#endif 


#ifdef  _GCUI_BUILD
#  define   GCUI_PORT  __declspec(dllexport)
#else
#  define   GCUI_PORT
#endif


GCUI_PORT void InitGcUiDLL();


GCUI_PORT HINSTANCE GcUiAppResourceInstance();
GCUI_PORT HINSTANCE GcUiAppBrandingResourceInstance();
GCUI_PORT LPCTSTR GcUiContextHelpFileName();
GCUI_PORT BOOL GcUiEnableToolTips();
GCUI_PORT BOOL GcUiFindContextHelpFullPath(
  LPCTSTR fileName, CString& fullPath
);
GCUI_PORT BOOL GcUiIsInputPending();
GCUI_PORT CWnd * GcUiMainWindow();
GCUI_PORT void GcUiRootKey(CString& rootKey);


typedef CGdUiRegistryAccess         CGcUiRegistryAccess;
typedef CGdUiRegistryDeleteAccess   CGcUiRegistryDeleteAccess;
typedef CGdUiRegistryWriteAccess    CGcUiRegistryWriteAccess;


#ifdef _GSOFT_WINDOWS_

#include "gcuiButton.h"
#include "gcuiDialogWorksheet.h"
#include "gcuiDialog.h"
#include "gcuiTabCtrl.h"

typedef CGcUiTabChildDialog         CGcUiTabExtension;

#include "gced.h"

#include "gcuidock.h"
#include "gcuiEdit.h"
#include "gcuiHeaderCtrl.h"
#include "gcuiListBox.h"
#include "gcuiListCtrl.h"
#include "gcuiComboBox.h"
#include "gcuiPathname.h"
#include "gcuiNavDialog.h"
#endif 

#endif
