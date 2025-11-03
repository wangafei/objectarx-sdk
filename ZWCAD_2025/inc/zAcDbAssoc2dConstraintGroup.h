
#pragma once
#include "zAcDbAssocAction.h"
#include "zAcConstraintGroupNode.h"
#include "zAcConstrainedGeometry.h"
#include "zAcGeomConstraint.h"
#include "zAcExplicitConstr.h"
#pragma pack (push, 8)

class ZcAutoConstrainEvaluationCallback;

#ifndef UNREFERENCED_PARAMETER
#define UNREFERENCED_PARAMETER(P)  (P)
#endif

class ZCDBCORE2D_PORT ZcDbAssoc2dConstraintGroup : public ZcDbAssocAction
{
public:
  ZCRX_DECLARE_MEMBERS(ZcDbAssoc2dConstraintGroup);

  enum SolutionStatus
  {

    kWellDefined = 0,

    kUnderConstrained,

    kOverConstrained,

    kInconsistent,

    kNotEvaluated,

    kNotAvailable,

    kRejectedByClient,
  };

  ZcDbAssoc2dConstraintGroup(const ZcGePlane& plane = ZcGePlane::kXYPlane);

  const ZcGePlane getWorkPlane() const;

  void setWorkPlane(const ZcGePlane& newPlane);

  Zcad::ErrorStatus transformActionBy(const ZcGeMatrix3d& transform);

  int getDOF();

  SolutionStatus solutionStatus(bool bAlsoCheckForConstraints = true) const;

  SolutionStatus geometryStatus(const ZcConstrainedGeometry* pConsGeom) const;

  SolutionStatus constraintStatus(const ZcGeomConstraint* pConstraint) const;

  Zcad::ErrorStatus addConstrainedGeometry(const ZcDbFullSubentPath& subentPath, ZcConstrainedGeometry*& pConsGeom);

  Zcad::ErrorStatus deleteConstrainedGeometry(const ZcDbObjectId& geomDependencyId);

  Zcad::ErrorStatus getConstrainedGeometry(const ZcDbFullSubentPath& fullSubentPath,
                                           ZcConstrainedGeometry*&   pConsGeom,
                                           bool bCreateArcLineMid = false);

  Zcad::ErrorStatus getConstrainedGeometry(const ZcDbAssocGeomDependency* pGeomDependency,
                                           ZcConstrainedGeometry*&   pConsGeom,
                                           ZcDb::ImplicitPointType* pPtType = NULL,
                                           int defPtIndex = -1,
                                           bool bCreateArcLineMid = false);

  Zcad::ErrorStatus getConstrainedGeometries(ZcArray<ZcConstrainedGeometry*>& aConstGeom) const;

  Zcad::ErrorStatus addGeometricalConstraint(ZcGeomConstraint::GeomConstraintType type,
                                             const ZcDbFullSubentPathArray& aPaths,
                                             ZcGeomConstraint** ppNewConstraint  = NULL,
                                             const ZcGeMatrix3d* pUCSCoord = NULL);

  Zcad::ErrorStatus addGeometricalConstraint(ZcGeomConstraint::GeomConstraintType type,
                                             const ZcArray<ZcConstrainedGeometry*>& apConsGeoms,
                                             ZcGeomConstraint** ppNewConstraint  = NULL,
                                             const ZcGeMatrix3d* pUCSCoord = NULL);

  Zcad::ErrorStatus addDistanceConstraint(ZcConstrainedGeometry* pConsGeom1,
                                          ZcConstrainedGeometry* pConsGeom2,
                                          ZcDistanceConstraint::DirectionType directionType,
                                          ZcDbObjectId valueDependencyId,
                                          ZcDbObjectId dimDependencyId,
                                          const ZcGeVector3d* pFixedDirection = NULL,
                                          const ZcConstrainedLine* pDirectionLine = NULL,
                                          ZcDistanceConstraint** ppNewDisConstraint = NULL);

  Zcad::ErrorStatus addAngleConstraint(ZcConstrainedLine* pConsLine1,
                                       ZcConstrainedLine* pConsLine2,
                                       ZcAngleConstraint::SectorType sectorType,
                                       ZcDbObjectId valueDependencyId,
                                       ZcDbObjectId dimDependencyId,
                                       ZcAngleConstraint** ppNewAngConstraint = NULL);

