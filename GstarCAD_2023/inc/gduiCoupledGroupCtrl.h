/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiCoupledGroupCtrl_h
#define _gduiCoupledGroupCtrl_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 


#pragma warning(push)
#pragma warning(disable : 4275)

class CGdUiGroupCtrl;
class CGdUiTheme;

#define GDUI_DEFAULT_TREE_TO_DETAILS_RATIO  0.4

class GCAD_PORT CGdUiCoupledGroupCtrl : public CWnd {

  DECLARE_DYNAMIC(CGdUiCoupledGroupCtrl);

public:
  CGdUiCoupledGroupCtrl();
  ~CGdUiCoupledGroupCtrl();

public:
  virtual void AddCouple(CGdUiGroupCtrl * pGdUiTopWnd,
    CGdUiGroupCtrl * pGdUiBottomWnd);
  virtual void AddCouple(CWnd* pWndTop, CWnd* pWndBottom);
  virtual void AddCouple(CGdUiGroupCtrl* pGdUiTopWnd, CWnd* pWndBottom);
  virtual void AddCouple(CWnd* pWndTop, CGdUiGroupCtrl* pGdUiBottomWnd);
  virtual void MinMaxOneChild(CWnd* pWnd, bool bMinimized);
  double GetTopToWholeRatio() const { return m_topToWholeRatio; }
  void SetTopToWholeRatio(double topToWholeRatio);
  void SetSplitterEnabled(bool bSplitterEnabled) {
    m_bSplitterEnabled = bSplitterEnabled;
  }
  bool GetSplitterEnabled() {
    return m_bSplitterEnabled;
  }
  CGdUiTheme* GetTheme() const;
  void SetTheme(CGdUiTheme* pTheme);

protected:
  afx_msg void OnSize(UINT nType, int cx, int cy);
  afx_msg void OnPaint();
  afx_msg void OnMouseMove(UINT nFlags, CPoint);
  afx_msg void OnLButtonDown(UINT nFlags, CPoint);
  afx_msg void OnLButtonUp(UINT nFlags, CPoint);
  afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

  DECLARE_MESSAGE_MAP()

protected:
  void ResizeChildren(int cx, int cy);
  bool ValidateCtrls();
  bool IsAnyCtrlMinimizedOrIconic();

protected:
  COLORREF m_crNCBackground;
  COLORREF m_crSplitter;
  CBrush   m_bkBrush;

protected:
  CGdUiGroupCtrl* m_pGdUiTopWnd;
  CGdUiGroupCtrl* m_pGdUiBottomWnd;
  CWnd*           m_pTopWnd;
  CWnd*           m_pBottomWnd;
  double          m_topToWholeRatio;
  bool            m_bDragging;
  bool            m_bSplitterEnabled;
  CPoint          m_ptLast;
  CRect           m_rtSpace;
  CGdUiTheme*     m_pTheme;
};

#pragma warning(pop)

#pragma pack (pop)
#endif
