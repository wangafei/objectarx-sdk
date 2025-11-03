/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRCPLX_H
#define GC_BRCPLX_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brent.h"

class GCBR_PORT GcBrComplex : public GcBrEntity
{
public:
  GCRX_DECLARE_MEMBERS(GcBrComplex);
  GcBrComplex();
  GcBrComplex(const GcBrComplex& src);
  ~GcBrComplex();

  GcBrComplex& operator =      (const GcBrComplex& src);
};

#endif
