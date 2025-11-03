/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRELEM_H
#define GC_BRELEM_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brment.h"

class GcBrMeshEntity;

class GCBR_PORT GcBrElement : public GcBrMeshEntity
{
public:
  GCRX_DECLARE_MEMBERS(GcBrElement);
  virtual ~GcBrElement();
protected:
  GcBrElement();
  GcBrElement(const GcBrElement& src);
  GcBrElement& operator =      (const GcBrElement& src);
};

#endif
