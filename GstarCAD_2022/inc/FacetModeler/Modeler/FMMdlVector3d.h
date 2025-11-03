#ifndef __FMMDL_VECTOR3D_H__
#define __FMMDL_VECTOR3D_H__


#include <math.h>
#include "../FacetModeler/Modeler/FMMdlIntVector3d.h"
#include "../FacetModeler/Modeler/FMMdlVector2d.h"

namespace FacetModeler
{

  class Transf3d;

  class FMGEOMETRY_API Vector3d
  {
  public:

    Vector3d(): x(0.),   y(0.),   z(0.) {} 
    Vector3d(double xx, double yy, double zz) : x(xx),   y(yy),   z(zz)   {}
    Vector3d(Vector2d     v)                  : x(v.x),  y(v.y),  z(0)    {}
    Vector3d(IntVector3d iv)                  : x(iv.x), y(iv.y), z(iv.z) {}

    Vector3d operator + (Vector3d v)    const { return Vector3d(x+v.x, y+v.y, z+v.z); }
    Vector3d operator - (Vector3d v)    const { return Vector3d(x-v.x, y-v.y, z-v.z); }
    double   operator % (Vector3d v)    const { return x*v.x+y*v.y+z*v.z;             }
    Vector3d operator * (Vector3d v)    const;
    Vector3d operator - ()              const { return Vector3d(-x, -y, -z);          }

    Vector3d operator * (double scalar) const { return Vector3d(x*scalar, y*scalar, z*scalar); }
    Vector3d operator / (double scalar) const { return Vector3d(x/scalar, y/scalar, z/scalar); }

    double   operator [](int index)     const { return (&x)[index]; }
    double&  operator [](int index)           { return (&x)[index]; }

    double   length     ()              const { return sqrt(x*x+y*y+z*z);       }
    double   lengthSqrd ()              const { return x*x+y*y+z*z;             }
    double   lengthRect ()              const { return fabs(x)+fabs(y)+fabs(z); }

    Vector3d normalize  () const;

    double   dist       (Vector3d v)    const { return (*this-v).length();     }
    double   distSqrd   (Vector3d v)    const { return (*this-v).lengthSqrd(); }
    double   distRect   (Vector3d v)    const { return (*this-v).lengthRect(); }

    bool     isEqual    (Vector3d v, double epsSqrd = epsNorSqrd()) const { return (distSqrd(v) <= epsSqrd); }
    bool     isEqualRect(Vector3d v, double epsRect = epsNor()    ) const { return (distRect(v) <= epsRect); }

    double   angle      (const Vector3d&) const;

    void     operator +=(Vector3d    v) { x += v.x; y += v.y; z += v.z; }
    void     operator -=(Vector3d    v) { x -= v.x; y -= v.y; z -= v.z; }
    void     operator *=(double scalar) { x *= scalar; y *= scalar; z *= scalar; }
    void     operator /=(double scalar) { x /= scalar; y /= scalar; z /= scalar; }

    Vector3d perpend() const;

    void     operator *=(const Transf3d&);

    bool     isNull     (double epsSqrd = epsNorSqrd()) const { return lengthSqrd() <= epsSqrd; }
    bool     isParallel (const Vector3d&, double epsNorSqrd = epsNorSqrd()) const;
    bool     isParallelNorm(const Vector3d&, double epsNorSqrd = epsNorSqrd()) const; // For normalized vectors
    bool     isPerpend  (const Vector3d&, double epsNor = epsNor()) const;
    bool     isExactNull() const { return x == 0 && y == 0 && z == 0; }

    void     orthoPlane (int& i1, int& i2)          const;
    void     orthoPlane (int& i1, int& i2, int& i3) const;

    int      dominantDirection() const;

    const Vector2d& toVector2d ()               const { return *((Vector2d*)this);             }
    Vector2d        toVector2d (int i1, int i2) const { return Vector2d((*this)[i1], (*this)[i2]); }
    Vector2d        toVector2d (int dropCoord ) const; 

    operator       OdGeVector3d& ()       { return *((OdGeVector3d*)this);       }
    operator const OdGeVector3d& () const { return *((const OdGeVector3d*)this); }

    static Vector3d& cast(OdGeVector3d& v) { return *(Vector3d*)&v; }

    Vector3d(const OdGeVector3d& v)        { *this = *(Vector3d*)&v; }

    static Vector3d random();

    double x, y, z;

    static const Vector3d kNull;
    static const Vector3d kXDir;
    static const Vector3d kYDir;
    static const Vector3d kZDir;

  };


  inline Vector3d& asVector3d(OdGeVector3d& v) { return *(Vector3d*)&v; }


  inline Vector3d operator *(double scalar, Vector3d v) 
  { 
    return Vector3d(scalar*v.x, scalar*v.y, scalar*v.z); 
  }

  inline Vector3d Vector3d::operator *(Vector3d v) const
  {
    return Vector3d(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
  }

  inline double det(Vector3d a, Vector3d b, Vector3d c)
  {
    return (a.x * (b.y*c.z - b.z*c.y) +
      a.y * (b.z*c.x - b.x*c.z) +
      a.z * (b.x*c.y - b.y*c.x));
  } 

  inline Vector2d Vector3d::toVector2d (int dropCoord) const
  {
    switch (dropCoord)
    {
    case 0:
      return Vector2d(y, z);
      break;
    case 1:
      return Vector2d(z, x);
      break;
    case 2:
    default:
      return Vector2d(x, y);
    }
  }
}

#endif //__FMMDL_VECTOR3D_H__
