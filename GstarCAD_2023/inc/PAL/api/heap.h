/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include <stddef.h>
#include "gsoft.h"
#include "PAL/api/def.h"

typedef void* GcHeapHandle;
GCPAL_PORT GcHeapHandle gcHeapCreate(Gsoft::UInt32 flags);
GCPAL_PORT void gcHeapDestroy(GcHeapHandle heap);
GCPAL_PORT void* gcHeapAlloc(GcHeapHandle heap, size_t size);
GCPAL_PORT void* gcTryHeapAlloc(GcHeapHandle heap, size_t size);
GCPAL_PORT void gcHeapFree(GcHeapHandle heap, void* p);
GCPAL_PORT void* gcHeapReAlloc(GcHeapHandle heap, void* p, size_t size);
GCPAL_PORT size_t gcHeapSize(GcHeapHandle heap, const void* p);
GCPAL_PORT bool gcHeapValidate(GcHeapHandle heap, const void* p);

GCPAL_PORT void* gcAllocAligned(size_t alignment, size_t size);
GCPAL_PORT void gcFreeAligned(void* p);
GCPAL_PORT size_t gcMsizeAligned(void* p, size_t alignment);