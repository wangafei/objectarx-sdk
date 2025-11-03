/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEBNDPLN_H
#define GC_GEBNDPLN_H

#include "geplanar.h"
#include "geplane.h"
#pragma pack (push, 8)

class GcGePlane;
class GcGeVector3d;
class GcGePoint3d;
class GcGePoint2d;
class GcGeLineSeg3d;

class
  GE_DLLDATAEXIMP
  GcGeBoundedPlane : public GcGePlanarEnt
{
public:
  GcGeBoundedPlane();
  GcGeBoundedPlane(const GcGeBoundedPlane& plane);
  GcGeBoundedPlane(const GcGePoint3d& origin, const GcGeVector3d& uVec,
    const GcGeVector3d& vVec);
  GcGeBoundedPlane(const GcGePoint3d& p1, const GcGePoint3d& origin,
    const GcGePoint3d& p2);

  Gsoft::Boolean    intersectWith(const GcGeLinearEnt3d& linEnt, GcGePoint3d& point,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean    intersectWith(const GcGePlane& plane, GcGeLineSeg3d& results,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean    intersectWith(const GcGeBoundedPlane& plane, GcGeLineSeg3d& result,
    const GcGeTol& tol = GcGeContext::gTol) const;

  GcGeBoundedPlane& set(const GcGePoint3d& origin,
    const GcGeVector3d& uVec,
    const GcGeVector3d& vVec);
  GcGeBoundedPlane& set(const GcGePoint3d& p1,
    const GcGePoint3d& origin,
    const GcGePoint3d& p2);
  GcGeBoundedPlane& operator =    (const GcGeBoundedPlane& bplane);
};

#pragma pack (pop)
#endif