/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCUIDLGWORKSHEET_H
#define GCUIDLGWORKSHEET_H

#include "gduiDialogWorksheet.h"

class GCAD_PORT CGcUiDialogWorksheet : public CGdUiDialogWorksheet
{
  DECLARE_DYNAMIC(CGcUiDialogWorksheet);

public:
  CGcUiDialogWorksheet(UINT ID, CWnd* pParent = NULL, HINSTANCE hResInst = NULL);
  ~CGcUiDialogWorksheet();

  enum { IDD = 0 };

protected:
  void DoDataExchange(CDataExchange* pDX) override;

protected:
  BOOL OnInitDialog() override;
  afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
  afx_msg void OnPaint();
  afx_msg void OnNcPaint();
  afx_msg BOOL OnNcActivate(BOOL bActive);
  afx_msg HCURSOR OnQueryDragIcon();
  afx_msg void OnSize(UINT nType, int cx, int cy);
  afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
  afx_msg BOOL OnEraseBkgnd(CDC *pDC);
  afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
  afx_msg void OnNcLButtonUp(UINT nHitTest, CPoint point);
  afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
  afx_msg void OnMouseMove(UINT nHitTest, CPoint point);
  afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
#if _MSC_VER<1400
  afx_msg UINT OnNcHitTest(CPoint point);
#else
  afx_msg LRESULT OnNcHitTest(CPoint point);
#endif
  afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
  afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
  afx_msg void OnSysColorChange();
  DECLARE_MESSAGE_MAP()
};

#endif 