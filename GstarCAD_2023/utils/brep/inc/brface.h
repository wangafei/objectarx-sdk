/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRFACE_H
#define GC_BRFACE_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "../../../inc/gegbl.h"
#include "brgbl.h"
#include "brent.h"

class GcGeSurface;
class GcGeNurbSurface;
class GcGeExternalBoundedSurface;
class GcGeCurve3d;
class GcGePoint3d;
class GcBrShell;

class GCBR_PORT GcBrFace : public GcBrEntity
{
public:
  GCRX_DECLARE_MEMBERS(GcBrFace);
  GcBrFace();
  GcBrFace(const GcBrFace& src);
  ~GcBrFace();

  GcBrFace&           operator =(const GcBrFace& src);

  GcBr::ErrorStatus   getSurfaceType(GcGe::EntityId& type) const;
  GcBr::ErrorStatus   getSurface(GcGeSurface*& surface) const;
  GcBr::ErrorStatus   getOrientToSurface(Gsoft::Boolean& bOrientToSurface) const;
  GcBr::ErrorStatus   getArea(double&       area,
                              const double *tolRequired = NULL,
                              double       *tolAchieved = NULL) const;
  GcBr::ErrorStatus   getPointRelationToFace(const GcGePoint3d& point, GcBr::Relation& relation) const;
  GcBr::ErrorStatus   getCurveRelationToFace(const GcGeCurve3d& curve, GcBr::Relation& relation) const;
  GcBr::ErrorStatus   getSurfaceAsNurb(GcGeNurbSurface& nurb,
                                       const double    *fitTolRequired = NULL,
                                       double          *fitTolAchieved = NULL) const;
  GcBr::ErrorStatus   getSurfaceAsTrimmedNurbs(Gsoft::UInt32&                numNurbs,
                                               GcGeExternalBoundedSurface**& ppNurbs) const;
  GcBr::ErrorStatus   getShell(GcBrShell& shell) const;
};

#endif
