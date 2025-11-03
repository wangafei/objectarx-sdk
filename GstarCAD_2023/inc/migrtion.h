/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef DB_MIGRATION_H
#define DB_MIGRATION_H

#include "gdsmigr.h"
#include "gcutmigr.h"

#define gcdbSetCurrentVPort gcedSetCurrentVPort
#define gcdbGetCurrentSelectionSet gcedGetCurrentSelectionSet

#define gcdbCurDwg gcdbHostApplicationServices()->workingDatabase

#define  gcdbGetRGB gcedGetRGB

#define gcdbGetCurViewportObjectId gcedGetCurViewportObjectId

#define getCurDwgXrefGraph gcedGetCurDwgXrefGraph

#endif 