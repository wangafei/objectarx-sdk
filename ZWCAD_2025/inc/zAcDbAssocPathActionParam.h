
#pragma once
#include "zAcDbAssocEdgeActionParam.h"
#include "zAcDbAssocCompoundActionParam.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocPathActionParam : public ZcDbAssocCompoundActionParam
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocPathActionParam);

    explicit ZcDbAssocPathActionParam(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    virtual Zcad::ErrorStatus setEdgeRefArray(const ZcArray<ZcDbEdgeRef>& edgeRefs, int dependencyOrder = 0);

    virtual Zcad::ErrorStatus updateEdgeRef(int edgeRefIndex, const ZcDbEdgeRef& edgeRef);

    virtual Zcad::ErrorStatus getEdgeRefArray(ZcArray<ZcArray<ZcDbEdgeRef> >& edgeRefs) const;
};

#pragma pack (pop)
