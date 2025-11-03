/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_DXFINPLN_H
#define GMODELER_INC_DXFINPLN_H

#include "global.h"

GMODELER_NAMESPACE_BEGIN

DllImpExp void dxfPolylineToAugmentedPolygon(FILE*                pInputDxfFile,
                                             int                  approx,
                                             Point3d*&            plg,
                                             PolygonVertexData**& vertexData,
                                             int&                 numVertices,
                                             Vector3d&            plgNormal);

GMODELER_NAMESPACE_END
#endif
