
#pragma once
#include "zAcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class ZCDB_PORT ZcDbAssocPlaneSurfaceActionBody : public ZcDbAssocPathBasedSurfaceActionBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocPlaneSurfaceActionBody);

    explicit ZcDbAssocPlaneSurfaceActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    static Zcad::ErrorStatus createInstance( const ZcDbObjectId& resultingSurfaceId,
                                             const ZcDbPathRef& inputPath,
                                             bool bEnabled,
                                             ZcDbObjectId& createdActionId);

};

#pragma pack (pop)
