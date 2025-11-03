
#ifndef __DBACIS_H__
#define __DBACIS_H__

#include "acdb.h"
#include "acadstrc.h"
#include "AcArray.h"
#include "acdbport.h"

#include "../../inc/zdbacis.h"

#ifndef AcDbDwgFiler
#define AcDbDwgFiler		ZcDbDwgFiler
#endif //#ifndef AcDbDwgFiler

#ifndef AcDbDxfFiler
#define AcDbDxfFiler		ZcDbDxfFiler
#endif //#ifndef AcDbDxfFiler

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef acdbModelerSaveEntityToDwgFiler
#define acdbModelerSaveEntityToDwgFiler		zcdbModelerSaveEntityToDwgFiler
#endif //#ifndef acdbModelerSaveEntityToDwgFiler

#ifndef acdbModelerSaveEntitiesToDwgFiler
#define acdbModelerSaveEntitiesToDwgFiler		zcdbModelerSaveEntitiesToDwgFiler
#endif //#ifndef acdbModelerSaveEntitiesToDwgFiler

#ifndef acdbModelerSaveEntityToDxfFiler
#define acdbModelerSaveEntityToDxfFiler		zcdbModelerSaveEntityToDxfFiler
#endif //#ifndef acdbModelerSaveEntityToDxfFiler

#ifndef acdbModelerSaveEntitiesToDxfFiler
#define acdbModelerSaveEntitiesToDxfFiler		zcdbModelerSaveEntitiesToDxfFiler
#endif //#ifndef acdbModelerSaveEntitiesToDxfFiler

#ifndef acdbIsModelerStarted
#define acdbIsModelerStarted		zcdbIsModelerStarted
#endif //#ifndef acdbIsModelerStarted

#ifndef acdbModelerEnd
#define acdbModelerEnd		zcdbModelerEnd
#endif //#ifndef acdbModelerEnd

#ifndef acdbModelerStart
#define acdbModelerStart		zcdbModelerStart
#endif //#ifndef acdbModelerStart

#ifndef acdbRestoreAcisEntityFromDwgFiler
#define acdbRestoreAcisEntityFromDwgFiler		zcdbRestoreAcisEntityFromDwgFiler
#endif //#ifndef acdbRestoreAcisEntityFromDwgFiler

#ifndef acdbSaveAcisEntityToDwgFiler
#define acdbSaveAcisEntityToDwgFiler		zcdbSaveAcisEntityToDwgFiler
#endif //#ifndef acdbSaveAcisEntityToDwgFiler

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef ACDB_PORT
#define ACDB_PORT		ZCDB_PORT
#endif //#ifndef ACDB_PORT

#ifndef acdbGetModelerDwgVer
#define acdbGetModelerDwgVer		zcdbGetModelerDwgVer
#endif //#ifndef acdbGetModelerDwgVer

#ifndef AcDbDwgVersion
#define AcDbDwgVersion		ZcDbDwgVersion
#endif //#ifndef AcDbDwgVersion

#ifndef acdbModelerSaveEntityToDwgFiler
#define acdbModelerSaveEntityToDwgFiler		zcdbModelerSaveEntityToDwgFiler
#endif //#ifndef acdbModelerSaveEntityToDwgFiler

#ifndef acdbModelerRestoreEntityFromDwgFiler
#define acdbModelerRestoreEntityFromDwgFiler		zcdbModelerRestoreEntityFromDwgFiler
#endif //#ifndef acdbModelerRestoreEntityFromDwgFiler

#ifndef acdbModelerRestoreEntitiesFromDwgFiler
#define acdbModelerRestoreEntitiesFromDwgFiler		zcdbModelerRestoreEntitiesFromDwgFiler
#endif //#ifndef acdbModelerRestoreEntitiesFromDwgFiler

#ifndef acdbModelerRestoreEntityFromDxfFiler
#define acdbModelerRestoreEntityFromDxfFiler		zcdbModelerRestoreEntityFromDxfFiler
#endif //#ifndef acdbModelerRestoreEntityFromDxfFiler

#endif //#ifndef __DBACIS_H__
