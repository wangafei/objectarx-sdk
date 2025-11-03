#pragma once
#include "zAcConstrainedGeometry.h"
#include "zAcGeomConstraint.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcPerpendicularConstraint: public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcPerpendicularConstraint);

  ZcPerpendicularConstraint(bool bCreateImp = true);
};

class ZCDBCORE2D_PORT ZcNormalConstraint: public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcNormalConstraint);

  ZcNormalConstraint(bool bCreateImp = true);
};

class ZCDBCORE2D_PORT ZcPointCurveConstraint: public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcPointCurveConstraint);

  ZcPointCurveConstraint(bool bCreateImp = true);
};

class ZCDBCORE2D_PORT ZcColinearConstraint: public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcColinearConstraint);

  ZcColinearConstraint(bool bCreateImp = true);
};

class ZCDBCORE2D_PORT ZcPointCoincidenceConstraint: public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcPointCoincidenceConstraint);

  ZcPointCoincidenceConstraint(bool bCreateImp = true);
};

class ZCDBCORE2D_PORT ZcConcentricConstraint: public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcConcentricConstraint);

  ZcConcentricConstraint(bool bCreateImp = true);
};

class ZCDBCORE2D_PORT ZcCenterPointConstraint: public ZcConcentricConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcCenterPointConstraint);
};

class ZCDBCORE2D_PORT ZcTangentConstraint : public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcTangentConstraint);

  ZcTangentConstraint(bool bCreateImp = true);
};

class ZCDBCORE2D_PORT ZcEqualRadiusConstraint: public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcEqualRadiusConstraint);

  ZcEqualRadiusConstraint(bool bCreateImp = true);
};

class ZCDBCORE2D_PORT ZcEqualDistanceConstraint: public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcEqualDistanceConstraint);

  ZcEqualDistanceConstraint(bool bCreateImp = true);
};

class ZCDBCORE2D_PORT ZcEqualLengthConstraint: public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcEqualLengthConstraint);

  ZcEqualLengthConstraint(bool bCreateImp = true);
};

class ZCDBCORE2D_PORT ZcParallelConstraint: public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcParallelConstraint);

  ZcParallelConstraint(bool bCreateImp = true);
};

class ZCDBCORE2D_PORT ZcHorizontalConstraint: public ZcParallelConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcHorizontalConstraint);

  ZcHorizontalConstraint(bool bCreateImp = true);
};

class ZCDBCORE2D_PORT ZcVerticalConstraint: public ZcParallelConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcVerticalConstraint);

  ZcVerticalConstraint(bool bCreateImp = true);
};

class ZCDBCORE2D_PORT ZcEqualCurvatureConstraint: public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcEqualCurvatureConstraint);

  ZcEqualCurvatureConstraint(bool bCreateImp = true);
};

class ZCDBCORE2D_PORT ZcSymmetricConstraint: public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcSymmetricConstraint);

  ZcSymmetricConstraint(bool bCreateImp = true);
};

class ZCDBCORE2D_PORT ZcMidPointConstraint: public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcMidPointConstraint);

  ZcMidPointConstraint(bool bCreateImp = true);
};

class ZCDBCORE2D_PORT ZcFixedConstraint : public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcFixedConstraint);

  ZcFixedConstraint(bool bCreateImp = true);
};

class ZCDBCORE2D_PORT ZcEqualHelpParameterConstraint : public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcEqualHelpParameterConstraint);

  ZcEqualHelpParameterConstraint(bool bCreateImp = true);

  Zcad::ErrorStatus getEqualHelpParameters(ZcHelpParameter*& pHelpParameter1, ZcHelpParameter*& pHelpParameter2) const;
};

class ZCDBCORE2D_PORT ZcG2SmoothConstraint : public ZcCompositeConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcG2SmoothConstraint);

  ZcG2SmoothConstraint(bool bCreateImp = true);
};

#pragma pack (pop)
