#pragma once
#include "GcFdUiFieldDialogHook.h"
class GCEDCLASSDECL CGcFdUiFieldManager : public CObject
{
public:
  CGcFdUiFieldManager(void);
  ~CGcFdUiFieldManager(void);

  BOOL  RegisterFieldDialogHook(CGcFdUiFieldDialogHook* pDlgHook);
  BOOL  UnregisterFieldDialogHook(const CGcFdUiFieldDialogHook* pDlgHook);
  int   etRegisteredDialogHooks(GcFdUiFieldDialogHookArray& hooks);
};