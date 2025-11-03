
#ifndef AECMODELER_INC_POINT3D_H
#define AECMODELER_INC_POINT3D_H

#include "zvector3d.h"
#include "zipoint3d.h"
#include "zpoint2d.h"

class ZcGePoint3d;

AECMODELER_NAMESPACE_BEGIN

class DllImpExp ZwPoint3d
{
public:
    ZwPoint3d() : x(0.0), y(0.0), z(0.0) {}
    ZwPoint3d(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {}
    ZwPoint3d(ZwIntPoint3d ip) : x(ip.x), y(ip.y), z(ip.z) {}
    ZwPoint3d(ZwPoint2d p) : x(p.x), y(p.y), z(0.0) {}

    ZwPoint3d	operator +(ZwPoint3d p) const	{ return ZwPoint3d(x + p.x, y + p.y, z + p.z); }
    ZwPoint3d	operator +(ZwVector3d v) const	{ return ZwPoint3d(x + v.x, y + v.y, z + v.z); }
    ZwVector3d	operator -(ZwPoint3d p) const	{ return ZwVector3d(x - p.x, y - p.y, z - p.z); }
    ZwPoint3d	operator -(ZwVector3d v) const	{ return ZwPoint3d(x - v.x, y - v.y, z - v.z); }
    ZwPoint3d	operator -() const				{ return ZwPoint3d(-x, -y, -z); }

    ZwPoint3d	operator *(double scalar) const	{ return ZwPoint3d(x * scalar, y * scalar, z * scalar); }
    ZwPoint3d	operator /(double scalar) const	{ return ZwPoint3d(x / scalar, y / scalar, z / scalar); }

    double		operator %(ZwVector3d v) const	{ return x * v.x + y * v.y + z * v.z; }

    double		operator [](int index) const	{ return (&x)[index]; }
    double&		operator [](int index)			{ return (&x)[index]; }

    double		length() const					{ return sqrt(x * x + y * y + z * z); }
    double		lengthSqrd() const				{ return x * x + y * y + z * z; }
    double		lengthRect() const				{ return fabs(x) + fabs(y) + fabs(z); }

    double		dist(ZwPoint3d p) const			{ return sqrt(sqr(x-p.x)+sqr(y-p.y)+sqr(z-p.z)); }
    double		distSqrd(ZwPoint3d p) const		{ return sqr(x-p.x)+sqr(y-p.y)+sqr(z-p.z); }
    double		distRect(ZwPoint3d p) const		{ return fabs(x - p.x) + fabs(y - p.y) + fabs(z - p.z); }

    bool		isEqual(ZwPoint3d p, double epsSqrd = ZwEpsAbsSqrd()) const { return (distSqrd(p) <= epsSqrd); }
    bool		isEqualRect(ZwPoint3d p, double epsRect = ZwEpsAbs()) const { return (distRect(p) <= epsRect); }

    void		operator +=(ZwPoint3d p)		{ x += p.x; y += p.y; z += p.z; }
    void		operator +=(ZwVector3d v)		{ x += v.x; y += v.y; z += v.z; }
    void		operator -=(ZwPoint3d p)		{ x -= p.x; y -= p.y; z -= p.z; }
    void		operator -=(ZwVector3d v)		{ x -= v.x; y -= v.y; z -= v.z; }
    void		operator *=(double scalar)		{ x *= scalar; y *= scalar; z *= scalar; }
    void		operator /=(double scalar)		{ x /= scalar; y /= scalar; z /= scalar; }

    void		operator *=(const ZwTransf3d&);

    ZwPoint3d	project(const ZwTransf3d&) const;

    bool		isBetween(const ZwPoint3d& p1, const ZwPoint3d& p2) const;

    bool		isValid() const					{ return fabs(x) < kMaxReal && fabs(y) < kMaxReal && fabs(z) < kMaxReal; }

    ZwPoint2d	toPoint2d() const				{ return *((ZwPoint2d*)this); }
    ZwPoint2d	toPoint2d(int i1, int i2) const	{ return ZwPoint2d((*this)[i1], (*this)[i2]); }
    ZwPoint2d	toPoint2d(int dropCoord) const;
    ZwVector3d	toVector3d() const				{ return *(ZwVector3d*)this; }

    //Casts from AECModeler::ZwPoint3d to ZcGePoint3d
    operator ZcGePoint3d&()						{ return *((ZcGePoint3d*)this); }
    operator const ZcGePoint3d&() const			{ return *((const ZcGePoint3d*)this); }

    static ZwPoint3d& cast(ZcGePoint3d& p)		{ return *(ZwPoint3d*)&p; }

    ZwPoint3d(const ZcGePoint3d& p)				{ *this = *(ZwPoint3d*)&p; }

    double x, y, z;

    static const ZwPoint3d kNull;
};

inline ZwPoint3d operator *(double scalar, ZwPoint3d p)
{
    return ZwPoint3d(scalar * p.x, scalar * p.y, scalar * p.z);
}

inline double det(ZwPoint3d a, ZwPoint3d b, ZwPoint3d c)
{
    return (a.x * (b.y * c.z - b.z * c.y) +
            a.y * (b.z * c.x - b.x * c.z) +
            a.z * (b.x * c.y - b.y * c.x));
}

inline ZwPoint2d ZwPoint3d::toPoint2d(int dropCoord) const
{
    switch (dropCoord)
    {
    case 0:
        return ZwPoint2d(y, z);
        break;
    case 1:
        return ZwPoint2d(z, x);
        break;
    case 2:
    default:
        return ZwPoint2d(x, y);
    }
}

DllImpExp bool areCoplanar(ZwPoint3d, ZwPoint3d, ZwPoint3d, ZwPoint3d);

AECMODELER_NAMESPACE_END

#endif
