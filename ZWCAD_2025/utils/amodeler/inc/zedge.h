
#ifndef AECMODELER_INC_EDGE_H
#define AECMODELER_INC_EDGE_H

#pragma warning(push)
#pragma warning(disable : 4702)
#include <vector>
#pragma warning(pop)
#include "zentity.h"
#include "zcolor.h"
#include "zcircle3d.h"
#include "zvertex.h"

AECMODELER_NAMESPACE_BEGIN


const ZwFlag AEF    = ZWFLAG(0);
const ZwFlag BEF    = ZWFLAG(1);
const ZwFlag PICKEF = ZWFLAG(2);

class DllImpExp ZwEdge : public ZwEntity
{
public:
    ZwEdge();

    ZwEdge(ZwVertex* pVertex, ZwFace* pFace, ZwEdge* prevEdge, ZwEdge* partner, ZwCurve* = NULL);
    
    ZwVertex* vertex        () const    { return mpVertex;  }
    ZwFace*   face          () const    { return mpFace;    }
    ZwEdge*   next          () const    { return mpNext;    }
    ZwEdge*   prev          () const    { return mpPrev;    }
    ZwEdge*   partner       () const    { return mpPartner; }
    ZwCurve*  curve         () const    { return mpCurve;   }
    ZwColor   color         () const    { return mColor;    }
    void    setVertex     (ZwVertex* v) { mpVertex  = v;    }
    void    setFace       (ZwFace*   f) { mpFace    = f;    }
    void    setNext       (ZwEdge*   e) { mpNext    = e;    }
    void    setPrev       (ZwEdge*   e) { mpPrev    = e;    }
    void    setPartner    (ZwEdge* par) { mpPartner = par;  }

    void    setCurve(ZwCurve*, bool partnersAlso = false);
    void    setColor(ZwColor, bool partnersAlso = false);

    void    addPartner(ZwEdge*);
    void    removePartner ();
    void    orderPartnerEdgesAroundEulerEdge();

    void    collapse();

    void    addAfter      (ZwEdge* prevEdge);

    ZwEdge* getPartnerBridgeEdge() const; // Returns NULL if not a bridge
    ZwEdge* nextSkipBridge() const;
    ZwEdge* prevSkipBridge() const;

    ZwCircle3d circle() const;

    double angleBetweenFaces() const;

    double angleBetweenEdges() const;

    ZwPoint3d point() const;

    ZwVector3d vector() const
    { 
        return mpNext->mpVertex->point() - mpVertex->point(); 
    }

    ZwVector3d unitVector() const;

    ZwLine3d line() const;

    ZwVector3d normal() const;

    ZwVector3d vertexNormal() const;

    ZwPlane plane() const;

    ZwSurface* surface() const;

    bool isOnCircle() const;

    bool isOnFullCircle() const;

    bool isManifold() const;

    bool angleBetweenFacesIsConvex  () const;  
    bool angleBetweenFacesIsConcave () const;  
    bool angleBetweenFacesIsStraight() const;  
    bool isBridge                   () const;
    bool isApprox                   () const;

    void setApproxFlag (ZwOnOff onOff = kOn);
    void setBridgeFlag (ZwOnOff onOff = kOn);

    bool hasPartner(ZwEdge*) const;

    bool isEulerEdge() const;

    ZwEdge* eulerEdge();

    bool canMergeWithPrevious(bool sameColorOnly) const;

    void print  (FILE* = NULL)         const; 
    void save   (ZwSaveRestoreCallback* pCallBack) const;
    void restore(ZwSaveRestoreCallback* pCallBack); 
    void mergeLoopsSharingEdge  ();
    void mergeLoopsAddBridgeEdge(ZwEdge* innerEdge);

    void getAllEdgesSharingSameFaces(bool                connectedSequenceOnly, 
                                     std::vector<ZwEdge*>& sortedEdges);

    void getAllEdgesStartingFromVertex(std::vector<ZwEdge*>&);
    void getAllEdgesEndingInVertex    (std::vector<ZwEdge*>&);

    void split (ZwVertex*);
    void merge (); 
    void remove();
    union
    {
        ZwEdge*          eptr;
        ZwEdge*          nie;
        int            xmin;
        ZwIntInterval3d* ibp;
        int            n;
    };

private:

    ZwVertex*  mpVertex;
    ZwFace*    mpFace;

    ZwEdge*    mpNext;
    ZwEdge*    mpPrev;
    ZwEdge*    mpPartner;

    ZwCurve*   mpCurve;

    ZwColor    mColor;

}; 


DllImpExp extern ZwEdge* me      (ZwFace* f1, ZwFace* f2, ZwVertex* v1, ZwVertex* v2);
DllImpExp extern ZwEdge* makeEdgeLoop(const ZwCircle3d&, int type, int approx, ZwFace* f1, ZwFace* f2, ZwBody*);
DllImpExp extern ZwEdge* makeEdgeLoop(ZwVertex* [], ZwCurve* [], ZwEdge* [], int numEdges, int type, ZwFace* f1, ZwFace* f2);


AECMODELER_NAMESPACE_END


#include "zface.h"

AECMODELER_NAMESPACE_BEGIN


inline ZwEdge::ZwEdge() 
      : mpVertex(NULL),
        mpFace   (NULL), 
        mpNext   (NULL), 
        mpPrev   (NULL), 
        mpCurve  (NULL),
        mColor   (defaultColor())
{
   mpPartner = this;
   eptr = NULL;
}



inline void ZwEdge::removePartner()
{
    ZwEdge* e = this;

    do {
    } while ((e = e->partner())->partner() != this);

    e->setPartner(partner());
    setPartner(this);
}



inline void ZwEdge::addAfter(ZwEdge* prevEdge)
{
    MASSERT(prevEdge != NULL);

    setNext(prevEdge->next());
    setPrev(prevEdge);
    prevEdge->setNext(this);
    if (next() != NULL) {
        next()->setPrev(this);
    } else {
        FAIL;
    }
}



inline ZwPoint3d ZwEdge::point() const
{
    return mpVertex->point();
}



inline ZwVector3d ZwEdge::unitVector() const
{ 
    return (next()->point() - point()).normalize(); 
}



inline bool ZwEdge::isManifold() const
{
    return partner()->partner() == this && partner() != this;
}



inline ZwPlane ZwEdge::plane() const
{
    return mpFace->plane();
}



inline ZwSurface* ZwEdge::surface() const
{
    return mpFace->surface();
}



inline ZwLine3d ZwEdge::line() const
{
    return ZwLine3d(mpVertex->point(), vector());
}



inline bool ZwEdge::isBridge() const
{
    return isFlagOn(BEF);
}



inline bool ZwEdge::isApprox() const
{
    return isFlagOn(AEF);
}


AECMODELER_NAMESPACE_END
#endif
