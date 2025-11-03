/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GECLIP2D_H
#define GC_GECLIP2D_H

#include "gsoft.h"
#include "assert.h"
#include "geent2d.h"
#include "gepnt2d.h"
#include "gept2dar.h"
#include "gegbl.h"
#include "geintarr.h"
#pragma pack (push, 8)

class GcGeImpClipBoundary2d;

class
  GE_DLLDATAEXIMP
  GcGeClipBoundary2d : public GcGeEntity2d
{
public:
  GcGeClipBoundary2d();
  GcGeClipBoundary2d(const GcGePoint2d& cornerA, const GcGePoint2d& cornerB);
  GcGeClipBoundary2d(const GcGePoint2dArray& clipBoundary);
  GcGeClipBoundary2d(const GcGeClipBoundary2d& src);

  GcGe::ClipError		set(const GcGePoint2d& cornerA, const GcGePoint2d& cornerB);
  GcGe::ClipError		set(const GcGePoint2dArray& clipBoundary);

  GcGe::ClipError		clipPolygon(const GcGePoint2dArray& rawVertices,
    GcGePoint2dArray& clippedVertices,
    GcGe::ClipCondition& clipCondition,
    GcGeIntArray* pClippedSegmentSourceLabel = 0) const;
  GcGe::ClipError		clipPolyline(const GcGePoint2dArray& rawVertices,
    GcGePoint2dArray& clippedVertices,
    GcGe::ClipCondition& clipCondition,
    GcGeIntArray* pClippedSegmentSourceLabel = 0) const;

  GcGeClipBoundary2d& operator = (const GcGeClipBoundary2d& crvInt);
};

#pragma pack (pop)
#endif