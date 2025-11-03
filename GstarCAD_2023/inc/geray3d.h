/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GERAY3D_H
#define GC_GERAY3D_H

#include "gelent3d.h"
#pragma pack (push, 8)

class GcGeRay2d;

class GE_DLLDATAEXIMP GcGeRay3d : public GcGeLinearEnt3d
{
public:
  GcGeRay3d();
  GcGeRay3d(const GcGeRay3d& line);
  GcGeRay3d(const GcGePoint3d& pnt, const GcGeVector3d& vec);
  GcGeRay3d(const GcGePoint3d& pnt1, const GcGePoint3d& pnt2);

  GcGeRay3d&     set(const GcGePoint3d& pnt, const GcGeVector3d& vec);
  GcGeRay3d&     set(const GcGePoint3d& pnt1, const GcGePoint3d& pnt2);

  GcGeRay3d&     operator =  (const GcGeRay3d& line);
};

#pragma pack (pop)
#endif
