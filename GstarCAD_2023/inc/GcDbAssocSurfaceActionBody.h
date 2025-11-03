/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocParamBasedActionBody.h"
#pragma pack (push, 8)

class DBCONSTRAINTS_PORT GcDbAssocSurfaceActionBody : public GcDbAssocParamBasedActionBody
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocSurfaceActionBody);

  explicit GcDbAssocSurfaceActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  GcDbObjectId resultingSurfaceDep(bool createIfDoesNotExist, bool isWriteOnlyDependency = true);
  GcDbObjectId resultingSurface() const;
  Gcad::ErrorStatus setResultingSurface(const GcDbObjectId& surfaceId, bool isWriteOnlyDependency = true);
  bool isSemiAssociative() const;
  virtual bool isSemiAssociativitySatisfiedOverride() const;
  void evaluateOverride() override;
  Gcad::ErrorStatus getDependentActionsToEvaluateOverride(GcDbActionsToEvaluateCallback*) const override;
  Gcad::ErrorStatus addMoreObjectsToDeepCloneOverride(
    GcDbIdMapping&, GcDbObjectIdArray& additionalObjectsToClone) const override;
  Gcad::ErrorStatus dragStatusOverride(const GcDb::DragStat) override;

  static Gcad::ErrorStatus findActionsThatAffectedTopologicalSubentity(
    const GcDbEntity*  pAsmBasedEntity,
    const GcDbSubentId&,
    GcDbObjectIdArray& actionIds);

  static Gcad::ErrorStatus getTopologicalSubentitiesForActionsOnEntity(
    const GcDbEntity*                pAsmBasedEntity,
    bool                             alsoUseAdjacentTopology,
    GcDbObjectIdArray&               actionIds,
    GcArray<GcArray<GcDbSubentId> >& actionSubentIds);

  static Gcad::ErrorStatus getSurfacesDirectlyDependentOnObject(
    const GcDbObject*,
    GcDbObjectIdArray& dependentSurfaceIds);

  virtual Gcad::ErrorStatus getGripPoints(
    GcGePoint3dArray& gripPoints,
    GcDbIntArray&     osnapModes,
    GcDbIntArray&     geomIds) const;

  virtual Gcad::ErrorStatus getGripPoints(
    GcDbGripDataPtrArray& grips,
    const double          curViewUnitSize,
    const int             gripSize,
    const GcGeVector3d&   curViewDir,
    const int             bitflags) const;

  virtual Gcad::ErrorStatus moveGripPoints(
    const GcDbIntArray& indices,
    const GcGeVector3d& offset);

  virtual Gcad::ErrorStatus moveGripPoints(
    const GcDbVoidPtrArray& gripAppData,
    const GcGeVector3d&     offset,
    const int               bitflags);

  virtual Gcad::ErrorStatus moveStretchPoints(
    const GcDbIntArray& indices,
    const GcGeVector3d& offset);

  virtual void gripStatus(const GcDb::GripStat status);

  virtual Gcad::ErrorStatus getGripEntityUCS(
    const void*   pGripAppData,
    GcGeVector3d& normalVec,
    GcGePoint3d&  origin,
    GcGeVector3d& xAxis) const;

  virtual void list() const;
};

#pragma pack (pop)