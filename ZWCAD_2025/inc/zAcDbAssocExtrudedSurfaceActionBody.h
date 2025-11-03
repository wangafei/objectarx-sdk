
#pragma once
#include "zAcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class ZcDbSweepOptions;

class ZCDB_PORT ZcDbAssocExtrudedSurfaceActionBody : public ZcDbAssocPathBasedSurfaceActionBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocExtrudedSurfaceActionBody);

    explicit ZcDbAssocExtrudedSurfaceActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    Zcad::ErrorStatus setTaperAngle( double dTaperAngle, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString());

    double            taperAngle(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    Zcad::ErrorStatus setHeight( double dHeight, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString());

    double            height(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    static Zcad::ErrorStatus createInstance( const ZcDbObjectId& resultingSurfaceId,
                                             const ZcDbPathRef& inputPath,
                                             const ZcGeVector3d& directionVec,
                                             const ZcDbSweepOptions& sweptOptions,
                                             bool  bEnabled,
                                             ZcDbObjectId& createdActionId);

};

#pragma pack (pop)
