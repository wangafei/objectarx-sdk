
#pragma once

#if _MSC_VER > 1000
#pragma once
#endif

#include "zacfdui.h"
#include "zacfduifielddialoghook.h"

class ZcTcUiSystemInternals;
class CZcFdUiFieldCatalog;
class CZcFdUiFieldDialogHook;

class ZCFDUI_PORT CZcFdUiFieldManager : public CObject
{
public:
    CZcFdUiFieldManager(void);
    ~CZcFdUiFieldManager(void);

    BOOL			RegisterFieldDialogHook	(CZcFdUiFieldDialogHook* pDlgHook);
    BOOL			UnregisterFieldDialogHook(const CZcFdUiFieldDialogHook* pDlgHook);
    int				GetRegisteredDialogHooks(ZcFdUiFieldDialogHookArray& hooks);

protected:
    void            *   mpImpObj;

private:
    friend class ZcFdUiSystemInternals;
};
