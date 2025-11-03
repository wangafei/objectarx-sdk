
#ifndef ZRX_AMODELER_INC_HIDE_H
#define ZRX_AMODELER_INC_HIDE_H

#include <limits.h>
#include "transf3d.h"

#include "../../../../utils/amodeler/inc/zhide.h"

#ifndef AModeler
#define AModeler    AECModeler
#endif //#ifndef AModeler

#ifndef HideIntegerTransform
#define HideIntegerTransform    ZwHideIntegerTransform
#endif //#ifndef HideIntegerTransform

#ifndef Point3d
#define Point3d    ZwPoint3d
#endif //#ifndef Point3d

#ifndef IntPoint3d
#define IntPoint3d    ZwIntPoint3d
#endif //#ifndef IntPoint3d

#ifndef PointInPolygonLocation
#define PointInPolygonLocation    ZwPointInPolygonLocation
#endif //#ifndef PointInPolygonLocation

#ifndef pointInPolygonTest
#define pointInPolygonTest    ZwpointInPolygonTest
#endif //#ifndef pointInPolygonTest



#endif
