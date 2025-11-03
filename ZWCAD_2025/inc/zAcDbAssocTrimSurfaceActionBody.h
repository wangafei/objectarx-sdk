
#pragma once
#include "zAcDbSurfaceTrimInfo.h"
#include "zAcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class ZCDB_PORT ZcDbAssocTrimSurfaceActionBody : public ZcDbAssocPathBasedSurfaceActionBody
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocTrimSurfaceActionBody);

    explicit ZcDbAssocTrimSurfaceActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    Zcad::ErrorStatus setTrimInfo(const ZcArray<ZcDbSurfaceTrimInfo> trimInfoArray, bool bAutoExtend);

    Zcad::ErrorStatus makeTrimPermanent();

    Zcad::ErrorStatus untrim();

    double getTrimmedArea() const;

    static Zcad::ErrorStatus createInstance( const ZcDbObjectId& resultingSurfaceId,
                                             const ZcArray<ZcDbSurfaceTrimInfo>& trimInfo,
                                             bool bAutoExtend,
                                             bool bEnabled,
                                             ZcDbObjectIdArray& createdActionIds);

};

#pragma pack (pop)
