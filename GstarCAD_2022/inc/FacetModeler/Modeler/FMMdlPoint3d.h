#ifndef __FMMDL_POINT3D_H__
#define __FMMDL_POINT3D_H__

#include "../FacetModeler/Modeler/FMMdlVector3d.h"
#include "../FacetModeler/Modeler/FMMdlIntPoint3d.h"
#include "../FacetModeler/Modeler/FMMdlPoint2d.h"

namespace FacetModeler
{

  class FMGEOMETRY_API Point3d
  {
  public:

    Point3d() : x(0.), y(0.), z(0.) {} 
    Point3d(double xx, double yy, double zz) : x(xx), y(yy), z(zz)       {}
    Point3d(IntPoint3d ip)                   : x(ip.x), y(ip.y), z(ip.z) {}
    Point3d(Point2d     p)                   : x(p.x), y(p.y), z(0)      {}

    Point3d  operator  +(Point3d  p) const { return Point3d (x+p.x, y+p.y, z+p.z); }
    Point3d  operator  +(Vector3d v) const { return Point3d (x+v.x, y+v.y, z+v.z); }
    Vector3d operator  -(Point3d  p) const { return Vector3d(x-p.x, y-p.y, z-p.z); }
    Point3d  operator  -(Vector3d v) const { return Point3d (x-v.x, y-v.y, z-v.z); }
    Point3d  operator  -()           const { return Point3d(-x, -y, -z);           }

    Point3d  operator  *(double scalar) const { return Point3d(x*scalar, y*scalar, z*scalar); }
    Point3d  operator  /(double scalar) const { return Point3d(x/scalar, y/scalar, z/scalar); }

    double   operator  %(Vector3d v) const { return x*v.x+y*v.y+z*v.z; }

    double   operator [](int index) const { return (&x)[index]; }
    double&  operator [](int index)       { return (&x)[index]; }

    double   length     ()          const { return sqrt(x*x+y*y+z*z);       }
    double   lengthSqrd ()          const { return x*x+y*y+z*z;             }
    double   lengthRect ()          const { return fabs(x)+fabs(y)+fabs(z); }

    double   dist       (Point3d p) const { return sqrt(sqr(x-p.x)+sqr(y-p.y)+sqr(z-p.z)); }
    double   distSqrd   (Point3d p) const { return sqr(x-p.x)+sqr(y-p.y)+sqr(z-p.z);       }
    double   distRect   (Point3d p) const { return fabs(x-p.x)+fabs(y-p.y)+fabs(z-p.z);    }

    bool     isEqual    (Point3d p, double epsSqrd = epsAbsSqrd()) const { return (distSqrd(p) <= epsSqrd); }
    bool     isEqualRect(Point3d p, double epsRect = epsAbs    ()) const { return (distRect(p) <= epsRect); }

    void     operator +=(Point3d     p) { x += p.x; y += p.y; z += p.z; }
    void     operator +=(Vector3d    v) { x += v.x; y += v.y; z += v.z; }
    void     operator -=(Point3d     p) { x -= p.x; y -= p.y; z -= p.z; }
    void     operator -=(Vector3d    v) { x -= v.x; y -= v.y; z -= v.z; }
    void     operator *=(double scalar) { x *= scalar; y *= scalar; z *= scalar; }
    void     operator /=(double scalar) { x /= scalar; y /= scalar; z /= scalar; }

    void     operator *=(const Transf3d&);

    Point3d  project    (const Transf3d&) const;

    bool     isBetween  (const Point3d& p1, const Point3d& p2) const;

    bool     isValid    () const { return fabs(x) < kMaxReal && fabs(y) < kMaxReal && fabs(z) < kMaxReal; }

    Point2d  toPoint2d  ()               const { return *((Point2d*)this);                 }
    Point2d  toPoint2d  (int i1, int i2) const { return Point2d((*this)[i1], (*this)[i2]); }
    Point2d  toPoint2d  (int dropCoord ) const; 
    Vector3d toVector3d ()               const { return *(Vector3d*)this;                  }

    operator       OdGePoint3d& ()       { return *((OdGePoint3d*)this);       }
    operator const OdGePoint3d& () const { return *((const OdGePoint3d*)this); }

    static Point3d& cast(OdGePoint3d& p) { return *(Point3d*)&p; }

    Point3d(const OdGePoint3d& p)        { *this = *(Point3d*)&p; }

    double x, y, z;

    static const Point3d kNull;

  };

  inline Point3d operator *(double scalar, Point3d p) 
  { 
    return Point3d(scalar*p.x, scalar*p.y, scalar*p.z); 
  }

  inline double det(Point3d a, Point3d b, Point3d c)
  {
    return (a.x * (b.y*c.z - b.z*c.y) +
      a.y * (b.z*c.x - b.x*c.z) +
      a.z * (b.x*c.y - b.y*c.x));
  } 

  inline Point2d Point3d::toPoint2d(int dropCoord) const
  {
    switch (dropCoord)
    {
    case 0:
      return Point2d(y, z);
      break;
    case 1:
      return Point2d(z, x);
      break;
    case 2:
    default:
      return Point2d(x, y);
    }
  }

  FMGEOMETRY_API bool areCoplanar(Point3d, Point3d, Point3d, Point3d);  
}

#endif //__FMMDL_POINT3D_H__
