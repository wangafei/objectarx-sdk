/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class DBCONSTRAINTS_PORT GcDbAssocEdgeFilletActionBody : public GcDbAssocPathBasedSurfaceActionBody
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocEdgeFilletActionBody);

  explicit GcDbAssocEdgeFilletActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  Gcad::ErrorStatus setInputEdges(const GcDbFullSubentPathArray& filletEdges);
  Gcad::ErrorStatus setRadius(double radius, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());
  double            radius(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;
  void              evaluateOverride() override;

  static Gcad::ErrorStatus createInstance(const GcDbFullSubentPathArray& filletEdges,
    double radius,
    bool bEnabled,
    GcDbObjectId& createdActionId);
};

#pragma pack (pop)