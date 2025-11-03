

#ifndef __ZAD_APPFRAME_H__
#define __ZAD_APPFRAME_H__

#include "zAdExportDef.h"

class ZdImpApplicationFrame;
class ZdImpMenuBar;
class ZdVisualElementBase;
class ZDAF_PORT ZdColorTheme;
class ZDAF_PORT ZdApplicationFrameReactor;
class ZDAF_PORT ZdMenuBar;

typedef LRESULT (*LPFNAPPFRAMECALLBACK)(UINT nIndex, void* pUserData, void *pContextData);

class ZDAF_PORT ZdCallDataTooltipInfo
{
public:

    ZdCallDataTooltipInfo(int nToolType, wchar_t* pBtnStr);

    int GetToolType();
    void SetToolType(int nToolType);
    wchar_t* GetButtonText();
    void SetButtonText(wchar_t* pBtnStr);

private:
   
	ZdCallDataTooltipInfo();
	
	ZdCallDataTooltipInfo(const ZdCallDataTooltipInfo& callDataTooltipInfo);
	ZdCallDataTooltipInfo& operator=(const ZdCallDataTooltipInfo& callDataTooltipInfo);

    int m_nToolType;

    wchar_t *m_pBtnStr;
};

class IWebServicesLoader
{
public:
    virtual bool LoadModule() = 0;

protected:
    virtual ~IWebServicesLoader() {}
};

class ZDAF_PORT ZdApplicationFrame
{
public:
    
    enum Zd_AppFrame_Const 
    {
		kZdApplicationStatusBarHeight_Min = 24,                     
		kZdDefaultDpi = 96
    };

    enum Zd_Frame_States
    {
        kZd_Frame_None = 0,
        kZd_Frame_DisableSize = 1,
        kZd_Frame_DisableMove = 2,
        kZd_Frame_DisableClose = 4,
    };

    enum Zd_HostWindow_States 
    {
		kZd_DocumentActivated = 1,
		kZd_MenuSelect        = 2,
		kZd_MDIStateChanged   = 3,
		kZd_WindowPosChanged  = 4,
		kZd_SessionInit       = 5,
		kZd_SessionDone       = 6,
		kZd_SettingChanged    = 7,
		kZd_MDIMetricsChanged = 8,
		kZd_SetWindowText     = 9,
		kZd_VisibilityChanged = 10,
		kZd_GetWindowText     = 11,
		kZd_GetWindowTextLen  = 12,
		kZd_SysColorChanged   = 13
    };

    enum Zd_AppFrame_Indexes
    {
        kZd_Index_ApplicationButton = 0,
        kZd_Index_QATBar = 1,
        kZd_Index_SysBtnGroup = 2,
        kZd_Index_InfoCenter = 3,
        kZd_Index_DocName = 4,
        kZd_Index_MenuBar = 5,
        kZd_Index_DocControl = 6
    };

    enum Zd_ApplicationButtonId
    {
        kZd_ApplicationButtonId_Big,
        kZd_ApplicationButtonId_Small,
        kZd_ApplicationButtonId_Window,
    };


    enum Zd_AppFrame_ToolTipId 
    {
        kZd_ToolId_ApplicationButton    = 1000,
    };

    enum Zd_Callback_Index 
    {
		kZd_ApplicationButton_IsOpen,
		kZd_ApplicationButton_ShowSmallButton,
		kZd_ToolTip_Close,
		kZd_ToolTip_Show,
		kZd_MenuBar_Show,
		kZd_MenuBar_ExecuteMenuItem,
		kZd_WorkSpaceInfo,
		kZd_GetProductName,
		kZd_Ribbon_IsDockedTop,
		kZd_ZCAD_InPlotPreview,
		kZd_ZCAD_GetDataSource,
		kZd_RecalcLayout,
		kZd_StayActive,
		kZd_GetMDIClient,
		kZd_MDIGetActive,
		kZd_SkipStandardBackgroundDraw,
		kZd_SkipProductNameUpdate,
        kZd_CustomDraw,
        kZd_NcCalcSize
    };

    enum Zd_Product_Character_Set
    {
		kZd_Unicode,
		kZd_MBCS
    };

    static void SetResourcesPath(LPCWSTR lpszName);
    static ZdApplicationFrame* CreateInstance(HWND hWndMainFrame);

    virtual ~ZdApplicationFrame();

    bool Initialize();

    void SessionInitialized();

    ZdMenuBar* GetMenuBar();