  Zcad::ErrorStatus add3PointAngleConstraint(ZcConstrainedPoint* pConsPoint1,
                                       ZcConstrainedPoint* pConsPoint2,
                                       ZcConstrainedPoint* pConsPoint3,
                                       ZcAngleConstraint::SectorType sectorType,
                                       ZcDbObjectId valueDependencyId,
                                       ZcDbObjectId dimDependencyId,
                                       Zc3PointAngleConstraint** ppNewAngConstraint = NULL);

  Zcad::ErrorStatus addRadiusDiameterConstraint(ZcConstrainedGeometry* pConsGeom,
                                                ZcRadiusDiameterConstraint::RadiusDiameterConstrType type,
                                                ZcDbObjectId valueDependencyId,
                                                ZcDbObjectId dimDependencyId,
                                                ZcRadiusDiameterConstraint** ppNewRadDiaConstraint = NULL);

  Zcad::ErrorStatus deleteConstraint(ZcGeomConstraint* pGeomConst);

  Zcad::ErrorStatus getConstraints(ZcArray<ZcGeomConstraint*>& apConstraints) const;

  Zcad::ErrorStatus autoConstrain(const ZcDbFullSubentPathArray& aPaths,
                                  const ZcGeTol& tol,
                                  ZcAutoConstrainEvaluationCallback* pCallback);

  Zcad::ErrorStatus getAllConnectedGeomDependencies(const ZcDbObjectIdArray& srcGeomDependencyIds,
                                                    ZcDbObjectIdArray& allConnectedGeomDependencyIds) const;

  ZcConstraintGroupNode* getGroupNodePtr(const ZcGraphNode::Id nodeId) const;

  void regenDimensionSystem();

  Zcad::ErrorStatus geometryMirrored(ZcDbAssocGeomDependency* pGeomDependency);

  static void addGlobalCallback(class ZcDbAssoc2dConstraintCallback* pCallback);

  static void removeGlobalCallback(class ZcDbAssoc2dConstraintCallback* pCallback);

  static class ZcDbAssoc2dConstraintCallback* globalCallback();

  static void setDoNotCheckNewlyAddedConstraints(bool doNotCheck);

  static bool doNotCheckNewlyAddedConstraints();

};

class ZCDBCORE2D_PORT ZcDbAssoc2dConstraintCallback
{
public:

    ZcDbAssoc2dConstraintCallback() {}

    virtual ~ZcDbAssoc2dConstraintCallback() {}

    virtual bool canBeRelaxed(const class ZcExplicitConstraint* pConstraint)
    {
        UNREFERENCED_PARAMETER(pConstraint);
        return false;
    }

    virtual void constraintDeactivated(const ZcExplicitConstraint *pConstraint,
                                       bool bDeactivated = true) {
        UNREFERENCED_PARAMETER(pConstraint);
        UNREFERENCED_PARAMETER(bDeactivated);
    }
};

class ZCDBCORE2D_PORT ZcAutoConstrainEvaluationCallback
{
    friend class ZcDbImpAssoc2dConstraintGroup;
    friend class ZcAutoConstraintEvalManager;
public:
  virtual ~ZcAutoConstrainEvaluationCallback() { }

  virtual void getConstraintPriorityOverride(ZcGeomConstraint::GeomConstraintType type,
        const ZcArray<const ZcConstrainedGeometry*>& geometries, int& priority) const
  {
      UNREFERENCED_PARAMETER(type);
      UNREFERENCED_PARAMETER(geometries);
      UNREFERENCED_PARAMETER(priority);
      return;
  }

  virtual void getAutoConstrainPriority(ZcArray<ZcGeomConstraint::GeomConstraintType>& constraintList) const
  {
      constraintList.setLogicalLength(0);
      for(int type = (int)ZcGeomConstraint::kHorizontal;
          type < (int)ZcGeomConstraint::kEqualRadius; ++type)
      {
          constraintList.append((ZcGeomConstraint::GeomConstraintType)type);
      }
  }

  virtual bool isEvaluationCancelled() { return false; }

  int getTotalConstraints(ZcArray<ZcGeomConstraint*>* pConstraints) const;

private:

  int getAutoConstraintMask() const;

  void validate(void* pData);

  bool isValidConstraintType(ZcGeomConstraint::GeomConstraintType type,
        const ZcGeomConstraint* pConstraint) const;

  void constraintAdded(ZcGeomConstraint* pNewCons);

private:
    ZcArray<ZcGeomConstraint*> mConstraints;
};

#pragma pack (pop)

