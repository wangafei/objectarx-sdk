/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRMESH_H
#define GC_BRMESH_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brment.h"

class GcBrMeshEntity;

class GCBR_PORT GcBrMesh : public GcBrMeshEntity
{
public:
  GCRX_DECLARE_MEMBERS(GcBrMesh);
  virtual ~GcBrMesh();

protected:
  GcBrMesh();
  GcBrMesh(const GcBrMesh&);
  GcBrMesh&           operator =      (const GcBrMesh&);
};

#endif
