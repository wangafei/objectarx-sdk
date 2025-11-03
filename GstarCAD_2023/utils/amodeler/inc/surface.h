/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_SURFACE_H
#define GMODELER_INC_SURFACE_H

#include "entity.h"
#include "circle3d.h"
#include "transf3d.h"

GMODELER_NAMESPACE_BEGIN

class DllImpExp Surface : public Entity
{
public:
  Surface(Body* = NULL);

  enum Type
  {
    kUnspecified,
    kCylinder,
    kCone,
    kSphere,
    kTorus
  };

  virtual Type     type() const = NULL;
  virtual Surface* copy() const = NULL;

  virtual bool     transform(const Transf3d&,
                             Transf3d::Type = Transf3d::kUnknown,
                             const Vector3d& = Vector3d::kNull) = NULL;

  virtual bool     isEqual(const Surface*) const = NULL;

  virtual bool containsPoint(const Point3d&) const = NULL;

  virtual Circle3d circle(const Plane&, const Line3d&) const = NULL;

  virtual Vector3d normal(const Point3d&) const = NULL;

  virtual void     print(FILE* = NULL) const = NULL;
  virtual void     save(SaveRestoreCallback*) const;
  virtual void     restore(SaveRestoreCallback*) {}

  Surface*         next() const { return mpNext; }
  void             setNext(Surface* s) { mpNext = s; }

  Surface* sptr;
  int      n;
private:
  Surface* mpNext;
};

class DllImpExp UnspecifiedSurface : public Surface
{
public:
  UnspecifiedSurface(Body* b = NULL) : Surface(b) {}

  virtual Type     type() const { return kUnspecified; }
  virtual Surface* copy() const { return new UnspecifiedSurface(*this); }
  virtual void     print(FILE* = NULL) const;

  virtual bool     transform(const Transf3d&,
                             Transf3d::Type = Transf3d::kUnknown,
                             const Vector3d& = Vector3d::kNull)
  {
    return true;
  }

  virtual bool     isEqual(const Surface* s) const;

  virtual bool containsPoint(const Point3d&) const { return false; }

  virtual Circle3d circle(const Plane&, const Line3d&) const { return Circle3d(); }
  virtual Vector3d normal(const Point3d&)              const { return Vector3d(0, 0, 0); }
};

class DllImpExp RevolutionSurface : public Surface
{
public:
  RevolutionSurface();
  RevolutionSurface(const Line3d& axis, const Vector3d& startDir, Body* = NULL);

  Line3d           axis() const { return mAxis; }
  Vector3d         startDir() const { return mStartDir; }

  virtual bool     transform(const Transf3d&,
                             Transf3d::Type  transfType = Transf3d::kUnknown,
                             const Vector3d& stretchVect = Vector3d::kNull);

  virtual bool     isEqual(const Surface*) const;

  virtual void     save(SaveRestoreCallback*) const;
  virtual void     restore(SaveRestoreCallback*);

private:
  Line3d   mAxis;
  Vector3d mStartDir;
};

class DllImpExp SphereSurface : public RevolutionSurface
{
public:
  SphereSurface() {}
  SphereSurface(const Point3d& origin, double radius, int approx, Body*);

  Point3d          center() const { return axis().point; }
  double           radius() const { return mRadius; }
  int              approx() const { return mApprox; }

  virtual Type     type() const { return kSphere; }
  virtual Surface* copy() const { return new SphereSurface(*this); }

  virtual bool     transform(const Transf3d&,
                             Transf3d::Type  transfType = Transf3d::kUnknown,
                             const Vector3d& stretchVect = Vector3d::kNull);

  virtual bool     isEqual(const Surface*) const;

  virtual bool containsPoint(const Point3d&) const;

  virtual Circle3d circle(const Plane&, const Line3d&) const;
  virtual Vector3d normal(const Point3d&)              const;

