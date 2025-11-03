/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GESPNT3D_H
#define GC_GESPNT3D_H

#include "gecurv3d.h"
#include "gekvec.h"
#include "gept3dar.h"
#include "gevec3d.h"
#include "gepnt3d.h"
#include "gept3dar.h"
#pragma pack (push, 8)

class GcGeKnotVector;

class GE_DLLDATAEXIMP GcGeSplineEnt3d : public GcGeCurve3d
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
  GcGePoint3d       startPoint() const;
  GcGePoint3d       endPoint() const;

  Gsoft::Boolean    hasFitData() const;

  double            knotAt(int idx) const;
  GcGeSplineEnt3d&  setKnotAt(int idx, double val);

  GcGePoint3d       controlPointAt(int idx) const;
  GcGeSplineEnt3d&  setControlPointAt(int idx, const GcGePoint3d& pnt);

  GcGeSplineEnt3d&  operator =            (const GcGeSplineEnt3d& spline);

protected:
  GcGeSplineEnt3d();
  GcGeSplineEnt3d(const GcGeSplineEnt3d&);
};

#pragma pack (pop)
#endif
