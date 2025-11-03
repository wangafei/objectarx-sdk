

#ifndef ZC_GEMAT2D_H
#define ZC_GEMAT2D_H

#include "zgegbl.h"
#include "zgepnt2d.h"
#pragma pack (push, 8)

class ZcGeVector2d;
class ZcGeLine2d;
class ZcGeTol;

class 
ZcGeMatrix2d
{
public:
    GE_DLLEXPIMPORT ZcGeMatrix2d();
    GE_DLLEXPIMPORT ZcGeMatrix2d(const ZcGeMatrix2d& src);

    GE_DLLDATAEXIMP static const   ZcGeMatrix2d   kIdentity;

    GE_DLLEXPIMPORT ZcGeMatrix2d&  setToIdentity();

    GE_DLLEXPIMPORT ZcGeMatrix2d   operator *   (const ZcGeMatrix2d& mat) const;
    GE_DLLEXPIMPORT ZcGeMatrix2d&  operator *=  (const ZcGeMatrix2d& mat);
    GE_DLLEXPIMPORT ZcGeMatrix2d&  preMultBy    (const ZcGeMatrix2d& leftSide);
    GE_DLLEXPIMPORT ZcGeMatrix2d&  postMultBy   (const ZcGeMatrix2d& rightSide);
    GE_DLLEXPIMPORT ZcGeMatrix2d&  setToProduct (const ZcGeMatrix2d& mat1, const ZcGeMatrix2d& mat2);

    GE_DLLEXPIMPORT ZcGeMatrix2d&  invert       ();
    GE_DLLEXPIMPORT ZcGeMatrix2d   inverse      () const;

    GE_DLLEXPIMPORT ZSoft::Boolean isSingular   (const ZcGeTol& tol = ZcGeContext::gTol) const;

    GE_DLLEXPIMPORT ZcGeMatrix2d&  transposeIt  ();
    GE_DLLEXPIMPORT ZcGeMatrix2d   transpose    () const;

    GE_DLLEXPIMPORT bool operator ==  (const ZcGeMatrix2d& mat) const;
    GE_DLLEXPIMPORT bool operator !=  (const ZcGeMatrix2d& mat) const;
    GE_DLLEXPIMPORT bool isEqualTo    (const ZcGeMatrix2d& mat,
                       const ZcGeTol& tol = ZcGeContext::gTol) const;

    GE_DLLEXPIMPORT ZSoft::Boolean isUniScaledOrtho(const ZcGeTol& tol = ZcGeContext::gTol) const;
    GE_DLLEXPIMPORT ZSoft::Boolean isScaledOrtho(const ZcGeTol& tol = ZcGeContext::gTol) const;
	GE_DLLEXPIMPORT double		   scale(void);

    GE_DLLEXPIMPORT double         det          () const;

    GE_DLLEXPIMPORT ZcGeMatrix2d&  setTranslation(const ZcGeVector2d& vec);
    GE_DLLEXPIMPORT ZcGeVector2d   translation  () const;

    GE_DLLEXPIMPORT ZSoft::Boolean isConformal (double& scale, double& angle,
                                ZSoft::Boolean& isMirror, ZcGeVector2d& reflex) const;

    GE_DLLEXPIMPORT ZcGeMatrix2d&  setCoordSystem(const ZcGePoint2d& origin,
                                 const ZcGeVector2d& e0,
                                 const ZcGeVector2d& e1);
    GE_DLLEXPIMPORT void           getCoordSystem(ZcGePoint2d& origin,
                                 ZcGeVector2d& e0,
                                 ZcGeVector2d& e1) const;

    GE_DLLEXPIMPORT ZcGeMatrix2d& setToTranslation(const ZcGeVector2d& vec);
    GE_DLLEXPIMPORT ZcGeMatrix2d& setToRotation (double angle,
                                 const ZcGePoint2d& center
				 = ZcGePoint2d::kOrigin);
    GE_DLLEXPIMPORT ZcGeMatrix2d& setToScaling  (double scaleAll,
                                 const ZcGePoint2d& center
				 = ZcGePoint2d::kOrigin);
    GE_DLLEXPIMPORT ZcGeMatrix2d& setToMirroring(const ZcGePoint2d& pnt);
    GE_DLLEXPIMPORT ZcGeMatrix2d& setToMirroring(const ZcGeLine2d& line);
    GE_DLLEXPIMPORT ZcGeMatrix2d& setToAlignCoordSys(const ZcGePoint2d&  fromOrigin,
                                 const ZcGeVector2d& fromE0,
                                 const ZcGeVector2d& fromE1,
                                 const ZcGePoint2d&  toOrigin,
                                 const ZcGeVector2d& toE0,
                                 const ZcGeVector2d& toE1);

    GE_DLLEXPIMPORT static
    ZcGeMatrix2d translation    (const ZcGeVector2d& vec);
    GE_DLLEXPIMPORT static
    ZcGeMatrix2d rotation       (double angle, const ZcGePoint2d& center
				 = ZcGePoint2d::kOrigin);
    GE_DLLEXPIMPORT static
    ZcGeMatrix2d scaling        (double scaleAll, const ZcGePoint2d& center
				 = ZcGePoint2d::kOrigin);
    GE_DLLEXPIMPORT static
    ZcGeMatrix2d mirroring      (const ZcGePoint2d& pnt);
    GE_DLLEXPIMPORT static
    ZcGeMatrix2d mirroring      (const ZcGeLine2d& line);
    GE_DLLEXPIMPORT static
    ZcGeMatrix2d alignCoordSys  (const ZcGePoint2d& fromOrigin,
                                 const ZcGeVector2d& fromE0,
                                 const ZcGeVector2d& fromE1,
                                 const ZcGePoint2d&  toOrigin,
                                 const ZcGeVector2d& toE0,
                                 const ZcGeVector2d& toE1);

    GE_DLLEXPIMPORT double         operator ()  (unsigned int, unsigned int) const;
    GE_DLLEXPIMPORT double&        operator ()  (unsigned int, unsigned int);

    double         entry[3][3]; 
};

inline bool
ZcGeMatrix2d::operator == (const ZcGeMatrix2d& otherMatrix) const
{
    return this->isEqualTo(otherMatrix);
}

inline bool
ZcGeMatrix2d::operator != (const ZcGeMatrix2d& otherMatrix) const
{
    return !this->isEqualTo(otherMatrix);
}

inline double
ZcGeMatrix2d::operator () (
    unsigned int row,
    unsigned int column) const
{
    return entry[row][column];
}

inline double&
ZcGeMatrix2d::operator () (
    unsigned int row,
    unsigned int column)
{
    return entry[row][column];
}

#pragma pack (pop)
#endif
