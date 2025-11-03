/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRSHELL_H
#define GC_BRSHELL_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brent.h"

class GcBrComplex;

class GCBR_PORT GcBrShell : public GcBrEntity
{
public:
  GCRX_DECLARE_MEMBERS(GcBrShell);
  GcBrShell();
  GcBrShell(const GcBrShell& src);
  ~GcBrShell();

  GcBrShell&          operator =      (const GcBrShell& src);

  GcBr::ErrorStatus   getComplex(GcBrComplex& complex) const;
  GcBr::ErrorStatus   getType(GcBr::ShellType& shellType) const;
};

#endif