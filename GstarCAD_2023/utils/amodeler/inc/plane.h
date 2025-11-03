/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_PLANE_H
#define GMODELER_INC_PLANE_H

#include "point3d.h"

GMODELER_NAMESPACE_BEGIN

class DllImpExp Plane
{
public:
  Plane() : normal(Vector3d::kNull), d(0) {}
  Plane(Vector3d nn, double dd) : normal(nn), d(dd) {}
  Plane(Point3d, Vector3d);
  Plane(const Point3d&, const Point3d&, const Point3d&);
  Plane(const Point3d&, const Vector3d&, const Vector3d&);
  Plane(const Point3d plg[], int n);
  Plane(const Point3d plg[], int n, const Vector3d& normal);

  static Plane fromPoints(const Point3d pts[], int pointCount, bool checkPlanarity);

  Plane    operator -()                const { return Plane(-normal, -d); }
  double   dist(Point3d p)       const { return p % normal + d; }
  Point3d  project(const Point3d&) const;
  Vector3d project(const Vector3d&) const;
  Line3d   project(const Line3d&) const;

  Line3d   operator* (const Plane&) const;
  Point3d  operator* (const Line3d&) const;

  bool     isValid() const { return fabs(normal.length() - 1) < epsNor(); }
  bool     isEqual(Plane) const;

  void     orthoPlane(int& i1, int& i2)          const;
  void     orthoPlane(int& i1, int& i2, int& i3) const;

  Vector3d normal;
  double   d;
};

inline Plane::Plane(Point3d p, Vector3d norm) : normal(norm)
{
  normal = normal.normalize();
  d = -p % normal;
}

inline bool Plane::isEqual(Plane pla) const
{
  return normal.isEqual(pla.normal) && fabs(d - pla.d) <= epsAbs();
}

GMODELER_NAMESPACE_END
#endif
