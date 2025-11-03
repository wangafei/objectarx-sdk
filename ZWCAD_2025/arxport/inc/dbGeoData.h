#ifndef __DBGEODATA_H__
#define  __DBGEODATA_H__

#include "AcDbCore2dDefs.h"

#include "../../inc/zdbGeoData.h"

#ifndef AcDbGeoDataReactor
#define AcDbGeoDataReactor		ZcDbGeoDataReactor
#endif //#ifndef AcDbGeoDataReactor

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbGeoData
#define AcDbGeoData		ZcDbGeoData
#endif //#ifndef AcDbGeoData

#ifndef ACDBCORE2D_DECLARE_MEMBERS
#define ACDBCORE2D_DECLARE_MEMBERS		ZCDBCORE2D_DECLARE_MEMBERS
#endif //#ifndef ACDBCORE2D_DECLARE_MEMBERS

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT		ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACDBGEODATA_VALIDATE_CS
#define ACDBGEODATA_VALIDATE_CS		ZCDBGEODATA_VALIDATE_CS
#endif //#ifndef ACDBGEODATA_VALIDATE_CS

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcGeVector2d
#define AcGeVector2d		ZcGeVector2d
#endif //#ifndef AcGeVector2d

#ifndef AcGePoint2d
#define AcGePoint2d		ZcGePoint2d
#endif //#ifndef AcGePoint2d

#ifndef AcGePoint2dArray
#define AcGePoint2dArray		ZcGePoint2dArray
#endif //#ifndef AcGePoint2dArray

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef ACDBGEODATA_GEOGRAPHICTODWG
#define ACDBGEODATA_GEOGRAPHICTODWG		ZCDBGEODATA_GEOGRAPHICTODWG
#endif //#ifndef ACDBGEODATA_GEOGRAPHICTODWG

#ifndef ACDBGEODATA_DWGTOGEOGRAPHIC
#define ACDBGEODATA_DWGTOGEOGRAPHIC		ZCDBGEODATA_DWGTOGEOGRAPHIC
#endif //#ifndef ACDBGEODATA_DWGTOGEOGRAPHIC

#ifndef AcDbDwgFiler
#define AcDbDwgFiler		ZcDbDwgFiler
#endif //#ifndef AcDbDwgFiler

#ifndef AcDbDxfFiler
#define AcDbDxfFiler		ZcDbDxfFiler
#endif //#ifndef AcDbDxfFiler

#ifndef acdbGetGeoDataObjId
#define acdbGetGeoDataObjId		zcdbGetGeoDataObjId
#endif //#ifndef acdbGetGeoDataObjId

#ifndef acdbGetGeoDataTransform
#define acdbGetGeoDataTransform		zcdbGetGeoDataTransform
#endif //#ifndef acdbGetGeoDataTransform

#ifndef acdbRegisterGeoDataReactor
#define acdbRegisterGeoDataReactor		zcdbRegisterGeoDataReactor
#endif //#ifndef acdbRegisterGeoDataReactor

#ifndef acdbRemoveGeoDataReactor
#define acdbRemoveGeoDataReactor		zcdbRemoveGeoDataReactor
#endif //#ifndef acdbRemoveGeoDataReactor

#endif	//__DBGEODATA_H__