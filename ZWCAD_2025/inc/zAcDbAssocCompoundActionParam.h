
#pragma once
#include "zAcDbAssocActionParam.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocCompoundActionParam : public ZcDbAssocActionParam
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocCompoundActionParam);

    explicit ZcDbAssocCompoundActionParam(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    virtual Zcad::ErrorStatus removeAllParams(bool alsoEraseThem);

    int paramCount() const;

    const ZcDbObjectIdArray& ownedParams() const;

    Zcad::ErrorStatus addParam(const ZcDbObjectId& paramId, int& paramIndex);

    Zcad::ErrorStatus removeParam(const ZcDbObjectId& paramId, bool alsoEraseIt);

    const ZcDbObjectIdArray& paramsAtName(const ZcString& paramName) const;

    ZcDbObjectId paramAtName(const ZcString& paramName, int index = 0) const;

    ZcDbObjectId paramAtIndex(int paramIndex) const;
};

#pragma pack (pop)
