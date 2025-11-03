/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRBREP_H
#define GC_BRBREP_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brent.h"

class GcDbEntity;
class GcDb3dSolid;
class GcDbSurface;
class GcGePoint3d;
class GcGeCurve3d;

class GCBR_PORT GcBrBrep : public GcBrEntity
{
public:
  using GcBrEntity::set;
  using GcBrEntity::get;

  GCRX_DECLARE_MEMBERS(GcBrBrep);
  GcBrBrep();
  GcBrBrep(const GcBrBrep& src);
  ~GcBrBrep();

  GcBrBrep&           operator =      (const GcBrBrep& src);

  GcBr::ErrorStatus   getPointRelationToBrep(const GcGePoint3d& point, GcBr::Relation& relation) const;
  GcBr::ErrorStatus   getCurveRelationToBrep(const GcGeCurve3d& curve, GcBr::Relation& relation) const;

  GcBr::ErrorStatus   set(const GcDbEntity& entity);
  GcBr::ErrorStatus   get(GcDb3dSolid*& pSolid) const;
  GcBr::ErrorStatus   get(GcDbSurface*& pSurface) const;
};

#endif
