/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEPLANAR_H
#define GC_GEPLANAR_H

#include "gesurf.h"
#include "gevec3d.h"
#pragma pack (push, 8)

class GcGeLineSeg3d;
class GcGeLinearEnt3d;
class GcGeCircArc3d;

class GE_DLLDATAEXIMP GcGePlanarEnt : public GcGeSurface
{
public:
  Gsoft::Boolean  intersectWith(const GcGeLinearEnt3d& linEnt,
                                                GcGePoint3d&           pnt,
                                                const GcGeTol&         tol = GcGeContext::gTol) const;

  GcGePoint3d     closestPointToLinearEnt(const GcGeLinearEnt3d& line,
                                                          GcGePoint3d&           pointOnLine,
                                                          const GcGeTol&         tol = GcGeContext::gTol) const;
  GcGePoint3d     closestPointToPlanarEnt(const GcGePlanarEnt& otherPln,
                                                          GcGePoint3d&         pointOnOtherPln,
                                                          const GcGeTol&       tol = GcGeContext::gTol) const;

  Gsoft::Boolean isParallelTo(const GcGeLinearEnt3d& linEnt,
                                              const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isParallelTo(const GcGePlanarEnt& otherPlnEnt,
                                              const GcGeTol& tol = GcGeContext::gTol) const;

  Gsoft::Boolean isPerpendicularTo(const GcGeLinearEnt3d& linEnt,
                                                   const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isPerpendicularTo(const GcGePlanarEnt& linEnt,
                                                   const GcGeTol& tol = GcGeContext::gTol) const;

  Gsoft::Boolean isCoplanarTo(const GcGePlanarEnt& otherPlnEnt,
                                              const GcGeTol& tol = GcGeContext::gTol) const;

  void           get(GcGePoint3d&, GcGeVector3d& uVec, GcGeVector3d& vVec) const;
  void           get(GcGePoint3d&, GcGePoint3d& origin, GcGePoint3d&) const;

  GcGePoint3d    pointOnPlane() const;
  GcGeVector3d   normal() const;
  void           getCoefficients(double& a, double& b, double& c, double& d) const;
  void           getCoordSystem(GcGePoint3d& origin, GcGeVector3d& axis1, GcGeVector3d& axis2) const;
  GcGePlanarEnt& operator =        (const GcGePlanarEnt& src);

protected:
  GcGePlanarEnt();
  GcGePlanarEnt(const GcGePlanarEnt&);
};

#pragma pack (pop)
#endif
