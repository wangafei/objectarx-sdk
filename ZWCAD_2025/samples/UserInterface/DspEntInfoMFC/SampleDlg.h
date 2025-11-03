#pragma once
#include "pch.h"
#include "framework.h"
#include <dbsymtb.h>
#include <dbapserv.h>
#include <adslib.h>
#include <adui.h>
#include <acui.h>

// SampleDlg Dialog

class SampleDlg : public CDialog
{
	DECLARE_DYNAMIC(SampleDlg)

public:
	SampleDlg(CWnd* pParent = nullptr);   // Standard Constructor
	virtual ~SampleDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV Support

	DECLARE_MESSAGE_MAP()
public:
	void AddToList(CString field, CString value);
	void AddSeperatorLine(CString field);
	void Display(AcDbObject* pObj);
	void Display(AcDbEntity* pObj);
	void Display(AcDbCurve* pObj);
	void Display(AcDbCircle* pObj);

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	CListCtrl m_listctl;
};
