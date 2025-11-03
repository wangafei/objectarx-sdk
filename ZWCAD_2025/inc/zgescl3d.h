

#ifndef ZC_GESCL3D_H
#define ZC_GESCL3D_H

#include "zadesk.h"
#include "zgegbl.h"
#pragma pack (push, 8)

class ZcGeMatrix3d;

class 
ZcGeScale3d
{
public:
    GE_DLLEXPIMPORT ZcGeScale3d();
    GE_DLLEXPIMPORT ZcGeScale3d(const ZcGeScale3d& src);
    GE_DLLEXPIMPORT ZcGeScale3d(double factor);
    GE_DLLEXPIMPORT ZcGeScale3d(double xFact, double yFact, double zFact);

    GE_DLLDATAEXIMP static const   ZcGeScale3d kIdentity;

    GE_DLLEXPIMPORT ZcGeScale3d    operator *  (const ZcGeScale3d& sclVec) const;
    GE_DLLEXPIMPORT ZcGeScale3d&   operator *= (const ZcGeScale3d& scl);
    GE_DLLEXPIMPORT ZcGeScale3d&   preMultBy   (const ZcGeScale3d& leftSide);
    GE_DLLEXPIMPORT ZcGeScale3d&   postMultBy  (const ZcGeScale3d& rightSide);
    GE_DLLEXPIMPORT ZcGeScale3d&   setToProduct(const ZcGeScale3d& sclVec1, const ZcGeScale3d& sclVec2);
	GE_DLLEXPIMPORT ZcGeScale3d    operator *  (double s) const;
	GE_DLLEXPIMPORT ZcGeScale3d&   operator *= (double s);
    GE_DLLEXPIMPORT ZcGeScale3d&   setToProduct(const ZcGeScale3d& sclVec, double s);
    friend GE_DLLEXPIMPORT
    ZcGeScale3d    operator *  (double, const ZcGeScale3d& scl);

    GE_DLLEXPIMPORT ZcGeScale3d    inverse        () const;
    GE_DLLEXPIMPORT ZcGeScale3d&   invert         ();

    GE_DLLEXPIMPORT ZSoft::Boolean isProportional(const ZcGeTol& tol = ZcGeContext::gTol) const;

    GE_DLLEXPIMPORT bool operator == (const ZcGeScale3d& sclVec) const;
    GE_DLLEXPIMPORT bool operator != (const ZcGeScale3d& sclVec) const;
    GE_DLLEXPIMPORT bool isEqualTo   (const ZcGeScale3d& scaleVec,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;

    GE_DLLEXPIMPORT double         operator [] (unsigned int i) const;
    GE_DLLEXPIMPORT double&        operator [] (unsigned int i);
    GE_DLLEXPIMPORT ZcGeScale3d&   set         (double sc0, double sc1, double sc2);

    GE_DLLEXPIMPORT operator       ZcGeMatrix3d   () const;
    GE_DLLEXPIMPORT void getMatrix(ZcGeMatrix3d& mat) const;
    GE_DLLEXPIMPORT ZcGeScale3d&   extractScale   ( const ZcGeMatrix3d& mat );
    GE_DLLEXPIMPORT ZcGeScale3d&   removeScale    ( ZcGeMatrix3d& mat );

    double         sx, sy, sz;
};

inline bool
ZcGeScale3d::operator == (const ZcGeScale3d& s) const
{
    return this->isEqualTo(s);
}

inline bool
ZcGeScale3d::operator != (const ZcGeScale3d& s) const
{
    return !(this->isEqualTo(s));
}

inline double
ZcGeScale3d::operator [] (unsigned int i) const
{
    return *(&sx+i);
}

inline double&
ZcGeScale3d::operator [] (unsigned int i)
{
    return *(&sx+i);
}

#pragma pack (pop)
#endif
