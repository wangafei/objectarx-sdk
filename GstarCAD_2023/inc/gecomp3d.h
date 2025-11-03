/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GECOMP3D_H
#define GC_GECOMP3D_H

#include "gecurv3d.h"
#include "gevptar.h"
#include "geintarr.h"
#pragma pack (push, 8)

class
  GE_DLLDATAEXIMP
  GcGeCompositeCurve3d : public GcGeCurve3d
{
public:
  GcGeCompositeCurve3d();
  GcGeCompositeCurve3d(const GcGeVoidPointerArray& curveList);
  GcGeCompositeCurve3d(const GcGeVoidPointerArray& curveList,
    const GcGeIntArray& isOwnerOfCurves);
  GcGeCompositeCurve3d(const GcGeCompositeCurve3d& compCurve);

  void		          getCurveList(GcGeVoidPointerArray& curveList) const;

  GcGeCompositeCurve3d& setCurveList(const GcGeVoidPointerArray& curveList);
  GcGeCompositeCurve3d& setCurveList(const GcGeVoidPointerArray& curveList,
    const GcGeIntArray& isOwnerOfCurves);

  double				  globalToLocalParam(double param, int& segNum) const;
  double				  localToGlobalParam(double param, int segNum) const;

  GcGeCompositeCurve3d& operator =         (const GcGeCompositeCurve3d& compCurve);
};

#pragma pack (pop)
#endif