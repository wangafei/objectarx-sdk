/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEVEC3D_H
#define GC_GEVEC3D_H

#include "gsoft.h"
#include "gegbl.h"
#include "gegblabb.h"
#pragma pack (push, 8)

class GcGeMatrix3d;
class GcGeVector2d;
class GcGePlane;
class GcGePlanarEnt;

class GE_DLLDATAEXIMP GcGeVector3d
{
public:
  GcGeVector3d();
  GcGeVector3d(const GcGeVector3d& vec);
  GcGeVector3d(double x, double y, double z);
  GcGeVector3d(const GcGePlanarEnt&, const GcGeVector2d&);

  static const   GcGeVector3d kIdentity;
  static const   GcGeVector3d kXAxis;
  static const   GcGeVector3d kYAxis;
  static const   GcGeVector3d kZAxis;

  friend GE_DLLEXPIMPORT GcGeVector3d   operator *  (const GcGeMatrix3d& mat, const GcGeVector3d& vec);
  GcGeVector3d&  setToProduct(const GcGeMatrix3d& mat, const GcGeVector3d& vec);
  GcGeVector3d&  transformBy(const GcGeMatrix3d& leftSide);
  GcGeVector3d&  rotateBy(double ang, const GcGeVector3d& axis);
  GcGeVector3d&  mirror(const GcGeVector3d& normalToPlane);
  GcGeVector2d   convert2d(const GcGePlanarEnt& pln) const;

  GcGeVector3d   operator *  (double scl) const;
  friend GE_DLLEXPIMPORT GcGeVector3d   operator *  (double scl, const GcGeVector3d& vec);

  GcGeVector3d&  operator *= (double scl);
  GcGeVector3d&  setToProduct(const GcGeVector3d& vec, double scl);
  GcGeVector3d   operator /  (double scl) const;
  GcGeVector3d&  operator /= (double scl);

  GcGeVector3d   operator +  (const GcGeVector3d& vec) const;
  GcGeVector3d&  operator += (const GcGeVector3d& vec);
  GcGeVector3d   operator -  (const GcGeVector3d& vec) const;
  GcGeVector3d&  operator -= (const GcGeVector3d& vec);
  GcGeVector3d&  setToSum(const GcGeVector3d& vec1, const GcGeVector3d& vec2);
  GcGeVector3d   operator -  () const;
  GcGeVector3d&  negate();

  GcGeVector3d   perpVector() const;

  double         angleTo(const GcGeVector3d& vec) const;
  double         angleTo(const GcGeVector3d& vec, const GcGeVector3d& refVec) const;
  double         angleOnPlane(const GcGePlanarEnt& pln) const;

