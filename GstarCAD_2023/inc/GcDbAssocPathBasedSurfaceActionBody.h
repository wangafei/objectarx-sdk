/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocEdgeActionParam.h"
#include "GcDbAssocSurfaceActionBody.h"
#include "GcDbAssocVertexActionParam.h"
#pragma pack (push, 8)

class DBCONSTRAINTS_PORT GcDbAssocPathBasedSurfaceActionBody : public GcDbAssocSurfaceActionBody
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocPathBasedSurfaceActionBody);

  explicit GcDbAssocPathBasedSurfaceActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  Gcad::ErrorStatus removeAllPathParams();
  Gcad::ErrorStatus getInputPathParams(GcDbObjectIdArray& pathParamIds) const;

  Gcad::ErrorStatus getInputPaths(GcArray<GcArray<GcArray<GcDbEdgeRef> > >&) const;
  Gcad::ErrorStatus setInputPaths(const GcArray<GcArray<GcDbEdgeRef> >&);
  Gcad::ErrorStatus setInputPaths(const GcArray<GcDbPathRef>&);
  Gcad::ErrorStatus updateInputPath(int pathIndex, const GcDbPathRef&);

  Gcad::ErrorStatus removeAllVertexParams();
  Gcad::ErrorStatus getInputVertexParams(GcDbObjectIdArray& vertexParamIds) const;

  Gcad::ErrorStatus setInputPoints(const GcArray<GcDbVertexRef>&);
  Gcad::ErrorStatus getInputPoints(GcArray<GcDbVertexRef>&) const;

  Gcad::ErrorStatus makeInputPathsDrawOnTopOfResultingSurface() const;
};

#pragma pack (pop)