
#ifndef __DBDIMASSOC_H__
#define __DBDIMASSOC_H__

#include "dbmain.h"

#include "../../inc/zdbdimassoc.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbDimAssoc
#define AcDbDimAssoc		ZcDbDimAssoc
#endif //#ifndef AcDbDimension

#ifndef AcDb2LineAngularDimension
#define AcDb2LineAngularDimension		ZcDb2LineAngularDimension
#endif //#ifndef AcDb2LineAngularDimension

#ifndef AcDb3PointAngularDimension
#define AcDb3PointAngularDimension		ZcDb3PointAngularDimension
#endif //#ifndef AcDb3PointAngularDimension

#ifndef AcDbAlignedDimension
#define AcDbAlignedDimension		ZcDbAlignedDimension
#endif //#ifndef AcDbAlignedDimension

#ifndef AcDbArcDimension
#define AcDbArcDimension		ZcDbArcDimension
#endif //#ifndef AcDbArcDimension

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbDiametricDimension
#define AcDbDiametricDimension		ZcDbDiametricDimension
#endif //#ifndef AcDbDiametricDimension

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbDwgFiler
#define AcDbDwgFiler		ZcDbDwgFiler
#endif //#ifndef AcDbDwgFiler

#ifndef AcDbDxfFiler
#define AcDbDxfFiler		ZcDbDxfFiler
#endif //#ifndef AcDbDxfFilerv

#ifndef AcDbIdMapping
#define AcDbIdMapping		ZcDbIdMapping
#endif //#ifndef AcDbIdMapping

#ifndef AcDbFullSubentPath
#define AcDbFullSubentPath		ZcDbFullSubentPath
#endif //#ifndef AcDbFullSubentPath

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbOrdinateDimension
#define AcDbOrdinateDimension		ZcDbOrdinateDimension
#endif //#ifndef AcDbOrdinateDimension

#ifndef AcDbRadialDimension
#define AcDbRadialDimension		ZcDbRadialDimension
#endif //#ifndef AcDbRadialDimension

#ifndef AcDbRadialDimensionLarge
#define AcDbRadialDimensionLarge		ZcDbRadialDimensionLarge
#endif //#ifndef AcDbRadialDimensionLarge

#ifndef AcDbRotatedDimension
#define AcDbRotatedDimension		ZcDbRotatedDimension
#endif //#ifndef AcDbRotatedDimension

#ifndef AcDbLeader
#define AcDbLeader		ZcDbLeader
#endif //#ifndef AcDbLeader

#ifndef AcDbMLeader
#define AcDbMLeader		ZcDbMLeader
#endif //#ifndef AcDbMLeader

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef acdbPostDimAssoc
#define acdbPostDimAssoc		zcdbPostDimAssoc
#endif //#ifndef acdbPostDimAssoc

#ifndef acdbUpdateDimension
#define acdbUpdateDimension		zcdbUpdateDimension
#endif //#ifndef acdbUpdateDimension

#ifndef acdbUpdateAllDimensions
#define acdbUpdateAllDimensions		zcdbUpdateAllDimensions
#endif //#ifndef acdbUpdateAllDimensions

#ifndef acdbGetDimAssocId
#define acdbGetDimAssocId		zcdbGetDimAssocId
#endif //#ifndef acdbGetDimAssocId

#ifndef acdbGetDimAssocIds
#define acdbGetDimAssocIds		zcdbGetDimAssocIds
#endif //#ifndef acdbGetDimAssocIds

#ifndef acdbIsTransSpatial
#define acdbIsTransSpatial		zcdbIsTransSpatial
#endif //#ifndef acdbIsTransSpatial

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef AcDbPointRef
#define AcDbPointRef		ZcDbPointRef
#endif //#ifndef AcDbPointRef

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT		ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT

#ifndef acdbGetAssocAnnotationActionBody
#define acdbGetAssocAnnotationActionBody		zcdbGetAssocAnnotationActionBody
#endif //#ifndef acdbGetAssocAnnotationActionBody

#ifndef acdbGetNonAssocAnnotations
#define acdbGetNonAssocAnnotations		zcdbGetNonAssocAnnotations
#endif //#ifndef acdbGetNonAssocAnnotations

#ifndef acdbIsEntityInBlockOrXref
#define acdbIsEntityInBlockOrXref		zcdbIsEntityInBlockOrXref
#endif //#ifndef acdbIsEntityInBlockOrXref

#ifndef acdbIsAnnoMonitorOn
#define acdbIsAnnoMonitorOn		zcdbIsAnnoMonitorOn
#endif //#ifndef acdbIsAnnoMonitorOn

#ifndef acdbIsAssociativityAlertIconDisabled
#define acdbIsAssociativityAlertIconDisabled		zcdbIsAssociativityAlertIconDisabled
#endif //#ifndef acdbIsAssociativityAlertIconDisabled

#ifndef acdbDisableAssociativityAlertIcon
#define acdbDisableAssociativityAlertIcon		zcdbDisableAssociativityAlertIcon
#endif //#ifndef acdbDisableAssociativityAlertIcon

#ifndef acdbIsAssociativeAnnotation
#define acdbIsAssociativeAnnotation		zcdbIsAssociativeAnnotation
#endif //#ifndef acdbIsAssociativeAnnotation

#ifndef AcDbAnnoAlertDisabler
#define AcDbAnnoAlertDisabler		ZcDbAnnoAlertDisabler
#endif //#ifndef AcDbAnnoAlertDisabler

#ifndef AcdbGetAssociativityOverride
#define AcdbGetAssociativityOverride		zcdbGetAssociativityOverride
#endif //#ifndef AcdbGetAssociativityOverride

#ifndef acdbSetAssociativityOverride
#define acdbSetAssociativityOverride		zcdbSetAssociativityOverride
#endif //#ifndef acdbSetAssociativityOverride

#endif //#ifndef __DBDIMASSOC_H__
