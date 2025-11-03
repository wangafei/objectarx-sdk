/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GECOMP2D_H
#define GC_GECOMP2D_H

#include "gecurv2d.h"
#include "gevptar.h"
#include "geintarr.h"
#pragma pack (push, 8)

class
  GE_DLLDATAEXIMP
  GcGeCompositeCurve2d : public GcGeCurve2d
{
public:
  GcGeCompositeCurve2d();
  GcGeCompositeCurve2d(const GcGeVoidPointerArray& curveList);
  GcGeCompositeCurve2d(const GcGeVoidPointerArray& curveList,
    const GcGeIntArray& isOwnerOfCurves);
  GcGeCompositeCurve2d(const GcGeCompositeCurve2d& compCurve);

  void		          getCurveList(GcGeVoidPointerArray& curveList) const;

  GcGeCompositeCurve2d& setCurveList(const GcGeVoidPointerArray& curveList);
  GcGeCompositeCurve2d& setCurveList(const GcGeVoidPointerArray& curveList,
    const GcGeIntArray& isOwnerOfCurves);

  double				  globalToLocalParam(double param, int& crvNum) const;
  double				  localToGlobalParam(double param, int crvNum) const;

  GcGeCompositeCurve2d& operator =         (const GcGeCompositeCurve2d& compCurve);
};

#pragma pack (pop)
#endif