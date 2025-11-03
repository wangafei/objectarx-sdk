
#pragma once
#include "zAcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class ZCDB_PORT ZcDbAssocSweptSurfaceActionBody : public ZcDbAssocPathBasedSurfaceActionBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocSweptSurfaceActionBody);

    explicit ZcDbAssocSweptSurfaceActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    Zcad::ErrorStatus setScaleFactor(double scale, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString());

    double scaleFactor(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    Zcad::ErrorStatus setAlignAngle(double angle, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString());

    double alignAngle(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    Zcad::ErrorStatus setTwistAngle(double angle, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString());

    double twistAngle(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    static Zcad::ErrorStatus createInstance( const ZcDbObjectId& resultingSurfaceId,
                                             const ZcDbPathRef& sweepProfile,
                                             const ZcDbPathRef& sweepPathProfile,
                                             const ZcDbSweepOptions& sweptOptions,
                                             bool  bEnabled,
                                             ZcDbObjectId& createdActionId);
};

#pragma pack (pop)
