#pragma once
#include <winreg.h>
#include <afxole.h>

#include "../grx/gdui.h"

#include "aduiRegistryAccess.h"

#include "aduiMessage.h"
#include "aduiDropTarget.h"
#include "aduiTabExtension.h"
#include "aduiTextTip.h"
#include "aduiButton.h"
#include "aduiTabCtrl.h"

#include "aduiBaseDialog.h"
#include "aduiDialog.h"
#include "aduiDialogBar.h"
#include "aduiFileDialog.h"
#include "aduiTabChildDialog.h"
#include "aduiTabMainDialog.h"

#include "aduiEdit.h"
#include "aduiHeaderCtrl.h"
#include "aduiListBox.h"
#include "aduiListCtrl.h"
#include "aduiComboBox.h"

#include "aduiDock.h"

#include "aduiVolumeDescriptor.h"
#include "aduiPathname.h"
#include "aduiPalette.h"
#include "aduiPaletteSet.h"

class CGdUiFileDialog;

#define  _ADUI_BUILD					_GDUI_BUILD
#define  ADUI_PORT						GDUI_PORT
#define  CAdUiThemeManager				CGdUiThemeManager
#define  InitAdUiDLL					InitGdUiDLL
#define  AdUiAlertDialog				GdUiAlertDialog
#define  AdUiDataValidationLevel		GdUiDataValidationLevel
#define  AdUiFindContextHelpFullPath	GdUiFindContextHelpFullPath
#define  AdUiSubstituteShellFont		GdUiSubstituteShellFont
#define  AdUiGetThemeManager			GdUiGetThemeManager

#define  CAdUiBaseDialog				CGdUiBaseDialog
#define  CAdUiComboBox					CGdUiComboBox
#define  CAdUiDialog					CGdUiDialog
#define  CAdUiDialogBar					CGdUiDialogBar
#define  CAdUiFileDialog				CGdUiFileDialog
#define  CAdUiTab						CGdUiTab		
#define  CAdUiTabChildDialog			CGdUiTabChildDialog		
#define  CAdUiTabExtensionManager		CGdUiTabExtensionManager	
#define  CAdUiTabMainDialog				CGdUiTabMainDialog	
#define  CAdUiDialogWorksheet 			CGdUiDialogWorksheet	
#define  CAdUiTheme        				CGdUiTheme
#define  CAdUiPalette					CGdUiPalette
#define  CAdUiPaletteSet				CGdUiPaletteSet
#define  CAdUiThemeMgrReactor			CGdUiThemeMgrReactor  
#define  CAduiLabelEdit					CGduiLabelEdit

#define  AdUi  GdUi
#define  AdUiIconMode	GdUiIconMode
#define  AdUiImage	    GdUiImage




