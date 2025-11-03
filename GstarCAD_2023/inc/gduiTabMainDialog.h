/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiTabMainDialog_h
#define _gduiTabMainDialog_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 

#ifndef _GSOFT_MAC_

class GCAD_PORT CGdUiTabMainDialog : public CGdUiDialog {
  friend class CGdUiTab;

  DECLARE_DYNAMIC(CGdUiTabMainDialog);

public:
  CGdUiTabMainDialog(
    UINT idd,
    CWnd *pParent = NULL,
    HINSTANCE hDialogResource = NULL
  );

private:
  int m_idDefaultButton;
  CGdUiTab *m_pGcadTab;
  CString m_strTabIndex;
  BOOL    TranslateTabKey();
protected:
  void    SetGcadTabPointer(CGdUiTab *pGcadTab);

public:
  int     AddExtendedTabs();
  int     GetDefaultButton();
  CGdUiTab *GetTabControl();
  void    SetDefaultButton(int nIdDefaultButton);
  void    UpdateDefaultButton(HWND hFocusBefore, HWND hFocusAfter);

  void    SetInitialTabIndex(LPCTSTR strTabIndex) { m_strTabIndex = strTabIndex; }
  LPCTSTR GetInitialTabIndex() { return m_strTabIndex; }

  int     GetInitialRequestedTabIndex();

protected:
  void    OnInitDialogBegin() override;
  void    OnInitDialogFinish() override;

protected:
  CGdUiTabExtensionManager m_xtabManager;

public:
  virtual BOOL    AddApplicationTabs(LPCTSTR pszAppName);
  CGdUiTabExtensionManager *GetXtabPointer();

public:
  BOOL    AddTab(
    int iPos, LPCTSTR tabName,
    UINT uTemplateID, CGdUiTabChildDialog *pDialog
  );
  BOOL    AddTab(
    int iPos, UINT uTabStringID,
    UINT uTemplateID, CGdUiTabChildDialog *pDialog
  );
  int     GetTabIndex(CGdUiTabChildDialog *pDialog);
  BOOL    RemoveTab(int iPos);

public:
  enum { IDD = 0 };

public:
  BOOL PreTranslateMessage(MSG* pMsg) override;
protected:
  void DoDataExchange(CDataExchange* pDX) override;
  void OnCancel() override;
  void OnOK() override;
  void RaiseApplyEvent();

protected:
  afx_msg void OnSize(UINT nType, int cx, int cy);

  DECLARE_MESSAGE_MAP()
};

#endif 

#pragma pack (pop)
#endif
