
#ifndef AECMODELER_INC_POINT2D_H
#define AECMODELER_INC_POINT2D_H

#include <math.h>
#include "zvector2d.h"

class ZcGePoint2d;

AECMODELER_NAMESPACE_BEGIN

class DllImpExp ZwPoint2d
{
public:
    ZwPoint2d() : x(0.0), y(0.0) {}
    ZwPoint2d(double xx, double yy) : x(xx), y(yy) {}

    ZwPoint2d	operator +(ZwPoint2d p) const	{ return ZwPoint2d(x + p.x, y + p.y); }
    ZwPoint2d	operator +(ZwVector2d v) const	{ return ZwPoint2d(x + v.x, y + v.y); }
    ZwVector2d	operator -(ZwPoint2d p) const	{ return ZwVector2d(x - p.x, y - p.y); }
    ZwPoint2d	operator -(ZwVector2d v) const	{ return ZwPoint2d(x - v.x, y - v.y); }
    ZwPoint2d	operator -() const				{ return ZwPoint2d(-x, -y); }

    ZwPoint2d	operator *(double scalar) const	{ return ZwPoint2d(x * scalar, y * scalar); }
    ZwPoint2d	operator /(double scalar) const	{ return ZwPoint2d(x / scalar, y / scalar); }

    double		operator %(ZwVector2d v) const	{ return x * v.x + y * v.y; }

    double		operator [](int index) const	{ return (&x)[index]; }
    double&		operator [](int index)			{ return (&x)[index]; }

    double		length() const					{ return sqrt(x * x + y * y); }
    double		lengthSqrd() const				{ return x * x + y * y; }
    double		lengthRect() const				{ return fabs(x) + fabs(y); }

    double		dist(ZwPoint2d p) const			{ return sqrt(sqr(x-p.x)+sqr(y-p.y)); }
    double		distSqrd(ZwPoint2d p) const		{ return sqr(x-p.x)+sqr(y-p.y);       }
    double		distRect(ZwPoint2d p) const		{ return fabs(x - p.x) + fabs(y - p.y); }

    bool		isEqual(ZwPoint2d p, double epsSqrd = ZwEpsAbsSqrd()) const	{ return (distSqrd(p) <= epsSqrd); }
    bool		isEqualRect(ZwPoint2d p, double epsRect = ZwEpsAbs()) const	{ return (distRect(p) <= epsRect); }

    void		operator +=(ZwPoint2d p)		{ x += p.x; y += p.y; }
    void		operator +=(ZwVector2d v)		{ x += v.x; y += v.y; }
    void		operator -=(ZwPoint2d p)		{ x -= p.x; y -= p.y; }
    void		operator -=(ZwVector2d v)		{ x -= v.x; y -= v.y; }
    void		operator *=(double scalar)		{ x *= scalar; y *= scalar; }
    void		operator /=(double scalar)		{ x /= scalar; y /= scalar; }

    bool		isValid() const					{ return fabs(x) < kMaxReal && fabs(y) < kMaxReal; }

    ZwVector2d	toVector2d() const				{ return *(ZwVector2d*)this; }

    operator ZcGePoint2d&()						{ return *((ZcGePoint2d*)this); }
    operator const ZcGePoint2d&() const			{ return *((const ZcGePoint2d*)this); }

    static ZwPoint2d& cast(ZcGePoint2d& p)		{ return *(ZwPoint2d*)&p; }

    ZwPoint2d(const ZcGePoint2d& p)				{ *this = *(ZwPoint2d*)&p; }

    double x, y;

    static const ZwPoint2d kNull;
};

inline ZwPoint2d operator *(double scalar, ZwPoint2d p)
{
    return ZwPoint2d(scalar * p.x, scalar * p.y);
}

inline double det(ZwPoint2d a, ZwPoint2d b)
{
    return (a.x * b.y - a.y * b.x);
}

DllImpExp ZwPoint2d intersect(const ZwPoint2d& p1, const ZwVector2d v1,
                              const ZwPoint2d& p2, const ZwVector2d v2,
                              bool& succeeded);

DllImpExp bool doIntersect(const ZwPoint2d& p1,
                           const ZwPoint2d& p2,
                           const ZwPoint2d& q1,
                           const ZwPoint2d& q2);

ZwPoint2d projectPointOnLine(ZwPoint2d p, ZwPoint2d lpoint, ZwVector2d lvector);

AECMODELER_NAMESPACE_END

#endif
