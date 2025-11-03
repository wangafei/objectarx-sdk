/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GESCL2D_H
#define GC_GESCL2D_H

#include "gsoft.h"
#include "gegbl.h"
#pragma pack (push, 8)

class GcGeMatrix2d;
class GcGeScale3d;

class GE_DLLDATAEXIMP GcGeScale2d
{
public:
  GcGeScale2d();
  GcGeScale2d(const GcGeScale2d& src);
  GcGeScale2d(double factor);
  GcGeScale2d(double xFactor, double yFactor);

  static const   GcGeScale2d kIdentity;

  GcGeScale2d    operator *  (const GcGeScale2d& sclVec) const;
  GcGeScale2d&   operator *= (const GcGeScale2d& scl);
  GcGeScale2d&   preMultBy(const GcGeScale2d& leftSide);
  GcGeScale2d&   postMultBy(const GcGeScale2d& rightSide);
  GcGeScale2d&   setToProduct(const GcGeScale2d& sclVec1, const GcGeScale2d& sclVec2);
  GcGeScale2d    operator *  (double s) const;
  GcGeScale2d&   operator *= (double s);
  GcGeScale2d&   setToProduct(const GcGeScale2d& sclVec, double s);
  friend GE_DLLEXPIMPORT GcGeScale2d    operator *  (double, const GcGeScale2d& scl);

  GcGeScale2d    inverse() const;
  GcGeScale2d&   invert();

  Gsoft::Boolean isProportional(const GcGeTol& tol = GcGeContext::gTol) const;

  bool operator == (const GcGeScale2d& sclVec) const;
  bool operator != (const GcGeScale2d& sclVec) const;
  bool isEqualTo(const GcGeScale2d& scaleVec, const GcGeTol& tol = GcGeContext::gTol) const;

  double         operator [] (unsigned int i) const;
  double&        operator [] (unsigned int i);
  GcGeScale2d&   set(double sc0, double sc1);

  operator GcGeMatrix2d   () const;
  void           getMatrix(GcGeMatrix2d& mat) const;
  GcGeScale2d&   extractScale(const GcGeMatrix2d& mat);
  GcGeScale2d&   removeScale(GcGeMatrix2d& mat);

  operator GcGeScale3d    () const;

  double         sx, sy;
};

inline double GcGeScale2d::operator [] (unsigned int i) const
{
  return *(&sx + i);
}

inline double& GcGeScale2d::operator [] (unsigned int i)
{
  return *(&sx + i);
}

inline bool GcGeScale2d::operator == (const GcGeScale2d& s) const
{
  return this->isEqualTo(s);
}

inline bool GcGeScale2d::operator != (const GcGeScale2d& s) const
{
  return !this->isEqualTo(s);
}

#pragma pack (pop)
#endif
