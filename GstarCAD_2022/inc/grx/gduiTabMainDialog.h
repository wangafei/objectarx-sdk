#ifndef _GduiTabMainDialog_h
#define _GduiTabMainDialog_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//#include "gdui.h"

/////////////////////////////////////////////////////////////////////////////

class GDUI_PORT CGdUiTabMainDialog : public CGdUiDialog {
friend class CGdUiTab;

    DECLARE_DYNAMIC(CGdUiTabMainDialog);

public:
  	            CGdUiTabMainDialog (
                    UINT idd,
                    CWnd *pParent=NULL,
                    HINSTANCE hDialogResource=NULL
                );

// Tab Dialog
private:
        // This member variable holds the ID of the button which is meant
        // to be the default button in cases where no other button needs to
        // be the default button, that is, it holds the default "default button".
        int m_idDefaultButton;

        CGdUiTab *m_pGcadTab;

        // The initial tab index as a string. Empty if not set.
        CString m_strTabIndex;

        BOOL    TranslateTabKey ();
protected:
        void    SetGcadTabPointer (CGdUiTab *pGcadTab);

public:
        // A tab extensible dialog calls this to add extended tabs.
        int     AddExtendedTabs ();    

        // Function to provide outside access to the default "default button".
        int     GetDefaultButton ();

        CGdUiTab *GetTabControl ();

        // Function to specify the default "default button".  This MUST be set
        // by the derived class, probably in its dialog initialization function.
        void    SetDefaultButton (int nIdDefaultButton);

        // Function to make sure the correct button is made the default button.
        void    UpdateDefaultButton (HWND hFocusBefore, HWND hFocusAfter);

        void    SetInitialTabIndex(LPCTSTR strTabIndex) {m_strTabIndex = strTabIndex;}
        LPCTSTR GetInitialTabIndex() {return m_strTabIndex;}
        int     GetInitialRequestedTabIndex();
        
// Elasticity
protected:
virtual void    OnInitDialogBegin ();
virtual BOOL    OnInitDialog();
 virtual void    OnInitDialogFinish ();

// Tab Extensions
protected:
        CGdUiTabExtensionManager m_xtabManager;

public:
 virtual BOOL    AddApplicationTabs (LPCTSTR pszAppName);
        CGdUiTabExtensionManager *GetXtabPointer ();

// Tab Removal and Restoration
public:
        BOOL    AddTab (
                    int iPos, LPCTSTR tabName,
                    UINT uTemplateID, CGdUiTabChildDialog *pDialog
                );
        BOOL    AddTab (
                    int iPos, UINT uTabStringID,
                    UINT uTemplateID, CGdUiTabChildDialog *pDialog
                );
        int     GetTabIndex (CGdUiTabChildDialog *pDialog);
        BOOL    RemoveTab (int iPos);

// ClassWizard-controlled
public:
	//{{AFX_DATA(CGdUiTabMainDialog)
	enum { IDD = 0 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CGdUiTabMainDialog)
public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);        // INTERNAL USE ONLY
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual void OnCancel();
     virtual void OnOK();

     void RaiseApplyEvent();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGdUiTabMainDialog)
    afx_msg void OnSize(UINT nType, int cx, int cy);    // INTERNAL USE ONLY
	//}}AFX_MSG

    DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

//////////////////////////////////////////////////////////////////////////////
