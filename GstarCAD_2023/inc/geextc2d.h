/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEEXTC2D_H
#define GC_GEEXTC2D_H

#include "gecurv2d.h"
#include "gearc2d.h"
#include "gevec2d.h"
#include "gepnt2d.h"
#pragma pack (push, 8)

class GcGeNurbCurve2d;
class GcGeExternalCurve2d;
class GcGeExternalCurve2d;

class
  GE_DLLDATAEXIMP
  GcGeExternalCurve2d : public GcGeCurve2d
{
public:
  GcGeExternalCurve2d();
  GcGeExternalCurve2d(const GcGeExternalCurve2d&);
  GcGeExternalCurve2d(void* curveDef, GcGe::ExternalEntityKind curveKind,
    Gsoft::Boolean makeCopy = Gsoft::kTrue);

  Gsoft::Boolean isNurbCurve() const;
  Gsoft::Boolean isNurbCurve(GcGeNurbCurve2d& nurbCurve) const;
  Gsoft::Boolean isDefined() const;
  void           getExternalCurve(void*& curveDef) const;
  GcGe::ExternalEntityKind externalCurveKind() const;
  GcGeExternalCurve2d& set(void* curveDef, GcGe::ExternalEntityKind curveKind,
    Gsoft::Boolean makeCopy = Gsoft::kTrue);
  GcGeExternalCurve2d& operator = (const GcGeExternalCurve2d& src);

  Gsoft::Boolean       isOwnerOfCurve() const;
  GcGeExternalCurve2d& setToOwnCurve();
};

#pragma pack (pop)
#endif