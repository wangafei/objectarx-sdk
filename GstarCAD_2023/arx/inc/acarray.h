/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "../../inc/gcarray.h"
#include "PAL/api/c11_Annex_K.h"
#include "adesk.h"
#include "acarrayhelper.h"

#define AC_ARRAY_ASSERT GC_ARRAY_ASSERT
#define ACARRAY_GROWTH_THRESHOLD GCARRAY_GROWTH_THRESHOLD
#define AcArrayValidateParams GcArrayValidateParams
#define AcArrayMemCopyReallocator GcArrayMemCopyReallocator
#define AcArrayObjectCopyReallocator GcArrayObjectCopyReallocator
#define AcArrayItemCopierSelector GcArrayItemCopierSelector
#define AcArray GcArray
#define AcStringArray GcStringArray