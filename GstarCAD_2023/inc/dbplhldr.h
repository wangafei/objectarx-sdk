/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBPLACEHOLDER_H
#define GD_DBPLACEHOLDER_H

#include "dbmain.h"

#pragma pack (push, 8)

class GCDB_PORT GcDbPlaceHolder : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbPlaceHolder);
  GcDbPlaceHolder();
  ~GcDbPlaceHolder();

  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;

protected:
  Gcad::ErrorStatus subWblockClone(GcRxObject* pOwnerObject,
    GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap,
    Gsoft::Boolean isPrimary
    = Gsoft::kTrue) const override;
};

#pragma pack (pop)

#endif