#pragma once
#include <afxwin.h>
#include "gduiDialog.h"

class GcDbField;
class GcDbDatabase;
class CGcFdUiFieldOptionDialog;
class CGcFdUiImpFieldDialog;

class GCEDCLASSDECL CGcFdUiFieldDialog : public CGdUiDialog
{
  friend CGcFdUiImpFieldDialog;
  DECLARE_DYNAMIC(CGcFdUiFieldDialog)

public:
  CGcFdUiFieldDialog(CWnd* pParent = NULL);
  virtual ~CGcFdUiFieldDialog();

  INT_PTR         DoModal(GcDbField*& pField, BOOL bEdit, GcDbDatabase* pDb);
  GcDbField*      GetFieldToEdit(void) const;
  BOOL            SetFieldCodeReadOnly(BOOL bReadOnly = TRUE);
  CString         GetFieldCode(void) const;
  BOOL            SetFieldCode(LPCTSTR pszExpr);
  BOOL            IsFieldCodeDirty(void);
  CEdit*          GetFieldCodeEditCtrl(void);
  BOOL            GetCurrentField(UINT* pFieldId, UINT* pCatId) const;
  BOOL            SelectField(UINT uFieldId, UINT uCatId);
  CGcFdUiFieldOptionDialog* GetOptionDialog(void) const;

public:
  // Base class overrides
  void            BeginEditorCommand(void);
  void            CompleteEditorCommand(BOOL restoreDialogs = TRUE);
  void            CancelEditorCommand(void);
};
