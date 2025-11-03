

#ifndef _ZCSTATUSBAR_H
#define _ZCSTATUSBAR_H 1

#pragma pack (push, 8)
#ifdef NEW_STATUS_BAR
#define SB_DEPRECATED __declspec(deprecated)
#else
#define SB_DEPRECATED
#endif

#ifndef ZCAD_PORT
#define ZCAD_PORT
#endif

#include "zacdocman.h"
#include "zadesk.h"

class CMenu;
class ZCAD_PORT ZcStatusBarItem
{
public:
    ZcStatusBarItem();
    ZcStatusBarItem(const CString& strId, bool isTrayItem);
    virtual ~ZcStatusBarItem();

    bool IsTrayItem() const;
    const CString& GetName() const;
    virtual BOOL SetIcon(HICON hIcon);
    virtual HICON GetIcon() const;

    virtual BOOL SetToolTipText(const CString& strText);
    virtual BOOL GetToolTipText(CString& strText) const;

    SB_DEPRECATED virtual BOOL QueryToolTipText(CString& strText) const;

    virtual void Enable(BOOL bValue);
    virtual BOOL IsEnabled();

    virtual void SetVisible(BOOL bIsVisible);
    virtual BOOL IsVisible();

    virtual void OnLButtonDown(UINT nFlags, CPoint point);
    virtual void OnRButtonDown(UINT nFlags, CPoint point);
    virtual void OnLButtonDblClk(UINT nFlags, CPoint point);

    virtual void OnDelete();

    SB_DEPRECATED virtual BOOL ClientToScreen(LPPOINT lpPoint);
    SB_DEPRECATED virtual BOOL ClientToScreen(LPRECT lpRect);

    SB_DEPRECATED virtual BOOL ScreenToClient(LPPOINT lpPoint);
    SB_DEPRECATED virtual BOOL ScreenToClient(LPRECT lpRect);

    virtual UINT DisplayContextMenu(CMenu& menu, CPoint point);

    SB_DEPRECATED virtual BOOL ShowTraySettingsDialog();

    SB_DEPRECATED virtual void SetContentChanged(BOOL bChanged) {m_bContentChanged = bChanged;}
    SB_DEPRECATED virtual BOOL ContentChanged() const {return m_bContentChanged;}

    SB_DEPRECATED virtual void SetVisibilityChanged(BOOL bChanged) {m_bVisibilityChanged = bChanged;}
    SB_DEPRECATED virtual BOOL VisibilityChanged() const {return m_bVisibilityChanged;}

    SB_DEPRECATED virtual void SetInternalData(void* pData, BOOL bForDocSwitch = FALSE);
    SB_DEPRECATED virtual void* GetInternalData(BOOL bForDocSwitch = TRUE) const;
    void*   GetData();
    int GetID() const;
    void SetID(int id);
    CString& GetActiveImageState() const;
    void SetActiveImageState(const CString& strActiveImageState);

private:
    HICON           m_hIcon;
    CString         m_strToolTipText;
    BOOL            m_bEnabled;
    BOOL            m_bVisible;
    BOOL            m_bContentChanged;
    BOOL            m_bVisibilityChanged;
    void*           m_pData;
    void*           m_pDocSwitchData;
};

#define ZCSB_NOBORDERS  (1<<0)
#define ZCSB_INACTIVE   (1<<1)
#define ZCSB_STRETCH    (1<<2)
#define ZCSB_ACTIVE     (1<<3)
#define ZCSB_COMMAND    (1<<4)
#define ZCSB_POPUP      (1<<5)
#define ZCSB_DIVIDER    (1<<6)
#define ZCSB_SUBDIVIDER (1<<7)
#define ZCSB_INDETERMINATE  (1<<8)
#define ZCSB_ONETIME    (1<<9)

#define ZCSB_POPOUT     ZCSB_INACTIVE
#define ZCSB_NORMAL     ZCSB_ACTIVE
class ZCAD_PORT ZcPane : public ZcStatusBarItem
{
public:
    ZcPane();
	ZcPane(const CString& strId); 
    virtual ~ZcPane();

    virtual BOOL SetIcon(HICON hIcon);
    virtual HICON GetIcon() const;

    virtual BOOL SetText(const CString& strText);
    virtual BOOL GetText(CString& strText) const;

    virtual BOOL SetStyle(int nStyle);
    virtual int GetStyle() const;

    virtual BOOL SetMinWidth(int cxWidth);
    virtual int GetMinWidth();

