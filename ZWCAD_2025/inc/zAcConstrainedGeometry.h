#pragma once

#include "zAcDbAssocPersSubentIdPE.h"
#include "zAcConstraintGroupNode.h"
#include "zAcGeomConstraint.h"
#include "zgenurb3d.h"
#include "zacdb.h"
#pragma pack (push, 8)

class ZcConstrainedRigidSet;

class ZCDB_PORT ZcConstrainedGeometry :  public ZcConstraintGroupNode
{
public:
  ZCRX_DECLARE_MEMBERS(ZcConstrainedGeometry);
  
  virtual bool isReadOnly() const; 
  ZcDbObjectId geomDependencyId() const;
  ZcConstrainedRigidSet* getOwningRigidSet() const;
  Zcad::ErrorStatus getConnectedConstraints(ZcArray<ZcGeomConstraint*>& apConstraints) const;
  Zcad::ErrorStatus getCommonConstraints(ZcConstrainedGeometry* pOtherConsGeom, ZcArray<ZcGeomConstraint*>& apConstraints) const;
  Zcad::ErrorStatus getConnectedGeometries(ZcArray<ZcConstrainedGeometry*>& apConsGeoms) const;
  Zcad::ErrorStatus getFullSubentPaths(ZcDbFullSubentPathArray& subentPaths) const;

protected:

  ZcConstrainedGeometry();
};

class ZCDB_PORT ZcConstrainedPoint: public ZcConstrainedGeometry
{
public:
  ZCRX_DECLARE_MEMBERS(ZcConstrainedPoint);
  explicit ZcConstrainedPoint(bool bCreateImp = true);
  ZcConstrainedPoint(ZcDbObjectId geomDependencyId);
  virtual ZcGePoint3d point() const ;
};

class ZCDB_PORT ZcConstrainedImplicitPoint: public ZcConstrainedPoint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcConstrainedImplicitPoint);
  explicit ZcConstrainedImplicitPoint(bool bCreateImp = true);
  ZcConstrainedImplicitPoint(ZcGraphNode::Id constrCurvId, ZcDb::ImplicitPointType ptype, int index = -1);
  ZcDb::ImplicitPointType       pointType()  const;
  int                     pointIndex() const;
  ZcGraphNode::Id constrainedCurveId() const;
  virtual ZcGePoint3d point() const override;
};

class ZCDB_PORT ZcConstrainedCurve :  public ZcConstrainedGeometry
{
public:
  ZCRX_DECLARE_MEMBERS(ZcConstrainedCurve);
  virtual bool isBounded() const;
  virtual void getConstrainedImplicitPoints(ZcArray<ZcConstrainedImplicitPoint*>& apImplicitPoints) const;
protected:
  explicit ZcConstrainedCurve(){}
};

class ZCDB_PORT ZcConstrainedLine: public ZcConstrainedCurve
{
public:
  ZCRX_DECLARE_MEMBERS(ZcConstrainedLine);
  explicit ZcConstrainedLine(bool bCreateImp = true);
  ZcConstrainedLine(ZcDbObjectId geomDependencyId);
  ZcGePoint3d pointOnLine() const;
  ZcGeVector3d direction() const;
};

class ZCDB_PORT ZcConstrainedConstructionLine: public ZcConstrainedLine
{
public:
  ZCRX_DECLARE_MEMBERS(ZcConstrainedConstructionLine);

protected:

  explicit ZcConstrainedConstructionLine();
};

class ZCDB_PORT ZcConstrained2PointsConstructionLine: public ZcConstrainedConstructionLine
{
public:
  ZCRX_DECLARE_MEMBERS(ZcConstrained2PointsConstructionLine);
  explicit ZcConstrained2PointsConstructionLine(bool bCreateImp = true);
  explicit ZcConstrained2PointsConstructionLine(const ZcGePoint3d& point1, const ZcGePoint3d& point2);
};

class ZCDB_PORT ZcConstrainedDatumLine: public ZcConstrainedConstructionLine
{
public:
  ZCRX_DECLARE_MEMBERS(ZcConstrainedDatumLine);
  explicit ZcConstrainedDatumLine(bool bCreateImp = true);
  explicit ZcConstrainedDatumLine(const ZcGePoint3d& pointOnLine, const ZcGeVector3d& direction);
};

