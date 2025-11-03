/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocPersSubentIdPE.h"
#include "GcConstraintGroupNode.h"
#include "GcGeomConstraint.h"
#include "genurb3d.h"
#include "gcdb.h"
#pragma pack (push, 8)

class GcConstrainedRigidSet;

class  GcConstrainedGeometry : public GcConstraintGroupNode
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcConstrainedGeometry, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT virtual bool isReadOnly() const;
  DBCONSTRAINTS_PORT GcDbObjectId geomDependencyId() const;
  DBCONSTRAINTS_PORT GcConstrainedRigidSet* getOwningRigidSet() const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getConnectedConstraints(GcArray<GcGeomConstraint*>& apConstraints) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getCommonConstraints(GcConstrainedGeometry* pOtherConsGeom, GcArray<GcGeomConstraint*>& apConstraints) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getConnectedGeometries(GcArray<GcConstrainedGeometry*>& apConsGeoms) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getFullSubentPaths(GcDbFullSubentPathArray& subentPaths) const;

protected:
  DBCONSTRAINTS_PORT GcConstrainedGeometry();
};

class  GcConstrainedPoint : public GcConstrainedGeometry
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcConstrainedPoint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcConstrainedPoint(bool bCreateImp = true);
  DBCONSTRAINTS_PORT          GcConstrainedPoint(GcDbObjectId geomDependencyId);

  DBCONSTRAINTS_PORT virtual GcGePoint3d point() const;
};

class  GcConstrainedImplicitPoint : public GcConstrainedPoint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcConstrainedImplicitPoint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcConstrainedImplicitPoint(bool bCreateImp = true);
  DBCONSTRAINTS_PORT          GcConstrainedImplicitPoint(GcGraphNode::Id constrCurvId, GcDb::ImplicitPointType ptype, int index = -1);

  DBCONSTRAINTS_PORT GcDb::ImplicitPointType pointType()  const;
  DBCONSTRAINTS_PORT int                     pointIndex() const;
  DBCONSTRAINTS_PORT GcGraphNode::Id         constrainedCurveId() const;
  DBCONSTRAINTS_PORT GcGePoint3d             point() const override;
};

class  GcConstrainedCurve : public GcConstrainedGeometry
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcConstrainedCurve, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT virtual bool isBounded() const;
  DBCONSTRAINTS_PORT virtual void getConstrainedImplicitPoints(GcArray<GcConstrainedImplicitPoint*>& apImplicitPoints) const;

protected:
  DBCONSTRAINTS_PORT explicit GcConstrainedCurve() {}
};

class  GcConstrainedLine : public GcConstrainedCurve
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcConstrainedLine, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcConstrainedLine(bool bCreateImp = true);
  DBCONSTRAINTS_PORT          GcConstrainedLine(GcDbObjectId geomDependencyId);

  DBCONSTRAINTS_PORT GcGePoint3d  pointOnLine() const;
  DBCONSTRAINTS_PORT GcGeVector3d direction() const;
};

class  GcConstrainedConstructionLine : public GcConstrainedLine
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcConstrainedConstructionLine, DBCONSTRAINTS_PORT);

protected:
  DBCONSTRAINTS_PORT explicit GcConstrainedConstructionLine();
};

class  GcConstrained2PointsConstructionLine : public GcConstrainedConstructionLine
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcConstrained2PointsConstructionLine, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcConstrained2PointsConstructionLine(bool bCreateImp = true);
  DBCONSTRAINTS_PORT explicit GcConstrained2PointsConstructionLine(const GcGePoint3d& point1, const GcGePoint3d& point2);
};

class  GcConstrainedDatumLine : public GcConstrainedConstructionLine
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcConstrainedDatumLine, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcConstrainedDatumLine(bool bCreateImp = true);
  DBCONSTRAINTS_PORT explicit GcConstrainedDatumLine(const GcGePoint3d& pointOnLine, const GcGeVector3d& direction);
};

class  GcConstrainedBoundedLine : public GcConstrainedLine
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcConstrainedBoundedLine, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcConstrainedBoundedLine(bool bCreateImp = true);
  DBCONSTRAINTS_PORT explicit GcConstrainedBoundedLine(GcDbObjectId geomDependencyId, bool bRay);

  DBCONSTRAINTS_PORT bool        isRay() const;
  DBCONSTRAINTS_PORT GcGePoint3d startPoint() const;
  DBCONSTRAINTS_PORT GcGePoint3d endPoint() const;
  DBCONSTRAINTS_PORT GcGePoint3d midPoint() const;
};

