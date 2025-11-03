#ifndef _GduiButton_h
#define _GduiButton_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "gdUiTheme.h"  // INTERNAL USE ONLY
//#include "gdui.h"

class CGdUiOwnerDrawButton;
class CGdUiTrackButtonDraw;

class CGdUiODButtonThemeModReactor : public CGdUiThemeModifiedReactor  // INTERNAL USE ONLY
{
public:
    CGdUiODButtonThemeModReactor(CGdUiOwnerDrawButton* pBtn);  // INTERNAL USE ONLY
    virtual void ThemeModified(const CGdUiTheme * pTheme, GdUiThemeElement element);  // INTERNAL USE ONLY

private:
    CGdUiOwnerDrawButton * m_pBtn;
};


/////////////////////////////////////////////////////////////////////////////
// CGdUiOwnerDrawButton
#pragma warning(push)
#pragma warning(disable : 4275)
class GDUI_PORT CGdUiOwnerDrawButton : public CButton {
  friend class CGdUiODButtonThemeModReactor;  // INTERNAL USE ONLY

  DECLARE_DYNAMIC(CGdUiOwnerDrawButton)

public:
  CGdUiOwnerDrawButton ();
  virtual         ~CGdUiOwnerDrawButton ();

protected:
  CPoint  m_lastMousePoint;
  CRect   m_tipRect;
  CGdUiTheme * m_pTheme;  // INTERNAL USE ONLY

// GdUi message handler
protected:
  CWnd    *m_gduiParent;

  virtual GDUI_REPLY DoGdUiMessage (
    GDUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam
    );
  virtual void    OnDrawTip (CDC& dc);
  virtual BOOL    OnDrawTipText (CGdUiDrawTipText& dtt);
  virtual GDUI_REPLY OnGetTipSupport (CPoint& p);
  virtual BOOL    OnGetTipRect (CRect& r);
  virtual BOOL    OnGetTipText (CString& text);
  virtual BOOL    OnHitTipRect (CPoint& p);
public:
  CWnd    *GetGdUiParent ();
  void    SetGdUiParent (CWnd *w);

  virtual void    SetTracking(BOOL b) { m_bIsTrackButton = b; };
  virtual CGdUiTheme * SetTheme(CGdUiTheme *pTheme);  // INTERNAL USE ONLY

  // Owner Draw routines
protected:
  static const UINT_PTR m_timerEvent;
  bool    m_bEnableDragDrop   : 1;
  bool    m_bEnableFastDraw   : 1;
  bool    m_bEnablePointedAt  : 1;
  bool    m_bIsPointedAt      : 1;
  bool    m_bIsStatic         : 1;
  bool    m_bIsToolButton     : 1;
  bool    m_bIsTrackButton    : 1;
  UINT_PTR  m_timerId;

  // members added for XP look and feel
  int     m_nPartId;
  int     m_nStateId;
  UINT    m_uEdge;
  BOOL    m_bMouseHover;

  virtual void    DrawBorder(CDC *pDC,CRect &r,COLORREF cr);
  virtual void    DrawHotBorder();
  virtual void    DrawButton(
    CDC& dc, int w, int h,
    BOOL isDefault,
    BOOL isDisabled,
    BOOL isSelected,
    BOOL isFocused
    );
  virtual void    DrawPushButtonBorder (
    CDC& dc, CRect& rButton, BOOL isDefault, BOOL isSelected
    );
  virtual void    DrawToolButtonBorder (
    CDC& dc, CRect& rButton, BOOL isSelected, BOOL isFocused
    );
  void    DrawTransparentBitmap (
    CDC& dc,
    CBitmap& bmp,
    int x, int y, int w, int h,
    BOOL isDisabled
    );
  void    DrawContentText (
    CDC& dc,
    CString sText,
    CRect& rcText,
    BOOL isDisabled
    );
  BOOL    GetIsPointedAt ();
  void    SetIsPointedAt (BOOL isPointedAt);
  virtual BOOL    OnAutoLoad ();
  virtual void    OnDragDrop (HDROP hDropInfo);
  virtual void    OnPointedAt (BOOL isPointedAt);
  virtual BOOL    OnReload (LPCTSTR strResId);
  void    StartTimer (DWORD ms=50);
  void    StopTimer ();


  virtual void ThemeModified(GdUiThemeElement element);  // INTERNAL USE ONLY
public:
  BOOL    AutoLoad ();
  BOOL    GetEnableDragDrop ();
  void    SetEnableDragDrop (BOOL allow);
  BOOL    GetEnableFastDraw ();
  void    SetEnableFastDraw (BOOL allow);
  BOOL    GetEnablePointedAt ();
  void    SetEnablePointedAt (BOOL allow);
  BOOL    GetIsStatic ();
  void    SetIsStatic (BOOL isStatic);
  BOOL    GetIsToolButton ();
  void    SetIsToolButton (BOOL isToolButton);
  BOOL    Reload (LPCTSTR strResId);

  // ClassWizard-controlled
public:
  //{{AFX_VIRTUAL(CGdUiOwnerDrawButton)
public:
  virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
  virtual void PreSubclassWindow();
  //}}AFX_VIRTUAL

protected:
  //{{AFX_MSG(CGdUiOwnerDrawButton)
  afx_msg LRESULT OnGdUiMessage (WPARAM wParam, LPARAM lParam);
  afx_msg void OnDropFiles(HDROP hDropInfo);
  afx_msg UINT OnGetDlgCode();
  afx_msg void OnKillFocus(CWnd* pNewWnd);
  afx_msg void OnMouseMove(UINT nFlags, CPoint point);
  afx_msg LRESULT OnMouseLeave(WPARAM, LPARAM);
  afx_msg void OnNcDestroy();
  afx_msg void OnSetFocus(CWnd* pOldWnd);
  afx_msg void OnTimer(UINT_PTR nIDEvent);
  afx_msg void OnDestroy( );
  afx_msg LRESULT OnThemeChanged(WPARAM wParam, LPARAM lParam);
  //}}AFX_MSG

