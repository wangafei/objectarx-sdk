/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiListCtrl_h
#define _gduiListCtrl_h
#pragma pack (push, 8)

#pragma once

#ifndef _GSOFT_MAC_
#pragma warning(push)
#pragma warning(disable : 4275)
class GCAD_PORT CGdUiListCtrl : public CListCtrl {
  DECLARE_DYNAMIC(CGdUiListCtrl);

public:
  CGdUiListCtrl();
  ~CGdUiListCtrl();

protected:
  CPoint  m_lastMousePoint;
  int     m_tipIndex;
  int     m_tipItem;
  CRect   m_tipRect;

public:
  CGdUiHeaderCtrl m_headerCtrl;

  int     ColumnCount();
  virtual void    GetContentExtent(
    int item, int index, LPCTSTR text, int& width, int& height
  );
  BOOL    GetItemAtPoint(CPoint& p, int& item, int& index);
  BOOL    GetSubItemRect(int item, int index, CRect& rect);
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

public:
protected:
  void PreSubclassWindow() override;

protected:
  afx_msg LRESULT OnGdUiMessage(WPARAM wParam, LPARAM lParam);
  afx_msg void OnMouseMove(UINT nFlags, CPoint point);
  DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)

#endif 

#pragma pack (pop)
#endif
