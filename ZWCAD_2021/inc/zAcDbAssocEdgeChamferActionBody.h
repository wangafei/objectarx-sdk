#pragma once
#include "zacdbassocpathbasedsurfaceactionbody.h"
#pragma pack (push, 8)

class ZCDB_PORT ZcDbAssocEdgeChamferActionBody : public ZcDbAssocPathBasedSurfaceActionBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocEdgeChamferActionBody);

    explicit ZcDbAssocEdgeChamferActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    Zcad::ErrorStatus setInput(const ZcDbFullSubentPathArray& chamferEdges, const ZcDbSubentId& baseFace);

    Zcad::ErrorStatus setBaseDistance(double baseDistance, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString());

    Zcad::ErrorStatus setOtherDistance(double otherDistance, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString());

    double baseDistance(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    double otherDistance(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    virtual void evaluateOverride() ZSOFT_OVERRIDE;

    static Zcad::ErrorStatus createInstance( const ZcDbFullSubentPathArray& chamferEdges,
                                             const ZcDbSubentId& baseFace,
                                             double baseDistance,
                                             double otherDistance,
                                             bool bEnabled,
                                             ZcDbObjectId& createdActionId);
};

#pragma pack (pop)
