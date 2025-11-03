/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GESPNT2d_H
#define GC_GESPNT2d_H

#include "gecurv2d.h"
#include "gekvec.h"
#include "gept2dar.h"
#include "gevec2d.h"
#include "gepnt2d.h"
#include "gept2dar.h"
#pragma pack (push, 8)

class GcGeKnotVector;

class GE_DLLDATAEXIMP GcGeSplineEnt2d : public GcGeCurve2d
{
public:
  Gsoft::Boolean        isRational() const;
  int                   degree() const;
  int                   order() const;
  int                   numKnots() const;
  const GcGeKnotVector& knots() const;
  int                   numControlPoints() const;
  int                   continuityAtKnot(int idx, const GcGeTol& tol = GcGeContext::gTol) const;

  double            startParam() const;
  double            endParam() const;
  GcGePoint2d       startPoint() const;
  GcGePoint2d       endPoint() const;

  Gsoft::Boolean    hasFitData() const;

  double            knotAt(int idx) const;
  GcGeSplineEnt2d&  setKnotAt(int idx, double val);

  GcGePoint2d       controlPointAt(int idx) const;
  GcGeSplineEnt2d&  setControlPointAt(int idx, const GcGePoint2d& pnt);

  GcGeSplineEnt2d&  operator =(const GcGeSplineEnt2d& spline);
protected:
  GcGeSplineEnt2d();
  GcGeSplineEnt2d(const GcGeSplineEnt2d&);
};

#pragma pack (pop)
#endif
