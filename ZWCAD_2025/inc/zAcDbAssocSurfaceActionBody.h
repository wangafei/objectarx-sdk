
#pragma once
#include "zAcDbAssocParamBasedActionBody.h"
#pragma pack (push, 8)

class ZCDB_PORT ZcDbAssocSurfaceActionBody : public ZcDbAssocParamBasedActionBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocSurfaceActionBody);

    explicit ZcDbAssocSurfaceActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    ZcDbObjectId resultingSurfaceDep(bool createIfDoesNotExist, bool isWriteOnlyDependency = true);

    ZcDbObjectId resultingSurface() const;

    Zcad::ErrorStatus setResultingSurface(const ZcDbObjectId& surfaceId, bool isWriteOnlyDependency = true);

    bool isSemiAssociative() const;

    virtual bool isSemiAssociativitySatisfiedOverride() const;

    void evaluateOverride() override;

    Zcad::ErrorStatus getDependentActionsToEvaluateOverride(ZcDbActionsToEvaluateCallback*) const override;

    Zcad::ErrorStatus addMoreObjectsToDeepCloneOverride(
        ZcDbIdMapping&, ZcDbObjectIdArray& additionalObjectsToClone) const override;

    Zcad::ErrorStatus dragStatusOverride(const ZcDb::DragStat) override;

    static Zcad::ErrorStatus findActionsThatAffectedTopologicalSubentity(
        const ZcDbEntity*  pZsmBasedEntity,
        const ZcDbSubentId&,
        ZcDbObjectIdArray& actionIds);

    static Zcad::ErrorStatus getTopologicalSubentitiesForActionsOnEntity(
        const ZcDbEntity*                pZsmBasedEntity,
        bool                             alsoUseAdjacentTopology,
        ZcDbObjectIdArray&               actionIds,
        ZcArray<ZcArray<ZcDbSubentId> >& actionSubentIds);

    static Zcad::ErrorStatus getSurfacesDirectlyDependentOnObject(
        const ZcDbObject*,
        ZcDbObjectIdArray& dependentSurfaceIds);

    virtual Zcad::ErrorStatus getGripPoints(
        ZcGePoint3dArray& gripPoints,
        ZcDbIntArray&     osnapModes,
        ZcDbIntArray&     geomIds) const;

    virtual Zcad::ErrorStatus getGripPoints(
        ZcDbGripDataPtrArray& grips,
        const double          curViewUnitSize,
        const int             gripSize,
        const ZcGeVector3d&   curViewDir,
        const int             bitflags) const;

    virtual Zcad::ErrorStatus moveGripPoints(
        const ZcDbIntArray& indices,
        const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus moveGripPoints(
        const ZcDbVoidPtrArray& gripAppData,
        const ZcGeVector3d&     offset,
        const int               bitflags);

    virtual Zcad::ErrorStatus moveStretchPoints(
        const ZcDbIntArray& indices,
        const ZcGeVector3d& offset);

    virtual void gripStatus(const ZcDb::GripStat status);

    virtual Zcad::ErrorStatus getGripEntityUCS(
        const void*   pGripAppData,
        ZcGeVector3d& normalVec,
        ZcGePoint3d&  origin,
        ZcGeVector3d& xAxis) const;

    virtual void list() const;

};

#pragma pack (pop)

