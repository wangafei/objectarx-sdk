/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_FACE_H
#define GMODELER_INC_FACE_H

#include "body.h"
#include "plane.h"
#include "enums.h"

GMODELER_NAMESPACE_BEGIN

const Flag FFF      = FLAG(0);
const Flag CONVEXFF = FLAG(1);

class DllImpExp Face : public Entity
{
public:
  Face();
  Face(Body*);
  Face(Surface*, Body*);
  Face(Edge*, Surface*, Body*);
  Face(const Face&);
  ~Face();
  Face(const Circle3d&, int type, int approx, Body*);
  Face(const Point3d      plg[],
       PolygonVertexData* vertexData[],
       int                numVertices,
       const Vector3d&    plgNormal,
       int                type,
       bool               checkPlanarity,
       Body*);
  Face(Point3d            p[],
       int                numEdges,
       int                type,
       bool               checkPlanarity,
       Body*,
       Edge**             createdEdges = NULL);
  Face(Vertex*            vertices[],
       Curve*             curves[],
       Edge*              partners[],
       int                numEdges,
       int                type,
       bool               checkPlanarity,
       Body*,
       Edge**             createdEdges = NULL);

  void     modified();

  int      edgeCount() const;
  Edge*    edge(int edgeIndexInFace) const;

  Edge*    edgeLoop() const { return mpEdgeLoop; }
  Surface* surface() const { return mpSurface; }
  Face*    next() const { return mpNext; }
  Face*    prev() const { return mpPrev; }
  Color    color() const { return mColor; }
  void*    attrib() const { return mpAttrib; }

  void     setEdgeLoop(Edge*       e) { mpEdgeLoop = e; }
  void     setSurface(Surface*    s) { mpSurface = s; }
  void     setNext(Face*       f) { mpNext = f; }
  void     setPrev(Face*       f) { mpPrev = f; }

  void     setColor(Color, bool edgesAlso = false, bool partnerEdgesAlso = false);
  void     setAttrib(void* a) { mpAttrib = a; }

  void     addEdge(Edge*, Edge* prevEdge = NULL);
  void     removeEdge(Edge*);
  void     deleteAllEdges();

  void     negate();

  void     paint(const Body&, Color, bool dae = false, bool dbe = false);

  void     massProperties(const Body&,
                          bool     dae,
                          bool     dbe,
                          double&  perimeter,
                          double&  area,
                          Point3d& centroid) const;

  double   area() const;

  void     triangulate(OutputTriangleCallback*, TriangulationType = kGenerateTriangles) const;

  void  lift(const Transf3d&, bool checkPlanarity, Body* owningBody);

  void extractAllLoops(std::vector<std::vector<Edge*> >& loops) const;

  Face* split(Edge* e1, Edge* e2, Body*);

  void insertHoles(const std::vector<Face*>& holeFaces,
                   Body*                     pBody,
                   std::vector<Face*>&       faces);

  void decomposeIntoContiguousFaces(Body* pBody, std::vector<Face*>& contiguousFaces);

  const Plane&         plane() const;
  const Interval3d&    interval() const;
  const IntInterval3d& projInterval() const;

  void deletePlane() const;
  void deleteInterval() const;
  void deleteProjInterval() const;

  void setProjInterval(const IntInterval3d&) const;

  bool isPointInside(const Point3d&)   const;
  bool isPlanar(double eps = epsAbs()) const;
  bool isSelfIntersecting()            const;

  void print(FILE* = NULL)          const;
  void save(SaveRestoreCallback*)  const;
  void restore(SaveRestoreCallback*, int version);

  union
  {
    Edge* iel;
    Face* fptr;
    int   n;
  };

private:
  Edge*          mpEdgeLoop;
  Surface*       mpSurface;

  Face*          mpNext;
  Face*          mpPrev;

  Plane*         mpPlane;
  Interval3d*    mpInterval;
  IntInterval3d* mpProjInterval;

  Color          mColor;
  void*          mpAttrib;

  double evaluatePlane() const;
  void   evaluateInterval() const;
};

GMODELER_NAMESPACE_END

#include "edge.h"

GMODELER_NAMESPACE_BEGIN

inline const Plane& Face::plane() const
{
  if (mpPlane == NULL)
    evaluatePlane();

  MASSERT(mpPlane->isValid());

  return *mpPlane;
}

inline const Interval3d& Face::interval() const
{
  if (mpInterval == NULL)
    evaluateInterval();

  return *mpInterval;
}

inline const IntInterval3d& Face::projInterval() const
{
  MASSERT(mpProjInterval != NULL);
  return *mpProjInterval;
}

inline void Face::addEdge(Edge* e, Edge* prevEdge)
{
  if (e == NULL)
  {
    FAIL;
    return;
  }

  MASSERT(e->next() == NULL && e->prev() == NULL && e->face() == NULL);

  if (prevEdge == NULL)
    prevEdge = edgeLoop();

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

inline void Face::removeEdge(Edge* e)
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

GMODELER_NAMESPACE_END
#endif