class  GcConstrainedCircle : public GcConstrainedCurve
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcConstrainedCircle, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcConstrainedCircle(bool bCreateImp = true);
  DBCONSTRAINTS_PORT explicit GcConstrainedCircle(GcDbObjectId geomDependencyId);

  DBCONSTRAINTS_PORT double      radius() const;
  DBCONSTRAINTS_PORT GcGePoint3d centerPoint() const;
};

class  GcConstrainedArc : public GcConstrainedCircle
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcConstrainedArc, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcConstrainedArc(bool bCreateImp = true);
  DBCONSTRAINTS_PORT explicit GcConstrainedArc(GcDbObjectId geomDependencyId);

  DBCONSTRAINTS_PORT GcGePoint3d startPoint() const;
  DBCONSTRAINTS_PORT GcGePoint3d endPoint() const;
  DBCONSTRAINTS_PORT GcGePoint3d midPoint() const;
};

class  GcConstrainedEllipse : public GcConstrainedCurve
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcConstrainedEllipse, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcConstrainedEllipse(bool bCreateImp = true);
  DBCONSTRAINTS_PORT explicit GcConstrainedEllipse(GcDbObjectId geomDependencyId);

  DBCONSTRAINTS_PORT GcGeVector3d direction() const;
  DBCONSTRAINTS_PORT double       majorRadius() const;
  DBCONSTRAINTS_PORT double       minorRadius() const;
  DBCONSTRAINTS_PORT GcGePoint3d  centerPoint() const;
};

class  GcConstrainedBoundedEllipse : public GcConstrainedEllipse
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcConstrainedBoundedEllipse, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcConstrainedBoundedEllipse(bool bCreateImp = true);
  DBCONSTRAINTS_PORT explicit GcConstrainedBoundedEllipse(GcDbObjectId geomDependencyId);

  DBCONSTRAINTS_PORT GcGePoint3d startPoint() const;
  DBCONSTRAINTS_PORT GcGePoint3d endPoint() const;
};

class  GcConstrainedSpline : public GcConstrainedCurve
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcConstrainedSpline, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcConstrainedSpline(bool bCreateImp = true);
  DBCONSTRAINTS_PORT explicit GcConstrainedSpline(GcDbObjectId geomDependencyId, const GcGeNurbCurve3d& spline);

  DBCONSTRAINTS_PORT const GcGeNurbCurve3d nurbSpline() const;
  DBCONSTRAINTS_PORT int                   numOfDefinePoints() const;
  DBCONSTRAINTS_PORT GcGePoint3d           definePointAt(int index) const;
};

class  GcConstrainedRigidSet : public GcConstrainedGeometry
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcConstrainedRigidSet, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcConstrainedRigidSet(bool bCreateImp = true);
  DBCONSTRAINTS_PORT explicit GcConstrainedRigidSet(bool bScalable, const GcGeMatrix3d& trans);

  DBCONSTRAINTS_PORT int                      numOfConstrainedGeoms() const;
  DBCONSTRAINTS_PORT GcConstrainedGeometry*   getConstrainedGeomAt(int index) const;
  DBCONSTRAINTS_PORT GcGeMatrix3d             transform() const;
};

struct  GcDbAssocTransInfo
{
  enum TransType
  {
    kGeneral = 0,
    kScaling,
    kRadius,
    kMajorRadius,
    kMinorRadius,
    kFixedRadius,
    kFixed,
    kFixWhenPossible,
    kNone,
  };

  DBCONSTRAINTS_PORT GcDbAssocTransInfo() : mRadius(-1.0), mTransType(kGeneral)
  {}

  TransType mTransType;
  GcGeMatrix3d mTrans;
  double mRadius;
};

struct  GcConstrainedGeometryDraggingInfo : public GcDbAssocTransInfo
{
  GcDbFullSubentPathArray maGeomFullSubentPaths;
  GcArray<GcConstrainedGeometry *> maDraggingGeometries;
  DBCONSTRAINTS_PORT static const GcString& getKey();
};

#pragma pack (pop)