

#ifndef ZDB_API_DBACIS_H
#define ZDB_API_DBACIS_H

#include "zacdb.h"
#include "zacadstrc.h"
#include "zacarray.h"
#include "zacdbport.h"	

class ZcDbDatabase;

#pragma pack (push, 8)

class ZcDbDwgFiler;
class ZcDbDxfFiler;
class ZcDbObject;
class ENTITY;

extern "C"
{
	void zcdbModelerStart();
	void zcdbModelerEnd();
	ZSoft::Boolean zcdbIsModelerStarted();
}



ZCDB_PORT
int zcdbGetModelerDwgVer(ZcDb::ZcDbDwgVersion dwgVer,
						 ZcDbObject* pObj = nullptr);

ZCDB_PORT
Zcad::ErrorStatus zcdbModelerSaveEntityToDwgFiler(ZcDbDwgFiler* filer, 
												  ENTITY*       entity,
												  ZcDbDatabase* pDb,
												  int modelerVersion = -1);

ZCDB_PORT
Zcad::ErrorStatus zcdbModelerSaveEntitiesToDwgFiler(ZcDbDwgFiler* filer, 
													const ZcArray<ENTITY*>& entities,
													ZcDbDatabase* pDb,
													int modelerVersion = -1);  

ZCDB_PORT
Zcad::ErrorStatus zcdbModelerSaveEntityToDxfFiler(ZcDbDxfFiler* filer,
												ENTITY*       entity,
												ZcDbDatabase* pDb,
												int modelerVersion = -1);

ZCDB_PORT
Zcad::ErrorStatus zcdbModelerSaveEntitiesToDxfFiler(ZcDbDxfFiler* filer,
													const ZcArray<ENTITY*>& entities,
													ZcDbDatabase* pDb,
													int modelerVersion = -1); 



enum ModelerRestoreOptions
{
	kReadForeignEntities			= 0x01,
	kReadUnknownEntities			= 0x02,
	kLoseUnknownCustomAttributes	= 0x04,
	kReadStrangerEntityDefault		= (kReadForeignEntities | kReadUnknownEntities | kLoseUnknownCustomAttributes), 
	kModelerRestoreOptionsFuture1	= 0x08,
	kModelerRestoreOptionsFuture2	= 0x10,
	kModelerRestoreOptionsFuture3	= 0x20,
	kModelerRestoreOptionsFuture4	= 0x40,
};


ZCDB_PORT
	Zcad::ErrorStatus zcdbModelerRestoreEntityFromDwgFiler(ZcDbDwgFiler* filer,
	ENTITY*& pEntity,
	int* pModelerVersion = nullptr,
	unsigned restoreOptions = kReadStrangerEntityDefault);	

ZCDB_PORT
	Zcad::ErrorStatus zcdbModelerRestoreEntitiesFromDwgFiler(ZcDbDwgFiler* filer, 
	ZcArray<ENTITY*>&      entities,
	int* pModelerVersion = nullptr,
	unsigned restoreOptions = kReadStrangerEntityDefault);	

ZCDB_PORT
Zcad::ErrorStatus zcdbModelerRestoreEntityFromDxfFiler(ZcDbDxfFiler* filer, 
	ENTITY*&      ent,
	int* pModelerVersion = nullptr,
	unsigned restoreOptions = kReadStrangerEntityDefault); 

#pragma pack (pop)
#endif
