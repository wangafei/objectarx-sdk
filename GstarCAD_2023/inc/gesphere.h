/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GESPHERE_H
#define GC_GESPHERE_H

#include "gegbl.h"
#include "gepnt3d.h"
#include "gevec3d.h"
#include "geintrvl.h"
#include "gesurf.h"
#pragma pack (push, 8)

class GcGeCircArc3d;

class GE_DLLDATAEXIMP GcGeSphere : public GcGeSurface
{
public:
  GcGeSphere();
  GcGeSphere(double radius, const GcGePoint3d& center);
  GcGeSphere(double radius,
             const GcGePoint3d& center,
             const GcGeVector3d& northAxis,
             const GcGeVector3d& refAxis,
             double startAngleU,
             double endAngleU,
             double startAngleV,
             double endAngleV);
  GcGeSphere(const GcGeSphere& sphere);

  double         radius() const;
  GcGePoint3d    center() const;
  void           getAnglesInU(double& start, double& end) const;
  void           getAnglesInV(double& start, double& end) const;
  GcGeVector3d   northAxis() const;
  GcGeVector3d   refAxis() const;
  GcGePoint3d    northPole() const;
  GcGePoint3d    southPole() const;
  Gsoft::Boolean isOuterNormal() const;
  Gsoft::Boolean isClosed(const GcGeTol& tol = GcGeContext::gTol) const;

  GcGeSphere&    setRadius(double);
  GcGeSphere&    setAnglesInU(double start, double end);
  GcGeSphere&    setAnglesInV(double start, double end);
  GcGeSphere&    set(double radius, const GcGePoint3d& center);
  GcGeSphere&    set(double radius,
                     const GcGePoint3d& center,
                     const GcGeVector3d& northAxis,
                     const GcGeVector3d& refAxis,
                     double startAngleU,
                     double endAngleU,
                     double startAngleV,
                     double endAngleV);
  GcGeSphere&    operator =     (const GcGeSphere& sphere);

  Gsoft::Boolean intersectWith(const GcGeLinearEnt3d&,
                               int& intn,
                               GcGePoint3d& p1,
                               GcGePoint3d& p2,
                               const GcGeTol& tol = GcGeContext::gTol) const;
};

#pragma pack (pop)
#endif
