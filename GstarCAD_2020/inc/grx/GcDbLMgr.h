#pragma once

#include "gcadstd.h"
#include "../DbLayoutManager.h"

#ifndef _WIN64
// todo: remove this version when we change binary compatibility
GCDB_DLL_DECL Gcad::ErrorStatus gcdbDoSetupForLayouts(GcDbDatabase* pDatabase, unsigned int& contextHandle);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbClearSetupForLayouts(unsigned int contextHandle);
#else
GCDB_DLL_DECL Gcad::ErrorStatus gcdbDoSetupForLayouts(GcDbDatabase* pDatabase, Hccad::ULongPtr& contextHandle);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbClearSetupForLayouts(Hccad::ULongPtr contextHandle);
#endif

GCDB_DLL_DECL Gcad::ErrorStatus gcdbDeleteLayout (const GCHAR* delname, GcDbDatabase* pDb = NULL);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbRenameLayout (const GCHAR* oldname, const GCHAR* newname, GcDbDatabase* pDb = NULL);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbCopyLayout (const GCHAR* copyname, const GCHAR* newname, GcDbDatabase* pDb = NULL);
