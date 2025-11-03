
#ifndef _ZDBSELECTGRIP_H
#define _ZDBSELECTGRIP_H

#include "zacdb.h"
#include "zdbmain.h"

#pragma pack (push, 8)

class ZCDB_PORT ZSOFT_NO_VTABLE ZcDbSelectGrip : public ZcRxObject {
public:
    ZCRX_DECLARE_MEMBERS(ZcDbSelectGrip);

    virtual bool SelectGrip(const ZcDbEntity * pEnt,
                            const ZcGiViewportDraw* pVd,
                            const void * pAppData) = 0;
};

class ZSOFT_NO_VTABLE ZcDbSelectGrip2 : public ZcRxObject {
public:
    ZCRX_DECLARE_MEMBERS(ZcDbSelectGrip2);

    virtual bool SelectGrip(const ZcDbEntity * pEnt,
                        const ZcGiViewportDraw* pVd,
                        const ZcDbGripData* pGripData) = 0;
};
#pragma pack (pop)

#endif

