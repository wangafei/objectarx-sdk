#include "gcadstd.h"
#include "gcstatusbar.h"
#include "core_rxmfcapi.h"

#ifndef GD_RXMFCAPI_H
#define GD_RXMFCAPI_H 1
#pragma pack (push, 8)

#ifndef WM_GCAD_KEEPFOCUS
#define WM_GCAD_KEEPFOCUS  (WM_USER+0x6D01)
#endif // WM_GCAD_KEEPFOCUS

class GcDbDatabase;
class GcApStatusBar;
class CDialogBar;
class GdApplicationFrame;

#ifdef _GCAD_WINDOWS_

#include "afxmdiframewndex.h"

GCAD_DLL_DECL CWinApp* gcedGetGcadWinApp();

GCAD_DLL_DECL CDocument* gcedGetGcadDoc();

GCAD_DLL_DECL CView* gcedGetGcadDwgView();

GCED_DLL_DECL CMDIFrameWndEx* gcedGetGcadFrame();

GCAD_DLL_DECL CWnd* gcedGetGcadDockCmdLine();

GCAD_DLL_DECL CWnd* gcedGetGcadTextCmdLine();

#endif // _GCAD_WINDOWS_

GCED_DLL_DECL HINSTANCE gcedGetGcadResourceInstance();

GCED_DLL_DECL HINSTANCE gcedGetGcadBrandingResourceInstance();

GCAD_DLL_DECL BOOL gcedRegisterOnModal(const GcedOnModalFn pfn);

GCAD_DLL_DECL BOOL gcedRemoveOnModal(const GcedOnModalFn pfn); 

#ifdef _GCAD_WINDOWS_
// GCAD MDI Child Window Frame settings
typedef struct tagChildFrmSettings {
    // More to come later
    GcColorSettings m_ColorSettings;
    bool m_bShowLayoutBar;
    bool m_bShowScrollBar;
    CDialogBar *m_pDialogBar;
    bool m_bIsBedit;
} GcChildFrmSettings;

GCED_DLL_DECL BOOL gcedGetChildFrameSettings(GcChildFrmSettings* pChildFrmSettings,
    CMDIChildWnd *pWnd);

GCED_DLL_DECL BOOL gcedSetChildFrameSettings(GcChildFrmSettings* pChildFrmSettings,
    CMDIChildWnd *pWnd);

#endif


#ifdef _GCAD_WINDOWS_
#ifdef _GRX_CUSTOM_DRAG_N_DROP_

GCED_DLL_DECL BOOL gcedRegisterCustomDropTarget(IDropTarget* pItarget);
GCED_DLL_DECL BOOL gcedStartOverrideDropTarget(COleDropTarget* pTarget);

GCED_DLL_DECL BOOL gcedRevokeCustomDropTarget();
GCED_DLL_DECL BOOL gcedEndOverrideDropTarget(COleDropTarget* pTarget);

GCED_DLL_DECL BOOL gcedAddDropTarget(COleDropTarget* pTarget);

GCED_DLL_DECL BOOL gcedRemoveDropTarget(COleDropTarget* pTarget);

#endif // _ARX_CUSTOM_DRAG_N_DROP_
#endif // _GCAD_WINDOWS_

#ifdef _GCAD_WINDOWS_
GCAD_DLL_DECL GcDbDatabase* GcApGetDatabase(CView *pView);
#endif

GCED_DLL_DECL const CString& gcedGetRegistryCompany();

GCED_DLL_DECL BOOL gcedRegisterExtendedTab(LPCTSTR szAppName, LPCTSTR szDialogName);

// Return an HMENU given a .MNU file alias.
GCAD_DLL_DECL HMENU gcedGetMenu(LPCTSTR pszAlias);

GCED_DLL_DECL BOOL gcedIsInputPending ();

GCED_DLL_DECL BOOL gcedSetIUnknownForCurrentCommand(const LPUNKNOWN);
GCED_DLL_DECL BOOL gcedGetIUnknownForCurrentCommand(LPUNKNOWN &pUnk);

GCED_DLL_DECL int gcedSetStatusBarProgressMeter(const GCHAR* pszLabel, int nMinPos, int nMaxPos);
GCED_DLL_DECL int gcedSetStatusBarProgressMeterPos(int nPos);

GCED_DLL_DECL GcApStatusBar* gcedGetApplicationStatusBar();

GCED_DLL_DECL void gcedRestoreStatusBar();

GCED_DLL_DECL BOOL gcedShowDrawingStatusBars(BOOL bShow = TRUE);

GCED_DLL_DECL BOOL gcedDrawingStatusBarsVisible();

#ifdef _GCAD_WINDOWS_

GCED_DLL_DECL BOOL gcedRegisterStatusBarMenuItem(GcStatusBarMenuItem* pItem,
                                   GcStatusBarMenuItem::GcStatusBarType nType);


GCED_DLL_DECL BOOL gcedUnregisterStatusBarMenuItem(GcStatusBarMenuItem* pItem,
                                     GcStatusBarMenuItem::GcStatusBarType nType);

GCED_DLL_DECL BOOL gcedSetStatusBarPaneID(GcPane* pPane,
                            GcStatusBarMenuItem::GcStatusBarType nType,
                            int nID);
#endif // _GCAD_WINDOWS_

GCED_DLL_DECL void gcedSuppressFileMRU(bool bSuppress);

GCAD_DLL_DECL GdApplicationFrame* gcedGetApplicationFrame();

typedef BOOL (* GcedPreTranslateMsgFn)(MSG*);

GCAD_DLL_DECL BOOL gcedRegisterMainFramePreTranslateObserver(const GcedPreTranslateMsgFn pfn);

GCAD_DLL_DECL BOOL gcedRemoveMainFramePreTranslateObserver(const GcedPreTranslateMsgFn pfn); 

#pragma pack (pop)
#endif // GD_RXMFCAPI_H
