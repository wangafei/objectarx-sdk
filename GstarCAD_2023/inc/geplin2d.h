/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEPLIN2D_H
#define GC_GEPLIN2D_H

#include "gecurv2d.h"
#include "gekvec.h"
#include "gept2dar.h"
#include "gevec2d.h"
#include "gepnt2d.h"
#include "gesent2d.h"
#pragma pack (push, 8)

class GE_DLLDATAEXIMP GcGePolyline2d : public GcGeSplineEnt2d
{
public:
  GcGePolyline2d();
  GcGePolyline2d(const GcGePolyline2d& src);
  GcGePolyline2d(const GcGePoint2dArray&);
  GcGePolyline2d(const GcGeKnotVector& knots, const GcGePoint2dArray& points);

  GcGePolyline2d(const GcGeCurve2d& crv, double apprEps);

  int              numFitPoints() const;
  GcGePoint2d      fitPointAt(int idx) const;
  GcGeSplineEnt2d& setFitPointAt(int idx, const GcGePoint2d& point);

  GcGePolyline2d& operator =     (const GcGePolyline2d& pline);
};

#pragma pack (pop)
#endif
