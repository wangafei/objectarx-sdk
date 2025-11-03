/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEARC2D_H
#define GC_GEARC2D_H

#include "gecurv2d.h"
#include "gepnt2d.h"
#include "gevec2d.h"
#pragma pack (push, 8)

class GcGeLine2d;
class GcGeLinearEnt2d;

class
  GE_DLLDATAEXIMP
  GcGeCircArc2d : public GcGeCurve2d
{
public:
  GcGeCircArc2d();
  GcGeCircArc2d(const GcGeCircArc2d& arc);
  GcGeCircArc2d(const GcGePoint2d& cent, double radius);
  GcGeCircArc2d(const GcGePoint2d& cent, double radius,
    double startAngle, double endAngle,
    const GcGeVector2d& refVec = GcGeVector2d::kXAxis,
    Gsoft::Boolean isClockWise = Gsoft::kFalse);
  GcGeCircArc2d(const GcGePoint2d& startPoint, const GcGePoint2d& point,
    const GcGePoint2d& endPoint);
  GcGeCircArc2d(const GcGePoint2d& startPoint, const GcGePoint2d& endPoint, double bulge,
    Gsoft::Boolean bulgeFlag = Gsoft::kTrue);

  Gsoft::Boolean intersectWith(const GcGeLinearEnt2d& line, int& intn,
    GcGePoint2d& p1, GcGePoint2d& p2,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean intersectWith(const GcGeCircArc2d& arc, int& intn,
    GcGePoint2d& p1, GcGePoint2d& p2,
    const GcGeTol& tol = GcGeContext::gTol) const;

  Gsoft::Boolean tangent(const GcGePoint2d& pnt, GcGeLine2d& line,
    const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean tangent(const GcGePoint2d& pnt, GcGeLine2d& line,
    const GcGeTol& tol, GcGeError& error) const;

  Gsoft::Boolean isInside(const GcGePoint2d& pnt,
    const GcGeTol& tol = GcGeContext::gTol) const;
  GcGePoint2d    center() const;
  double         radius() const;
  double         startAng() const;
  double         endAng() const;
  Gsoft::Boolean isClockWise() const;
  GcGeVector2d   refVec() const;
  GcGePoint2d    startPoint() const;
  GcGePoint2d    endPoint() const;

  GcGeCircArc2d& setCenter(const GcGePoint2d& cent);
  GcGeCircArc2d& setRadius(double radius);
  GcGeCircArc2d& setAngles(double startAng, double endAng);
  GcGeCircArc2d& setToComplement();
  GcGeCircArc2d& setRefVec(const GcGeVector2d& vec);
  GcGeCircArc2d& set(const GcGePoint2d& cent, double radius);
  GcGeCircArc2d& set(const GcGePoint2d& cent, double radius,
    double ang1, double ang2,
    const GcGeVector2d& refVec =
    GcGeVector2d::kXAxis,
    Gsoft::Boolean isClockWise = Gsoft::kFalse);
  GcGeCircArc2d& set(const GcGePoint2d& startPoint, const GcGePoint2d& pnt,
    const GcGePoint2d& endPoint);
  GcGeCircArc2d& set(const GcGePoint2d& startPoint, const GcGePoint2d& pnt,
    const GcGePoint2d& endPoint, GcGeError& error);
  GcGeCircArc2d& set(const GcGePoint2d& startPoint,
    const GcGePoint2d& endPoint,
    double bulge, Gsoft::Boolean bulgeFlag = Gsoft::kTrue);
  GcGeCircArc2d& set(const GcGeCurve2d& curve1,
    const GcGeCurve2d& curve2,
    double radius, double& param1, double& param2,
    Gsoft::Boolean& success);
  GcGeCircArc2d& set(const GcGeCurve2d& curve1,
    const GcGeCurve2d& curve2,
    const GcGeCurve2d& curve3,
    double& param1, double& param2, double& param3,
    Gsoft::Boolean& success);
  GcGeCircArc2d& operator =     (const GcGeCircArc2d& arc);
};

#pragma pack (pop)
#endif