    virtual BOOL SetMaxWidth(int cxWidth);
    virtual int GetMaxWidth();

	virtual BOOL SetPaneName(const CString& strName);
	virtual BOOL GetPaneName(CString& strName) const;
	
	virtual BOOL SetRegistryKey(const CString& strRegistryKey);
	virtual BOOL GetRegistryKey(CString& strRegistryKey) const;

    virtual UINT DisplayPopupPaneMenu(CMenu& menu);

private:
    CString m_strText;
    int     m_nStyle;
    int     m_cxMinWidth;
    int     m_cxMaxWidth;
	CString m_strName;
	CString m_strRegistryKey;
};

typedef void (*ZcTrayItemAnimationCallbackFunc)(void *, int);
typedef void *ZcTrayItemAnimationCallbackData;

class ZCAD_PORT ZcTrayItemAnimationControl
{
public:
    SB_DEPRECATED ZcTrayItemAnimationControl();
    SB_DEPRECATED ZcTrayItemAnimationControl(const CString& strGIFFile);
    SB_DEPRECATED ZcTrayItemAnimationControl(HBITMAP hBitmap);
    SB_DEPRECATED ~ZcTrayItemAnimationControl();

    SB_DEPRECATED void SetBitmap(HBITMAP hBitmap) { m_hBitmap = hBitmap; }
    SB_DEPRECATED void SetGIFFile(const CString& strGIFFile) { m_strGIFFile = strGIFFile; }
    SB_DEPRECATED void SetGIFResourceData(HGLOBAL hGlobal, DWORD dwSize) { m_hGifGlobal = hGlobal; m_dwGifSize = dwSize; };
    SB_DEPRECATED void SetDuration(int nDurationInSeconds) { m_nDurationInSeconds = nDurationInSeconds; }
    SB_DEPRECATED void SetNewIcon(HICON hNewIcon) { m_hNewIcon = hNewIcon; }
    SB_DEPRECATED void SetCallback(ZcTrayItemAnimationCallbackFunc pCallbackFunc, ZcTrayItemAnimationCallbackData pCallbackData)
    {
        m_pCallbackFunc = pCallbackFunc;
        m_pCallbackData = pCallbackData;
    }

    SB_DEPRECATED HBITMAP GetBitmap() const { return m_hBitmap; };
    SB_DEPRECATED const CString& GetGIFFile() const { return m_strGIFFile; };
    SB_DEPRECATED void GetGIFResourceData(HGLOBAL &hGlobal, DWORD &dwSize) const { hGlobal = m_hGifGlobal; dwSize = m_dwGifSize;};
    SB_DEPRECATED int GetDuration() const { return m_nDurationInSeconds; }
    SB_DEPRECATED HICON GetNewIcon() const { return m_hNewIcon; };
    SB_DEPRECATED ZcTrayItemAnimationCallbackFunc GetCallbackFunc() const { return m_pCallbackFunc; }
    SB_DEPRECATED ZcTrayItemAnimationCallbackData GetCallbackData() const { return m_pCallbackData; }

    enum
    {
        ANIMATION_ERROR_NO_CREATE,
        ANIMATION_ERROR_NO_ICONS,
        ANIMATION_KILLED,
        ANIMATION_FINISHED,
    };

private:
    void InitDefault()
    {
        m_pCallbackFunc = 0;
        m_pCallbackData = 0;
        m_nDurationInSeconds = 5;
        m_hNewIcon = 0;
    }

    HBITMAP                         m_hBitmap;
    HGLOBAL                         m_hGifGlobal;
    DWORD                           m_dwGifSize;
    CString                         m_strGIFFile;
    int                             m_nDurationInSeconds;
    HICON                           m_hNewIcon;
    ZcTrayItemAnimationCallbackFunc m_pCallbackFunc;
    ZcTrayItemAnimationCallbackData m_pCallbackData;
};

typedef void * ZcTrayItemClickCallbackData;
typedef void (*ZcTrayItemClickCallbackFunc)(UINT mouseButtonMsg, UINT controlButtonDownFlags, const CPoint& point, ZcTrayItemClickCallbackData userData);
typedef void *ZcTrayItemBubbleWindowCallbackData;
typedef void (*ZcTrayItemBubbleWindowCallbackFunc)(ZcTrayItemBubbleWindowCallbackData, int);

