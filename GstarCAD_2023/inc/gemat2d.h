/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEMAT2D_H
#define GC_GEMAT2D_H

#include "gegbl.h"
#include "gepnt2d.h"
#pragma pack (push, 8)

class GcGeVector2d;
class GcGeLine2d;
class GcGeTol;

class GE_DLLDATAEXIMP GcGeMatrix2d
{
public:
  GcGeMatrix2d();
  GcGeMatrix2d(const GcGeMatrix2d& src);

  static const   GcGeMatrix2d   kIdentity;

  GcGeMatrix2d&  setToIdentity();

  GcGeMatrix2d   operator *   (const GcGeMatrix2d& mat) const;
  GcGeMatrix2d&  operator *=  (const GcGeMatrix2d& mat);
  GcGeMatrix2d&  preMultBy(const GcGeMatrix2d& leftSide);
  GcGeMatrix2d&  postMultBy(const GcGeMatrix2d& rightSide);
  GcGeMatrix2d&  setToProduct(const GcGeMatrix2d& mat1, const GcGeMatrix2d& mat2);

  GcGeMatrix2d&  invert();
  GcGeMatrix2d   inverse() const;

  Gsoft::Boolean isSingular(const GcGeTol& tol = GcGeContext::gTol) const;

  GcGeMatrix2d&  transposeIt();
  GcGeMatrix2d   transpose() const;

  bool operator ==  (const GcGeMatrix2d& mat) const;
  bool operator !=  (const GcGeMatrix2d& mat) const;
  bool isEqualTo(const GcGeMatrix2d& mat, const GcGeTol& tol = GcGeContext::gTol) const;

  Gsoft::Boolean isUniScaledOrtho(const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isScaledOrtho(const GcGeTol& tol = GcGeContext::gTol) const;
  double         scale(void);
  double         det() const;

  GcGeMatrix2d&  setTranslation(const GcGeVector2d& vec);
  GcGeVector2d   translation() const;

  Gsoft::Boolean isConformal(double& scale, double& angle, Gsoft::Boolean& isMirror, GcGeVector2d& reflex) const;

  GcGeMatrix2d&  setCoordSystem(const GcGePoint2d& origin, const GcGeVector2d& e0, const GcGeVector2d& e1);
  void           getCoordSystem(GcGePoint2d& origin, GcGeVector2d& e0, GcGeVector2d& e1) const;

  GcGeMatrix2d& setToTranslation(const GcGeVector2d& vec);
  GcGeMatrix2d& setToRotation(double angle, const GcGePoint2d& center = GcGePoint2d::kOrigin);
  GcGeMatrix2d& setToScaling(double scaleAll, const GcGePoint2d& center = GcGePoint2d::kOrigin);
  GcGeMatrix2d& setToMirroring(const GcGePoint2d& pnt);
  GcGeMatrix2d& setToMirroring(const GcGeLine2d& line);
  GcGeMatrix2d& setToAlignCoordSys(const GcGePoint2d&  fromOrigin,
                                                   const GcGeVector2d& fromE0,
                                                   const GcGeVector2d& fromE1,
                                                   const GcGePoint2d&  toOrigin,
                                                   const GcGeVector2d& toE0,
                                                   const GcGeVector2d& toE1);

  static GcGeMatrix2d translation(const GcGeVector2d& vec);
  static GcGeMatrix2d rotation(double angle, const GcGePoint2d& center = GcGePoint2d::kOrigin);
  static GcGeMatrix2d scaling(double scaleAll, const GcGePoint2d& center = GcGePoint2d::kOrigin);
  static GcGeMatrix2d mirroring(const GcGePoint2d& pnt);
  static GcGeMatrix2d mirroring(const GcGeLine2d& line);
  static GcGeMatrix2d alignCoordSys(const GcGePoint2d&  fromOrigin,
                                                    const GcGeVector2d& fromE0,
                                                    const GcGeVector2d& fromE1,
                                                    const GcGePoint2d&  toOrigin,
                                                    const GcGeVector2d& toE0,
                                                    const GcGeVector2d& toE1);

  double         operator ()  (unsigned int, unsigned int) const;
  double&        operator ()  (unsigned int, unsigned int);

  double         entry[3][3];
};

inline bool GcGeMatrix2d::operator == (const GcGeMatrix2d& otherMatrix) const
{
  return this->isEqualTo(otherMatrix);
}

inline bool GcGeMatrix2d::operator != (const GcGeMatrix2d& otherMatrix) const
{
  return !this->isEqualTo(otherMatrix);
}

inline double  GcGeMatrix2d::operator () (unsigned int row, unsigned int column) const
{
  return entry[row][column];
}

inline double& GcGeMatrix2d::operator () (unsigned int row, unsigned int column)
{
  return entry[row][column];
}

#pragma pack (pop)
#endif
