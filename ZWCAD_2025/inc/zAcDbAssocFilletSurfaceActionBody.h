
#pragma once
#include "zAcDbAssocSurfaceActionBody.h"
#pragma pack (push, 8)

class ZCDB_PORT ZcDbAssocFilletSurfaceActionBody : public ZcDbAssocSurfaceActionBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocFilletSurfaceActionBody);

    explicit ZcDbAssocFilletSurfaceActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    Zcad::ErrorStatus getHintPoints(ZcGePoint3d hintPoints[2]) const;

    Zcad::ErrorStatus setHintPoints(const ZcGePoint3d hintPoints[2], const ZcGeVector3d& viewDir);

    Zcad::ErrorStatus setRadius( double dRadius, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString() );

    double radius(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    Zcad::ErrorStatus setTrimMode ( ZcDb::FilletTrimMode trimMode );

    ZcDb::FilletTrimMode trimMode() const;

    Zcad::ErrorStatus getFilletHandleData (ZcGePoint3d& pt,
                                           ZcGeVector3d& dir,
                                           ZcGePoint3d& filletCenPt,
                                           ZcGeVector3d& filletNormal) const;

    static Zcad::ErrorStatus createInstance( const ZcDbObjectId& resultingSurfaceId,
                                             const ZcDbObjectId& inputSurfaceId1,
                                             const ZcGePoint3d& pickPt1,
                                             const ZcDbObjectId& inputSurfaceId2,
                                             const ZcGePoint3d& pickPt2,
                                             double radius, ZcDb::FilletTrimMode trimMode,
                                             const ZcGeVector3d& viewDir,
                                             bool bEnabled,
                                             ZcDbObjectId& createdActionId);

};

#pragma pack (pop)
