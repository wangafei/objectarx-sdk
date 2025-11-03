/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gdui.h"
#include "GcFdUi.h"

class GcTcUiSystemInternals;
class CGcFdUiFieldDialog;
class CGcFdUiFieldDialogHook;
class CGcFdUiImpFieldDialog;
class GcDbField;

class GCFDUI_PORT CGcFdUiFieldOptionDialog : public CGdUiDialog
{
  friend CGcFdUiFieldDialog;
  friend CGcFdUiImpFieldDialog;

  DECLARE_DYNAMIC(CGcFdUiFieldOptionDialog)

public:
  CGcFdUiFieldOptionDialog(CGcFdUiFieldDialogHook* pDialogHook, CGcFdUiFieldDialog* pFieldDlg,
    UINT nIDTemplate, HINSTANCE hDialogResource = NULL);
  ~CGcFdUiFieldOptionDialog();

  CGcFdUiFieldDialogHook* GetFieldDialogHook(void) const;
  CGcFdUiFieldDialog* GetFieldDialog(void) const;
  virtual BOOL    Create(CWnd* pParent);

public:
  virtual BOOL    Create(LPCTSTR lpszTemplateName,
    CWnd* pParent = NULL);
  virtual BOOL    Create(UINT nIDTemplate,
    CWnd* pParent = NULL);

protected:
  virtual BOOL    OnSetActive(void);
  virtual BOOL    OnKillActive(void);
  virtual BOOL    OnFieldSelected(UINT uNewFieldId);

protected:
  void            OnOK() override;
  void            OnCancel() override;

protected:
  void DoDataExchange(CDataExchange* pDX) override;
  afx_msg LRESULT OnFormatChanged(WPARAM wParam,
    LPARAM lParam);
  afx_msg LRESULT OnBeginFormatExDialog(WPARAM wParam,
    LPARAM lParam);
  afx_msg LRESULT OnEndFormatExDialog(WPARAM wParam,
    LPARAM lParam);
  DECLARE_MESSAGE_MAP()

protected:
  void* mpImpObj;

private:
  friend class GcFdUiSystemInternals;
};