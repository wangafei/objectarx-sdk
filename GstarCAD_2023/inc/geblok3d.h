/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEBLOCK3D_H
#define GC_GEBLOCK3D_H

#include "geent3d.h"
#pragma pack (push, 8)
class GcGePoint3d;
class GcGeVector3d;

class
  GE_DLLDATAEXIMP
  GcGeBoundBlock3d : public GcGeEntity3d
{
public:
  GcGeBoundBlock3d();
  GcGeBoundBlock3d(const GcGePoint3d& base, const GcGeVector3d& dir1,
    const GcGeVector3d& dir2, const GcGeVector3d& dir3);
  GcGeBoundBlock3d(const GcGeBoundBlock3d& block);

  void              getMinMaxPoints(GcGePoint3d& point1,
    GcGePoint3d& point2) const;
  void              get(GcGePoint3d& base,
    GcGeVector3d& dir1,
    GcGeVector3d& dir2,
    GcGeVector3d& dir3) const;
  GcGeBoundBlock3d& set(const GcGePoint3d& point1,
    const GcGePoint3d& point2);
  GcGeBoundBlock3d& set(const GcGePoint3d& base,
    const GcGeVector3d& dir1,
    const GcGeVector3d& dir2,
    const GcGeVector3d& dir3);
  GcGeBoundBlock3d& extend(const GcGePoint3d& point);
  GcGeBoundBlock3d& swell(double distance);
  Gsoft::Boolean    contains(const GcGePoint3d& point) const;
  Gsoft::Boolean    isDisjoint(const GcGeBoundBlock3d& block) const;

  GcGeBoundBlock3d& operator =       (const GcGeBoundBlock3d& block);

  Gsoft::Boolean     isBox() const;
  GcGeBoundBlock3d&  setToBox(Gsoft::Boolean);
};


#pragma pack (pop)
#endif