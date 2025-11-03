/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRBSTRAV_H
#define GC_BRBSTRAV_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class GcBrBrep;
class GcBrShell;

class GCBR_PORT GcBrBrepShellTraverser : public GcBrTraverser
{
public:
  GCRX_DECLARE_MEMBERS(GcBrBrepShellTraverser);
  GcBrBrepShellTraverser();
  GcBrBrepShellTraverser(const GcBrBrepShellTraverser& src);
  ~GcBrBrepShellTraverser();

  GcBrBrepShellTraverser& operator =(const GcBrBrepShellTraverser& src);

  GcBr::ErrorStatus   setBrepAndShell(const GcBrShell& shell);
  GcBr::ErrorStatus   setBrep(const GcBrBrep& brep);
  GcBr::ErrorStatus   getBrep(GcBrBrep& brep) const;
  GcBr::ErrorStatus   setShell(const GcBrShell& shell);
  GcBr::ErrorStatus   getShell(GcBrShell& shell) const;
};

#endif
