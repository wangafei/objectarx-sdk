#ifndef __FMMDL_INTVECTOR3D_H__
#define __FMMDL_INTVECTOR3D_H__

#include "../FacetModeler/Modeler/FMMdlBase.h"

namespace FacetModeler
{
  class FMGEOMETRY_API IntVector3d
  {
  public:

    IntVector3d(int xx, int yy, int zz) : x(xx), y(yy), z(zz) {}

    IntVector3d operator  +(IntVector3d v) const { return IntVector3d(x+v.x, y+v.y, z+v.z); }
    IntVector3d operator  -(IntVector3d v) const { return IntVector3d(x-v.x, y-v.y, z-v.z); }

    int         operator [](int index)     const { return (&x)[index]; }
    int&        operator [](int index)           { return (&x)[index]; }

    bool        operator ==(IntVector3d v) const { return x == v.x && y == v.y && z == v.z; }
    bool        operator !=(IntVector3d v) const { return !(*this == v); }

    void        operator +=(IntVector3d v)       { x += v.x; y += v.y; z += v.z; }
    void        operator -=(IntVector3d v)       { x -= v.x; y -= v.y; z -= v.z; }

    int x, y, z;

  };
}

#endif //__FMMDL_INTVECTOR3D_H__
