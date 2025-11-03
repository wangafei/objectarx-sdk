
#pragma once

#include "zac_tcslen.h"
#include "zadesk.h"

#include <cwchar>

#define Zc64Assert ZcTcsLen_Assert

#ifdef  HIBYTE
#undef HIBYTE
#endif
#define HIBYTE(w)           LOBYTE((ZSoft::UIntPtr)(w) >> 8)

#pragma warning(push)
#pragma warning(disable:4100)
inline int ZcIntPtrToInt(ZSoft::LongPtr nVal, ZSoft::LongPtr nLimit = 0x1000000)
{
    Zc64Assert(nVal < nLimit);
    Zc64Assert(nVal > -nLimit);
    const int nRet = static_cast<int>(nVal);
    Zc64Assert(nRet == nVal);
    return nRet;
}

inline unsigned int ZcUIntPtrToUInt(ZSoft::ULongPtr nVal, ZSoft::ULongPtr nLimit = 0x1000000)
{
    Zc64Assert(nVal < nLimit);
    const unsigned int nRet = static_cast<unsigned int>(nVal);
    Zc64Assert(nRet == nVal);
    return nRet;
}
#pragma warning(pop)

inline ZSoft::LongPtr  ZSOFT_STDCALL ZcStrToIntPtr(const wchar_t * s)
{
#if defined(_WIN64) || defined(_ZC64)
    return std::wcstoll(s, nullptr, 10);
#else
    return std::wcstol(s, nullptr, 10);
#endif
}
