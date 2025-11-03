/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_VERTEX_H
#define GMODELER_INC_VERTEX_H

#include "entity.h"
#include "point3d.h"

GMODELER_NAMESPACE_BEGIN

const Flag PICKVF = FLAG(0);
const Flag NONMANIFOLD_VF = FLAG(1);

class DllImpExp Vertex : public Entity
{
public:
  Vertex() : mpVertexSurfaceDataList(NULL), mpNext(NULL) {}
  Vertex(const Point3d&, Body*);
  ~Vertex();

  const Point3d& point() const { return mPoint; }
  Vertex*        next() const { return mpNext; }

  void           setPoint(const Point3d& p) { mPoint = p; }
  void           setNext(Vertex* v) { mpNext = v; }
  void           transform(const Transf3d&);
  void           modified();

  VertexSurfaceData* vertexSurfaceDataList() const { return mpVertexSurfaceDataList; }
  void               deleteVertexSurfaceData();
  void               setVertexSurfaceDataList(VertexSurfaceData* vsd) { mpVertexSurfaceDataList = vsd; }
  VertexSurfaceData* vertexSurfaceData(const Edge* e);

  void           print(FILE* = NULL)         const;
  void           save(SaveRestoreCallback*) const;
  void           restore(SaveRestoreCallback*, int version);

  IntPoint3d     ip;

  union
  {
    Vertex* vptr;
    int     n;
  };
  union
  {
    Edge*   eptr;
    Vertex* vptr1;
  };

private:
  Point3d            mPoint;
  VertexSurfaceData* mpVertexSurfaceDataList;
  Vertex*            mpNext;
};

inline Vertex::~Vertex()
{
  deleteVertexSurfaceData();
}

GMODELER_NAMESPACE_END
#endif
