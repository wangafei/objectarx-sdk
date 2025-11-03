/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gcutilgds_h
#define _gcutilgds_h 1

#include "gdsdef.h"
#include "GdGChar.h"
#include "gcdbport.h"
#include <stdarg.h>
#include "GcDbCore2dDefs.h"

#pragma pack (push, 8)

GCCORE_PORT void           gcad__assert(const GCHAR *, const GCHAR *, int);
GCCORE_PORT int            gcutCvUnit(gds_real value, const GCHAR *oldunit,
  const GCHAR *newunit, gds_real *result);
GCCORE_PORT int            gcutWcMatch(const GCHAR *string, const GCHAR *pattern);
GCCORE_PORT int            gcutPrintf(const GCHAR *format, ...);
GCCORE_PORT int            gcutSPrintf(GCHAR *buffer, size_t nBufLen, const GCHAR *format, ...);
GCBASE_PORT struct resbuf *gcutNewRb(int v);
GCBASE_PORT int            gcutRelRb(struct resbuf *rb);
GCBASE_PORT struct resbuf *gcutBuildList(int rtype, ...);
GCBASE_PORT int            gcutRbDup(const struct resbuf *source, struct resbuf **result);
GCCORE_PORT gds_real       gcutAngle(const gds_point pt1, const gds_point pt2);
GCCORE_PORT gds_real       gcutDistance(const gds_point pt1, const gds_point pt2);
GCCORE_PORT void           gcutPolar(const gds_point pt, gds_real angle,
  gds_real dist, gds_point ptres);
GCCORE_PORT int            gcutIsAlpha(int c);
GCCORE_PORT int            gcutIsUpper(int c);
GCCORE_PORT int            gcutIsLower(int c);
GCCORE_PORT int            gcutIsDigit(int c);
GCCORE_PORT int            gcutIsXDigit(int c);
GCCORE_PORT int            gcutIsSpace(int c);
GCCORE_PORT int            gcutIsPunct(int c);
GCCORE_PORT int            gcutIsAlNum(int c);
GCCORE_PORT int            gcutIsPrint(int c);
GCCORE_PORT int            gcutIsGraph(int c);
GCCORE_PORT int            gcutIsCntrl(int c);
GCCORE_PORT int            gcutToUpper(int c);
GCCORE_PORT int            gcutToLower(int c);

#pragma pack (pop)

#ifdef __cplusplus

GCCORE_PORT int gcutVSPrintf(wchar_t *buf, size_t nBufLen, const wchar_t *fmt, va_list va);

template<size_t nBufLen> inline int gcutSPrintf(wchar_t(&buf)[nBufLen], const GCHAR *format, ...)
{
  va_list va;
  va_start(va, format);
  const int nRet = ::gcutVSPrintf(buf, nBufLen, format, va);
  va_end(va);
  return nRet;
}

template<size_t nBufLen> inline int gcutVSPrintf(wchar_t(&buf)[nBufLen], const GCHAR *format,
  va_list va)
{
  return ::gcutVSPrintf(buf, nBufLen, format, va);
}

#endif

#endif 