  DECLARE_MESSAGE_MAP()
protected:
  HANDLE GetVisualStylesTheme() {return m_hVS;}
private:
  CGdUiODButtonThemeModReactor* m_pThemeModReactor;  // INTERNAL USE ONLY
  HANDLE    m_hVS;               // INTERNAL USE ONLY
};
#pragma warning(pop)
/////////////////////////////////////////////////////////////////////////////
// CGdUiBitmapButton

class GDUI_PORT CGdUiBitmapButton : public CGdUiOwnerDrawButton {
  DECLARE_DYNAMIC(CGdUiBitmapButton)

  friend class CGdUiImpBitmapButton;
public:
  CGdUiBitmapButton ();
  virtual         ~CGdUiBitmapButton ();

  // Owner Draw routines
protected:
  virtual void    DrawButton(
    CDC& dc, int w, int h,
    BOOL isDefault,
    BOOL isDisabled,
    BOOL isSelected,
    BOOL isFocused
    );
  virtual BOOL    OnAutoLoad ();
  virtual BOOL    OnReload (LPCTSTR strResId);

  // Bitmap Button routines
protected:
  BOOL    m_bAutoSizeToBitmap;
  CBitmap m_bmp;
  CString m_bmpResId;
  int     m_bmpHeight;
  int     m_bmpWidth;
  int     m_bmpX;
  int     m_bmpY;
  int     m_focusRectOffset;

  void    CalcBitmapSize ();
  BOOL    LoadBitmap (LPCTSTR strResId);
  BOOL    LoadBitmapResource (
    LPCTSTR strResId, CBitmap& bmp, HINSTANCE hInst
    );
  virtual BOOL    OnLoadBitmap (LPCTSTR strResId);
public:
  BOOL    GetAutoSizeToBitmap ();
  void    SetAutoSizeToBitmap (BOOL autoSizeToBitmap);
  void    SizeToBitmap ();
  void    SetBitmapOffsets(int nBorderOffset, int nFocusRectOffset);

  // ClassWizard-controlled
public:
  //{{AFX_VIRTUAL(CGdUiBitmapButton)
  //}}AFX_VIRTUAL

protected:
  //{{AFX_MSG(CGdUiBitmapButton)
  //}}AFX_MSG

  DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CGdUiBitmapStatic

class GDUI_PORT CGdUiBitmapStatic : public CGdUiBitmapButton {
	DECLARE_DYNAMIC(CGdUiBitmapStatic)

public:
	            CGdUiBitmapStatic ();
 virtual         ~CGdUiBitmapStatic ();

// ClassWizard-controlled
public:
	//{{AFX_VIRTUAL(CGdUiBitmapStatic)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGdUiBitmapStatic)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CGdUiDropSite

class GDUI_PORT CGdUiDropSite : public CGdUiBitmapStatic {
	DECLARE_DYNAMIC(CGdUiDropSite)

public:
	            CGdUiDropSite ();
 virtual         ~CGdUiDropSite ();

// ClassWizard-controlled
public:
	//{{AFX_VIRTUAL(CGdUiDropSite)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGdUiDropSite)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CGdUiToolButton

class GDUI_PORT CGdUiToolButton : public CGdUiBitmapButton {
	DECLARE_DYNAMIC(CGdUiToolButton)

public:
	            CGdUiToolButton ();
 virtual         ~CGdUiToolButton ();

// ClassWizard-controlled
public:
	//{{AFX_VIRTUAL(CGdUiToolButton)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGdUiToolButton)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CGdUiTrackButton

class GDUI_PORT CGdUiTrackButton : public CGdUiOwnerDrawButton {
	DECLARE_DYNAMIC(CGdUiTrackButton)

public:
	            CGdUiTrackButton();
                CGdUiTrackButton(const CGdUiTrackButtonDraw & pDraw);
 virtual         ~CGdUiTrackButton();

// ClassWizard-controlled
public:
	//{{AFX_VIRTUAL(CGdUiTrackButton)
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

virtual CGdUiTheme * GetTheme() const;
 virtual CGdUiTheme * SetTheme(CGdUiTheme *pTheme);  // INTERNAL USE ONLY

static  CGdUiTrackButtonDraw * SetDefaultDraw(CGdUiTrackButtonDraw * pDraw);
        CGdUiTrackButtonDraw * SetDraw(CGdUiTrackButtonDraw * pDraw);

virtual void    SetTracking(BOOL b);

protected:
virtual void    DrawButton(
                    CDC& dc, int w, int h,
	                BOOL isDefault,
	                BOOL isDisabled,
                    BOOL isSelected,
	                BOOL isFocused
                );
virtual void    DrawBorder(CDC *pDC,CRect &r,COLORREF cr);
virtual void    DrawHotBorder();
virtual void    DrawPushButtonBorder (CDC& dc, CRect& rButton, BOOL isDefault, BOOL isSelected);
virtual void    DrawToolButtonBorder (CDC& dc, CRect& rButton, BOOL isSelected, BOOL isFocused);

virtual GDUI_REPLY OnGetTipSupport (CPoint& p);

	//{{AFX_MSG(CGdUiTrackButton)
    afx_msg void OnNcPaint();
    afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

     virtual void releaseDraw();

// Implementation
private:
    static CGdUiTrackButtonDraw * s_pDefaultDraw;
    CGdUiTrackButtonDraw * m_pDraw;

};
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

//////////////////////////////////////////////////////////////////////////////
