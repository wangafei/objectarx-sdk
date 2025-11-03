/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEPNT3D_H
#define GC_GEPNT3D_H

#include "gevec3d.h"
#pragma pack (push, 8)

class GcGeMatrix3d;
class GcGeLinearEnt3d;
class GcGePlane;
class GcGePlanarEnt;
class GcGeVector3d;
class GcGePoint2d;

class GE_DLLDATAEXIMP GcGePoint3d
{
public:
  GcGePoint3d();
  GcGePoint3d(const GcGePoint3d& pnt);
  GcGePoint3d(double x, double y, double z);
  GcGePoint3d(const GcGePlanarEnt& pln, const GcGePoint2d& pnt2d);

  static const   GcGePoint3d    kOrigin;

  friend GE_DLLEXPIMPORT GcGePoint3d    operator *  (const GcGeMatrix3d& mat, const GcGePoint3d& pnt);

  GcGePoint3d&   setToProduct(const GcGeMatrix3d& mat, const GcGePoint3d& pnt);
  GcGePoint3d&   transformBy(const GcGeMatrix3d& leftSide);
  GcGePoint3d&   rotateBy(double angle, const GcGeVector3d& vec, const GcGePoint3d& wrtPoint = GcGePoint3d::kOrigin);
  GcGePoint3d&   mirror(const GcGePlane& pln);
  GcGePoint3d&   scaleBy(double scaleFactor, const GcGePoint3d& wrtPoint = GcGePoint3d::kOrigin);
  GcGePoint2d    convert2d(const GcGePlanarEnt& pln) const;

  GcGePoint3d    operator *  (double scl) const;
  GE_DLLEXPIMPORT friend GcGePoint3d    operator *  (double scl, const GcGePoint3d& pnt);
  GcGePoint3d&   operator *= (double scl);
  GcGePoint3d    operator /  (double scl) const;
  GcGePoint3d&   operator /= (double scl);

  GcGePoint3d    operator +  (const GcGeVector3d& vec) const;
  GcGePoint3d&   operator += (const GcGeVector3d& vec);
  GcGePoint3d    operator -  (const GcGeVector3d& vec) const;
  GcGePoint3d&   operator -= (const GcGeVector3d& vec);
  GcGePoint3d&   setToSum(const GcGePoint3d& pnt, const GcGeVector3d& vec);

  GcGeVector3d   operator -  (const GcGePoint3d& pnt) const;
  GcGeVector3d   asVector() const;

  double         distanceTo(const GcGePoint3d& pnt) const;

  GcGePoint3d    project(const GcGePlane& pln, const GcGeVector3d& vec) const;
  GcGePoint3d    orthoProject(const GcGePlane& pln) const;

  bool operator == (const GcGePoint3d& pnt) const;
  bool operator != (const GcGePoint3d& pnt) const;
  bool isEqualTo(const GcGePoint3d& pnt, const GcGeTol& tol = GcGeContext::gTol) const;

  double         operator [] (unsigned int i) const;
  double&        operator [] (unsigned int idx);
  GcGePoint3d&   set(double x, double y, double z);
  GcGePoint3d&   set(const GcGePlanarEnt& pln, const GcGePoint2d& pnt);

  double         x, y, z;
};

inline GcGePoint3d::GcGePoint3d() : x(0.0), y(0.0), z(0.0)
{
}

inline GcGePoint3d::GcGePoint3d(const GcGePoint3d& src) : x(src.x), y(src.y), z(src.z)
{ 
}

inline GcGePoint3d::GcGePoint3d(double xx, double yy, double zz) : x(xx), y(yy), z(zz)
{
}

inline bool GcGePoint3d::operator == (const GcGePoint3d& p) const
{
  return this->isEqualTo(p);
}

inline bool GcGePoint3d::operator != (const GcGePoint3d& p) const
{
  return !this->isEqualTo(p);
}

inline GcGePoint3d GcGePoint3d::operator * (double val) const
{
  return GcGePoint3d(x*val, y*val, z*val);
}

inline GcGePoint3d operator * (double val, const GcGePoint3d& p)
{
  return GcGePoint3d(p.x*val, p.y*val, p.z*val);
}

inline GcGePoint3d& GcGePoint3d::operator *= (double val)
{
  x *= val;
  y *= val;
  z *= val;
  return *this;
}

inline GcGePoint3d GcGePoint3d::operator / (double val) const
{
  return GcGePoint3d(x / val, y / val, z / val);
}

inline GcGePoint3d& GcGePoint3d::operator /= (double val)
{
  x /= val;
  y /= val;
  z /= val;
  return *this;
}

inline GcGePoint3d GcGePoint3d::operator + (const GcGeVector3d& v) const
{
  return GcGePoint3d(x + v.x, y + v.y, z + v.z);
}

inline GcGePoint3d& GcGePoint3d::operator += (const GcGeVector3d& v)
{
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}

inline GcGePoint3d GcGePoint3d::operator - (const GcGeVector3d& v) const
{
  return GcGePoint3d(x - v.x, y - v.y, z - v.z);
}

inline GcGePoint3d& GcGePoint3d::operator -= (const GcGeVector3d& v)
{
  x -= v.x;
  y -= v.y;
  z -= v.z;
  return *this;
}

inline GcGeVector3d GcGePoint3d::operator - (const GcGePoint3d& p) const
{
  return GcGeVector3d(x - p.x, y - p.y, z - p.z);
}

inline GcGeVector3d GcGePoint3d::asVector() const
{
  return GcGeVector3d(x, y, z);
}

inline GcGePoint3d& GcGePoint3d::set(double xx, double yy, double zz)
{
  x = xx;
  y = yy;
  z = zz;
  return *this;
}

inline double GcGePoint3d::operator [] (unsigned int i) const
{
  return *(&x + i);
}

inline double& GcGePoint3d::operator [] (unsigned int i)
{
  return *(&x + i);
}

#define GSFT_GCGEPOINT3D_DEFINED
#include "gcarrayhelper.h"

#pragma pack (pop)
#endif
