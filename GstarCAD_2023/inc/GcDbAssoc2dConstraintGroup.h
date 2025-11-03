/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocAction.h"
#include "GcConstraintGroupNode.h"
#include "GcConstrainedGeometry.h"
#include "GcGeomConstraint.h"
#include "GcExplicitConstr.h"
#pragma pack (push, 8)

class GcAutoConstrainEvaluationCallback;

#ifndef UNREFERENCED_PARAMETER
#define UNREFERENCED_PARAMETER(P)  (P)
#endif

class GcDbAssoc2dConstraintGroup : public GcDbAssocAction
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssoc2dConstraintGroup, DBCONSTRAINTS_PORT);

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

  DBCONSTRAINTS_PORT GcDbAssoc2dConstraintGroup(const GcGePlane& plane = GcGePlane::kXYPlane);

  DBCONSTRAINTS_PORT const GcGePlane getWorkPlane() const;
  DBCONSTRAINTS_PORT void setWorkPlane(const GcGePlane& newPlane);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus transformActionBy(const GcGeMatrix3d& transform); 

  DBCONSTRAINTS_PORT int getDOF();

  DBCONSTRAINTS_PORT SolutionStatus solutionStatus(bool bAlsoCheckForConstraints = true) const;
  DBCONSTRAINTS_PORT SolutionStatus geometryStatus(const GcConstrainedGeometry* pConsGeom) const;
  DBCONSTRAINTS_PORT SolutionStatus constraintStatus(const GcGeomConstraint* pConstraint) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus addConstrainedGeometry(const GcDbFullSubentPath& subentPath, GcConstrainedGeometry*& pConsGeom);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus deleteConstrainedGeometry(const GcDbObjectId& geomDependencyId);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getConstrainedGeometry(const GcDbFullSubentPath& fullSubentPath,
                                                              GcConstrainedGeometry*&   pConsGeom,
                                                              bool bCreateArcLineMid = false);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getConstrainedGeometry(const GcDbAssocGeomDependency* pGeomDependency,
                                                              GcConstrainedGeometry*&   pConsGeom,
                                                              GcDb::ImplicitPointType* pPtType = NULL,
                                                              int defPtIndex = -1,
                                                              bool bCreateArcLineMid = false);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getConstrainedGeometries(GcArray<GcConstrainedGeometry*>& aConstGeom) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus addGeometricalConstraint(GcGeomConstraint::GeomConstraintType type, 
                                                                const GcDbFullSubentPathArray& aPaths,
                                                                GcGeomConstraint** ppNewConstraint  = NULL,
                                                                const GcGeMatrix3d* pUCSCoord = NULL);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus addGeometricalConstraint(GcGeomConstraint::GeomConstraintType type,
                                                                const GcArray<GcConstrainedGeometry*>& apConsGeoms,
                                                                GcGeomConstraint** ppNewConstraint  = NULL,
                                                                const GcGeMatrix3d* pUCSCoord = NULL);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus addDistanceConstraint(GcConstrainedGeometry* pConsGeom1,
                                                             GcConstrainedGeometry* pConsGeom2,
                                                             GcDistanceConstraint::DirectionType directionType,
                                                             GcDbObjectId valueDependencyId,
                                                             GcDbObjectId dimDependencyId,
                                                             const GcGeVector3d* pFixedDirection = NULL,
                                                             const GcConstrainedLine* pDirectionLine = NULL,
                                                             GcDistanceConstraint** ppNewDisConstraint = NULL);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus addAngleConstraint(GcConstrainedLine* pConsLine1,
                                                          GcConstrainedLine* pConsLine2,
                                                          GcAngleConstraint::SectorType sectorType,
                                                          GcDbObjectId valueDependencyId,
                                                          GcDbObjectId dimDependencyId, 
                                                          GcAngleConstraint** ppNewAngConstraint = NULL);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus add3PointAngleConstraint(GcConstrainedPoint* pConsPoint1,
                                                                GcConstrainedPoint* pConsPoint2,
                                                                GcConstrainedPoint* pConsPoint3,
                                                                GcAngleConstraint::SectorType sectorType,
                                                                GcDbObjectId valueDependencyId,
                                                                GcDbObjectId dimDependencyId, 
                                                                Gc3PointAngleConstraint** ppNewAngConstraint = NULL);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus addRadiusDiameterConstraint(GcConstrainedGeometry* pConsGeom,
                                                                   GcRadiusDiameterConstraint::RadiusDiameterConstrType type,
                                                                   GcDbObjectId valueDependencyId,
                                                                   GcDbObjectId dimDependencyId, 
                                                                   GcRadiusDiameterConstraint** ppNewRadDiaConstraint = NULL);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus deleteConstraint(GcGeomConstraint* pGeomConst);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getConstraints(GcArray<GcGeomConstraint*>& apConstraints) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus autoConstrain(const GcDbFullSubentPathArray& aPaths,
                                                     const GcGeTol& tol,
                                                     GcAutoConstrainEvaluationCallback* pCallback);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getAllConnectedGeomDependencies(const GcDbObjectIdArray& srcGeomDependencyIds,
                                                    GcDbObjectIdArray& allConnectedGeomDependencyIds) const;

  DBCONSTRAINTS_PORT GcConstraintGroupNode* getGroupNodePtr(const GcGraphNode::Id nodeId) const;
  DBCONSTRAINTS_PORT void regenDimensionSystem();
  DBCONSTRAINTS_PORT Gcad::ErrorStatus geometryMirrored(GcDbAssocGeomDependency* pGeomDependency);
  
  DBCONSTRAINTS_PORT static void addGlobalCallback(class GcDbAssoc2dConstraintCallback* pCallback);
  DBCONSTRAINTS_PORT static void removeGlobalCallback(class GcDbAssoc2dConstraintCallback* pCallback);
  DBCONSTRAINTS_PORT static class GcDbAssoc2dConstraintCallback* globalCallback();

  DBCONSTRAINTS_PORT static void setDoNotCheckNewlyAddedConstraints(bool doNotCheck);
  DBCONSTRAINTS_PORT static bool doNotCheckNewlyAddedConstraints();
}; 

