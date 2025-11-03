#ifndef __HEAP_H__
#define __HEAP_H__

#include <stddef.h>
#include "adesk.h"
#include "def.h"
#include "../../../../inc/PAL/api/zheap.h"

#ifndef AcHeapHandle
#define AcHeapHandle		ZcHeapHandle
#endif //#ifndef AcHeapHandle

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef ACPAL_PORT
#define ACPAL_PORT		ZCPAL_PORT
#endif //#ifndef ACPAL_PORT

#ifndef acHeapCreate
#define acHeapCreate		zcHeapCreate
#endif //#ifndef acHeapCreate

#ifndef acHeapDestroy
#define acHeapDestroy		zcHeapDestroy
#endif //#ifndef acHeapDestroy

#ifndef acHeapAlloc
#define acHeapAlloc		zcHeapAlloc
#endif //#ifndef acHeapAlloc

#ifndef acTryHeapAlloc
#define acTryHeapAlloc		zcTryHeapAlloc
#endif //#ifndef acTryHeapAlloc

#ifndef acHeapFree
#define acHeapFree		zcHeapFree
#endif //#ifndef acHeapFree

#ifndef acHeapReAlloc
#define acHeapReAlloc		zcHeapReAlloc
#endif //#ifndef acHeapReAlloc

#ifndef acHeapSize
#define acHeapSize		zcHeapSize
#endif //#ifndef acHeapSize

#ifndef acHeapValidate
#define acHeapValidate		zcHeapValidate
#endif //#ifndef acHeapValidate

#ifndef acAllocAligned
#define acAllocAligned		zcAllocAligned
#endif //#ifndef acAllocAligned

#ifndef acFreeAligned
#define acFreeAligned		zcFreeAligned
#endif //#ifndef acFreeAligned

#ifndef acMsizeAligned
#define acMsizeAligned		zcMsizeAligned
#endif //#ifndef acMsizeAligned

#endif //__HEAP_H__