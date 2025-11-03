#pragma once
#include <fstream>
#include "malloc.h"
#include "gchar.h"
#include "GdCharFmt.h"
#include <assert.h>

#ifdef ASSERT
#define GcFStream_Assert ASSERT
#elif defined assert
#define GcFStream_Assert assert
#else
#define GcFStream_Assert(T)
#endif

#ifdef UNICODE
inline int GcFStream_wideToMulti(const wchar_t *pSrc, int nSrcSize,
  char *pDest, int nDestSize);
inline std::locale GcFStream_curLocale();
#endif

class OdIfstream : public
#ifndef UNICODE
  std::ifstream {
#else
  std::wifstream{
#endif
  public:
  class OdIfstream() {};
  class OdIfstream(const GCHAR *pName);
#ifdef UNICODE
  void open(const wchar_t *pName);
  void open(const wchar_t *pName, ios_base::openmode nMode);
#endif
};

class OdOfstream : public
#ifndef UNICODE
  std::ofstream {
#else
  std::wofstream{
#endif
  public:
  class OdOfstream() {};
  class OdOfstream(const GCHAR *pName);
#ifdef UNICODE
  void open(const wchar_t *pName);
  void open(const wchar_t *pName, ios_base::openmode nMode);
#endif

};

#ifndef UNICODE
inline OdIfstream::OdIfstream(const GCHAR *pName) : std::ifstream(pName)
{
}
inline OdOfstream::OdOfstream(const GCHAR *pName) : std::ofstream(pName)
{
}
#else
inline OdIfstream::OdIfstream(const GCHAR *pName)
{
  this->open(pName);
}

inline OdOfstream::OdOfstream(const GCHAR *pName)
{
  this->open(pName);
}

inline std::locale GcFStream_curLocale()
{
  char buf[100];
  sprintf_s(buf, 100, ".%d", GetACP());
  return std::locale(buf, LC_CTYPE);
}

inline int GcFStream_wideToMulti(const wchar_t *pSrc, int nSrcSize,
  char *pDest, int nDestSize)
{
  return ::WideCharToMultiByte(
    CP_ACP,
#if defined(WINVER) && (WINVER >= 0x0500)

    WC_NO_BEST_FIT_CHARS,
#else
    0,
#endif
    pSrc,
    nSrcSize,
    pDest,
    nDestSize,
    NULL,
    NULL);
}

inline void OdIfstream::open(const wchar_t *pName)
{
  this->std::wifstream::open(pName);
  this->imbue(GcFStream_curLocale());
}

inline void OdIfstream::open(const wchar_t *pName, ios_base::openmode nMode)
{
  this->std::wifstream::open(pName, nMode);
  this->imbue(GcFStream_curLocale());
}

inline void OdOfstream::open(const wchar_t *pName)
{
  this->std::wofstream::open(pName);
  this->imbue(GcFStream_curLocale());
}

inline void OdOfstream::open(const wchar_t *pName, ios_base::openmode nMode)
{
  this->std::wofstream::open(pName, nMode);
  this->imbue(GcFStream_curLocale());
}

#endif