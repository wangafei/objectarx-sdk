/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class GcDbRevolveOptions;

class DBCONSTRAINTS_PORT GcDbAssocRevolvedSurfaceActionBody : public GcDbAssocPathBasedSurfaceActionBody
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocRevolvedSurfaceActionBody);

  explicit GcDbAssocRevolvedSurfaceActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  Gcad::ErrorStatus setRevolveAngle(double angle, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());
  double revolveAngle(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;

  static Gcad::ErrorStatus createInstance(const GcDbObjectId& resultingSurfaceId,
    const GcDbPathRef& revolvePath,
    const GcDbPathRef& axisPath,
    double dAngle,
    double dStartAngle,
    const GcDbRevolveOptions& revolveOptions,
    bool bFlipAxisDirection,
    bool bEnabled,
    GcDbObjectId& createdActionId);
};

#pragma pack (pop)