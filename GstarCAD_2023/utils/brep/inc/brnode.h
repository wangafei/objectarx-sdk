/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRNODE_H
#define GC_BRNODE_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "../../../inc/gegbl.h"
#include "brgbl.h"
#include "brment.h"

class GcGePoint3d;
class GcBrMeshEntity;
class GcBrNodeData;

class GCBR_PORT GcBrNode : public GcBrMeshEntity
{
public:
  GCRX_DECLARE_MEMBERS(GcBrNode);
  GcBrNode();
  GcBrNode(const GcBrNode& src);
  ~GcBrNode();

  GcBrNode&           operator =      (const GcBrNode& src);

  GcBr::ErrorStatus   set(GcBrNodeData* nodeData);
  GcBr::ErrorStatus   get(GcBrNodeData*& nodeData) const;
  GcBr::ErrorStatus   getPoint(GcGePoint3d& point) const;
};

#endif
