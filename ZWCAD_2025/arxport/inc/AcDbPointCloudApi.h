#ifndef __ACDBPOINTCLOUDAPI_H__
#define __ACDBPOINTCLOUDAPI_H__

#include "gepnt3d.h"
#include "gevec3d.h"

#include "../../inc/zAcDbPointCloudApi.h"

#ifndef IAcDbPointCloudSpatialFilter
#define IAcDbPointCloudSpatialFilter	IZcDbPointCloudSpatialFilter
#endif //#ifndef IAcDbPointCloudSpatialFilter

#ifndef IAcDbPointCloudAttributeFilter
#define IAcDbPointCloudAttributeFilter	IZcDbPointCloudAttributeFilter
#endif //#ifndef IAcDbPointCloudAttributeFilter

#ifndef Adesk
#define Adesk	ZSoft
#endif //#ifndef Adesk

#ifndef AcGePoint3d
#define AcGePoint3d	ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGeVector3d
#define AcGeVector3d	ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcGeMatrix3d
#define AcGeMatrix3d	ZcGeMatrix3d
#endif //#ifndef AcGeMatrix3d

#ifndef IAcDbPointCloudDataBuffer
#define IAcDbPointCloudDataBuffer	IZcDbPointCloudDataBuffer
#endif //#ifndef IAcDbPointCloudDataBuffer   

#ifndef IAcDbPointCloudPointProcessor
#define IAcDbPointCloudPointProcessor		IZcDbPointCloudPointProcessor
#endif //#ifndef IAcDbPointCloudPointProcessor

#endif //#ifndef __ACDBPOINTCLOUDAPI_H__
