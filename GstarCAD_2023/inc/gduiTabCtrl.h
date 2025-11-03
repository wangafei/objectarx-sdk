/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiTabCtrl_h
#define _gduiTabCtrl_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 

#ifndef _GSOFT_MAC_

#pragma warning(push)
#pragma warning(disable : 4275)
class GCAD_PORT CGdUiTab : public CTabCtrl {
  friend class CGdUiTabMainDialog;
  friend class CGdUiTabChildDialog;

  DECLARE_DYNAMIC(CGdUiTab);

public:
  CGdUiTab();
  ~CGdUiTab();

private:
  BOOL    m_bDirty;
  HWND    m_hwndFocus;
  int     m_iActiveTab;
  UINT    m_uApplyButtonID;

  BOOL    BringTabToFront(int iPos);
  void    PositionTabDialog(CGdUiTabChildDialog *pDialog);
public:
  BOOL    AddTab(
    int iPos, CString const& sTabname,
    UINT uTemplateID, CGdUiTabChildDialog *pDialog
  );
  BOOL    AddTab(
    int iPos, UINT uTabStringID,
    UINT uTemplateID, CGdUiTabChildDialog *pDialog
  );

  BOOL    DeleteItem(int iPos);
  BOOL    DestroyTab(int iPos, BOOL bUpdateData = FALSE);
  int     GetActiveTab();
  CGdUiTabMainDialog *GetMainDialog();
  int     GetTabIndex(CGdUiTabChildDialog *pDialog);
  CGdUiTabChildDialog *GetDialogPointer(int iPos);
  BOOL    IsDirty();
  BOOL    RemoveTab(int iPos);
  int     SetActiveTab(int iPos);
  void    SetApplyButtonID(UINT uID);
  void    SetChildFocus();
  void    SetDirty(BOOL bDirty = TRUE);
  void    SetValidationInfo(CDataExchange* pDX);

public:
  BOOL    DisplayData();
  BOOL    ExchangeData(BOOL bSaveAndValidate);
  BOOL    ValidateData();

protected:
  void PreSubclassWindow() override;

protected:
  afx_msg BOOL OnSelChange(NMHDR* pNMHDR, LRESULT* pResult);
  afx_msg BOOL OnSelChanging(NMHDR* pNMHDR, LRESULT* pResult);

  DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)

#endif 

#pragma pack (pop)
#endif
