/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRFLTRAV_H
#define GC_BRFLTRAV_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class GcBrFace;
class GcBrLoop;
class GcBrShellFaceTraverser;

class GCBR_PORT GcBrFaceLoopTraverser : public GcBrTraverser
{
public:
  GCRX_DECLARE_MEMBERS(GcBrFaceLoopTraverser);
  GcBrFaceLoopTraverser();
  GcBrFaceLoopTraverser(const GcBrFaceLoopTraverser& src);
  ~GcBrFaceLoopTraverser();

  GcBrFaceLoopTraverser& operator =   (const GcBrFaceLoopTraverser& src);

  GcBr::ErrorStatus   setFace(GcBrFace& face);
  GcBr::ErrorStatus   getFace(GcBrFace& face) const;
  GcBr::ErrorStatus   setLoop(GcBrLoop& loop);
  GcBr::ErrorStatus   getLoop(GcBrLoop& loop) const;
  GcBr::ErrorStatus   setFaceAndLoop(const GcBrLoop& loop);
  GcBr::ErrorStatus   setFace(const GcBrFace& face);
  GcBr::ErrorStatus   setLoop(const GcBrLoop& loop);
  GcBr::ErrorStatus   setFace(const GcBrShellFaceTraverser& shellFaceTrav);
};

#endif
