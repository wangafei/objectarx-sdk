/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEPT2DAR_H
#define GC_GEPT2DAR_H

#include "gsoft.h"
#include "assert.h"
#include "gepnt2d.h"

#include "gcarray.h"
typedef GcArray<GcGePoint2d> GcGePoint2dArray;

#if GE_LOCATED_NEW
GE_DLLDATAEXIMP
GcGe::metaTypeIndex GcGeGetMetaTypeIndex(GcGePoint2dArray* pT);
#endif

#endif