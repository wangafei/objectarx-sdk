/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRENTRAV_H
#define GC_BRENTRAV_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "../../../inc/gegbl.h"
#include "brgbl.h"
#include "brtrav.h"

class GcGePoint2d;
class GcGeVector3d;
class GcBrElement2d;
class GcBrNode;
class GcBrMesh2dElement2dTraverser;

class GCBR_PORT GcBrElement2dNodeTraverser : public GcBrTraverser
{
public:
  GCRX_DECLARE_MEMBERS(GcBrElement2dNodeTraverser);
  GcBrElement2dNodeTraverser();
  GcBrElement2dNodeTraverser(const GcBrElement2dNodeTraverser& src);
  ~GcBrElement2dNodeTraverser();

  GcBrElement2dNodeTraverser& operator =(const GcBrElement2dNodeTraverser& src);

  GcBr::ErrorStatus   setElement(const GcBrMesh2dElement2dTraverser& mesh2dElement2dTraverser);
  GcBr::ErrorStatus   setElement(const GcBrElement2d& element);
  GcBr::ErrorStatus   getElement(GcBrElement2d& element) const;
  GcBr::ErrorStatus   setNode(const GcBrNode& node);
  GcBr::ErrorStatus   getNode(GcBrNode& node) const;
  GcBr::ErrorStatus   getSurfaceNormal(GcGeVector3d& vector) const;
  GcBr::ErrorStatus   getParamPoint(GcGePoint2d& point) const;
};

#endif
