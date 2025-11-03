/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiTextTip_h
#define _gduiTextTip_h

#pragma pack (push, 8)

#pragma once

#ifndef _GSOFT_MAC_
#pragma warning(push)
#pragma warning(disable : 4275)
class GCAD_PORT CGdUiTipWindow : public CWnd {
  DECLARE_DYNAMIC(CGdUiTipWindow)

public:
  CGdUiTipWindow();
  ~CGdUiTipWindow();

private:
  void    ForwardClickMessage(UINT msg, UINT nFlags, CPoint& point, BOOL focus);
protected:
  static  LPCTSTR m_className;
  static const UINT_PTR m_timerEvent;

  BOOL    m_bUseText;
  CWnd    *m_control;
  CWnd    *m_owner;
  UINT_PTR m_timerId;

  virtual void    DrawBorder(CDC& dc, CRect& rExterior, CRect& rInterior);
  virtual void    DrawContent(CDC& dc, CRect& rInterior);
  void    StartTimer(DWORD ms = 50);
  void    StopTimer();
public:
  virtual BOOL    Create(CWnd *owner);
  CWnd    *GetControl();
  void    GetTextExtent(LPCTSTR text, int& width, int& height);
  BOOL    GetUseText();
  virtual void    Hide();
  CWnd    *Owner();
  void    SetControl(CWnd *control);
  void    SetUseText(BOOL useText);
  virtual void    Show();

protected:
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
  DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)

class GCAD_PORT CGdUiBalloonTip : public CGdUiTipWindow {
  DECLARE_DYNAMIC(CGdUiBalloonTip)

public:
  CGdUiBalloonTip();
  ~CGdUiBalloonTip();

protected:
  CPoint  m_initialCursorPos;

  void    DrawBorder(CDC& dc, CRect& rExterior, CRect& rInterior) override;
  void    DrawContent(CDC& dc, CRect& rInterior) override;

public:
  void    Hide() override;
  void    Show() override;

protected:
  afx_msg void OnTimer(UINT_PTR nIDEvent);
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGdUiTextTip : public CGdUiTipWindow {
  DECLARE_DYNAMIC(CGdUiTextTip)

public:
  CGdUiTextTip();
  ~CGdUiTextTip();

protected:
  void    DrawBorder(CDC& dc, CRect& rExterior, CRect& rInterior) override;
  void    DrawContent(CDC& dc, CRect& rInterior) override;
public:
  void    Hide() override;
  void    Update(CWnd *control, BOOL useText);
  void    UpdateIfNecessary(CWnd *control, BOOL useText);

public:
  BOOL PreCreateWindow(CREATESTRUCT& cs) override;

protected:
  DECLARE_MESSAGE_MAP()
};

class GdToolTip;

#pragma warning(push)
#pragma warning(disable : 4275)
class GCAD_PORT CGdToolTipCtrl : public CToolTipCtrl {

  DECLARE_MESSAGE_MAP()
public:
  CGdToolTipCtrl();
  ~CGdToolTipCtrl();

  BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult) override;
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
  afx_msg void OnDestroy();
  static void SetToolTipsFlag(BOOL bToolTipsFlag);
  static void SetDeaultDelayTime(int nDelay);

protected:
  virtual GdToolTip * CreateGdToolTipInstance();
  GdToolTip* m_pToolTip;
  BOOL m_bActivate;
  UINT m_nDelayTime;

private:
  static BOOL m_bToolTipHasCreated;
  static BOOL m_bToolTipsFlag;
  static UINT m_nDefaultDealyTime;
};
#pragma warning(pop)


class GdWthToolTip;

class GCAD_PORT CGdWthToolTipCtrl : public CGdToolTipCtrl
{
  DECLARE_MESSAGE_MAP()
public:
  GdWthToolTip* GetWthToolTip();
protected:
  GdToolTip * CreateGdToolTipInstance() override;
};

void GCAD_PORT GdUiHideBalloonTip(CWnd *control);
BOOL GCAD_PORT GdUiShowBalloonTip(
  CWnd *owner, CWnd *control, LPCTSTR text, BOOL beep
);
BOOL GCAD_PORT GdUiShowBalloonTip(
  CWnd *owner, CWnd *control, CRect& rect, LPCTSTR text, BOOL beep
);

#endif 

#pragma pack (pop)
#endif
