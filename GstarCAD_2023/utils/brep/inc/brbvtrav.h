/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRBVTRAV_H
#define GC_BRBVTRAV_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class GcBrBrep;
class GcBrVertex;

class GCBR_PORT GcBrBrepVertexTraverser : public GcBrTraverser
{
public:
  GCRX_DECLARE_MEMBERS(GcBrBrepVertexTraverser);
  GcBrBrepVertexTraverser();
  GcBrBrepVertexTraverser(const GcBrBrepVertexTraverser& src);
  ~GcBrBrepVertexTraverser();

  GcBrBrepVertexTraverser& operator = (const GcBrBrepVertexTraverser& src);

  GcBr::ErrorStatus   setBrepAndVertex(const GcBrVertex& vertex);
  GcBr::ErrorStatus   setBrep(const GcBrBrep& brep);
  GcBr::ErrorStatus   getBrep(GcBrBrep& brep) const;
  GcBr::ErrorStatus   setVertex(const GcBrVertex& vertex);
  GcBr::ErrorStatus   getVertex(GcBrVertex& vertex) const;
};

#endif