class GcDbAssoc2dConstraintCallback
{
public:
  GcDbAssoc2dConstraintCallback() {}
  virtual ~GcDbAssoc2dConstraintCallback() {}

  virtual bool canBeRelaxed(const class GcExplicitConstraint* pConstraint)
  {
    UNREFERENCED_PARAMETER(pConstraint);
    return false;
  }

  virtual void constraintDeactivated(const GcExplicitConstraint *pConstraint,
                                     bool bDeactivated = true) {
    UNREFERENCED_PARAMETER(pConstraint);
    UNREFERENCED_PARAMETER(bDeactivated);
  }
};

class GcAutoConstrainEvaluationCallback
{
  friend class GcDbImpAssoc2dConstraintGroup;
  friend class GcAutoConstraintEvalManager;
public:
  DBCONSTRAINTS_PORT virtual ~GcAutoConstrainEvaluationCallback() { }

  DBCONSTRAINTS_PORT virtual void getConstraintPriorityOverride(GcGeomConstraint::GeomConstraintType type,
                                                                const GcArray<const GcConstrainedGeometry*>& geometries, int& priority) const
  {
    UNREFERENCED_PARAMETER(type);
    UNREFERENCED_PARAMETER(geometries);
    UNREFERENCED_PARAMETER(priority);
    return;
  }

  DBCONSTRAINTS_PORT virtual void getAutoConstrainPriority(GcArray<GcGeomConstraint::GeomConstraintType>& constraintList) const
  {
    constraintList.setLogicalLength(0);
    for (int type = (int)GcGeomConstraint::kHorizontal;
      type < (int)GcGeomConstraint::kEqualRadius; ++type)
    {
      constraintList.append((GcGeomConstraint::GeomConstraintType)type);
    }
  }

  DBCONSTRAINTS_PORT virtual bool isEvaluationCancelled() { return false; }

  DBCONSTRAINTS_PORT int getTotalConstraints(GcArray<GcGeomConstraint*>* pConstraints) const;

private:  
  int  getAutoConstraintMask() const;
  void validate(void* pData);
  bool isValidConstraintType(GcGeomConstraint::GeomConstraintType type,
                             const GcGeomConstraint* pConstraint) const;
  void constraintAdded(GcGeomConstraint* pNewCons);
private:
  GcArray<GcGeomConstraint*> mConstraints;
};

#pragma pack (pop)