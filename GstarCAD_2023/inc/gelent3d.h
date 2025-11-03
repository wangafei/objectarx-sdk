/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GELENT3D_H
#define GC_GELENT3D_H

#include "gecurv3d.h"
#include "gevec3d.h"
#include "gepnt3d.h"
#pragma pack (push, 8)

class GcGeLine3d;
class GcGeCircArc3d;
class GcGePlanarEnt;
class GE_DLLDATAEXIMP GcGeLinearEnt3d : public GcGeCurve3d
{
public:
  Gsoft::Boolean intersectWith(const GcGeLinearEnt3d& line,
                                               GcGePoint3d&           intPt,
                                               const GcGeTol&         tol = GcGeContext::gTol) const;
  Gsoft::Boolean intersectWith(const GcGePlanarEnt& plane,
                                               GcGePoint3d&         intPnt,
                                               const GcGeTol&       tol = GcGeContext::gTol) const;

  Gsoft::Boolean projIntersectWith(const GcGeLinearEnt3d& line,
                                                   const GcGeVector3d&    projDir,
                                                   GcGePoint3d&           pntOnThisLine,
                                                   GcGePoint3d&           pntOnOtherLine,
                                                   const GcGeTol&         tol = GcGeContext::gTol) const;

  Gsoft::Boolean overlap(const GcGeLinearEnt3d& line,
                                         GcGeLinearEnt3d*&      overlap,
                                         const GcGeTol&         tol = GcGeContext::gTol) const;

  Gsoft::Boolean isOn(const GcGePoint3d& pnt,
                                      const GcGeTol&     tol = GcGeContext::gTol) const;
  Gsoft::Boolean isOn(const GcGePoint3d& pnt,
                                      double&            param,
                                      const GcGeTol&     tol = GcGeContext::gTol) const;
  Gsoft::Boolean isOn(double         param,
                                      const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isOn(const GcGePlane& plane,
                                      const GcGeTol&   tol = GcGeContext::gTol) const;

  Gsoft::Boolean isParallelTo(const GcGeLinearEnt3d& line,
                                              const GcGeTol&         tol = GcGeContext::gTol) const;
  Gsoft::Boolean isParallelTo(const GcGePlanarEnt& plane,
                                              const GcGeTol&       tol = GcGeContext::gTol) const;
  Gsoft::Boolean isPerpendicularTo(const GcGeLinearEnt3d& line,
                                                   const GcGeTol&         tol = GcGeContext::gTol) const;
  Gsoft::Boolean isPerpendicularTo(const GcGePlanarEnt& plane,
                                                   const GcGeTol&       tol = GcGeContext::gTol) const;
  Gsoft::Boolean isColinearTo(const GcGeLinearEnt3d& line,
                                              const GcGeTol&         tol = GcGeContext::gTol) const;

  void           getPerpPlane(const GcGePoint3d& pnt, GcGePlane& plane) const;

  GcGePoint3d    pointOnLine() const;
  GcGeVector3d   direction() const;
  void           getLine(GcGeLine3d&) const;

  GcGeLinearEnt3d& operator =  (const GcGeLinearEnt3d& line);

protected:
  GcGeLinearEnt3d();
  GcGeLinearEnt3d(const GcGeLinearEnt3d&);
};

#pragma pack (pop)
#endif
