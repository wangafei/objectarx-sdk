#ifndef _GCUI_COMBOBOX_
#define _GCUI_COMBOBOX_

#pragma pack(push, 8)

#pragma warning(push)
#pragma warning(disable : 4275)

class GDUI_PORT CGdUiComboBox : public CComboBox 
{
  DECLARE_DYNAMIC(CGdUiComboBox)

public:
  CGdUiComboBox();
  virtual ~CGdUiComboBox();

public:
  virtual void  GetLBString(int nIndex, CString& rString);

protected:
  CPoint  m_lastMousePoint;
  CRect   m_tipRect;
  CString m_sToolTipText;

public:
  static  bool    IsVistaTheme();
  static  bool    IsInEdit(UINT nItemState);

  virtual BOOL    Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
  virtual BOOL    OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
  virtual void    DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

  virtual void    GetContentExtent (LPCTSTR text, int& width, int& height);
  void    GetTextExtent (LPCTSTR text, int& width, int& height);
  BOOL    IsOwnerDraw ();
  BOOL    IsStatic ();

  // GdUi message handlers
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
  virtual void    OnDrawThemeComboBoxBk(LPDRAWITEMSTRUCT lpDrawItemStruct);
public:
  BOOL            GetThemeEnable();
  void            SetThemeEnable(BOOL bEnable);
  CWnd    *GetGdUiParent ();
  void    SetGdUiParent (CWnd *w);

  CString  GetToolTipText      (void) const;
  BOOL     SetToolTipText      (const CString& sText);

  // Subclassed controls
protected:
  bool    m_bAutoDeleteEBox       : 1;    // set to automatically delete
  bool    m_bAutoDeleteLBox       : 1;    //  the edit or listbox controls
  bool    m_bSubclassedControls   : 1;    // set when all children are found
  CGdUiEdit *m_pComboEBox;                // the child edit control (if any)
  CGdUiListBox *m_pComboLBox;             // the list box
  BOOL    m_bThemeEnable;
public:
  CGdUiEdit *GetEditBox ();
  void    SetEditBox (CGdUiEdit *control, BOOL autoDelete);
  CGdUiListBox *GetListBox ();
  void    SetListBox (CGdUiListBox *control, BOOL autoDelete);

  // Validation style for subclassed EditBox
public:
  DWORD   GetStyleMask ();
  BOOL    IsStyleMaskSet (DWORD mask);
  void    SetStyleMask (DWORD mask);

  // ClassWizard-controlled
public:
  //{{AFX_VIRTUAL(CGdUiComboBox)
  //}}AFX_VIRTUAL

protected:
  virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
  //{{AFX_MSG(CGdUiComboBox)
  afx_msg void OnPaint();
  afx_msg LRESULT OnGdUiMessage (WPARAM wParam, LPARAM lParam);
  afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
  afx_msg void OnMouseMove(UINT nFlags, CPoint point);
  //}}AFX_MSG
  afx_msg LRESULT  OnGetToolTipText  (WPARAM wParam, LPARAM lParam);
  DECLARE_MESSAGE_MAP()
};

#pragma warning(pop)
#pragma pack (pop)

#endif//_GCUI_COMBOBOX_
