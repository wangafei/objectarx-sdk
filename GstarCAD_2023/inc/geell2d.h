/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEELL2D_H
#define GC_GEELL2D_H

#include "gecurv2d.h"
#include "gevec2d.h"
#include "gepnt2d.h"
#include "geponc2d.h"
#include "geintrvl.h"
#pragma pack (push, 8)

class GcGeCircArc2d;
class GcGePlanarEnt;
class GcGeEllipArc2d;
class GcGeLinearEnt2d;

class
  GE_DLLDATAEXIMP
  GcGeEllipArc2d : public GcGeCurve2d
{
public:
  GcGeEllipArc2d();
  GcGeEllipArc2d(const GcGeEllipArc2d& ell);
  GcGeEllipArc2d(const GcGeCircArc2d& arc);
  GcGeEllipArc2d(const GcGePoint2d& cent, const GcGeVector2d& majorAxis,
    const GcGeVector2d& minorAxis, double majorRadius,
    double minorRadius);
  GcGeEllipArc2d(const GcGePoint2d& cent, const GcGeVector2d& majorAxis,
    const GcGeVector2d& minorAxis, double majorRadius,
    double minorRadius, double startAngle, double endAngle);

  Gsoft::Boolean intersectWith(const GcGeLinearEnt2d& line, int& intn,
    GcGePoint2d& p1, GcGePoint2d& p2,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isCircular(const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isInside(const GcGePoint2d& pnt,
    const GcGeTol& tol = GcGeContext::gTol) const;
  GcGePoint2d    center() const;
  double         minorRadius() const;
  double         majorRadius() const;
  GcGeVector2d   minorAxis() const;
  GcGeVector2d   majorAxis() const;
  double         startAng() const;
  double         endAng() const;
  GcGePoint2d    startPoint() const;
  GcGePoint2d    endPoint() const;
  Gsoft::Boolean isClockWise() const;
  GcGeEllipArc2d& setCenter(const GcGePoint2d& cent);
  GcGeEllipArc2d& setMinorRadius(double rad);
  GcGeEllipArc2d& setMajorRadius(double rad);
  GcGeEllipArc2d& setAxes(const GcGeVector2d& majorAxis, const GcGeVector2d& minorAxis);
  GcGeEllipArc2d& setAngles(double startAngle, double endAngle);
  GcGeEllipArc2d& set(const GcGePoint2d& cent,
    const GcGeVector2d& majorAxis,
    const GcGeVector2d& minorAxis,
    double majorRadius, double minorRadius);
  GcGeEllipArc2d& set(const GcGePoint2d& cent,
    const GcGeVector2d& majorAxis,
    const GcGeVector2d& minorAxis,
    double majorRadius, double minorRadius,
    double startAngle, double endAngle);
  GcGeEllipArc2d& set(const GcGeCircArc2d& arc);

  GcGeEllipArc2d& operator =    (const GcGeEllipArc2d& ell);
};

#pragma pack (pop)
#endif
