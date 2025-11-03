#pragma once
#include "gcadstd.h"
#include "../DbXrefGraph.h"

GCED_DLL_DECL Gcad::ErrorStatus gcedGetCurDwgXrefGraph(OdDbXrefGraph&, OdBool includeGhosts = ::kFalse);
