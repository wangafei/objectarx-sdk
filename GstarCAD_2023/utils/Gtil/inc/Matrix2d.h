/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif

#ifndef MATRIX2D_H
#define MATRIX2D_H

#ifndef POINT2D_H
namespace Gtil { class Point2d; }
#endif
#ifndef VECTOR2D_H
namespace Gtil { class Vector2d; }
#endif

namespace Gtil
{
  class GTIL_EXPORT Matrix2d
  {
  public:
    static Matrix2d translation(const Vector2d& vec);
    static Matrix2d rotation(double angle, const Point2d& center);
    static Matrix2d scaling(double scaleAll, const Point2d& center);
    static Matrix2d mirroring(const Point2d& pnt);
    static Matrix2d alignCoordSys(const Point2d&  fromOrigin,
                                  const Vector2d& fromE0,
                                  const Vector2d& fromE1,
                                  const Point2d&  toOrigin,
                                  const Vector2d& toE0,
                                  const Vector2d& toE1);

  public:
    Matrix2d();
    Matrix2d(const Matrix2d& src);

    static const Matrix2d kIdentity;

    Matrix2d& setToIdentity();

    Matrix2d operator*(const Matrix2d& mat) const;
    Matrix2d& operator*=(const Matrix2d& mat);

    Matrix2d& preMultBy(const Matrix2d& leftSide);
    Matrix2d& postMultBy(const Matrix2d& rightSide);

    Matrix2d& setToProduct(const Matrix2d& mat1, const Matrix2d& mat2);

    Matrix2d& invert();

    Matrix2d inverse() const;

    bool isSingular() const;

    Matrix2d& transposeIt();

    Matrix2d transpose() const;

    bool operator== (const Matrix2d& mat) const;
    bool operator!= (const Matrix2d& mat) const;

    bool isEqualTo(const Matrix2d& mat) const;

    double scale(void);

    double det() const;

    Matrix2d& setTranslation(const Vector2d& vec);
    Vector2d translation() const;

    bool isConformal(double& scale, double& angle, bool& isMirror, Vector2d& reflex) const;

    Matrix2d& setCoordSystem(const Point2d& origin, const Vector2d& e0, const Vector2d& e1);
    void getCoordSystem(Point2d& origin, Vector2d& e0, Vector2d& e1) const;

    Matrix2d& setToTranslation(const Vector2d& vec);
    Matrix2d& setToRotation(double angle, const Point2d& center);
    Matrix2d& setToScaling(double scaleAll, const Point2d& center);
    Matrix2d& setToScaling(double scaleX, double scaleY, const Point2d& center);
    Matrix2d& setToMirroring(const Point2d& pnt);
    Matrix2d& setToAlignCoordSys(const Point2d&  fromOrigin,
                                 const Vector2d& fromE0,
                                 const Vector2d& fromE1,
                                 const Point2d&  toOrigin,
                                 const Vector2d& toE0,
                                 const Vector2d& toE1);

    double  operator()(unsigned int row, unsigned int column) const;
    double& operator()(unsigned int row, unsigned int column);

    double entry[3][3];
  };

  inline double Matrix2d::operator() (unsigned int row, unsigned int column) const
  {
    return entry[row][column];
  }

  inline double& Matrix2d::operator() (unsigned int row, unsigned int column)
  {
    return entry[row][column];
  }
}

#endif
