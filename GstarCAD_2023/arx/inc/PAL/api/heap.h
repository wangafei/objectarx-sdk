/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "../../../../inc/PAL/api/heap.h"
#include "../../adesk.h"
#include "def.h"

#define AcHeapHandle GcHeapHandle
#define acHeapCreate gcHeapCreate 
#define acHeapDestroy gcHeapDestroy
#define acHeapAlloc gcHeapAlloc
#define acTryHeapAlloc gcTryHeapAlloc
#define acHeapFree gcHeapFree
#define acHeapReAlloc gcHeapReAlloc
#define acHeapSize gcHeapSize
#define acHeapValidate gcHeapValidate
#define acAllocAligned gcAllocAligned
#define acFreeAligned gcFreeAligned
#define acMsizeAligned gcMsizeAligned