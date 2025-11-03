/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_VERTDATA_H
#define GMODELER_INC_VERTDATA_H

#include "circle3d.h"

GMODELER_NAMESPACE_BEGIN

class DllImpExp PolygonVertexData
{
public:
  enum Type
  {
    kArc3d,
    kArcByRadius,
    kArcByBulge,
    kFilletByRadius,
    kUnspecifiedCurve
  };

  PolygonVertexData(Type);
  PolygonVertexData(Type, const Circle3d&, int apprx);
  PolygonVertexData(Type, double rad, bool isCenLeft, int apprx);
  PolygonVertexData(Type, double bulgeOrRadius, int apprx);

  bool isArc() const
  {
    return type == kArc3d || type == kArcByRadius || type == kArcByBulge || type == kFilletByRadius;
  }

public:
  Type     type;
  Circle3d circle;
  int      approx;
  bool     isCenterLeft;
  double   bulge;
  Curve*   curve;
  Surface* surface;
};

DllImpExp void deleteVertexData(PolygonVertexData* vertexDataArray[], int arrayLength, bool alsoDeleteArray);

GMODELER_NAMESPACE_END
#endif
