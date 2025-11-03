/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEOFFC2D_H
#define GC_GEOFFC2D_H

#include "gecurv2d.h"
#pragma pack (push, 8)

class GE_DLLDATAEXIMP GcGeOffsetCurve2d : public GcGeCurve2d
{
public:
  GcGeOffsetCurve2d(const GcGeCurve2d& baseCurve, double offsetDistance);
  GcGeOffsetCurve2d(const GcGeOffsetCurve2d& offsetCurve);

  const GcGeCurve2d*  curve() const;
  double              offsetDistance() const;
  Gsoft::Boolean      paramDirection() const;
  GcGeMatrix2d        transformation() const;

  GcGeOffsetCurve2d&  setCurve(const GcGeCurve2d& baseCurve);
  GcGeOffsetCurve2d&  setOffsetDistance(double distance);

  GcGeOffsetCurve2d&  operator = (const GcGeOffsetCurve2d& offsetCurve);
};

#pragma pack (pop)
#endif
