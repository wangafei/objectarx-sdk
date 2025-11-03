
#pragma once

#include "zacdb.h"
#include "zdynprops-AcFilterablePropertyContext.h"

#pragma pack (push, 8)


class ZCDBCORE2D_PORT ZcDbPropertyFilterCustomizationPE : public ZcRxObject
{
public:

    ZCRX_DECLARE_MEMBERS(ZcDbPropertyFilterCustomizationPE);

    virtual bool vetoCustomization(ZcFilterablePropertyContext context,
                                   ZcRxClass* pCls) const = 0;

    virtual bool createObject(ZcDbDatabase* pDb,
                              ZcRxClass* pCls,
                              ZcDbEntity** ppEnt,
                              ZcDbObjectId& objId,
                              const ZcString& sGUID) const = 0;
};

#pragma pack (pop)

