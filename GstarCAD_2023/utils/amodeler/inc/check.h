/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_CHECK_H
#define GMODELER_INC_CHECK_H

#include "global.h"

GMODELER_NAMESPACE_BEGIN

DllImpExp void checkProfile(const Body& profileBody);
DllImpExp void checkMorphingMap(const MorphingMap& morphingMap, int numEdges0, int numEdges1);
DllImpExp void checkFaceAgainstAxis(Face*, const Line3d& axis);

DllImpExp bool isPolygonSelfIntersecting(const Point3d plg[], int numEdges, int i1, int i2);

DllImpExp ErrorCode checkPolygon(const Point3d   plg[],
                                 int             numEdges,
                                 const Plane&    plgPlane,
                                 const Vector3d& plgNormal);

GMODELER_NAMESPACE_END
#endif
