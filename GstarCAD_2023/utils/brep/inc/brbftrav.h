/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRBFTRAV_H
#define GC_BRBFTRAV_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class GcBrBrep;
class GcBrFace;

class GCBR_PORT GcBrBrepFaceTraverser : public GcBrTraverser
{
public:
  GCRX_DECLARE_MEMBERS(GcBrBrepFaceTraverser);
  GcBrBrepFaceTraverser();
  GcBrBrepFaceTraverser(const GcBrBrepFaceTraverser& src);
  ~GcBrBrepFaceTraverser();

  GcBrBrepFaceTraverser& operator =   (const GcBrBrepFaceTraverser& src);

  GcBr::ErrorStatus   setBrep(GcBrBrep& brep);
  GcBr::ErrorStatus   getBrep(GcBrBrep& brep) const;
  GcBr::ErrorStatus   setFace(GcBrFace& face);
  GcBr::ErrorStatus   getFace(GcBrFace& face) const;
  GcBr::ErrorStatus   setBrepAndFace(const GcBrFace& face);
  GcBr::ErrorStatus   setBrep(const GcBrBrep& brep);
  GcBr::ErrorStatus   setFace(const GcBrFace& face);
};

#endif
