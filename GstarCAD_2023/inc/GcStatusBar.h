/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GCSTATUSBAR_H
#define _GCSTATUSBAR_H 1

#pragma pack (push, 8)


#ifdef NEW_STATUS_BAR
#define SB_DEPRECATED __declspec(deprecated)
#else
#define SB_DEPRECATED
#endif

#ifndef GCAD_PORT
#define GCAD_PORT
#endif

#include "gcdocman.h"
#include "gsoft.h"

class CMenu;

class GCAD_PORT GcStatusBarItem
{
public:
  GcStatusBarItem();
  GcStatusBarItem(const CString& strId, bool isTrayItem);
  virtual ~GcStatusBarItem();

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

  SB_DEPRECATED virtual void SetContentChanged(BOOL bChanged) { m_bContentChanged = bChanged; }
  SB_DEPRECATED virtual BOOL ContentChanged() const { return m_bContentChanged; }

  SB_DEPRECATED virtual void SetVisibilityChanged(BOOL bChanged) { m_bVisibilityChanged = bChanged; }
  SB_DEPRECATED virtual BOOL VisibilityChanged() const { return m_bVisibilityChanged; }

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

#define GCSB_NOBORDERS  (1<<0) 
#define GCSB_INACTIVE   (1<<1)
#define GCSB_STRETCH    (1<<2) 
#define GCSB_ACTIVE     (1<<3)
#define GCSB_COMMAND    (1<<4) 
#define GCSB_POPUP      (1<<5)
#define GCSB_DIVIDER    (1<<6)
#define GCSB_SUBDIVIDER (1<<7)
#define GCSB_INDETERMINATE  (1<<8)  
#define GCSB_ONETIME    (1<<9)      

#define GCSB_POPOUT     GCSB_INACTIVE
#define GCSB_NORMAL     GCSB_ACTIVE

class GCAD_PORT GcPane : public GcStatusBarItem
{
public:
  GcPane();
  GcPane(const CString& strId);
  ~GcPane();

  BOOL SetIcon(HICON hIcon) override;
  HICON GetIcon() const override;

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

typedef void(*GcTrayItemAnimationCallbackFunc)(void *, int);
typedef void *GcTrayItemAnimationCallbackData;

class GCAD_PORT GcTrayItemAnimationControl
{
public:
  SB_DEPRECATED GcTrayItemAnimationControl();
  SB_DEPRECATED GcTrayItemAnimationControl(const CString& strGIFFile);
  SB_DEPRECATED GcTrayItemAnimationControl(HBITMAP hBitmap);
  SB_DEPRECATED ~GcTrayItemAnimationControl();

  SB_DEPRECATED void SetBitmap(HBITMAP hBitmap) { m_hBitmap = hBitmap; }
  SB_DEPRECATED void SetGIFFile(const CString& strGIFFile) { m_strGIFFile = strGIFFile; }
  SB_DEPRECATED void SetGIFResourceData(HGLOBAL hGlobal, DWORD dwSize) { m_hGifGlobal = hGlobal; m_dwGifSize = dwSize; };
  SB_DEPRECATED void SetDuration(int nDurationInSeconds) { m_nDurationInSeconds = nDurationInSeconds; }
  SB_DEPRECATED void SetNewIcon(HICON hNewIcon) { m_hNewIcon = hNewIcon; }
  SB_DEPRECATED void SetCallback(GcTrayItemAnimationCallbackFunc pCallbackFunc, GcTrayItemAnimationCallbackData pCallbackData)
  {
    m_pCallbackFunc = pCallbackFunc;
    m_pCallbackData = pCallbackData;
  }

