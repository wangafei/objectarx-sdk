
#pragma once
#include "zdbgrip.h"
#include "zAcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class ZcDbLoftProfile;
class ZcDbBlendOptions;

class ZCDB_PORT ZcDbAssocBlendSurfaceActionBody : public ZcDbAssocPathBasedSurfaceActionBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocBlendSurfaceActionBody);

    explicit ZcDbAssocBlendSurfaceActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    ZSoft::Int16       startEdgeContinuity(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    Zcad::ErrorStatus  setStartEdgeContinuity (ZSoft::Int16 value, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString());

    ZSoft::Int16       endEdgeContinuity(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    Zcad::ErrorStatus  setEndEdgeContinuity (ZSoft::Int16 value, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString());

    double             startEdgeBulge(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    Zcad::ErrorStatus  setStartEdgeBulge(double value, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString());

    double             endEdgeBulge(ZcString& expression = dummyString(), ZcString& evaluatorId = dummyString()) const;

    Zcad::ErrorStatus  setEndEdgeBulge(double value, const ZcString& expression = ZcString(),
        const ZcString& evaluatorId = ZcString());

    Zcad::ErrorStatus  getContinuityGripPoints(ZcGePoint3d& startEdgePt,
		                              ZcGePoint3d& endEdgePt) const;

    Zcad::ErrorStatus  getProfiles(ZcDbLoftProfile* & pStartProfile,
                                   ZcDbLoftProfile* & pEndProfile) const;

    Zcad::ErrorStatus  getBlendOptions( ZcDbBlendOptions& blendOptions ) const;

    Zcad::ErrorStatus  setBlendOptions (const ZcDbBlendOptions& blendOptions );

    static Zcad::ErrorStatus createInstance( const ZcDbObjectId& resultingSurfaceId,
                                             const ZcDbLoftProfile* startProfile,
                                             const ZcDbLoftProfile* endProfile,
                                             const ZcDbBlendOptions& blendOptions,
                                             bool bEnabled,
                                             ZcDbObjectId& createdActionId);

};

#pragma pack (pop)
