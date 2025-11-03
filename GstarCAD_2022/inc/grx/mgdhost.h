#pragma once

class OdDbManagedHost
{
public:
    virtual int version() { throw OdError(OdResult::eNotImplemented); return 1;}
    virtual OdResult load(const OdChar * fname){return eNotImplementedYet;};
};

GCDB_DLL_DECL OdDbManagedHost* gcdbGetManagedHost();
GCDB_DLL_DECL OdResult gcdbSetManagedHost(OdDbManagedHost* pHost);
GCDB_DLL_DECL HRESULT gcdbInitializeManagedLayer();
GCDB_DLL_DECL HRESULT gcdbTerminateManagedLayer();
