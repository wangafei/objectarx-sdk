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

class DBCONSTRAINTS_PORT GcDbAssocSingleEdgePersSubentId : public GcDbAssocPersSubentId
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocSingleEdgePersSubentId);

  int transientSubentCount(const GcDbEntity* pEntity, GcDbDatabase* pDatabase) const override {
    UNREFERENCED_PARAMETER(pEntity);
    UNREFERENCED_PARAMETER(pDatabase);
    return 1;
  }

  GcDb::SubentType subentType(const GcDbEntity* pEntity, GcDbDatabase* pDatabase) const override {
    UNREFERENCED_PARAMETER(pEntity);
    UNREFERENCED_PARAMETER(pDatabase);
    return GcDb::kEdgeSubentType;
  }

  bool isNull() const override { return false; }
  bool isEqualTo(const GcDbEntity* pEntity, GcDbDatabase* pDatabase, const GcDbAssocPersSubentId* pOther) const override;
};

#pragma pack (pop)