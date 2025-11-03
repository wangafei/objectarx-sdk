/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRELEM2D_H
#define GC_BRELEM2D_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brelem.h"

class GcGeVector3d;
class GcBrElement;
class GcBrElement2dData;

class GCBR_PORT GcBrElement2d : public GcBrElement
{
public:
  GCRX_DECLARE_MEMBERS(GcBrElement2d);
  GcBrElement2d();
  GcBrElement2d(const GcBrElement2d& src);
  ~GcBrElement2d();

  GcBrElement2d&      operator =      (const GcBrElement2d& src);

  GcBr::ErrorStatus   set(GcBrElement2dData* data);
  GcBr::ErrorStatus   get(GcBrElement2dData*& data) const;
  GcBr::ErrorStatus   getNormal(GcGeVector3d& normal) const;
};

#endif
