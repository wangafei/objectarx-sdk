/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocPathBasedSurfaceActionBody.h"
#include "GcDbAssocLoftedSurfaceActionBody.h"
#pragma pack (push, 8)

class DBCONSTRAINTS_PORT GcDbAssocNetworkSurfaceActionBody : public GcDbAssocPathBasedSurfaceActionBody
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocNetworkSurfaceActionBody);

  explicit GcDbAssocNetworkSurfaceActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  Gcad::ErrorStatus getContinuity(GcDbAssocLoftedSurfaceActionBody::ProfileType type,
    int &continuity, GcString& expression = dummyString(),
    GcString& evaluatorId = dummyString()) const;
  Gcad::ErrorStatus setContinuity(GcDbAssocLoftedSurfaceActionBody::ProfileType type,
    int continuity, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());

  Gcad::ErrorStatus getBulge(GcDbAssocLoftedSurfaceActionBody::ProfileType type,
    double &bulge, GcString& expression = dummyString(),
    GcString& evaluatorId = dummyString()) const;
  Gcad::ErrorStatus setBulge(GcDbAssocLoftedSurfaceActionBody::ProfileType type,
    double bulge, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());

  static Gcad::ErrorStatus createInstance(const GcDbObjectId& resultingSurfaceId,
    const GcArray<GcDbPathRef>& crossSections,
    const GcArray<GcDbPathRef>& guideCurves,
    const GcArray<int>& continuityArray,
    const GcArray<double>& bulgeArray,
    bool bEnabled,
    GcDbObjectId& createdActionId);
};

#pragma pack (pop)