class ZCAD_PORT ZcTrayItemBubbleWindowControl
{
public:
    ZcTrayItemBubbleWindowControl();
    ZcTrayItemBubbleWindowControl(
            const CString& strTitle,
            const CString& strText,
            const CString& strHyperText = ZCRX_T(""),
            const CString& strHyperLink = ZCRX_T(""),
            const CString& strText2 = ZCRX_T(""),
            const CString& strCheckboxText = ZCRX_T(""),
            bool  bIsChecked = false
            );
    ~ZcTrayItemBubbleWindowControl();

    void SetIconType(int nIconType)         { m_nIconType = nIconType; }
    void SetTitle(const CString& strTitle)  { m_strTitle = strTitle; }
    void SetText(const CString& strText)    { m_strText = strText; }
    void SetHyperText(const CString& strHyperText) { m_strHyperText = strHyperText; }
    void SetHyperLink(const CString& strHyperLink) { m_strHyperLink = strHyperLink; }
    void SetText2(const CString& strText2)  { m_strText2 = strText2; }
    void SetCheckboxText(const CString& strText) { m_strCheckboxText = strText; }
    void SetIsChecked(bool bNewVal) { m_bIsChecked = bNewVal; }
    void SetCallback(ZcTrayItemBubbleWindowCallbackFunc pCallbackFunc, ZcTrayItemBubbleWindowCallbackData pCallbackData = 0)
    {
        m_pCallbackFunc = pCallbackFunc;
        m_pCallbackData = pCallbackData;
    }

    int GetIconType() const { return m_nIconType; };
    const CString& GetTitle() const { return m_strTitle; }
    const CString& GetText() const { return m_strText; }
    const CString& GetHyperText() const { return m_strHyperText; }
    const CString& GetHyperLink() const { return m_strHyperLink; }
    const CString& GetText2() const { return m_strText2; }
    const CString& GetCheckboxText() const { return m_strCheckboxText; }
    const bool GetIsChecked() const { return m_bIsChecked; }
    ZcTrayItemBubbleWindowCallbackFunc GetCallbackFunc() const { return m_pCallbackFunc; }
    ZcTrayItemBubbleWindowCallbackData GetCallbackData() const { return m_pCallbackData; }

    enum
    {
        BUBBLE_WINDOW_ICON_NONE,
        BUBBLE_WINDOW_ICON_INFORMATION,
        BUBBLE_WINDOW_ICON_CRITICAL,
        BUBBLE_WINDOW_ICON_WARNING,
    };

    enum
    {
        BUBBLE_WINDOW_ERROR_NO_CREATE,
        BUBBLE_WINDOW_ERROR_NO_ICONS,
        BUBBLE_WINDOW_ERROR_NO_NOTIFICATIONS,
        BUBBLE_WINDOW_CLOSE,
        BUBBLE_WINDOW_TIME_OUT,
        BUBBLE_WINDOW_HYPERLINK_CLICK,
        BUBBLE_WINDOW_HYPERLINK_CLICK_CHECKED,
        BUBBLE_WINDOW_DOCUMENT_DEACTIVATED
    };

private:
    void InitDefault()
    {
        m_pCallbackFunc = 0;
        m_pCallbackData = 0;
        m_nIconType = BUBBLE_WINDOW_ICON_INFORMATION;
    }

    int                                 m_nIconType;
    CString                             m_strTitle;
    CString                             m_strText;
    CString                             m_strHyperText;
    CString                             m_strHyperLink;
    CString                             m_strText2;
    CString                             m_strCheckboxText;
    bool                                m_bIsChecked;
    ZcTrayItemBubbleWindowCallbackFunc  m_pCallbackFunc;
    ZcTrayItemBubbleWindowCallbackData  m_pCallbackData;
};

class ZcRxValue;
class ZCAD_PORT ZcTrayItem : public ZcStatusBarItem
{
public:
    ZcTrayItem();
    ZcTrayItem(const CString& strId);
    virtual ~ZcTrayItem();

    virtual BOOL SetIcon(HICON hIcon);
    virtual HICON GetIcon() const;

    virtual BOOL ShowBubbleWindow(ZcTrayItemBubbleWindowControl* pBubbleWindowControl);
    virtual ZcTrayItemBubbleWindowControl* GetBubbleWindowControl() const;

    virtual BOOL CloseAllBubbleWindows();