class ZCDB_PORT ZcConstrainedBoundedLine: public ZcConstrainedLine
{
public:
  ZCRX_DECLARE_MEMBERS(ZcConstrainedBoundedLine);
  explicit ZcConstrainedBoundedLine(bool bCreateImp = true);
  explicit ZcConstrainedBoundedLine(ZcDbObjectId geomDependencyId, bool bRay);
  bool isRay() const;
  ZcGePoint3d startPoint() const;
  ZcGePoint3d endPoint() const;
  ZcGePoint3d midPoint() const;
};

class ZCDB_PORT ZcConstrainedCircle: public ZcConstrainedCurve
{
public:
  ZCRX_DECLARE_MEMBERS(ZcConstrainedCircle);
  explicit ZcConstrainedCircle(bool bCreateImp = true);
  explicit ZcConstrainedCircle(ZcDbObjectId geomDependencyId);
  double radius() const;
  ZcGePoint3d centerPoint() const;
};

class ZCDB_PORT ZcConstrainedArc: public ZcConstrainedCircle
{
public:
  ZCRX_DECLARE_MEMBERS(ZcConstrainedArc);
  explicit ZcConstrainedArc(bool bCreateImp = true);
  explicit ZcConstrainedArc(ZcDbObjectId geomDependencyId);
  ZcGePoint3d startPoint() const;
  ZcGePoint3d endPoint() const;
  ZcGePoint3d midPoint() const;
};

class ZCDB_PORT ZcConstrainedEllipse: public ZcConstrainedCurve
{
public:
  ZCRX_DECLARE_MEMBERS(ZcConstrainedEllipse);
  explicit ZcConstrainedEllipse(bool bCreateImp = true);
  explicit ZcConstrainedEllipse(ZcDbObjectId geomDependencyId);
  ZcGeVector3d direction() const;
  double majorRadius() const;
  double minorRadius() const;
  ZcGePoint3d centerPoint() const;
};

class ZCDB_PORT ZcConstrainedBoundedEllipse : public ZcConstrainedEllipse
{
public:
  ZCRX_DECLARE_MEMBERS(ZcConstrainedBoundedEllipse);
  explicit ZcConstrainedBoundedEllipse(bool bCreateImp = true);
  explicit ZcConstrainedBoundedEllipse(ZcDbObjectId geomDependencyId);
  ZcGePoint3d startPoint() const;
  ZcGePoint3d endPoint() const;
};

class ZCDB_PORT ZcConstrainedSpline: public ZcConstrainedCurve
{
public:
  ZCRX_DECLARE_MEMBERS(ZcConstrainedSpline);
  explicit ZcConstrainedSpline(bool bCreateImp = true);
  explicit ZcConstrainedSpline(ZcDbObjectId geomDependencyId, const ZcGeNurbCurve3d& spline);
  const ZcGeNurbCurve3d nurbSpline() const;
  int numOfDefinePoints() const;
  ZcGePoint3d definePointAt(int index) const;
};

class ZCDB_PORT ZcConstrainedRigidSet : public ZcConstrainedGeometry
{
public:
  ZCRX_DECLARE_MEMBERS(ZcConstrainedRigidSet);
  explicit ZcConstrainedRigidSet(bool bCreateImp = true);
  explicit ZcConstrainedRigidSet(bool bScalable, const ZcGeMatrix3d& trans);
  int                      numOfConstrainedGeoms() const;
  ZcConstrainedGeometry*   getConstrainedGeomAt(int index) const;
  ZcGeMatrix3d             transform() const;
};

struct ZCDB_PORT ZcDbAssocTransInfo
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

    ZcDbAssocTransInfo() : mRadius(-1.0), mTransType(kGeneral) {}

    TransType mTransType;
    ZcGeMatrix3d mTrans;
    double mRadius;
};

struct ZCDB_PORT ZcConstrainedGeometryDraggingInfo : public ZcDbAssocTransInfo
{
    ZcDbFullSubentPathArray maGeomFullSubentPaths;
    ZcArray<ZcConstrainedGeometry *> maDraggingGeometries;
    static const ZcString& getKey();
};

#pragma pack (pop)
