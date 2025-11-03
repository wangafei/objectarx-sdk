/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiHeaderCtrl_h
#define _gduiHeaderCtrl_h
#pragma pack (push, 8)

#pragma once

#ifndef _GSOFT_MAC_
#pragma warning(push)
#pragma warning(disable : 4275)
class GCAD_PORT CGdUiHeaderCtrl : public CHeaderCtrl {
  DECLARE_DYNAMIC(CGdUiHeaderCtrl)

public:
  CGdUiHeaderCtrl();
  ~CGdUiHeaderCtrl();

protected:
  CPoint  m_lastMousePoint;
  int     m_tipItem;
  CRect   m_tipRect;

public:
  virtual void    GetContentExtent(
    int item, LPCTSTR text, int& width, int& height
  );
  int     GetItemAtPoint(CPoint& p);
  BOOL    GetItemRect(int idx, CRect& rItem);
  BOOL    GetText(int idx, CString& text);
  void    GetTextExtent(LPCTSTR text, int& width, int& height);
  BOOL    IsOwnerDraw(int idx);

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
  afx_msg LRESULT OnGdUiMessage(WPARAM wParam, LPARAM lParam);
  afx_msg void OnMouseMove(UINT nFlags, CPoint point);
  DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)

#endif 

#pragma pack (pop)
#endif
