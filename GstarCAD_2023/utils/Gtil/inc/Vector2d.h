/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif

#ifndef POINT2D_H
namespace Gtil { class Point2d; }
#endif
#ifndef MATRIX2D_H
namespace Gtil { class Matrix2d; }
#endif

#ifndef VECTOR2D_H
#define VECTOR2D_H

namespace Gtil
{
  class GTIL_EXPORT Vector2d
  {
  public:
    double x;
    double y;

    Vector2d();
    Vector2d(double valueX, double valueY);
    Vector2d(const Vector2d& xy);
    virtual ~Vector2d();

    virtual const Vector2d& set(const Vector2d& v2d);
    virtual const Vector2d& set(double valueX, double valueY);

    virtual Vector2d& transformBy(const Matrix2d& leftSide);
    virtual const Vector2d& rotate(double dRgds);

    virtual double length() const;

    virtual double angle() const;
    virtual double angleTo(const Vector2d& bvTo) const;

    virtual double ccwAngleTo(const Vector2d& bvTo) const;

    virtual const Vector2d& normalize();

    virtual Vector2d normal() const;

    virtual const Vector2d& negate();

    virtual Vector2d perpVector() const;
    virtual double dotProduct(const Vector2d& v) const;

    virtual bool isCodirectionalTo(const Vector2d& iv) const;
    virtual bool isParallelTo(const Vector2d& v) const;
    virtual bool isEqualTo(const Vector2d& v) const;

    virtual Vector2d  getOrthoVector() const;

    virtual Vector2d operator-() const;
    virtual Vector2d operator-(const Vector2d& rhs) const;
    virtual Vector2d& operator-=(const Vector2d& rhs);

    virtual Point2d operator-(const Point2d& rhs) const;
    virtual Point2d operator+(const Point2d& rhs) const;

    virtual Vector2d operator+(const Vector2d& rhs) const;
    virtual Vector2d& operator+=(const Vector2d& rhs);

    virtual Vector2d operator*(const double& rhs) const;
    virtual Vector2d& operator*=(const double& rhs);

    virtual Vector2d operator/(const double&rhs) const;
    virtual Vector2d& operator/=(const double& rhs);

    virtual bool operator==(const Vector2d& rhs) const;
    virtual bool operator!=(const Vector2d& rhs) const;
  };

  class GTIL_EXPORT VectorUL : public Vector2d
  {
  public:
    VectorUL();
    VectorUL(double dx, double dy);
    VectorUL(const Vector2d& xy);
    virtual ~VectorUL();

    virtual const Vector2d& rotate(double dRgds);

    virtual Vector2d perpVector() const;

    virtual double angle() const;

    virtual double ccwAngleTo(const Vector2d& bvTo) const;
  };
}

#endif
