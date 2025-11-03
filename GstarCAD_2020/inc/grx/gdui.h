#ifndef _Gdui_h
#define _Gdui_h

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// Note: _GDUI_BUILD should be defined only when building the DLL.

#ifdef  _GDUI_BUILD
#  define   GDUI_PORT  __declspec(dllexport)
#else
#  define   GDUI_PORT  __declspec(dllimport)
#endif

class GDUI_PORT CGdUiThemeManager;    // INTERNAL USE ONLY

/////////////////////////////////////////////////////////////////////////////
// Initialize the extension DLL, register the classes, etc
// Call this exported function from your Dll or Executable once
// - an ideal location is the InitInstance() member function 

void GDUI_PORT InitGdUiDLL();

// This function shows an alert type dialog with three buttons. Caption
// string and text for each button are arguments along with a default button
// 0 based index. Returns 0 based button index or -1 on CANCEL. Button 2
// is always the CANCEL button.
int  GDUI_PORT GdUiAlertDialog (
    LPCTSTR captionText,
    LPCTSTR msg0Text,
    LPCTSTR button0Text,                      
    LPCTSTR button1Text,
    UINT defButton = 0          // Means first button is default.
);

int  GDUI_PORT GdUiDataValidationLevel ();      // INTERNAL USE ONLY

// Helper function to expand a help file name into a fully-qualified pathname.
BOOL GDUI_PORT GdUiFindContextHelpFullPath (
    LPCTSTR fileName, CString& fullPath
);

void GDUI_PORT GdUiSubstituteShellFont (CWnd& dlg, CFont& font);
CGdUiThemeManager GDUI_PORT * GdUiGetThemeManager();  // INTERNAL USE ONLY

/////////////////////////////////////////////////////////////////////////////
// Class prototypes

class GDUI_PORT CGdUiBaseDialog;
class GDUI_PORT CGdUiComboBox;
class GDUI_PORT CGdUiDialog;
class GDUI_PORT CGdUiDialogBar;
class GDUI_PORT CGdUiTab;
class GDUI_PORT CGdUiTabChildDialog;
class GDUI_PORT CGdUiTabExtensionManager;
class GDUI_PORT CGdUiTabMainDialog;
class GDUI_PORT CGdUiDialogWorksheet;  // INTERNAL USE ONLY
class GDUI_PORT CGdUiDropTarget;
class GDUI_PORT CGdUiTheme;            // INTERNAL USE ONLY
class GDUI_PORT CGdUiPalette;
class GDUI_PORT CGdUiPaletteSet;
class GDUI_PORT CGdUiThemeMgrReactor;  // INTERNAL USE ONLY
class GDUI_PORT CGduiLabelEdit;  // INTERNAL USE ONLY

/////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////

// WINREG.H declares HKEY, needed by gduiRegistryAccess.h
#include <winreg.h>

//// AFXOLE.H declares COleDropTarget needed by gduiDropTarget.h
#include <afxole.h>

#include "gduiRegistryAccess.h"

#include "gduiMessage.h"
#include "gduiDropTarget.h"
#include "gduiTabExtension.h"
#include "gduiTextTip.h"
#include "gduiButton.h"
#include "gduiTabCtrl.h"

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

#include "gduiVolumeDescriptor.h"
#include "gduiPathname.h"
#include "gduiPalette.h"
#include "gduiPaletteSet.h"


// 图片的大小
#define IMG_SIZEX_16 16
#define IMG_SIZEY_16 16

#define IMG_SIZEX_32 32
#define IMG_SIZEY_32 32

#define IMG_SIZEX_48 48
#define IMG_SIZEY_48 48

#define IMG_SIZEX_64 64
#define IMG_SIZEY_64 64

#define IMG_SIZEX_80 80
#define IMG_SIZEY_80 80

#define IMG_SIZEX_96 96
#define IMG_SIZEY_96 96

#define IMG_SIZEX_112 112
#define IMG_SIZEY_112 112

#define IMG_SIZEX_128 128
#define IMG_SIZEY_128 128

#define IMG_SIZEX_144 144
#define IMG_SIZEY_144 144

#define IMG_SIZEX_160 160
#define IMG_SIZEY_160 160

enum ImageSize
{
  ImageSize_16 = 0,
  ImageSize_32 = 1,
  ImageSize_48 = 2,
  ImageSize_64 = 3,
  ImageSize_128 = 4,
};

namespace GdUi
{
  enum GdUiIconMode
  {
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

  // Description：支持4k屏添加的接口，用来计算图标的尺寸
  // Author：Hongjihai，2018/9/4 13:15:54
int GDUI_PORT GdUiGetImageDPICx();
int GDUI_PORT GdUiGetImageDPICy();
int GDUI_PORT GdUiGetCtrlDPISize(const int val);
void GDUI_PORT GdUiSetCtrlItemWndHeightDPISize(CWnd* pWnd, const bool isHavingImage, const bool isSmallImage);
void GDUI_PORT GdUiSetCtrlItemHeightDPISize(CWnd* pWnd, const bool isHavingImage, const bool isSmallImage);

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif

//////////////////////////////////////////////////////////////////////////////
