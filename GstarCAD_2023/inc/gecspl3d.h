/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GECSPL3D_H
#define GC_GECSPL3D_H

class GcGePointOnCurve3d;
class GcGeCurve3dIntersection;
class GcGeInterval;
class GcGePlane;

#include "gesent3d.h"
#include "gept3dar.h"
#include "gevc3dar.h"
#include "gevec3d.h"
#include "gekvec.h"
#pragma pack (push, 8)

class
  GE_DLLDATAEXIMP
  GcGeCubicSplineCurve3d : public GcGeSplineEnt3d
{
public:
  GcGeCubicSplineCurve3d();
  GcGeCubicSplineCurve3d(const GcGeCubicSplineCurve3d& spline);
  GcGeCubicSplineCurve3d(const GcGePoint3dArray& fitPnts,
    const GcGeTol& tol = GcGeContext::gTol);
  GcGeCubicSplineCurve3d(const GcGePoint3dArray& fitPnts,
    const GcGeVector3d& startDeriv,
    const GcGeVector3d& endDeriv,
    const GcGeTol& tol = GcGeContext::gTol);
  GcGeCubicSplineCurve3d(const GcGeCurve3d& curve,
    double epsilon = GcGeContext::gTol.equalPoint());
  GcGeCubicSplineCurve3d(const GcGeKnotVector& knots,
    const GcGePoint3dArray& fitPnts,
    const GcGeVector3dArray& firstDerivs,
    Gsoft::Boolean isPeriodic = Gsoft::kFalse);

  int                     numFitPoints()        const;
  GcGePoint3d             fitPointAt(int idx) const;
  GcGeCubicSplineCurve3d& setFitPointAt(int idx, const GcGePoint3d& point);
  GcGeVector3d            firstDerivAt(int idx) const;
  GcGeCubicSplineCurve3d& setFirstDerivAt(int idx, const GcGeVector3d& deriv);

  GcGeCubicSplineCurve3d&  operator = (const GcGeCubicSplineCurve3d& spline);
};

#pragma pack (pop)
#endif