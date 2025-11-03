/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GECYLNDR_H
#define GC_GECYLNDR_H

#include "gegbl.h"
#include "gesurf.h"
#include "gevec3d.h"
#include "geintrvl.h"
#include "gearc3d.h"
#pragma pack (push, 8)

class GcGeCircArc3d;

class
  GX_DLLEXPIMPORT
  GcGeCylinder : public GcGeSurface
{
public:
  GcGeCylinder();
  GcGeCylinder(double radius, const GcGePoint3d& origin,
    const GcGeVector3d& axisOfSymmetry);
  GcGeCylinder(double radius, const GcGePoint3d& origin,
    const GcGeVector3d& axisOfSymmetry,
    const GcGeVector3d& refAxis,
    const GcGeInterval& height,
    double startAngle, double endAngle);
  GcGeCylinder(const GcGeCylinder&);

  double         radius() const;
  GcGePoint3d    origin() const;
  void           getAngles(double& start, double& end) const;
  void           getHeight(GcGeInterval& height) const;
  double         heightAt(double u) const;
  GcGeVector3d   axisOfSymmetry() const;
  GcGeVector3d   refAxis() const;
  Gsoft::Boolean isOuterNormal() const;
  Gsoft::Boolean isClosed(const GcGeTol& tol = GcGeContext::gTol) const;

  GcGeCylinder&  setRadius(double radius);
  GcGeCylinder&  setAngles(double start, double end);
  GcGeCylinder&  setHeight(const GcGeInterval& height);
  GcGeCylinder&  set(double radius, const GcGePoint3d& origin,
    const GcGeVector3d& axisOfSym);
  GcGeCylinder&  set(double radius, const GcGePoint3d& origin,
    const GcGeVector3d& axisOfSym,
    const GcGeVector3d& refAxis,
    const GcGeInterval& height,
    double startAngle, double endAngle);
  GcGeCylinder&  operator =    (const GcGeCylinder& cylinder);

  Gsoft::Boolean intersectWith(const GcGeLinearEnt3d& linEnt, int& intn,
    GcGePoint3d& p1, GcGePoint3d& p2,
    const GcGeTol& tol = GcGeContext::gTol) const;
};

#pragma pack (pop)
#endif