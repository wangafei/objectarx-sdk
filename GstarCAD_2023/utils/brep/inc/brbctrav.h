/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRBCTRAV_H
#define GC_BRBCTRAV_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class GcBrBrep;
class GcBrComplex;

class GCBR_PORT GcBrBrepComplexTraverser : public GcBrTraverser
{
public:
  GCRX_DECLARE_MEMBERS(GcBrBrepComplexTraverser);
  GcBrBrepComplexTraverser();
  GcBrBrepComplexTraverser(const GcBrBrepComplexTraverser& src);
  ~GcBrBrepComplexTraverser();

  GcBrBrepComplexTraverser& operator =(const GcBrBrepComplexTraverser& src);

  GcBr::ErrorStatus   setBrepAndComplex(const GcBrComplex& complex);
  GcBr::ErrorStatus   setBrep(const GcBrBrep& brep);
  GcBr::ErrorStatus   getBrep(GcBrBrep& brep) const;
  GcBr::ErrorStatus   setComplex(const GcBrComplex& complex);
  GcBr::ErrorStatus   getComplex(GcBrComplex& complex) const;
};

#endif
