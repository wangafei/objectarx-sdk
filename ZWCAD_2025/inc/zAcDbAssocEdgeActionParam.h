
#pragma once
#include "zAcDbAssocActionParam.h"
#include "zAcDbGeomRef.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocEdgeActionParam : public ZcDbAssocActionParam
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocEdgeActionParam);

    explicit ZcDbAssocEdgeActionParam(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    virtual Zcad::ErrorStatus setEdgeRef(const ZcDbEdgeRef& edgeRef, bool isReadDependency = true, bool isWriteDependency = false, int dependencyOrder = 0);

    virtual Zcad::ErrorStatus getEdgeRef(ZcArray<ZcDbEdgeRef>& edgeRefs) const;

    virtual Zcad::ErrorStatus setEdgeSubentityGeometry(const ZcGeCurve3d* pNewEdgeCurve);

    Zcad::ErrorStatus getDependentOnCompoundObject(ZcDbCompoundObjectId& compoundId) const;
};

#pragma pack (pop)

