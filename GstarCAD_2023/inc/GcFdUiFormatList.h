/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GcFdUi.h"

class GcTcUiSystemInternals;

class GCFDUI_PORT CGcFdUiFormatList : public CGdUiListBox
{
  DECLARE_DYNAMIC(CGcFdUiFormatList)

public:
  CGcFdUiFormatList(void);
  ~CGcFdUiFormatList(void);

  void			SetRootKey(LPCTSTR pszKey);
  void			SetPersistency(BOOL bPersist);
  CString		GetFormatType(void) const;
  BOOL			SetFormatType(LPCTSTR pszFormatType);
  int				GetCurrentFormat(CString& sDisplayName,
    CString& sFormatString) const;
  BOOL			SetCurrentFormat(LPCTSTR pszDisplayName,
    LPCTSTR pszFormatString);
  BOOL			Refresh(void);

protected:
  afx_msg int     OnCreate(LPCREATESTRUCT lpCreateStruct);
  afx_msg void 	  OnDestroy(void);

  DECLARE_MESSAGE_MAP()

protected:
  void* mpImpObj;

private:
  friend class GcFdUiSystemInternals;
};