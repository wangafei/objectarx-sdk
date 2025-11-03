/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef DB_API_DBACIS_H
#define DB_API_DBACIS_H

#include "gcdb.h"
#include "gcadstrc.h"
#include "gcarray.h"
#include "gcdbport.h"

class GcDbDatabase;
#pragma pack (push, 8)

class GcDbDwgFiler;
class GcDbDxfFiler;
class GcDbObject;
class ENTITY;

extern "C"
{
  GCCORE_PORT void gcdbModelerStart();
  GCCORE_PORT void gcdbModelerEnd();
  GCCORE_PORT Gsoft::Boolean gcdbIsModelerStarted();
}

GCCORE_PORT
int gcdbGetModelerDwgVer(GcDb::GcDbDwgVersion dwgVer,
  GcDbObject* pObj = nullptr);

GCCORE_PORT
Gcad::ErrorStatus gcdbModelerSaveEntityToDwgFiler(GcDbDwgFiler* filer,
  ENTITY*       entity,
  GcDbDatabase* pDb,
  int modelerVersion = -1);

GCCORE_PORT
Gcad::ErrorStatus gcdbModelerSaveEntitiesToDwgFiler(GcDbDwgFiler* filer,
  const GcArray<ENTITY*>& entities,
  GcDbDatabase* pDb,
  int modelerVersion = -1);

GCCORE_PORT
Gcad::ErrorStatus gcdbModelerSaveEntityToDxfFiler(GcDbDxfFiler* filer,
  ENTITY*       entity,
  GcDbDatabase* pDb,
  int modelerVersion = -1);

GCCORE_PORT
Gcad::ErrorStatus gcdbModelerSaveEntitiesToDxfFiler(GcDbDxfFiler* filer,
  const GcArray<ENTITY*>& entities,
  GcDbDatabase* pDb,
  int modelerVersion = -1);

enum ModelerRestoreOptions
{
  kReadForeignEntities = 0x01,
  kReadUnknownEntities = 0x02,
  kLoseUnknownCustomAttributes = 0x04,

  kReadStrangerEntityDefault = (kReadForeignEntities |
  kReadUnknownEntities | kLoseUnknownCustomAttributes),

  kModelerRestoreOptionsFuture1 = 0x08,
  kModelerRestoreOptionsFuture2 = 0x10,
  kModelerRestoreOptionsFuture3 = 0x20,
  kModelerRestoreOptionsFuture4 = 0x40,
};

GCCORE_PORT
Gcad::ErrorStatus gcdbModelerRestoreEntityFromDwgFiler(GcDbDwgFiler* filer,
  ENTITY*& pEntity,
  int* pModelerVersion = nullptr,
  unsigned restoreOptions = kReadStrangerEntityDefault);

GCCORE_PORT
Gcad::ErrorStatus gcdbModelerRestoreEntitiesFromDwgFiler(GcDbDwgFiler* filer,
  GcArray<ENTITY*>& entities,
  int* pModelerVersion = nullptr,
  unsigned restoreOptions = kReadStrangerEntityDefault);

GCCORE_PORT
Gcad::ErrorStatus gcdbModelerRestoreEntityFromDxfFiler(GcDbDxfFiler* filer,
  ENTITY*& pEntity,
  int* pModelerVersion = nullptr,
  unsigned restoreOptions = kReadStrangerEntityDefault);
#pragma pack (pop)
#endif