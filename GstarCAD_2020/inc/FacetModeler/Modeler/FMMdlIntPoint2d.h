#ifndef __FMMDL_INTPOINT2D_H__
#define __FMMDL_INTPOINT2D_H__

#include "../FacetModeler/Modeler/FMMdlBase.h"
#include "../FacetModeler/Modeler/FMMdlIntVector2d.h"

namespace FacetModeler
{
  class FMGEOMETRY_API IntPoint2d
  {
  public:

    IntPoint2d() {} 
    IntPoint2d(int xx, int yy) : x(xx), y(yy) {}

    IntPoint2d  operator  +(IntPoint2d  p) const { return IntPoint2d (x+p.x, y+p.y); }
    IntPoint2d  operator  +(IntVector2d v) const { return IntPoint2d (x+v.x, y+v.y); }
    IntVector2d operator  -(IntPoint2d  p) const { return IntVector2d(x-p.x, y-p.y); }
    IntPoint2d  operator  -(IntVector2d v) const { return IntPoint2d (x-v.x, y-v.y); }
    IntPoint2d  operator  -()              const { return IntPoint2d(-x, -y);        }

    int         operator [](int index)     const { return (&x)[index]; }
    int&        operator [](int index)           { return (&x)[index]; }

    bool        operator ==(IntPoint2d  p) const { return x == p.x && y == p.y; }
    bool        operator !=(IntPoint2d  p) const { return !(*this == p); }

    void        operator +=(IntPoint2d  p) { x += p.x; y += p.y; }
    void        operator +=(IntVector2d v) { x += v.x; y += v.y; }
    void        operator -=(IntPoint2d  p) { x -= p.x; y -= p.y; }
    void        operator -=(IntVector2d v) { x -= v.x; y -= v.y; }

    int x, y;

    static const IntPoint2d kNull;

  };
}

#endif //__FMMDL_INTPOINT2D_H__
