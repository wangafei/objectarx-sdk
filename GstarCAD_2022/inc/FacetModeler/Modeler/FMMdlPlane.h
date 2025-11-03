#ifndef __FMMDL_PLANE_H__
#define __FMMDL_PLANE_H__


#include "../FacetModeler/Modeler/FMMdlPoint3d.h"


namespace FacetModeler
{

  class FMGEOMETRY_API Plane
  {
  public:

    Plane()                                 : normal(Vector3d::kNull), d(0) {}
    Plane(Vector3d nn, double dd)           : normal(nn), d(dd)             {}
    Plane(Point3d, Vector3d); 
    Plane(const Point3d&, const Point3d&,  const Point3d&);
    Plane(const Point3d&, const Vector3d&, const Vector3d&);

    Plane(const Point3d plg[], int n);

    Plane(const Point3d plg[], int n, const Vector3d& normal);

    static Plane fromPoints(const Point3d pts[], int pointCount, bool checkPlanarity);

    Plane    operator -()                const { return Plane(-normal, -d); }
    double   dist      (Point3d p)       const { return p % normal + d; }
    Point3d  project   (const Point3d& ) const;
    Vector3d project   (const Vector3d&) const;
    Line3d   project   (const Line3d&  ) const;

    Line3d   operator* (const Plane&   ) const;
    Point3d  operator* (const Line3d&  ) const;

    bool     isValid   () const { return fabs(normal.length() - 1) < epsNor(); }

    bool     isEqual   (Plane) const;

    void     orthoPlane(int& i1, int& i2)          const;
    void     orthoPlane(int& i1, int& i2, int& i3) const;

    void     set(Point3d, Vector3d);

    Vector3d normal;
    double   d;

  };

  inline void Plane::set(Point3d p, Vector3d norm)
  {
    normal = normal.normalize();
    d = -p % normal;
  }

  inline Plane::Plane(Point3d p, Vector3d norm)
    : normal(norm)
  {
    normal = normal.normalize();
    d = -p % normal;
  }


  inline bool Plane::isEqual(Plane pla) const 
  { 
    return normal.isEqual(pla.normal) && fabs(d-pla.d) <= epsAbs(); 
  }
}

#endif //__FMMDL_PLANE_H__
