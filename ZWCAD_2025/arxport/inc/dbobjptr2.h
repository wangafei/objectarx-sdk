
#ifndef __DBOBJPTR2_H__
#define __DBOBJPTR2_H__

#include "dbobjptr.h"

#include "../../inc/zdbobjptr2.h"

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT		ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef accessAcDbObjectForRead
#define accessAcDbObjectForRead		accessZcDbObjectForRead
#endif //#ifndef accessAcDbObjectForRead

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcRxClass
#define AcRxClass		ZcRxClass
#endif //#ifndef AcRxClass

#ifndef ACDB_CLASS
#define ACDB_CLASS		ZCDB_CLASS
#endif //#ifndef ACDB_CLASS

#ifndef AcDbSmartObjectPointer
#define AcDbSmartObjectPointer		ZcDbSmartObjectPointer
#endif //#ifndef AcDbSmartObjectPointer

#ifndef ReadableAcDbObject
#define ReadableAcDbObject		ReadableZcDbObject
#endif //#ifndef ReadableAcDbObject

#ifndef accessAcDbObjectForWrite
#define accessAcDbObjectForWrite		accessZcDbObjectForWrite
#endif //#ifndef accessAcDbObjectForWrite

#ifndef revertAcDbObjectFromWrite
#define revertAcDbObjectFromWrite		revertZcDbObjectFromWrite
#endif //#ifndef revertAcDbObjectFromWrite

#ifndef WritableAcDbObject
#define WritableAcDbObject		WritableZcDbObject
#endif //#ifndef WritableAcDbObject

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#endif 
