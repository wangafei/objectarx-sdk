#pragma once

#define AcArray  GcArray
#define GcArray  OdArray

#define AcIntArray  GcIntArray
#define GcIntArray  OdIntArray

#define AcDbIntArray  GcDbIntArray
#define GcDbIntArray  OdDbIntArray

#define AcDbIntPtrArray  GcDbIntPtrArray
#define GcDbIntPtrArray  OdDbIntPtrArray

#include "adesk.h"
#include "assert.h"

#include "acarray.h"
#include "../IntArray.h"

typedef OdArray<OdIntPtr> OdDbIntPtrArray;