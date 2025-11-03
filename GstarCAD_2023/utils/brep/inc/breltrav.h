/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRELTRAV_H
#define GC_BRELTRAV_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class GcBrLoop;
class GcBrEdge;
class GcBrLoopEdgeTraverser;
class GcBrVertexEdgeTraverser;

class GCBR_PORT GcBrEdgeLoopTraverser : public GcBrTraverser
{
public:
  GCRX_DECLARE_MEMBERS(GcBrEdgeLoopTraverser);
  GcBrEdgeLoopTraverser();
  GcBrEdgeLoopTraverser(const GcBrEdgeLoopTraverser& src);
  ~GcBrEdgeLoopTraverser();

  GcBrEdgeLoopTraverser& operator =   (const GcBrEdgeLoopTraverser& src);

  GcBr::ErrorStatus   setEdgeAndLoop(GcBrLoopEdgeTraverser& loopEdge);
  GcBr::ErrorStatus   setEdge(GcBrEdge& edge);
  GcBr::ErrorStatus   getEdge(GcBrEdge& edge) const;
  GcBr::ErrorStatus   getLoop(GcBrLoop& loop) const;
  GcBr::ErrorStatus   setEdgeAndLoop(const GcBrLoopEdgeTraverser& loopEdge);
  GcBr::ErrorStatus   setEdge(const GcBrVertexEdgeTraverser& vertexEdge);
  GcBr::ErrorStatus   setEdge(const GcBrEdge& edge);
  GcBr::ErrorStatus   setLoop(const GcBrLoop& loop);
};

#endif
