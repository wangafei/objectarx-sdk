
#pragma once
#include "zAcDbAssocDimDependencyBodyBase.h"

class ZCDBCORE2D_PORT ZcDbAssocDimDependencyBody : public ZcDbAssocDimDependencyBodyBase
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocDimDependencyBody);

    ZcDbAssocDimDependencyBody();

    ~ZcDbAssocDimDependencyBody();

    ZcString getEntityTextOverride() const override;

    Zcad::ErrorStatus setEntityTextOverride(const ZcString& newText) override;

    double getEntityMeasurementOverride() const override;

    bool isEntityAttachmentChangedOverride() const override;

    Zcad::ErrorStatus updateDependentOnObjectOverride() override;

    static Zcad::ErrorStatus
                createAndPostToDatabase(const ZcDbObjectId& dimId,
                                        ZcDbObjectId&       dimDepId,
                                        ZcDbObjectId&       dimDepBodyId);
};

