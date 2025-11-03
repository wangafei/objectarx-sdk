#pragma once

#include "adesk.h"
#include "assert.h"
#include "dbidapps.h"
#include "acarray.h"
#include "../OdArray.h"
#include "../IdArrays.h"

#define AcDbObjectIdArray     GcDbObjectIdArray
#define GcDbObjectIdArray     OdDbObjectIdArray
typedef OdArray<OdDbObjectId> OdDbObjectIdArray;
