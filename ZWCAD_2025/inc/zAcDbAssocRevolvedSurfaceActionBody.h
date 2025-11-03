
#pragma once
#include "zAcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class ZcDbRevolveOptions;

class ZCDB_PORT ZcDbAssocRevolvedSurfaceActionBody : public ZcDbAssocPathBasedSurfaceActionBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocRevolvedSurfaceActionBody);

    explicit ZcDbAssocRevolvedSurfaceActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    Zcad::ErrorStatus setRevolveAngle(double angle, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString());

    double revolveAngle(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    static Zcad::ErrorStatus createInstance( const ZcDbObjectId& resultingSurfaceId,
                                             const ZcDbPathRef& revolvePath,
                                             const ZcDbPathRef& axisPath,
                                             double dAngle,
                                             double dStartAngle,
                                             const ZcDbRevolveOptions& revolveOptions,
                                             bool bFlipAxisDirection,
                                             bool bEnabled,
                                             ZcDbObjectId& createdActionId);

};

#pragma pack (pop)
