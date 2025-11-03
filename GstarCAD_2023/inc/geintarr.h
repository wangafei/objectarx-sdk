/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEINTARR_H
#define GC_GEINTARR_H

#ifndef unix
#include <stdlib.h>
#endif
#include "gsoft.h"
#include "assert.h"

#include "gcarray.h"
typedef GcArray<int> GcGeIntArray;
typedef GcArray<Gsoft::IntPtr> GcGeIntPtrArray;

#if GE_LOCATED_NEW
GE_DLLDATAEXIMP
GcGe::metaTypeIndex GcGeGetMetaTypeIndex(GcGeIntArray* pT);
#endif
#endif