  virtual void     print(FILE* = NULL)         const;
  virtual void     save(SaveRestoreCallback*)  const;
  virtual void     restore(SaveRestoreCallback*);

private:
  double  mRadius;
  int     mApprox;
};

class DllImpExp CylinderSurface : public RevolutionSurface
{
public:
  CylinderSurface() {}
  CylinderSurface(const Line3d& axis, double radius, int approx, Body*);
  CylinderSurface(const Line3d& axis, const Vector3d& startDir, double radius, int approx, Body*);

  double           radius() const { return mRadius; }
  int              approx() const { return mApprox; }

  virtual Type     type() const { return kCylinder; }
  virtual Surface* copy() const { return new CylinderSurface(*this); }

  virtual bool     transform(const Transf3d&,
                             Transf3d::Type  transfType = Transf3d::kUnknown,
                             const Vector3d& stretchVect = Vector3d::kNull);

  virtual bool     isEqual(const Surface*) const;

  virtual bool containsPoint(const Point3d&) const;

  virtual Circle3d circle(const Plane&, const Line3d&) const;
  virtual Vector3d normal(const Point3d&)              const;

  virtual void     print(FILE* = NULL)         const;
  virtual void     save(SaveRestoreCallback*)  const;
  virtual void     restore(SaveRestoreCallback*);

private:
  double mRadius;
  int    mApprox;
};

class DllImpExp ConeSurface : public RevolutionSurface
{
public:
  ConeSurface() {}
  ConeSurface(const Line3d& axis, double radius1, double radius2, int approx, Body*);

  double           radius() const { return mRadius; }
  double           tanAngle() const { return mTanAngle; }
  int              approx() const { return mApprox; }
  Point3d          apex() const;

  virtual Type     type() const { return kCone; }
  virtual Surface* copy() const { return new ConeSurface(*this); }

  virtual bool     transform(const Transf3d&,
                             Transf3d::Type  transfType = Transf3d::kUnknown,
                             const Vector3d& stretchVect = Vector3d::kNull);

  virtual bool     isEqual(const Surface*) const;

  virtual bool containsPoint(const Point3d&) const;

  virtual Circle3d circle(const Plane&, const Line3d&) const;
  virtual Vector3d normal(const Point3d&)              const;

  virtual void     print(FILE* = NULL)         const;
  virtual void     save(SaveRestoreCallback*)  const;
  virtual void     restore(SaveRestoreCallback*);

private:
  double mRadius;
  double mTanAngle;
  int    mApprox;
};

class DllImpExp TorusSurface : public RevolutionSurface
{
public:
  TorusSurface() {}
  TorusSurface(const Line3d& axis,
               double        majRadius,
               double        minRadius,
               int           majApprox,
               int           minApprox,
               Body*         b);

  Point3d          center() const { return axis().point; }
  double           majorRadius() const { return mMajorRadius; }
  double           minorRadius() const { return mMinorRadius; }
  int              majorApprox() const { return mMajorApprox; }
  int              minorApprox() const { return mMinorApprox; }

  virtual Type     type() const { return kTorus; }
  virtual Surface* copy() const { return new TorusSurface(*this); }

  virtual bool     transform(const Transf3d&,
                             Transf3d::Type  transfType = Transf3d::kUnknown,
                             const Vector3d& stretchVect = Vector3d::kNull);

  virtual bool     isEqual(const Surface*) const;

  virtual bool containsPoint(const Point3d&) const;

  virtual Circle3d circle(const Plane&, const Line3d&) const;
  virtual Vector3d normal(const Point3d&)              const;

  virtual void     print(FILE* = NULL)         const;
  virtual void     save(SaveRestoreCallback*)  const;
  virtual void     restore(SaveRestoreCallback*);

private:
  double mMajorRadius;
  double mMinorRadius;
  int    mMajorApprox;
  int    mMinorApprox;
};

GMODELER_NAMESPACE_END
#endif
