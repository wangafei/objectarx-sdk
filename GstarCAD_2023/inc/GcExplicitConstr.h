/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcGeomConstraint.h"
#pragma pack (push, 8)

class GcExplicitConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcExplicitConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcDbObjectId valueDependencyId() const;
  DBCONSTRAINTS_PORT GcDbObjectId dimDependencyId() const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setDimDependencyId(const GcDbObjectId& dimDependencyId);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getMeasuredValue(double&) const;

protected:
  DBCONSTRAINTS_PORT GcExplicitConstraint() {};
};

class GcDistanceConstraint : public GcExplicitConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDistanceConstraint, DBCONSTRAINTS_PORT);

  enum DirectionType
  {
    kNotDirected = 0,
    kFixedDirection,
    kPerpendicularToLine,
    kParallelToLine
  };

  DBCONSTRAINTS_PORT GcDistanceConstraint(bool bCreateImp = true);
  DBCONSTRAINTS_PORT GcDistanceConstraint(const GcGeVector3d& direction);
  DBCONSTRAINTS_PORT GcDistanceConstraint(const GcGraphNode::Id consLineId, DirectionType type = kPerpendicularToLine);

  DBCONSTRAINTS_PORT DirectionType   directionType() const;
  DBCONSTRAINTS_PORT GcGeVector3d    direction()           const;
  DBCONSTRAINTS_PORT GcGraphNode::Id constrainedLineId()   const;
};

class GcAngleConstraint : public GcExplicitConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcAngleConstraint, DBCONSTRAINTS_PORT);

  enum SectorType
  {
    kParallelAntiClockwise = 0,
    kAntiParallelClockwise = 1,
    kParallelClockwise = 2,
    kAntiParallelAntiClockwise = 3,
  };

  DBCONSTRAINTS_PORT GcAngleConstraint(bool bCreateImp = true);
  DBCONSTRAINTS_PORT GcAngleConstraint(GcAngleConstraint::SectorType type);

  DBCONSTRAINTS_PORT SectorType    sectorType() const;
  DBCONSTRAINTS_PORT static void   setAngleMultiplier(double multiplier);
  DBCONSTRAINTS_PORT static double angleMultiplier();
};

class Gc3PointAngleConstraint : public GcAngleConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(Gc3PointAngleConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT Gc3PointAngleConstraint(bool bCreateImp = true);
  DBCONSTRAINTS_PORT Gc3PointAngleConstraint(GcAngleConstraint::SectorType type);
};

class GcRadiusDiameterConstraint : public GcExplicitConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRadiusDiameterConstraint, DBCONSTRAINTS_PORT);

  enum RadiusDiameterConstrType
  {
    kCircleRadius = 0,
    kCircleDiameter,
    kMinorRadius,
    kMajorRadius
  };

  DBCONSTRAINTS_PORT GcRadiusDiameterConstraint(bool bCreateImp = true);
  DBCONSTRAINTS_PORT GcRadiusDiameterConstraint(RadiusDiameterConstrType type);

  DBCONSTRAINTS_PORT RadiusDiameterConstrType constrType() const;
};

#pragma pack (pop)