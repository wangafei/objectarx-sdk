/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBDICTDFLT_H
#define GD_DBDICTDFLT_H

#include "dbdict.h"

#pragma pack(push, 8)

class GcDbImpDictionaryWithDefault;

class GCDB_PORT GcDbDictionaryWithDefault : public GcDbDictionary
{
public:
  GCDB_DECLARE_MEMBERS(GcDbDictionaryWithDefault);
  GcDbDictionaryWithDefault();
  ~GcDbDictionaryWithDefault();

  Gcad::ErrorStatus setDefaultId(const GcDbObjectId& newId);
  GcDbObjectId defaultId() const;

  virtual Gcad::ErrorStatus getObjectBirthVersion(GcDb::GcDbDwgVersion& ver,
    GcDb::MaintenanceReleaseVersion& maintVer);
};

#pragma pack(pop)

#endif