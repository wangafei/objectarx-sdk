#pragma once

#define AcRxDbxApp                    GcRxDbxApp
#define acrxGetApp                    gcrxGetApp

#define ACDB_REGISTER_OBJECT_ENTRY_PRAGMA GCDB_REGISTER_OBJECT_ENTRY_PRAGMA
#define ACDB_REGISTER_OBJECT_ENTRY_AUTO   GCDB_REGISTER_OBJECT_ENTRY_AUTO
#define IMPLEMENT_ARX_ENTRYPOINT_CLR      IMPLEMENT_GRX_ENTRYPOINT_CLR
#define IMPLEMENT_ARX_ENTRYPOINT_STD      IMPLEMENT_GRX_ENTRYPOINT_STD
#define IMPLEMENT_ARX_ENTRYPOINT          IMPLEMENT_GRX_ENTRYPOINT

#include "rxdefs.h"
#include "rxdlinkr.h"

#define AcRxClass                    GcRxClass
#define GcRxClass                    OdRxClass
class OdRxClass;

#include "../grx/dbxEntryPoint.h"

