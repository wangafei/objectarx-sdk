/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiFileDialog_h
#define _gduiFileDialog_h
#pragma pack (push, 8)

#pragma once

#ifndef kDialogOptionNone
#define kDialogOptionNone       0
#endif

#ifndef kDialogOptionUseTips
#define kDialogOptionUseTips       1
#endif

#ifndef kDialogOptionUseTipsForContextHelp
#define kDialogOptionUseTipsForContextHelp       2
#endif

#ifndef _GSOFT_MAC_

#pragma warning(push)
#pragma warning(disable : 4275)

class GCAD_PORT CGdUiFileDialog : public CFileDialog {
  DECLARE_DYNAMIC(CGdUiFileDialog);

public:
  CGdUiFileDialog(
    BOOL bOpenFileDialog,
    LPCTSTR lpszDefExt = NULL,
    LPCTSTR lpszFileName = NULL,
    DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
    LPCTSTR lpszFilter = NULL,
    CWnd *pParentWnd = NULL,
    HINSTANCE hDialogResource = NULL
  );
  ~CGdUiFileDialog();

protected:
  virtual GDUI_REPLY DoGdUiMessage(
    GDUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam
  );
  virtual GDUI_REPLY OnNotifyControlChange(UINT controlId, LPARAM lParam);
  virtual GDUI_REPLY OnNotifyControlValid(UINT controlId, BOOL isValid);
  virtual GDUI_REPLY OnNotifyGeneric(UINT controlId, LPARAM lParam);
  virtual GDUI_REPLY OnNotifyUpdateTip(CWnd *control);

private:
  HINSTANCE m_commandResourceInstance;
  BOOL    m_commandWindowWasEnabled;
  HWND    m_commandWindowWithFocus;

protected:
  GDUI_COMMAND_STATE m_commandState;

  void    BeginEditorCommand();
  void    CancelEditorCommand();
  void    CompleteEditorCommand(BOOL restoreDialogs = TRUE);
  void    MakeDialogsVisible(BOOL visible);
public:
  BOOL    EditorCommandCancelled();

protected:
  CString m_contextHelpFileName;
  CString m_contextHelpFullPathName;
  CString m_contextHelpPrefix;

  virtual BOOL    FindContextHelpFullPath(LPCTSTR fileName, CString& fullPath);
public:
  LPCTSTR GetContextHelpFileName();
  void    SetContextHelpFileName(LPCTSTR pFileName);
  LPCTSTR GetContextHelpFullPathName();
  void    SetContextHelpFullPathName(LPCTSTR pFullPathName);
  LPCTSTR GetContextHelpPrefix();
  void    SetContextHelpPrefix(LPCTSTR pPrefix);
  void    SetDialogName(LPCTSTR name);
  void    SetDialogHelpTag(LPCTSTR tag) { m_dlgHelpTag = tag; }
  void    GetDialogName(CString& name) { name = m_dlgName; }
  void    GetDialogHelpTag(CString& tag) { tag = m_dlgHelpTag; }

private:
  HINSTANCE m_hDialogResourceSaved;
  CString m_dlgHelpTag;
  CString m_dlgName;
  CImageList *m_pNavButtonImageList;

protected:
  int    m_bUseTips;
  HINSTANCE m_hDialogResource;
  HICON   m_hIcon;
  CGdUiTextTip *m_pTextTip;
  CToolTipCtrl *m_pToolTip;
  CString m_rootKey;
  CWnd* m_pParent;

  virtual void    OnInitDialogBegin();
  virtual void    OnInitDialogFinish();
public:
  virtual CWnd    *AppMainWindow();
  virtual HINSTANCE AppResourceInstance();
  virtual LPCTSTR AppRootKey();
  virtual void    EnableFloatingWindows(BOOL allow);
  int    GetUseTips();
  void    SetUseTips(int useTips);
  HICON   GetDialogIcon();
  void    SetDialogIcon(HICON hIcon);
  virtual void OnDialogHelp();
  virtual BOOL DoDialogHelp();
  void AutoHiDPIScaleNavButtons();

public:
  enum { IDD = 0 };

public:
  BOOL PreTranslateMessage(MSG* pMsg) override;
  INT_PTR DoModal() override;
protected:
  void DoDataExchange(CDataExchange* pDX) override;
  void PostNcDestroy() override;
  BOOL PreCreateWindow(CREATESTRUCT& cs) override;

protected:
  BOOL OnInitDialog() override;
  afx_msg LRESULT OnGdUiMessage(WPARAM wParam, LPARAM lParam);
  afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
  afx_msg BOOL OnHelpInfo(HELPINFO* lpHelpInfo);
  afx_msg BOOL OnNotify_ToolTipText(UINT id, NMHDR *pNMHDR, LRESULT *pResult);
  DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)

#endif 

#pragma pack (pop)
#endif
