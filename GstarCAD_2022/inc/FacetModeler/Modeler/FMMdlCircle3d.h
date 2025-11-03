#ifndef __FMMDL_CIRCLE3D_H__
#define __FMMDL_CIRCLE3D_H__

#include "../FacetModeler/Modeler/FMMdlLine3d.h"

namespace FacetModeler
{
  class FMGEOMETRY_API Circle3d
  {
  public:
    Circle3d() : radius(0) {}
    Circle3d(Line3d ax, double rad) : axis(ax), radius(rad) {}

    Circle3d(const Point3d&  p1,
      const Point3d&  p2,
      const Vector3d& norm, 
      double          rad,
      bool            isCenterLeft);

    Circle3d(const Point3d& p1,
      const Point3d& p2,
      const Point3d& p3,
      double         rad); 

    void operator *=(const Transf3d&);

    Vector3d tangentAt(const Point3d& pointOnCircle) const;

    bool isValid() const { return radius != 0 && axis.isValid(); }

    bool isEqual(const Circle3d&) const;

    int tessellate(int            approx,
      bool           goCcw,
      const Point3d  startPoint, 
      const Point3d  endPoint, 
      Point3d*       ptsArray); 

    Line3d axis;
    double radius;

  };  
}

#endif //__FMMDL_CIRCLE3D_H__
