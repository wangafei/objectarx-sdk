
#pragma once
#include "zacui_port.h"
#include "zaduiFileDialog.h"
#include "zaduiTabChildDialog.h"
#include "zaduiTabMainDialog.h"
#pragma pack (push, 8)

class ZCUI_PORT CZcUiDialog : public CZdUiDialog {
    DECLARE_DYNAMIC(CZcUiDialog);

public:
                CZcUiDialog (
                    UINT idd,
                    CWnd *pParent=NULL,
                    HINSTANCE hDialogResource=NULL
                );
virtual         ~CZcUiDialog ();

protected:
virtual BOOL    FindContextHelpFullPath (LPCTSTR fileName, CString& fullPath) override;

public:
virtual CWnd    *AppMainWindow () override;
virtual HINSTANCE AppResourceInstance () override;
virtual LPCTSTR AppRootKey () override;
virtual void    EnableFloatingWindows (BOOL allow) override;
virtual int IsMultiDocumentActivationEnabled() override;
virtual int EnableMultiDocumentActivation(BOOL bEnable) override;

virtual void    OnDialogHelp() override;     

	virtual BOOL    OnInitDialog() override;

public:

    enum { IDD = 0 };

    protected:
    virtual void OnOK() override;
	virtual void OnCancel() override;
    virtual void DoDataExchange(CDataExchange* pDX) override;

protected:

    DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiFileDialog : public CZdUiFileDialog {
    DECLARE_DYNAMIC(CZcUiFileDialog);

public:
                CZcUiFileDialog (
                    BOOL bOpenFileDialog,
                    LPCTSTR lpszDefExt=NULL,
                    LPCTSTR lpszFileName=NULL,
                    DWORD dwFlags=OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
                    LPCTSTR lpszFilter=NULL,
                    CWnd *pParentWnd=NULL
                );
virtual         ~CZcUiFileDialog ();

public:
virtual CWnd    *AppMainWindow () override;
virtual HINSTANCE AppResourceInstance () override;
virtual LPCTSTR AppRootKey () override;
virtual void    EnableFloatingWindows (BOOL allow) override;
virtual void    OnDialogHelp() override; 

public:

    enum { IDD = 0 };

    protected:
    virtual void OnOK() override;
	virtual void OnCancel() override;
    virtual void DoDataExchange(CDataExchange* pDX) override;

protected:

    DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiTabChildDialog : public CZdUiTabChildDialog {
    DECLARE_DYNAMIC(CZcUiTabChildDialog);

public:
                CZcUiTabChildDialog (
                    CWnd *pParent=NULL,
                    HINSTANCE hDialogResource=NULL
                );
virtual         ~CZcUiTabChildDialog ();

public:
virtual CWnd    *AppMainWindow () override;
virtual HINSTANCE AppResourceInstance () override;
virtual LPCTSTR AppRootKey () override;
virtual void    EnableFloatingWindows (BOOL allow) override;
virtual BOOL OnMainDialogHelp() override;
virtual void    OnDialogHelp() override;

public:

    enum { IDD = 0 };

    protected:
    virtual void DoDataExchange(CDataExchange* pDX) override;

protected:

    DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiTabMainDialog : public CZdUiTabMainDialog {
    DECLARE_DYNAMIC(CZcUiTabMainDialog);

public:
                  CZcUiTabMainDialog (
                    UINT idd,
                    CWnd *pParent=NULL,
                    HINSTANCE hDialogResource=NULL
                );
virtual         ~CZcUiTabMainDialog ();

public:
virtual CWnd    *AppMainWindow () override;
virtual HINSTANCE AppResourceInstance () override;
virtual LPCTSTR AppRootKey () override;
virtual void    EnableFloatingWindows (BOOL allow) override;
virtual void    OnDialogHelp() override;
virtual int IsMultiDocumentActivationEnabled() override;
virtual int EnableMultiDocumentActivation(BOOL bEnable) override;

public:
virtual BOOL    AddApplicationTabs (LPCTSTR pszAppName) override;

public:

    enum { IDD = 0 };

    protected:
    virtual void OnOK() override;
	virtual void OnCancel() override;
	virtual void DoDataExchange(CDataExchange* pDX) override;

protected:

    DECLARE_MESSAGE_MAP()
};

#pragma pack (pop)


