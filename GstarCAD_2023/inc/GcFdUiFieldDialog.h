/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gdui.h"
#include "GcFdUi.h"
#include "gcui.h"

class GcFdUiSystemInternals;
class CGcFdUiFieldOptionDialog;
class CGcFdUiImpFieldDialog;

#define GCFDUI_FD_CREATE_FIELD         1
#define GCFDUI_FD_EDIT_FIELD           2

class GCFDUI_PORT CGcFdUiFieldDialog : public CGcUiDialog
{
  friend CGcFdUiImpFieldDialog;
  DECLARE_DYNAMIC(CGcFdUiFieldDialog)

public:
  CGcFdUiFieldDialog(CWnd* pParent = NULL);
  ~CGcFdUiFieldDialog();

  INT_PTR         DoModal(GcDbField*& pField,
    BOOL bEdit,
    GcDbDatabase* pDb);
  GcDbField   *   GetFieldToEdit(void) const;
  BOOL            SetFieldCodeReadOnly(BOOL bReadOnly = TRUE);
  CString         GetFieldCode(void) const;
  BOOL            SetFieldCode(LPCTSTR pszExpr);
  BOOL            IsFieldCodeDirty(void);
  CEdit       *   GetFieldCodeEditCtrl(void);
  BOOL            GetCurrentField(UINT* pFieldId,
    UINT* pCatId) const;
  BOOL            SelectField(UINT uFieldId,
    UINT uCatId);
  CGcFdUiFieldOptionDialog* GetOptionDialog(void) const;

public:
  void            BeginEditorCommand(void);
  void            CompleteEditorCommand(BOOL restoreDialogs = TRUE);
  void            CancelEditorCommand(void);

protected:
  void DoDataExchange(CDataExchange* pDX) override;

  DECLARE_MESSAGE_MAP()

protected:
  BOOL            OnInitDialog() override;
  void            OnOK() override;
  void            OnCancel() override;

  afx_msg void    OnCbnSelChangeCategoryList(void);
  afx_msg void    OnLbnSelChangeFieldNameList(void);
  afx_msg void    OnEnChangeFieldCode(void);
  afx_msg void    OnDialogHelp(void);
  afx_msg LRESULT OnFormatChanged(WPARAM wParam,
    LPARAM lParam);
  afx_msg LRESULT OnBeginFormatExDialog(WPARAM wParam,
    LPARAM lParam);
  afx_msg LRESULT OnEndFormatExDialog(WPARAM wParam,
    LPARAM lParam);

protected:
  void* mpImpObj;

private:
  friend class GcFdUiSystemInternals;
};