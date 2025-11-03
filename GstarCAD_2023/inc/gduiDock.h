/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiDock_h
#define _gduiDock_h

#if _MSC_VER >= 1000
#pragma once
#endif 

#include <afxpriv.h>                    
#include "GdGChar.h"
#pragma pack (push, 8)
class CPaletteSetTooltip;
class CGdUiDockFrame;
class CGdUiDockControlBar;

#define GDUI_DOCK_POSITION_TOOL_KEY     GDUI_XML_DOCK_TOOL_INFO
#define GDUI_DOCK_STARTUP_TOOL_KEY      GDUI_XML_DOCK_STARTUP_INFO
#define GDUI_XML_ROOT                   GCRX_T("GdUiTools")
#define GDUI_XML_DOCK_TOOL_INFO         GCRX_T("ToolsInfo")
#define GDUI_XML_DOCK_TOOL              GCRX_T("Tool")
#define GDUI_XML_DOCK_TOOL_CLSID        GCRX_T("CLSID")
#define GDUI_XML_DOCK_STARTUP_INFO      GCRX_T("StartupInfo")
#define GDUI_XML_DOCK_STARTUP_TOOL_NAME GCRX_T("ToolName")
#define GDUI_XML_DOCK_STARTUP_CMD_NAME  GCRX_T("Command")

#define ID_GDUI_ALLOWDOCK           0x1001
#define ID_GDUI_HIDEBAR             0x1002

#define GDUI_DOCK_CS_DESTROY_ON_CLOSE  0x01    
#define GDUI_DOCK_CS_STDMOUSECLICKS    0x02    

#define GDUI_DOCK_NF_SIZECHANGED       0x01
#define GDUI_DOCK_NF_STATECHANGED      0x02
#define GDUI_DOCK_NF_FRAMECHANGED      0x02

#define WM_GCAD_DOCKBAR_ROLLED_UP  (WM_USER+37)  
#define WM_GCAD_DOCKBAR_ROLLED_OUT (WM_USER+38)  

#pragma warning(push)
#ifndef _GSOFT_MAC_
#pragma warning(disable : 4275)

class CGdUiDockControlBarThemeModReactor : public CGdUiThemeModifiedReactor
{
public:
  CGdUiDockControlBarThemeModReactor(CGdUiDockControlBar* pDockControlBar);
  void ThemeModified(const CGdUiTheme * pTheme, GdUiThemeElement element) override;
  void SetDockControlBar(CGdUiDockControlBar* pDockControlBar);

private:
  CGdUiDockControlBar * m_pDockControlBar;
};

class GCAD_PORT CGdUiDockControlBar : public CControlBar
{
  friend class CGdUiDockFrame;
  friend class CGdUiPaletteSetDockFrame;
  friend class CGdUiDockDragContext;
  friend class CGdUiDockBar;
  friend class CGdUiImpPaletteSet;
  friend class CGdUiDockBarMutator;
  friend class CGdUiDockControlBarThemeModReactor;

private:
  static CObArray * m_paBars;
  CSize             m_FloatSize;
  CSize             m_HorzDockSize;
  CSize             m_VertDockSize;
  CPoint            m_FloatingPosition;
  bool              m_bAllowDockingMenuItemState;
  int               m_Style;
  CSize             m_PrevSize;
  BOOL              m_bPrevFloating;
  CGdUiBitmapButton m_closeBtn;
  CGdUiBitmapButton m_pinBtn;
  CLSID             m_ID;
  bool              m_bShowCloseButton;

  static int        m_nLastBarID;
  static bool       m_bToolsRestartMode;

  CRect             m_PersistedDockRect;
  CRect             m_PersistedFloatRect;

private:
  void        SetDockFlag(DWORD dwStyle);
  void        Resized(int cx, int cy, BOOL bFloating, int flags);
  LRESULT     AddMenuItems(WPARAM wParam, LPARAM lParam);
  static void RemoveBars();
  void        OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler);
  void        PaintBar(CDC *pDC);
  void        Draw3DRect(CDC *pDC, LPRECT lpRect, CPen *pPenGray);
  LRESULT     WindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam);
  void        LoadDefaultLocation(UINT nOrientation, RECT *pSizeFloating);

