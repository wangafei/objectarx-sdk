/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEPT3DAR_H
#define GC_GEPT3DAR_H

#include "gsoft.h"
#include "assert.h"
#include "gepnt3d.h"

#include "gcarray.h"
typedef GcArray<GcGePoint3d> GcGePoint3dArray;

#if GE_LOCATED_NEW
GE_DLLDATAEXIMP
GcGe::metaTypeIndex GcGeGetMetaTypeIndex(GcGePoint3dArray* pT);
#endif

#endif