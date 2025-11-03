
#pragma once
#include "zAcDbCompoundObjectId.h"
#include "zAcDbAssocGlobal.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocDependencyPE : public ZcRxObject
{
public:
	ZCRX_DECLARE_MEMBERS(ZcDbAssocDependencyPE);

    virtual bool allowsDependencies(const ZcDbObject*          pObject,
                                    bool                       isWriteDependency,
                                    const ZcRxClass*           pActionBodyOrActionClass,
                                    const ZcDbAssocDependency* pDependency,
                                    const ZcRxObject*          pContext) const = 0;

    virtual Zcad::ErrorStatus redirectDependencyAttachment(ZcDbObject*                 pObject,
                                                           const ZcDbCompoundObjectId& compoundObjectId,
                                                           ZcDbAssocDependency*        pDependency,
                                                           ZcDbCompoundObjectId&       redirectedCompoundObjectId)
    {
        ZSOFT_UNREFED_PARAM(pDependency);
        ZSOFT_UNREFED_PARAM(pObject);
        redirectedCompoundObjectId = compoundObjectId;
        return Zcad::eOk;
    }

};

#pragma pack (pop)

