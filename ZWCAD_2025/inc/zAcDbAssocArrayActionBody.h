
#pragma once
#include "zAcDbAssocParamBasedActionBody.h"
#include "zAcDbAssocArrayItem.h"

class ZcDbVertexRef;
class ZcDbAssocArrayParameters;

class ZCDBCORE2D_PORT ZcDbAssocArrayActionBody : public ZcDbAssocParamBasedActionBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocArrayActionBody);

    explicit ZcDbAssocArrayActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    ~ZcDbAssocArrayActionBody(void);

    const ZcDbAssocArrayParameters* parameters() const;

    ZcDbAssocArrayParameters* parameters();

    Zcad::ErrorStatus deleteItem(const ZcDbItemLocator& index, bool bErase = true);

    Zcad::ErrorStatus transformItemBy(const ZcDbItemLocator& index,
                                      const ZcGeMatrix3d&    xform);

    void getItems(ZcArray<ZcDbItemLocator>& indices, bool skipErased = true) const;

    const ZcDbAssocArrayItem* getItemAt(const ZcDbItemLocator& index,
        ZcDbFullSubentPath& path) const;
    inline const ZcDbAssocArrayItem* getItemAt(const ZcDbItemLocator& index) const
    {
        ZcDbFullSubentPath path = ZcDbFullSubentPath();
        return getItemAt(index, path);
    }

    const ZcDbAssocArrayItem* getItemAt(const ZcDbFullSubentPath& path) const;

    void evaluateOverride() override;

    virtual ZcDbObjectId getArrayEntity() const;

    virtual bool controlsItem(const ZcDbAssocArrayItem& index) const;

    virtual Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);

    virtual ZcGeMatrix3d getTransform() const;

    ZcDbObjectIdArray getSourceEntities() const;

    Zcad::ErrorStatus addSourceEntity(ZcDbObjectId entity,
        const ZcGePoint3d& basePoint);

    Zcad::ErrorStatus removeSourceEntity(ZcDbObjectId entity);

    Zcad::ErrorStatus setSourceBasePoint(const ZcDbVertexRef& basePoint);

    Zcad::ErrorStatus getSourceBasePoint(ZcDbVertexRef& vertexRef,
                                 ZcGePoint3d& position) const;

    static bool isAssociativeArray(const ZcDbEntity* pEntity);

    static ZcDbObjectId getControllingActionBody(const ZcDbEntity* pEntity,
        const ZcDbItemLocator* pItemIndex = NULL);

    static Zcad::ErrorStatus explode(ZcDbEntity* pEntity,
        ZcDbObjectIdArray& newIds);

    static Zcad::ErrorStatus resetArrayItems(ZcDbObjectId arrayEntityId,
        const ZcArray<ZcDbItemLocator>& indices, bool resetAll = false);

    static Zcad::ErrorStatus getArrayItemLocators(
        const ZcDbFullSubentPathArray& subents, ZcArray<ZcDbItemLocator>& indices);

    static Zcad::ErrorStatus createInstance(const ZcDbObjectIdArray& sourceEntites,
        ZcDbVertexRef& basePoint, const ZcDbAssocArrayParameters* pParameters,
        ZcDbObjectId& arrayId, ZcDbObjectId& actionBodyId);

    ZcDbObjectId getArraySourceBTR() const;

    Zcad::ErrorStatus addMoreObjectsToDeepCloneOverride(ZcDbIdMapping& idMap,
        ZcDbObjectIdArray& additionalObjectsToClone) const override;

    Zcad::ErrorStatus postProcessAfterDeepCloneOverride(ZcDbIdMapping& idMap) override;

    Zcad::ErrorStatus dragStatusOverride(const ZcDb::DragStat status) override;
};
