/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gcuiDialog_h
#define _gcuiDialog_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 


class GCAD_PORT CGcUiDialog : public CGdUiDialog {
  DECLARE_DYNAMIC(CGcUiDialog);

public:
  CGcUiDialog(
    UINT idd,
    CWnd *pParent = NULL,
    HINSTANCE hDialogResource = NULL
  );
  ~CGcUiDialog();

protected:
  BOOL    FindContextHelpFullPath(LPCTSTR fileName, CString& fullPath) override;

public:
  CWnd    *AppMainWindow() override;
  HINSTANCE AppResourceInstance() override;
  LPCTSTR AppRootKey() override;
  void    EnableFloatingWindows(BOOL allow) override;
  int IsMultiDocumentActivationEnabled() override;
  int EnableMultiDocumentActivation(BOOL bEnable) override;
  void    OnDialogHelp() override;
  BOOL    OnInitDialog() override;

public:
  enum { IDD = 0 };

protected:
  void OnOK() override;
  void OnCancel() override;
  void DoDataExchange(CDataExchange* pDX) override;

protected:
  DECLARE_MESSAGE_MAP()
};


class GCAD_PORT CGcUiDialogBar : public CGdUiDialogBar {
  DECLARE_DYNAMIC(CGcUiDialogBar);
public:
  CGcUiDialogBar();
  ~CGcUiDialogBar();

public:
  CWnd    *AppMainWindow() override;
  HINSTANCE AppResourceInstance() override;
  LPCTSTR AppRootKey() override;

public:
  enum { IDD = 0 };

protected:
  void DoDataExchange(CDataExchange* pDX) override;

protected:
  DECLARE_MESSAGE_MAP()
};


class GCAD_PORT CGcUiFileDialog : public CGdUiFileDialog {
  DECLARE_DYNAMIC(CGcUiFileDialog);

public:
  CGcUiFileDialog(
    BOOL bOpenFileDialog,
    LPCTSTR lpszDefExt = NULL,
    LPCTSTR lpszFileName = NULL,
    DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
    LPCTSTR lpszFilter = NULL,
    CWnd *pParentWnd = NULL
  );
  ~CGcUiFileDialog();

public:
  CWnd    *AppMainWindow() override;
  HINSTANCE AppResourceInstance() override;
  LPCTSTR AppRootKey() override;
  void    EnableFloatingWindows(BOOL allow) override;
  void    OnDialogHelp() override;
public:
  enum { IDD = 0 };

protected:
  void OnOK() override;
  void OnCancel() override;
  void DoDataExchange(CDataExchange* pDX) override;

protected:
  DECLARE_MESSAGE_MAP()
};


class GCAD_PORT CGcUiTabChildDialog : public CGdUiTabChildDialog {
  DECLARE_DYNAMIC(CGcUiTabChildDialog);

public:
  CGcUiTabChildDialog(
    CWnd *pParent = NULL,
    HINSTANCE hDialogResource = NULL
  );
  ~CGcUiTabChildDialog();

public:
  CWnd    *AppMainWindow() override;
  HINSTANCE AppResourceInstance() override;
  LPCTSTR AppRootKey() override;
  void    EnableFloatingWindows(BOOL allow) override;
  BOOL OnMainDialogHelp() override;
  void    OnDialogHelp() override;

public:
  enum { IDD = 0 };

protected:
  void DoDataExchange(CDataExchange* pDX) override;

protected:
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGcUiTabMainDialog : public CGdUiTabMainDialog {
  DECLARE_DYNAMIC(CGcUiTabMainDialog);
public:
  CGcUiTabMainDialog(
    UINT idd,
    CWnd *pParent = NULL,
    HINSTANCE hDialogResource = NULL
  );
  ~CGcUiTabMainDialog();

public:
  CWnd    *AppMainWindow() override;
  HINSTANCE AppResourceInstance() override;
  LPCTSTR AppRootKey() override;
  void    EnableFloatingWindows(BOOL allow) override;
  void    OnDialogHelp() override;
  int IsMultiDocumentActivationEnabled() override;
  int EnableMultiDocumentActivation(BOOL bEnable) override;

public:
  BOOL    AddApplicationTabs(LPCTSTR pszAppName) override;

public:
  enum { IDD = 0 };

protected:
  void OnOK() override;
  void OnCancel() override;
  void DoDataExchange(CDataExchange* pDX) override;

protected:
  DECLARE_MESSAGE_MAP()
};

#pragma pack (pop)
#endif
