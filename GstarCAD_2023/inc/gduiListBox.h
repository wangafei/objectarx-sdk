/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiListBox_h
#define _gduiListBox_h
#pragma pack (push, 8)

#pragma once

#ifndef _GSOFT_MAC_
#pragma warning(push)
#pragma warning(disable : 4275)
class GCAD_PORT CGdUiListBox : public CListBox {
  DECLARE_DYNAMIC(CGdUiListBox);

public:
  CGdUiListBox();
  ~CGdUiListBox();

protected:
  CPoint  m_lastMousePoint;
  int     m_tipItem;
  CRect   m_tipRect;

public:
  virtual void    GetContentExtent(
    int item, LPCTSTR text, int& width, int& height
  );
  int     GetItemAtPoint(CPoint& p);
  void    GetTextExtent(LPCTSTR text, int& width, int& height);
  BOOL    IsOwnerDraw();

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

protected:
  BOOL    m_bComboBoxDraw;
  CGdUiComboBox *m_pComboBox;

public:
  CGdUiComboBox *GetComboBox();
  void    SetComboBox(CGdUiComboBox *control);
  BOOL    GetComboBoxDraw();
  void    SetComboBoxDraw(BOOL comboBoxDraw);

public:
  int  CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct) override;
  void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct) override;
  void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override;
  void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) override;

protected:
  afx_msg LRESULT OnGdUiMessage(WPARAM wParam, LPARAM lParam);
  afx_msg void OnDestroy();
  afx_msg void OnMouseMove(UINT nFlags, CPoint point);
  DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)

#endif 

#pragma pack (pop)
#endif
