
#pragma once

#include "zacui_port.h"

ZCUI_PORT void InitZcUiDLL();

ZCUI_PORT HINSTANCE ZcUiAppResourceInstance ();
ZCUI_PORT HINSTANCE ZcUiAppBrandingResourceInstance ();

ZCUI_PORT LPCTSTR ZcUiContextHelpFileName();
ZCUI_PORT BOOL ZcUiEnableToolTips ();


ZCUI_PORT bool ZcUiFindContextHelpFullPath (
    LPCTSTR fileName, CString& fullPath
);
ZCUI_PORT bool ZcUiIsInputPending ();
ZCUI_PORT CWnd * ZcUiMainWindow ();
ZCUI_PORT void ZcUiRootKey (CString& rootKey);

typedef CZdUiRegistryAccess         CZcUiRegistryAccess;
typedef CZdUiRegistryDeleteAccess   CZcUiRegistryDeleteAccess;
typedef CZdUiRegistryWriteAccess    CZcUiRegistryWriteAccess;

#ifdef _ZSOFT_WINDOWS_

#include "zacuiButton.h"
#include "zacuiDialogWorksheet.h"
#include "zacuiDialog.h"
#include "zacuitabctrl.h"

typedef CZcUiTabChildDialog         CZcUiTabExtension;

#include "zaced.h"

#include "zacuiDock.h"
#include "zacuiEdit.h"
#include "zacuiheaderctrl.h"
#include "zacuilistbox.h"
#include "zacuilistctrl.h"
#include "zacuiComboBox.h"
#include "zacuipathname.h"
#include "zacuiNavDialog.h"
#endif

