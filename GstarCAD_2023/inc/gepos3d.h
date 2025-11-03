/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEPOS3D_H
#define GC_GEPOS3D_H

#include "gsoft.h"
#include "gepent3d.h"
#include "gepnt3d.h"
#pragma pack (push, 8)

class GE_DLLDATAEXIMP GcGePosition3d : public GcGePointEnt3d
{
public:
  GcGePosition3d();
  GcGePosition3d(const GcGePoint3d& pnt);
  GcGePosition3d(double x, double y, double z);
  GcGePosition3d(const GcGePosition3d& pos);

  GcGePosition3d&  set(const GcGePoint3d&);
  GcGePosition3d&  set(double x, double y, double z);

  GcGePosition3d& operator =  (const GcGePosition3d& pos);
};

#pragma pack (pop)
#endif
