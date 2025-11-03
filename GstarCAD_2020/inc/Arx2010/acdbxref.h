#pragma once
#include "AdAChar.h"
#include "xgraph.h"
#include "../grx/gcdbxref.h"

#define acdbResolveCurrentXRefs gcdbResolveCurrentXRefs
#define	acdbAttachXref 	gcdbAttachXref
#define	acdbOverlayXref 	gcdbOverlayXref
#define	acdbDetachXref 	gcdbDetachXref
#define	acdbUnloadXrefs 	gcdbUnloadXrefs
#define	acdbReloadXrefs 	gcdbReloadXrefs
#define	acdbBindXrefs 	gcdbBindXrefs
#define	acdbXBindXrefs 	gcdbXBindXrefs
#define	acdbReleaseHostDwg 	gcdbReleaseHostDwg
#define	acdbGetHostDwgXrefGraph 	gcdbGetHostDwgXrefGraph

#define	AcDbXrefObjectId 	GcDbXrefObjectId
#define	GcDbXrefObjectId 	OdDbXrefObjectId
