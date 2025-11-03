#ifndef ZACDB_DBXUTIL_H
#define ZACDB_DBXUTIL_H 1

#include "zacdbport.h"

ZCDB_PORT bool zcdbGetPreviewBitmapFromDwg(const ZTCHAR* pszDwgfilename,
    HBITMAP* pPreviewBmp,
    HPALETTE* pRetPal);

#endif
