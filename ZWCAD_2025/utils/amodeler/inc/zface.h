
#ifndef AECMODELER_INC_FACE_H
#define AECMODELER_INC_FACE_H


#include "zbody.h"
#include "zplane.h"
#include "zenums.h"

AECMODELER_NAMESPACE_BEGIN


const ZwFlag FFF = ZWFLAG(0);
const ZwFlag CONVEXFF = ZWFLAG(1);



class DllImpExp ZwFace : public ZwEntity
{
public:
    ZwFace();
    ZwFace(                 ZwBody*);
    ZwFace(       ZwSurface*, ZwBody*);
    ZwFace(ZwEdge*, ZwSurface*, ZwBody*);
    ZwFace(const ZwFace&);
    ~ZwFace();


    ZwFace(const ZwCircle3d&, int type, int approx, ZwBody*);

    ZwFace(const ZwPoint3d      plg       [],
         ZwPolygonVertexData* vertexData[],
         int                numVertices, 
         const ZwVector3d&    plgNormal,
         int                type,  
         bool               checkPlanarity, 
         ZwBody*);

    ZwFace(ZwPoint3d            p[], 
         int                numEdges,
         int                type, 
         bool               checkPlanarity,
         ZwBody*,
         ZwEdge**             createdEdges = NULL);

    ZwFace(ZwVertex*            vertices[],
         ZwCurve*             curves[],
         ZwEdge*              partners[], 
         int                numEdges, 
         int                type, 
         bool               checkPlanarity, 
         ZwBody*, 
         ZwEdge**             createdEdges = NULL);

    void     modified      ();

    int      edgeCount     () const;
    ZwEdge*    edge          (int edgeIndexInFace) const;
    
    ZwEdge*    edgeLoop      () const        { return mpEdgeLoop; }
    ZwSurface* surface       () const        { return mpSurface;  }
    ZwFace*    next          () const        { return mpNext;     }
    ZwFace*    prev          () const        { return mpPrev;     }
    ZwColor    color         () const        { return mColor;     }
    void*    attrib        () const        { return mpAttrib;   }

    void     setEdgeLoop   (ZwEdge*       e) { mpEdgeLoop = e;    }
    void     setSurface    (ZwSurface*    s) { mpSurface  = s;    }
    void     setNext       (ZwFace*       f) { mpNext     = f;    }
    void     setPrev       (ZwFace*       f) { mpPrev     = f;    }

    void     setColor      (ZwColor, bool edgesAlso = false, bool partnerEdgesAlso = false);
    void     setAttrib     (void* a)       { mpAttrib = a; }

    void     addEdge       (ZwEdge*, ZwEdge* prevEdge = NULL);
    void     removeEdge    (ZwEdge*);
    void     deleteAllEdges();

    void     negate        ();
    
    void     paint         (const ZwBody&, ZwColor, bool dae=false, bool dbe=false);

    void     massProperties(const ZwBody&,
                            bool     dae,
                            bool     dbe,
                            double&  perimeter,
                            double&  area,
                            ZwPoint3d& centroid) const;

    double   area          () const;

    void     triangulate   (ZwOutputTriangleCallback*, 
                            ZwTriangulationType = kGenerateTriangles) const;

    void  lift(const ZwTransf3d&, bool checkPlanarity, ZwBody* owningBody);

    void extractAllLoops(std::vector<std::vector<ZwEdge*> >& loops) const;

    ZwFace* split(ZwEdge* e1, ZwEdge* e2, ZwBody*);

    void insertHoles(const std::vector<ZwFace*>& holeFaces, 
                     ZwBody*                     pBody,
                     std::vector<ZwFace*>&       faces);

    void decomposeIntoContiguousFaces(ZwBody* pBody, std::vector<ZwFace*>& contiguousFaces);

    const ZwPlane&         plane       () const;
    const ZwInterval3d&    interval    () const;
    const ZwIntInterval3d& projInterval() const;

    void deletePlane          () const;
    void deleteInterval       () const;
    void deleteProjInterval   () const;

    void setProjInterval      (const ZwIntInterval3d&) const;

    bool isPointInside(const ZwPoint3d&)   const;
    bool isPlanar(double eps = ZwEpsAbs()) const;
    bool isSelfIntersecting()            const;

    void print   (FILE* = NULL)          const;
    void save    (ZwSaveRestoreCallback* pCallBack)  const;
    void restore (ZwSaveRestoreCallback* pCallBack, int version);
    
    union
    {
        ZwEdge* iel;
        ZwFace* fptr;
        int   n;
    };

private:

    ZwEdge*          mpEdgeLoop;
    ZwSurface*       mpSurface;

    ZwFace*          mpNext;
    ZwFace*          mpPrev;

    ZwPlane*         mpPlane;
    ZwInterval3d*    mpInterval;
    ZwIntInterval3d* mpProjInterval;

    ZwColor          mColor;
    void*          mpAttrib;

    double evaluatePlane   () const;
    void   evaluateInterval() const;

};


AECMODELER_NAMESPACE_END



#include "zedge.h"

AECMODELER_NAMESPACE_BEGIN

inline const ZwPlane& ZwFace::plane() const 
{
    if (mpPlane == NULL)
        evaluatePlane();

    MASSERT(mpPlane->isValid());   

    return *mpPlane; 
}



inline const ZwInterval3d& ZwFace::interval() const 
{ 
    if (mpInterval == NULL)
        evaluateInterval();

    return *mpInterval;
}


inline const ZwIntInterval3d& ZwFace::projInterval() const 
{ 
    MASSERT(mpProjInterval != NULL);
    return *mpProjInterval;
}


inline void ZwFace::addEdge(ZwEdge* e, ZwEdge* prevEdge)
{
    if (e == NULL) 
    {
        FAIL;
        return;
    }


    MASSERT(e->next() == NULL && e->prev() == NULL && e->face() == NULL);

    if (prevEdge == NULL)
    {
        prevEdge = edgeLoop();
    }

    if (prevEdge != NULL)
    {
        e->addAfter(prevEdge);
    }
    else 
    {
        e->setNext(e);
        e->setPrev(e);
    }

    e->setFace(this);
    setEdgeLoop(e);
}


inline void ZwFace::removeEdge(ZwEdge* e)
{
    if (e == NULL || e->face() != this)
    {
        FAIL;
        return;
    }

    if (edgeLoop() == e)
    {
        if (e->next() != e)
        {
            setEdgeLoop(e->next());
        }
        else
        {
            setEdgeLoop(NULL);
        }
    }

    e->next()->setPrev(e->prev());
    e->prev()->setNext(e->next());
    e->removePartner();

    e->setNext(NULL);
    e->setPrev(NULL);
    e->setFace(NULL);
}

AECMODELER_NAMESPACE_END
#endif