  GcGeVector3d   normal(const GcGeTol& tol = GcGeContext::gTol) const;
  GcGeVector3d&  normalize(const GcGeTol& tol = GcGeContext::gTol);
  GcGeVector3d&  normalize(const GcGeTol& tol, GcGeError& flag);
  double         length() const;
  double         lengthSqrd() const;
  Gsoft::Boolean isUnitLength(const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isZeroLength(const GcGeTol& tol = GcGeContext::gTol) const;

  Gsoft::Boolean isParallelTo(const GcGeVector3d& vec, const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isParallelTo(const GcGeVector3d& vec, const GcGeTol& tol, GcGeError& flag) const;

  Gsoft::Boolean isCodirectionalTo(const GcGeVector3d& vec, const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isCodirectionalTo(const GcGeVector3d& vec, const GcGeTol& tol, GcGeError& flag) const;

  Gsoft::Boolean isPerpendicularTo(const GcGeVector3d& vec, const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isPerpendicularTo(const GcGeVector3d& vec, const GcGeTol& tol, GcGeError& flag) const;

  double         dotProduct(const GcGeVector3d& vec) const;
  GcGeVector3d   crossProduct(const GcGeVector3d& vec) const;
  GcGeMatrix3d   rotateTo(const GcGeVector3d& vec, const GcGeVector3d& axis = GcGeVector3d::kIdentity) const;

  GcGeVector3d   project(const GcGeVector3d& planeNormal, const GcGeVector3d& projectDirection) const;
  GcGeVector3d   project(const GcGeVector3d& planeNormal, const GcGeVector3d& projectDirection, const GcGeTol& tol, GcGeError& flag) const;
  GcGeVector3d   orthoProject(const GcGeVector3d& planeNormal) const;
  GcGeVector3d   orthoProject(const GcGeVector3d& planeNormal, const GcGeTol& tol, GcGeError& flag) const;

  bool operator == (const GcGeVector3d& vec) const;
  bool operator != (const GcGeVector3d& vec) const;
  bool isEqualTo(const GcGeVector3d& vec, const GcGeTol& tol = GcGeContext::gTol) const;

  double         operator [] (unsigned int i) const;
  double&        operator [] (unsigned int i);
  unsigned int   largestElement() const;
  GcGeVector3d&  set(double x, double y, double z);
  GcGeVector3d&  set(const GcGePlanarEnt& pln, const GcGeVector2d& vec);

  operator GcGeMatrix3d() const;

  double         x, y, z;
};

inline GcGeVector3d::GcGeVector3d() : x(0.0), y(0.0), z(0.0)
{
}

inline GcGeVector3d::GcGeVector3d(const GcGeVector3d& src) : x(src.x), y(src.y), z(src.z)
{  
}

inline GcGeVector3d::GcGeVector3d(double xx, double yy, double zz) : x(xx), y(yy), z(zz)
{
}

inline bool GcGeVector3d::operator == (const GcGeVector3d& v) const
{
  return this->isEqualTo(v);
}

inline bool GcGeVector3d::operator != (const GcGeVector3d& v) const
{
  return !this->isEqualTo(v);
}

inline GcGeVector3d GcGeVector3d::operator + (const GcGeVector3d& v) const
{
  return GcGeVector3d(x + v.x, y + v.y, z + v.z);
}

inline GcGeVector3d& GcGeVector3d::operator += (const GcGeVector3d& v)
{
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}

inline GcGeVector3d GcGeVector3d::operator - (const GcGeVector3d& v) const
{
  return GcGeVector3d(x - v.x, y - v.y, z - v.z);
}

inline GcGeVector3d& GcGeVector3d::operator -= (const GcGeVector3d& v)
{
  x -= v.x;
  y -= v.y;
  z -= v.z;
  return *this;
}

inline GcGeVector3d& GcGeVector3d::setToSum(const GcGeVector3d& v1, const GcGeVector3d& v2)
{
  x = v1.x + v2.x;
  y = v1.y + v2.y;
  z = v1.z + v2.z;
  return *this;
}

inline GcGeVector3d GcGeVector3d::operator - () const
{
  return GcGeVector3d(-x, -y, -z);
}

inline GcGeVector3d& GcGeVector3d::negate()
{
  x = -x;
  y = -y;
  z = -z;
  return *this;
}

inline GcGeVector3d GcGeVector3d::operator * (double s) const
{
  return GcGeVector3d(x * s, y * s, z * s);
}

inline GcGeVector3d& GcGeVector3d::operator *= (double s)
{
  x *= s;
  y *= s;
  z *= s;
  return *this;
}

inline GcGeVector3d& GcGeVector3d::setToProduct(const GcGeVector3d& v, double s)
{
  x = s * v.x;
  y = s * v.y;
  z = s * v.z;
  return *this;
}

inline GcGeVector3d GcGeVector3d::operator / (double val) const
{
  return GcGeVector3d(x / val, y / val, z / val);
}

inline GcGeVector3d& GcGeVector3d::operator /= (double val)
{
  x /= val;
  y /= val;
  z /= val;
  return *this;
}

inline double GcGeVector3d::lengthSqrd() const
{
  return x * x + y * y + z * z;
}

inline double GcGeVector3d::dotProduct(const GcGeVector3d& v) const
{
  return x * v.x + y * v.y + z * v.z;
}

inline GcGeVector3d& GcGeVector3d::set(double xx, double yy, double zz)
{
  x = xx;
  y = yy;
  z = zz;
  return *this;
}

inline double GcGeVector3d::operator [] (unsigned int i) const
{
  return *(&x + i);
}

inline double& GcGeVector3d::operator [] (unsigned int i)
{
  return *(&x + i);
}
#define GSFT_GCGEVECTOR3D_DEFINED
#include "gcarrayhelper.h"

#pragma pack (pop)
#endif
