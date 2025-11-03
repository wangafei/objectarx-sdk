/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCUINAVDIALOG_H_
#define GCUINAVDIALOG_H_
#include "gNav.h"

class CGcUiNavPreviewButton;

typedef enum
{
  gcUiOpenNoTemplateNone = 0x0000,
  gcUiOpenNoTemplateImperail = 0x0001,
  gcUiOpenNoTemplateMetric = 0x0002
} GcUiOpenNoTemplateFlag;

class GCAD_PORT CGcUiNavDialog : public CNavDialog {
  DECLARE_DYNAMIC(CGcUiNavDialog)
public:
  CGcUiNavDialog(
    CNavDataArray& dataArray,
    CNavFilterArray& filterArray,
    UINT idd = 0,
    CWnd *pParent = NULL,
    HINSTANCE hDialogResource = NULL
  );
  ~CGcUiNavDialog();

  BOOL OnInitDialog() override;
  BOOL GetRecentDirectory(CString& strRecent) override;
  BOOL FindInSearchPath(LPCTSTR sBase, CString* pFullPath) override;
  void GetDefaultBrowserStartURL(CString& strStartPage) override;
  BOOL LaunchBrowserDialog(CString& strSelectedURL, LPCTSTR strDialogCaption,
    LPCTSTR strOk, LPCTSTR strStartPage) override;
  void DisplaySearchError(LPCTSTR sBase) override;
  void OnDoLocate() override;
  BOOL GetProductName(CString& strProduct) override;
  BOOL BeginDownloadFiles(CStringArray& strURLs, CDWordArray& dwActionCodes) override;
  DWORD GetDownloadActionCodes(CString& strURL) override;
  virtual void OnPaintPreview(LPCTSTR strFullPath, CWnd* previewWnd);
  void OnDialogHelp() override;
  void OnDialogHelp(LPCTSTR pTag) override;
  BOOL GetPreviewPresent();
  void SetPreviewPresent(BOOL preview);
  BOOL GetPreviewVisible();
  void SetPreviewVisible(BOOL visible);
  BOOL GetInitialViewButtonChecked();
  void ConvertFlagsToState(int nFlags);
  GcUiOpenNoTemplateFlag GetOpenNoTemplateSelection();
  short GetUpdateThumbnailOverride();
  void SetUseRememberFolders(bool bUseRememberFolders);
  bool GetUseRememberFolders() const;

public:
  void EnableFloatingWindows(BOOL allow) override;
  int IsMultiDocumentActivationEnabled() override;
  int EnableMultiDocumentActivation(BOOL bEnable) override;

protected:
  void OnFolderItemChange() override;
  void OnFilterChange() override;
  BOOL OnFileNameOK() override;
  void OnFileNameChange() override;
  void PrepareOkMenu(CMenu* pMenu) override;
  void PrepareViewsMenu(CMenu* pMenu) override;
  void PrepareToolsMenu(CMenu* pMenu) override;
  void OnURLDownloadSuccess(CString& strURL) override;
  virtual BOOL GetOptionsState();
  void OnCancel() override;
  void OnOK() override;
  void Do3DDwfOptionsDialog();
  void InitPreviewState();

protected:
  afx_msg void OnOpenNoTemplateImperial();
  afx_msg void OnOpenNoTemplateMetric();
  afx_msg void OnOpenMenuPartialOpen();
  afx_msg void OnOpenMenuPartialOpenReadOnly();
  afx_msg void OnViewsMenuPreview();
  afx_msg void OnToolsMenuOptions();
  afx_msg void OnToolsMenuSecurity();
  afx_msg void OnDestroy();
  afx_msg void OnUpdateThumbnailCheck();
  afx_msg void OnOnlineOptions();
  afx_msg void OnShowReferenceFiles();
  DECLARE_MESSAGE_MAP()

private:
  short m_CmdInProgress;
  short m_nUpdateThumbnailOverride;
  BOOL m_bIsOpen;
  BOOL m_bIsSaveAs;
  BOOL m_bIsRecover;
  BOOL m_bPartialOpenAlwaysDisabled;
  BOOL m_bInitialViewButtonPresent;
  BOOL m_bInitialViewButtonChecked;
  BOOL m_bPartialOpenPresent;
  BOOL m_bOptionsPresent;
  BOOL m_bPreviewPresent;
  BOOL m_bPreviewVisible;
  BOOL m_bOpenNoTemplate;
  GcUiOpenNoTemplateFlag m_nOpenNoTemplateSelection;
  CGcUiNavPreviewButton* m_previewButton;
  BOOL m_bIsExport;
  BOOL CanPartiallyOpen(LPCTSTR szfullPath);
  bool ApplyRememberFoldersInitialization(int rememberFolders);
  bool ApplyRememberFoldersOnOk();
  bool m_bUseRememberFolders;
  void HideControls();
  void UpdateInitialFolder();
  int  CheckSharedFilePrivileges(const CString & filename);

  static BOOL m_bOriginalMultiSelAllowed;
  BOOL m_bOpenSample;

};
#endif 