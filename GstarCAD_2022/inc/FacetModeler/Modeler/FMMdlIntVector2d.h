#ifndef __FMMDL_INTVECTOR2D_H__
#define __FMMDL_INTVECTOR2D_H__

#include "../FacetModeler/Modeler/FMMdlBase.h"

namespace FacetModeler
{
  class FMGEOMETRY_API IntVector2d
  {
  public:

    IntVector2d(int xx, int yy) : x(xx), y(yy) {}

    IntVector2d operator  +(IntVector2d v) const { return IntVector2d(x+v.x, y+v.y); }
    IntVector2d operator  -(IntVector2d v) const { return IntVector2d(x-v.x, y-v.y); }

    int         operator [](int index)     const { return (&x)[index]; }
    int&        operator [](int index)           { return (&x)[index]; }

    bool        operator ==(IntVector2d v) const { return x == v.x && y == v.y; }
    bool        operator !=(IntVector2d v) const { return !(*this == v); }

    void        operator +=(IntVector2d v)       { x += v.x; y += v.y; }
    void        operator -=(IntVector2d v)       { x -= v.x; y -= v.y; }

    int x, y;

  }; 

}

#endif //__FMMDL_INTVECTOR2D_H__
