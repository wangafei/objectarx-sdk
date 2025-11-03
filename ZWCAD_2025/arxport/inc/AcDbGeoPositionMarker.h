#ifndef __ACDBGEOPOSITIONMARKER_H__
#define __ACDBGEOPOSITIONMARKER_H__

#include "acdbport.h"
#include "dbmain.h"
#include "rxboiler.h"
#include "gepnt3d.h"
#include "gevec3d.h"
#include "AcString.h"

#include "../../inc/zAcDbGeoPositionMarker.h"

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT	ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT  

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS	ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef AcDbEntity
#define AcDbEntity	ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcGePoint3d
#define AcGePoint3d	ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef Acad
#define Acad	Zcad
#endif //#ifndef Acad

#ifndef AcString
#define AcString	ZcString
#endif //#ifndef AcString

#ifndef AcGeVector3d
#define AcGeVector3d	ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcDbObjectId
#define AcDbObjectId	ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbGeoPositionMarker 
#define AcDbGeoPositionMarker 	ZcDbGeoPositionMarker 
#endif //#ifndef AcDbGeoPositionMarker    

#ifndef AcDbMText
#define AcDbMText		ZcDbMText
#endif //#ifndef AcDbMText

#endif //#ifndef __ACDBGEOPOSITIONMARKER_H__
