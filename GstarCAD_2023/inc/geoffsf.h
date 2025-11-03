/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEOFFSF_H
#define GC_GEOFFSF_H

#include "gegbl.h"
#include "gepnt3d.h"
#include "gesurf.h"
#pragma pack (push, 8)

class GcGePlane;
class GcGeBoundedPlane;
class GcGeCylinder;
class GcGeCone;
class GcGeSphere;
class GcGeTorus;

class GX_DLLEXPIMPORT GcGeOffsetSurface : public GcGeSurface
{
public:
  GcGeOffsetSurface();
  GcGeOffsetSurface(GcGeSurface* baseSurface, double offsetDist, Gsoft::Boolean makeCopy = Gsoft::kTrue);
  GcGeOffsetSurface(const GcGeOffsetSurface& offset);

  Gsoft::Boolean    isPlane() const;
  Gsoft::Boolean    isBoundedPlane() const;
  Gsoft::Boolean    isSphere() const;
  Gsoft::Boolean    isCylinder() const;
  Gsoft::Boolean    isCone() const;
  Gsoft::Boolean    isTorus() const;
  Gsoft::Boolean    getSurface(GcGeSurface*&) const;
  void              getConstructionSurface(GcGeSurface*& base) const;
  double            offsetDist() const;

  GcGeOffsetSurface& set(GcGeSurface*, double offsetDist, Gsoft::Boolean makeCopy = Gsoft::kTrue);

  GcGeOffsetSurface& operator =  (const GcGeOffsetSurface& offset);
};

#pragma pack (pop)
#endif
