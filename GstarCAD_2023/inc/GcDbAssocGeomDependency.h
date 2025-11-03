/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocDependency.h"
#include "GcDbAssocPersSubentId.h"
#pragma pack (push, 8)

class GcDbAssocGeomDependency : public GcDbAssocDependency
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocGeomDependency, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcDbAssocGeomDependency(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  DBCONSTRAINTS_PORT const GcDbAssocPersSubentId* persistentSubentId() const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getTransientSubentIds(GcArray<GcDbSubentId>& transientSubentIds) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus setSubentity(const GcDbSubentId& transientSubentId);
  DBCONSTRAINTS_PORT GcDb::SubentType subentType() const;
  DBCONSTRAINTS_PORT int transientSubentCount() const;

  DBCONSTRAINTS_PORT bool isCachingSubentityGeometry() const;
  DBCONSTRAINTS_PORT void setCachingSubentityGeometry(bool yesNo);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getVertexSubentityGeometry(GcGePoint3dArray& vertexPositions) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getEdgeSubentityGeometry(GcArray<GcGeCurve3d*>& edgeCurves) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getFaceSubentityGeometry(GcArray<GcGeSurface*>& faceSurfaces) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setVertexSubentityGeometry(const GcGePoint3dArray& newVertexPositions);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setEdgeSubentityGeometry(const GcArray<const GcGeCurve3d*>& newEdgeCurves);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setFaceSubentityGeometry(const GcArray<const GcGeSurface*>& newFaceSurfaces);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus dependentOnObjectMirrored();
  DBCONSTRAINTS_PORT static Gcad::ErrorStatus redirectToAnotherSubentity(const GcDbObjectId& oldObjectId,
    const GcDbSubentId& oldSubentId,
    const GcDbObjectId& newObjectId,
    const GcDbSubentId& newSubentId);

};

#pragma pack (pop)