  SB_DEPRECATED HBITMAP GetBitmap() const { return m_hBitmap; };
  SB_DEPRECATED const CString& GetGIFFile() const { return m_strGIFFile; };
  SB_DEPRECATED void GetGIFResourceData(HGLOBAL &hGlobal, DWORD &dwSize) const { hGlobal = m_hGifGlobal; dwSize = m_dwGifSize; };
  SB_DEPRECATED int GetDuration() const { return m_nDurationInSeconds; }
  SB_DEPRECATED HICON GetNewIcon() const { return m_hNewIcon; };
  SB_DEPRECATED GcTrayItemAnimationCallbackFunc GetCallbackFunc() const { return m_pCallbackFunc; }
  SB_DEPRECATED GcTrayItemAnimationCallbackData GetCallbackData() const { return m_pCallbackData; }

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
  GcTrayItemAnimationCallbackFunc m_pCallbackFunc;
  GcTrayItemAnimationCallbackData m_pCallbackData;
};

typedef void(*GcTrayItemBubbleWindowCallbackFunc)(void *, int);
typedef void *GcTrayItemBubbleWindowCallbackData;

class GCAD_PORT GcTrayItemBubbleWindowControl
{
public:
  GcTrayItemBubbleWindowControl();
  GcTrayItemBubbleWindowControl(
    const CString& strTitle,
    const CString& strText,
    const CString& strHyperText = GCRX_T(""),
    const CString& strHyperLink = GCRX_T(""),
    const CString& strText2 = GCRX_T("")
  );
  ~GcTrayItemBubbleWindowControl();

  void SetIconType(int nIconType) { m_nIconType = nIconType; }
  void SetTitle(const CString& strTitle) { m_strTitle = strTitle; }
  void SetText(const CString& strText) { m_strText = strText; }
  void SetHyperText(const CString& strHyperText) { m_strHyperText = strHyperText; }
  void SetHyperLink(const CString& strHyperLink) { m_strHyperLink = strHyperLink; }
  void SetText2(const CString& strText2) { m_strText2 = strText2; }
  void SetCallback(GcTrayItemBubbleWindowCallbackFunc pCallbackFunc, GcTrayItemBubbleWindowCallbackData pCallbackData = 0)
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
  GcTrayItemBubbleWindowCallbackFunc GetCallbackFunc() const { return m_pCallbackFunc; }
  GcTrayItemBubbleWindowCallbackData GetCallbackData() const { return m_pCallbackData; }

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
  GcTrayItemBubbleWindowCallbackFunc  m_pCallbackFunc;
  GcTrayItemBubbleWindowCallbackData  m_pCallbackData;
};

class GcRxValue;
class GCAD_PORT GcTrayItem : public GcStatusBarItem
{
public:
  GcTrayItem();
  GcTrayItem(const CString& strId);
  virtual ~GcTrayItem();

  BOOL SetIcon(HICON hIcon) override;
  HICON GetIcon() const override;


  virtual BOOL ShowBubbleWindow(GcTrayItemBubbleWindowControl* pBubbleWindowControl);
  virtual GcTrayItemBubbleWindowControl* GetBubbleWindowControl() const;

  virtual BOOL CloseAllBubbleWindows();
  void GoToState(const CString& state, GcRxValue* parameter = NULL);

  SB_DEPRECATED BOOL PlayAnimation(GcTrayItemAnimationControl* pAnimationControl);
  SB_DEPRECATED void StopAnimation();
  SB_DEPRECATED GcTrayItemAnimationControl* GetAnimationControl() const;

private:
  GcTrayItemAnimationControl      m_AnimationControl;
  GcTrayItemAnimationControl      *m_pAnimationControl;

