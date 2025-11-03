#pragma once
#include "zacarray.h"
#include "zdbsubeid.h"
#include "zAcDbAssocPersSubentId.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocEdgePersSubentId : public ZcDbAssocPersSubentId
{
public:
	ZCRX_DECLARE_MEMBERS(ZcDbAssocEdgePersSubentId);

    ZcDbAssocEdgePersSubentId();

    explicit ZcDbAssocEdgePersSubentId(int vertexIdentifier1,
                                       int vertexIdentifier2);

    explicit ZcDbAssocEdgePersSubentId(int vertexIdentifier1,
                                       int vertexIdentifier2,
                                       bool isSegArcCenter,
                                       bool isSegMidpoint);

    virtual int transientSubentCount(const ZcDbEntity* pEntity, ZcDbDatabase* pDatabase) const override {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(pDatabase);
        return !isNull() ? 1 : 0;
    }

    virtual ZcDb::SubentType subentType(const ZcDbEntity* pEntity, ZcDbDatabase* pDatabase) const override;

    virtual bool isNull() const override { return mIndex1 == 0; }

    virtual bool isEqualTo(const ZcDbEntity* pEntity, ZcDbDatabase* pDatabase, const ZcDbAssocPersSubentId* pOther) const override;

    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const override;

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler) override;

    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;

    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler) override;

    virtual Zcad::ErrorStatus audit(ZcDbAuditInfo* pAuditInfo) override;

    int index1() const;

    int index2() const;

    bool isSegmentArcCenter() const;

    bool isSegmentMidpoint () const;

private:
    int mIndex1;
    int mIndex2;

};

#pragma pack (pop)
