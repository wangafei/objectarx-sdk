/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GECONE_H
#define GC_GECONE_H

#include "gegbl.h"
#include "geintrvl.h"
#include "gevec3d.h"
#include "gesurf.h"
#include "gearc3d.h"
#pragma pack (push, 8)

class GcGePoint3d;
class GcGeVector3d;
class GcGeCircArc3d;
class GcGeInterval;
class GcGeLinearEnt3d;

class
  GX_DLLEXPIMPORT
  GcGeCone : public GcGeSurface
{
public:
  GcGeCone();
  GcGeCone(double cosineAngle, double sineAngle,
    const  GcGePoint3d& baseOrigin, double baseRadius,
    const  GcGeVector3d& axisOfSymmetry);
  GcGeCone(double cosineAngle, double sineAngle,
    const  GcGePoint3d& baseOrigin, double baseRadius,
    const  GcGeVector3d& axisOfSymmetry,
    const  GcGeVector3d& refAxis, const  GcGeInterval& height,
    double startAngle, double endAngle);
  GcGeCone(const GcGeCone& cone);

  double           baseRadius() const;
  GcGePoint3d      baseCenter() const;
  void             getAngles(double& start, double& end) const;
  double           halfAngle() const;
  void             getHalfAngle(double& cosineAngle, double& sineAngle)
    const;
  void             getHeight(GcGeInterval& range) const;
  double           heightAt(double u) const;
  GcGeVector3d     axisOfSymmetry() const;
  GcGeVector3d     refAxis() const;
  GcGePoint3d      apex() const;
  Gsoft::Boolean   isClosed(const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean   isOuterNormal() const;

  GcGeCone&        setBaseRadius(double radius);
  GcGeCone&        setAngles(double startAngle, double endAngle);
  GcGeCone&        setHeight(const GcGeInterval& height);
  GcGeCone&        set(double cosineAngle, double sineAngle,
    const  GcGePoint3d& baseCenter,
    double baseRadius,
    const  GcGeVector3d& axisOfSymmetry);
  GcGeCone&        set(double cosineAngle, double sineAngle,
    const  GcGePoint3d& baseCenter,
    double baseRadius,
    const  GcGeVector3d& axisOfSymmetry,
    const  GcGeVector3d& refAxis,
    const  GcGeInterval& height,
    double startAngle, double endAngle);
  GcGeCone&        operator =        (const GcGeCone& cone);
  Gsoft::Boolean   intersectWith(const GcGeLinearEnt3d& linEnt, int& intn,
    GcGePoint3d& p1, GcGePoint3d& p2,
    const GcGeTol& tol = GcGeContext::gTol) const;
};

#pragma pack (pop)
#endif