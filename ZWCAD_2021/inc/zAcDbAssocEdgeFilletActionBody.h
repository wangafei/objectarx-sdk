#pragma once
#include "zacdbassocpathbasedsurfaceactionbody.h"
#pragma pack (push, 8)

class ZCDB_PORT ZcDbAssocEdgeFilletActionBody : public ZcDbAssocPathBasedSurfaceActionBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocEdgeFilletActionBody);

    explicit ZcDbAssocEdgeFilletActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    Zcad::ErrorStatus setInputEdges(const ZcDbFullSubentPathArray& filletEdges);

    Zcad::ErrorStatus setRadius(double radius, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString());

    double radius(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    virtual void evaluateOverride() ZSOFT_OVERRIDE;

    static Zcad::ErrorStatus createInstance( const ZcDbFullSubentPathArray& filletEdges,
                                             double radius,
                                             bool bEnabled,
                                             ZcDbObjectId& createdActionId);
};

#pragma pack (pop)
