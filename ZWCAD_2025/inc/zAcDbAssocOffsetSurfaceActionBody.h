
#pragma once
#include "zAcDbAssocSurfaceActionBody.h"
#pragma pack (push, 8)

class ZCDB_PORT ZcDbAssocOffsetSurfaceActionBody : public ZcDbAssocSurfaceActionBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocOffsetSurfaceActionBody);

    explicit ZcDbAssocOffsetSurfaceActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    Zcad::ErrorStatus setDistance(double distance, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString());

    double distance(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    static Zcad::ErrorStatus createInstance( const ZcDbObjectId& resultingSurfaceId,
                                             const ZcDbObjectId& inputSurfaceId,
                                             double distance,
                                             bool bEnabled,
                                             ZcDbObjectId& createdActionId);

};

#pragma pack (pop)
