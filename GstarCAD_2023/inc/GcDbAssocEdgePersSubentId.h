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

class GcDbAssocEdgePersSubentId : public GcDbAssocPersSubentId
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocEdgePersSubentId, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcDbAssocEdgePersSubentId();
  DBCONSTRAINTS_PORT explicit GcDbAssocEdgePersSubentId(int vertexIdentifier1,
    int vertexIdentifier2);
  DBCONSTRAINTS_PORT explicit GcDbAssocEdgePersSubentId(int vertexIdentifier1,
    int vertexIdentifier2,
    bool isSegArcCenter,
    bool isSegMidpoint);

  DBCONSTRAINTS_PORT int transientSubentCount(const GcDbEntity* pEntity, GcDbDatabase* pDatabase) const override {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(pDatabase);
    return !isNull() ? 1 : 0;
  }

  DBCONSTRAINTS_PORT GcDb::SubentType subentType(const GcDbEntity* pEntity, GcDbDatabase* pDatabase) const override;
  DBCONSTRAINTS_PORT bool isNull() const override { return mIndex1 == 0; }
  DBCONSTRAINTS_PORT bool isEqualTo(const GcDbEntity* pEntity, GcDbDatabase* pDatabase, const GcDbAssocPersSubentId* pOther) const override;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus audit(GcDbAuditInfo* pAuditInfo) override;

  DBCONSTRAINTS_PORT int index1() const;
  DBCONSTRAINTS_PORT int index2() const;

  DBCONSTRAINTS_PORT bool isSegmentArcCenter() const;
  DBCONSTRAINTS_PORT bool isSegmentMidpoint() const;

private:
  int mIndex1;
  int mIndex2;
};

#pragma pack (pop)