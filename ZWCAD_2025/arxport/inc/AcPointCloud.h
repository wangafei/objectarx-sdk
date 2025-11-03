#ifndef __ACPOINTCLOUD_H__
#define __ACPOINTCLOUD_H__

#include "rxobject.h"
#include "AcString.h"

#include "../../inc/zAcPointCloud.h"

#ifndef AcGeMatrix3d
#define AcGeMatrix3d	ZcGeMatrix3d
#endif //#ifndef AcGeMatrix3d

#ifndef Acad
#define Acad	Zcad
#endif //#ifndef Acad

#ifndef AcDbEntity
#define AcDbEntity	ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcString
#define AcString	ZcString
#endif //#ifndef AcString

#ifndef AcGePoint3d
#define AcGePoint3d	ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcDbObjectId
#define AcDbObjectId	ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbDatabase
#define AcDbDatabase	ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcPointCloudViewFrustum
#define AcPointCloudViewFrustum	ZcPointCloudViewFrustum
#endif //#ifndef AcPointCloudViewFrustum

#ifndef AcViewFrustum
#define AcViewFrustum		ZcViewFrustum
#endif //#ifndef AcViewFrustum

#ifndef AcPcPointFloat 
#define AcPcPointFloat 		ZcPcPointFloat 
#endif //#ifndef AcPcPointFloat 

#ifndef AcPcPointDouble 
#define AcPcPointDouble 		ZcPcPointDouble 
#endif //#ifndef AcPcPointDouble

#ifndef AcPcPointAttributes
#define AcPcPointAttributes		ZcPcPointAttributes
#endif //#ifndef AcPcPointAttributes

#ifndef IAcPcDataBuffer 
#define IAcPcDataBuffer 	IZcPcDataBuffer 
#endif //#ifndef IAcPcDataBuffer   

#ifndef IAcPcPointFilter
#define IAcPcPointFilter		IZcPcPointFilter
#endif //#ifndef IAcPcPointFilter

#ifndef IAcPcPointProcessor 
#define IAcPcPointProcessor 		IZcPcPointProcessor 
#endif //#ifndef IAcPcPointProcessor 

#ifndef acdbCreatePointCloudEntity
#define acdbCreatePointCloudEntity		zcdbCreatePointCloudEntity
#endif //#ifndef acdbCreatePointCloudEntity

#ifndef acdbAttachPointCloudExEntity
#define acdbAttachPointCloudExEntity		zcdbAttachPointCloudExEntity
#endif //#ifndef acdbAttachPointCloudExEntity

#ifndef acdbAttachPointCloudEntity
#define acdbAttachPointCloudEntity	zcdbAttachPointCloudEntity
#endif //#ifndef acdbAttachPointCloudEntity   

#ifndef acdbModifyPointCloudDataView
#define acdbModifyPointCloudDataView		zcdbModifyPointCloudDataView
#endif //#ifndef acdbModifyPointCloudDataView

#ifndef acdbResetPointCloudDataView
#define acdbResetPointCloudDataView		zcdbResetPointCloudDataView
#endif //#ifndef acdbResetPointCloudDataView

#ifndef acdbProcessPointCloudData
#define acdbProcessPointCloudData		zcdbProcessPointCloudData
#endif //#ifndef acdbProcessPointCloudData

#ifndef acdbSetPointCloudFilter
#define acdbSetPointCloudFilter		zcdbSetPointCloudFilter
#endif //#ifndef acdbSetPointCloudFilter

#ifndef AcDbExtents
#define AcDbExtents		ZcDbExtents
#endif //#ifndef AcDbExtents

#ifndef ACDB_PORT
#define ACDB_PORT		ZCDB_PORT
#endif //#ifndef ACDB_PORT

#endif //#ifndef __ACPOINTCLOUD_H__
