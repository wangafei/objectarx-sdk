/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEPONC2D_H
#define GC_GEPONC2D_H

#include "gepent2d.h"
#pragma pack (push, 8)

class GcGeCurve2d;

class GE_DLLDATAEXIMP GcGePointOnCurve2d : public GcGePointEnt2d
{
public:
  GcGePointOnCurve2d();
  GcGePointOnCurve2d(const GcGeCurve2d& crv);
  GcGePointOnCurve2d(const GcGeCurve2d& crv, double param);
  GcGePointOnCurve2d(const GcGePointOnCurve2d& src);

  GcGePointOnCurve2d& operator =     (const GcGePointOnCurve2d& src);

  const GcGeCurve2d*  curve() const;
  double              parameter() const;

  GcGePoint2d         point() const;
  GcGePoint2d         point(double param);
  GcGePoint2d         point(const GcGeCurve2d& crv, double param);

  GcGeVector2d        deriv(int order) const;
  GcGeVector2d        deriv(int order, double param);
  GcGeVector2d        deriv(int order, const GcGeCurve2d& crv, double param);
  Gsoft::Boolean      isSingular(const GcGeTol&  tol = GcGeContext::gTol) const;
  Gsoft::Boolean      curvature(double& res);
  Gsoft::Boolean      curvature(double param, double& res);
  GcGePointOnCurve2d& setCurve(const GcGeCurve2d& crv);
  GcGePointOnCurve2d& setParameter(double param);
};

#pragma pack (pop)
#endif
