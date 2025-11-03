/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRMETRAV_H
#define GC_BRMETRAV_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class GcBrMesh2d;
class GcBrElement2d;

class GCBR_PORT GcBrMesh2dElement2dTraverser : public GcBrTraverser
{
public:
  GCRX_DECLARE_MEMBERS(GcBrMesh2dElement2dTraverser);
  GcBrMesh2dElement2dTraverser();
  GcBrMesh2dElement2dTraverser(const GcBrMesh2dElement2dTraverser& src);
  ~GcBrMesh2dElement2dTraverser();

  GcBrMesh2dElement2dTraverser& operator =(const GcBrMesh2dElement2dTraverser& src);

  GcBr::ErrorStatus   setMeshAndElement(const GcBrElement2d& element2d);
  GcBr::ErrorStatus   setMesh(const GcBrMesh2d& mesh2d);
  GcBr::ErrorStatus   getMesh(GcBrMesh2d& mesh2d) const;
  GcBr::ErrorStatus   setElement(const GcBrElement2d& element2d);
  GcBr::ErrorStatus   getElement(GcBrElement2d& element2d) const;
};

#endif
