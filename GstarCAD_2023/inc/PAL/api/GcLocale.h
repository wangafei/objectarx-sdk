/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#ifndef GCLOCALE_H
#define GCLOCALE_H

#include "PAL/api/def.h"
#include <string>
class GcLocaleImp;

class GcLocale
{
public:
  GCPAL_PORT GcLocale(const wchar_t* iso2LangName, const wchar_t* iso2CountryName);
  GCPAL_PORT ~GcLocale();
  GCPAL_PORT GcLocale(const GcLocale& locale);
  GCPAL_PORT GcLocale& operator =(const GcLocale& locale);
  GCPAL_PORT GcLocale(GcLocale&& locale);
  GCPAL_PORT GcLocale& operator =(GcLocale&& locale);
  GCPAL_PORT bool operator ==(const GcLocale& loc) const;
  GCPAL_PORT bool operator !=(const GcLocale& loc) const;

  GCPAL_PORT const wchar_t*   iso2LangName() const;
  GCPAL_PORT const wchar_t*   iso2CountryName() const;

  GCPAL_PORT bool             isValid() const;

#if defined(GC_NON_CROSS_PLATFORM_API)
  using LocaleId = int;
  GCPAL_PORT GcLocale(LocaleId lcid);
  GCPAL_PORT operator LocaleId();
#endif

private:
  friend class GcLocaleService;
  GcLocale(const GcLocaleImp* pImpLocale);

  GcLocaleImp* m_pImpGcLocale;
};
#endif