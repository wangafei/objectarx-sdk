#ifndef __ACHEAPMANAGER_H__
#define __ACHEAPMANAGER_H__

#include "PAL/api/heap.h"
#include "acbasedefs.h"

#include "../../inc/zacheapmanager.h"

#ifndef ADESK_UNREFED_PARAM
#define ADESK_UNREFED_PARAM		ZSOFT_UNREFED_PARAM
#endif //#ifndef ADESK_UNREFED_PARAM

#ifndef ACBASE_PORT
#define ACBASE_PORT	ZCBASE_PORT
#endif //#ifndef ACBASE_PORT   

#ifndef acStackHeapAlloc
#define acStackHeapAlloc	zcStackHeapAlloc
#endif //#ifndef acStackHeapAlloc   

#ifndef acStackHeapRealloc
#define acStackHeapRealloc		zcStackHeapRealloc
#endif //#ifndef acStackHeapRealloc

#ifndef acStackHeapFree
#define acStackHeapFree		zcStackHeapFree
#endif //#ifndef acStackHeapFree

#ifndef AcStackAllocator
#define AcStackAllocator		ZcStackAllocator
#endif //#ifndef AcStackAllocator

#endif //#ifndef __ACHEAPMANAGER_H__
