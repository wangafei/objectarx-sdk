#ifndef __GD_APPFRAME_H__
#define __GD_APPFRAME_H__

// forward declarations
class GdImpApplicationFrame;
class GdImpMenuBar;
class GdVisualElementBase;
namespace Hccad 
{ 
    namespace WebServices 
    {
        class IWebServicesConfiguration;
    }
}

class GdColorTheme;
class GdApplicationFrameReactor;
class GdMenuBar;


typedef LRESULT (*LPFNAPPFRAMECALLBACK)(UINT nIndex, void* pUserData, void *pContextData);

class GdCallDataTooltipInfo
{
public:

    GdCallDataTooltipInfo(int nToolType, wchar_t* pBtnStr);

    int GetToolType();
    void SetToolType(int nToolType);
    wchar_t* GetButtonText();
    void SetButtonText(wchar_t* pBtnStr);

private:
    GdCallDataTooltipInfo();
    GdCallDataTooltipInfo(const GdCallDataTooltipInfo& callDataTooltipInfo);
    GdCallDataTooltipInfo& operator=(const GdCallDataTooltipInfo& callDataTooltipInfo);

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

//////////////////////////////////////////////////////////////////
// Application Frame
class GCAD_DLL_DECL GdApplicationFrame
{
public:
    enum Gd_AppFrame_Const 
    {
        kGdApplicationStatusBarHeight_Min = 24,                     // Minimum height of Application Status Bar
        kGdDefaultDpi = 96
    };
                               
    enum Gd_HostWindow_States 
    {
        kGd_DocumentActivated = 1,
        kGd_MenuSelect        = 2,
        kGd_MDIStateChanged   = 3,
        kGd_WindowPosChanged  = 4,
        kGd_SessionInit       = 5,
        kGd_SessionDone       = 6,
        kGd_SettingChanged    = 7,
        kGd_MDIMetricsChanged = 8,
        kGd_SetWindowText     = 9,
        kGd_VisibilityChanged = 10,
        kGd_GetWindowText     = 11,
        kGd_GetWindowTextLen  = 12,
        kGd_SysColorChanged   = 13
    };
                                            
    enum Gd_AppFrame_ToolTipId 
    {
        kGd_ToolId_ApplicationButton    = 1000,
    };
                      
    enum Gd_Callback_Index 
    {
        kGd_ApplicationButton_IsOpen,
        kGd_ApplicationButton_ShowSmallButton,
        kGd_ToolTip_Close,
        kGd_ToolTip_Show,
        kGd_MenuBar_Show,
        kGd_MenuBar_ExecuteMenuItem,
        kGd_WorkSpaceInfo,
        kGd_GetProductName,
        kGd_Ribbon_IsDockedTop,
        kGd_ACAD_InPlotPreview,
        kGd_ACAD_GetDataSource,
        kGd_RecalcLayout,
        kGd_StayActive,
        kGd_GetMDIClient,
        kGd_MDIGetActive,
        kGd_SkipStandardBackgroundDraw,
        kGd_SkipProductNameUpdate
    };
                                        
    enum Gd_Product_Character_Set
    {
        kGd_Unicode,
        kGd_MBCS
    };

    static void SetResourcesPath(LPCWSTR lpszName);
    static GdApplicationFrame* CreateInstance(HWND hWndMainFrame);

    virtual ~GdApplicationFrame();

    bool Initialize();

    void SessionInitialized();

    GdMenuBar* GetMenuBar();

    void SetDocumentName(LPCWSTR wszDocumentName);

    bool SetProductLogo(HBITMAP hBitmap);
    bool SetBrand(HBITMAP hBitmap);
    bool SetProductIcon(HICON hIcon);
    bool SetMainMenu(HMENU hMainMenu);
    bool SetMainFrame(HWND hWndMainFrame);
    bool SetMainFrameRect(RECT rectMainFrame);
    bool SetProductCharacterSet(Gd_Product_Character_Set charSet);
    bool SetProductName(LPCWSTR lpszName);
    bool SetApplicationButton(HBITMAP hBitmap, 
        HBITMAP hHotBitmap, HBITMAP hSelectedBitmap);
    bool SetSmallApplicationButton(HBITMAP hBitmap, 
        HBITMAP hHotBitmap, HBITMAP hSelectedBitmap);

    bool IsMenuBarVisible();
    void ShowMenuBar(bool bShow = true);

    void UpdateApplicationButton();
    bool IsApplicationButtonEnabled() const;
    void EnableApplicationButton(bool bEnable = true);

    void ForceFrameRepaint(HWND hWnd);

    unsigned long GetFrameStates();
    unsigned long SetFrameStates(unsigned long dwFrameStates);

    bool AddFrameReactor(GdApplicationFrameReactor *pFrameReactor);
    bool RemoveFrameReactor(GdApplicationFrameReactor *pFrameReactor);

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
    
    int GetCachePath(wchar_t *path, int size) const;

    void SetCachePath(const wchar_t* path);

    void SetWebServicesLoader(IWebServicesLoader* loader);
    
    IWebServicesLoader* GetWebServicesLoader() const;

protected:
    GdApplicationFrame(HWND hWndMainFrame); 

    static GdApplicationFrame *spAppFrame;

    GdImpApplicationFrame *mpImpAppFrame;

    GdMenuBar *mpGdMenuBar;
};

#endif
