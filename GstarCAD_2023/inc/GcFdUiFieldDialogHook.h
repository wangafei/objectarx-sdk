/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#if _MSC_VER > 1000
#pragma once
#endif 

#include "GcFdUi.h"
#include "DbField.h"
#include <afxtempl.h>

class GcTcUiSystemInternals;
class CGcFdUiFieldDialog;
class CGcFdUiFieldOptionDialog;
class CGcFdUiImpFieldDialog;
class CGcFdUiFieldDialogHook;

typedef CTypedPtrArray<CPtrArray, CGcFdUiFieldDialogHook*>  GcFdUiFieldDialogHookArray;

class GCFDUI_PORT CGcFdUiFieldDialogHook : public CObject
{
public:
  CGcFdUiFieldDialogHook(void);
  ~CGcFdUiFieldDialogHook(void);

  virtual BOOL    CreateInstance(CGcFdUiFieldDialogHook*& pHook);

  virtual int     GetEvaluatorIds(CStringArray& evalIds);
  virtual BOOL    BeginFieldDialog(CGcFdUiFieldDialog* pFieldDlg,
    GcDbDatabase* pDb,
    int nContext);
  virtual BOOL    EndFieldDialog(int nRet);
  virtual BOOL    SetFieldToEdit(GcDbField* pField);
  GcDbDatabase *  GetDatabase(void) const;
  virtual BOOL    GetCategoryNames(UINT uMinUnusedCatId,
    CStringArray& catNames,
    CUIntArray& catIds);
  virtual BOOL    GetFieldNames(UINT uCatId,
    UINT uMinUnusedFieldId,
    CStringArray& fieldNames,
    CUIntArray& fieldIds,
    BOOL& bSort);
  virtual BOOL    GetOptionDialog(UINT uFieldId,
    CGcFdUiFieldOptionDialog*& pOptionDlg);
  virtual CString GetPreview(LPCTSTR pszFormatType,
    LPCTSTR pszFormat);
  virtual BOOL    UpdateFieldCode(void);
  virtual BOOL    OnFieldSelected(UINT uFieldId);
  virtual BOOL    CreateField(UINT uFieldId,
    GcDbField*& pField);

protected:
  void* mpImpObj;

private:
  friend class GcFdUiSystemInternals;
};