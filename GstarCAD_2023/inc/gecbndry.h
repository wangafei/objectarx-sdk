/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GECBNDRY_H
#define GC_GECBNDRY_H

#include "gegbl.h"
#pragma pack (push, 8)

class GcGeCurve2d;
class GcGeEntity3d;
class GcGePosition3d;
class GcGeImpCurveBoundary;

class
  GE_DLLDATAEXIMP
  GcGeCurveBoundary
{
public:
  GcGeCurveBoundary();
  GcGeCurveBoundary(int numberOfCurves, const GcGeEntity3d *const * crv3d,
    const GcGeCurve2d *const * crv2d,
    Gsoft::Boolean* orientation3d,
    Gsoft::Boolean* orientation2d,
    Gsoft::Boolean makeCopy = Gsoft::kTrue);
  GcGeCurveBoundary(const GcGeCurveBoundary&);
  ~GcGeCurveBoundary();

  GcGeCurveBoundary& operator =   (const GcGeCurveBoundary& src);

  Gsoft::Boolean     isDegenerate() const;
  Gsoft::Boolean     isDegenerate(GcGePosition3d& degenPoint, GcGeCurve2d** paramCurve) const;
  int                numElements() const;
  void               getContour(int& n, GcGeEntity3d*** crv3d,
    GcGeCurve2d*** paramGeometry,
    Gsoft::Boolean** orientation3d,
    Gsoft::Boolean** orientation2d) const;
  GcGeCurveBoundary& set(int numElements, const GcGeEntity3d *const * crv3d,
    const GcGeCurve2d *const * crv2d,
    Gsoft::Boolean* orientation3d,
    Gsoft::Boolean* orientation2d,
    Gsoft::Boolean makeCopy = Gsoft::kTrue);

  Gsoft::Boolean     isOwnerOfCurves() const;
  GcGeCurveBoundary& setToOwnCurves();

protected:
  friend class GcGeImpCurveBoundary;

  GcGeImpCurveBoundary    *mpImpBnd;
  int                     mDelBnd;
};

#pragma pack (pop)
#endif