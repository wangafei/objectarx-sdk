#pragma once
#include "zAcGeomConstraint.h"
#pragma pack (push, 8)

class ZCDB_PORT ZcExplicitConstraint : public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcExplicitConstraint);
  ZcDbObjectId valueDependencyId() const;
  ZcDbObjectId dimDependencyId() const;
  Zcad::ErrorStatus setDimDependencyId(const ZcDbObjectId& dimDependencyId);
  Zcad::ErrorStatus getMeasuredValue(double&) const;

protected:
  ZcExplicitConstraint(){};
};

class ZCDB_PORT ZcDistanceConstraint: public ZcExplicitConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcDistanceConstraint);

  enum DirectionType
  {
    kNotDirected         = 0,
    kFixedDirection         ,
    kPerpendicularToLine    ,
    kParallelToLine
  };

  ZcDistanceConstraint(bool bCreateImp = true);
  ZcDistanceConstraint(const ZcGeVector3d& direction);
  ZcDistanceConstraint(const ZcGraphNode::Id consLineId, DirectionType type = kPerpendicularToLine);
  DirectionType directionType() const;
  ZcGeVector3d                    direction()           const;
  ZcGraphNode::Id         constrainedLineId()   const;
};

class ZCDB_PORT ZcAngleConstraint: public ZcExplicitConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcAngleConstraint);

  enum SectorType
  {
    kParallelAntiClockwise = 0,
    kAntiParallelClockwise = 1,
    kParallelClockwise = 2,
    kAntiParallelAntiClockwise = 3,
  };

  ZcAngleConstraint(bool bCreateImp = true);
  ZcAngleConstraint(ZcAngleConstraint::SectorType type);
  SectorType sectorType() const;
  static void setAngleMultiplier(double multiplier);
  static double angleMultiplier();
};

class ZCDB_PORT Zc3PointAngleConstraint: public ZcAngleConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(Zc3PointAngleConstraint);
  Zc3PointAngleConstraint(bool bCreateImp = true);
  Zc3PointAngleConstraint(ZcAngleConstraint::SectorType type);
};

class ZCDB_PORT ZcRadiusDiameterConstraint : public ZcExplicitConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcRadiusDiameterConstraint);

  enum RadiusDiameterConstrType
  {
    kCircleRadius   = 0,
    kCircleDiameter    ,
    kMinorRadius       ,
    kMajorRadius
  };

  ZcRadiusDiameterConstraint(bool bCreateImp = true);
  ZcRadiusDiameterConstraint(RadiusDiameterConstrType type);
  RadiusDiameterConstrType constrType() const;
};

#pragma pack (pop)
