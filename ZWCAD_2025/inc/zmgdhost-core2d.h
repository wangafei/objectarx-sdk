
#include "zAdAChar.h"
#include "zacadstrc.h"
#include "zAcDbCore2dDefs.h"

#pragma once
class ZcString;



class ZcDbManagedHost
{
public:
    virtual int version() { return 1;}
    virtual Zcad::ErrorStatus load(const ZTCHAR * fname)=0;
    virtual bool loadIndirectString(const ZcString& resAssemblyPath, const ZcString& cmdString, ZcString& localCmd) = 0;
    virtual bool isLoaded() = 0;
};

ZCDBCORE2D_PORT ZcDbManagedHost* ZSOFT_STDCALL zcdbGetManagedHost();
ZCDBCORE2D_PORT Zcad::ErrorStatus ZSOFT_STDCALL zcdbSetManagedHost(ZcDbManagedHost* pHost);

