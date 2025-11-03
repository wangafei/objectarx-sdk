#pragma once

#include "dbunderlayhost.h"

GCDB_DLL_DECL OdDbUnderlayHost* oddbGetCurrentDgnDocHost();
GCDB_DLL_DECL OdDbUnderlayHost* oddbSetCurrentDgnDocHost(OdDbUnderlayHost* pHost);

GCDB_DLL_DECL void oddbConvertRgbToHsl(const OdGeVector3d& rgb, OdGeVector3d& hsl);
GCDB_DLL_DECL void oddbConvertHslToRgb(const OdGeVector3d& hsl, OdGeVector3d& rgb);

GCDB_DLL_DECL bool oddbIsDgnToDwgInProgress();

GCDB_DLL_DECL OdDbUnderlayHost* oddbGetCurrentPdfHost();
GCDB_DLL_DECL OdDbUnderlayHost* oddbSetCurrentPdfHost(OdDbUnderlayHost* pHost);
