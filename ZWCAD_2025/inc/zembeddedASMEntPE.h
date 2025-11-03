
#pragma once




#include "zacdbport.h"
#include "zrxobject.h"

class ZCDB_PORT ZcDbEmbeddedZSMEntPropsPE : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbEmbeddedZSMEntPropsPE);
    virtual void setIsEmbeddedEnt(ZcDbObject* pObj, bool bIsEmbedded = true);
};

