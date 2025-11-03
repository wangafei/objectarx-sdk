#pragma once

#include "gcadstd.h"

#include "../IdArrays.h"
#include "../Gi/Gi.h"
#include "../Gi/GiDrawable.h"
#include "../Gi/GiViewport.h"
#include "../Gi/GiCommonDraw.h"
#include "../Gi/GiWorldDraw.h"
#include "../Gi/GiViewportDraw.h"
#include "../Gi/GiGeometry.h"
#include "../Gi/GiWorldGeometry.h"
#include "../Gi/GiViewportGeometry.h"
#include "../Gi/GiTextStyle.h"
#include "../Gi/GiPolyline.h"
#include "../Gi/GiRasterWrappers.h"
#include "../GiContextForDbDatabase.h"
#include "../Gi/GiClipBoundary.h"

#ifndef ODGI_EXPORT_EX
  #ifdef GCGS_EXPORTS
    #define ODGI_EXPORT_EX
  #else
    #define ODGI_EXPORT_EX ODGI_EXPORT
  #endif
#endif

#include "gcgitransient.h"

ODGI_EXPORT_EX bool gcgiIsValidClipBoundary(const GcGePoint2dArray& pts);

ODGI_EXPORT_EX Gcad::ErrorStatus gcgiGetRegenBlockRefStack(GcDbObjectIdArray& blkRefs);

