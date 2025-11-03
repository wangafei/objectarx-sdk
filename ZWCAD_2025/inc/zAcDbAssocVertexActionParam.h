
#pragma once
#include "zAcDbAssocEdgeActionParam.h"
#include "zAcDbGeomRef.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocVertexActionParam : public ZcDbAssocActionParam
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocVertexActionParam);

    explicit ZcDbAssocVertexActionParam(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    virtual Zcad::ErrorStatus setVertexRef(const ZcDbVertexRef& vertexRef, bool isReadDependency = true, bool isWriteDependency = false, int dependencyOrder = 0);

    virtual Zcad::ErrorStatus getVertexRef(ZcArray<ZcDbVertexRef>& vertexRefs) const;

    Zcad::ErrorStatus getVertexRef(ZcDbVertexRef& vertexRef) const;

    virtual Zcad::ErrorStatus setVertexSubentityGeometry(const ZcGePoint3d& newPosition);

    Zcad::ErrorStatus getDependentOnCompoundObject(ZcDbCompoundObjectId& compoundId) const;
};

#pragma pack (pop)
