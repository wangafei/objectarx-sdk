#ifndef _GduiDialogBar_h
#define _GduiDialogBar_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//#include "gdui.h"

//////////////////////////////////////////////////////////////////////////////
// Dialog Bar
//
// Essentialy a straight port of CGdUiBaseDialog, except for the constructor.
//
// Note: This class is now obsolete and is slated for removal.
#pragma warning(push)
#pragma warning(disable : 4275)
class GDUI_PORT CGdUiDialogBar : public CDialogBar {
    DECLARE_DYNAMIC(CGdUiDialogBar);

public:
                CGdUiDialogBar ();
virtual         ~CGdUiDialogBar ();

// GdUi message handlers
protected:
virtual GDUI_REPLY DoGdUiMessage (
                    GDUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam
                );
virtual GDUI_REPLY OnNotifyControlChange (UINT controlId, LPARAM lParam);
virtual GDUI_REPLY OnNotifyControlValid (UINT controlId, BOOL isValid);
virtual GDUI_REPLY OnNotifyGeneric (UINT controlId, LPARAM lParam);
virtual GDUI_REPLY OnNotifyUpdateTip (CWnd *control);

// Misc.
protected:
        BOOL    m_bUseTips;
        CGdUiTextTip *m_pTextTip;
        CToolTipCtrl *m_pToolTip;
        CString m_rootKey;

public:
virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();
        BOOL    GetUseTips ();
        void    SetUseTips (BOOL useTips);

// ClassWizard-controlled
public:
    //{{AFX_DATA(CGdUiDialogBar)
    enum { IDD = 0 };
    //}}AFX_DATA

    //{{AFX_VIRTUAL(CGdUiDialogBar)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
 	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CGdUiDialogBar)
    afx_msg LRESULT OnGdUiMessage (WPARAM wParam, LPARAM lParam);
	afx_msg int OnCreate(LPCREATESTRUCT lpcs);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
    afx_msg BOOL OnNotify_ToolTipText(UINT id, NMHDR *pNMHDR, LRESULT *pResult);
    DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

/////////////////////////////////////////////////////////////////////////////
