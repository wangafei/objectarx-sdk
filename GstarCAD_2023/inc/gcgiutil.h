/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GCGIUTIL_H
#define _GCGIUTIL_H 1

#include "dbid.h"
#include "GdGChar.h"
#include "gcgi.h"

#pragma pack (push, 8)

GCCORE_PORT Gcad::ErrorStatus fromGcDbTextStyle(GcGiTextStyle&,
  const GcDbObjectId& GcDbStyleId);
GCCORE_PORT Gcad::ErrorStatus fromGcDbTextStyle(GcGiTextStyle&, const GCHAR * GcDbStyleName);

GCCORE_PORT Gcad::ErrorStatus toGcDbTextStyle(GcGiTextStyle&);
GCCORE_PORT Gcad::ErrorStatus toGcDbTextStyle(GcGiTextStyle&,
  GcDbObjectId& GcDbStyleId);
GCCORE_PORT Gcad::ErrorStatus toGcDbTextStyle(const GcDbObjectId GcDbStyleId,
  GcGiTextStyle&);
GCCORE_PORT Gcad::ErrorStatus toGcDbTextStyle(GcGiTextStyle&, const GCHAR * GcDbStyleName);
GCCORE_PORT Gcad::ErrorStatus toGcDbTextStyle(GcGiTextStyle&, const GCHAR * GcDbStyleName,
  GcDbObjectId& GcDbStyleId);

#pragma pack (pop)

#endif 