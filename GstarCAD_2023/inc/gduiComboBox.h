/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiComboBox_h
#define _gduiComboBox_h
#pragma pack (push, 8)

#pragma once

#ifndef _GSOFT_MAC_
#pragma warning(push)
#pragma warning(disable : 4275)

class CGdUiComboBoxDraw;

class GCAD_PORT CGdUiComboBox : public CComboBox {
  DECLARE_DYNAMIC(CGdUiComboBox)

public:
  CGdUiComboBox();
  ~CGdUiComboBox();

public:
  void    GetLBString(int nIndex, CString& rString);

protected:
  CPoint  m_lastMousePoint;
  CRect   m_tipRect;
  CString m_sToolTipText;
  CGdUiComboBoxDraw* m_pDraw;
  CGdUiTheme* m_pTheme;

public:
  static  bool    IsVistaTheme();
  static  bool    IsInEdit(UINT nItemState);

  BOOL    Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID) override;
  BOOL    OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*) override;
  void    DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override;
  void    MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) override;

  virtual void    GetContentExtent(LPCTSTR text, int& width, int& height);
  void    GetTextExtent(LPCTSTR text, int& width, int& height);
  BOOL    IsOwnerDraw();
  BOOL    IsStatic();

  void    SetDraw(CGdUiComboBoxDraw* pDraw);

  bool    IsThemed() const;
  void    SetIsThemed(bool bValue);

  CGdUiTheme* GetTheme() const;
  void SetTheme(CGdUiTheme* pTheme);

protected:
  CWnd    *m_gduiParent;

  virtual GDUI_REPLY DoGdUiMessage(
    GDUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam
  );
  virtual void    OnDrawTip(CDC& dc);
  virtual BOOL    OnDrawTipText(CGdUiDrawTipText& dtt);
  virtual GDUI_REPLY OnGetTipSupport(CPoint& p);
  virtual BOOL    OnGetTipRect(CRect& r);
  virtual BOOL    OnGetTipText(CString& text);
  virtual BOOL    OnHitTipRect(CPoint& p);
public:
  CWnd    *GetGdUiParent();
  void    SetGdUiParent(CWnd *w);

  CString  GetToolTipText(void) const;
  BOOL     SetToolTipText(const CString& sText);

protected:
  bool    m_bAutoDeleteEBox : 1;
  bool    m_bAutoDeleteLBox : 1;
  bool    m_bSubclassedControls : 1;
  CGdUiEdit *m_pComboEBox;
  CGdUiListBox *m_pComboLBox;
public:
  CGdUiEdit *GetEditBox();
  void    SetEditBox(CGdUiEdit *control, BOOL autoDelete);
  CGdUiListBox *GetListBox();
  void    SetListBox(CGdUiListBox *control, BOOL autoDelete);

public:
  DWORD   GetStyleMask();
  BOOL    IsStyleMaskSet(DWORD mask);
  void    SetStyleMask(DWORD mask);

public:
  void PreSubclassWindow() override;

protected:
  LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam) override;
  afx_msg void OnPaint();
  afx_msg LRESULT OnGdUiMessage(WPARAM wParam, LPARAM lParam);
  afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
  afx_msg void OnMouseMove(UINT nFlags, CPoint point);
  afx_msg LRESULT  OnGetToolTipText(WPARAM wParam, LPARAM lParam);
  DECLARE_MESSAGE_MAP()
};

inline void CGdUiComboBox::SetDraw(CGdUiComboBoxDraw* pDraw)
{
  m_pDraw = pDraw;
}

inline CGdUiTheme* CGdUiComboBox::GetTheme() const
{
  return m_pTheme;
}

#pragma warning(pop)

#endif 

#pragma pack (pop)
#endif
