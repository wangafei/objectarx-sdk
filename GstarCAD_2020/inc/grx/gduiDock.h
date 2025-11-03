#ifndef _GduiDock_h
#define _GduiDock_h

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#include <afxpriv.h>                    // For CDockBar and CMiniDockFrameWnd
#include <afxdockablepane.h>
#pragma pack (push, 8)
class CPaletteSetTooltip;
class CGdUiDockFrame;
//////////////////////////////////////////////////////////////////////////////

#define GDUI_DOCK_POSITION_TOOL_KEY     GDUI_XML_DOCK_TOOL_INFO
#define GDUI_DOCK_STARTUP_TOOL_KEY      GDUI_XML_DOCK_STARTUP_INFO
#define GDUI_XML_ROOT                   "gdUiTools"
#define GDUI_XML_DOCK_TOOL_INFO         "ToolsInfo"
#define GDUI_XML_DOCK_TOOL              "Tool"
#define GDUI_XML_DOCK_TOOL_CLSID        "CLSID"
#define GDUI_XML_DOCK_STARTUP_INFO      "StartupInfo"
#define GDUI_XML_DOCK_STARTUP_TOOL_NAME "ToolName"
#define GDUI_XML_DOCK_STARTUP_CMD_NAME  "Command"

#define GD_GDUI_ALLOWDOCK           0x1001
#define GD_GDUI_HIDEBAR             0x1002

#define GDUI_DOCK_CS_DESTROY_ON_CLOSE  0x01    // closing the floating window closes the control bar
#define GDUI_DOCK_CS_STDMOUSECLICKS    0x02    // standard mouse handling for the menu

#define GDUI_DOCK_NF_SIZECHANGED       0x01
#define GDUI_DOCK_NF_STATECHANGED      0x02
#define GDUI_DOCK_NF_FRAMECHANGED      0x02

//////////////////////////////////////////////////////////////////////////////

#pragma warning(push)
#pragma warning(disable : 4275)
class GDUI_PORT CGdUiDockControlBar: public CDockablePane
{
  friend class CGdUiDockFrame;
  friend class CGdUiImpPaletteSet;

  // Attributes
private:
	static CObArray * m_paBars;				    // array of dynamically allocated bars
  CSize             m_FloatSize;                  // size when docked
  CSize             m_HorzDockSize;               // size when docked horizontal
  CSize             m_VertDockSize;               // size when docked vertical
  CPoint            m_FloatingPosition;           // floating position
  bool              m_bAllowDockingMenuItemState; // allow docking menu item state
  int               m_Style;                      // style flags
  CSize             m_PrevSize;
  BOOL              m_bPrevFloating;
  CLSID             m_ID;
  bool              m_bShowCloseButton;           // Show and draw close button on docked bar

  static int        m_nLastBarID;
  static bool       m_bToolsRestartMode;      // Boolean variable to signal start/end of
  // restarting of tools (usually set/cleared 
  // by the the application during startup.

  // variables which reflect persisted dock/float rect for the controlbar 
  // across application sessions
  CRect             m_PersistedDockRect;      
  CRect             m_PersistedFloatRect;

private:
	void        SetDockFlag (DWORD dwStyle);
	void        Resized (int cx, int cy, BOOL bFloating, int flags);
	LRESULT     AddMenuItems (WPARAM wParam, LPARAM lParam);
	static void RemoveBars ();
    void        OnUpdateCmdUI (CFrameWnd* pTarget, BOOL bDisableIfNoHndler);
	void        PaintBar (CDC *pDC);
	void        Draw3DRect (CDC *pDC, LPRECT lpRect, CPen *pPenGray);
    LRESULT     WindowProc (UINT nMsg, WPARAM wParam, LPARAM lParam);
    void        LoadDefaultLocation(UINT nOrientation, RECT *pSizeFloating);

public:
  CGdUiDockControlBar (int nStyle = GDUI_DOCK_CS_STDMOUSECLICKS);

