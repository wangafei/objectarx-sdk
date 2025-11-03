/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GETORUS_H
#define GC_GETORUS_H

#include "gegbl.h"
#include "gesurf.h"
#include "geintrvl.h"
#include "gevec3d.h"
#pragma pack (push, 8)

class GcGeCircArc3d;

class GX_DLLEXPIMPORT GcGeTorus : public GcGeSurface
{
public:
  GcGeTorus();
  GcGeTorus(double majorRadius,
            double minorRadius,
            const GcGePoint3d& origin,
            const GcGeVector3d& axisOfSymmetry);
  GcGeTorus(double majorRadius,
            double minorRadius,
            const GcGePoint3d&  origin,
            const GcGeVector3d& axisOfSymmetry,
            const GcGeVector3d& refAxis,
            double startAngleU,
            double endAngleU,
            double startAngleV,
            double endAngleV);
  GcGeTorus(const GcGeTorus& torus);

  double          majorRadius() const;
  double          minorRadius() const;
  void            getAnglesInU(double& start, double& end) const;
  void            getAnglesInV(double& start, double& end) const;
  GcGePoint3d     center() const;
  GcGeVector3d    axisOfSymmetry() const;
  GcGeVector3d    refAxis() const;
  Gsoft::Boolean  isOuterNormal() const;

  GcGeTorus&      setMajorRadius(double radius);
  GcGeTorus&      setMinorRadius(double radius);
  GcGeTorus&      setAnglesInU(double start, double end);
  GcGeTorus&      setAnglesInV(double start, double end);
  GcGeTorus&      set(double majorRadius,
                      double minorRadius,
                      const GcGePoint3d& origin,
                      const GcGeVector3d& axisOfSymmetry);
  GcGeTorus&      set(double majorRadius,
                      double minorRadius,
                      const GcGePoint3d&  origin,
                      const GcGeVector3d& axisOfSymmetry,
                      const GcGeVector3d& refAxis,
                      double startAngleU,
                      double endAngleU,
                      double startAngleV,
                      double endAngleV);
  GcGeTorus&      operator =     (const GcGeTorus& torus);

  Gsoft::Boolean  intersectWith(const GcGeLinearEnt3d& linEnt,
                                int& intn,
                                GcGePoint3d& p1,
                                GcGePoint3d& p2,
                                GcGePoint3d& p3,
                                GcGePoint3d& p4,
                                const GcGeTol& tol = GcGeContext::gTol) const;

  Gsoft::Boolean isLemon() const;
  Gsoft::Boolean isApple() const;
  Gsoft::Boolean isVortex() const;
  Gsoft::Boolean isDoughnut() const;
  Gsoft::Boolean isDegenerate() const;
  Gsoft::Boolean isHollow() const;
};

#pragma pack (pop)
#endif
