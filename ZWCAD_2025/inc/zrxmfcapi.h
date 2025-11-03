
#include "zadesk.h"
#include "zAdAChar.h"
#include "zacStatusBar.h"
#include "zcore_rxmfcapi.h"

#ifndef ZD_RXMFCAPI_H
#define ZD_RXMFCAPI_H 1
#pragma pack (push, 8)

#ifndef WM_ZCAD_KEEPFOCUS
#define WM_ZCAD_KEEPFOCUS  (WM_USER+0x6D01)
#endif

class ZcDbDatabase;
class CDialogBar;
class ZdApplicationFrame;

#ifdef _ZSOFT_WINDOWS_

CWinApp* zcedGetZcadWinApp();

CDocument* zcedGetZcadDoc();

CView* zcedGetZcadDwgView();

CMDIFrameWnd* zcedGetZcadFrame();

CWnd* zcedGetZcadDockCmdLine();

CWnd* zcedGetZcadTextCmdLine();
#endif

HINSTANCE zcedGetZcadBrandingResourceInstance();

#ifdef _ZSOFT_WINDOWS_

typedef struct tagChildFrmSettings {

    ZcColorSettings m_ColorSettings;
    bool m_bShowLayoutBar;
    bool m_bShowScrollBar;
    CDialogBar *m_pDialogBar;
    bool m_bIsBedit;
} ZcChildFrmSettings;

BOOL zcedGetChildFrameSettings(ZcChildFrmSettings* pChildFrmSettings,
    CMDIChildWnd *pWnd);
BOOL zcedSetChildFrameSettings(ZcChildFrmSettings* pChildFrmSettings,
    CMDIChildWnd *pWnd);
#endif

#ifdef _ZSOFT_WINDOWS_

#ifdef _ZRX_CUSTOM_DRAG_N_DROP_

BOOL zcedRegisterCustomDropTarget(IDropTarget* pItarget);
BOOL zcedStartOverrideDropTarget(COleDropTarget* pTarget);

BOOL zcedRevokeCustomDropTarget();
BOOL zcedEndOverrideDropTarget(COleDropTarget* pTarget);

BOOL zcedAddDropTarget(COleDropTarget* pTarget);

BOOL zcedRemoveDropTarget(COleDropTarget* pTarget);

#endif
#endif

#ifdef _ZSOFT_WINDOWS_

ZcDbDatabase* ZcApGetDatabase(CView *pView);
#endif

const CString& zcedGetRegistryCompany();

BOOL zcedRegisterExtendedTab(const wchar_t* szAppName, const wchar_t* szDialogName);

HMENU zcedGetMenu(const wchar_t* pszAlias);

BOOL zcedSetIUnknownForCurrentCommand(const LPUNKNOWN);
BOOL zcedGetIUnknownForCurrentCommand(LPUNKNOWN &pUnk);

BOOL zcedShowDrawingStatusBars(BOOL bShow = TRUE);

#ifdef _ZSOFT_WINDOWS_

BOOL zcedRegisterStatusBarMenuItem(ZcStatusBarMenuItem* pItem,
                                   ZcStatusBarMenuItem::ZcStatusBarType nType);

BOOL zcedUnregisterStatusBarMenuItem(ZcStatusBarMenuItem* pItem,
                                     ZcStatusBarMenuItem::ZcStatusBarType nType);

BOOL zcedSetStatusBarPaneID(ZcPane* pPane,
                            ZcStatusBarMenuItem::ZcStatusBarType nType,
                            int nID);
#endif

void zcedSuppressFileMRU(bool bSuppress);

ZdApplicationFrame* zcedGetApplicationFrame();

typedef BOOL (* ZcedPreTranslateMsgFn)(MSG*);

BOOL zcedRegisterMainFramePreTranslateObserver(const ZcedPreTranslateMsgFn pfn);

BOOL zcedRemoveMainFramePreTranslateObserver(const ZcedPreTranslateMsgFn pfn);

bool zcedHatchPalletteDialog(const ZTCHAR* pchCurrentPattern, bool bIsShowCustomPattern, ZTCHAR*& prefchNewSelectedPattern);

int ZDCHatchGetRegistryHPFileName(CString& strHPFileName);
int ZDCHatchWriteRegistryHPFileName(CString strHPFileName);

#pragma pack (pop)
#endif
