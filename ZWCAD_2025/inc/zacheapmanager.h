#ifndef ZACHEAPMANAGER_H_
#define ZACHEAPMANAGER_H_

#pragma once

#include "PAL/api/zheap.h"
#include "zacbasedefs.h"

ZCBASE_PORT void* zcStackHeapAlloc(size_t size, const void* pParent);
ZCBASE_PORT void* zcStackHeapRealloc(void* p, size_t size);
ZCBASE_PORT void zcStackHeapFree(void* p);

#pragma push_macro("new")
#undef new
#pragma push_macro("delete")
#undef delete

#pragma pack (push, 8)

class ZcStackAllocator
{
public:
    virtual ~ZcStackAllocator() = 0;
    static void* operator new(size_t size, void* pParent)
    {
        return zcStackHeapAlloc(size, pParent);
    }
    static void operator delete(void* p, void* pParent)
    {
        ZSOFT_UNREFED_PARAM(pParent);
        return zcStackHeapFree(p);
    }

    static void deallocate(ZcStackAllocator *p, void* pParent)
    {
        p->~ZcStackAllocator();
        ZcStackAllocator::operator delete(p, pParent);
    }

protected:
    static void operator delete(void * p)
    {
        return zcStackHeapFree(p);
    }

};

inline ZcStackAllocator::~ZcStackAllocator()
{
}

#pragma pack (pop)

#pragma pop_macro("delete")
#pragma pop_macro("new")

#endif
