

#include "zacdb.h"
#include "zdbmain.h"

#pragma once
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbJoinEntityPE : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbJoinEntityPE);

    virtual Zcad::ErrorStatus 
        joinEntity(ZcDbEntity* pPrimaryEntity, 
            ZcDbEntity* pSecondaryEntity,
            const ZcGeTol& tol = ZcGeContext::gTol) const = 0;

    virtual Zcad::ErrorStatus 
        joinEntities(ZcDbEntity* pPrimaryEntity, 
            const ZcArray<ZcDbEntity*>& otherEntities,
            ZcGeIntArray& joinedEntityIndices,
            const ZcGeTol& tol = ZcGeContext::gTol) const = 0;
};

#pragma pack (pop)



