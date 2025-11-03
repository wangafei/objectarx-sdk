/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_VERTSURF_H
#define GMODELER_INC_VERTSURF_H

#include "entity.h"
#include "vector3d.h"

GMODELER_NAMESPACE_BEGIN

class DllImpExp VertexSurfaceData : public Entity
{
public:
  VertexSurfaceData() : mpSurface(NULL), mpNext(NULL), mNormal(0, 0, 0) {}
  VertexSurfaceData(const Edge*);

  Surface*           surface() const { return mpSurface; }
  VertexSurfaceData* next() const { return mpNext; }
  const Vector3d&    normal() const { return mNormal; }

  void               setNext(VertexSurfaceData* pVsd) { mpNext = pVsd; }
  void               setSurface(Surface*           s) { mpSurface = s; }
  void               transform(const Transf3d&    t) { mNormal *= t; }

  void            print(FILE* = NULL)         const;
  void            save(SaveRestoreCallback*) const;
  void            restore(SaveRestoreCallback*);

private:
  Surface*           mpSurface;
  VertexSurfaceData* mpNext;
  Vector3d           mNormal;
};

GMODELER_NAMESPACE_END
#endif
