/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEENT2D_H
#define GC_GEENT2D_H

#include "gegbl.h"
#include "gepnt2d.h"
#include "geintrvl.h"
#include "gegblnew.h"
#pragma pack (push, 8)

class
  GE_DLLDATAEXIMP
  GcGeEntity2d
{
public:
  ~GcGeEntity2d();

  Gsoft::Boolean   isKindOf(GcGe::EntityId entType) const;
  GcGe::EntityId   type() const;
  GcGeEntity2d*    copy() const;

  GcGeEntity2d&    operator =  (const GcGeEntity2d& entity);
  Gsoft::Boolean   operator == (const GcGeEntity2d& entity) const;
  Gsoft::Boolean   operator != (const GcGeEntity2d& entity) const;

  Gsoft::Boolean   isEqualTo(const GcGeEntity2d& entity,
    const GcGeTol& tol = GcGeContext::gTol) const;
  GcGeEntity2d&    transformBy(const GcGeMatrix2d& xfm);
  GcGeEntity2d&    translateBy(const GcGeVector2d& translateVec);
  GcGeEntity2d&    rotateBy(double angle, const GcGePoint2d& wrtPoint
    = GcGePoint2d::kOrigin);
  GcGeEntity2d&    mirror(const GcGeLine2d& line);
  GcGeEntity2d&    scaleBy(double scaleFactor,
    const GcGePoint2d& wrtPoint
    = GcGePoint2d::kOrigin);
  Gsoft::Boolean   isOn(const GcGePoint2d& pnt,
    const GcGeTol& tol = GcGeContext::gTol) const;
protected:
  friend class GcGeEntity3d;
  friend class GcGeImpEntity3d;
  class GcGeImpEntity3d* mpImpEnt;
  int mDelEnt;
  GcGeEntity2d();
  GcGeEntity2d(const GcGeEntity2d&);
  GcGeEntity2d(GcGeImpEntity3d&, int);
  GcGeEntity2d(GcGeImpEntity3d*);
  GcGeEntity2d*    newEntity2d(GcGeImpEntity3d*) const;
};

inline GcGeEntity2d*
GcGeEntity2d::newEntity2d(GcGeImpEntity3d *impEnt) const
{
  return GENEWLOC(GcGeEntity2d, this) (impEnt);
}

#pragma pack (pop)
#endif
