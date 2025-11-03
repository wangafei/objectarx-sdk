/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEPENT3D_H
#define GC_GEPENT3D_H

#include "gsoft.h"
#include "geent3d.h"
#pragma pack (push, 8)

class GE_DLLDATAEXIMP GcGePointEnt3d : public GcGeEntity3d
{
public:
  GcGePoint3d     point3d() const;
  operator GcGePoint3d () const;
  GcGePointEnt3d& operator =  (const GcGePointEnt3d& pnt);

protected:
  GcGePointEnt3d();
  GcGePointEnt3d(const GcGePointEnt3d&);
};

#pragma pack (pop)
#endif
