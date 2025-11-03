/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRVETRAV_H
#define GC_BRVETRAV_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class GcBrEdge;
class GcBrVertex;

class GCBR_PORT GcBrVertexEdgeTraverser : public GcBrTraverser
{
public:
  GCRX_DECLARE_MEMBERS(GcBrVertexEdgeTraverser);
  GcBrVertexEdgeTraverser();
  GcBrVertexEdgeTraverser(const GcBrVertexEdgeTraverser& src);
  ~GcBrVertexEdgeTraverser();

  GcBrVertexEdgeTraverser& operator =(const GcBrVertexEdgeTraverser& src);

  GcBr::ErrorStatus   setVertex(const GcBrVertex& vertex);
  GcBr::ErrorStatus   getVertex(GcBrVertex& vertex) const;
  GcBr::ErrorStatus   setEdge(const GcBrEdge& edge);
  GcBr::ErrorStatus   getEdge(GcBrEdge& edge) const;
};

#endif
