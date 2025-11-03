#ifndef _GcuiDialog_h
#define _GcuiDialog_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class GCUI_PORT CGcUiDialog : public CGdUiDialog {
    DECLARE_DYNAMIC(CGcUiDialog);

public:
                CGcUiDialog ( UINT idd, CWnd *pParent=NULL, HINSTANCE hDialogResource=NULL );
virtual         ~CGcUiDialog ();

virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();
virtual void    EnableFloatingWindows (BOOL allow);
virtual int		IsMultiDocumentActivationEnabled();
virtual int		EnableMultiDocumentActivation(BOOL bEnable);
virtual void    OnDialogHelp();     

protected:
virtual BOOL    FindContextHelpFullPath (LPCTSTR fileName, CString& fullPath);

public:
virtual BOOL    OnInitDialog();
public:
    //{{AFX_DATA(CGcUiDialog)
    enum { IDD = 0 };
    //}}AFX_DATA

    //{{AFX_VIRTUAL(CGcUiDialog)
protected:
virtual void OnOK();
virtual void OnCancel();
virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CGcUiDialog)
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

class GCUI_PORT CGcUiDialogBar : public CGdUiDialogBar {
    DECLARE_DYNAMIC(CGcUiDialogBar);

public:
                CGcUiDialogBar ();
virtual         ~CGcUiDialogBar ();

virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();

public:
    //{{AFX_DATA(CGcUiDialogBar)
    enum { IDD = 0 };
    //}}AFX_DATA

    //{{AFX_VIRTUAL(CGcUiDialogBar)
protected:
virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CGcUiDialogBar)
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


class GCUI_PORT CGcUiFileDialog : public CGdUiFileDialog {
    DECLARE_DYNAMIC(CGcUiFileDialog);

public:
                CGcUiFileDialog (
                    BOOL bOpenFileDialog,
                    LPCTSTR lpszDefExt=NULL,
                    LPCTSTR lpszFileName=NULL,
                    DWORD dwFlags=OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
                    LPCTSTR lpszFilter=NULL,
                    CWnd *pParentWnd=NULL
                );
virtual         ~CGcUiFileDialog ();

virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();
virtual void    EnableFloatingWindows (BOOL allow);
virtual void    OnDialogHelp(); 
public:
    //{{AFX_DATA(CGcUiFileDialog)
    enum { IDD = 0 };
    //}}AFX_DATA

    //{{AFX_VIRTUAL(CGcUiFileDialog)
protected:
virtual void OnOK();
virtual void OnCancel();
virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CGcUiFileDialog)
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


class GCUI_PORT CGcUiTabChildDialog : public CGdUiTabChildDialog {
    DECLARE_DYNAMIC(CGcUiTabChildDialog);

public:
                CGcUiTabChildDialog ( CWnd *pParent=NULL, HINSTANCE hDialogResource=NULL );
virtual         ~CGcUiTabChildDialog ();

virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();
virtual void    EnableFloatingWindows (BOOL allow);
virtual BOOL	OnMainDialogHelp();
virtual void    OnDialogHelp();

public:
    //{{AFX_DATA(CGcUiTabChildDialog)
    enum { IDD = 0 };
    //}}AFX_DATA

    //{{AFX_VIRTUAL(CGcUiTabChildDialog)
protected:
virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CGcUiTabChildDialog)
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

class GCUI_PORT CGcUiTabMainDialog : public CGdUiTabMainDialog {
    DECLARE_DYNAMIC(CGcUiTabMainDialog);

public:
  	            CGcUiTabMainDialog (UINT idd, CWnd *pParent=NULL, HINSTANCE hDialogResource=NULL );
virtual         ~CGcUiTabMainDialog ();

virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();
virtual void    EnableFloatingWindows (BOOL allow);
virtual void    OnDialogHelp();
virtual int		IsMultiDocumentActivationEnabled();
virtual int		EnableMultiDocumentActivation(BOOL bEnable);

virtual BOOL    AddApplicationTabs (LPCTSTR pszAppName);

public:
	//{{AFX_DATA(CGcUiTabMainDialog)
	enum { IDD = 0 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CGcUiTabMainDialog)
protected:
virtual void OnOK();
virtual void OnCancel();
virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGcUiTabMainDialog)
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

#pragma pack (pop)
#endif