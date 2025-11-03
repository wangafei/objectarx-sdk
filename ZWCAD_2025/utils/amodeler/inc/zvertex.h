#ifndef AECMODELER_INC_VERTEX_H
#define AECMODELER_INC_VERTEX_H


#include "zentity.h"
#include "zpoint3d.h"

AECMODELER_NAMESPACE_BEGIN

const ZwFlag PICKVF = ZWFLAG(0);
const ZwFlag NONMANIFOLD_VF = ZWFLAG(1);


class DllImpExp ZwVertex : public ZwEntity
{
public:
    ZwVertex() : vptr(NULL), eptr(NULL), mpVertexSurfaceDataList(NULL), mpNext(NULL) {}
    ZwVertex(const ZwPoint3d&, ZwBody*);
    ~ZwVertex();

    const ZwPoint3d& point     () const           { return mPoint; }
    ZwVertex*        next      () const           { return mpNext; }

    void           setPoint  (const ZwPoint3d& p) { mPoint  = p;   }
    void           setNext   (ZwVertex* v)        { mpNext  = v;   }
    void           transform (const ZwTransf3d&); 
    void           modified  ();
    ZwVertexSurfaceData* vertexSurfaceDataList   () const { return mpVertexSurfaceDataList; }
    void               deleteVertexSurfaceData ();
    void               setVertexSurfaceDataList(ZwVertexSurfaceData* vsd) { mpVertexSurfaceDataList = vsd; }

    ZwVertexSurfaceData* vertexSurfaceData(const ZwEdge* e);

    void           print     (FILE* = NULL)         const; 
    void           save      (ZwSaveRestoreCallback* pCallBack) const;
    void           restore   (ZwSaveRestoreCallback* pCallBack, int version);

    ZwIntPoint3d     ip;

    union
    {
        ZwVertex* vptr;
        int     n;
    };
    union
    {
        ZwEdge*   eptr;
        ZwVertex* vptr1;
    };

private:

    ZwPoint3d            mPoint;            
    ZwVertexSurfaceData* mpVertexSurfaceDataList; 
    ZwVertex*            mpNext; 

};

inline ZwVertex::~ZwVertex()
{
    deleteVertexSurfaceData();
}


AECMODELER_NAMESPACE_END
#endif
