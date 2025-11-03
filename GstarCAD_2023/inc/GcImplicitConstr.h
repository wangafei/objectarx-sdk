/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcConstrainedGeometry.h"
#include "GcGeomConstraint.h"
#pragma pack (push, 8)

class  GcPerpendicularConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcPerpendicularConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcPerpendicularConstraint(bool bCreateImp = true);
};

class  GcNormalConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcNormalConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcNormalConstraint(bool bCreateImp = true);
};

class  GcPointCurveConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcPointCurveConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcPointCurveConstraint(bool bCreateImp = true);
};

class  GcColinearConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcColinearConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcColinearConstraint(bool bCreateImp = true);
};

class  GcPointCoincidenceConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcPointCoincidenceConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcPointCoincidenceConstraint(bool bCreateImp = true);
};

class  GcConcentricConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcConcentricConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcConcentricConstraint(bool bCreateImp = true);
};

class  GcCenterPointConstraint : public GcConcentricConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcCenterPointConstraint, DBCONSTRAINTS_PORT);
};

class  GcTangentConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcTangentConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcTangentConstraint(bool bCreateImp = true);
};

class  GcEqualRadiusConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcEqualRadiusConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcEqualRadiusConstraint(bool bCreateImp = true);
};

class  GcEqualDistanceConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcEqualDistanceConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcEqualDistanceConstraint(bool bCreateImp = true);
};

class  GcEqualLengthConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcEqualLengthConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcEqualLengthConstraint(bool bCreateImp = true);
};

class  GcParallelConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcParallelConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcParallelConstraint(bool bCreateImp = true);
};

class  GcHorizontalConstraint : public GcParallelConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcHorizontalConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcHorizontalConstraint(bool bCreateImp = true);
};

class  GcVerticalConstraint : public GcParallelConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcVerticalConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcVerticalConstraint(bool bCreateImp = true);
};

class  GcEqualCurvatureConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcEqualCurvatureConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcEqualCurvatureConstraint(bool bCreateImp = true);
};


class  GcSymmetricConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcSymmetricConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcSymmetricConstraint(bool bCreateImp = true);
};

class  GcMidPointConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcMidPointConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcMidPointConstraint(bool bCreateImp = true);
};

class  GcFixedConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcFixedConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcFixedConstraint(bool bCreateImp = true);
};

class  GcEqualHelpParameterConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcEqualHelpParameterConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcEqualHelpParameterConstraint(bool bCreateImp = true);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getEqualHelpParameters(GcHelpParameter*& pHelpParameter1, GcHelpParameter*& pHelpParameter2) const;
};

class  GcG2SmoothConstraint : public GcCompositeConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcG2SmoothConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcG2SmoothConstraint(bool bCreateImp = true);
};

#pragma pack (pop)