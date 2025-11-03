/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRCSTRAV_H
#define GC_BRCSTRAV_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class GcBrComplex;
class GcBrShell;
class GcBrBrepComplexTraverser;

class GCBR_PORT GcBrComplexShellTraverser : public GcBrTraverser
{
public:
  GCRX_DECLARE_MEMBERS(GcBrComplexShellTraverser);
  GcBrComplexShellTraverser();
  GcBrComplexShellTraverser(const GcBrComplexShellTraverser& src);
  ~GcBrComplexShellTraverser();

  GcBrComplexShellTraverser& operator = (const GcBrComplexShellTraverser& src);

  GcBr::ErrorStatus   setComplexAndShell(const GcBrShell& shell);
  GcBr::ErrorStatus   setComplex(const GcBrBrepComplexTraverser& brepcompshell);
  GcBr::ErrorStatus   setComplex(const GcBrComplex& complex);
  GcBr::ErrorStatus   getComplex(GcBrComplex& complex) const;
  GcBr::ErrorStatus   setShell(const GcBrShell& shell);
  GcBr::ErrorStatus   getShell(GcBrShell& shell) const;
};

#endif
