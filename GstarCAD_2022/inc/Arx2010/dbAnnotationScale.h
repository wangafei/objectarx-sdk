#pragma once

#define AcDbAnnotationScale  GcDbAnnotationScale
#define GcDbAnnotationScale  OdDbAnnotationScale

#define AcDbAnnotationScaleReactor       GcDbAnnotationScaleReactor
#define GcDbAnnotationScaleReactor       OdDbAnnotationScaleReactor

#define acdbAddAnnotationScaleReactor    gcdbAddAnnotationScaleReactor
#define gcdbAddAnnotationScaleReactor    oddbAddAnnotationScaleReactor

#define acdbRemoveAnnotationScaleReactor gcdbRemoveAnnotationScaleReactor
#define gcdbRemoveAnnotationScaleReactor oddbRemoveAnnotationScaleReactor

#include "dbObjContext.h"
#include "../DbAnnotationScale.h"
#include "../DbAnnotationScaleReactor.h"