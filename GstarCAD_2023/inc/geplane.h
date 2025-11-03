/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEPLANE_H
#define GC_GEPLANE_H

#include "geplanar.h"
#pragma pack (push, 8)

class GcGeBoundedPlane;
class GcGeLine3d;

class GE_DLLDATAEXIMP GcGePlane : public GcGePlanarEnt
{
public:
  static const GcGePlane kXYPlane;
  static const GcGePlane kYZPlane;
  static const GcGePlane kZXPlane;

  GcGePlane();
  GcGePlane(const GcGePlane& src);
  GcGePlane(const GcGePoint3d& origin, const GcGeVector3d& normal);
  GcGePlane(const GcGePoint3d& pntU, const GcGePoint3d& org, const GcGePoint3d& pntV);
  GcGePlane(const GcGePoint3d& org, const GcGeVector3d& uAxis, const GcGeVector3d& vAxis);
  GcGePlane(double a, double b, double c, double d);

  double         signedDistanceTo(const GcGePoint3d& pnt) const;

  Gsoft::Boolean intersectWith(const GcGeLinearEnt3d& linEnt,
                                               GcGePoint3d&           resultPnt,
                                               const GcGeTol&         tol = GcGeContext::gTol) const;
  Gsoft::Boolean intersectWith(const GcGePlane& otherPln,
                                               GcGeLine3d&      resultLine,
                                               const GcGeTol&   tol = GcGeContext::gTol) const;
  Gsoft::Boolean intersectWith(const GcGeBoundedPlane& bndPln,
                                               GcGeLineSeg3d&          resultLineSeg,
                                               const GcGeTol&          tol = GcGeContext::gTol) const;

  GcGePlane&     set(const GcGePoint3d& pnt, const GcGeVector3d& normal);
  GcGePlane&     set(const GcGePoint3d& pntU, const GcGePoint3d& org, const GcGePoint3d& pntV);
  GcGePlane&     set(double a, double b, double c, double d);
  GcGePlane&     set(const GcGePoint3d& org, const GcGeVector3d& uAxis, const GcGeVector3d& vAxis);
  GcGePlane&     operator =       (const GcGePlane& src);
};

#pragma pack (pop)
#endif
