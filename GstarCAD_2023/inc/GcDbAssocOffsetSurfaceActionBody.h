/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocSurfaceActionBody.h"
#pragma pack (push, 8)

class  DBCONSTRAINTS_PORT GcDbAssocOffsetSurfaceActionBody : public GcDbAssocSurfaceActionBody
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocOffsetSurfaceActionBody);

  explicit GcDbAssocOffsetSurfaceActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  Gcad::ErrorStatus setDistance(double distance, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());
  double            distance(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;

  static Gcad::ErrorStatus createInstance(const GcDbObjectId& resultingSurfaceId,
    const GcDbObjectId& inputSurfaceId,
    double distance,
    bool bEnabled,
    GcDbObjectId& createdActionId);


};

#pragma pack (pop)