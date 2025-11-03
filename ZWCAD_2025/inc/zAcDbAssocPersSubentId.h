
#pragma once
#include "zacdb.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocPersSubentId : public ZcRxObject
{
public:

    ZCRX_DECLARE_MEMBERS(ZcDbAssocPersSubentId);

    ZcDbAssocPersSubentId() {}

    ~ZcDbAssocPersSubentId() {}

    virtual Zcad::ErrorStatus release(ZcDbEntity* pEntity, ZcDbDatabase* pDatabase) const;

    virtual Zcad::ErrorStatus getTransientSubentIds(const ZcDbEntity*      pEntity,
                                                    ZcDbDatabase*          pDatabase,
                                                    ZcArray<ZcDbSubentId>& subents) const;

    virtual ZcDb::SubentType subentType(const ZcDbEntity* pEntity,
                                        ZcDbDatabase*     pDatabase) const = 0;

    virtual int transientSubentCount(const ZcDbEntity* pEntity,
                                     ZcDbDatabase*     pDatabase) const;

    virtual bool isNull() const = 0;

    virtual bool isEqualTo(const ZcDbEntity*            pEntity,
                           ZcDbDatabase*                pDatabase,
                           const ZcDbAssocPersSubentId* pOther) const;

    virtual Zcad::ErrorStatus mirror(const ZcDbEntity* pMirroredEntity,
                                     ZcDbDatabase*     pDatabase);

    static Zcad::ErrorStatus
    createObjectAndDwgInFields(ZcDbDatabase*           pDatabase,
                               ZcDbDwgFiler*           pFiler,
                               ZcDbAssocPersSubentId*& pCreatedPersSubentId);

    static Zcad::ErrorStatus
    createObjectAndDxfInFields(ZcDbDxfFiler*           pFiler,
                               ZcDbAssocPersSubentId*& pCreatedPersSubentId);

    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);

    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;

    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);

    virtual Zcad::ErrorStatus audit(ZcDbAuditInfo*) {
        return Zcad::eOk;
    }

    Zcad::ErrorStatus copyFrom(const ZcRxObject* pSource) override;

};

#pragma pack (pop)

