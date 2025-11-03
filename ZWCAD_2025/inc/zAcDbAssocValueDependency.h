
#pragma once
#include "zAcDbAssocDependency.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocValueDependency : public ZcDbAssocDependency
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocValueDependency);

    explicit ZcDbAssocValueDependency(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    const ZcString& valueName() const;

    Zcad::ErrorStatus setValueName(const ZcString& newValueName);

    Zcad::ErrorStatus getDependentOnObjectValue(ZcDbEvalVariant& objectValue) const;

    Zcad::ErrorStatus setDependentOnObjectValue(const ZcDbEvalVariant& newObjectValue);

};

#pragma pack (pop)
