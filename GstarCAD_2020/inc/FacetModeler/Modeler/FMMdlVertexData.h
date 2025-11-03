#ifndef __FMMDL_VERTEXDATA_H__
#define __FMMDL_VERTEXDATA_H__

#include "../FacetModeler/Modeler/FMMdlCircle3d.h"

/**
  <group TA_Geometry>
*/
namespace FacetModeler
{

  class FMGEOMETRY_API PolygonVertexData
  {
  public:

    enum Type { kArc3d, kArcByRadius, kArcByBulge, kFilletByRadius, kUnspecifiedCurve };

    PolygonVertexData(Type);                            
    PolygonVertexData(Type, const Circle3d&, int apprx);
    PolygonVertexData(Type, double rad, bool isCenLeft, int apprx);
    PolygonVertexData(Type, double bulgeOrRadius, int apprx);      

    bool isArc() const 
    { 
      return type == kArc3d || type == kArcByRadius || type == kArcByBulge || type == kFilletByRadius; 
    }

  public: // data

    Type     type;
    Circle3d circle;
    int      approx;
    bool     isCenterLeft;
    double   bulge;
    Curve*   curve;
    Surface* surface;

  }; // class PolygonVertexData

 FMGEOMETRY_API void deleteVertexData(PolygonVertexData* vertexDataArray[], int arrayLength, bool alsoDeleteArray);
}

#endif //__FMMDL_VERTEXDATA_H__
