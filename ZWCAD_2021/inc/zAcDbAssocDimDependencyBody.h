#pragma once
#include "zAcDbAssocDimDependencyBodyBase.h"

class ZCDB_PORT ZcDbAssocDimDependencyBody : public ZcDbAssocDimDependencyBodyBase
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocDimDependencyBody);

    ZcDbAssocDimDependencyBody();

    virtual ~ZcDbAssocDimDependencyBody();

    virtual ZcString getEntityTextOverride() const ZSOFT_OVERRIDE;

    virtual Zcad::ErrorStatus setEntityTextOverride(const ZcString& newText) ZSOFT_OVERRIDE;

    virtual double getEntityMeasurementOverride() const ZSOFT_OVERRIDE;

    virtual bool isEntityAttachmentChangedOverride() const ZSOFT_OVERRIDE;

    virtual Zcad::ErrorStatus updateDependentOnObjectOverride() ZSOFT_OVERRIDE;

    static Zcad::ErrorStatus
                createAndPostToDatabase(const ZcDbObjectId& dimId,
                                        ZcDbObjectId&       dimDepId,
                                        ZcDbObjectId&       dimDepBodyId);
};
