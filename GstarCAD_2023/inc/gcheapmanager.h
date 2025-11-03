/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCHEAPMANAGER_H_
#define GCHEAPMANAGER_H_

#pragma once

#include "PAL/api/heap.h"
#include "gcbasedefs.h"

GCBASE_PORT void* gcStackHeapAlloc(size_t size, const void* pParent);
GCBASE_PORT void* gcStackHeapRealloc(void* p, size_t size);
GCBASE_PORT void gcStackHeapFree(void* p);

#pragma push_macro("new")
#undef new
#pragma push_macro("delete")
#undef delete

#pragma pack (push, 8)

class GcStackAllocator
{
public:
  virtual ~GcStackAllocator() = 0;
  static void* operator new(size_t size, void* pParent)
  {
    return gcStackHeapAlloc(size, pParent);
  }
  static void operator delete(void* p, void* pParent)
  {
    GSOFT_UNREFED_PARAM(pParent);
    return gcStackHeapFree(p);
  }

  static void deallocate(GcStackAllocator *p, void* pParent)
  {
    p->~GcStackAllocator();
    GcStackAllocator::operator delete(p, pParent);
  }

protected:
  static void operator delete(void * p)
  {
    return gcStackHeapFree(p);
  }

};

inline GcStackAllocator::~GcStackAllocator()
{
}


#pragma pack (pop)

#pragma pop_macro("delete")
#pragma pop_macro("new")

#endif 