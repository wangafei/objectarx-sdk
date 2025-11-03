/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocEdgeActionParam.h"
#include "GcDbAssocCompoundActionParam.h"
#pragma pack (push, 8)

class  DBCONSTRAINTS_PORT GcDbAssocPathActionParam : public GcDbAssocCompoundActionParam
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocPathActionParam);

  explicit GcDbAssocPathActionParam(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  virtual Gcad::ErrorStatus setEdgeRefArray(const GcArray<GcDbEdgeRef>& edgeRefs, int dependencyOrder = 0);
  virtual Gcad::ErrorStatus updateEdgeRef(int edgeRefIndex, const GcDbEdgeRef& edgeRef);
  virtual Gcad::ErrorStatus getEdgeRefArray(GcArray<GcArray<GcDbEdgeRef> >& edgeRefs) const;
};

#pragma pack (pop)