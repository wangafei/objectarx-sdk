
#pragma once
#include "zAcDbAssocEdgeActionParam.h"
#include "zAcDbAssocCompoundActionParam.h"
#pragma pack (push, 8)

class ZCDB_PORT ZcDbAssocZsmBodyActionParam : public ZcDbAssocActionParam
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocZsmBodyActionParam);

    explicit ZcDbAssocZsmBodyActionParam(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    virtual Zcad::ErrorStatus setBody(const ZcDbEntity* pZsmEntity, bool isReadDependency = true, bool isWriteDependency = false, int dependencyOrder = 0);

    virtual Zcad::ErrorStatus setBody(ZcDbObjectId zsmEntityId, bool isReadDependency = true, bool isWriteDependency = false, int dependencyOrder = 0);

    virtual Zcad::ErrorStatus setBody(void* pZsmBody, bool makeCopy);

    virtual void* body(bool makeCopy) const;

    Zcad::ErrorStatus getDependentOnCompoundObject(ZcDbCompoundObjectId& compoundId) const;
};

#pragma pack (pop)
