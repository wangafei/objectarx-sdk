/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BREDGE_H
#define GC_BREDGE_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "../../../inc/gegbl.h"
#include "brgbl.h"
#include "brent.h"

class GcGePoint3d;
class GcGeCurve3d;
class GcGeNurbCurve3d;
class GcBrVertex;

class GCBR_PORT GcBrEdge : public GcBrEntity
{
public:
  GCRX_DECLARE_MEMBERS(GcBrEdge);
  GcBrEdge();
  GcBrEdge(const GcBrEdge& src);
  ~GcBrEdge();

  GcBrEdge&           operator =      (const GcBrEdge& src);

  GcBr::ErrorStatus   getCurveType(GcGe::EntityId& type) const;
  GcBr::ErrorStatus   getCurve(GcGeCurve3d*& curve) const;
  GcBr::ErrorStatus   getOrientToCurve(Gsoft::Boolean& bOrientToCurve) const;

  GcBr::ErrorStatus   getVertex1(GcBrVertex& vertex) const;
  GcBr::ErrorStatus   getVertex2(GcBrVertex& vertex) const;

  GcBr::ErrorStatus   getPointRelationToEdge(const GcGePoint3d& point, GcBr::Relation& relation) const;
  GcBr::ErrorStatus   getCurveRelationToEdge(const GcGeCurve3d& curve, GcBr::Relation& relation) const;

  GcBr::ErrorStatus   getCurveAsNurb(GcGeNurbCurve3d& nurb,
                                     const double    *fitTolRequired = NULL,
                                     double          *fitTolAchieved = NULL) const;
};

#endif
