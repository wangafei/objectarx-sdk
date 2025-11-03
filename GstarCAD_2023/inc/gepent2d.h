/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEPENT2D_H
#define GC_GEPENT2D_H

#include "gsoft.h"
#include "geent2d.h"
#include "gepnt2d.h"
#pragma pack (push, 8)

class GE_DLLDATAEXIMP GcGePointEnt2d : public GcGeEntity2d
{
public:
  GcGePoint2d     point2d() const;
  operator GcGePoint2d () const;
  GcGePointEnt2d& operator =  (const GcGePointEnt2d& pnt);

protected:
  GcGePointEnt2d();
  GcGePointEnt2d(const GcGePointEnt2d&);
};

#pragma pack (pop)
#endif
