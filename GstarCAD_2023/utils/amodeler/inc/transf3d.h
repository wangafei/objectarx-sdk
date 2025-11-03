/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_TRANSF3D_H
#define GMODELER_INC_TRANSF3D_H

#include "point3d.h"

GMODELER_NAMESPACE_BEGIN

class DllImpExp Transf3d
{
public:
  Transf3d();
  Transf3d(const Point3d& origin, const Vector3d& xDir, const Vector3d& yDir, const Vector3d& zDir);
  Transf3d(const Point3d& origin, const Vector3d& xDir, const Vector3d& yDir);
  Transf3d(const Line3d& axis);
  Transf3d(const Point3d& origin);

  double& operator ()(int i1, int i2) { return c[i1][i2]; }
  double  operator ()(int i1, int i2) const { return c[i1][i2]; }

  Point3d  operator *(const Point3d&) const;
  Vector3d operator *(const Vector3d&) const;
  Line3d   operator *(const Line3d&) const;
  Transf3d operator *(const Transf3d&) const;

  void     getCoordSystem(Point3d&  origin,
                          Vector3d& xDir,
                          Vector3d& yDir,
                          Vector3d& zDir) const;

  Point3d  origin() const;
  Vector3d xDir() const;
  Vector3d yDir() const;
  Vector3d zDir() const;

  static Transf3d translation(const Vector3d&);
  static Transf3d rotation(const Line3d& axis, double angle);
  static Transf3d scaling(const Point3d& fixedPt, double factor);
  static Transf3d scaling(const Point3d& fixedPt, const Vector3d& xyzFactors);
  static Transf3d stretching(const Line3d& axis);
  static Transf3d mirroring(const Plane&);
  static Transf3d projectOn(const Plane& projPlane, const Vector3d& projDir = Vector3d::kNull);

  static Transf3d align(const Point3d& src1,
                        const Point3d& src2,
                        const Point3d& src3,
                        const Point3d& dst1,
                        const Point3d& dst2,
                        const Point3d& dst3);
  static Transf3d align(const Point3d&  src1,
                        const Vector3d& src2,
                        const Vector3d& src3,
                        const Point3d&  dst1,
                        const Vector3d& dst2,
                        const Vector3d& dst3);
  static Transf3d align(const Point3d&  src1,
                        const Vector3d& src2,
                        const Point3d&  dst1,
                        const Vector3d& dst2);

  Point3d project(const Point3d& p) const;

  enum ProjectionType
  {
    kParallelProjection,
    kPerspectiveProjection
  };

  Transf3d(ProjectionType  type,
           const Point3d&  fromPt,
           const Point3d&  toPt = Point3d(0, 0, 0),
           const Vector3d& upDir = Vector3d(0, 0, 0));

  static const Transf3d kFrontView;
  static const Transf3d kBackView;
  static const Transf3d kTopView;
  static const Transf3d kBottomView;
  static const Transf3d kLeftView;
  static const Transf3d kRightView;
  static const Transf3d kIsometricView;
  static const Transf3d kDimetricView;

  Transf3d invert(bool isRigidMotion = true) const;

  bool     isValid() const;
  bool     isOrthogonal() const;
  bool     isEqualScalingOrthogonal() const;
  Vector3d stretchVector() const;
  bool     isMirror() const;
  bool     isPerspective() const;
  bool     isIdentity() const;

  static const Transf3d kIdentity;

  operator GcGeMatrix3d& () { return *((GcGeMatrix3d*)this); }
  operator const GcGeMatrix3d& () const { return *((const GcGeMatrix3d*)this); }

  static Transf3d& cast(GcGeMatrix3d& m) { return *(Transf3d*)&m; }
  Transf3d(const GcGeMatrix3d& m) { *this = *(Transf3d*)&m; }

  void save(SaveRestoreCallback*) const;
  void restore(SaveRestoreCallback*);

  double c[4][4];

  enum Type
  {
    kRigidMotion,
    kEqualScalingOrtho,
    kNonOrtho,
    kProjection,
    kUnknown
  };

  static bool isError;
};

DllImpExp void operator *=(double& dist, const Transf3d&);

inline Transf3d::Transf3d()
{
  c[0][1] = c[0][2] = c[0][3] = c[1][0] = c[1][2] = c[1][3] =
  c[2][0] = c[2][1] = c[2][3] = c[3][0] = c[3][1] = c[3][2] = 0.0;
  c[0][0] = c[1][1] = c[2][2] = c[3][3] = 1;
  isError = false;
}

GMODELER_NAMESPACE_END
#endif
