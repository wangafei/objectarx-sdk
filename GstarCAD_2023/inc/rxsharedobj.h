/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _RXSHAREDOBJ_H_
#define _RXSHAREDOBJ_H_
#pragma once

#include "gcbasedefs.h"
#include "PAL/api/def.h"
#include "gsoft.h"
#include "pimplapi.h"
#include "GcHeapOpers.h"
#include <memory>

#undef PAL
namespace Gssoft { namespace Gscad { namespace PAL { class GcRxSharedObjImp; } } }

class GcRxSharedObject
  : public Pimpl::ApiPart<GcHeapOperators, Gssoft::Gscad::PAL::GcRxSharedObjImp>
{
private:
  GcRxSharedObject(Gssoft::Gscad::PAL::GcRxSharedObjImp* soImp);
  GcRxSharedObject(const GcRxSharedObject& from) = delete;
  GcRxSharedObject& operator=(const GcRxSharedObject& from) = delete;
  GcRxSharedObject(const wchar_t*) = delete;

public:
  GCBASE_PORT GcRxSharedObject();
  GCBASE_PORT GcRxSharedObject(void* nativeHandle);
  GCBASE_PORT ~GcRxSharedObject() = default;
  GCBASE_PORT GcRxSharedObject(GcRxSharedObject&& from) = default;
  GCBASE_PORT GcRxSharedObject& operator=(GcRxSharedObject&& from);

  GCBASE_PORT bool isLoaded() const noexcept;
  GCBASE_PORT void * getSymbol(const char *  name) const noexcept;

  static GCBASE_PORT GcRxSharedObject tryLoad(const wchar_t* path, bool autoRelease = true);
};

#endif
