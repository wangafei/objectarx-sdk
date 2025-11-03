/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gc_tcslen.h"
#include "gsoft.h"
#include <cwchar>

#define Gc64Assert GcTcsLen_Assert

#ifdef  HIBYTE
#undef  HIBYTE
#endif
#define HIBYTE(w)           LOBYTE((Gsoft::UIntPtr)(w) >> 8)

#pragma warning(push)
#pragma warning(disable:4100)
inline int GcIntPtrToInt(Gsoft::LongPtr nVal, Gsoft::LongPtr nLimit = 0x1000000)
{
  Gc64Assert(nVal < nLimit);
  Gc64Assert(nVal > -nLimit);
  const int nRet = static_cast<int>(nVal);
  Gc64Assert(nRet == nVal);
  return nRet;
}

inline unsigned int GcUIntPtrToUInt(Gsoft::ULongPtr nVal, Gsoft::ULongPtr nLimit = 0x1000000)
{
  Gc64Assert(nVal < nLimit);
  const unsigned int nRet = static_cast<unsigned int>(nVal);
  Gc64Assert(nRet == nVal);
  return nRet;
}
#pragma warning(pop)

inline Gsoft::LongPtr GSOFT_STDCALL GcStrToIntPtr(const wchar_t * s)
{
#if defined(_WIN64) || defined(_GC64)
  return std::wcstoll(s, nullptr, 10);
#else
  return std::wcstol(s, nullptr, 10);
#endif
}