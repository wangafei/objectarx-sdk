/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_EDGE_H
#define GMODELER_INC_EDGE_H


#pragma warning(push)
#pragma warning(disable : 4702) 
#include <vector>
#pragma warning(pop)
#include "entity.h"
#include "color.h"
#include "circle3d.h"
#include "vertex.h"

GMODELER_NAMESPACE_BEGIN

const Flag AEF = FLAG(0);
const Flag BEF = FLAG(1);
const Flag PICKEF = FLAG(2);

class DllImpExp Edge : public Entity
{
public:
  Edge();
  Edge(Vertex*, Face* face, Edge* prevEdge, Edge* partner, Curve* = NULL);

  Vertex* vertex() const { return mpVertex; }
  Face*   face() const { return mpFace; }
  Edge*   next() const { return mpNext; }
  Edge*   prev() const { return mpPrev; }
  Edge*   partner() const { return mpPartner; }
  Curve*  curve() const { return mpCurve; }
  Color   color() const { return mColor; }

  void    setVertex(Vertex* v) { mpVertex = v; }
  void    setFace(Face*   f) { mpFace = f; }
  void    setNext(Edge*   e) { mpNext = e; }
  void    setPrev(Edge*   e) { mpPrev = e; }
  void    setPartner(Edge* par) { mpPartner = par; }

  void    setCurve(Curve*, bool partnersAlso = false);
  void    setColor(Color, bool partnersAlso = false);

  void    addPartner(Edge*);
  void    removePartner();

  void orderPartnerEdgesAroundEulerEdge();

  void collapse();

  void    addAfter(Edge* prevEdge);

  Edge*   getPartnerBridgeEdge() const;
  Edge*   nextSkipBridge() const;
  Edge*   prevSkipBridge() const;

  Circle3d circle() const;

  double angleBetweenFaces() const;
  double angleBetweenEdges() const;

  Point3d point() const;

  Vector3d vector() const
  {
    return mpNext->mpVertex->point() - mpVertex->point();
  }

  Vector3d unitVector() const;

  Line3d line() const;

  Vector3d normal() const;

  Vector3d vertexNormal() const;

  Plane plane() const;

  Surface* surface() const;

  bool isOnCircle() const;
  bool isOnFullCircle() const;
  bool isManifold() const;

  bool angleBetweenFacesIsConvex() const;
  bool angleBetweenFacesIsConcave() const;
  bool angleBetweenFacesIsStraight() const;
  bool isBridge() const;
  bool isApprox() const;

  void setApproxFlag(OnOff = kOn);
  void setBridgeFlag(OnOff = kOn);

  bool hasPartner(Edge*) const;

  bool isEulerEdge() const;

  Edge* eulerEdge();

  bool canMergeWithPrevious(bool sameColorOnly) const;

  void print(FILE* = NULL)         const;
  void save(SaveRestoreCallback*) const;
  void restore(SaveRestoreCallback*);

  void mergeLoopsSharingEdge();
  void mergeLoopsAddBridgeEdge(Edge* innerEdge);

  void getAllEdgesSharingSameFaces(bool                connectedSequenceOnly,
                                   std::vector<Edge*>& sortedEdges);

  void getAllEdgesStartingFromVertex(std::vector<Edge*>&);
  void getAllEdgesEndingInVertex(std::vector<Edge*>&);

  void split(Vertex*);
  void merge();
  void remove();

  union
  {
    Edge*          eptr;
    Edge*          nie;
    int            xmin;
    IntInterval3d* ibp;
    int            n;
  };

private:
  Vertex*  mpVertex;
  Face*    mpFace;
  Edge*    mpNext;
  Edge*    mpPrev;
  Edge*    mpPartner;
  Curve*   mpCurve;
  Color    mColor;
};

DllImpExp extern Edge* me(Face* f1, Face* f2, Vertex* v1, Vertex* v2);
DllImpExp extern Edge* makeEdgeLoop(const Circle3d&, int type, int approx, Face* f1, Face* f2, Body*);
DllImpExp extern Edge* makeEdgeLoop(Vertex*[], Curve*[], Edge*[], int numEdges, int type, Face* f1, Face* f2);

GMODELER_NAMESPACE_END

#include "face.h"

GMODELER_NAMESPACE_BEGIN

inline Edge::Edge()
  : mpVertex(NULL),
    mpFace(NULL),
    mpNext(NULL),
    mpPrev(NULL),
    mpCurve(NULL),
    mColor(defaultColor())
{
  mpPartner = this;
}

inline void Edge::removePartner()
{
  Edge* e = this;
  do
  {
  } while ((e = e->partner())->partner() != this);

  e->setPartner(partner());
  setPartner(this);
}

inline void Edge::addAfter(Edge* prevEdge)
{
  MASSERT(prevEdge != NULL);

  setNext(prevEdge->next());
  setPrev(prevEdge);
  prevEdge->setNext(this);
  if (next() != NULL)
  {
    next()->setPrev(this);
  }
  else
  {
    FAIL;
  }
}

inline Point3d Edge::point() const
{
  return mpVertex->point();
}

inline Vector3d Edge::unitVector() const
{
  return (next()->point() - point()).normalize();
}

inline bool Edge::isManifold() const
{
  return partner()->partner() == this && partner() != this;
}

inline Plane Edge::plane() const
{
  return mpFace->plane();
}

inline Surface* Edge::surface() const
{
  return mpFace->surface();
}

inline Line3d Edge::line() const
{
  return Line3d(mpVertex->point(), vector());
}

inline bool Edge::isBridge() const
{
  return isFlagOn(BEF);
}

inline bool Edge::isApprox() const
{
  return isFlagOn(AEF);
}

GMODELER_NAMESPACE_END
#endif
