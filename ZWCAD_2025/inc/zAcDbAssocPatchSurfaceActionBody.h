
#pragma once
#include "zdbgrip.h"
#include "zAcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class ZCDB_PORT ZcDbAssocPatchSurfaceActionBody : public ZcDbAssocPathBasedSurfaceActionBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocPatchSurfaceActionBody);

    explicit ZcDbAssocPatchSurfaceActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    Zcad::ErrorStatus setConstraintPoints( const ZcArray<ZcDbVertexRef> & constraintPoints);

    Zcad::ErrorStatus setConstraintCurves( const ZcArray<ZcDbEdgeRef> & constraintCurves );

    Zcad::ErrorStatus setContinuity(int continuity, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString());

    int continuity(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    Zcad::ErrorStatus getContinuityGripPoint ( ZcGePoint3d&  gripPt) const;

    Zcad::ErrorStatus setBulge(double bulge, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString());

    double bulge(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    static Zcad::ErrorStatus createInstance( const ZcDbObjectId& patchSurfaceId,
                                             const ZcArray<ZcDbEdgeRef>& profileCurves,
                                             const ZcArray<ZcDbEdgeRef>& constraintCurves,
                                             const ZcArray<ZcDbVertexRef>&constraintPoints,
                                             int nContinuity,
                                             double dBulge,
                                             bool bEnabled,
                                             ZcDbObjectId& createdActionId);

    static Zcad::ErrorStatus createInstance( const ZcDbObjectId& patchSurfaceId,
                                             const ZcArray<ZcDbEdgeRef>& profileCurves,
                                             const ZcArray<ZcDbEdgeRef>& constraintCurves,
                                             const ZcArray<ZcDbVertexRef>&constraintPoints,
                                             bool bEnabled,
                                             ZcDbObjectId& createdActionId);

};

#pragma pack (pop)
