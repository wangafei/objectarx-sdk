#pragma once
#include "gcadstd.h"
#include "gcdb.h"

#pragma pack (push, 8)

class GcDbDwgFiler;
class GcDbDxfFiler;
class ENTITY;

extern "C"
{
	GCDB_DLL_DECL void gcdbModelerStart();
	GCDB_DLL_DECL void gcdbModelerEnd();
	
	GCDB_DLL_DECL OdBool gcdbIsModelerStarted();

    GCDB_DLL_DECL OdResult gcdbAcisSaveEntityToDwgFiler     (GcDbDwgFiler* filer, ENTITY* ent);
    GCDB_DLL_DECL OdResult gcdbAcisSaveEntityToDwgFiler2     (GcDbDwgFiler* filer, ENTITY* ent, GcDbDatabase* pDb);
    GCDB_DLL_DECL OdResult gcdbAcisRestoreEntityFromDwgFiler(GcDbDwgFiler* filer, ENTITY*& ent);
    GCDB_DLL_DECL OdResult gcdbAcisSaveEntityToDxfFiler     (GcDbDxfFiler* filer, ENTITY* ent);
    GCDB_DLL_DECL OdResult gcdbAcisSaveEntityToDxfFiler2     (GcDbDxfFiler* filer, ENTITY* ent, GcDbDatabase* pDb);
    GCDB_DLL_DECL OdResult gcdbAcisRestoreEntityFromDxfFiler(GcDbDxfFiler* filer, ENTITY*& ent); 

    GCDB_DLL_DECL void   gcdbAcisSetDeleteBulletins(OdBool onOff);
	
    GCDB_DLL_DECL OdBool gcdbAcisGetDeleteBulletins();

	GCDB_DLL_DECL OdBool gcdbSetAcisDwgVer(int version);

    GCDB_DLL_DECL void   gcdbAcisDeleteModelerBulletins(void);
}

#define gcdbSaveAcisEntityToDwgFiler      gcdbAcisSaveEntityToDwgFiler
#define gcdbRestoreAcisEntityFromDwgFiler gcdbAcisRestoreEntityFromDwgFiler

#pragma pack (pop)

