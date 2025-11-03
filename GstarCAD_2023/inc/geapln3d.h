/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEAPLN3D_H
#define GC_GEAPLN3D_H

#include "gecurv3d.h"
#include "gekvec.h"
#include "gept3dar.h"
#include "gevc3dar.h"
#include "gevec3d.h"
#include "gepnt3d.h"
#include "geplin3d.h"

#pragma pack (push, 8)

class
  GE_DLLDATAEXIMP
  GcGeAugPolyline3d : public GcGePolyline3d
{
public:
  GcGeAugPolyline3d();
  GcGeAugPolyline3d(const GcGeAugPolyline3d& apline);
  GcGeAugPolyline3d(const GcGeKnotVector& knots,
    const GcGePoint3dArray& cntrlPnts,
    const GcGeVector3dArray& vecBundle);
  GcGeAugPolyline3d(const GcGePoint3dArray& cntrlPnts,
    const GcGeVector3dArray& vecBundle);
  GcGeAugPolyline3d(const GcGeCurve3d& curve,
    double fromParam, double toParam,
    double apprEps);

  GcGeAugPolyline3d& operator = (const GcGeAugPolyline3d& apline);

  GcGePoint3d           getPoint(int idx) const;
  GcGeAugPolyline3d&    setPoint(int idx, GcGePoint3d pnt);
  void                  getPoints(GcGePoint3dArray& pnts) const;

  GcGeVector3d          getVector(int idx) const;
  GcGeAugPolyline3d&    setVector(int idx, GcGeVector3d pnt);
  void                  getD1Vectors(GcGeVector3dArray& tangents) const;

  GcGeVector3d          getD2Vector(int idx) const;
  GcGeAugPolyline3d&    setD2Vector(int idx, GcGeVector3d pnt);
  void                  getD2Vectors(GcGeVector3dArray& d2Vectors) const;

  double                approxTol() const;
  GcGeAugPolyline3d&    setApproxTol(double approxTol);

};

#pragma pack (pop)
#endif