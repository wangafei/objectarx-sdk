/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_HIDE_H
#define GMODELER_INC_HIDE_H

#include <limits.h>
#include "transf3d.h"

GMODELER_NAMESPACE_BEGIN

const int kHideIntMax = INT_MAX / 4 - 4;

class DllImpExp HideIntegerTransform
{
public:
  Point3d projectedIntToProjectedDouble(IntPoint3d ip) const
  {
    return Point3d(mRx*ip.x + mSx, mRy*ip.y + mSy, mRz*ip.z + mSz);
  }

  double mRx, mSx;
  double mRy, mSy;
  double mRz, mSz;
};

enum PointInPolygonLocation
{
  kPointOutsidePolygon      = 0,
  kPointBehindPolygonVertex = 1,
  kPointBehindPolygonEdge   = 2,
  kPointBehindPolygonFace   = 3,
  kPointAtPolygonVertex     = -1,
  kPointOnPolygonEdge       = -2,
  kPointInPolygonFace       = -3
};

PointInPolygonLocation pointInPolygonTest(IntPoint3d p, Face* f, int* zPtr = NULL);

GMODELER_NAMESPACE_END
#endif
