/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEOFFC3D_H
#define GC_GEOFFC3D_H

#include "gecurv3d.h"
#pragma pack (push, 8)

class GE_DLLDATAEXIMP GcGeOffsetCurve3d : public GcGeCurve3d
{
public:
  GcGeOffsetCurve3d(const GcGeCurve3d& baseCurve, const GcGeVector3d& planeNormal, double offsetDistance);
  GcGeOffsetCurve3d(const GcGeOffsetCurve3d& offsetCurve);

  const GcGeCurve3d*  curve() const;
  GcGeVector3d        normal() const;
  double              offsetDistance() const;
  Gsoft::Boolean      paramDirection() const;
  GcGeMatrix3d        transformation() const;

  GcGeOffsetCurve3d&  setCurve(const GcGeCurve3d& baseCurve);
  GcGeOffsetCurve3d&  setNormal(const GcGeVector3d& planeNormal);
  GcGeOffsetCurve3d&  setOffsetDistance(double offsetDistance);

  GcGeOffsetCurve3d&  operator = (const GcGeOffsetCurve3d& offsetCurve);
};

#pragma pack (pop)
#endif
