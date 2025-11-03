#pragma once

#include "aced.h"
#include "../grx/gcui.h"

#include "acuiButton.h"
#include "acuiDialogWorksheet.h"
#include "acuiDialog.h"
#include "acuiTabCtrl.h"
#include "acuiDock.h"
#include "acuiEdit.h"
#include "acuiHeaderCtrl.h"
#include "acuiListBox.h"
#include "acuiListCtrl.h"
#include "acuiComboBox.h"
#include "acuiString.h"
#include "acuiPathname.h"
#include "acuiNavDialog.h"

#define  _ACUI_BUILD  _GCUI_BUILD
#define  ACUI_PORT    GCUI_PORT

#define  InitAcUiDLL  InitGcUiDLL

#define  AcUiAppResourceInstance      GcUiAppResourceInstance
#define  AcUiContextHelpFileName      GcUiContextHelpFileName
#define  AcUiEnableToolTips           GcUiEnableToolTips
#define  AcUiFindContextHelpFullPath  GcUiFindContextHelpFullPath
#define  AcUiIsInputPending           GcUiIsInputPending
#define  AcUiMainWindow               GcUiMainWindow
#define  AcUiRootKey                  GcUiRootKey

#define	CAcUiRegistryAccess       CGcUiRegistryAccess
#define	CAcUiRegistryDeleteAccess CGcUiRegistryDeleteAccess
#define	CAcUiRegistryWriteAccess  CGcUiRegistryWriteAccess
#define	CAcUiTabExtension         CGcUiTabExtension