/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocActionParam.h"
#include "GcDbGeomRef.h"
#pragma pack (push, 8)

class DBCONSTRAINTS_PORT GcDbAssocEdgeActionParam : public GcDbAssocActionParam
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocEdgeActionParam);

  explicit GcDbAssocEdgeActionParam(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  virtual Gcad::ErrorStatus setEdgeRef(const GcDbEdgeRef& edgeRef, bool isReadDependency = true, bool isWriteDependency = false, int dependencyOrder = 0);
  virtual Gcad::ErrorStatus getEdgeRef(GcArray<GcDbEdgeRef>& edgeRefs) const;
  virtual Gcad::ErrorStatus setEdgeSubentityGeometry(const GcGeCurve3d* pNewEdgeCurve);
  Gcad::ErrorStatus getDependentOnCompoundObject(GcDbCompoundObjectId& compoundId) const;
};

#pragma pack (pop)