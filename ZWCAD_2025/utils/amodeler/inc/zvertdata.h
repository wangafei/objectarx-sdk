
#ifndef AECMODELER_INC_VERTDATA_H
#define AECMODELER_INC_VERTDATA_H


#include "zcircle3d.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwPolygonVertexData
{
public:

    enum Type { kArc3d, kArcByRadius, kArcByBulge, kFilletByRadius, kUnspecifiedCurve };

    ZwPolygonVertexData(Type);
    ZwPolygonVertexData(Type, const ZwCircle3d&, int apprx);
    ZwPolygonVertexData(Type, double rad, bool isCenLeft, int apprx);
    ZwPolygonVertexData(Type, double bulgeOrRadius, int apprx);

    bool isArc() const 
    { 
        return type == kArc3d || type == kArcByRadius || type == kArcByBulge || type == kFilletByRadius; 
    }

public:

    Type     type;
    ZwCircle3d circle;
    int      approx;
    bool     isCenterLeft;
    double   bulge;
    ZwCurve*   curve;
    ZwSurface* surface;

};

DllImpExp void ZwDeleteVertexData(ZwPolygonVertexData* vertexDataArray[], int arrayLength, bool alsoDeleteArray);


AECMODELER_NAMESPACE_END
#endif
