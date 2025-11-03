/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "rxoverrule.h"

#pragma pack (push, 8)

class GCDB_PORT GcDbObjectOverrule : public GcRxOverrule
{
public:
  GCRX_DECLARE_MEMBERS(GcDbObjectOverrule);
  GcDbObjectOverrule();

  virtual Gcad::ErrorStatus open(GcDbObject* pSubject, GcDb::OpenMode mode);
  virtual Gcad::ErrorStatus close(GcDbObject* pSubject);
  virtual Gcad::ErrorStatus cancel(GcDbObject* pSubject);
  virtual Gcad::ErrorStatus erase(GcDbObject* pSubject, Gsoft::Boolean erasing);
  virtual Gcad::ErrorStatus deepClone(const GcDbObject* pSubject,
    GcDbObject* pOwnerObject,
    GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap,
    Gsoft::Boolean isPrimary = true);
  virtual Gcad::ErrorStatus wblockClone(const GcDbObject* pSubject,
    GcRxObject* pOwnerObject,
    GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap,
    Gsoft::Boolean isPrimary = true);

};

#pragma pack (pop)