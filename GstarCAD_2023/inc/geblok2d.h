/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEBLOCK2D_H
#define GC_GEBLOCK2D_H

#include "geent2d.h"
#pragma pack (push, 8)
class GcGePoint2d;
class GcGeVector2d;

class
  GE_DLLDATAEXIMP
  GcGeBoundBlock2d : public GcGeEntity2d
{
public:
  GcGeBoundBlock2d();
  GcGeBoundBlock2d(const GcGePoint2d& point1, const GcGePoint2d& point2);
  GcGeBoundBlock2d(const GcGePoint2d& base,
    const GcGeVector2d& dir1, const GcGeVector2d& dir2);
  GcGeBoundBlock2d(const GcGeBoundBlock2d& block);

  void              getMinMaxPoints(GcGePoint2d& point1,
    GcGePoint2d& point2) const;
  void              get(GcGePoint2d& base,
    GcGeVector2d& dir1,
    GcGeVector2d& dir2) const;
  GcGeBoundBlock2d& set(const GcGePoint2d& point1,
    const GcGePoint2d& point2);
  GcGeBoundBlock2d& set(const GcGePoint2d& base,
    const GcGeVector2d& dir1,
    const GcGeVector2d& dir2);
  GcGeBoundBlock2d& extend(const GcGePoint2d& point);
  GcGeBoundBlock2d& swell(double distance);
  Gsoft::Boolean    contains(const GcGePoint2d& point) const;
  Gsoft::Boolean    isDisjoint(const GcGeBoundBlock2d& block)
    const;
  GcGeBoundBlock2d& operator =  (const GcGeBoundBlock2d& block);

  Gsoft::Boolean    isBox() const;
  GcGeBoundBlock2d& setToBox(Gsoft::Boolean);
};


#pragma pack (pop)
#endif