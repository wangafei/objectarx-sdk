/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GELINE3D_H
#define GC_GELINE3D_H

#include "gelent3d.h"
#pragma pack (push, 8)

class GcGeLine2d;

class GE_DLLDATAEXIMP GcGeLine3d : public GcGeLinearEnt3d
{
public:
  GcGeLine3d();
  GcGeLine3d(const GcGeLine3d& line);
  GcGeLine3d(const GcGePoint3d& pnt, const GcGeVector3d& vec);
  GcGeLine3d(const GcGePoint3d& pnt1, const GcGePoint3d& pnt2);

  static const GcGeLine3d kXAxis;
  static const GcGeLine3d kYAxis;
  static const GcGeLine3d kZAxis;

  GcGeLine3d& set(const GcGePoint3d& pnt, const GcGeVector3d& vec);
  GcGeLine3d& set(const GcGePoint3d& pnt1, const GcGePoint3d& pnt2);

  GcGeLine3d& operator = (const GcGeLine3d& line);
};

#pragma pack (pop)
#endif