public:
  CGdUiDockControlBar(int nStyle = GDUI_DOCK_CS_STDMOUSECLICKS);

  BOOL Create(CWnd * pParent, LPCTSTR lpszTitle, UINT nID,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
    const RECT & rect = CFrameWnd::rectDefault);
  BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
    DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
    UINT nID, CCreateContext* pContext = NULL);

  void EnableDocking(DWORD dwDockStyle);
  void TileInRow();
  BOOL IsFloating();

  void DockControlBar(UINT nOrientation, RECT *pRect);
  void RestoreControlBar(UINT nPreferredOrientation = AFX_IDW_DOCKBAR_LEFT,
    CRect *pSizeFloating = NULL);

  void InitFloatingPosition(CRect *pSizeFloating);
  void GetFloatingRect(CRect *pFloatingPos);

  void GetPersistedDockingRect(CRect *pDockRect);
  void GetPersistedFloatingRect(CRect *pFloatRect);

  static void SetToolsRestartMode(bool bMode);
  static bool GetToolsRestartMode();

  void SetAllowDockingMenuItemState(bool bState) { m_bAllowDockingMenuItemState = bState; }
  bool AllowDockingMenuItemState() { return m_bAllowDockingMenuItemState; }

  void SetToolID(CLSID* pCLSID);
  CLSID* GetToolID() { return &m_ID; }
  DWORD GetDockStyle() { return m_dwDockStyle; }

  virtual bool CanFrameworkTakeFocus() { return false; }

  virtual BOOL Load(IUnknown* pUnk);
  virtual BOOL Save(IUnknown* pUnk);

  CSize CalcFixedLayout(BOOL bStretch, BOOL bHorz) override;

  bool Anchored();
  bool Anchored(bool bHiddenReturnsLastState);

  static bool ShowPalettes();
  static bool HidePalettes();

  bool AdjustVertDockedBarHeight(int nHeight);

  CGdUiTheme* GetTheme();

  CGdUiTheme* SetTheme(CGdUiTheme* pTheme);

  virtual void ThemeModified(GdUiThemeElement element);

  LONG GetTitleBarSize();

  const CSize& GetHorzDockSize() { return m_HorzDockSize; }
  const CSize& GetVertDockSize() { return m_VertDockSize; }
  void SetHorzDockSize(const CSize& size) { m_HorzDockSize = size; }
  void SetVertDockSize(const CSize& size) { m_VertDockSize = size; }

#ifdef _DEBUG
  void AssertValid() const;
#endif

protected:
  BOOL OnCommand(WPARAM wParam, LPARAM lParam) override;

public:
  ~CGdUiDockControlBar();

protected:
  enum {
    btnWidth = 12,
    btnHeight = 12,
    idCloseBtn = 10001,
    idPinBtn = 10002
  };

protected:
  afx_msg void OnWindowPosChanged(WINDOWPOS FAR* lpwndpos);
  afx_msg BOOL OnEraseBkgnd(CDC* pDC);
  afx_msg void OnAllowDock();
  afx_msg void OnAnchor();
  afx_msg void OnAnchorLeft();
  afx_msg void OnAnchorRight();
  afx_msg void OnHideBar();
  afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
  afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
  afx_msg void OnPaint();

