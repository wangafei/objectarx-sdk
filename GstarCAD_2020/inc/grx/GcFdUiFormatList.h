#pragma once

class GCEDCLASSDECL CGcFdUiFormatList : public CGdUiListBox
{
  DECLARE_DYNAMIC(CGcFdUiFormatList)

public:
  CGcFdUiFormatList(void);
  virtual ~CGcFdUiFormatList(void);

  void      SetRootKey(LPCTSTR pszKey);
  void      SetPersistency(BOOL bPersist);
  CString   GetFormatType(void) const;
  BOOL      SetFormatType(LPCTSTR pszFormatType);
  int       GetCurrentFormat(CString& sDisplayName, CString& sFormatString) const;
  BOOL      SetCurrentFormat(LPCTSTR pszDisplayName, LPCTSTR pszFormatString);
  BOOL      Refresh(void);
};