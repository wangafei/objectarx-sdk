
#ifndef AECMODELER_INC_VECTOR2D_H
#define AECMODELER_INC_VECTOR2D_H

#include <math.h>
#include "zglobal.h"

class ZcGeVector2d;

AECMODELER_NAMESPACE_BEGIN

class DllImpExp ZwVector2d
{
public:
    ZwVector2d() : x(0.0), y(0.0) {}
    ZwVector2d(double xx, double yy) : x(xx), y(yy) {}

    ZwVector2d	operator +(ZwVector2d v) const	{ return ZwVector2d(x + v.x, y + v.y); }
    ZwVector2d	operator -(ZwVector2d v) const	{ return ZwVector2d(x - v.x, y - v.y); }
    double		operator %(ZwVector2d v) const	{ return x * v.x + y * v.y; }
    ZwVector2d	operator -() const				{ return ZwVector2d(-x, -y); }

    ZwVector2d	operator *(double scalar) const	{ return ZwVector2d(x * scalar, y * scalar); }
    ZwVector2d	operator /(double scalar) const	{ return ZwVector2d(x / scalar, y / scalar); }

    double		operator [](int index) const	{ return (&x)[index]; }
    double&		operator [](int index)			{ return (&x)[index]; }

    double		length() const					{ return sqrt(x * x + y * y); }
    double		lengthSqrd() const				{ return x * x + y * y; }
    double		lengthRect() const				{ return fabs(x) + fabs(y); }

    ZwVector2d	normalize() const;

    double		dist(ZwVector2d v) const		{ return (*this - v).length(); }
    double		distSqrd(ZwVector2d v) const	{ return (*this - v).lengthSqrd(); }
    double		distRect(ZwVector2d v) const	{ return (*this - v).lengthRect(); }

    bool		isEqual(ZwVector2d v, double epsSqrd = ZwEpsNorSqrd()) const { return (distSqrd(v) <= epsSqrd); }
    bool		isEqualRect(ZwVector2d v, double epsRect = ZwEpsNor()) const { return (distRect(v) <= epsRect); }
    bool		isExactNull() const				{ return x == 0.0 && y == 0.0; }
    bool		isParallel(const ZwVector2d&) const;
    bool		isPerpend(const ZwVector2d&) const;

    void		operator +=(ZwVector2d v)		{ x += v.x; y += v.y; }
    void		operator -=(ZwVector2d v)		{ x -= v.x; y -= v.y; }
    void		operator *=(double scalar)		{ x *= scalar; y *= scalar; }
    void		operator /=(double scalar)		{ x /= scalar; y /= scalar; }

    ZwVector2d	perpend() const					{ return ZwVector2d(-y, x); }

    double		angle(const ZwVector2d&) const;
    bool		isNull(double epsSqrd = ZwEpsNorSqrd()) const { return lengthSqrd() <= epsSqrd; }

    operator ZcGeVector2d&()					{ return *((ZcGeVector2d*)this); }
    operator const ZcGeVector2d&() const		{ return *((const ZcGeVector2d*)this); }

    static ZwVector2d& cast(ZcGeVector2d& v)	{ return *(ZwVector2d*)&v; }

    ZwVector2d(const ZcGeVector2d& v)			{ *this = *(ZwVector2d*)&v; }

    double x, y;

    static const ZwVector2d kNull;
    static const ZwVector2d kXDir;
    static const ZwVector2d kYDir;
};

inline ZwVector2d ZwVector2d::normalize() const
{
    const double l = length();
    return (l > kEpsZero ? ZwVector2d(x / l, y / l) : ZwVector2d(0.0, 0.0));
}

inline double det(ZwVector2d v1, ZwVector2d v2)
{
    return (v1.x * v2.y - v1.y * v2.x);
}

AECMODELER_NAMESPACE_END

#endif
