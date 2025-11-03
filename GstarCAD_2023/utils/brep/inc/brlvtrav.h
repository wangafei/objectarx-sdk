/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRLVTRAV_H
#define GC_BRLVTRAV_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class GcGePoint2d;
class GcBrLoop;
class GcBrVertex;
class GcBrFaceLoopTraverser;
class GcBrVertexLoopTraverser;

class GCBR_PORT GcBrLoopVertexTraverser : public GcBrTraverser
{
public:
  GCRX_DECLARE_MEMBERS(GcBrLoopVertexTraverser);
  GcBrLoopVertexTraverser();
  GcBrLoopVertexTraverser(const GcBrLoopVertexTraverser& src);
  ~GcBrLoopVertexTraverser();

  GcBrLoopVertexTraverser& operator = (const GcBrLoopVertexTraverser& src);

  GcBr::ErrorStatus   setLoop(GcBrFaceLoopTraverser& faceLoop);
  GcBr::ErrorStatus   getLoop(GcBrLoop& loop) const;
  GcBr::ErrorStatus   getVertex(GcBrVertex& vertex) const;
  GcBr::ErrorStatus   getParamPoint(GcGePoint2d*& ppoint) const;
  GcBr::ErrorStatus   getParamPoint(GcGePoint2d& ppoint) const;
  GcBr::ErrorStatus   setLoopAndVertex(const GcBrVertexLoopTraverser& vertexLoop);
  GcBr::ErrorStatus   setLoop(const GcBrFaceLoopTraverser& faceLoop);
  GcBr::ErrorStatus   setLoop(const GcBrLoop& loop);
  GcBr::ErrorStatus   setVertex(const GcBrVertex& vertex);
};

#endif