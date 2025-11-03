
#ifndef _ZRXSHAREDOBJ_H_
#define _ZRXSHAREDOBJ_H_
#pragma once

#include "zacbasedefs.h"
#include "PAL/api/zdef.h"
#include "zadesk.h"
#include "zpimplapi.h"
#include "zAcHeapOpers.h"
#include <memory>

#undef PAL
namespace ZwSoft { namespace ZwCAD {namespace PAL { class ZcRxSharedObjImp; } } }

class ZCBASE_PORT ZcRxSharedObject
    : public Pimpl::ApiPart<AcHeapOperators, ZwSoft::ZwCAD::PAL::ZcRxSharedObjImp>
{
private:
    ZcRxSharedObject(ZwSoft::ZwCAD::PAL::ZcRxSharedObjImp* soImp);

    ZcRxSharedObject(const ZcRxSharedObject& from) = delete;
    ZcRxSharedObject& operator=(const ZcRxSharedObject& from) = delete;
    ZcRxSharedObject(const wchar_t*) = delete;
public:
    ZcRxSharedObject();
    ZcRxSharedObject(void* nativeHandle);
    ~ZcRxSharedObject() = default;
    ZcRxSharedObject(ZcRxSharedObject&& from) = default;
    ZcRxSharedObject& operator=(ZcRxSharedObject&& from);

    bool isLoaded() const noexcept;
    void * getSymbol(const char * /*ascii*/ name) const noexcept;

    static ZcRxSharedObject tryLoad(const wchar_t* path, bool autoRelease = true);    
};

#endif