/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCDB_OBJECTCONTEXTMANAGER_H
#define GCDB_OBJECTCONTEXTMANAGER_H

#pragma once

#include "gcdb.h"
#include "dbmain.h"
#include "GcString.h"

class GcDbObjectContextCollection;
class GcDbObjectContext;
class GcDbImpObjectContextManager;

#pragma pack (push, 8)

class GCDB_PORT GcDbObjectContextManager : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbObjectContextManager);
  GcDbObjectContextManager();
  ~GcDbObjectContextManager();

  Gcad::ErrorStatus registerContextCollection(
    const GcString&              collectionName,
    GcDbObjectContextCollection* pCollection);
  Gcad::ErrorStatus unregisterContextCollection(const GcString& collectionName);
  GcDbObjectContextCollection* const contextCollection(const GcString& collectionName) const;

private:
  GcDbImpObjectContextManager* mpImp;
  friend class GcDbContextDataSubManager;
};

#pragma pack (pop)

#endif