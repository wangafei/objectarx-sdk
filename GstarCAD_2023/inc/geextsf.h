/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEEXTSF_H
#define GC_GEEXTSF_H

#include "gegbl.h"
#include "gesurf.h"
#pragma pack (push, 8)

class GcGePlane;
class GcGeCylinder;
class GcGeCone;
class GcGeSphere;
class GcGeTorus;
class GcGeNurbSurface;
class surface;

class
  GE_DLLDATAEXIMP
  GcGeExternalSurface : public GcGeSurface
{
public:
  GcGeExternalSurface();
  GcGeExternalSurface(void* surfaceDef, GcGe::ExternalEntityKind surfaceKind,
    Gsoft::Boolean makeCopy = Gsoft::kTrue);
  GcGeExternalSurface(const GcGeExternalSurface&);

  void getExternalSurface(void*& surfaceDef) const;
  GcGe::ExternalEntityKind  externalSurfaceKind() const;

  Gsoft::Boolean    isPlane() const;
  Gsoft::Boolean    isSphere() const;
  Gsoft::Boolean    isCylinder() const;
  Gsoft::Boolean    isCone() const;
  Gsoft::Boolean    isTorus() const;
  Gsoft::Boolean    isNurbSurface() const;
  Gsoft::Boolean    isDefined() const;

  Gsoft::Boolean isNativeSurface(GcGeSurface*& nativeSurface) const;

  GcGeExternalSurface& operator = (const GcGeExternalSurface& src);

  GcGeExternalSurface& set(void* surfaceDef,
    GcGe::ExternalEntityKind surfaceKind,
    Gsoft::Boolean makeCopy = Gsoft::kTrue);
  Gsoft::Boolean       isOwnerOfSurface() const;
  GcGeExternalSurface& setToOwnSurface();
};

#pragma pack (pop)
#endif