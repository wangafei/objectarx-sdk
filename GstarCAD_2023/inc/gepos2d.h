/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEPOS2D_H
#define GC_GEPOS2D_H

#include "gsoft.h"
#include "gepent2d.h"
#pragma pack (push, 8)

class GE_DLLDATAEXIMP GcGePosition2d : public GcGePointEnt2d
{
public:
  GcGePosition2d();
  GcGePosition2d(const GcGePoint2d& pnt);
  GcGePosition2d(double x, double y);
  GcGePosition2d(const GcGePosition2d& pos);

  GcGePosition2d&  set(const GcGePoint2d&);
  GcGePosition2d&  set(double x, double y);

  GcGePosition2d& operator =  (const GcGePosition2d& pos);
};

#pragma pack (pop)
#endif
