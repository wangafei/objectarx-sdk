/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEEXTC3D_H
#define GC_GEEXTC3D_H

#include "gecurv3d.h"
#include "gearc3d.h"
#include "gevec3d.h"
#include "gepnt3d.h"
#pragma pack (push, 8)

class GcGeLine3d;
class GcGeLineSeg3d;
class GcGeRay3d;
class GcGeEllipArc3d;
class GcGeNurbCurve3d;
class GcGeExternalCurve2d;
class GcGeExternalCurve3d;

class
  GE_DLLDATAEXIMP
  GcGeExternalCurve3d : public GcGeCurve3d
{
public:
  GcGeExternalCurve3d();
  GcGeExternalCurve3d(const GcGeExternalCurve3d& src);
  GcGeExternalCurve3d(void* curveDef, GcGe::ExternalEntityKind curveKind,
    Gsoft::Boolean makeCopy = Gsoft::kTrue);

  Gsoft::Boolean isLine() const;
  Gsoft::Boolean isRay() const;
  Gsoft::Boolean isLineSeg() const;
  Gsoft::Boolean isCircArc() const;
  Gsoft::Boolean isEllipArc() const;
  Gsoft::Boolean isNurbCurve() const;
  Gsoft::Boolean isDefined() const;
  Gsoft::Boolean isNativeCurve(GcGeCurve3d*& nativeCurve) const;
  void           getExternalCurve(void*& curveDef) const;
  GcGe::ExternalEntityKind externalCurveKind() const;
  GcGeExternalCurve3d& set(void* curveDef, GcGe::ExternalEntityKind curveKind,
    Gsoft::Boolean makeCopy = Gsoft::kTrue);
  GcGeExternalCurve3d& operator = (const GcGeExternalCurve3d& src);

  Gsoft::Boolean       isOwnerOfCurve() const;
  GcGeExternalCurve3d& setToOwnCurve();
};

#pragma pack (pop)
#endif