/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef VECTOR2D_H
namespace Gtil { class Vector2d; }
#endif
#ifndef MATRIX2D_H
namespace Gtil { class Matrix2d; }
#endif

#ifndef POINT2D_H
#define POINT2D_H

namespace Gtil
{
  class GTIL_EXPORT Point2d
  {
  public:
    double x;
    double y;

  public:
    Point2d();
    Point2d(int valueX, int  valueY);
    Point2d(double valueX, double valueY);

    ~Point2d();

    const Point2d& set(int valueX, int  valueY);
    const Point2d& set(double valueX, double valueY);

    Point2d& transformBy(const Matrix2d& leftSide);

    double distance(const Point2d& ipPoint) const;

    Vector2d operator-(const Point2d& rhs) const;
    Point2d operator+(const Vector2d& rhs) const;

    Point2d& operator+=(const Vector2d& rhs);

    bool operator==(const Point2d& rhs) const;
    bool operator!=(const Point2d& rhs) const;
  };
}

#endif