    void GoToState(const CString& state, ZcRxValue* parameter = NULL);
    SB_DEPRECATED BOOL PlayAnimation(ZcTrayItemAnimationControl* pAnimationControl);
    SB_DEPRECATED void StopAnimation();
    SB_DEPRECATED ZcTrayItemAnimationControl* GetAnimationControl() const;

private:
    ZcTrayItemAnimationControl      m_AnimationControl;
    ZcTrayItemAnimationControl      *m_pAnimationControl;

    ZcTrayItemBubbleWindowControl   m_BubbleWindowControl;
    ZcTrayItemBubbleWindowControl   *m_pBubbleWindowControl;
};

enum ZcDefaultPane
{
    ZCSBPANE_APP_MODEMACRO,
    ZCSBPANE_APP_CURSORCOORD,
    ZCSBPANE_APP_SNAP,
    ZCSBPANE_APP_GRID,
    ZCSBPANE_APP_ORTHO,
    ZCSBPANE_APP_POLAR,
    ZCSBPANE_APP_OTRACK,
    ZCSBPANE_APP_LINEWEIGHT,
    ZCSBPANE_APP_PAPERMODEL,
    ZCSBPANE_APP_PAPER,
    ZCSBPANE_APP_MODEL,
	ZCSBPANE_APP_OSNAP,
	ZCSBPANE_APP_FLOAT,
	ZCSBPANE_APP_TABLET,
	ZCSBPANE_APP_SPACER,
	ZCSBPANE_APP_VPMAX_PREV,
	ZCSBPANE_APP_VPMAX,
	ZCSBPANE_APP_VPMAX_NEXT,
	ZCSBPANE_APP_DYNINPUT,
	ZCSBPANE_APP_DYNAMICUCS,
	ZCSBPANE_APP_LAYOUTMODELICONS,
    ZCSBPANE_APP_MODEL_ICON,
    ZCSBPANE_APP_LAYOUT_ICON,
    ZCSBPANE_APP_LAYOUTMORE_ICON,

	ZCSBPANE_APP_ALL,
    ZCSBPANE_ANNO_STRETCH,
    ZCSBPANE_ANNO_AUTOSCALE,
    ZCSBPANE_ANNO_VIEWPORT_SCALE_LABEL,
    ZCSBPANE_ANNO_VIEWPORT_SCALE,
    ZCSBPANE_ANNO_VIEWPORT_LOCK_STATE,
    ZCSBPANE_ANNO_ANNOTATION_SCALE_LABEL,
    ZCSBPANE_ANNO_ANNOTATION_SCALE,
    ZCSBPANE_ANNO_ANNO_ALL_VISIBLE,
    ZCSBPANE_ANNO_EMPTY,
	ZCSBPANE_APP_STRETCH,
	ZCSBPANE_APP_WORKSPACE,
	ZCSBPANE_APP_WORKSPACE_LOCK,
	ZCSBPANE_APP_QPROPERTIES,
	ZCSBPANE_ANNO_SYNCHSCALES,

	ZCSBPANE_APP_QV_LAYOUTS,
	ZCSBPANE_APP_QV_DRAWINGS,
	ZCSBPANE_APP_QV_SPACER,        
	ZCSBPANE_APP_QV_PAN,           
	ZCSBPANE_APP_QV_ZOOM,          
	ZCSBPANE_APP_QV_STEERINGWHEEL, 
	ZCSBPANE_APP_QV_SHOWMOTION,    
	ZCSBPANE_APP_QV_ANNO_SPACER,
	ZCSBPANE_APP_3DOSNAP,
	ZCSBPANE_APP_WORKSPACE_PERFORMANCE,
	ZCSBPANE_APP_SELECTIONCYCLING,

	ZCSBPANE_APP_TRANSPARENCY,
	ZCSBPANE_APP_INFER,
	ZCSBPANE_APP_ANNOMONITOR,
	ZACSBPANE_APP_SELECTION_FILTER,
	ZCSBPANE_APP_GIZMO,
	ZCSBPANE_APP_UNITS,
	ZCSBPANE_APP_GEO_SPACER,
	ZCSBPANE_APP_GEO_MARKERVISIBILITY,
	ZCSBPANE_APP_GEO_COORDSYS,
	ZCSBPANE_APP_ISODRAFT,
	ZCSBPANE_APP_HARDWAREACCELERATION,

	ZCSBPANE_APP_ADD_CLEANSCREEN,
	ZCSBPANE_APP_ADD_CUSTOMIZATION
};

