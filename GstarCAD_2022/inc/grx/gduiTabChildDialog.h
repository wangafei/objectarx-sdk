#ifndef _GduiTabChildDialog_h
#define _GduiTabChildDialog_h
#pragma pack (push, 8)

//#include "gdui.h"

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//////////////////////////////////////////////////////////////////////////////

class GDUI_PORT CGdUiTabChildDialog : public CGdUiDialog {
  friend class CGdUiTab;

  DECLARE_DYNAMIC(CGdUiTabChildDialog);

public:
  CGdUiTabChildDialog (
    CWnd *pParent=NULL,
    HINSTANCE hDialogResource=NULL
    );

  // Tab Child Dialog
private:
  BOOL    m_bDirty;
  HWND    m_hWndFocus;
  CGdUiTab *m_pGcadTab;

  void    SetGcadTabPointer (CGdUiTab *pGcadTab);
  BOOL    TranslateTabKey ();
public:
  CGdUiTab *GetGcadTabPointer ();
  CGdUiTabMainDialog *GetMainDialog ();
  int     GetTabIndex ();
  BOOL    IsDirty ();
  virtual void    OnTabActivation (BOOL bActivate);
  virtual BOOL    OnTabChanging ();
  void    SetGcadTabChildFocus (HWND hWndFocus);

  // Call this if you've changed your contents and might need saving...
  void    SetDirty (BOOL bDirty=TRUE);

  void    SetValidationInfo (CDataExchange *pDX);

  // Elasticity
protected:
  virtual void    OnInitDialogBegin ();
  virtual void    OnInitDialogFinish ();

  // ClassWizard-controlled
public:
  //{{AFX_DATA(CGdUiTabChildDialog)
  enum { IDD = 0 };
  //}}AFX_DATA

  //{{AFX_VIRTUAL(CGdUiTabChildDialog)
public:
  virtual BOOL PreTranslateMessage(MSG* pMsg);
  virtual void OnMainDialogApply();
  virtual void OnMainDialogCancel();
  virtual void OnMainDialogOK();
  virtual BOOL OnMainDialogHelp();     
  virtual BOOL DoDialogHelp();// INTERNAL USE ONLY

protected:
  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  virtual void OnCancel();
  virtual void OnOK();
  //}}AFX_VIRTUAL

protected:
  //{{AFX_MSG(CGdUiTabChildDialog)
  afx_msg void OnSize(UINT nType, int cx, int cy);
  //}}AFX_MSG
  afx_msg LRESULT OnResizePage(WPARAM wParam, LPARAM lParam);

  DECLARE_MESSAGE_MAP()
};

//////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

//////////////////////////////////////////////////////////////////////////////
