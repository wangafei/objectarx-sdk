/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GECSPL2D_H
#define GC_GECSPL2D_H

class GcGePointOnCurve2d;
class GcGeCurve2dIntersection;
class GcGeInterval;
class GcGePlane;

#include "gesent2d.h"
#include "gept2dar.h"
#include "gevc2dar.h"
#include "gevec2d.h"
#include "gekvec.h"
#pragma pack (push, 8)

class
  GE_DLLDATAEXIMP
  GcGeCubicSplineCurve2d : public GcGeSplineEnt2d
{
public:
  GcGeCubicSplineCurve2d();
  GcGeCubicSplineCurve2d(const GcGeCubicSplineCurve2d& spline);
  GcGeCubicSplineCurve2d(const GcGePoint2dArray& fitPnts,
    const GcGeTol& tol = GcGeContext::gTol);
  GcGeCubicSplineCurve2d(const GcGePoint2dArray& fitPnts,
    const GcGeVector2d& startDeriv,
    const GcGeVector2d& endDeriv,
    const GcGeTol& tol = GcGeContext::gTol);
  GcGeCubicSplineCurve2d(const GcGeCurve2d& curve,
    double epsilon = GcGeContext::gTol.equalPoint());
  GcGeCubicSplineCurve2d(const GcGeKnotVector& knots,
    const GcGePoint2dArray& fitPnts,
    const GcGeVector2dArray& firstDerivs,
    Gsoft::Boolean isPeriodic = Gsoft::kFalse);

  int                     numFitPoints()        const;
  GcGePoint2d             fitPointAt(int idx) const;
  GcGeCubicSplineCurve2d& setFitPointAt(int idx, const GcGePoint2d& point);
  GcGeVector2d            firstDerivAt(int idx) const;
  GcGeCubicSplineCurve2d& setFirstDerivAt(int idx, const GcGeVector2d& deriv);

  GcGeCubicSplineCurve2d&  operator = (const GcGeCubicSplineCurve2d& spline);
};

#pragma pack (pop)
#endif