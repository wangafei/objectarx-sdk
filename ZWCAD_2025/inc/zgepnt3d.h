

#ifndef ZC_GEPNT3D_H
#define ZC_GEPNT3D_H

#include "zgevec3d.h"
#pragma pack (push, 8)

class ZcGeMatrix3d;
class ZcGeLinearEnt3d;
class ZcGePlane;
class ZcGePlanarEnt;
class ZcGeVector3d;
class ZcGePoint2d;

class
ZcGePoint3d
{
public:
    GE_DLLEXPIMPORT ZcGePoint3d();
    GE_DLLEXPIMPORT ZcGePoint3d(const ZcGePoint3d& pnt);
    GE_DLLEXPIMPORT ZcGePoint3d(double x, double y, double z);
    GE_DLLEXPIMPORT ZcGePoint3d(const ZcGePlanarEnt& pln, const ZcGePoint2d& pnt2d);

    GE_DLLDATAEXIMP static const   ZcGePoint3d    kOrigin;

    friend GE_DLLEXPIMPORT
    ZcGePoint3d    operator *  (const ZcGeMatrix3d& mat, const ZcGePoint3d& pnt);
    GE_DLLEXPIMPORT ZcGePoint3d&   setToProduct(const ZcGeMatrix3d& mat, const ZcGePoint3d& pnt);

    GE_DLLEXPIMPORT ZcGePoint3d&   transformBy (const ZcGeMatrix3d& leftSide);
    GE_DLLEXPIMPORT ZcGePoint3d&   rotateBy    (double angle, const ZcGeVector3d& vec,
                                const ZcGePoint3d& wrtPoint = ZcGePoint3d::kOrigin);
    GE_DLLEXPIMPORT ZcGePoint3d&   mirror      (const ZcGePlane& pln);
    GE_DLLEXPIMPORT ZcGePoint3d&   scaleBy     (double scaleFactor, const ZcGePoint3d&
                                wrtPoint = ZcGePoint3d::kOrigin);
    GE_DLLEXPIMPORT ZcGePoint2d    convert2d   (const ZcGePlanarEnt& pln) const;

    GE_DLLEXPIMPORT ZcGePoint3d    operator *  (double scl) const;
    GE_DLLEXPIMPORT friend
    ZcGePoint3d    operator *  (double scl, const ZcGePoint3d& pnt);
    GE_DLLEXPIMPORT ZcGePoint3d&   operator *= (double scl);
    GE_DLLEXPIMPORT ZcGePoint3d    operator /  (double scl) const;
    GE_DLLEXPIMPORT ZcGePoint3d&   operator /= (double scl);

    GE_DLLEXPIMPORT ZcGePoint3d    operator +  (const ZcGeVector3d& vec) const;
    GE_DLLEXPIMPORT ZcGePoint3d&   operator += (const ZcGeVector3d& vec);
    GE_DLLEXPIMPORT ZcGePoint3d    operator -  (const ZcGeVector3d& vec) const;
    GE_DLLEXPIMPORT ZcGePoint3d&   operator -= (const ZcGeVector3d& vec);
    GE_DLLEXPIMPORT ZcGePoint3d&   setToSum    (const ZcGePoint3d& pnt, const ZcGeVector3d& vec);

    GE_DLLEXPIMPORT ZcGeVector3d   operator -  (const ZcGePoint3d& pnt) const;
    GE_DLLEXPIMPORT ZcGeVector3d   asVector    () const;

    GE_DLLEXPIMPORT double         distanceTo       (const ZcGePoint3d& pnt) const;

    GE_DLLEXPIMPORT ZcGePoint3d    project       (const ZcGePlane& pln, const ZcGeVector3d& vec) const;
    GE_DLLEXPIMPORT ZcGePoint3d    orthoProject  (const ZcGePlane& pln) const;

    GE_DLLEXPIMPORT bool operator == (const ZcGePoint3d& pnt) const;
    GE_DLLEXPIMPORT bool operator != (const ZcGePoint3d& pnt) const;
    GE_DLLEXPIMPORT bool isEqualTo   (const ZcGePoint3d& pnt,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;

    GE_DLLEXPIMPORT double         operator [] (unsigned int i) const;
    GE_DLLEXPIMPORT double&        operator [] (unsigned int idx);
    GE_DLLEXPIMPORT ZcGePoint3d&   set         (double x, double y, double z);
    GE_DLLEXPIMPORT ZcGePoint3d&   set         (const ZcGePlanarEnt& pln, const ZcGePoint2d& pnt);

    double         x, y, z;
};

inline
ZcGePoint3d::ZcGePoint3d() : x(0.0), y(0.0), z(0.0)
{
}

inline
ZcGePoint3d::ZcGePoint3d(const ZcGePoint3d& src)
{
    constexpr size_t sizeOfDouble = sizeof(double);
    memcpy_s(&x, sizeOfDouble, &(src.x), sizeOfDouble);
    memcpy_s(&y, sizeOfDouble, &(src.y), sizeOfDouble);
    memcpy_s(&z, sizeOfDouble, &(src.z), sizeOfDouble);
}

inline
ZcGePoint3d::ZcGePoint3d(double xx, double yy, double zz) : x(xx), y(yy), z(zz)
{
}

inline bool
ZcGePoint3d::operator == (const ZcGePoint3d& p) const
{
    return this->isEqualTo(p);
}

inline bool
ZcGePoint3d::operator != (const ZcGePoint3d& p) const
{
    return !this->isEqualTo(p);
}

inline ZcGePoint3d
ZcGePoint3d::operator * (double val) const
{
    return ZcGePoint3d(x*val, y*val, z*val);
}

inline ZcGePoint3d
operator * (double val, const ZcGePoint3d& p)
{
    return ZcGePoint3d(p.x*val, p.y*val, p.z*val);
}

inline ZcGePoint3d&
ZcGePoint3d::operator *= (double val)
{
    x *= val;
    y *= val;
    z *= val;
    return *this;
}

inline ZcGePoint3d
ZcGePoint3d::operator / (double val) const
{
    return ZcGePoint3d (x/val, y/val, z/val);
}

inline ZcGePoint3d&
ZcGePoint3d::operator /= (double val)
{
    x /= val;
    y /= val;
    z /= val;
    return *this;
}

inline ZcGePoint3d
ZcGePoint3d::operator + (const ZcGeVector3d& v) const
{
    return ZcGePoint3d (x + v.x, y + v.y, z + v.z);
}

inline ZcGePoint3d&
ZcGePoint3d::operator += (const ZcGeVector3d& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

inline ZcGePoint3d
ZcGePoint3d::operator - (const ZcGeVector3d& v) const
{
    return ZcGePoint3d (x - v.x, y - v.y, z - v.z);
}

inline ZcGePoint3d&
ZcGePoint3d::operator -= (const ZcGeVector3d& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

inline ZcGeVector3d
ZcGePoint3d::operator - (const ZcGePoint3d& p) const
{
    return ZcGeVector3d (x - p.x, y - p.y, z - p.z);
}

inline ZcGeVector3d
ZcGePoint3d::asVector() const
{
    return ZcGeVector3d(x, y, z);
}

inline ZcGePoint3d&
ZcGePoint3d::set(double xx, double yy, double zz)
{
    x = xx;
    y = yy;
    z = zz;
    return *this;
}

inline double
ZcGePoint3d::operator [] (unsigned int i) const
{
    return *(&x+i);
}

inline double&
ZcGePoint3d::operator [] (unsigned int i)
{
    return *(&x+i);
}

#define ZSOFT_ZCGEPOINT3D_DEFINED
#include "zacarrayhelper.h"

#pragma pack (pop)
#endif
