#ifndef _GduiEdit_h
#define _GduiEdit_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//#include "gdui.h"

////////////////////////////////////////////////////////////////////////////
// CGdUiEdit window
#pragma warning(push)
#pragma warning(disable : 4275)
class GDUI_PORT CGdUiEdit : public CEdit {
    DECLARE_DYNAMIC(CGdUiEdit)

public:
                CGdUiEdit ();
virtual         ~CGdUiEdit ();

// Misc.
protected:
        CPoint  m_lastMousePoint;
        CRect   m_tipRect;

public:
virtual void    GetContentExtent (LPCTSTR text, int& width, int& height);
        void    GetTextExtent (LPCTSTR text, int& width, int& height);

// Validation style
public:
        DWORD   m_styleMask;            // style bits (application-defined)

virtual void    SetStyleMask (DWORD);   // define behavior
        DWORD   GetStyleMask ();        // fetch the style
        BOOL    IsStyleMaskSet (DWORD); // verify styles

// GdUi message handlers
protected:
        CWnd    *m_iduiParent;
        //background brush
        CBrush m_brBackGnd;	
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
        void    SetThemeEnable(BOOL bEnable);
// ClassWizard-controlled
public:
	//{{AFX_VIRTUAL(CGdUiEdit)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGdUiEdit)
    afx_msg LRESULT OnGdUiMessage (WPARAM wParam, LPARAM lParam);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
    afx_msg void OnPaint();
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
protected:
  BOOL m_bThemeEnable;
};

class    CGdUiSearchBoxEditor;
class    CGdUiSearchBoxSearchButton;
class    CGdUiSearchBoxClearButton;

////////////////////////////////////////////////////////////////////////////
// CGdUiSearchBox window
class GDUI_PORT CGdUiSearchBox : public CGdUiEdit{
  DECLARE_DYNAMIC(CGdUiSearchBox)

public:
  CGdUiSearchBox ();
  virtual         ~CGdUiSearchBox ();
  virtual BOOL    Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
  virtual void    PreSubclassWindow();
  void    SetDefaultText(LPCTSTR pszText);
  void    SetNotification(LPCTSTR pszText);
  void    ClearEditor();
  bool    IsEditEmpty();

public: //Override methods
  virtual void    EditChanged();
  virtual void    ClearButtonClicked();
  virtual void    SearchButtonClicked();

protected:
  virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
  //{{AFX_MSG(CAdUiComboBox)
  virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
  afx_msg void OnClearButton();
  afx_msg void OnSearchButton();
  afx_msg void SetEditFocus();
  afx_msg void KillEditFocus();
  afx_msg void OnEditChange();
  afx_msg void OnSize(UINT nType, int cx, int cy);
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
private:
  BOOL    CreateControls();
  BOOL    DestroyControls();
  void    UpdateSearchBox();
  void    UpdateButton();
  void    GetControlRect(CRect &editRect, CRect &buttonRect);

private:
  bool                    m_bIsControlsCreated;
  CGdUiSearchBoxEditor*    m_pEditor;
  CGdUiSearchBoxSearchButton*      m_pBtnSearch;
  CGdUiSearchBoxClearButton*   m_pBtnClear;

  CString                 m_strNotification;
  CString                 m_strDefaultText;
};
#pragma warning(pop)
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

/////////////////////////////////////////////////////////////////////////////
