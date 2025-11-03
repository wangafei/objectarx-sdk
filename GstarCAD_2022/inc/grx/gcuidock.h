#ifndef _GCUIDOCK_H
#define _GCUIDOCK_H
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CGcUiDockFrame window 

class GCUI_PORT CGcUiDockFrame : public CGdUiDockFrame {
  DECLARE_DYNCREATE(CGcUiDockFrame);

public:
  CGcUiDockFrame();
  virtual         ~CGcUiDockFrame();

  // ClassWizard-controlled
public:
  //{{AFX_VIRTUAL(CAcUiDockFrame)
  //}}AFX_VIRTUAL

protected:
  //{{AFX_MSG(CAcUiDockFrame)
  afx_msg LRESULT OnACADKeepFocus(WPARAM wParam, LPARAM lParam);
  //}}AFX_MSG

  DECLARE_MESSAGE_MAP()
};


class GCUI_PORT CGcUiDockControlBar : public CGdUiDockControlBar {
    DECLARE_DYNCREATE(CGcUiDockControlBar);

public:
    CGcUiDockControlBar () {}

protected:
    virtual bool CanFrameworkTakeFocus ();
};

#pragma pack (pop)
#endif