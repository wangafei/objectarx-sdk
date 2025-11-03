/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "gcdb.h"
#include "dbmain.h"
#include "rxobject.h"
#pragma pack (push, 8)

class DBCONSTRAINTS_PORT GcDbAssocPersSubentId : public GcRxObject
{
public:

  GCRX_DECLARE_MEMBERS(GcDbAssocPersSubentId);

  GcDbAssocPersSubentId() {}
  ~GcDbAssocPersSubentId() {}

  virtual Gcad::ErrorStatus release(GcDbEntity* pEntity, GcDbDatabase* pDatabase) const;
  virtual Gcad::ErrorStatus getTransientSubentIds(const GcDbEntity*      pEntity,
    GcDbDatabase*          pDatabase,
    GcArray<GcDbSubentId>& subents) const;
  virtual GcDb::SubentType subentType(const GcDbEntity* pEntity,
    GcDbDatabase*     pDatabase) const = 0;
  virtual int transientSubentCount(const GcDbEntity* pEntity,
    GcDbDatabase*     pDatabase) const;
  virtual bool isNull() const = 0;
  virtual bool isEqualTo(const GcDbEntity*            pEntity,
    GcDbDatabase*                pDatabase,
    const GcDbAssocPersSubentId* pOther) const;
  virtual Gcad::ErrorStatus mirror(const GcDbEntity* pMirroredEntity,
    GcDbDatabase*     pDatabase);

  static Gcad::ErrorStatus
    createObjectAndDwgInFields(GcDbDatabase*           pDatabase,
      GcDbDwgFiler*           pFiler,
      GcDbAssocPersSubentId*& pCreatedPersSubentId);
  static Gcad::ErrorStatus
    createObjectAndDxfInFields(GcDbDxfFiler*           pFiler,
      GcDbAssocPersSubentId*& pCreatedPersSubentId);

  virtual Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const;
  virtual Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler);
  virtual Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const;
  virtual Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler);

  virtual Gcad::ErrorStatus audit(GcDbAuditInfo*) {
    return Gcad::eOk;
  }

  Gcad::ErrorStatus copyFrom(const GcRxObject* pSource) override;
};

#pragma pack (pop)