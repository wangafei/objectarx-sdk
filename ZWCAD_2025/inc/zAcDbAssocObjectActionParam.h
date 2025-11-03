
#pragma once
#include "zAcDbAssocActionParam.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocObjectActionParam : public ZcDbAssocActionParam
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocObjectActionParam);

    explicit ZcDbAssocObjectActionParam(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    Zcad::ErrorStatus getObject(ZcDbCompoundObjectId& object) const;

    Zcad::ErrorStatus setObject(const ZcDbCompoundObjectId& object, bool isReadDependency = true, bool isWriteDependency = false, int dependencyOrder = 0);
};

#pragma pack (pop)
