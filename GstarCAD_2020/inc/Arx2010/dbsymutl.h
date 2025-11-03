#pragma once

#define ACDBSYMUTIL_SERVICES_CURRENT_VERSION  ODDBSYMUTIL_SERVICES_CURRENT_VERSION

#define AcDbSymbolUtilities  GcDbSymbolUtilities
#define GcDbSymbolUtilities  OdDbSymUtil

#define AcDbSymUtilServices  GcDbSymUtilServices
#define GcDbSymUtilServices  OdDbSymUtilServices

#define acdbSymUtil  gcdbSymUtil

#include <assert.h>
#include <stddef.h>
#include "dbsymtb.h"
#include "../Ge/GeVector2d.h"
#include "../DbSymUtl.h"