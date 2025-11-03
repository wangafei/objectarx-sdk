/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#include "gsoft.h"
#include "GdGChar.h"
#include "GcStatusBar.h"
#include "core_rxmfcapi.h"

#ifndef GD_RXMFCAPI_H
#define GD_RXMFCAPI_H 1
#pragma pack (push, 8)

#ifndef WM_GCAD_KEEPFOCUS
#define WM_GCAD_KEEPFOCUS  (WM_USER+0x6D01)
#endif

class GcDbDatabase;
class CDialogBar;
class GdApplicationFrame;

#ifdef _GSOFT_WINDOWS_

GCAD_PORT CWinApp*      gcedGetGcadWinApp();
GCAD_PORT CDocument*    gcedGetGcadDoc();
GCAD_PORT CView*        gcedGetGcadDwgView();
GCAD_PORT CMDIFrameWnd* gcedGetGcadFrame();
GCAD_PORT CWnd*         gcedGetGcadDockCmdLine();
GCAD_PORT CWnd*         gcedGetGcadTextCmdLine();
#endif

GCAD_PORT HINSTANCE     gcedGetGcadBrandingResourceInstance();

#ifdef _GSOFT_WINDOWS_
typedef struct tagChildFrmSettings
{
  GcColorSettings m_ColorSettings;
  bool            m_bShowLayoutBar;
  bool            m_bShowScrollBar;
  CDialogBar     *m_pDialogBar;
  bool            m_bIsBedit;
} GcChildFrmSettings;

GCAD_PORT BOOL gcedGetChildFrameSettings(GcChildFrmSettings* pChildFrmSettings, CMDIChildWnd *pWnd);
GCAD_PORT BOOL gcedSetChildFrameSettings(GcChildFrmSettings* pChildFrmSettings, CMDIChildWnd *pWnd);
#endif

#ifdef _GSOFT_WINDOWS_
#ifdef _GRX_CUSTOM_DRAG_N_DROP_
GCAD_PORT BOOL gcedRegisterCustomDropTarget(IDropTarget* pItarget);
GCAD_PORT BOOL gcedStartOverrideDropTarget(COleDropTarget* pTarget);
GCAD_PORT BOOL gcedRevokeCustomDropTarget();
GCAD_PORT BOOL gcedEndOverrideDropTarget(COleDropTarget* pTarget);
GCAD_PORT BOOL gcedAddDropTarget(COleDropTarget* pTarget);
GCAD_PORT BOOL gcedRemoveDropTarget(COleDropTarget* pTarget);

#endif
#endif

#ifdef _GSOFT_WINDOWS_
GCAD_PORT GcDbDatabase* GcApGetDatabase(CView *pView);
#endif

GCAD_PORT const CString& gcedGetRegistryCompany();

GCAD_PORT BOOL gcedRegisterExtendedTab(const wchar_t* szAppName, const wchar_t* szDialogName);

GCAD_PORT HMENU gcedGetMenu(const wchar_t* pszAlias);

GCAD_PORT BOOL gcedSetIUnknownForCurrentCommand(const LPUNKNOWN);
GCAD_PORT BOOL gcedGetIUnknownForCurrentCommand(LPUNKNOWN &pUnk);

GCAD_PORT BOOL gcedShowDrawingStatusBars(BOOL bShow = TRUE);

#ifdef _GSOFT_WINDOWS_
GCAD_PORT BOOL gcedRegisterStatusBarMenuItem(GcStatusBarMenuItem* pItem,
                             GcStatusBarMenuItem::GcStatusBarType nType);
GCAD_PORT BOOL gcedUnregisterStatusBarMenuItem(GcStatusBarMenuItem* pItem,
                               GcStatusBarMenuItem::GcStatusBarType nType);
GCAD_PORT BOOL gcedSetStatusBarPaneID(GcPane* pPane,
         GcStatusBarMenuItem::GcStatusBarType nType,
                                          int nID);
#endif

GCAD_PORT void gcedSuppressFileMRU(bool bSuppress);

GCAD_PORT GdApplicationFrame* gcedGetApplicationFrame();

typedef BOOL (* GcedPreTranslateMsgFn)(MSG*);

GCAD_PORT BOOL gcedRegisterMainFramePreTranslateObserver(const GcedPreTranslateMsgFn pfn);
GCAD_PORT BOOL gcedRemoveMainFramePreTranslateObserver(const GcedPreTranslateMsgFn pfn);

#pragma pack (pop)
#endif
