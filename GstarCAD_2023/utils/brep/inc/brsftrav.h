/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRSFTRAV_H
#define GC_BRSFTRAV_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class GcBrShell;
class GcBrFace;
class GcBrComplexShellTraverser;

class GCBR_PORT GcBrShellFaceTraverser : public GcBrTraverser
{
public:
  GCRX_DECLARE_MEMBERS(GcBrShellFaceTraverser);
  GcBrShellFaceTraverser();
  GcBrShellFaceTraverser(const GcBrShellFaceTraverser& src);
  ~GcBrShellFaceTraverser();

  GcBrShellFaceTraverser& operator =  (const GcBrShellFaceTraverser& src);

  GcBr::ErrorStatus   setShellAndFace(const GcBrFace& face);
  GcBr::ErrorStatus   setShell(const GcBrComplexShellTraverser& complexShellTraverser);
  GcBr::ErrorStatus   setShell(const GcBrShell& shell);
  GcBr::ErrorStatus   getShell(GcBrShell& shell) const;
  GcBr::ErrorStatus   setFace(const GcBrFace& face);
  GcBr::ErrorStatus   getFace(GcBrFace& face) const;
};

#endif
