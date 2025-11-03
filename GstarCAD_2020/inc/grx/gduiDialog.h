#ifndef _GduiDialog_h
#define _GduiDialog_h

#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////

class GDUI_PORT CGdUiDialog : public CGdUiBaseDialog
{
	DECLARE_DYNAMIC(CGdUiDialog);

public:
	CGdUiDialog (UINT idd, CWnd *pParent=NULL, HINSTANCE hDialogResource=NULL);
	virtual ~CGdUiDialog ();

	// Misc.
protected:
	virtual void    OnInitDialogBegin ();
	virtual void    OnInitDialogFinish ();

	// Elasticity
private:
	LPVOID  m_pElastic;
  CString m_dlgName;
	CString m_dlgHelpTag;       // The help string tag for this dialog.

protected:
	BOOL    m_bEnableElasticMessageMap; // INTERNAL USE ONLY
	UINT    m_templateid;               // INTERNAL USE ONLY

public:
	BOOL    AddControl (CWnd *pControl);
	BOOL    AutoLoadControl (CWnd *pControl);
	BOOL    ForceControlRepaint (CWnd *pControl, BOOL bForce);
	BOOL    ForceControlResize (CWnd *pControl, LPRECT prect);
	BOOL    GetColumnSizes (CListCtrl *pList);
	CSize   *GetCurrentDelta ();
	BOOL    GetDialogData (LPCTSTR valueName, CString& data);
	BOOL    GetDialogData (LPCTSTR valueName, DWORD& data);
	BOOL    GetDialogKey (CString& key);
	BOOL    GetDialogName (CString& name);
	void    GetDialogHelpTag (CString& tag);        
	void    GetElasticMinMaxInfo (MINMAXINFO& mmi);
	LPVOID  GetElasticPointer ();
	BOOL    GetPixelData (CRect& r);
	void    LockDialogHeight ();
	void    LockDialogWidth ();
	BOOL    MoveControlX (UINT id, LONG lMovePct);
	BOOL    MoveControlXY (UINT id, LONG lMoveXPct, LONG lMoveYPct);
	BOOL    MoveControlY (UINT id, LONG lMovePct);
	BOOL    ReloadControl (CWnd *pControl, LPCTSTR lpResString);
	BOOL    RemoveControl (CWnd *pControl);
	BOOL    SaveColumnSizes (CListCtrl *pList);
	BOOL    SetControlProperty (PDLGCTLINFO lp, DWORD numElements);
	BOOL    SetDialogData (LPCTSTR valueName, LPCTSTR data);
	BOOL    SetDialogData (LPCTSTR valueName, DWORD data);
	void    SetDialogMaxExtents (int width, int height);
	void    SetDialogMinExtents (int width, int height);
	void    SetDialogName (LPCTSTR name);
	void    SetDialogHelpTag (LPCTSTR tag);        
	void    SetElasticSize (CSize& size, BOOL bRefreshDialog);
	void    SetPersistency (BOOL bFlag);
	void    SetRootKey (LPCTSTR key);
	void    SetTabSize (LPARAM lParam, BOOL bRefreshDialog);
	BOOL    StorePixelData ();
	BOOL    StretchControlX (UINT id, LONG lStretchPct);
	BOOL    StretchControlXY (UINT id, LONG lStretchXPct, LONG lStretchYPct);
	BOOL    StretchControlY (UINT id, LONG lStretchPct);

	// ClassWizard-controlled
public:
	//{{AFX_DATA(CGdUiDialog)
	enum { IDD = 0 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CGdUiDialog)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

public:
	virtual void OnDialogHelp();    // Override this to provide dialog help.
	virtual BOOL DoDialogHelp();                        // INTERNAL USE ONLY
  virtual BOOL OnInitDialog();

protected:
	//{{AFX_MSG(CGdUiDialog)
  afx_msg LRESULT HandleInitDialog(WPARAM, LPARAM);       // INTERNAL USE ONLY
  afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);    // INTERNAL USE ONLY
 	afx_msg void OnSize(UINT nType, int cx, int cy);        // INTERNAL USE ONLY
  afx_msg void OnDestroy();                               // INTERNAL USE ONLY
  virtual void OnOK();                                    // INTERNAL USE ONLY
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

/////////////////////////////////////////////////////////////////////////////
