
#ifndef _RXSERVERICE_H_INCLUDED_
#define _RXSERVERICE_H_INCLUDED_ 1

#include "rxobject.h"
#include "TD_PackPush.h"

extern "C" {
    typedef OdRx::AppRetCode (*DepFuncPtr)(OdRx::AppMsgCode, void*);
}

class OdRxServicePrototype;
class OdRxService;

class FIRSTDLL_EXPORT OdRxService: public OdRxObject
{
public:
    ODRX_DECLARE_MEMBERS(OdRxService);
    OdRxService();
    virtual ~OdRxService();

    OdRxObject* getSysInfo() const;
    void        setSysInfo(OdRxObject* sysInfoObj);

    void        addDependency();
    void        removeDependency();

    OdBool unloadable() const;

    // The following functions are not currently implemented
    // They are present as place holders so that they can be
    // implemented in the future without breaking binary
    // compatibility
    //
    DepFuncPtr dependencyFunctionPtr();
    void setDependencyFunctionPtr(DepFuncPtr);

private:
    OdRxServicePrototype* mpImpService;
};

#include "TD_PackPop.h"
#endif
