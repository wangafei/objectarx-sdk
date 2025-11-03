/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEXBNDSF_H
#define GC_GEXBNDSF_H

#include "gegbl.h"
#include "gesurf.h"
#pragma pack (push, 8)

class GcGeExternalSurface;
class GcGeCurveBoundary;

class GE_DLLDATAEXIMP GcGeExternalBoundedSurface : public GcGeSurface
{
public:
  GcGeExternalBoundedSurface();
  GcGeExternalBoundedSurface(void* surfaceDef, GcGe::ExternalEntityKind surfaceKind, Gsoft::Boolean makeCopy = Gsoft::kTrue);
  GcGeExternalBoundedSurface(const GcGeExternalBoundedSurface&);

  GcGe::ExternalEntityKind   externalSurfaceKind() const;
  Gsoft::Boolean             isDefined() const;
  void                       getExternalSurface(void*& surfaceDef) const;

  void getBaseSurface(GcGeSurface*& surfaceDef) const;
  void getBaseSurface(GcGeExternalSurface& unboundedSurfaceDef) const;

  Gsoft::Boolean isPlane() const;
  Gsoft::Boolean isSphere() const;
  Gsoft::Boolean isCylinder() const;
  Gsoft::Boolean isCone() const;
  Gsoft::Boolean isTorus() const;
  Gsoft::Boolean isNurbs() const;
  Gsoft::Boolean isExternalSurface() const;

  int          numContours() const;
  void         getContours(int& numContours, GcGeCurveBoundary*& curveBoundaries) const;

  GcGeExternalBoundedSurface& set(void* surfaceDef,
                                  GcGe::ExternalEntityKind surfaceKind,
                                  Gsoft::Boolean makeCopy = Gsoft::kTrue);

  GcGeExternalBoundedSurface& operator = (const GcGeExternalBoundedSurface&);

  Gsoft::Boolean               isOwnerOfSurface() const;
  GcGeExternalBoundedSurface&  setToOwnSurface();
};

#pragma pack (pop)
#endif
