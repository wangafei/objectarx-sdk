/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRVTX_H
#define GC_BRVTX_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brent.h"

class GcGePoint3d;
class GcGeCurve3d;

class GCBR_PORT GcBrVertex : public GcBrEntity
{
public:
  GCRX_DECLARE_MEMBERS(GcBrVertex);
  GcBrVertex();
  GcBrVertex(const GcBrVertex& src);
  ~GcBrVertex();

  GcBrVertex&         operator =(const GcBrVertex& src);

  GcBr::ErrorStatus   getPoint(GcGePoint3d*& point) const;
  GcBr::ErrorStatus   getPointRelationToVertex(const GcGePoint3d& point, GcBr::Relation& relation) const;
  GcBr::ErrorStatus   getCurveRelationToVertex(const GcGeCurve3d& curve, GcBr::Relation& relation) const;
  GcBr::ErrorStatus   getPoint(GcGePoint3d& point) const;
};

#endif
