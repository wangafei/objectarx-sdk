#pragma once

#include <memory.h>
#include <stdlib.h>
#include "adesk.h"
#include "assert.h"
#include <type_traits>

#include "../OdArray.h"


#define	AcArrayMemCopyReallocator 	GcArrayMemCopyReallocator
#define	GcArrayMemCopyReallocator 	OdMemoryAllocator

#define	AcArrayObjectCopyReallocator 	GcArrayObjectCopyReallocator
#define	GcArrayObjectCopyReallocator 	OdObjectsAllocator

#define	AcArray 	GcArray
#define	GcArray 	OdArray

template<typename T, bool>
struct AllocatorSelector;

template<typename T>
struct AllocatorSelector<T, false>
{
  typedef OdObjectsAllocator<T> allocator;
};

template<typename T>
struct AllocatorSelector<T, true>
{
  typedef OdMemoryAllocator<T> allocator;
};

#include "acarrayhelper.h"