  GcTrayItemBubbleWindowControl   m_BubbleWindowControl;
  GcTrayItemBubbleWindowControl   *m_pBubbleWindowControl;
};

enum GcDefaultPane
{
  GCSBPANE_APP_MODEMACRO,
  GCSBPANE_APP_CURSORCOORD,
  GCSBPANE_APP_SNAP,
  GCSBPANE_APP_GRID,
  GCSBPANE_APP_ORTHO,
  GCSBPANE_APP_POLAR,
  GCSBPANE_APP_OTRACK,
  GCSBPANE_APP_LINEWEIGHT,
  GCSBPANE_APP_PAPERMODEL,
  GCSBPANE_APP_PAPER,
  GCSBPANE_APP_MODEL,
  GCSBPANE_APP_OSNAP,
  GCSBPANE_APP_FLOAT,
  GCSBPANE_APP_TABLET,
  GCSBPANE_APP_SPACER,
  GCSBPANE_APP_VPMAX_PREV,
  GCSBPANE_APP_VPMAX,
  GCSBPANE_APP_VPMAX_NEXT,
  GCSBPANE_APP_DYNINPUT,
  GCSBPANE_APP_DYNAMICUCS,
  GCSBPANE_APP_LAYOUTMODELICONS,
  GCSBPANE_APP_MODEL_ICON,
  GCSBPANE_APP_LAYOUT_ICON,
  GCSBPANE_APP_LAYOUTMORE_ICON,

  GCSBPANE_APP_ALL,
  GCSBPANE_ANNO_STRETCH,
  GCSBPANE_ANNO_AUTOSCALE,
  GCSBPANE_ANNO_VIEWPORT_SCALE_LABEL,
  GCSBPANE_ANNO_VIEWPORT_SCALE,
  GCSBPANE_ANNO_VIEWPORT_LOCK_STATE,
  GCSBPANE_ANNO_ANNOTATION_SCALE_LABEL,
  GCSBPANE_ANNO_ANNOTATION_SCALE,
  GCSBPANE_ANNO_ANNO_ALL_VISIBLE,
  GCSBPANE_ANNO_EMPTY,
  GCSBPANE_APP_STRETCH,
  GCSBPANE_APP_WORKSPACE,
  GCSBPANE_APP_WORKSPACE_LOCK,
  GCSBPANE_APP_QPROPERTIES,
  GCSBPANE_ANNO_SYNCHSCALES,

  GCSBPANE_APP_QV_LAYOUTS,
  GCSBPANE_APP_QV_DRAWINGS,
  GCSBPANE_APP_QV_SPACER,
  GCSBPANE_APP_QV_PAN,
  GCSBPANE_APP_QV_ZOOM,
  GCSBPANE_APP_QV_STEERINGWHEEL,
  GCSBPANE_APP_QV_SHOWMOTION,
  GCSBPANE_APP_QV_ANNO_SPACER,
  GCSBPANE_APP_3DOSNAP,
  GCSBPANE_APP_WORKSPACE_PERFORMANCE,
  GCSBPANE_APP_SELECTIONCYCLING,

  GCSBPANE_APP_TRANSPARENCY,
  GCSBPANE_APP_INFER,
  GCSBPANE_APP_ANNOMONITOR,

  GCSBPANE_APP_SELECTION_FILTER,
  GCSBPANE_APP_GIZMO,
  GCSBPANE_APP_UNITS,
  GCSBPANE_APP_GEO_SPACER,
  GCSBPANE_APP_GEO_MARKERVISIBILITY,
  GCSBPANE_APP_GEO_COORDSYS,
  GCSBPANE_APP_ISODRAFT,
  GCSBPANE_APP_HARDWAREACCELERATION,

  GCSBPANE_APP_ADD_CLEANSCREEN,
  GCSBPANE_APP_ADD_CUSTOMIZATION
};

class GcApStatusBar
{
public:
  virtual BOOL Insert(int nIndex, GcPane* pPane, BOOL bUpdate = TRUE) = 0;
  virtual BOOL Insert(int nIndex, GcTrayItem* pTrayItem, BOOL bUpdate = TRUE) = 0;

  virtual BOOL Remove(GcPane* pPane, BOOL bUpdate = TRUE) = 0;
  virtual BOOL Remove(GcTrayItem* pTrayItem, BOOL bUpdate = TRUE) = 0;
  virtual BOOL Remove(int nIndex, BOOL bTrayItem = FALSE, BOOL bUpdate = TRUE) = 0;

