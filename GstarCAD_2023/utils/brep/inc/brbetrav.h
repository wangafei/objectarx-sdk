/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRBETRAV_H
#define GC_BRBETRAV_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class GcBrBrep;
class GcBrEdge;

class GCBR_PORT GcBrBrepEdgeTraverser : public GcBrTraverser
{
public:
  GCRX_DECLARE_MEMBERS(GcBrBrepEdgeTraverser);
  GcBrBrepEdgeTraverser();
  GcBrBrepEdgeTraverser(const GcBrBrepEdgeTraverser& src);
  ~GcBrBrepEdgeTraverser();

  GcBrBrepEdgeTraverser& operator =   (const GcBrBrepEdgeTraverser& src);

  GcBr::ErrorStatus   setBrepAndEdge(const GcBrEdge& edge);
  GcBr::ErrorStatus   setBrep(const GcBrBrep& brep);
  GcBr::ErrorStatus   getBrep(GcBrBrep& brep) const;
  GcBr::ErrorStatus   setEdge(const GcBrEdge& edge);
  GcBr::ErrorStatus   getEdge(GcBrEdge& edge) const;
};

#endif
