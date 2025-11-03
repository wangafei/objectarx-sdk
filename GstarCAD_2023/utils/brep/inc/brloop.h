/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRLOOP_H
#define GC_BRLOOP_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brent.h"

class GcBrFace;

class GCBR_PORT GcBrLoop : public GcBrEntity
{
public:
  GCRX_DECLARE_MEMBERS(GcBrLoop);
  GcBrLoop();
  GcBrLoop(const GcBrLoop& src);
  ~GcBrLoop();

  GcBrLoop&           operator =      (const GcBrLoop& src);

  GcBr::ErrorStatus   getFace(GcBrFace& face) const;
  GcBr::ErrorStatus   getType(GcBr::LoopType& type) const;
};

#endif