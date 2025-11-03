/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#pragma pack(push, 8)

#include "dbmain.h"

class GCDB_PORT GcDbObjectContext : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbObjectContext);
  GcDbObjectContext();
  ~GcDbObjectContext();

  virtual Gcad::ErrorStatus getName(GcString& name) const = 0;
  virtual Gcad::ErrorStatus setName(const GcString& name) = 0;
  virtual Gsoft::LongPtr uniqueIdentifier() const = 0;
  virtual GcString collectionName() const = 0;
};

#pragma pack(pop)