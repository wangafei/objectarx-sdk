#pragma once


// CDlgPalette dialog
#include "resource.h"

class CDlgPalette : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgPalette)

public:
	CDlgPalette(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPalette();

// Dialog Data
	enum { IDD = IDD_DIALOG_PALETTE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  afx_msg LRESULT OnACADKeepFocus(WPARAM wParam, LPARAM lParam);
  afx_msg void OnBnClickedButtonCheck();
  afx_msg void OnEnChangeEdit1();
};
