/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GELENT2D_H
#define GC_GELENT2D_H

#include "gecurv2d.h"
#include "gepnt2d.h"
#include "gevec2d.h"
#pragma pack (push, 8)

class GcGeCircArc2d;

class GE_DLLDATAEXIMP GcGeLinearEnt2d : public GcGeCurve2d
{
public:
  Gsoft::Boolean   intersectWith(const GcGeLinearEnt2d& line,
                                                 GcGePoint2d&           intPnt,
                                                 const GcGeTol&         tol = GcGeContext::gTol) const;

  Gsoft::Boolean   overlap(const GcGeLinearEnt2d& line,
                                           GcGeLinearEnt2d*&      overlap,
                                           const GcGeTol&         tol = GcGeContext::gTol) const;
  Gsoft::Boolean   isParallelTo(const GcGeLinearEnt2d& line,
                                                const GcGeTol&         tol = GcGeContext::gTol) const;
  Gsoft::Boolean   isPerpendicularTo(const GcGeLinearEnt2d& line,
                                                     const GcGeTol&         tol = GcGeContext::gTol) const;
  Gsoft::Boolean   isColinearTo(const GcGeLinearEnt2d& line,
                                                const GcGeTol&         tol = GcGeContext::gTol) const;
  void             getPerpLine(const GcGePoint2d& pnt, GcGeLine2d& perpLine) const;

  GcGePoint2d      pointOnLine() const;
  GcGeVector2d     direction() const;
  void             getLine(GcGeLine2d& line) const;

  GcGeLinearEnt2d& operator =     (const GcGeLinearEnt2d& line);

protected:
  GcGeLinearEnt2d();
  GcGeLinearEnt2d(const GcGeLinearEnt2d&);
};

#pragma pack (pop)
#endif
