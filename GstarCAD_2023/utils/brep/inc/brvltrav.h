/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRVLTRAV_H
#define GC_BRVLTRAV_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class GcBrLoop;
class GcBrVertex;
class GcBrLoopVertexTraverser;

class GCBR_PORT GcBrVertexLoopTraverser : public GcBrTraverser
{
public:
  GCRX_DECLARE_MEMBERS(GcBrVertexLoopTraverser);
  GcBrVertexLoopTraverser();
  GcBrVertexLoopTraverser(const GcBrVertexLoopTraverser& src);
  ~GcBrVertexLoopTraverser();

  GcBrVertexLoopTraverser& operator =(const GcBrVertexLoopTraverser& src);

  GcBr::ErrorStatus   setVertexAndLoop(const GcBrLoopVertexTraverser& LoopVertexTraverser);
  GcBr::ErrorStatus   setVertex(const GcBrVertex& vertex);
  GcBr::ErrorStatus   getVertex(GcBrVertex& vertex) const;
  GcBr::ErrorStatus   setLoop(const GcBrLoop& loop);
  GcBr::ErrorStatus   getLoop(GcBrLoop& loop) const;
};

#endif
