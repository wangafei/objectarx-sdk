
#ifndef _GCSTATUSBAR_H
#define _GCSTATUSBAR_H 1

#pragma pack (push, 8)

#include "gcdocman.h"

class GCAD_DLL_DECL GcStatusBarItem
{
public:
  GcStatusBarItem();
  virtual ~GcStatusBarItem();

  virtual BOOL SetIcon(HICON hIcon);
  virtual HICON GetIcon() const;
  
  virtual void SetIconLabel(CString sIcon);
  virtual CString GetIconLabel();


  virtual BOOL SetToolTipText(const CString& strText);
  virtual BOOL GetToolTipText(CString& strText) const;

  virtual BOOL QueryToolTipText(CString& strText) const;

  virtual void Enable(BOOL bValue);
  virtual BOOL IsEnabled();

  virtual void SetVisible(BOOL bIsVisible);
  virtual BOOL IsVisible();

  virtual void OnLButtonDown(UINT nFlags, CPoint point);
  virtual void OnRButtonDown(UINT nFlags, CPoint point);
  virtual void OnLButtonDblClk(UINT nFlags, CPoint point);

  virtual void OnDelete();

  virtual BOOL ClientToScreen(LPPOINT lpPoint);
  virtual BOOL ClientToScreen(LPRECT lpRect);

  virtual BOOL ScreenToClient(LPPOINT lpPoint);
  virtual BOOL ScreenToClient(LPRECT lpRect);

  virtual UINT DisplayContextMenu(CMenu& menu, CPoint point);

  virtual BOOL ShowTraySettingsDialog();

  //////////////////////////////////////////////////////////////////////////////
  // Note: These methods are for INTERNAL USE ONLY.  Using these methods may
  //       adversely affect application functionality
  virtual void SetContentChanged(BOOL bChanged) {m_bContentChanged = bChanged;}
  virtual BOOL ContentChanged() const {return m_bContentChanged;}

  virtual void SetVisibilityChanged(BOOL bChanged) {m_bVisibilityChanged = bChanged;}
  virtual BOOL VisibilityChanged() const {return m_bVisibilityChanged;}

  virtual void SetInternalData(void* pData, BOOL bForDocSwitch = FALSE);
  virtual void* GetInternalData(BOOL bForDocSwitch = TRUE) const;
  // End INTERNAL USE ONLY.
  //////////////////////////////////////////////////////////////////////////////
private:
  CString         m_sIcon;
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

//Deprecated styles.
#define GCSB_POPOUT     GCSB_INACTIVE
#define GCSB_NORMAL     GCSB_ACTIVE

class GCAD_DLL_DECL GcPane : public GcStatusBarItem
{
public:
  GcPane();
  virtual ~GcPane();

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

  virtual UINT DisplayPopupPaneMenu(CMenu& menu);

private:
  CString m_strText;
  int     m_nStyle;
  int     m_cxMinWidth;
  int     m_cxMaxWidth;
};

typedef void (*GcTrayItemAnimationCallbackFunc)(void *, int);
typedef void *GcTrayItemAnimationCallbackData;

//////////////////////////////////////////////////////////////////////////////
// Note: This class is for INTERNAL USE ONLY.  Using this class may
//       adversely affect application functionality

class GCAD_DLL_DECL GcTrayItemAnimationControl
{
public:
  GcTrayItemAnimationControl();
  GcTrayItemAnimationControl(const CString& strGIFFile);
  GcTrayItemAnimationControl(HBITMAP hBitmap);
  ~GcTrayItemAnimationControl();

  void SetBitmap(HBITMAP hBitmap) { m_hBitmap = hBitmap; }
  void SetGIFFile(const CString& strGIFFile) { m_strGIFFile = strGIFFile; }
  void SetGIFResourceData(HGLOBAL hGlobal, DWORD dwSize) { m_hGifGlobal = hGlobal; m_dwGifSize = dwSize; };
  void SetDuration(int nDurationInSeconds) { m_nDurationInSeconds = nDurationInSeconds; }
  void SetNewIcon(HICON hNewIcon) { m_hNewIcon = hNewIcon; }
  void SetCallback(GcTrayItemAnimationCallbackFunc pCallbackFunc, GcTrayItemAnimationCallbackData pCallbackData)
  {
    m_pCallbackFunc = pCallbackFunc;
    m_pCallbackData = pCallbackData;
  }

  HBITMAP GetBitmap() const { return m_hBitmap; };
  const CString& GetGIFFile() const { return m_strGIFFile; };
  void GetGIFResourceData(HGLOBAL &hGlobal, DWORD &dwSize) const { hGlobal = m_hGifGlobal; dwSize = m_dwGifSize;};
  int GetDuration() const { return m_nDurationInSeconds; }
  HICON GetNewIcon() const { return m_hNewIcon; };
  GcTrayItemAnimationCallbackFunc GetCallbackFunc() const { return m_pCallbackFunc; }
  GcTrayItemAnimationCallbackData GetCallbackData() const { return m_pCallbackData; }

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
// End INTERNAL USE ONLY.
//////////////////////////////////////////////////////////////////////////////

typedef void (*GcTrayItemBubbleWindowCallbackFunc)(void *, int);
typedef void *GcTrayItemBubbleWindowCallbackData;

class GCAD_DLL_DECL GcTrayItemBubbleWindowControl
{
public:
  GcTrayItemBubbleWindowControl();
  GcTrayItemBubbleWindowControl(
    const CString& strTitle,
    const CString& strText,
    const CString& strHyperText = _T(""),
    const CString& strHyperLink = _T(""),
    const CString& strText2 = _T("")
    );
  ~GcTrayItemBubbleWindowControl();

