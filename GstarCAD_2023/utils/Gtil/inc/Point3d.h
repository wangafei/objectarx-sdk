/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif

#ifndef POINT3D_H
#define POINT3D_H

namespace Gtil
{
  class GTIL_EXPORT Point3d
  {
  public:
    double x;
    double y;
    double z;
  public:
    Point3d();
    Point3d(int valueX, int  valueY, int valueZ);
    Point3d(double valueX, double valueY, double valueZ);
    ~Point3d();

    const Point3d& set(int valueX, int  valueY, int valueZ);
    const Point3d& set(double valueX, double valueY, double valueZ);

    bool operator==(const Point3d& rhs) const;
    bool operator!=(const Point3d& rhs) const;
  };
}

#endif
