/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEPLIN3D_H
#define GC_GEPLIN3D_H

#include "gecurv3d.h"
#include "gekvec.h"
#include "gept3dar.h"
#include "gevec3d.h"
#include "gepnt3d.h"
#include "gesent3d.h"
#pragma pack (push, 8)

class GE_DLLDATAEXIMP GcGePolyline3d : public GcGeSplineEnt3d
{
public:
  GcGePolyline3d();
  GcGePolyline3d(const GcGePolyline3d& src);
  GcGePolyline3d(const GcGePoint3dArray& points);
  GcGePolyline3d(const GcGeKnotVector& knots, const GcGePoint3dArray& cntrlPnts);

  GcGePolyline3d(const GcGeCurve3d& crv, double apprEps);

  int              numFitPoints() const;
  GcGePoint3d      fitPointAt(int idx) const;
  GcGeSplineEnt3d& setFitPointAt(int idx, const GcGePoint3d& point);

  GcGePolyline3d& operator =     (const GcGePolyline3d& pline);
};

#pragma pack (pop)
#endif
