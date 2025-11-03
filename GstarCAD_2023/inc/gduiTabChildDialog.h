/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiTabChildDialog_h
#define _gduiTabChildDialog_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 

#ifndef _GSOFT_MAC_

class GCAD_PORT CGdUiTabChildDialog : public CGdUiDialog {
  friend class CGdUiTab;
  DECLARE_DYNAMIC(CGdUiTabChildDialog);
public:
  CGdUiTabChildDialog(
    CWnd *pParent = NULL,
    HINSTANCE hDialogResource = NULL
  );

private:
  BOOL    m_bDirty;
  HWND    m_hWndFocus;
  CGdUiTab *m_pGcadTab;

  void    SetGcadTabPointer(CGdUiTab *pGcadTab);
  BOOL    TranslateTabKey();
public:
  CGdUiTab *GetGcadTabPointer();
  CGdUiTabMainDialog *GetMainDialog();
  int     GetTabIndex();
  BOOL    IsDirty();
  virtual void    OnTabActivation(BOOL bActivate);
  virtual BOOL    OnTabChanging();
  void    SetGcadTabChildFocus(HWND hWndFocus);
  void    SetDirty(BOOL bDirty = TRUE);
  void    SetValidationInfo(CDataExchange *pDX);

protected:
  void    OnInitDialogBegin() override;
  void    OnInitDialogFinish() override;

public:
  enum { IDD = 0 };

public:
  BOOL PreTranslateMessage(MSG* pMsg) override;
  virtual void OnMainDialogCancel();
  virtual void OnMainDialogOK();
  virtual BOOL OnMainDialogHelp();
  virtual void OnMainDialogApply();
protected:
  void DoDataExchange(CDataExchange* pDX) override;
  void OnCancel() override;
  void OnOK() override;

protected:
  afx_msg void OnSize(UINT nType, int cx, int cy);
  afx_msg LRESULT OnResizePage(WPARAM wParam, LPARAM lParam);

  DECLARE_MESSAGE_MAP()
};

#endif 

#pragma pack (pop)
#endif