  void SetIconType(int nIconType)         { m_nIconType = nIconType; }
  void SetTitle(const CString& strTitle)  { m_strTitle = strTitle; }
  void SetText(const CString& strText)    { m_strText = strText; }
  void SetHyperText(const CString& strHyperText) { m_strHyperText = strHyperText; }
  void SetHyperLink(const CString& strHyperLink) { m_strHyperLink = strHyperLink; }
  void SetText2(const CString& strText2)  { m_strText2 = strText2; }
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

class GCAD_DLL_DECL GcTrayItem : public GcStatusBarItem
{
public:
  GcTrayItem();
  virtual ~GcTrayItem();

  virtual BOOL SetIcon(HICON hIcon);
  virtual HICON GetIcon() const;

  virtual BOOL ShowBubbleWindow(GcTrayItemBubbleWindowControl* pBubbleWindowControl);
  virtual GcTrayItemBubbleWindowControl* GetBubbleWindowControl() const;
  virtual BOOL CloseAllBubbleWindows();

  //////////////////////////////////////////////////////////////////////////////
  // Note: These methods are for INTERNAL USE ONLY.  Using these methods may
  //       adversely affect application functionality
  BOOL PlayAnimation(GcTrayItemAnimationControl* pAnimationControl);
  void StopAnimation();
  GcTrayItemAnimationControl* GetAnimationControl() const;
  // End INTERNAL USE ONLY.
  //////////////////////////////////////////////////////////////////////////////

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
  GCSBPANE_APP_LOGO,
  GCSBPANE_APP_MAGNIFIER,
  GCSBPANE_APP_MIRRDRAW,
  GCSBPANE_APP_PICKMIRRAXIS,

  GCSBPANE_APP_OSDIVIDE,
  GCSBPANE_APP_OSDISTANCE,

  GCSBPANE_APP_AUTOLAYER,
  GCSBPANE_APP_LOCKULOCKVP,
  GCSBPANE_APP_QUICKPROPERTIES,
  GCSBPANE_APP_SELCYCLING,

  GCSBPANE_APP_MAX
};

class GCAD_DLL_DECL GcApStatusBar
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

  virtual void Update() = 0;

  virtual int GetIndex(GcPane* pPane) const = 0;
  virtual int GetIndex(GcTrayItem* pTrayItem) const = 0;
  virtual int GetIndex(int nID, BOOL bTrayItem = FALSE) const = 0;

  virtual int GetID(GcPane* pPane) const = 0;
  virtual int GetID(GcTrayItem* pTrayItem) const = 0;
  virtual int GetID(int nIndex, BOOL bTrayItem = FALSE) const = 0;

  virtual int GetPaneCount() const = 0;

  virtual GcPane* GetPane(int nIndex) = 0;

  virtual int GetTrayItemCount() const = 0;

  virtual GcTrayItem* GetTrayItem(int nIndex) = 0;

  virtual BOOL RemoveAllTrayIcons(BOOL bUpdate = TRUE) = 0;

  virtual BOOL ClientToScreen(LPPOINT lpPoint) = 0;
  virtual BOOL ClientToScreen(LPRECT lpRect) = 0;

  virtual BOOL ScreenToClient(LPPOINT lpPoint) = 0;
  virtual BOOL ScreenToClient(LPRECT lpRect) = 0;

  virtual int GetTextWidth(const CString& strText) const = 0;

  virtual UINT DisplayContextMenu(CMenu& menu, CPoint point) = 0;
  virtual UINT DisplayPopupPaneMenu(GcPane* pPane, CMenu& menu) = 0;

  virtual BOOL GetTraySettingsShowIcons() const = 0;
  virtual BOOL GetTraySettingsShowNotifications() const = 0;

  virtual void ShowStatusBarMenuIcon(BOOL bShow) = 0;

  virtual BOOL SetStatusBarMenuItem(GcPane* pPane) = 0;

  virtual void ShowCleanScreenIcon(BOOL bShow) = 0;
  virtual BOOL RemoveCleanScreenIcon() = 0;

  virtual BOOL ShowTraySettingsDialog() = 0;

  virtual GcPane* GetDefaultPane(GcDefaultPane nPane) = 0;
  virtual BOOL RemoveDefaultPane(GcDefaultPane nPane, BOOL bUpdate = TRUE) = 0;

  virtual BOOL CloseAllBubbleWindows(GcTrayItem* pTrayItem) = 0;
};

class GCAD_DLL_DECL GcStatusBarMenuItem
{
public:

  enum GcStatusBarType 
  {
    kApplicationStatusBar  = 0,
    kDrawingStatusBar = 1
  };

  GcStatusBarMenuItem();
  virtual ~GcStatusBarMenuItem();

  virtual BOOL CustomizeMenu(
    GcStatusBarType nType,
    CMenu* pMenu,
    UINT nStartCmdId,
    UINT nEndCmdId);

  virtual BOOL InvokeMenuCommand(
    GcStatusBarType nType,
    UINT nCmdId);
};

#pragma pack (pop)
#endif // GCSTATUSBAR_H

