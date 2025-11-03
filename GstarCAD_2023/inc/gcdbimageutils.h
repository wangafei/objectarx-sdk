/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCDB_DBXUTIL_H
#define GCDB_DBXUTIL_H 1

#include "gcdbport.h"

GCCORE_PORT bool gcdbGetPreviewBitmapFromDwg(const GCHAR* pszDwgfilename,
  HBITMAP* pPreviewBmp,
  HPALETTE* pRetPal);

#endif 