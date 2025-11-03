/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GESURF_H
#define GC_GESURF_H

#include "geent3d.h"
#include "gevc3dar.h"
#pragma pack (push, 8)

class GcGePoint2d;
class GcGeCurve3d;
class GcGePointOnCurve3d;
class GcGePointOnSurface;
class GcGePointOnSurfaceData;
class GcGeInterval;

class GE_DLLDATAEXIMP GcGeSurface : public GcGeEntity3d
{
public:
  GcGePoint2d     paramOf(const GcGePoint3d& pnt,
                                          const GcGeTol&     tol = GcGeContext::gTol) const;

  Gsoft::Boolean  isOn(const GcGePoint3d& pnt,
                                       const GcGeTol&     tol = GcGeContext::gTol) const;
  Gsoft::Boolean  isOn(const GcGePoint3d& pnt,
                                       GcGePoint2d&       paramPoint,
                                       const GcGeTol&     tol = GcGeContext::gTol) const;

  GcGePoint3d     closestPointTo(const GcGePoint3d& pnt,
                                             const GcGeTol&     tol = GcGeContext::gTol) const;
  void            getClosestPointTo(const GcGePoint3d&  pnt,
                                                GcGePointOnSurface& result,
                                                const GcGeTol&      tol = GcGeContext::gTol) const;

  double          distanceTo(const GcGePoint3d& pnt,
                                             const GcGeTol&     tol = GcGeContext::gTol) const;

  Gsoft::Boolean  isNormalReversed() const;
  GcGeSurface&    reverseNormal();

  GcGeSurface&    operator =     (const GcGeSurface& otherSurface);

  void   getEnvelope(GcGeInterval& intrvlX, GcGeInterval& intrvlY) const;

  Gsoft::Boolean isClosedInU(const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isClosedInV(const GcGeTol& tol = GcGeContext::gTol) const;

  GcGePoint3d   evalPoint(const GcGePoint2d& param) const;
  GcGePoint3d   evalPoint(const GcGePoint2d& param,
                                          int                derivOrd,
                                          GcGeVector3dArray& derivatives) const;
  GcGePoint3d   evalPoint(const GcGePoint2d& param,
                                          int                derivOrd,
                                          GcGeVector3dArray& derivatives,
                                          GcGeVector3d&      normal) const;
protected:
  GcGeSurface();
  GcGeSurface(const GcGeSurface&);
};

#pragma pack (pop)
#endif
