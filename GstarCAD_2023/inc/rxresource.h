/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _RXRESOURCE_H_
#define _RXRESOURCE_H_
#pragma once

#include "gcbasedefs.h"
#include "PAL/api/def.h"
#include "gsoft.h"
#include "pimplapi.h"
#include "GcHeapOpers.h"

class GcString;
class GcLocale;

#ifdef _GSOFT_CROSS_PLATFORM_
#define GCBASE_NON_CROSSPLATFORM GSOFT_DEPRECATED
#else
#define GCBASE_NON_CROSSPLATFORM 
#endif

#undef PAL
namespace Gssoft { namespace Gscad { namespace PAL { class GcRxResourceInstanceImp; } } }

class GcRxResourceInstance
  : public Pimpl::ApiPart<GcHeapOperators, Gssoft::Gscad::PAL::GcRxResourceInstanceImp>
{
public:
  GCBASE_PORT explicit GcRxResourceInstance(const wchar_t* path);
  GCBASE_PORT GcRxResourceInstance(const GcLocale& locale, const wchar_t* resDllName);
  GCBASE_PORT GCBASE_NON_CROSSPLATFORM GcRxResourceInstance(void* hInst);

  GCBASE_PORT GcRxResourceInstance(const GcRxResourceInstance& other);
  GCBASE_PORT ~GcRxResourceInstance();

  GcRxResourceInstance(GcRxResourceInstance&&) = delete;

  GcRxResourceInstance& operator= (GcRxResourceInstance&&) = delete;
  GcRxResourceInstance& operator= (const GcRxResourceInstance& other) = delete;

  GCBASE_PORT bool tryLoadString(Gsoft::Int32 id, GcString& out) const noexcept;
  GCBASE_PORT bool isLoaded() const noexcept;
  GCBASE_PORT bool loadDataResource(Gsoft::Int32 id, unsigned long& resourceSize, const void*& data) const noexcept;
  GCBASE_PORT void freeDataResource(const void*& data) const noexcept;

  GCBASE_PORT const static GcRxResourceInstance& empty();
};
#endif