class ZcApStatusBar
{
public:
    virtual BOOL Insert(int nIndex, ZcPane* pPane, BOOL bUpdate = TRUE) = 0;
    virtual BOOL Insert(int nIndex, ZcTrayItem* pTrayItem, BOOL bUpdate = TRUE) = 0;

    virtual BOOL Remove(ZcPane* pPane, BOOL bUpdate = TRUE) = 0;
    virtual BOOL Remove(ZcTrayItem* pTrayItem, BOOL bUpdate = TRUE) = 0;
    virtual BOOL Remove(int nIndex, BOOL bTrayItem = FALSE, BOOL bUpdate = TRUE) = 0;

    virtual BOOL RemoveAllPanes(BOOL bUpdate = TRUE) = 0;

    virtual int Add(ZcPane* pPane, BOOL bUpdate = TRUE) = 0;
    virtual int Add(ZcTrayItem* pTrayItem, BOOL bUpdate = TRUE) = 0;

    SB_DEPRECATED virtual void Update() = 0;

    virtual int GetIndex(ZcPane* pPane) const = 0;
    virtual int GetIndex(ZcTrayItem* pTrayItem) const = 0;
    virtual int GetIndex(int nID, BOOL bTrayItem = FALSE) const = 0;

    SB_DEPRECATED virtual int GetID(ZcPane* pPane) const = 0;
    SB_DEPRECATED virtual int GetID(ZcTrayItem* pTrayItem) const = 0;
    SB_DEPRECATED virtual int GetID(int nIndex, BOOL bTrayItem = FALSE) const = 0;

    virtual int GetPaneCount() const = 0;

    virtual ZcPane* GetPane(int nIndex) = 0;

    virtual int GetTrayItemCount() const = 0;

    virtual ZcTrayItem* GetTrayItem(int nIndex) = 0;

    virtual BOOL RemoveAllTrayIcons(BOOL bUpdate = TRUE) = 0;

    SB_DEPRECATED virtual BOOL ClientToScreen(LPPOINT lpPoint) = 0;
    SB_DEPRECATED virtual BOOL ClientToScreen(LPRECT lpRect) = 0;

    SB_DEPRECATED virtual BOOL ScreenToClient(LPPOINT lpPoint) = 0;
    SB_DEPRECATED virtual BOOL ScreenToClient(LPRECT lpRect) = 0;

    SB_DEPRECATED virtual int GetTextWidth(const CString& strText) const = 0;

    virtual UINT DisplayContextMenu(CMenu& menu, CPoint point) = 0;
    virtual UINT DisplayPopupPaneMenu(ZcPane* pPane, CMenu& menu) = 0;

    SB_DEPRECATED virtual BOOL GetTraySettingsShowIcons() const = 0;
    SB_DEPRECATED virtual BOOL GetTraySettingsShowNotifications() const = 0;

    SB_DEPRECATED virtual void ShowStatusBarMenuIcon(BOOL bShow) = 0;

    SB_DEPRECATED virtual BOOL SetStatusBarMenuItem(ZcPane* pPane) = 0;

    SB_DEPRECATED virtual void ShowCleanScreenIcon(BOOL bShow) = 0;
    SB_DEPRECATED virtual BOOL RemoveCleanScreenIcon() = 0;

    SB_DEPRECATED virtual BOOL ShowTraySettingsDialog() = 0;

    SB_DEPRECATED virtual ZcPane* GetDefaultPane(ZcDefaultPane nPane) = 0;
    SB_DEPRECATED virtual BOOL RemoveDefaultPane(ZcDefaultPane nPane, BOOL bUpdate = TRUE) = 0;

    virtual BOOL CloseAllBubbleWindows(ZcTrayItem* pTrayItem) = 0;

};

class ZCAD_PORT ZcStatusBarMenuItem
{
public:

    enum ZcStatusBarType {
        kApplicationStatusBar  = 0,
        kDrawingStatusBar = 1
    };

    SB_DEPRECATED ZcStatusBarMenuItem();
    SB_DEPRECATED virtual ~ZcStatusBarMenuItem();

    SB_DEPRECATED virtual BOOL    CustomizeMenu       (ZcStatusBarType nType,
                                         CMenu* pMenu,
                                         UINT nStartCmdId,
                                         UINT nEndCmdId);

    SB_DEPRECATED virtual BOOL    InvokeMenuCommand   (ZcStatusBarType nType,
                                         UINT nCmdId);
};
#pragma pack (pop)
#endif 

