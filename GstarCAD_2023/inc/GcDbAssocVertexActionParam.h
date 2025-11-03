/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocEdgeActionParam.h"
#include "GcDbGeomRef.h"
#pragma pack (push, 8)

class DBCONSTRAINTS_PORT GcDbAssocVertexActionParam : public GcDbAssocActionParam
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocVertexActionParam);

  explicit GcDbAssocVertexActionParam(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  virtual Gcad::ErrorStatus setVertexRef(const GcDbVertexRef& vertexRef, bool isReadDependency = true, bool isWriteDependency = false, int dependencyOrder = 0);
  virtual Gcad::ErrorStatus getVertexRef(GcArray<GcDbVertexRef>& vertexRefs) const;
  Gcad::ErrorStatus getVertexRef(GcDbVertexRef& vertexRef) const;
  virtual Gcad::ErrorStatus setVertexSubentityGeometry(const GcGePoint3d& newPosition);
  Gcad::ErrorStatus getDependentOnCompoundObject(GcDbCompoundObjectId& compoundId) const;
};

#pragma pack (pop)