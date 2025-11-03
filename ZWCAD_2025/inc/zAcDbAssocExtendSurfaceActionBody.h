
#pragma once
#include "zAcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class ZcDbSurface;
#include "zdbsurf.h"

class ZCDB_PORT ZcDbAssocExtendSurfaceActionBody : public ZcDbAssocPathBasedSurfaceActionBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocExtendSurfaceActionBody);

    explicit ZcDbAssocExtendSurfaceActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    Zcad::ErrorStatus setDistance(double distance, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString());

    double distance(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    static Zcad::ErrorStatus createInstance( const ZcDbObjectId& resultingSurfaceId,
                                             const ZcArray<ZcDbEdgeRef>& extendEdges,
                                             double distance,
                                             ZcDbSurface::EdgeExtensionType option,
                                             bool bEnabled,
                                             ZcDbObjectId& createdActionId );

};

#pragma pack (pop)
