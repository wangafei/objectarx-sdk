#pragma once

#define AcDbGeoData  GcDbGeoData
#define GcDbGeoData  OdDbGeoData

#define acdbGetGeoDataObjId  gcdbGetGeoDataObjId
#define gcdbGetGeoDataObjId  oddbGetGeoDataObjId

#define acdbGetGeoDataTransform  gcdbGetGeoDataTransform
#define gcdbGetGeoDataTransform  oddbGetGeoDataTransform

#include "dbmain.h"
#include "../DbGeoData.h"
