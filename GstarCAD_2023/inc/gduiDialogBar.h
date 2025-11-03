/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiDialogBar_h
#define _gduiDialogBar_h
#pragma pack (push, 8)

#pragma once

#ifndef _GSOFT_MAC_
#pragma warning(push)
#pragma warning(disable : 4275)
class GCAD_PORT CGdUiDialogBar : public CDialogBar {
  DECLARE_DYNAMIC(CGdUiDialogBar);

public:
  CGdUiDialogBar();
  ~CGdUiDialogBar();

protected:
  virtual GDUI_REPLY DoGdUiMessage(
    GDUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam
  );
  virtual GDUI_REPLY OnNotifyControlChange(UINT controlId, LPARAM lParam);
  virtual GDUI_REPLY OnNotifyControlValid(UINT controlId, BOOL isValid);
  virtual GDUI_REPLY OnNotifyGeneric(UINT controlId, LPARAM lParam);
  virtual GDUI_REPLY OnNotifyUpdateTip(CWnd *control);

protected:
  BOOL    m_bUseTips;
  CGdUiTextTip *m_pTextTip;
  CToolTipCtrl *m_pToolTip;
  CString m_rootKey;

public:
  virtual CWnd    *AppMainWindow();
  virtual HINSTANCE AppResourceInstance();
  virtual LPCTSTR AppRootKey();
  BOOL    GetUseTips();
  void    SetUseTips(BOOL useTips);

public:
  enum { IDD = 0 };

public:
  BOOL PreTranslateMessage(MSG* pMsg) override;
protected:
  void DoDataExchange(CDataExchange* pDX) override;
  void PostNcDestroy() override;

protected:
  afx_msg LRESULT OnGdUiMessage(WPARAM wParam, LPARAM lParam);
  afx_msg int OnCreate(LPCREATESTRUCT lpcs);
  afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
  afx_msg BOOL OnNotify_ToolTipText(UINT id, NMHDR *pNMHDR, LRESULT *pResult);
  DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)

#endif 

#pragma pack (pop)
#endif
