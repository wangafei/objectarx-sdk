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
#include "GcFdUiFieldDialogHook.h"

class GcTcUiSystemInternals;
class CGcFdUiFieldCatalog;
class CGcFdUiFieldDialogHook;

class GCFDUI_PORT CGcFdUiFieldManager : public CObject
{
public:
  CGcFdUiFieldManager(void);
  ~CGcFdUiFieldManager(void);

  BOOL			RegisterFieldDialogHook(CGcFdUiFieldDialogHook* pDlgHook);
  BOOL			UnregisterFieldDialogHook(const CGcFdUiFieldDialogHook* pDlgHook);
  int				GetRegisteredDialogHooks(GcFdUiFieldDialogHookArray& hooks);

protected:
  void* mpImpObj;

private:
  friend class GcFdUiSystemInternals;
};