	BOOL Create (CWnd * pParent, LPCTSTR lpszTitle, UINT nID,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
    const RECT & rect = CFrameWnd::rectDefault);
	BOOL Create (LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
    DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
    UINT nID, CCreateContext* pContext = NULL);

  void SetPaneAlignment(DWORD dwAlignment);
  void EnableDocking (DWORD dwDockStyle);
  void TileInRow ();
  BOOL IsFloating ();

  void DockControlBar (UINT nOrientation, RECT *pRect);
  void RestoreControlBar (UINT nPreferredOrientation = AFX_IDW_DOCKBAR_LEFT,
    CRect *pSizeFloating = NULL);

  void InitFloatingPosition (CRect *pSizeFloating);
  void GetFloatingRect (CRect *pFloatingPos);

  // access methods which returns the cached dock/float
  // rect which would have persisted in the fixed profile
  // across gcad sessions. 
  void GetPersistedDockingRect(CRect *pDockRect);
  void GetPersistedFloatingRect(CRect *pFloatRect);

  // Get/Set methods to signal begining and end of
  // restarting of tools. Set and cleared by the 
  // application to position controlbars inside
  // one of the four dockbars during the application
  // startup.
  static void SetToolsRestartMode ( bool bMode );
  static bool GetToolsRestartMode (  );

  void SetAllowDockingMenuItemState(bool bState) { m_bAllowDockingMenuItemState = bState; }
  bool AllowDockingMenuItemState()const { return m_bAllowDockingMenuItemState; }

  void SetToolID (CLSID* pCLSID);
  CLSID* GetToolID () { return &m_ID; }
  DWORD GetDockStyle ();
  virtual BOOL CanFloat() const;
  virtual DWORD GetEnabledAlignment() const;

  // Called in response to the application's query to take the focus back.
  // Default implementation returns false, keeping the focus in the tool window.
  virtual bool CanFrameworkTakeFocus () { return false; }

  // Loads the data from xml file 
  virtual BOOL Load(IUnknown* pUnk);
  // Saves the data to xml file
  virtual BOOL Save(IUnknown* pUnk);

  virtual CSize CalcFixedLayout (BOOL bStretch, BOOL bHorz);
  bool Anchored();

  bool AdjustVertDockedBarHeight(int nHeight);
  static bool ShowPalettes();
  static bool HidePalettes();

  CGdUiTheme* GetTheme();
  CGdUiTheme* SetTheme(CGdUiTheme* pTheme);
  void ThemeModified(GdUiThemeElement element);

  // Returns the title bar width/height
  LONG GetTitleBarSize();

  void setVisible(bool bVisible);
  bool isVisible() const;
  virtual BOOL LoadState(LPCTSTR lpszProfileName = NULL, int nIndex = -1, UINT uiID = (UINT) -1);
  virtual BOOL SaveState(LPCTSTR lpszProfileName = NULL, int nIndex = -1, UINT uiID = (UINT) -1);
  virtual void ShowPane(BOOL bShow, BOOL bDelay, BOOL bActivate/* = TRUE*/);
  virtual void OnPressCloseButton();
  virtual BOOL DockPane(CBasePane* pDockBar, LPCRECT lpRect, AFX_DOCK_METHOD dockMethod);
  virtual BOOL FloatPane(CRect rectFloat, AFX_DOCK_METHOD dockMethod = DM_UNKNOWN, bool bShow = true);
#ifdef _DEBUG
  void AssertValid() const;
#endif

  // Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CGdUiDockControlBar)
protected:
  virtual BOOL OnCommand (WPARAM wParam, LPARAM lParam);
  //}}AFX_VIRTUAL

public:
  virtual ~CGdUiDockControlBar();

protected:
  enum {
    btnWidth    = 12,
    btnHeight   = 12,
    idCloseBtn  = 10001,
    idPinBtn    = 10002
  };

protected:
  // windows message handlers
  //{{AFX_MSG(CGdUiDockControlBar)
  afx_msg void OnWindowPosChanged (WINDOWPOS FAR* lpwndpos);
  afx_msg BOOL OnEraseBkgnd (CDC* pDC);
  afx_msg void OnAllowDock ();
  afx_msg void OnAnchor ();
  afx_msg void OnAnchorLeft();
  afx_msg void OnAnchorRight();
  afx_msg void OnHideBar ();
  afx_msg void OnContextMenu (CWnd* pWnd, CPoint point);
  afx_msg int  OnCreate (LPCREATESTRUCT lpCreateStruct);
  afx_msg void OnPaint ();
  afx_msg void OnNcPaint(void);
  afx_msg void OnNcCalcSize(BOOL bCalcValidRects,NCCALCSIZE_PARAMS* lpncsp);
  afx_msg LRESULT OnNcHitTest(CPoint point);
  afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
  afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
  afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
  afx_msg void OnMouseMove(UINT nFlags, CPoint point);
  //}}AFX_MSG


protected:
  void GetUsedRect (CRect& rect);
  void ShowCloseButton (bool bShow) { m_bShowCloseButton = bShow; };
  bool CloseButtonVisible () { return m_bShowCloseButton; };
  void RepositionOrHideButtons ();
  static LRESULT CALLBACK MouseProc (int nCode, WPARAM wParam, LPARAM lParam);

  // Overridable functions
  virtual void PaintControlBar (CDC *pDC);
  virtual BOOL CreateControlBar (LPCREATESTRUCT lpCreateStruct);
    virtual void SizeChanged (CRect *lpRect, BOOL bFloating, int flags) {lpRect, bFloating, flags;}
  virtual bool OnClosing ();
  virtual void GetFloatingMinSize (long *pnMinWidth, long *pnMinHeight)const;
  virtual BOOL AddCustomMenuItems(LPARAM hMenu); 
    virtual void OnUserSizing (UINT nSide, LPRECT pRect) { nSide, pRect; }

  DECLARE_SERIAL (CGdUiDockControlBar)
  DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
// CGdUiDockFrame window

class GDUI_PORT CGdUiDockFrame : public CMiniDockFrameWnd 
{
  DECLARE_DYNCREATE(CGdUiDockFrame)

public:
  CGdUiDockFrame();

  // Docking frame
public:
  enum ContainedBarType { Unknown, Standard, AdskBar };

  enum ContainedBarType GetContainedBarType();
protected:
  enum ContainedBarType m_nContainedBarType;
  bool m_bZOrderChanged;

  bool CanFrameworkTakeFocus();
  void ForceChildRepaint();

  // ClassWizard-controlled
public:
  //{{AFX_VIRTUAL(CAdUiDockFrame)
protected:
  virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
  //}}AFX_VIRTUAL

protected:
  //{{AFX_MSG(CAdUiDockFrame)
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
  afx_msg void OnSize(UINT nType, int cx, int cy);
  afx_msg void OnClose();
  afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint pt);
#if _MSC_VER<1400
  afx_msg UINT OnNcHitTest(CPoint point);
#else
  afx_msg LRESULT OnNcHitTest(CPoint point);
#endif
  afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
  afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
  afx_msg void OnPaint();
  afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
  afx_msg void OnSizing(UINT nSide, LPRECT pRect);
  //}}AFX_MSG

  bool CanAutoCADTakeFocus();

  DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

bool GDUI_PORT GdUiRegisterTool (
    LPCSTR lpszToolName, LPCSTR lpszCommand, CLSID* pID
);

GDUI_PORT CRuntimeClass* GdUiSetFloatingFrameClass(CRuntimeClass* pNewClass);
GDUI_PORT void GdUiRegisterFloatingFrameClassAddress(CRuntimeClass** pClass);
GDUI_PORT CRuntimeClass* GdUiGetRegisteredPaletteSetFloatingFrameClass(void);

typedef HRESULT GDUI_LOADFN(IUnknown** ppIdUiRootNode);
typedef HRESULT GDUI_SAVEFN(IUnknown* pIdUiRootNode);

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif
