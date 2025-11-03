/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEVC3DAR_H
#define GC_GEVC3DAR_H

#include "gsoft.h"
#include "assert.h"
#include "gevec3d.h"

#include "gcarray.h"
typedef GcArray<GcGeVector3d> GcGeVector3dArray;

#if GE_LOCATED_NEW
GE_DLLDATAEXIMP
GcGe::metaTypeIndex GcGeGetMetaTypeIndex(GcGeVector3dArray* pT);
#endif

#endif