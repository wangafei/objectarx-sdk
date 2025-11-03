#pragma once
#include <stddef.h>
#include "zdef.h"
#include "../../zadesk.h"

typedef void* ZcHeapHandle;
ZCPAL_PORT ZcHeapHandle zcHeapCreate(ZSoft::UInt32 flags);
ZCPAL_PORT void zcHeapDestroy(ZcHeapHandle heap);
ZCPAL_PORT void* zcHeapAlloc(ZcHeapHandle heap, size_t size);
ZCPAL_PORT void* zcTryHeapAlloc(ZcHeapHandle heap, size_t size);
ZCPAL_PORT void zcHeapFree(ZcHeapHandle heap, void* p);
ZCPAL_PORT void* zcHeapReAlloc(ZcHeapHandle heap, void* p, size_t size);
ZCPAL_PORT size_t zcHeapSize(ZcHeapHandle heap, const void* p);
ZCPAL_PORT bool zcHeapValidate(ZcHeapHandle heap, const void* p);

ZCPAL_PORT void* zcAllocAligned(size_t alignment, size_t size);
ZCPAL_PORT void zcFreeAligned(void* p);
ZCPAL_PORT size_t zcMsizeAligned(void* p, size_t alignment);
