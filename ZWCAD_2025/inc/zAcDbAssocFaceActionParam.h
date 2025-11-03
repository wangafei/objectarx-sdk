
#pragma once
#include "zAcDbAssocActionParam.h"
#include "zAcDbGeomRef.h"
#pragma pack (push, 8)

class ZCDB_PORT ZcDbAssocFaceActionParam : public ZcDbAssocActionParam
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocFaceActionParam);

    explicit ZcDbAssocFaceActionParam(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    virtual Zcad::ErrorStatus setFaceRef(const ZcDbFaceRef& faceRef, bool isReadDependency = true, bool isWriteDependency = false, int dependencyOrder = 0);

    virtual Zcad::ErrorStatus getFaceRef(ZcArray<ZcDbFaceRef>& faceRefs) const;

    virtual Zcad::ErrorStatus setFaceSubentityGeometry(const ZcGeSurface* pNewFaceSurface);

    Zcad::ErrorStatus getDependentOnCompoundObject(ZcDbCompoundObjectId& compoundId) const;
};

#pragma pack (pop)

