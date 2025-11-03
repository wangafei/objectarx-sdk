/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "gsoft.h"
#include "gcheapmanager.h"

class GCBASE_PORT GcHeapOperators {
public:

#undef new
#undef delete
  static void* operator new(size_t size) {
    void *p = ::gcHeapAlloc(nullptr, size);
    if (p)
      return p;
    GSOFT_UNREACHABLE;
  }

  static void* operator new[](size_t size) {
    void *p = ::gcHeapAlloc(nullptr, size);
    if (p)
      return p;
    GSOFT_UNREACHABLE;
  }

    static void* operator new(size_t size, const char *,
      int)
  {
    void * p = ::gcHeapAlloc(nullptr, size);
    if (p)
      return p;
    GSOFT_UNREACHABLE;
  }

  static void* operator new[](size_t size,
    const char *, int)
  {
    void *p = ::gcHeapAlloc(nullptr, size);
    if (p)
      return p;
    GSOFT_UNREACHABLE;
  }

    static void operator delete(void *p) {
    if (p != NULL)
      ::gcHeapFree(nullptr, p);
  }

  static void operator delete[](void *p) {
    if (p != NULL)
      ::gcHeapFree(nullptr, p);
  }

    static void operator delete(void *p, const char *,
      int)
  {
    if (p != NULL)
      ::gcHeapFree(nullptr, p);
  }

  static void operator delete[](void *p,
    const char *, int)
  {
    if (p != NULL)
      ::gcHeapFree(nullptr, p);
  }
};