  virtual BOOL RemoveAllPanes(BOOL bUpdate = TRUE) = 0;

  virtual int Add(GcPane* pPane, BOOL bUpdate = TRUE) = 0;
  virtual int Add(GcTrayItem* pTrayItem, BOOL bUpdate = TRUE) = 0;

  SB_DEPRECATED virtual void Update() = 0;

  virtual int GetIndex(GcPane* pPane) const = 0;
  virtual int GetIndex(GcTrayItem* pTrayItem) const = 0;
  virtual int GetIndex(int nID, BOOL bTrayItem = FALSE) const = 0;

  SB_DEPRECATED virtual int GetID(GcPane* pPane) const = 0;
  SB_DEPRECATED virtual int GetID(GcTrayItem* pTrayItem) const = 0;
  SB_DEPRECATED virtual int GetID(int nIndex, BOOL bTrayItem = FALSE) const = 0;

  virtual int GetPaneCount() const = 0;
  virtual GcPane* GetPane(int nIndex) = 0;
  virtual int GetTrayItemCount() const = 0;
  virtual GcTrayItem* GetTrayItem(int nIndex) = 0;
  virtual BOOL RemoveAllTrayIcons(BOOL bUpdate = TRUE) = 0;

  SB_DEPRECATED virtual BOOL ClientToScreen(LPPOINT lpPoint) = 0;
  SB_DEPRECATED virtual BOOL ClientToScreen(LPRECT lpRect) = 0;

  SB_DEPRECATED virtual BOOL ScreenToClient(LPPOINT lpPoint) = 0;
  SB_DEPRECATED virtual BOOL ScreenToClient(LPRECT lpRect) = 0;

  SB_DEPRECATED virtual int GetTextWidth(const CString& strText) const = 0;

  virtual UINT DisplayContextMenu(CMenu& menu, CPoint point) = 0;
  virtual UINT DisplayPopupPaneMenu(GcPane* pPane, CMenu& menu) = 0;

  SB_DEPRECATED virtual BOOL GetTraySettingsShowIcons() const = 0;
  SB_DEPRECATED virtual BOOL GetTraySettingsShowNotifications() const = 0;

  SB_DEPRECATED virtual void ShowStatusBarMenuIcon(BOOL bShow) = 0;
  SB_DEPRECATED virtual BOOL SetStatusBarMenuItem(GcPane* pPane) = 0;
  SB_DEPRECATED virtual void ShowCleanScreenIcon(BOOL bShow) = 0;
  SB_DEPRECATED virtual BOOL RemoveCleanScreenIcon() = 0;
  SB_DEPRECATED virtual BOOL ShowTraySettingsDialog() = 0;

  SB_DEPRECATED virtual GcPane* GetDefaultPane(GcDefaultPane nPane) = 0;
  SB_DEPRECATED virtual BOOL RemoveDefaultPane(GcDefaultPane nPane, BOOL bUpdate = TRUE) = 0;

  virtual BOOL CloseAllBubbleWindows(GcTrayItem* pTrayItem) = 0;
};

class GCAD_PORT GcStatusBarMenuItem
{
public:
  enum GcStatusBarType {
    kApplicationStatusBar = 0,
    kDrawingStatusBar = 1
  };

  SB_DEPRECATED GcStatusBarMenuItem();
  SB_DEPRECATED virtual ~GcStatusBarMenuItem();

  SB_DEPRECATED virtual BOOL    CustomizeMenu(GcStatusBarType nType,
    CMenu* pMenu,
    UINT nStartCmdId,
    UINT nEndCmdId);
  SB_DEPRECATED virtual BOOL    InvokeMenuCommand(GcStatusBarType nType,
    UINT nCmdId);
};

#pragma pack (pop)
#endif 
