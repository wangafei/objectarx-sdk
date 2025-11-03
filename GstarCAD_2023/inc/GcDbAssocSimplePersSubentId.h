/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "gcarray.h"
#include "dbsubeid.h"
#include "GcDbAssocPersSubentId.h"
#pragma pack (push, 8)

#ifndef UNREFERENCED_PARAMETER
#define UNREFERENCED_PARAMETER(P)  (P)
#endif

class DBCONSTRAINTS_PORT GcDbAssocSimplePersSubentId : public GcDbAssocPersSubentId
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocSimplePersSubentId);

  explicit GcDbAssocSimplePersSubentId(GcDbSubentId subentId = kNullSubentId) : mSubentId(subentId) {}

  int transientSubentCount(const GcDbEntity* pEntity, GcDbDatabase* pDatabase) const override {
    UNREFERENCED_PARAMETER(pEntity);
    UNREFERENCED_PARAMETER(pDatabase);
    return !isNull() ? 1 : 0;
  }

  GcDb::SubentType subentType(const GcDbEntity* pEntity, GcDbDatabase* pDatabase) const override {
    UNREFERENCED_PARAMETER(pEntity);
    UNREFERENCED_PARAMETER(pDatabase);
    return mSubentId.type();
  }

  virtual GcDbSubentId subentId(const GcDbEntity*) const { return mSubentId; }

  bool isNull() const override
  {
    return mSubentId.type() == GcDb::kNullSubentType;
  }

  bool isEqualTo(const GcDbEntity* pEntity, GcDbDatabase* pDatabase, const GcDbAssocPersSubentId* pOther) const override;

  void setSubentId(const GcDbSubentId& newSubentId) { mSubentId = newSubentId; }

  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;

  Gcad::ErrorStatus audit(GcDbAuditInfo* pAuditInfo) override;

private:
  GcDbSubentId mSubentId;
};

#pragma pack (pop)