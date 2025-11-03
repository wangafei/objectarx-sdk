#ifndef _GduiTextTip_h
#define _GduiTextTip_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//#include "gdui.h"

/////////////////////////////////////////////////////////////////////////////
// CGdUiTipWindow
#pragma warning(push)
#pragma warning(disable : 4275)
class GDUI_PORT CGdUiTipWindow : public CWnd {
	DECLARE_DYNAMIC(CGdUiTipWindow)

public:
                CGdUiTipWindow ();
 virtual         ~CGdUiTipWindow ();

// Tip Window
private:
        void    ForwardClickMessage (UINT msg, UINT nFlags, CPoint& point, BOOL focus);
protected:
static  LPCTSTR m_className;                // Registered class name
static const UINT m_timerEvent;

        BOOL    m_bUseText;                 // Draw as text vs. owner-draw.
        CWnd    *m_control;                 // Related control
        CWnd    *m_owner;                   // Owner (dialog, etc.)
        UINT    m_timerId;

virtual void    DrawBorder (CDC& dc, CRect& rExterior, CRect& rInterior);
 virtual void    DrawContent (CDC& dc, CRect& rInterior);
        void    StartTimer (DWORD ms=50);
        void    StopTimer ();
public:
virtual BOOL    Create (CWnd *owner);
        CWnd    *GetControl ();
        void    GetTextExtent (LPCTSTR text, int& width, int& height);
        BOOL    GetUseText ();
virtual void    Hide ();
        CWnd    *Owner ();
        void    SetControl (CWnd *control);
        void    SetUseText (BOOL useText);
 virtual void    Show ();

// ClassWizard-controlled
public:
    //{{AFX_VIRTUAL(CGdUiTipWindow)
    //}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGdUiTipWindow)
	afx_msg void OnActivateApp(BOOL bActive, DWORD hTask);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnNcDestroy();
	afx_msg void OnPaint();
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)
/////////////////////////////////////////////////////////////////////////////
// CGdUiBalloonTip window - INTERNAL USE ONLY

class GDUI_PORT CGdUiBalloonTip : public CGdUiTipWindow {
	DECLARE_DYNAMIC(CGdUiBalloonTip)

public:
                CGdUiBalloonTip ();
 virtual         ~CGdUiBalloonTip ();

// Text Tip
protected:
        CPoint  m_initialCursorPos;

virtual void    DrawBorder (CDC& dc, CRect& rExterior, CRect& rInterior);
virtual void    DrawContent (CDC& dc, CRect& rInterior);
public:
virtual void    Hide ();
virtual void    Show ();

// ClassWizard-controlled
public:
    //{{AFX_VIRTUAL(CGdUiBalloonTip)
    //}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGdUiBalloonTip)
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CGdUiTextTip window

class GDUI_PORT CGdUiTextTip : public CGdUiTipWindow {
	DECLARE_DYNAMIC(CGdUiTextTip)

public:
                CGdUiTextTip ();
 virtual         ~CGdUiTextTip ();

// Text Tip
protected:
virtual void    DrawBorder (CDC& dc, CRect& rExterior, CRect& rInterior);
virtual void    DrawContent (CDC& dc, CRect& rInterior);
public:
virtual void    Hide ();
        void    Update (CWnd *control, BOOL useText);
        void    UpdateIfNecessary (CWnd *control, BOOL useText);

// ClassWizard-controlled
public:
    //{{AFX_VIRTUAL(CGdUiTextTip)
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    //}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGdUiTextTip)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CGdToolTipCtrl: for INTERNAL USE ONLY.
//typedef CToolTipCtrl CGdToolTipCtrl;

class GDUI_PORT CGdToolTipCtrl : public CToolTipCtrl
{
public:
  static void SetDeaultDelayTime(int nDelay);

  virtual ~CGdToolTipCtrl() {}
  static void SetToolTipsFlag(BOOL bToolTipsFlag);

public:
  //{{AFX_VIRTUAL(CGdToolTipCtrl)
  virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
  //}}AFX_VIRTUAL

protected:
  //{{AFX_MSG(CGdToolTipCtrl)
  afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
  afx_msg void OnDestroy();
  //}}AFX_MSG

  DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// These functions are all for INTERNAL USE ONLY.

void GDUI_PORT GdUiHideBalloonTip (CWnd *control);
BOOL GDUI_PORT GdUiShowBalloonTip (
    CWnd *owner, CWnd *control, LPCTSTR text, BOOL beep
);
BOOL GDUI_PORT GdUiShowBalloonTip (
    CWnd *owner, CWnd *control, CRect& rect, LPCTSTR text, BOOL beep
);

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

//////////////////////////////////////////////////////////////////////////////
