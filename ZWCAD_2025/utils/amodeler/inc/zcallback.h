
#ifndef AECMODELER_INC_CALLBACK_H
#define AECMODELER_INC_CALLBACK_H


#include "zglobal.h"
#include "zcolor.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwOutputPolylineCallback
{
public:

    virtual ~ZwOutputPolylineCallback() {}
    
    virtual void outputPolyline(ZwEdge*          edgeArray [],
                                const ZwPoint3d  pointArray[],
                                const double   bulgeArray[],
                                int            numPoints,
                                bool           isClosed,
                                bool           isVisible) = NULL;

    virtual void outputArc     (ZwEdge*          edge,
                                const ZwPoint3d& center,
                                double         radius,
                                double         startAngle,
                                double         endAngle,
                                bool           isVisible) = NULL;

};



class DllImpExp ZwOutputTriangleCallback
{
public:

    virtual ~ZwOutputTriangleCallback() {}

    virtual void outputTriangle(ZwEdge* edgeArray[], int arrayLength) = NULL;

    enum { kMaxTriStripLength = 200 };

    virtual void outputTriStrip(ZwEdge* edgeArray[], 
                                int   arrayLength,
                                bool  firstTriangleIsCcw) = NULL;

};



class DllImpExp ZwSaveRestoreCallback
{
public:

    virtual ~ZwSaveRestoreCallback() {}

    virtual void saveBytes   (const void* buffer, int requiredLength) = NULL;
    virtual void restoreBytes(void*       buffer, int requiredLength) = NULL;

}; 


class DllImpExp ZwTopologyChangeCallback
{
public:

    virtual ~ZwTopologyChangeCallback() {}
    virtual void entityCreated(ZwEntity*) = NULL;
    virtual void entityDeleted(ZwEntity*) = NULL;
    virtual void entitySplit(ZwEntity* pOrig, ZwEntity* pNew) = NULL;
    virtual void entityMerged(ZwEntity* pSurviving, ZwEntity* pDeleted) = NULL;


};



class DllImpExp ZwSaveToSatCallback
{
public:

    virtual ~ZwSaveToSatCallback() {}

    virtual void saveIndex  (int)         = NULL; 
    virtual void saveIdent  (const char*) = NULL;
    virtual void saveDouble (double)      = NULL;
    virtual void saveInt    (int)         = NULL;

};


AECMODELER_NAMESPACE_END
#endif

