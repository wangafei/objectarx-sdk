/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GERAY2D_H
#define GC_GERAY2D_H

#include "gelent2d.h"
#pragma pack (push, 8)

class GE_DLLDATAEXIMP GcGeRay2d : public GcGeLinearEnt2d
{
public:
  GcGeRay2d();
  GcGeRay2d(const GcGeRay2d& line);
  GcGeRay2d(const GcGePoint2d& pnt, const GcGeVector2d& vec);
  GcGeRay2d(const GcGePoint2d& pnt1, const GcGePoint2d& pnt2);

  GcGeRay2d&     set(const GcGePoint2d& pnt, const GcGeVector2d& vec);
  GcGeRay2d&     set(const GcGePoint2d& pnt1, const GcGePoint2d& pnt2);

  GcGeRay2d&     operator =  (const GcGeRay2d& line);
};

#pragma pack (pop)
#endif
