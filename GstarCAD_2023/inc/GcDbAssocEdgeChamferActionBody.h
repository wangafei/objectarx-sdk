/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class DBCONSTRAINTS_PORT GcDbAssocEdgeChamferActionBody : public GcDbAssocPathBasedSurfaceActionBody
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocEdgeChamferActionBody);

  explicit GcDbAssocEdgeChamferActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  Gcad::ErrorStatus setInput(const GcDbFullSubentPathArray& chamferEdges, const GcDbSubentId& baseFace);

  Gcad::ErrorStatus setBaseDistance(double baseDistance, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());
  Gcad::ErrorStatus setOtherDistance(double otherDistance, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());

  double baseDistance(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;
  double otherDistance(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;

  void evaluateOverride() override;

  static Gcad::ErrorStatus createInstance(const GcDbFullSubentPathArray& chamferEdges,
    const GcDbSubentId& baseFace,
    double baseDistance,
    double otherDistance,
    bool bEnabled,
    GcDbObjectId& createdActionId);
};

#pragma pack (pop)