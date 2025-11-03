/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class DBCONSTRAINTS_PORT GcDbAssocPlaneSurfaceActionBody : public GcDbAssocPathBasedSurfaceActionBody
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocPlaneSurfaceActionBody);

  explicit GcDbAssocPlaneSurfaceActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  static Gcad::ErrorStatus createInstance(const GcDbObjectId& resultingSurfaceId,
    const GcDbPathRef& inputPath,
    bool bEnabled,
    GcDbObjectId& createdActionId);
};

#pragma pack (pop)