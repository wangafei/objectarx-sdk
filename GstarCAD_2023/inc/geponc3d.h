/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEPONC3D_H
#define GC_GEPONC3D_H

#include "gepent3d.h"
#pragma pack (push, 8)

class GcGeCurve3d;

class GE_DLLDATAEXIMP GcGePointOnCurve3d : public GcGePointEnt3d
{
public:
  GcGePointOnCurve3d();
  GcGePointOnCurve3d(const GcGeCurve3d& crv);
  GcGePointOnCurve3d(const GcGeCurve3d& crv, double param);
  GcGePointOnCurve3d(const GcGePointOnCurve3d& src);

  GcGePointOnCurve3d& operator =     (const GcGePointOnCurve3d& src);

  const GcGeCurve3d*  curve() const;
  double              parameter() const;

  GcGePoint3d         point() const;
  GcGePoint3d         point(double param);
  GcGePoint3d         point(const GcGeCurve3d& crv, double param);

  GcGeVector3d        deriv(int order) const;
  GcGeVector3d        deriv(int order, double param);
  GcGeVector3d        deriv(int order, const GcGeCurve3d& crv, double param);
  Gsoft::Boolean      isSingular(const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean      curvature(double& res);
  Gsoft::Boolean      curvature(double param, double& res);

  GcGePointOnCurve3d& setCurve(const GcGeCurve3d& crv);
  GcGePointOnCurve3d& setParameter(double param);
};

#pragma pack (pop)
#endif
