/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class DBCONSTRAINTS_PORT GcDbAssocSweptSurfaceActionBody : public GcDbAssocPathBasedSurfaceActionBody
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocSweptSurfaceActionBody);

  explicit GcDbAssocSweptSurfaceActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  Gcad::ErrorStatus setScaleFactor(double scale, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());
  double scaleFactor(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;

  Gcad::ErrorStatus setAlignAngle(double angle, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());
  double alignAngle(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;

  Gcad::ErrorStatus setTwistAngle(double angle, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());
  double twistAngle(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;

  static Gcad::ErrorStatus createInstance(const GcDbObjectId& resultingSurfaceId,
    const GcDbPathRef& sweepProfile,
    const GcDbPathRef& sweepPathProfile,
    const GcDbSweepOptions& sweptOptions,
    bool  bEnabled,
    GcDbObjectId& createdActionId);
};

#pragma pack (pop)