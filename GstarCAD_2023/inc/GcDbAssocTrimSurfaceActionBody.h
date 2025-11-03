/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbSurfaceTrimInfo.h"
#include "GcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class DBCONSTRAINTS_PORT GcDbAssocTrimSurfaceActionBody : public GcDbAssocPathBasedSurfaceActionBody
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocTrimSurfaceActionBody);

  explicit GcDbAssocTrimSurfaceActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  Gcad::ErrorStatus setTrimInfo(const GcArray<GcDbSurfaceTrimInfo> trimInfoArray, bool bAutoExtend);
  Gcad::ErrorStatus makeTrimPermanent();
  Gcad::ErrorStatus untrim();
  double getTrimmedArea() const;
  static Gcad::ErrorStatus createInstance(const GcDbObjectId& resultingSurfaceId,
    const GcArray<GcDbSurfaceTrimInfo>& trimInfo,
    bool bAutoExtend,
    bool bEnabled,
    GcDbObjectIdArray& createdActionIds);
};

#pragma pack (pop)