    void SetDocumentName(LPCWSTR wszDocumentName);

    bool SetProductLogo(HBITMAP hBitmap);
    bool SetBrand(HBITMAP hBitmap);
    bool SetProductIcon(HICON hIcon);
    bool SetMainMenu(HMENU hMainMenu);
    bool SetMainFrame(HWND hWndMainFrame);
    bool SetMainFrameRect(RECT rectMainFrame);
    bool SetProductCharacterSet(Zd_Product_Character_Set charSet);
    bool SetProductName(LPCWSTR lpszName);
    void SetUseModernizedUI(bool bUse);
    void DisableVistaUI();
    bool SetApplicationWindowButton(HBITMAP hBitmap, 
        HBITMAP hHotBitmap, HBITMAP hSelectedBitmap);
    bool SetApplicationButton(HBITMAP hBitmap, 
        HBITMAP hHotBitmap, HBITMAP hSelectedBitmap);
    bool SetSmallApplicationButton(HBITMAP hBitmap, 
        HBITMAP hHotBitmap, HBITMAP hSelectedBitmap);
    bool SetApplicationButtonSize(Zd_ApplicationButtonId nButtonId, SIZE size);
    void EnableWindows11UI();

    bool IsMenuBarVisible();
    void ShowMenuBar(bool bShow = true);

    void UpdateApplicationButton();
    bool IsApplicationButtonEnabled() const;
    void EnableApplicationButton(bool bEnable = true);

    void ForceFrameRepaint(HWND hWnd);

    unsigned long GetFrameStates();
    unsigned long SetFrameStates(unsigned long dwFrameStates);

    bool AddFrameReactor(ZdApplicationFrameReactor *pFrameReactor);
    bool RemoveFrameReactor(ZdApplicationFrameReactor *pFrameReactor);

    LPFNAPPFRAMECALLBACK AddFrameCallback(LPFNAPPFRAMECALLBACK pfnCallback, void* pUserData);

    bool TranslateMainFrameMessage(MSG *pMessage);
    BOOL PreTranslateMessageHandler(MSG* pMsg);

    LRESULT ProcessMainFrameMessage(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam);
    bool HostWindowStateChanged(UINT nState, WPARAM wParam, LPARAM lParam);

    HWND GetAppFrameHwnd();

    HWND GetQuickAccessToolBarHwnd();
    bool IsQuickAccessToolBarVisible();
    void ShowQuickAccessToolBar(bool bShow);

    HWND GetInfoCenterControl();
    bool SetInfoCenterControl(HWND hControl);
    void EnableInfoCtrCtrl(BOOL bEnable);
    void UpdateInfoCenterControl();


    int GetDocumentControlHeight() const;

    void TrackPopupByMenuCmd(int nIndex);
    void EnableMenuBar(bool bEnable);
    void EnableSysBtnGroup(bool bEnable);
    void SetExitOnApplicationButtonDoubleClick(bool bExit);
    bool GetExitOnApplicationButtonDoubleClick();
    const wchar_t * GetApplicationButtonClassName();

    bool IsWebServicesEnabled() const;

    void EnableWebServices(bool isWebServicesEnabled);

    int GetCurrentLocale(wchar_t* locale, int size) const;

    void SetCurrentLocale(const wchar_t* locale);

    void SetSerialNumber(const wchar_t* snumber);

	
    void SetDecryptedConsumerKey(const wchar_t* skey);

    
#ifdef _WIN32
    __declspec(deprecated("**This function is obsolete**")) 
#endif 
    int GetCachePath(wchar_t *path, int size) const;

#ifdef _WIN32
    __declspec(deprecated("**This function is obsolete. No need to call this function anymore.**")) 
#endif 
    void SetCachePath(const wchar_t* path);

    void SetWebServicesLoader(IWebServicesLoader* loader);

    IWebServicesLoader* GetWebServicesLoader() const;

    bool IsLoggedIn() const;

    int GetLoginUserName(wchar_t* name, int size) const;

    
    int GetLoginUserId(wchar_t* userId, int size) const;

    int GetServer() const;

    bool IsSyncServiceInstalled() const;

	HWND GetClicUI(int width, int height);

	void HideClicUI();

	void ShowClicUI();
	
protected:
    ZdApplicationFrame(HWND hWndMainFrame); 

    static ZdApplicationFrame *spAppFrame;

    ZdImpApplicationFrame *mpImpAppFrame;

    ZdMenuBar *mpAdMenuBar;
};

#endif
