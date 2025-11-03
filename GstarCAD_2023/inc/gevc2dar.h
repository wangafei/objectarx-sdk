/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEVC2DAR_H
#define GC_GEVC2DAR_H

#include "gsoft.h"
#include "assert.h"
#include "gevec2d.h"

#include "gcarray.h"
typedef GcArray<GcGeVector2d> GcGeVector2dArray;

#if GE_LOCATED_NEW
GE_DLLDATAEXIMP
GcGe::metaTypeIndex GcGeGetMetaTypeIndex(GcGeVector2dArray* pT);
#endif

#endif