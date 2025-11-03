/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiTabExtension_h
#define _gduiTabExtension_h
#pragma pack (push, 8)


class GCAD_PORT CGdUiTabExtensionManager {
public:
  CGdUiTabExtensionManager();
  virtual         ~CGdUiTabExtensionManager();

private:
  CString m_dlgName;
  CGdUiTabMainDialog *m_pDlg;
  CGdUiTab *m_pTabCtrl;

  BOOL    AddApplicationTabs(LPCTSTR pszAppName);
public:
  int     AddExtendedTabs();

  virtual BOOL    AddTab(
    HINSTANCE hInstRes,
    UINT uTemplateID,
    LPCTSTR pszTabName,
    CGdUiTabChildDialog *pDialog
  );

  virtual LPCTSTR GetDialogName();
  void    Initialize(CGdUiTab *pTabCtrl, CGdUiTabMainDialog *pDlg);
  CGdUiTab* GetTabControl() const { return m_pTabCtrl; }
};

#pragma pack (pop)
#endif
