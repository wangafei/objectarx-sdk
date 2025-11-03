

#ifndef ZC_GEMAT3D_H
#define ZC_GEMAT3D_H

#include "zgegbl.h"
#include "zgemat2d.h"
#include "zgepnt3d.h"
#pragma pack (push, 8)

class ZcGeLine3d;
class ZcGeVector3d;
class ZcGePlane;
class ZcGeTol;

class 
ZcGeMatrix3d
{
public:
    GE_DLLEXPIMPORT ZcGeMatrix3d();
    GE_DLLEXPIMPORT ZcGeMatrix3d(const ZcGeMatrix3d& src);

    GE_DLLDATAEXIMP static const   ZcGeMatrix3d    kIdentity;

    GE_DLLEXPIMPORT ZcGeMatrix3d&  setToIdentity();

    GE_DLLEXPIMPORT ZcGeMatrix3d   operator *      (const ZcGeMatrix3d& mat) const;
    GE_DLLEXPIMPORT ZcGeMatrix3d&  operator *=     (const ZcGeMatrix3d& mat);
    GE_DLLEXPIMPORT ZcGeMatrix3d&  preMultBy       (const ZcGeMatrix3d& leftSide);
    GE_DLLEXPIMPORT ZcGeMatrix3d&  postMultBy      (const ZcGeMatrix3d& rightSide);
    GE_DLLEXPIMPORT ZcGeMatrix3d&  setToProduct    (const ZcGeMatrix3d& mat1, const ZcGeMatrix3d& mat2);

    GE_DLLEXPIMPORT ZcGeMatrix3d&  invert          ();
    GE_DLLEXPIMPORT ZcGeMatrix3d   inverse         () const;
    GE_DLLEXPIMPORT ZcGeMatrix3d   inverse         (const ZcGeTol& tol) const;

    GE_DLLEXPIMPORT ZSoft::Boolean isSingular      (const ZcGeTol& tol = ZcGeContext::gTol) const;

    GE_DLLEXPIMPORT ZcGeMatrix3d&  transposeIt     ();
    GE_DLLEXPIMPORT ZcGeMatrix3d   transpose       () const;

    GE_DLLEXPIMPORT bool operator ==     (const ZcGeMatrix3d& mat) const;
    GE_DLLEXPIMPORT bool operator !=     (const ZcGeMatrix3d& mat) const;
    GE_DLLEXPIMPORT bool isEqualTo       (const ZcGeMatrix3d& mat, const ZcGeTol& tol
                                    = ZcGeContext::gTol) const;

    GE_DLLEXPIMPORT ZSoft::Boolean isUniScaledOrtho(const ZcGeTol& tol = ZcGeContext::gTol) const;
    GE_DLLEXPIMPORT ZSoft::Boolean isScaledOrtho   (const ZcGeTol& tol = ZcGeContext::gTol) const;

    GE_DLLEXPIMPORT double         det             () const;

    GE_DLLEXPIMPORT ZcGeMatrix3d&  setTranslation  (const ZcGeVector3d& vec);
    GE_DLLEXPIMPORT ZcGeVector3d   translation     () const;

    GE_DLLEXPIMPORT ZcGeMatrix3d&  setCoordSystem  (const ZcGePoint3d& origin,
                                    const ZcGeVector3d& xAxis,
                                    const ZcGeVector3d& yAxis,
                                    const ZcGeVector3d& zAxis);
    GE_DLLEXPIMPORT void           getCoordSystem  (ZcGePoint3d& origin,
                                    ZcGeVector3d& xAxis,
                                    ZcGeVector3d& yAxis,
                                    ZcGeVector3d& zAxis) const;

    GE_DLLEXPIMPORT ZcGeMatrix3d&  setToTranslation(const ZcGeVector3d& vec);
    GE_DLLEXPIMPORT ZcGeMatrix3d&  setToRotation   (double angle, const ZcGeVector3d& axis,
                                    const ZcGePoint3d& center
                                    = ZcGePoint3d::kOrigin);
    GE_DLLEXPIMPORT ZcGeMatrix3d&  setToScaling    (double scaleAll, const ZcGePoint3d& center
                                    = ZcGePoint3d::kOrigin);
    GE_DLLEXPIMPORT ZcGeMatrix3d&  setToMirroring  (const ZcGePlane& pln);
    GE_DLLEXPIMPORT ZcGeMatrix3d&  setToMirroring  (const ZcGePoint3d& pnt);
    GE_DLLEXPIMPORT ZcGeMatrix3d&  setToMirroring  (const ZcGeLine3d& line);
    GE_DLLEXPIMPORT ZcGeMatrix3d&  setToProjection (const ZcGePlane& projectionPlane,
                                    const ZcGeVector3d& projectDir);
    GE_DLLEXPIMPORT ZcGeMatrix3d&  setToAlignCoordSys(const ZcGePoint3d& fromOrigin,
                                    const ZcGeVector3d& fromXAxis,
                                    const ZcGeVector3d& fromYAxis,
                                    const ZcGeVector3d& fromZAxis,
                                    const ZcGePoint3d& toOrigin,
                                    const ZcGeVector3d& toXAxis,
                                    const ZcGeVector3d& toYAxis,
                                    const ZcGeVector3d& toZAxis);

    GE_DLLEXPIMPORT ZcGeMatrix3d&  setToWorldToPlane(const ZcGeVector3d& normal);
    GE_DLLEXPIMPORT ZcGeMatrix3d&  setToWorldToPlane(const ZcGePlane& plane);
    GE_DLLEXPIMPORT ZcGeMatrix3d&  setToPlaneToWorld(const ZcGeVector3d& normal);
    GE_DLLEXPIMPORT ZcGeMatrix3d&  setToPlaneToWorld(const ZcGePlane& plane);

    GE_DLLEXPIMPORT static
    ZcGeMatrix3d   translation     (const ZcGeVector3d& vec);
    GE_DLLEXPIMPORT static
    ZcGeMatrix3d   rotation        (double angle, const ZcGeVector3d& axis,
                                    const ZcGePoint3d& center
                                    = ZcGePoint3d::kOrigin);
    GE_DLLEXPIMPORT static
    ZcGeMatrix3d   scaling         (double scaleAll, const ZcGePoint3d& center
                                    = ZcGePoint3d::kOrigin);
    GE_DLLEXPIMPORT static
    ZcGeMatrix3d   mirroring       (const ZcGePlane& pln);
    GE_DLLEXPIMPORT static
    ZcGeMatrix3d   mirroring       (const ZcGePoint3d& pnt);
    GE_DLLEXPIMPORT static
    ZcGeMatrix3d   mirroring       (const ZcGeLine3d& line);
    GE_DLLEXPIMPORT static
    ZcGeMatrix3d   projection      (const ZcGePlane& projectionPlane,
                                    const ZcGeVector3d& projectDir);
    GE_DLLEXPIMPORT static
    ZcGeMatrix3d   alignCoordSys   (const ZcGePoint3d&  fromOrigin,
                                    const ZcGeVector3d& fromXAxis,
                                    const ZcGeVector3d& fromYAxis,
                                    const ZcGeVector3d& fromZAxis,
                                    const ZcGePoint3d&  toOrigin,
                                    const ZcGeVector3d& toXAxis,
                                    const ZcGeVector3d& toYAxis,
                                    const ZcGeVector3d& toZAxis);

    GE_DLLEXPIMPORT static
    ZcGeMatrix3d   worldToPlane    (const ZcGeVector3d& normal);
    GE_DLLEXPIMPORT static
    ZcGeMatrix3d   worldToPlane    (const ZcGePlane&);
    GE_DLLEXPIMPORT static
    ZcGeMatrix3d   planeToWorld    (const ZcGeVector3d& normal);
    GE_DLLEXPIMPORT static
    ZcGeMatrix3d   planeToWorld    (const ZcGePlane&);

	GE_DLLEXPIMPORT double scale(void) const;

    GE_DLLEXPIMPORT double          norm            () const;

    GE_DLLEXPIMPORT ZcGeMatrix2d convertToLocal     (ZcGeVector3d& normal, double& elev) const;

    GE_DLLEXPIMPORT double         operator ()     (unsigned int, unsigned int) const;
    GE_DLLEXPIMPORT double&        operator ()     (unsigned int, unsigned int);

    double         entry[4][4];    

    GE_DLLEXPIMPORT ZSoft::Boolean  inverse(ZcGeMatrix3d& inv, double tol) const;

private:
    void           pivot           (int, ZcGeMatrix3d&);
    int            pivotIndex(int) const;
    void           swapRows        (int, int, ZcGeMatrix3d&);
};

inline bool
ZcGeMatrix3d::operator == (const ZcGeMatrix3d& otherMatrix) const
{
    return this->isEqualTo(otherMatrix);
}

inline bool
ZcGeMatrix3d::operator != (const ZcGeMatrix3d& otherMatrix) const
{
    return !this->isEqualTo(otherMatrix);
}

inline double
ZcGeMatrix3d::operator () (
    unsigned int row,
    unsigned int column) const
{
    return entry[row][column];
}

inline double&
ZcGeMatrix3d::operator () (
    unsigned int row,
    unsigned int column)
{
    return entry[row][column];
}

#pragma pack (pop)
#endif
