/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEELL3D_H
#define GC_GEELL3D_H

#include "gecurv3d.h"
#include "gevec3d.h"
#include "gepnt3d.h"
#include "geintrvl.h"
#include "geponc3d.h"
#include "geplane.h"
#pragma pack (push, 8)

class GcGeEllipArc2d;
class GcGeCircArc3d;
class GcGeLineEnt3d;
class GcGePlanarEnt;

class
  GE_DLLDATAEXIMP
  GcGeEllipArc3d : public GcGeCurve3d
{
public:
  GcGeEllipArc3d();
  GcGeEllipArc3d(const GcGeEllipArc3d& ell);
  GcGeEllipArc3d(const GcGeCircArc3d& arc);
  GcGeEllipArc3d(const GcGePoint3d& cent, const GcGeVector3d& majorAxis,
    const GcGeVector3d& minorAxis, double majorRadius,
    double minorRadius);
  GcGeEllipArc3d(const GcGePoint3d& cent, const GcGeVector3d& majorAxis,
    const GcGeVector3d& minorAxis, double majorRadius,
    double minorRadius, double ang1, double ang2);

  GcGePoint3d    closestPointToPlane(const GcGePlanarEnt& plane,
    GcGePoint3d& pointOnPlane,
    const GcGeTol& = GcGeContext::gTol) const;
  Gsoft::Boolean intersectWith(const GcGeLinearEnt3d& line, int& intn,
    GcGePoint3d& p1, GcGePoint3d& p2,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean intersectWith(const GcGePlanarEnt& plane, int& numOfIntersect,
    GcGePoint3d& p1, GcGePoint3d& p2,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean projIntersectWith(const GcGeLinearEnt3d& line,
    const GcGeVector3d& projDir, int &numInt,
    GcGePoint3d& pntOnEllipse1,
    GcGePoint3d& pntOnEllipse2,
    GcGePoint3d& pntOnLine1,
    GcGePoint3d& pntOnLine2,
    const GcGeTol& tol = GcGeContext::gTol) const;
  void           getPlane(GcGePlane& plane) const;
  Gsoft::Boolean isCircular(const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isInside(const GcGePoint3d& pnt,
    const GcGeTol& tol = GcGeContext::gTol) const;
  GcGePoint3d    center() const;
  double         minorRadius() const;
  double         majorRadius() const;
  GcGeVector3d   minorAxis() const;
  GcGeVector3d   majorAxis() const;
  GcGeVector3d   normal() const;
  double         startAng() const;
  double         endAng() const;
  GcGePoint3d    startPoint() const;
  GcGePoint3d    endPoint() const;

  GcGeEllipArc3d& setCenter(const GcGePoint3d& cent);
  GcGeEllipArc3d& setMinorRadius(double rad);
  GcGeEllipArc3d& setMajorRadius(double rad);
  GcGeEllipArc3d& setAxes(const GcGeVector3d& majorAxis, const GcGeVector3d& minorAxis);
  GcGeEllipArc3d& setAngles(double startAngle, double endAngle);
  GcGeEllipArc3d& set(const GcGePoint3d& cent,
    const GcGeVector3d& majorAxis,
    const GcGeVector3d& minorAxis,
    double majorRadius, double minorRadius);
  GcGeEllipArc3d& set(const GcGePoint3d& cent,
    const GcGeVector3d& majorAxis,
    const GcGeVector3d& minorAxis,
    double majorRadius, double minorRadius,
    double startAngle, double endAngle);
  GcGeEllipArc3d& set(const GcGeCircArc3d&);

  GcGeEllipArc3d& operator =    (const GcGeEllipArc3d& ell);
};

#pragma pack (pop)
#endif