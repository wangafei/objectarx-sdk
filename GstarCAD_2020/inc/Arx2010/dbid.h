#pragma once

#define AcDbObjectId  GcDbObjectId
#define GcDbObjectId  OdDbObjectId

#define AcDbHardOwnershipId  GcDbHardOwnershipId
#define GcDbHardOwnershipId  OdDbHardOwnershipId

#define AcDbSoftOwnershipId  GcDbSoftOwnershipId
#define GcDbSoftOwnershipId  OdDbSoftOwnershipId

#define AcDbHardPointerId  GcDbHardPointerId
#define GcDbHardPointerId  OdDbHardPointerId

#define AcDbSoftPointerId  GcDbSoftPointerId
#define GcDbSoftPointerId  OdDbSoftPointerId

#include "adesk.h"
#include "dbhandle.h"
#include "../DbObjectId.h"

#define ODDB_ODDBOBJECTID_DEFINED
#include "acarrayhelper.h"