
#pragma once
#include "zAcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class ZcDbPathRef;
class ZcDbLoftOptions;

class ZCDB_PORT ZcDbAssocLoftedSurfaceActionBody : public ZcDbAssocPathBasedSurfaceActionBody
{
public:

    enum ProfileType {

        kStartCrossSection  = 0x01,

        kEndCrossSection    = 0x02,

        kStartGuide         = 0x04,

        kEndGuide           = 0x08
    };
    ZCRX_DECLARE_MEMBERS(ZcDbAssocLoftedSurfaceActionBody);

    explicit ZcDbAssocLoftedSurfaceActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    Zcad::ErrorStatus getContinuity( ProfileType type, int &continuity, ZcString& expression = dummyString(),
        ZcString& evaluatorId = dummyString() ) const;

    Zcad::ErrorStatus setContinuity( ProfileType type, int continuity, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString() );

    Zcad::ErrorStatus getBulge( ProfileType type, double &bulge, ZcString& expression = dummyString(),
        ZcString& evaluatorId = dummyString() ) const;

    Zcad::ErrorStatus setBulge( ProfileType type, double bulge, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString() );

    static Zcad::ErrorStatus createInstance( const ZcDbObjectId& resultingSurfaceId,
                                             const ZcArray<ZcDbGeomRef *>& crossSections,
                                             const ZcArray<ZcDbPathRef>& guideCurves,
                                             const ZcDbPathRef& pathCurve,
                                             const ZcDbLoftOptions& loftOptions,
                                             const ZcArray<int>& continuityArray,
                                             const ZcArray<double>& bulgeArray,
                                             bool bEnabled,
                                             ZcDbObjectId& createdActionId);

};

#pragma pack (pop)
