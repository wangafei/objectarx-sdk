#ifndef GCUIDLGWORKSHEET_H
#define GCUIDLGWORKSHEET_H

#include "gduiDIalogWorksheet.h"

class GCUI_PORT CGcUiDialogWorksheet : public CGdUiDialogWorksheet
{
    DECLARE_DYNAMIC(CGcUiDialogWorksheet);
    
public:
		CGcUiDialogWorksheet(UINT ID, CWnd* pParent = NULL, HINSTANCE hResInst=NULL);
		~CGcUiDialogWorksheet();

	//{{AFX_DATA(CGcUiDialogWorksheet)
	enum { IDD = 0 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CGcUiDialogWorksheet)
protected:
	virtual void	DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGcUiDialogWorksheet)
	virtual BOOL	OnInitDialog();
	afx_msg void	OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void	OnPaint();
	afx_msg void	OnNcPaint();
	afx_msg BOOL	OnNcActivate(BOOL bActive);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void	OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH	OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL	OnEraseBkgnd(CDC *pDC);
	afx_msg void	OnNcLButtonDown( UINT nHitTest, CPoint point );
	afx_msg void	OnNcLButtonUp( UINT nHitTest, CPoint point );
	afx_msg void	OnNcMouseMove(UINT nHitTest,CPoint point);
	afx_msg void	OnMouseMove(UINT nHitTest,CPoint point);
	afx_msg void	OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg LRESULT	OnNcHitTest(CPoint pt);
	afx_msg void	OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void	OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void	OnSysColorChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif /* GCUIDLGWORKSHEET_H */