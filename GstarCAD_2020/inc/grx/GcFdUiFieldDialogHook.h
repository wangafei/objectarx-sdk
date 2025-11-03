#pragma once
#include <afxtempl.h>
class CGcFdUiFieldOptionDialog;
class CGcFdUiFieldDialog;
class GCEDCLASSDECL CGcFdUiFieldDialogHook : public CObject
{
public:
  CGcFdUiFieldDialogHook(void);
  ~CGcFdUiFieldDialogHook(void);

  // For internal use only
  virtual BOOL    CreateInstance(CGcFdUiFieldDialogHook*& pHook);

  virtual int     GetEvaluatorIds(CStringArray& evalIds);
  virtual BOOL    BeginFieldDialog(CGcFdUiFieldDialog* pFieldDlg, GcDbDatabase* pDb, int nContext);
  virtual BOOL    EndFieldDialog(int nRet);
  virtual BOOL    SetFieldToEdit(GcDbField* pField);
  GcDbDatabase *  GetDatabase(void) const;
  virtual BOOL    GetCategoryNames(UINT uMinUnusedCatId, CStringArray& catNames, CUIntArray& catIds);
  virtual BOOL    GetFieldNames(UINT uCatId, UINT uMinUnusedFieldId, CStringArray& fieldNames, CUIntArray& fieldIds, BOOL& bSort);
  virtual BOOL    GetOptionDialog(UINT uFieldId, CGcFdUiFieldOptionDialog*& pOptionDlg);
  virtual CString GetPreview(LPCTSTR pszFormatType, LPCTSTR pszFormat);
  virtual BOOL    UpdateFieldCode(void);
  virtual BOOL    OnFieldSelected(UINT uFieldId);
  virtual BOOL    CreateField(UINT uFieldId, GcDbField*& pField);
};

typedef CTypedPtrArray<CPtrArray, CGcFdUiFieldDialogHook*>  GcFdUiFieldDialogHookArray;