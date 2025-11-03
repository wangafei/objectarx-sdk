
#ifndef AECMODELER_INC_HIDE_H
#define AECMODELER_INC_HIDE_H

#include <limits.h>
#include "ztransf3d.h"

AECMODELER_NAMESPACE_BEGIN

const int kHideIntMax = INT_MAX/4 - 4; 

class DllImpExp ZwHideIntegerTransform
{
public:

    ZwPoint3d projectedIntToProjectedDouble(ZwIntPoint3d ip) const
    {
        return ZwPoint3d(mRx*ip.x+mSx, mRy*ip.y+mSy, mRz*ip.z+mSz);
    }

    double mRx, mSx;
    double mRy, mSy;
    double mRz, mSz;
};

enum ZwPointInPolygonLocation
{
    kPointOutsidePolygon      =  0,
    kPointBehindPolygonVertex =  1,
    kPointBehindPolygonEdge   =  2,
    kPointBehindPolygonFace   =  3,
    kPointAtPolygonVertex     = -1,
    kPointOnPolygonEdge       = -2,
    kPointInPolygonFace       = -3
};

ZwPointInPolygonLocation ZwPointInPolygonTest(ZwIntPoint3d p, ZwFace* f, int* zPtr = NULL);

AECMODELER_NAMESPACE_END
#endif
