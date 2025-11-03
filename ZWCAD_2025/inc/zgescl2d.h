

#ifndef ZC_GESCL2D_H
#define ZC_GESCL2D_H

#include "zadesk.h"
#include "zgegbl.h"
#pragma pack (push, 8)

class ZcGeMatrix2d;
class ZcGeScale3d;

class 
ZcGeScale2d
{
public:
    GE_DLLEXPIMPORT ZcGeScale2d();
    GE_DLLEXPIMPORT ZcGeScale2d(const ZcGeScale2d& src);
    GE_DLLEXPIMPORT ZcGeScale2d(double factor);
    GE_DLLEXPIMPORT ZcGeScale2d(double xFactor, double yFactor);

    GE_DLLDATAEXIMP static const   ZcGeScale2d kIdentity;

    GE_DLLEXPIMPORT ZcGeScale2d    operator *  (const ZcGeScale2d& sclVec) const;
    GE_DLLEXPIMPORT ZcGeScale2d&   operator *= (const ZcGeScale2d& scl);
    GE_DLLEXPIMPORT ZcGeScale2d&   preMultBy   (const ZcGeScale2d& leftSide);
    GE_DLLEXPIMPORT ZcGeScale2d&   postMultBy  (const ZcGeScale2d& rightSide);
    GE_DLLEXPIMPORT ZcGeScale2d&   setToProduct(const ZcGeScale2d& sclVec1, const ZcGeScale2d& sclVec2);
    GE_DLLEXPIMPORT ZcGeScale2d    operator *  (double s) const;
    GE_DLLEXPIMPORT ZcGeScale2d&   operator *= (double s);
    GE_DLLEXPIMPORT ZcGeScale2d&   setToProduct(const ZcGeScale2d& sclVec, double s);
    friend GE_DLLEXPIMPORT
    ZcGeScale2d    operator *  (double, const ZcGeScale2d& scl);

    GE_DLLEXPIMPORT ZcGeScale2d    inverse        () const;
    GE_DLLEXPIMPORT ZcGeScale2d&   invert         ();

    GE_DLLEXPIMPORT ZSoft::Boolean isProportional(const ZcGeTol& tol = ZcGeContext::gTol) const;

    GE_DLLEXPIMPORT bool operator == (const ZcGeScale2d& sclVec) const;
    GE_DLLEXPIMPORT bool operator != (const ZcGeScale2d& sclVec) const;
    GE_DLLEXPIMPORT bool isEqualTo   (const ZcGeScale2d& scaleVec,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;

    GE_DLLEXPIMPORT double         operator [] (unsigned int i) const;
    GE_DLLEXPIMPORT double&        operator [] (unsigned int i);
    GE_DLLEXPIMPORT ZcGeScale2d&   set         (double sc0, double sc1);

    GE_DLLEXPIMPORT operator       ZcGeMatrix2d   () const;
    GE_DLLEXPIMPORT void           getMatrix      (ZcGeMatrix2d& mat) const;
    GE_DLLEXPIMPORT ZcGeScale2d&   extractScale   ( const ZcGeMatrix2d& mat );
    GE_DLLEXPIMPORT ZcGeScale2d&   removeScale    ( ZcGeMatrix2d& mat );

    GE_DLLEXPIMPORT operator       ZcGeScale3d    () const;

    double         sx, sy;
};

inline double
ZcGeScale2d::operator [] (unsigned int i) const
{
    return *(&sx+i);
}

inline double&
ZcGeScale2d::operator [] (unsigned int i)
{
    return *(&sx+i);
}

inline bool
ZcGeScale2d::operator == (const ZcGeScale2d& s) const
{
    return this->isEqualTo(s);
}

inline bool
ZcGeScale2d::operator != (const ZcGeScale2d& s) const
{
    return !this->isEqualTo(s);
}

#pragma pack (pop)
#endif
