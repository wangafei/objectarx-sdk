
#pragma once
#include "zAcDbAssocPathBasedSurfaceActionBody.h"
#include "zAcDbAssocLoftedSurfaceActionBody.h"
#pragma pack (push, 8)

class ZCDB_PORT ZcDbAssocNetworkSurfaceActionBody : public ZcDbAssocPathBasedSurfaceActionBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocNetworkSurfaceActionBody);

    explicit ZcDbAssocNetworkSurfaceActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    Zcad::ErrorStatus getContinuity( ZcDbAssocLoftedSurfaceActionBody::ProfileType type,
        int &continuity, ZcString& expression = dummyString(),
        ZcString& evaluatorId = dummyString() ) const;

    Zcad::ErrorStatus setContinuity( ZcDbAssocLoftedSurfaceActionBody::ProfileType type,
        int continuity, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString() );

    Zcad::ErrorStatus getBulge( ZcDbAssocLoftedSurfaceActionBody::ProfileType type,
        double &bulge, ZcString& expression = dummyString(),
        ZcString& evaluatorId = dummyString() ) const;

    Zcad::ErrorStatus setBulge( ZcDbAssocLoftedSurfaceActionBody::ProfileType type,
        double bulge, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString() );

    static Zcad::ErrorStatus createInstance( const ZcDbObjectId& resultingSurfaceId,
                                             const ZcArray<ZcDbPathRef>& crossSections,
                                             const ZcArray<ZcDbPathRef>& guideCurves,
                                             const ZcArray<int>& continuityArray,
                                             const ZcArray<double>& bulgeArray,
                                             bool bEnabled,
                                             ZcDbObjectId& createdActionId);

};

#pragma pack (pop)
