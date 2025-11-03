/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_LINE3D_H
#define GMODELER_INC_LINE3D_H

#include "point3d.h"

GMODELER_NAMESPACE_BEGIN

class DllImpExp Line3d
{
public:
  Line3d() : point(Point3d::kNull), vector(Vector3d::kNull) {}
  Line3d(const Point3d&  p, const Vector3d& v) : point(p), vector(v) {}
  Line3d(const Point3d& p1, const Point3d& p2) : point(p1), vector(p2 - p1) {}

  double  dist(const Point3d&) const;
  Point3d project(const Point3d&) const;

  void operator *=(const Transf3d&);

  bool intersect(const Line3d&, Point3d& intersPoint) const;
  bool isEqual(const Line3d&) const;
  bool isValid() const { return !vector.isNull(); }
  bool isCoincident(const Line3d&, bool sameDirectionAlso) const;

  Point3d  point;
  Vector3d vector;

  static const Line3d kNull;
  static const Line3d kXAxis;
  static const Line3d kYAxis;
  static const Line3d kZAxis;
};

GMODELER_NAMESPACE_END
#endif
