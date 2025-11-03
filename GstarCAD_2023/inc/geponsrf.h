/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEPONSRF_H
#define GC_GEPONSRF_H

#include "gepent3d.h"
#pragma pack (push, 8)

class GcGeSurface;

class GE_DLLDATAEXIMP GcGePointOnSurface : public GcGePointEnt3d
{
public:
  GcGePointOnSurface();
  GcGePointOnSurface(const GcGeSurface& surf);
  GcGePointOnSurface(const GcGeSurface& surf, const GcGePoint2d& param);
  GcGePointOnSurface(const GcGePointOnSurface& src);

  GcGePointOnSurface& operator =     (const GcGePointOnSurface& src);

  const GcGeSurface*  surface() const;
  GcGePoint2d         parameter() const;

  GcGePoint3d         point() const;
  GcGePoint3d         point(const GcGePoint2d& param);
  GcGePoint3d         point(const GcGeSurface& surf, const GcGePoint2d& param);

  GcGeVector3d        normal() const;
  GcGeVector3d        normal(const GcGePoint2d& param);
  GcGeVector3d        normal(const GcGeSurface& surf, const GcGePoint2d& param);
  GcGeVector3d        uDeriv(int order) const;
  GcGeVector3d        uDeriv(int order, const GcGePoint2d& param);
  GcGeVector3d        uDeriv(int order, const GcGeSurface& surf, const GcGePoint2d& param);

  GcGeVector3d        vDeriv(int order) const;
  GcGeVector3d        vDeriv(int order, const GcGePoint2d& param);
  GcGeVector3d        vDeriv(int order, const GcGeSurface& surf, const GcGePoint2d& param);

  GcGeVector3d        mixedPartial() const;
  GcGeVector3d        mixedPartial(const GcGePoint2d& param);
  GcGeVector3d        mixedPartial(const GcGeSurface& surf, const GcGePoint2d& param);

  GcGeVector3d        tangentVector(const GcGeVector2d& vec) const;
  GcGeVector3d        tangentVector(const GcGeVector2d& vec, const GcGePoint2d& param);
  GcGeVector3d        tangentVector(const GcGeVector2d& vec, const GcGeSurface& vecSurf, const GcGePoint2d& param);

  GcGeVector2d        inverseTangentVector(const GcGeVector3d& vec) const;
  GcGeVector2d        inverseTangentVector(const GcGeVector3d& vec, const GcGePoint2d& param);
  GcGeVector2d        inverseTangentVector(const GcGeVector3d& vec, const GcGeSurface& surf, const GcGePoint2d& param);
  GcGePointOnSurface& setSurface(const GcGeSurface& surf);
  GcGePointOnSurface& setParameter(const GcGePoint2d& param);
};

#pragma pack (pop)
#endif