protected:
  void GetUsedRect(CRect& rect);
  void ShowCloseButton(bool bShow) { m_bShowCloseButton = bShow; };
  bool CloseButtonVisible() { return m_bShowCloseButton; };
  void RepositionOrHideButtons();
  static LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);

  virtual void PaintControlBar(CDC *pDC);
  virtual BOOL CreateControlBar(LPCREATESTRUCT lpCreateStruct);
  virtual void SizeChanged(CRect *, BOOL, int) {}
  virtual bool OnClosing();
  virtual void GetFloatingMinSize(long *pnMinWidth, long *pnMinHeight);
  virtual BOOL AddCustomMenuItems(LPARAM hMenu);
  virtual void OnUserSizing(UINT, LPRECT) {};

  DECLARE_DYNAMIC(CGdUiDockControlBar)
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGdUiDockFrame : public CMiniDockFrameWnd
{
  DECLARE_DYNCREATE(CGdUiDockFrame)

public:
  CGdUiDockFrame();

public:
  enum ContainedBarType { Unknown, Standard, GsftBar };

  enum ContainedBarType GetContainedBarType();
protected:
  enum ContainedBarType m_nContainedBarType;
  bool m_bZOrderChanged;

  bool CanFrameworkTakeFocus();
  void ForceChildRepaint();

public:
protected:
  BOOL PreCreateWindow(CREATESTRUCT& cs) override;

protected:
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

  bool CanGscadTakeFocus();

  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGdUiPaletteSetDockFrame : public CMiniDockFrameWnd
{
  friend class CGdUiImpPaletteSet;
  friend class CGdUiDockDragContext;
  friend class CGdUiDockBarMutator;
  friend class CGdUiAnchorBar;

  DECLARE_DYNCREATE(CGdUiPaletteSetDockFrame)

public:
  CGdUiPaletteSetDockFrame();
  ~CGdUiPaletteSetDockFrame();

  BOOL Create(CWnd* pParent, DWORD dwBarStyle) override;
  static bool HidePalettes();
  static bool ShowPalettes();

public:
  enum ContainedBarType { Unknown, Standard, GsftBar };

  enum ContainedBarType GetContainedBarType();

  void SetAutoRollup(BOOL bSet);
  void CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType = adjustBorder) override;

  typedef enum {
    kLeft = 0,
    kRight
  } GdUiTitleBarLocation;

  CGdUiPaletteSetDockFrame::GdUiTitleBarLocation TitleBarLocation();
  void SetTitleBarLocation(CGdUiPaletteSetDockFrame::GdUiTitleBarLocation);

protected:
  enum ContainedBarType m_nContainedBarType;
  bool m_bZOrderChanged;

  bool CanFrameworkTakeFocus();
  void ForceChildRepaint();

  void UpdateThemeElements();

public:
protected:
  BOOL PreCreateWindow(CREATESTRUCT& cs) override;

protected:
  BOOL PreTranslateMessage(MSG * msg) override;

  afx_msg int     OnCreate(LPCREATESTRUCT lpCreateStruct);
  afx_msg void    OnDestroy();
  afx_msg void    OnSize(UINT nType, int cx, int cy);
  afx_msg void    OnClose();
  afx_msg void    OnLButtonDown(UINT nHitTest, CPoint pt);
  afx_msg void    OnNcLButtonDown(UINT nHitTest, CPoint pt);
  afx_msg void    OnNcRButtonDown(UINT nHitTest, CPoint pt);
  afx_msg void    OnNcRButtonUp(UINT nHitTest, CPoint pt);
  afx_msg void    OnNcLButtonUp(UINT nHitTest, CPoint pt);
#if _MSC_VER<1400
  afx_msg UINT OnNcHitTest(CPoint point);
#else
  afx_msg LRESULT OnNcHitTest(CPoint point);
#endif
  afx_msg void    OnMouseMove(UINT nHitTest, CPoint pt);
  afx_msg void    OnNcMouseMove(UINT nHitTest, CPoint pt);
  afx_msg int     OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
  afx_msg void    OnWindowPosChanging(WINDOWPOS* lpwndpos);
  afx_msg void    OnPaint();
  afx_msg void    OnNcPaint();
  afx_msg LRESULT OnDisplayChange(WPARAM wParam, LPARAM lParam);
  afx_msg LRESULT OnNcCalcSize(WPARAM wParam, LPARAM lParam);
  afx_msg void    OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
  afx_msg BOOL    OnNcActivate(BOOL bActive);
  afx_msg void    OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
  afx_msg void    OnSizing(UINT nSide, LPRECT pRect);
  afx_msg void    OnShowWindow(BOOL bShow, UINT nStatus);
  afx_msg BOOL    OnSetCursor(CWnd *pwnd, UINT nHitTest, UINT msg);
  afx_msg void    OnSetFocus(CWnd * pOldWnd);
  afx_msg void    OnTimer(UINT_PTR nIdEvent);
  afx_msg void    OnContextMenu(CWnd* pWnd, CPoint pos);
  afx_msg BOOL    OnEraseBkgnd(CDC* pDC);
  afx_msg LRESULT OnEnterSizeMove(WPARAM, LPARAM);
  afx_msg LRESULT OnExitSizeMove(WPARAM, LPARAM);
  afx_msg void    OnSettingChange(UINT uFlags, LPCTSTR lpszSection);

  virtual LRESULT OnDragEnter(WPARAM wParam, LPARAM lParam);
  virtual LRESULT OnDragOver(WPARAM wParam, LPARAM lParam);
  virtual LRESULT OnDrop(WPARAM wParam, LPARAM lParam);
  virtual LRESULT OnDropEx(WPARAM wParam, LPARAM lParam);
  virtual LRESULT OnDragLeave(WPARAM wParam, LPARAM lParam);
  virtual LRESULT  OnDragScroll(WPARAM wParam, LPARAM lParam);

  bool CanGscadTakeFocus();

  BOOL HitTest(CPoint pt, UINT& nFlag, DWORD& dwData);

  CGdUiPaletteSet* GetPaletteSet();

  DECLARE_MESSAGE_MAP()

private:

  enum GdUiSkBtnItems {
    kBtnUnknown = -1,
    kBtnPushPin = 0,
    kBtnOptionMenu = 1,
    kBtnClose = 2,
    kBtnIcon = 3,
  };

  enum GdUiSkIds {
    kRollupTimerId = 0x3011,
    kRolloutTimerId = 0x3012,
    kCursorCheckTimerId = 0x3013
  };

  enum GdUiSkUiFlags {
    kImgListUnpinnedLeft = 0,
    kImgListUnpinnedRight = 1,
    kImgListPinnedLeft = 2,
    kImgListPinnedRight = 3,
    kImgListOptionMenuLeft = 4,
    kImgListOptionMenuRight = 5,
    kImgListClose = 6,
    kImgList_Count = 7,
  };

  void ncPaint(UINT nPtFlags);
  void windowToNonClient(CRect & rect);
  void nonclientToWindow(CRect & rect);
  void getRegion(CRgn & rgn);
  void getBorderRects(CRect & rectTop, CRect & rectBottom, CRect & rectSide);
  int getMetrics(UINT nItem);
  void getWndCaptionRect(CRect & rect);
  void getWndStatusRect(CRect & rect);
  void getWndSizerRect(CRect & rect);
  void getButtonItemRect(GdUiSkBtnItems eBtn, CRect & rect);
  void GetNonClientSize(CSize& size);
  int  GetTopGrabbableHeight();
  void SnapToRect(CRect & rect, WINDOWPOS * pWndpos,
    int nPaletteWidth, int nPaletteHeight,
    bool bSnapInside, bool bSnapOutside);
  void InitFonts();
  BOOL isImgListItemValid(int nItem);
  void OnOptionsMenu();
  void OnSystemMenu(CPoint pos);

  bool btnPress(GdUiSkBtnItems eBtn, LPPOINT pt);

  void btnPressOptionMenu();
  void btnPressPushPin();
  void btnPressClose();

  void setWindowRgn();

  void    doDrawCaption(CDC *pDC);
  void    doDrawStatus(CDC *pDC);
  void    doDrawBorder(CDC* pDC);
  void    doDrawButton(CDC *pDC, GdUiSkBtnItems btnItem, BOOL bErase = false);
  void    doEraseBackground(CDC *pDC, const CRect & rect, BOOL bErase);
  void    doButtonBlt(CDC *pDC, int nImage, CRect &rcBtn);

  void        displayTip(LPPOINT pt);

  void        SetRollupDelay();
  DWORD       GetRollupDelay() {
    return m_bDelayRolledOut ? m_nHoldopenDelay : m_nRollupDelay;
  }
  void        SetRolloutDelay();
  DWORD       GetRolloutDelay() { return m_nRolloutDelay; }

  void        RollOut(CPoint * pPt, bool bDelay = false);
  void        rollupDlg(BOOL bRollup = TRUE);
  void        SetRolloutTimer();
  void        SetRollupTimer();
  bool        shouldWindowBeRolledUp(CWnd* pWndUnderCursor, CGdUiPaletteSet& ps) const;

  BOOL RolledUp() { return (!m_rectSize.IsRectEmpty()); }
  CRect m_rectSize;
  CSize m_sizeShadow;
  CRect m_rectCaptionText;
  CImageList m_imgListGui;
  CImageList m_imgListIcon;
  DWORD m_dwUiTransientFlags;
  bool  m_bRolloutTimerSet;
  bool  m_bRollupTimerSet;
  static DWORD m_nRollupDelay;
  static DWORD m_nRolloutDelay;
  static DWORD m_nHoldopenDelay;
  CPaletteSetTooltip* m_pToolTip;
  BOOL  m_bAllowSnapping;
  CGdUiDropTarget* m_pDropTarget;
  GdUiTitleBarLocation m_orphanTitleBarLoc;
  bool m_bUserEnteredAutoHideMode;
  CRect m_rectWorkArea;
  bool m_bDelayRolledOut;
};

