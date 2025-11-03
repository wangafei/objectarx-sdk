/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_ENUMS_H
#define GMODELER_INC_ENUMS_H

#include "global.h"

GMODELER_NAMESPACE_BEGIN

enum BoolOperType
{
  kBoolOperUnite,
  kBoolOperSubtract,
  kBoolOperIntersect
};

enum BodyInterferenceType
{
  kBodiesDoNotInterfere,
  kBodiesTouch,
  kBodiesInterfere
};

enum PointInBodyLocation
{
  kPointOutsideBody,
  kPointAtVertex,
  kPointOnEdge,
  kPointInFace,
  kPointInsideBody
};

enum HiddenLinesDisplay
{
  kHiddenLinesInvisible,
  kHiddenLinesDashed,
  kHiddenLinesVisible
};

enum HiddenLineDrawingImprove
{
  kNoDrawingImprove,
  kConnectDrawingImprove,
  kArcReconstructDrawingImprove
};

enum TriangulationType
{
  kGenerateTriangles,
  kGenerateQuadrilaterals,
  kGenerateTriStrips,
  kGenerateTriStripsPerSurface
};

enum RayBodyIntersection
{
  kRayDoesNotIntersect,
  kRayPointAtVertex,
  kRayPointOnEdge,
  kRayPointInFace,
  kRayIntersectsVertex,
  kRayIntersectsEdge,
  kRayIntersectsFace
};

GMODELER_NAMESPACE_END
#endif
