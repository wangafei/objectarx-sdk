/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEVEC2D_H
#define GC_GEVEC2D_H

#include "gsoft.h"
#include "gegbl.h"
#include "gegblabb.h"
#pragma pack (push, 8)

class GcGeMatrix2d;

class GE_DLLDATAEXIMP GcGeVector2d
{
public:
  GcGeVector2d();
  GcGeVector2d(const GcGeVector2d& vec);
  GcGeVector2d(double x, double y);

  static const   GcGeVector2d kIdentity;
  static const   GcGeVector2d kXAxis;
  static const   GcGeVector2d kYAxis;

  friend GE_DLLEXPIMPORT GcGeVector2d   operator *  (const GcGeMatrix2d& mat, const GcGeVector2d& vec);
  GcGeVector2d&  setToProduct(const GcGeMatrix2d& mat, const GcGeVector2d& vec);
  GcGeVector2d&  transformBy(const GcGeMatrix2d& leftSide);
  GcGeVector2d&  rotateBy(double angle);
  GcGeVector2d&  mirror(const GcGeVector2d& line);

  GcGeVector2d   operator *  (double scl) const;
  friend GE_DLLEXPIMPORT GcGeVector2d   operator *  (double scl, const GcGeVector2d& vec);

  GcGeVector2d&  operator *= (double scl);
  GcGeVector2d&  setToProduct(const GcGeVector2d& vec, double scl);
  GcGeVector2d   operator /  (double scl) const;
  GcGeVector2d&  operator /= (double scl);

  GcGeVector2d   operator +  (const GcGeVector2d& vec) const;
  GcGeVector2d&  operator += (const GcGeVector2d& vec);
  GcGeVector2d   operator -  (const GcGeVector2d& vec) const;
  GcGeVector2d&  operator -= (const GcGeVector2d& vec);
  GcGeVector2d&  setToSum(const GcGeVector2d& vec1, const GcGeVector2d& vec2);
  GcGeVector2d   operator -  () const;
  GcGeVector2d&  negate();

  GcGeVector2d   perpVector() const;

  double         angle() const;
  double         angleTo(const GcGeVector2d& vec) const;

  GcGeVector2d   normal(const GcGeTol& tol = GcGeContext::gTol) const;
  GcGeVector2d&  normalize(const GcGeTol& tol = GcGeContext::gTol);
  GcGeVector2d&  normalize(const GcGeTol& tol, GcGeError& flag);
  double         length() const;
  double         lengthSqrd() const;
  Gsoft::Boolean isUnitLength(const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isZeroLength(const GcGeTol& tol = GcGeContext::gTol) const;

  Gsoft::Boolean isParallelTo(const GcGeVector2d& vec, const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isParallelTo(const GcGeVector2d& vec, const GcGeTol& tol, GcGeError& flag) const;
  Gsoft::Boolean isCodirectionalTo(const GcGeVector2d& vec, const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isCodirectionalTo(const GcGeVector2d& vec, const GcGeTol& tol, GcGeError& flag) const;
  Gsoft::Boolean isPerpendicularTo(const GcGeVector2d& vec, const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isPerpendicularTo(const GcGeVector2d& vec, const GcGeTol& tol, GcGeError& flag) const;

  double         dotProduct(const GcGeVector2d& vec) const;

  bool operator == (const GcGeVector2d& vec) const;
  bool operator != (const GcGeVector2d& vec) const;
  bool isEqualTo(const GcGeVector2d& vec, const GcGeTol& tol = GcGeContext::gTol) const;

  double         operator [] (unsigned int i) const;
  double&        operator [] (unsigned int i);
  GcGeVector2d&  set(double x, double y);

  operator GcGeMatrix2d() const;

  double         x, y;
};

inline GcGeVector2d::GcGeVector2d() : x(0.0), y(0.0)
{
}

inline GcGeVector2d::GcGeVector2d(const GcGeVector2d& src) : x(src.x), y(src.y)
{
}

inline GcGeVector2d::GcGeVector2d(double xx, double yy) : x(xx), y(yy)
{
}

inline bool GcGeVector2d::operator == (const GcGeVector2d& v) const
{
  return this->isEqualTo(v);
}

inline bool GcGeVector2d::operator != (const GcGeVector2d& v) const
{
  return !this->isEqualTo(v);
}

inline GcGeVector2d GcGeVector2d::operator * (double s) const
{
  return GcGeVector2d(x * s, y * s);
}

inline GcGeVector2d& GcGeVector2d::operator *= (double s)
{
  x *= s;
  y *= s;
  return *this;
}

inline GcGeVector2d& GcGeVector2d::setToProduct(const GcGeVector2d& v, double s)
{
  x = s * v.x;
  y = s * v.y;
  return *this;
}

inline GcGeVector2d GcGeVector2d::operator / (double val) const
{
  return GcGeVector2d(x / val, y / val);
}

inline GcGeVector2d& GcGeVector2d::operator /= (double val)
{
  x /= val;
  y /= val;
  return *this;
}

inline GcGeVector2d GcGeVector2d::operator + (const GcGeVector2d& v) const
{
  return GcGeVector2d(x + v.x, y + v.y);
}

inline GcGeVector2d& GcGeVector2d::operator += (const GcGeVector2d& v)
{
  x += v.x;
  y += v.y;
  return *this;
}

inline GcGeVector2d GcGeVector2d::operator - (const GcGeVector2d& v) const
{
  return GcGeVector2d(x - v.x, y - v.y);
}

inline GcGeVector2d& GcGeVector2d::operator -= (const GcGeVector2d& v)
{
  x -= v.x;
  y -= v.y;
  return *this;
}

inline GcGeVector2d& GcGeVector2d::setToSum(const GcGeVector2d& v1, const GcGeVector2d& v2)
{
  x = v1.x + v2.x;
  y = v1.y + v2.y;
  return *this;
}

inline GcGeVector2d GcGeVector2d::operator - () const
{
  return GcGeVector2d(-x, -y);
}

inline GcGeVector2d& GcGeVector2d::negate()
{
  x = -x;
  y = -y;
  return *this;
}

inline GcGeVector2d GcGeVector2d::perpVector() const
{
  return GcGeVector2d(-y, x);
}

inline double GcGeVector2d::lengthSqrd() const
{
  return x * x + y * y;
}

inline double GcGeVector2d::dotProduct(const GcGeVector2d& v) const
{
  return x * v.x + y * v.y;
}

inline GcGeVector2d& GcGeVector2d::set(double xx, double yy)
{
  x = xx;
  y = yy;
  return *this;
}

inline double GcGeVector2d::operator [] (unsigned int i) const
{
  return *(&x + i);
}

inline double& GcGeVector2d::operator [] (unsigned int i)
{
  return *(&x + i);
}

#define GSFT_GCGEVECTOR2D_DEFINED
#include "gcarrayhelper.h"

#pragma pack (pop)
#endif