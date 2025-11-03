/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEENT3D_H
#define GC_GEENT3D_H

#include "gegbl.h"
#include "gepnt3d.h"
#include "geent2d.h"
#include "geintrvl.h"
#include "gegblnew.h"
#pragma pack (push, 8)

class
  GE_DLLDATAEXIMP
  GcGeEntity3d
{
public:
  ~GcGeEntity3d();

  Gsoft::Boolean   isKindOf(GcGe::EntityId entType) const;
  GcGe::EntityId   type() const;
  GcGeEntity3d*    copy() const;

  GcGeEntity3d&    operator =  (const GcGeEntity3d& entity);
  Gsoft::Boolean   operator == (const GcGeEntity3d& entity) const;
  Gsoft::Boolean   operator != (const GcGeEntity3d& entity) const;
  Gsoft::Boolean   isEqualTo(const GcGeEntity3d& ent,
    const GcGeTol& tol = GcGeContext::gTol) const;
  GcGeEntity3d&    transformBy(const GcGeMatrix3d& xfm);
  GcGeEntity3d&    translateBy(const GcGeVector3d& translateVec);
  GcGeEntity3d&    rotateBy(double angle, const GcGeVector3d& vec,
    const GcGePoint3d& wrtPoint = GcGePoint3d::kOrigin);
  GcGeEntity3d&    mirror(const GcGePlane& plane);
  GcGeEntity3d&    scaleBy(double scaleFactor,
    const GcGePoint3d& wrtPoint
    = GcGePoint3d::kOrigin);
  Gsoft::Boolean   isOn(const GcGePoint3d& pnt,
    const GcGeTol& tol = GcGeContext::gTol) const;
protected:
  friend class GcGeImpEntity3d;
  class GcGeImpEntity3d  *mpImpEnt;
  int              mDelEnt;
  GcGeEntity3d();
  GcGeEntity3d(const GcGeEntity3d&);
  GcGeEntity3d(GcGeImpEntity3d&, int);
  GcGeEntity3d(GcGeImpEntity3d*);
  GcGeEntity2d* newEntity2d(GcGeImpEntity3d*) const;
  GcGeEntity2d* newEntity2d(GcGeImpEntity3d&, int) const;
  GcGeEntity3d* newEntity3d(GcGeImpEntity3d*) const;
  GcGeEntity3d* newEntity3d(GcGeImpEntity3d&, int) const;
};

inline GcGeEntity2d*
GcGeEntity3d::newEntity2d(GcGeImpEntity3d *impEnt) const
{
  return GENEWLOC(GcGeEntity2d, this) (impEnt);
}

inline GcGeEntity3d*
GcGeEntity3d::newEntity3d(GcGeImpEntity3d *impEnt) const
{
  return GENEWLOC(GcGeEntity3d, this) (impEnt);
}

inline GcGeEntity3d*
GcGeEntity3d::newEntity3d(GcGeImpEntity3d& impEnt, int dummy) const
{
  return GENEWLOC(GcGeEntity3d, this)(impEnt, dummy);
}

inline GcGeEntity2d*
GcGeEntity3d::newEntity2d(GcGeImpEntity3d& impEnt, int dummy) const
{
  return GENEWLOC(GcGeEntity2d, this)(impEnt, dummy);
}

#pragma pack (pop)
#endif