#endif 
#pragma warning(pop)

void GCAD_PORT GdUiSaveDockingToolPositions();
void GCAD_PORT GdUiShowDockControlBars(bool bShow);
bool GCAD_PORT GdUiRegisterDockingTool(
  LPCTSTR lpszToolName, LPCTSTR lpszCommand, UINT nToolbarID
);
bool GCAD_PORT GdUiRegisterTool(
  LPCTSTR lpszToolName, LPCTSTR lpszCommand, CLSID* pID
);

GCAD_PORT CRuntimeClass* GdUiSetFloatingFrameClass(CRuntimeClass* pNewClass);

GCAD_PORT void GdUiRegisterFloatingFrameClassAddress(CRuntimeClass** pClass);
GCAD_PORT void GdUiRegisterPaletteSetFloatingFrameClass(CRuntimeClass* pClass);
GCAD_PORT CRuntimeClass* GdUiGetRegisteredPaletteSetFloatingFrameClass(void);

typedef HRESULT GDUI_LOADFN(IUnknown** ppGdUiRootNode);
typedef HRESULT GDUI_SAVEFN(IUnknown* pGdUiRootNode);

#ifndef _GSOFT_MAC_
void GCAD_PORT GdUiEnableDocking(
  CFrameWnd *pFrame, DWORD dwDockStyle, GDUI_LOADFN* pLoadFcn, GDUI_SAVEFN* pSaveFcn);

class GCAD_PORT CGdUiPaletteSetDockSite {
public:
  void Initialize(CControlBar* pBar, CSize* pDesiredSize, DWORD dwDockStyle);
  CRect* CanDock(const CPoint& pMousePos);
  bool DockControlBar(CControlBar* pBar);
private:
  DWORD           m_dwDockStyle;
  CControlBar*    m_pBar;
  CGdUiDockBar*   m_pTargetDockBar;
  CFrameWnd*      m_pDockSite;

  CRect m_rectDragDock;
  CRect m_rectDragHorz;
  CRect m_rectDragHorzAlone;

};
#endif 

bool GCAD_PORT CanStealFocusFromDockedWindow();
void GCAD_PORT GetSystemVirtualScreen(RECT &rect);

void GCAD_PORT GdUiEnableDockControlBars(BOOL bEnable, CStringArray* pToolIds = NULL);

#pragma pack (pop)
#endif