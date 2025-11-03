/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gdui_h
#define _gdui_h

#if _MSC_VER >= 1000
#pragma once
#endif 

#include "gdui_port.h"

class GCAD_PORT CGdUiThemeManager;

void GCAD_PORT InitGdUiDLL();
int  GCAD_PORT GdUiAlertDialog(
  LPCTSTR captionText,
  LPCTSTR msg0Text,
  LPCTSTR button0Text,
  LPCTSTR button1Text,
  UINT defButton = 0
);
int  GCAD_PORT GdUiDataValidationLevel();
BOOL GCAD_PORT GdUiFindContextHelpFullPath(
  LPCTSTR fileName, CString& fullPath
);
void GCAD_PORT GdUiSubstituteShellFont(CWnd& dlg, CFont& font);
CGdUiThemeManager GCAD_PORT * GdUiGetThemeManager();
HWND GCAD_PORT GdUiGetSafeParentHwnd();
GCAD_PORT CWnd* GdUiGetSafeParentWnd();
bool GCAD_PORT GdUiSetDockBarMinWidth(int width);

class GCAD_PORT CGdUiBaseDialog;
class GCAD_PORT CGdUiComboBox;
class GCAD_PORT CGdUiDialog;
class GCAD_PORT CGdUiDialogBar;
class GCAD_PORT CGdUiFileDialog;
class GCAD_PORT CGdUiTab;
class GCAD_PORT CGdUiTabChildDialog;
class GCAD_PORT CGdUiTabExtensionManager;
class GCAD_PORT CGdUiTabMainDialog;
class GCAD_PORT CGdUiDialogWorksheet;
class GCAD_PORT CGdUiDropTarget;
class GCAD_PORT CGdUiTheme;
class GCAD_PORT CGdUiPalette;
class GCAD_PORT CGdUiPaletteSet;
class GCAD_PORT CGdUiThemeMgrReactor;
class GCAD_PORT CGduiLabelEdit;

#define MOVEX               0x00001
#define MOVEY               0x00002
#define MOVEXY              0x00003
#define ELASTICX            0x00010
#define ELASTICY            0x00020
#define ELASTICXY           0x00030

#pragma pack (push, 8)
typedef struct _dlgControlTag {
  DWORD       id;
  DWORD       flags;
  DWORD       pct;
} DLGCTLINFO, *PDLGCTLINFO;
#pragma pack (pop)

namespace GdUi
{
  enum GdUiIconMode {
    kSmall = 0,
    kLarge
  };

  enum GdUiImage
  {
    kImageSmall = 1,
    kImageLarge = 2,

    kImageEnable = 4,
    kImageDisable = 8,
  };

};


#include <winreg.h>

#include <afxole.h>

#include "gduiRegistryAccess.h"

#include "gduiMessage.h"
#include "gduiDropTarget.h"
#include "gduiTabExtension.h"
#include "gduiTextTip.h"

#include "gduiButton.h"
#include "gduiTabCtrl.h"
#include "gduiRichEditCtrl.h"

#include "gduiBaseDialog.h"
#include "gduiDialog.h"
#include "gduiDialogBar.h"
#include "gduiFileDialog.h"
#include "gduiTabChildDialog.h"
#include "gduiTabMainDialog.h"

#include "gduiEdit.h"
#include "gduiHeaderCtrl.h"
#include "gduiListBox.h"
#include "gduiListCtrl.h"
#include "gduiComboBox.h"

#include "gduiDock.h"

#include "gduiPathname.h"
#include "gduiPalette.h"
#include "gduiPaletteSet.h"


#endif
