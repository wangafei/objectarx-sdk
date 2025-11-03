
#pragma once
#include "zAcDbAssocActionBody.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocParamBasedActionBody : public ZcDbAssocActionBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocParamBasedActionBody);

    explicit ZcDbAssocParamBasedActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);
};

#pragma pack (pop)

