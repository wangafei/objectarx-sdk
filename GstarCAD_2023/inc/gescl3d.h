/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GESCL3D_H
#define GC_GESCL3D_H

#include "gsoft.h"
#include "gegbl.h"
#pragma pack (push, 8)

class GcGeMatrix3d;

class GE_DLLDATAEXIMP GcGeScale3d
{
public:
  GcGeScale3d();
  GcGeScale3d(const GcGeScale3d& src);
  GcGeScale3d(double factor);
  GcGeScale3d(double xFact, double yFact, double zFact);

  static const   GcGeScale3d kIdentity;

  GcGeScale3d    operator *  (const GcGeScale3d& sclVec) const;
  GcGeScale3d&   operator *= (const GcGeScale3d& scl);
  GcGeScale3d&   preMultBy(const GcGeScale3d& leftSide);
  GcGeScale3d&   postMultBy(const GcGeScale3d& rightSide);
  GcGeScale3d&   setToProduct(const GcGeScale3d& sclVec1, const GcGeScale3d& sclVec2);
  GcGeScale3d    operator *  (double s) const;
  GcGeScale3d&   operator *= (double s);
  GcGeScale3d&   setToProduct(const GcGeScale3d& sclVec, double s);
  friend GE_DLLEXPIMPORT GcGeScale3d    operator *  (double, const GcGeScale3d& scl);

  GcGeScale3d    inverse() const;
  GcGeScale3d&   invert();

  Gsoft::Boolean isProportional(const GcGeTol& tol = GcGeContext::gTol) const;

  bool operator == (const GcGeScale3d& sclVec) const;
  bool operator != (const GcGeScale3d& sclVec) const;
  bool isEqualTo(const GcGeScale3d& scaleVec, const GcGeTol& tol = GcGeContext::gTol) const;

  double         operator [] (unsigned int i) const;
  double&        operator [] (unsigned int i);
  GcGeScale3d&   set(double sc0, double sc1, double sc2);

  operator GcGeMatrix3d   () const;
  void getMatrix(GcGeMatrix3d& mat) const;
  GcGeScale3d&   extractScale(const GcGeMatrix3d& mat);
  GcGeScale3d&   removeScale(GcGeMatrix3d& mat);

  double         sx, sy, sz;
};

inline bool GcGeScale3d::operator == (const GcGeScale3d& s) const
{
  return this->isEqualTo(s);
}

inline bool GcGeScale3d::operator != (const GcGeScale3d& s) const
{
  return !(this->isEqualTo(s));
}

inline double GcGeScale3d::operator [] (unsigned int i) const
{
  return *(&sx + i);
}

inline double& GcGeScale3d::operator [] (unsigned int i)
{
  return *(&sx + i);
}

#pragma pack (pop)
#endif
