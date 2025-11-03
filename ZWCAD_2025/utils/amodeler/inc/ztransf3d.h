
#ifndef AECMODELER_INC_TRANSF3D_H
#define AECMODELER_INC_TRANSF3D_H

#include "zpoint3d.h"

class ZcGeMatrix3d;

AECMODELER_NAMESPACE_BEGIN

class DllImpExp ZwTransf3d
{
public:
    ZwTransf3d();

    ZwTransf3d(const ZwPoint3d& origin,
               const ZwVector3d& xDir,
               const ZwVector3d& yDir,
               const ZwVector3d& zDir);


    ZwTransf3d(const ZwPoint3d&  origin,
             const ZwVector3d& xDir,
             const ZwVector3d& yDir);


    ZwTransf3d(const ZwLine3d& axis);
    ZwTransf3d(const ZwPoint3d& origin);

    double& operator ()(int i1, int i2) { return c[i1][i2]; }
    double operator ()(int i1, int i2) const { return c[i1][i2]; }

    ZwPoint3d operator *(const ZwPoint3d&) const;
    ZwVector3d operator *(const ZwVector3d&) const;
    ZwLine3d operator *(const ZwLine3d&) const;
    ZwTransf3d operator *(const ZwTransf3d&) const;

    void getCoordSystem(ZwPoint3d& origin,
                        ZwVector3d& xDir,
                        ZwVector3d& yDir,
                        ZwVector3d& zDir) const;

    ZwPoint3d origin() const;
    ZwVector3d xDir() const;
    ZwVector3d yDir() const;
    ZwVector3d zDir() const;

    static ZwTransf3d translation(const ZwVector3d&);
    static ZwTransf3d rotation(const ZwLine3d& axis, double angle);
    static ZwTransf3d scaling(const ZwPoint3d& fixedPt, double factor);
    static ZwTransf3d scaling(const ZwPoint3d& fixedPt, const ZwVector3d& xyzFactors);
    static ZwTransf3d stretching(const ZwLine3d& axis);
    static ZwTransf3d mirroring(const ZwPlane&);
    static ZwTransf3d projectOn(const ZwPlane& projPlane, const ZwVector3d& projDir = ZwVector3d::kNull);

    static ZwTransf3d align(const ZwPoint3d& src1,
                            const ZwPoint3d& src2,
                            const ZwPoint3d& src3,
                            const ZwPoint3d& dst1,
                            const ZwPoint3d& dst2,
                            const ZwPoint3d& dst3);

    static ZwTransf3d align(const ZwPoint3d& src1,
                            const ZwVector3d& src2,
                            const ZwVector3d& src3,
                            const ZwPoint3d& dst1,
                            const ZwVector3d& dst2,
                            const ZwVector3d& dst3);

    static ZwTransf3d align(const ZwPoint3d& src1,
                            const ZwVector3d& src2,
                            const ZwPoint3d& dst1,
                            const ZwVector3d& dst2);

    ZwPoint3d project(const ZwPoint3d& p) const;

    enum ProjectionType { kParallelProjection, kPerspectiveProjection };

    ZwTransf3d(ProjectionType type,
               const ZwPoint3d& fromPt,
               const ZwPoint3d& toPt = ZwPoint3d(0.0, 0.0, 0.0),
               const ZwVector3d& upDir = ZwVector3d(0.0, 0.0, 0.0));

    static const ZwTransf3d kFrontView;
    static const ZwTransf3d kBackView;
    static const ZwTransf3d kTopView;
    static const ZwTransf3d kBottomView;
    static const ZwTransf3d kLeftView;
    static const ZwTransf3d kRightView;
    static const ZwTransf3d kIsometricView;
    static const ZwTransf3d kDimetricView;

    ZwTransf3d invert(bool isRigidMotion = true) const;

    bool isValid() const;
    bool isOrthogonal() const;
    bool isEqualScalingOrthogonal() const;
    ZwVector3d stretchVector() const;
    bool isMirror() const;
    bool isPerspective() const;
    bool isIdentity() const;

    static const ZwTransf3d kIdentity;

    operator ZcGeMatrix3d&() { return *((ZcGeMatrix3d*)this); }
    operator const ZcGeMatrix3d&() const { return *((const ZcGeMatrix3d*)this); }

    static ZwTransf3d& cast(ZcGeMatrix3d& m) { return *(ZwTransf3d*)&m; }

    ZwTransf3d(const ZcGeMatrix3d& m) { *this = *(ZwTransf3d*)&m; }

    void save(ZwSaveRestoreCallback*) const;
    void restore(ZwSaveRestoreCallback*);

    double c[4][4];

    enum Type { kRigidMotion, kEqualScalingOrtho, kNonOrtho, kProjection, kUnknown };

    static bool isError;
};

DllImpExp void operator *=(double& dist, const ZwTransf3d&);

inline ZwTransf3d::ZwTransf3d()
{
    c[0][1] = c[0][2] = c[0][3] = c[1][0] = c[1][2] = c[1][3] =
    c[2][0] = c[2][1] = c[2][3] = c[3][0] = c[3][1] = c[3][2] = 0.0;
    c[0][0] = c[1][1] = c[2][2] = c[3][3] = 1;
    isError = false;
}

AECMODELER_NAMESPACE_END

#endif
