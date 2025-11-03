#ifndef __ACDBGEOCOORDINATESYSTEM_H__
#define __ACDBGEOCOORDINATESYSTEM_H__

#include "acdb.h"
#include "AcString.h"
#include "gepnt3d.h"

#include "../../inc/zAcDbGeoCoordinateSystem.h"

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT	ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT  

#ifndef AcDbExtents2d
#define AcDbExtents2d	ZcDbExtents2d
#endif //#ifndef AcDbExtents2d

#ifndef AcGeVector2d
#define AcGeVector2d	ZcGeVector2d
#endif //#ifndef AcGeVector2d

#ifndef AcString
#define AcString	ZcString
#endif //#ifndef AcString

#ifndef Acad
#define Acad	Zcad
#endif //#ifndef Acad

#ifndef AcArray
#define AcArray	ZcArray
#endif //#ifndef AcArray

#ifndef AcDb
#define AcDb	ZcDb
#endif //#ifndef AcDb

#ifndef AcGePoint3d
#define AcGePoint3d	ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGePoint3dArray
#define AcGePoint3dArray	ZcGePoint3dArray
#endif //#ifndef AcGePoint3dArray

#ifndef AcDbGeoCoordinateSystem
#define AcDbGeoCoordinateSystem	ZcDbGeoCoordinateSystem
#endif //#ifndef AcDbGeoCoordinateSystem   

#ifndef AcDbGeoDatum
#define AcDbGeoDatum		ZcDbGeoDatum
#endif //#ifndef AcDbGeoDatum

#ifndef AcDbGeoEllipsoid
#define AcDbGeoEllipsoid		ZcDbGeoEllipsoid
#endif //#ifndef AcDbGeoEllipsoid

#ifndef AcDbGeoProjectionParameter
#define AcDbGeoProjectionParameter		ZcDbGeoProjectionParameter
#endif //#ifndef AcDbGeoProjectionParameter

#ifndef AcDbGeoCoordinateSystemCategory
#define AcDbGeoCoordinateSystemCategory		ZcDbGeoCoordinateSystemCategory
#endif //#ifndef AcDbGeoCoordinateSystemCategory

#ifndef AcDbExtents2d
#define AcDbExtents2d	ZcDbExtents2d
#endif //#ifndef AcDbExtents2d   

#ifndef AcDbGeoCoordinateSystemTransformer
#define AcDbGeoCoordinateSystemTransformer		ZcDbGeoCoordinateSystemTransformer
#endif //#ifndef AcDbGeoCoordinateSystemTransformer

#endif //#ifndef __ACDBGEOCOORDINATESYSTEM_H__
