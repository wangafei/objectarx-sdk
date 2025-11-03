#pragma once
#include "zAcDbAssocArrayActionBody.h"

class ZcDbVertexRef;

class ZCDB_PORT ZcDbAssocArrayModifyActionBody : public ZcDbAssocArrayActionBody
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbAssocArrayModifyActionBody);

    explicit ZcDbAssocArrayModifyActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    ~ZcDbAssocArrayModifyActionBody(void);

    Zcad::ErrorStatus getOverridenItems(ZcArray<ZcDbItemLocator>& indices) const;

    Zcad::ErrorStatus setOverridenItems(const ZcArray<ZcDbItemLocator>& indices);

    virtual bool controlsItem(const ZcDbAssocArrayItem& item) const ZSOFT_OVERRIDE;

    static Zcad::ErrorStatus createInstance(ZcDbObjectId arrayId,
                                       const ZcArray<ZcDbItemLocator>& indices,
                                       const ZcDbObjectIdArray& substEntities,
                                       ZcDbVertexRef& basePoint,
                                       ZcDbObjectId& actionBodyId);
};
