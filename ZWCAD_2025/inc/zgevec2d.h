

#ifndef ZC_GEVEC2D_H
#define ZC_GEVEC2D_H

#include "zadesk.h"
#include "zgegbl.h"
#include "zgegblabb.h"
#pragma pack (push, 8)

class ZcGeMatrix2d;

class 
ZcGeVector2d
{
public:
    GE_DLLEXPIMPORT ZcGeVector2d();
    GE_DLLEXPIMPORT ZcGeVector2d(const ZcGeVector2d& vec);
    GE_DLLEXPIMPORT ZcGeVector2d(double x, double y);

    GE_DLLDATAEXIMP static const   ZcGeVector2d kIdentity;
    GE_DLLDATAEXIMP static const   ZcGeVector2d kXAxis;
    GE_DLLDATAEXIMP static const   ZcGeVector2d kYAxis;

    friend GE_DLLEXPIMPORT
    ZcGeVector2d   operator *  (const ZcGeMatrix2d& mat, const ZcGeVector2d& vec);
    GE_DLLEXPIMPORT ZcGeVector2d&  setToProduct(const ZcGeMatrix2d& mat, const ZcGeVector2d& vec);
    GE_DLLEXPIMPORT ZcGeVector2d&  transformBy (const ZcGeMatrix2d& leftSide);
    GE_DLLEXPIMPORT ZcGeVector2d&  rotateBy    (double angle);
    GE_DLLEXPIMPORT ZcGeVector2d&  mirror      (const ZcGeVector2d& line );

    GE_DLLEXPIMPORT ZcGeVector2d   operator *  (double scl) const;
    friend GE_DLLEXPIMPORT
    ZcGeVector2d   operator *  (double scl, const ZcGeVector2d& vec);
    GE_DLLEXPIMPORT ZcGeVector2d&  operator *= (double scl);
    GE_DLLEXPIMPORT ZcGeVector2d&  setToProduct(const ZcGeVector2d& vec, double scl);
    GE_DLLEXPIMPORT ZcGeVector2d   operator /  (double scl) const;
    GE_DLLEXPIMPORT ZcGeVector2d&  operator /= (double scl);

    GE_DLLEXPIMPORT ZcGeVector2d   operator +  (const ZcGeVector2d& vec) const;
    GE_DLLEXPIMPORT ZcGeVector2d&  operator += (const ZcGeVector2d& vec);
    GE_DLLEXPIMPORT ZcGeVector2d   operator -  (const ZcGeVector2d& vec) const;
    GE_DLLEXPIMPORT ZcGeVector2d&  operator -= (const ZcGeVector2d& vec);
    GE_DLLEXPIMPORT ZcGeVector2d&  setToSum    (const ZcGeVector2d& vec1, const ZcGeVector2d& vec2);
    GE_DLLEXPIMPORT ZcGeVector2d   operator -  () const;
    GE_DLLEXPIMPORT ZcGeVector2d&  negate      ();

    GE_DLLEXPIMPORT ZcGeVector2d   perpVector  () const;

    GE_DLLEXPIMPORT double         angle       () const;
    GE_DLLEXPIMPORT double         angleTo     (const ZcGeVector2d& vec) const;

    GE_DLLEXPIMPORT ZcGeVector2d   normal      (const ZcGeTol& tol = ZcGeContext::gTol) const;
    GE_DLLEXPIMPORT ZcGeVector2d&  normalize   (const ZcGeTol& tol = ZcGeContext::gTol);
    GE_DLLEXPIMPORT ZcGeVector2d&  normalize   (const ZcGeTol& tol, ZcGeError& flag);
			
    GE_DLLEXPIMPORT double         length      () const;
    GE_DLLEXPIMPORT double         lengthSqrd  () const;
    GE_DLLEXPIMPORT ZSoft::Boolean isUnitLength(const ZcGeTol& tol = ZcGeContext::gTol) const;
    GE_DLLEXPIMPORT ZSoft::Boolean isZeroLength(const ZcGeTol& tol = ZcGeContext::gTol) const;

    GE_DLLEXPIMPORT ZSoft::Boolean isParallelTo(const ZcGeVector2d& vec,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;
    GE_DLLEXPIMPORT ZSoft::Boolean isParallelTo(const ZcGeVector2d& vec,
						const ZcGeTol& tol, ZcGeError& flag) const;

    GE_DLLEXPIMPORT ZSoft::Boolean isCodirectionalTo(const ZcGeVector2d& vec,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;
    GE_DLLEXPIMPORT ZSoft::Boolean isCodirectionalTo(const ZcGeVector2d& vec,
						const ZcGeTol& tol, ZcGeError& flag) const;

    GE_DLLEXPIMPORT ZSoft::Boolean isPerpendicularTo(const ZcGeVector2d& vec,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;
    GE_DLLEXPIMPORT ZSoft::Boolean isPerpendicularTo(const ZcGeVector2d& vec,
						const ZcGeTol& tol, ZcGeError& flag) const;

    GE_DLLEXPIMPORT double         dotProduct  (const ZcGeVector2d& vec) const;

    GE_DLLEXPIMPORT bool operator == (const ZcGeVector2d& vec) const;
    GE_DLLEXPIMPORT bool operator != (const ZcGeVector2d& vec) const;
    GE_DLLEXPIMPORT bool isEqualTo   (const ZcGeVector2d& vec,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;

    GE_DLLEXPIMPORT double         operator [] (unsigned int i) const;
    GE_DLLEXPIMPORT double&        operator [] (unsigned int i) ;
    GE_DLLEXPIMPORT ZcGeVector2d&  set         (double x, double y);

    GE_DLLEXPIMPORT operator       ZcGeMatrix2d() const;

    double         x, y;
};

inline
ZcGeVector2d::ZcGeVector2d() : x(0.0), y(0.0)
{
}

inline
ZcGeVector2d::ZcGeVector2d(const ZcGeVector2d& src) : x(src.x), y(src.y)
{
}

inline
ZcGeVector2d::ZcGeVector2d(double xx, double yy) : x(xx), y(yy)
{
}

inline bool
ZcGeVector2d::operator == (const ZcGeVector2d& v) const
{
    return this->isEqualTo(v);
}

inline bool
ZcGeVector2d::operator != (const ZcGeVector2d& v) const
{
    return !this->isEqualTo(v);
}

inline ZcGeVector2d
ZcGeVector2d::operator * (double s) const
{
    return ZcGeVector2d (x * s, y * s);
}

inline ZcGeVector2d&
ZcGeVector2d::operator *= (double s)
{
    x *= s;
    y *= s;
    return *this;
}

inline ZcGeVector2d&
ZcGeVector2d::setToProduct(const ZcGeVector2d& v, double s)
{
    x = s * v.x;
    y = s * v.y;
    return *this;
}

inline ZcGeVector2d
ZcGeVector2d::operator / (double val) const
{
    return ZcGeVector2d (x/val, y/val);
}

inline ZcGeVector2d&
ZcGeVector2d::operator /= (double val)
{
    x /= val;
    y /= val;
    return *this;
}

inline ZcGeVector2d
ZcGeVector2d::operator + (const ZcGeVector2d& v) const
{
    return ZcGeVector2d (x + v.x, y + v.y);
}

inline ZcGeVector2d&
ZcGeVector2d::operator += (const ZcGeVector2d& v)
{
    x += v.x;
    y += v.y;
    return *this;
}

inline ZcGeVector2d
ZcGeVector2d::operator - (const ZcGeVector2d& v) const
{
    return ZcGeVector2d (x - v.x, y - v.y);
}

inline ZcGeVector2d&
ZcGeVector2d::operator -= (const ZcGeVector2d& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

inline ZcGeVector2d&
ZcGeVector2d::setToSum(const ZcGeVector2d& v1, const ZcGeVector2d& v2)
{
    x = v1.x + v2.x;
    y = v1.y + v2.y;
    return *this;
}

inline ZcGeVector2d
ZcGeVector2d::operator - () const
{
    return ZcGeVector2d (-x, -y);
}

inline ZcGeVector2d&
ZcGeVector2d::negate()
{
    x = -x;
    y = -y;
    return *this;
}

inline ZcGeVector2d
ZcGeVector2d::perpVector() const
{
    return ZcGeVector2d (-y, x);
}

inline double
ZcGeVector2d::lengthSqrd() const
{
    return x*x + y*y;
}

inline double
ZcGeVector2d::dotProduct(const ZcGeVector2d& v) const
{
    return x * v.x + y * v.y;
}

inline ZcGeVector2d&
ZcGeVector2d::set(double xx, double yy)
{
    x = xx;
    y = yy;
    return *this;
}

inline double
ZcGeVector2d::operator [] (unsigned int i) const
{
    return *(&x+i);
}

inline double&
ZcGeVector2d::operator [] (unsigned int i)
{
    return *(&x+i);
}

#define ZSOFT_ZCGEVECTOR2D_DEFINED
#include "zacarrayhelper.h"

#pragma pack (pop)
#endif
