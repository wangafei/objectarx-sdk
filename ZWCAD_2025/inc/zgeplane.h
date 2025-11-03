

#ifndef ZC_GEPLANE_H
#define ZC_GEPLANE_H

#include "zgeplanar.h"
#pragma pack (push, 8)

class ZcGeBoundedPlane;
class ZcGeLine3d;

class
ZcGePlane : public ZcGePlanarEnt
{
public:

    GE_DLLDATAEXIMP static const ZcGePlane kXYPlane;
    GE_DLLDATAEXIMP static const ZcGePlane kYZPlane;
    GE_DLLDATAEXIMP static const ZcGePlane kZXPlane;

    GE_DLLEXPIMPORT ZcGePlane();
    GE_DLLEXPIMPORT ZcGePlane(const ZcGePlane& src);
    GE_DLLEXPIMPORT ZcGePlane(const ZcGePoint3d& origin, const ZcGeVector3d& normal);

    GE_DLLEXPIMPORT ZcGePlane(const ZcGePoint3d& pntU, const ZcGePoint3d& org, const ZcGePoint3d& pntV);

    GE_DLLEXPIMPORT ZcGePlane(const ZcGePoint3d& org, const ZcGeVector3d& uAxis,
              const ZcGeVector3d& vAxis);
    GE_DLLEXPIMPORT ZcGePlane(double a, double b, double c, double d);

    GE_DLLEXPIMPORT double         signedDistanceTo (const ZcGePoint3d& pnt) const;

    GE_DLLEXPIMPORT ZSoft::Boolean intersectWith    (const ZcGeLinearEnt3d& linEnt, ZcGePoint3d& resultPnt,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;
    GE_DLLEXPIMPORT ZSoft::Boolean intersectWith    (const ZcGePlane& otherPln, ZcGeLine3d& resultLine,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;
    GE_DLLEXPIMPORT ZSoft::Boolean intersectWith    (const ZcGeBoundedPlane& bndPln, ZcGeLineSeg3d& resultLineSeg,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;

    GE_DLLEXPIMPORT ZcGePlane&     set              (const ZcGePoint3d& pnt, const ZcGeVector3d& normal);
    GE_DLLEXPIMPORT ZcGePlane&     set              (const ZcGePoint3d& pntU, const ZcGePoint3d& org,
                                     const ZcGePoint3d& pntV);
    GE_DLLEXPIMPORT ZcGePlane&     set              (double a, double b, double c, double d);
    GE_DLLEXPIMPORT ZcGePlane&     set              (const ZcGePoint3d& org,
                                     const ZcGeVector3d& uAxis,
                                     const ZcGeVector3d& vAxis);

    GE_DLLEXPIMPORT ZcGePlane&     operator =       (const ZcGePlane& src);
};

#pragma pack (pop)
#endif
