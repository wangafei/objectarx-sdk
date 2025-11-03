#ifndef __FMMDL_CALLBACK_H__
#define __FMMDL_CALLBACK_H__


#include "../FacetModeler/Modeler/FMMdlBase.h"

namespace FacetModeler
{

class FMGEOMETRY_API OutputPolylineCallback
{
public:

    virtual ~OutputPolylineCallback() {}
    virtual void outputPolyline(Edge*          edgeArray [],
                                const Point3d  pointArray[],
                                const double   bulgeArray[],
                                int            numPoints,
                                bool           isClosed,
                                bool           isVisible) = NULL;

    virtual void outputArc     (Edge*          edge,
                                const Point3d& center,
                                double         radius,
                                double         startAngle,
                                double         endAngle,
                                bool           isVisible) = NULL;

}; 


class FMGEOMETRY_API OutputTriangleCallback
{
public:

    virtual ~OutputTriangleCallback() {}

    virtual void outputTriangle(Edge* edgeArray[], int arrayLength) = NULL;

    enum { kMaxTriStripLength = 200 };

    virtual void outputTriStrip(Edge* edgeArray[], 
                                int   arrayLength,
                                bool  firstTriangleIsCcw) = NULL;

};


class FMGEOMETRY_API SaveRestoreCallback
{
public:

    virtual ~SaveRestoreCallback() {}

    virtual void saveBytes   (const void* buffer, int requiredLength) = NULL;
    virtual void restoreBytes(void*       buffer, int requiredLength) = NULL;

};


/*
class FMGEOMETRY_API TopologyChangeCallback
{
public:

    virtual ~TopologyChangeCallback() {}

    virtual void entityCreated(Entity*)                              = NULL;
    virtual void entityDeleted(Entity*)                              = NULL;
    virtual void entitySplit  (Entity* pOrig,      Entity* pNew)     = NULL;
    virtual void entityMerged (Entity* pSurviving, Entity* pDeleted) = NULL;


};
*/


class FMGEOMETRY_API SaveToSatCallback
{
public:

    virtual ~SaveToSatCallback() {}

    virtual void saveIndex  (int)         = NULL; 
    virtual void saveIdent  (const char*) = NULL;
    virtual void saveDouble (double)      = NULL;
    virtual void saveInt    (int)         = NULL;

}; 


}
#endif

