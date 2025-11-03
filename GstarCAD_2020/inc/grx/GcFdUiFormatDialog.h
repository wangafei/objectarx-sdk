#pragma once
#include "gduiDialog.h"
#include <afxwin.h>
class CGcFdUiFormatList;

class GCEDCLASSDECL CGcFdUiFormatDialog : public CGdUiDialog
{
  DECLARE_DYNAMIC(CGcFdUiFormatDialog)

public:
  CGcFdUiFormatDialog(CWnd* pParent, BOOL bNew);
  virtual ~CGcFdUiFormatDialog();

  virtual BOOL 	Create(CWnd* pParent);

  CGcFdUiFormatList* GetFormatList(void);
  CString    GetFormatType(void) const;
  BOOL       SetFormatType(LPCTSTR pszFormatType);
  int        GetCurrentFormat(CString& sDisplayName, CString& sFormatString, CString& sVersion) const;
  BOOL       SetCurrentFormat(LPCTSTR pszDisplayName, LPCTSTR pszFormatString);
  BOOL       SetFormatPreviewReadOnly(BOOL bReadOnly = TRUE);
  BOOL       SetFormatPreviewLabel(LPCTSTR pszText);
  BOOL       SetFormatPreviewText(LPCTSTR pszPreviewText, const GcValue& fieldValue);
  BOOL       SetDialogStyle(int nStyle);

};