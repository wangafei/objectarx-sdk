#pragma once
#include "zacarray.h"
#include "zdbsubeid.h"
#include "zAcDbAssocPersSubentId.h"
#pragma pack (push, 8)

#ifndef UNREFERENCED_PARAMETER
#define UNREFERENCED_PARAMETER(P)  (P)
#endif

class ZCDBCORE2D_PORT ZcDbAssocSimplePersSubentId : public ZcDbAssocPersSubentId
{
public:
	ZCRX_DECLARE_MEMBERS(ZcDbAssocSimplePersSubentId);

    explicit ZcDbAssocSimplePersSubentId(ZcDbSubentId subentId = kNullSubentId) : mSubentId(subentId) {}

    virtual int transientSubentCount(const ZcDbEntity* pEntity, ZcDbDatabase* pDatabase) const override {
        UNREFERENCED_PARAMETER(pEntity);
        UNREFERENCED_PARAMETER(pDatabase);
        return !isNull() ? 1 : 0;
    }

    virtual ZcDb::SubentType subentType(const ZcDbEntity* pEntity, ZcDbDatabase* pDatabase) const override {
        UNREFERENCED_PARAMETER(pEntity);
        UNREFERENCED_PARAMETER(pDatabase);
        return mSubentId.type();
    }

    virtual ZcDbSubentId subentId(const ZcDbEntity*) const { return mSubentId; }

    virtual bool isNull() const override
    {
        return mSubentId.type() == ZcDb::kNullSubentType;
    }

    virtual bool isEqualTo(const ZcDbEntity* pEntity, ZcDbDatabase* pDatabase, const ZcDbAssocPersSubentId* pOther) const override;

    void setSubentId(const ZcDbSubentId& newSubentId) { mSubentId = newSubentId; }

    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const override;

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler) override;

    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;

    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler) override;

    virtual Zcad::ErrorStatus audit(ZcDbAuditInfo* pAuditInfo) override;

private:

    ZcDbSubentId mSubentId;

};

#pragma pack (pop)
