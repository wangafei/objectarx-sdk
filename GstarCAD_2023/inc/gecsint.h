/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GECSINT_H
#define GC_GECSINT_H

#include "gsoft.h"
#include "geent3d.h"
#include "geponc3d.h"
#include "geponsrf.h"
#include "geintrvl.h"
#include "gegbl.h"
#include "gegblabb.h"
#pragma pack (push, 8)

class GcGeCurve3d;
class GcGeSurface;

class
  GE_DLLDATAEXIMP
  GcGeCurveSurfInt : public GcGeEntity3d
{
public:
  GcGeCurveSurfInt();
  GcGeCurveSurfInt(const GcGeCurve3d& crv, const GcGeSurface& srf,
    const GcGeTol& tol = GcGeContext::gTol);
  GcGeCurveSurfInt(const GcGeCurveSurfInt& src);

  const GcGeCurve3d  *curve() const;
  const GcGeSurface  *surface() const;
  GcGeTol            tolerance() const;
  int  numIntPoints(GcGeIntersectError& err) const;
  GcGePoint3d  intPoint(int intNum, GcGeIntersectError& err) const;
  void               getIntParams(int intNum,
    double& param1, GcGePoint2d& param2, GcGeIntersectError& err) const;
  void               getPointOnCurve(int intNum, GcGePointOnCurve3d&, GcGeIntersectError& err) const;
  void               getPointOnSurface(int intNum, GcGePointOnSurface&, GcGeIntersectError& err) const;
  void			   getIntConfigs(int intNum, GcGe::csiConfig& lower,
    GcGe::csiConfig& higher, Gsoft::Boolean& smallAngle, GcGeIntersectError& err) const;
  GcGeCurveSurfInt& set(const GcGeCurve3d& cvr,
    const GcGeSurface& srf,
    const GcGeTol& tol = GcGeContext::gTol);

  GcGeCurveSurfInt& operator = (const GcGeCurveSurfInt& crvInt);
};
#pragma pack (pop)
#endif