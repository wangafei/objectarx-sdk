#pragma once
#include "gcadstd.h"
#include "../OdArray.h"
#include "../RxObject.h"
#include "../DbHostAppServices.h"
#include "../rxdlinkr.h"
#include "gcdb.h"


GCDB_DLL_DECL int gcdbHostAppMinorVersion();

GCDB_DLL_DECL Gcad::ErrorStatus gcdbSetHostApplicationServices(GcDbHostApplicationServices * pServices);
