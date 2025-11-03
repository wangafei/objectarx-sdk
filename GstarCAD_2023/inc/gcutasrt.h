/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GCUTASRT_H
#define _GCUTASRT_H

#include "PAL/api/def.h"
#include "GdGChar.h"
#pragma pack (push, 8)

GCPAL_PORT void gcutAssertMessage(
  const GCHAR *condition,
  const GCHAR *filename,
  int         lineNumber,
  const GCHAR *status);

#pragma pack (pop)
#endif 