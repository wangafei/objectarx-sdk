

#ifndef ZC_GEPNT2D_H
#define ZC_GEPNT2D_H

#include "zgevec2d.h"
#pragma pack (push, 8)

class ZcGeMatrix2d;
class ZcGeVector2d;
class ZcGeLinearEnt2d;
class ZcGeLine2d;

class
ZcGePoint2d
{
public:
    GE_DLLEXPIMPORT ZcGePoint2d();
    GE_DLLEXPIMPORT ZcGePoint2d(const ZcGePoint2d& pnt);
    GE_DLLEXPIMPORT ZcGePoint2d(double x, double y);

    GE_DLLDATAEXIMP static const   ZcGePoint2d kOrigin;

    friend GE_DLLEXPIMPORT
    ZcGePoint2d    operator *  (const ZcGeMatrix2d& mat, const ZcGePoint2d& pnt);
    GE_DLLEXPIMPORT ZcGePoint2d&   setToProduct(const ZcGeMatrix2d& mat, const ZcGePoint2d& pnt);
    GE_DLLEXPIMPORT ZcGePoint2d&   transformBy (const ZcGeMatrix2d& leftSide);
    GE_DLLEXPIMPORT ZcGePoint2d&   rotateBy    (double angle, const ZcGePoint2d& wrtPoint
                                = ZcGePoint2d::kOrigin);
    GE_DLLEXPIMPORT ZcGePoint2d&   mirror      (const ZcGeLine2d& line);
    GE_DLLEXPIMPORT ZcGePoint2d&   scaleBy     (double scaleFactor, const ZcGePoint2d& wrtPoint
                                = ZcGePoint2d::kOrigin);

    GE_DLLEXPIMPORT ZcGePoint2d    operator *  (double) const;
    GE_DLLEXPIMPORT friend
    ZcGePoint2d    operator *  (double, const ZcGePoint2d& scl);
    GE_DLLEXPIMPORT ZcGePoint2d&   operator *= (double scl);
    GE_DLLEXPIMPORT ZcGePoint2d    operator /  (double scl) const;
    GE_DLLEXPIMPORT ZcGePoint2d&   operator /= (double scl);

    GE_DLLEXPIMPORT ZcGePoint2d    operator +  (const ZcGeVector2d& vec) const;
    GE_DLLEXPIMPORT ZcGePoint2d&   operator += (const ZcGeVector2d& vec);
    GE_DLLEXPIMPORT ZcGePoint2d    operator -  (const ZcGeVector2d& vec) const;
    GE_DLLEXPIMPORT ZcGePoint2d&   operator -= (const ZcGeVector2d& vec);
    GE_DLLEXPIMPORT ZcGePoint2d&   setToSum    (const ZcGePoint2d& pnt, const ZcGeVector2d& vec);

    GE_DLLEXPIMPORT ZcGeVector2d   operator -  (const ZcGePoint2d& pnt) const;
    GE_DLLEXPIMPORT ZcGeVector2d   asVector    () const;

    GE_DLLEXPIMPORT double         distanceTo  (const ZcGePoint2d& pnt) const;

    GE_DLLEXPIMPORT bool operator == (const ZcGePoint2d& pnt) const;
    GE_DLLEXPIMPORT bool operator != (const ZcGePoint2d& pnt) const;
    GE_DLLEXPIMPORT bool isEqualTo   (const ZcGePoint2d& pnt,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;

    GE_DLLEXPIMPORT double         operator [] (unsigned int i) const;
    GE_DLLEXPIMPORT double&        operator [] (unsigned int idx);
    GE_DLLEXPIMPORT ZcGePoint2d&   set         (double x, double y);

    double         x, y;
};

inline
ZcGePoint2d::ZcGePoint2d() : x(0.0), y(0.0)
{
}

inline
ZcGePoint2d::ZcGePoint2d(const ZcGePoint2d& src) : x(src.x), y(src.y)
{
}

inline
ZcGePoint2d::ZcGePoint2d(double xx, double yy) : x(xx), y(yy)
{
}

inline bool
ZcGePoint2d::operator == (const ZcGePoint2d& p) const
{
    return this->isEqualTo(p);
}

inline bool
ZcGePoint2d::operator != (const ZcGePoint2d& p) const
{
    return !this->isEqualTo(p);
}

inline ZcGePoint2d
ZcGePoint2d::operator * (double val) const
{
    return ZcGePoint2d(x*val, y*val);
}

inline ZcGePoint2d
operator * (double val, const ZcGePoint2d& p)
{
    return ZcGePoint2d(p.x*val, p.y*val);
}

inline ZcGePoint2d&
ZcGePoint2d::operator *= (double val)
{
    x *= val;
    y *= val;
    return *this;
}

inline ZcGePoint2d
ZcGePoint2d::operator / (double val) const
{
    return ZcGePoint2d (x/val, y/val);
}

inline ZcGePoint2d&
ZcGePoint2d::operator /= (double val)
{
    x /= val;
    y /= val;
    return *this;
}

inline ZcGePoint2d
ZcGePoint2d::operator + (const ZcGeVector2d& v) const
{
    return ZcGePoint2d(x + v.x, y + v.y);
}

inline ZcGePoint2d&
ZcGePoint2d::operator += (const ZcGeVector2d& v)
{
    x += v.x;
    y += v.y;
    return *this;
}

inline ZcGePoint2d
ZcGePoint2d::operator - (const ZcGeVector2d& v) const
{
    return ZcGePoint2d(x - v.x, y - v.y);
}

inline ZcGePoint2d&
ZcGePoint2d::operator -= (const ZcGeVector2d& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

inline ZcGeVector2d
ZcGePoint2d::operator - (const ZcGePoint2d& p) const
{
    return ZcGeVector2d(x - p.x, y - p.y);
}

inline ZcGeVector2d
ZcGePoint2d::asVector() const
{
    return ZcGeVector2d(x, y);
}

inline ZcGePoint2d&
ZcGePoint2d::set(double xx, double yy)
{
    x = xx;
    y = yy;
    return *this;
}

inline double
ZcGePoint2d::operator [] (unsigned int i) const
{
    return *(&x+i);
}

inline double&
ZcGePoint2d::operator [] (unsigned int i)
{
    return *(&x+i);
}

#define ZSOFT_ZCGEPOINT2D_DEFINED
#include "zacarrayhelper.h"

#pragma pack (pop)
#endif
