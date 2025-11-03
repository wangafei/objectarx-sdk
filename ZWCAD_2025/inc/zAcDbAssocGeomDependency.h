
#pragma once
#include "zAcDbAssocDependency.h"
#include "zAcDbAssocPersSubentId.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocGeomDependency : public ZcDbAssocDependency
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocGeomDependency);

    explicit ZcDbAssocGeomDependency(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    const ZcDbAssocPersSubentId* persistentSubentId() const;

    Zcad::ErrorStatus getTransientSubentIds(ZcArray<ZcDbSubentId>& transientSubentIds) const;

    Zcad::ErrorStatus setSubentity(const ZcDbSubentId& transientSubentId);

    ZcDb::SubentType subentType() const;

    int transientSubentCount() const;

    bool isCachingSubentityGeometry() const;

    void setCachingSubentityGeometry(bool yesNo);

    Zcad::ErrorStatus getVertexSubentityGeometry(ZcGePoint3dArray& vertexPositions) const;

    Zcad::ErrorStatus getEdgeSubentityGeometry(ZcArray<ZcGeCurve3d*>& edgeCurves) const;

    Zcad::ErrorStatus getFaceSubentityGeometry(ZcArray<ZcGeSurface*>& faceSurfaces) const;

    Zcad::ErrorStatus setVertexSubentityGeometry(const ZcGePoint3dArray& newVertexPositions);

    Zcad::ErrorStatus setEdgeSubentityGeometry(const ZcArray<const ZcGeCurve3d*>& newEdgeCurves);

    Zcad::ErrorStatus setFaceSubentityGeometry(const ZcArray<const ZcGeSurface*>& newFaceSurfaces);

    Zcad::ErrorStatus dependentOnObjectMirrored();

    static Zcad::ErrorStatus redirectToAnotherSubentity(const ZcDbObjectId& oldObjectId,
                                                        const ZcDbSubentId& oldSubentId,
                                                        const ZcDbObjectId& newObjectId,
                                                        const ZcDbSubentId& newSubentId);

};

#pragma pack (pop)

