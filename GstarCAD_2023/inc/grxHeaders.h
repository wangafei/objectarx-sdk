/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "dbxHeaders.h"

#pragma pack (push, 8)
#pragma warning (disable: 4312 4275)

#pragma comment (lib ,"gccore.lib") 
#ifdef _AFXEXT
#pragma comment (lib ,"gcad.lib")
//  #pragma comment (lib ,"GcTc.lib")
//  #pragma comment (lib ,"GcTcUi.lib")
//  #pragma comment (lib ,"GcFdUi.lib")
#endif 
//#pragma comment (lib ,"GcFdEval.lib")
#ifdef _RENDER_SUPPORT_
#pragma comment (lib, "gvlib.lib")
#endif 
#ifdef _GSE_SUPPORT_
#ifndef GC_FULL_DEBUG
#pragma comment (lib ,"gseapi.lib")
#pragma comment (lib ,"gsiapi.lib")
#else
#pragma comment (lib ,"gseapid.lib")
#pragma comment (lib ,"gsiapid.lib")
#endif
#pragma comment (lib ,"userdata.lib")
#endif 

#include "gccmd.h"
#include "gced.h"
#include "gcdocman.h"
#include "gctrans.h"
#include "gcedsel.h"
#include "gcedxref.h"
#include "lngtrans.h"
#include "dbltrans.h"
#include "gcaplmgr.h"
#include "gcedinet.h"
#include "gcedinpt.h"
#include "GcDblClkEdit.h"
#include "GcGradThumbEng.h"

#include "dbjig.h"
#include "dbmatch.h"
#include "dbInterferencePE.h"
#include "dbosnap.h"

#include "clipdata.h"

#ifdef _AFXEXT
#include "gs.h"
#endif 
#include "GcGsManager.h"

#include "GcPl.h"
#include "GcPlDSDData.h"
#include "GcPlDSDEntry.h"
#include "GcPlHostAppServices.h"
#include "GcPlObject.h"
#include "GcPlPlotConfig.h"
#include "GcPlPlotConfigMgr.h"
#include "GcPlPlotEngine.h"
#include "GcPlPlotErrorHandler.h"
#include "GcPlPlotErrorHandlerLock.h"
#include "GcPlPlotFactory.h"
#include "GcPlPlotInfo.h"
#include "GcPlPlotInfoValidator.h"
#include "GcPlPlotLogger.h"
#include "GcPlPlotLoggingErrorHandler.h"
#include "GcPlPlotProgress.h"
#include "gcplplotreactor.h"
#include "gcplplotreactormgr.h"

#include "gcpublishreactors.h"
#include "gcpublishuireactors.h"

#include "gcdmmapi.h"
#include "gcdmmeplotproperties.h"
#include "gcdmmeplotproperty.h"
#include "gcdmmutils.h"

#ifdef _AFXEXT
#pragma warning (disable: 4275)
#include "gdui.h"
#include "GcExtensionModule.h"
#include "gduiBaseDialog.h"
#include "gduiButton.h"
#include "gduiComboBox.h"
#include "gduiDialog.h"
#include "gduiDialogBar.h"
#include "gduiDialogWorksheet.h"
#include "gduiDock.h"
#include "gduiDropTarget.h"
#include "gduiEdit.h"
#include "gduiFileDialog.h"
#include "gduiHeaderCtrl.h"
#include "gduiListBox.h"
#include "gduiListCtrl.h"
#include "gduiMessage.h"
#include "gduiPalette.h"
#include "gduiPaletteSet.h"
#include "gduiPathname.h"
#include "gduiRegistryAccess.h"
#include "gduiTabChildDialog.h"
#include "gduiTabCtrl.h"
#include "gduiTabExtension.h"
#include "gduiTabMainDialog.h"
#include "gduiTextTip.h"
#include "gduiTheme.h"
#include "gduiThemeManager.h"
#include "gduiCoupledGroupCtrl.h"
#include "gduiGroupCtrl.h"
#include "gduipathenums.h"

#include "gcui.h"
#include "rxmfcapi.h"
#include "GcStatusBar.h"
#include "gcuiButton.h"
#include "gcuiComboBox.h"
#include "gcuiDialog.h"
#include "gcuiDialogWorksheet.h"
#include "gcuidock.h"
#include "gcuiEdit.h"
#include "gcuiHeaderCtrl.h"
#include "gcuiListBox.h"
#include "gcuiListCtrl.h"
#include "gcuiNavDialog.h"
#include "gcuiPathname.h"
#include "gcuiTabCtrl.h"

#include "gNav.h"
#include "gNavArray.h"
#include "gNavData.h"
#include "gNavDataArray.h"
#include "gNavDialog.h"
#include "gNavFilter.h"
#include "gNavFilterArray.h"
#include "gNavListCtrl.h"

#include "GcTc.h"
#include "GcTcUiManager.h"
#include "GcTcUI.h"
#include "GcTcUiCatalogView.h"
#include "GcTcUiCatalogViewItem.h"
#include "GcTcUiPaletteView.h"
#include "GcTcUiToolPalette.h"
#include "GcTcUiToolPaletteSet.h"
#include "GcTcUiToolPaletteGroup.h"
#include "GcTcUiScheme.h"
//#include "GcTc_i.h"
#include "dcdispid.h"

#include "GcFdUi.h"
#include "GcFdUiFieldDialog.h"
#include "GcFdUiFieldDialogHook.h"
#include "GcFdUiFieldFormatDialog.h"
#include "GcFdUiFieldFormatList.h"
#include "GcFdUiFieldManager.h"
#include "GcFdUiFieldOptionDialog.h"
#include "GcFdUtil.h"

#endif

#include "gdsdlg.h"
#include "gdsrxdef.h"
#include "gdslib.h"

#include "gcssgetfilter.h"
#include "gcutasrt.h"
#include "grxEntryPoint.h"
#include "GcApDMgr.h"
#include "gcprofile.h"

#ifdef __ATLCOM_H__
#include "dynpropmgr.h"
#endif

#ifdef _INC_LEAGACY_HEADERS_
#include "ol_errno.h"
#endif

#ifdef _GSE_SUPPORT_
#include "asisys.h"
#include "asiappl.h"
#include "csptypes.h"
#include "avoidtry.h"
#include "asiucode.h"
#include "asiconst.h"
#include "asisdata.h"
#include "asiclass.h"
#include "aseconst.h"
#include "aseclass.h"
#endif

#ifdef _RENDER_SUPPORT_
#include "averror.h"
#include "avlib.h"
#endif

#pragma pack (pop)
