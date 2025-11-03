/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GELINE2D_H
#define GC_GELINE2D_H

#include "gelent2d.h"
#pragma pack (push, 8)

class GE_DLLDATAEXIMP GcGeLine2d : public GcGeLinearEnt2d
{
public:
  GcGeLine2d();
  GcGeLine2d(const GcGeLine2d& line);
  GcGeLine2d(const GcGePoint2d& pnt, const GcGeVector2d& vec);
  GcGeLine2d(const GcGePoint2d& pnt1, const GcGePoint2d& pnt2);

  static const GcGeLine2d kXAxis;
  static const GcGeLine2d kYAxis;

  GcGeLine2d& set(const GcGePoint2d& pnt, const GcGeVector2d& vec);
  GcGeLine2d& set(const GcGePoint2d& pnt1, const GcGePoint2d& pnt2);

  GcGeLine2d& operator = (const GcGeLine2d& line);
};

#pragma pack (pop)
#endif
