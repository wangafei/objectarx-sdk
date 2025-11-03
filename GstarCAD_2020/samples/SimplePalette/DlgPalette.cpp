// DlgPalette.cpp : implementation file
//

#include "stdafx.h"
#include "DlgPalette.h"
#include "afxdialogex.h"


// CDlgPalette dialog

IMPLEMENT_DYNAMIC(CDlgPalette, CDialogEx)

CDlgPalette::CDlgPalette(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgPalette::IDD, pParent)
{

}

CDlgPalette::~CDlgPalette()
{
}

void CDlgPalette::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgPalette, CDialogEx)
  ON_MESSAGE(WM_ACAD_KEEPFOCUS, &CDlgPalette::OnACADKeepFocus)
  ON_BN_CLICKED(IDC_BUTTON_CHECK, &CDlgPalette::OnBnClickedButtonCheck)
  ON_EN_CHANGE(IDC_EDIT1, &CDlgPalette::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CDlgPalette message handlers
LRESULT CDlgPalette::OnACADKeepFocus(WPARAM wParam, LPARAM lParam)
{
  return 1L;
}

void CDlgPalette::OnBnClickedButtonCheck()
{
  // TODO: Add your control notification handler code here
}


void CDlgPalette::OnEnChangeEdit1()
{
  // TODO:  If this is a RICHEDIT control, the control will not
  // send this notification unless you override the CDialogEx::OnInitDialog()
  // function and call CRichEditCtrl().SetEventMask()
  // with the ENM_CHANGE flag ORed into the mask.

  // TODO:  Add your control notification handler code here
}
