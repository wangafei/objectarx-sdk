/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GCUTIL_H
#define _GCUTIL_H

#include "gcadstrc.h"

#pragma pack (push, 8)

GCCORE_PORT bool              gcutSplitString(
  size_t &      numLeftBytes,
  const GCHAR *& pRight,
  const GCHAR  * source,
  unsigned int  delimiter);
GCCORE_PORT void              gcutTrimWhiteSpace(GCHAR * pStr);
GCCORE_PORT bool              gcutWcMatchEx(
  const GCHAR * string,
  const GCHAR * pattern,
  bool         ignoreCase);
GCCORE_PORT size_t            gcutXStrLength(const GCHAR * str);
GCCORE_PORT Gcad::ErrorStatus gcutXStrNormalize(
  GCHAR *& pStr,
  bool preserveCase);

inline Gcad::ErrorStatus
gcutXStrUppercase(GCHAR *& pStr)
{
  return gcutXStrNormalize(pStr, false);
}

#pragma pack (pop)
#endif 