
#pragma once
#include "zAcDbAssocEdgeActionParam.h"
#include "zAcDbAssocSurfaceActionBody.h"
#include "zAcDbAssocVertexActionParam.h"
#pragma pack (push, 8)

class ZCDB_PORT ZcDbAssocPathBasedSurfaceActionBody : public ZcDbAssocSurfaceActionBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocPathBasedSurfaceActionBody);

    explicit ZcDbAssocPathBasedSurfaceActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    Zcad::ErrorStatus removeAllPathParams();

    Zcad::ErrorStatus getInputPathParams(ZcDbObjectIdArray& pathParamIds) const;

    Zcad::ErrorStatus getInputPaths(ZcArray<ZcArray<ZcArray<ZcDbEdgeRef> > >&) const;

    Zcad::ErrorStatus setInputPaths(const ZcArray<ZcArray<ZcDbEdgeRef> >&);

    Zcad::ErrorStatus setInputPaths(const ZcArray<ZcDbPathRef>&);

    Zcad::ErrorStatus updateInputPath(int pathIndex, const ZcDbPathRef&);

    Zcad::ErrorStatus removeAllVertexParams();

    Zcad::ErrorStatus getInputVertexParams(ZcDbObjectIdArray& vertexParamIds) const;

    Zcad::ErrorStatus setInputPoints(const ZcArray<ZcDbVertexRef>&);

    Zcad::ErrorStatus getInputPoints(ZcArray<ZcDbVertexRef>&) const;

    Zcad::ErrorStatus makeInputPathsDrawOnTopOfResultingSurface() const;

};

#pragma pack (pop)

