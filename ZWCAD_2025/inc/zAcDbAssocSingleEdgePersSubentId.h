
#pragma once
#include "zacarray.h"
#include "zdbsubeid.h"
#include "zAcDbAssocPersSubentId.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocSingleEdgePersSubentId : public ZcDbAssocPersSubentId
{
public:

	ZCRX_DECLARE_MEMBERS(ZcDbAssocSingleEdgePersSubentId);

    int transientSubentCount(const ZcDbEntity* pEntity, ZcDbDatabase* pDatabase) const override {
        UNREFERENCED_PARAMETER(pEntity);
        UNREFERENCED_PARAMETER(pDatabase);
        return 1;
    }

    ZcDb::SubentType subentType(const ZcDbEntity* pEntity, ZcDbDatabase* pDatabase) const override {
        UNREFERENCED_PARAMETER(pEntity);
        UNREFERENCED_PARAMETER(pDatabase);
        return ZcDb::kEdgeSubentType;
    }

    bool isNull() const override { return false; }

    bool isEqualTo(const ZcDbEntity* pEntity, ZcDbDatabase* pDatabase, const ZcDbAssocPersSubentId* pOther) const override;

};

#pragma pack (pop)

