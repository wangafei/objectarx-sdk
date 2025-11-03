/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEARC3D_H
#define GC_GEARC3D_H

#include "gecurv3d.h"
#include "gevec3d.h"
#include "gepnt3d.h"
#include "geplane.h"
#include "gegblabb.h"
#pragma pack (push, 8)
class GcGeLine3d;
class GcGeCircArc2d;
class GcGePlanarEnt;

class
  GE_DLLDATAEXIMP
  GcGeCircArc3d : public GcGeCurve3d
{
public:
  GcGeCircArc3d();
  GcGeCircArc3d(const GcGeCircArc3d& arc);
  GcGeCircArc3d(const GcGePoint3d& cent,
    const GcGeVector3d& nrm, double radius);
  GcGeCircArc3d(const GcGePoint3d& cent, const GcGeVector3d& nrm,
    const GcGeVector3d& refVec, double radius,
    double startAngle, double endAngle);
  GcGeCircArc3d(const GcGePoint3d& startPoint, const GcGePoint3d& pnt, const GcGePoint3d& endPoint);

  GcGePoint3d    closestPointToPlane(const GcGePlanarEnt& plane,
    GcGePoint3d& pointOnPlane,
    const GcGeTol& tol
    = GcGeContext::gTol) const;
  Gsoft::Boolean intersectWith(const GcGeLinearEnt3d& line, int& intn,
    GcGePoint3d& p1, GcGePoint3d& p2,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean intersectWith(const GcGeCircArc3d& arc, int& intn,
    GcGePoint3d& p1, GcGePoint3d& p2,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean  intersectWith(const GcGePlanarEnt& plane, int& numOfIntersect,
    GcGePoint3d& p1, GcGePoint3d& p2,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean projIntersectWith(const GcGeLinearEnt3d& line,
    const GcGeVector3d& projDir, int& numInt,
    GcGePoint3d& pntOnArc1,
    GcGePoint3d& pntOnArc2,
    GcGePoint3d& pntOnLine1,
    GcGePoint3d& pntOnLine2,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean tangent(const GcGePoint3d& pnt, GcGeLine3d& line,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean tangent(const GcGePoint3d& pnt, GcGeLine3d& line,
    const GcGeTol& tol, GcGeError& error) const;
  void           getPlane(GcGePlane& plane) const;
  Gsoft::Boolean isInside(const GcGePoint3d& pnt,
    const GcGeTol& tol = GcGeContext::gTol) const;

  GcGePoint3d    center() const;
  GcGeVector3d   normal() const;
  GcGeVector3d   refVec() const;
  double         radius() const;
  double         startAng() const;
  double         endAng() const;
  GcGePoint3d    startPoint() const;
  GcGePoint3d    endPoint() const;

  GcGeCircArc3d& setCenter(const GcGePoint3d&);
  GcGeCircArc3d& setAxes(const GcGeVector3d& normal,
    const GcGeVector3d& refVec);
  GcGeCircArc3d& setRadius(double);
  GcGeCircArc3d& setAngles(double startAngle, double endAngle);

  GcGeCircArc3d& set(const GcGePoint3d& cent,
    const GcGeVector3d& nrm, double radius);
  GcGeCircArc3d& set(const GcGePoint3d& cent,
    const GcGeVector3d& nrm,
    const GcGeVector3d& refVec, double radius,
    double startAngle, double endAngle);
  GcGeCircArc3d& set(const GcGePoint3d& startPoint, const GcGePoint3d& pnt,
    const GcGePoint3d& endPoint);
  GcGeCircArc3d& set(const GcGePoint3d& startPoint, const GcGePoint3d& pnt,
    const GcGePoint3d& endPoint, GcGeError& error);
  GcGeCircArc3d& set(const GcGeCurve3d& curve1,
    const GcGeCurve3d& curve2,
    double radius, double& param1, double& param2,
    Gsoft::Boolean& success);
  GcGeCircArc3d& set(const GcGeCurve3d& curve1,
    const GcGeCurve3d& curve2,
    const GcGeCurve3d& curve3,
    double& param1, double& param2, double& param3,
    Gsoft::Boolean& success);

  GcGeCircArc3d& operator =     (const GcGeCircArc3d& arc);
};

#pragma pack (pop)
#endif