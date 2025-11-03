/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class GcDbPathRef;
class GcDbLoftOptions;

class DBCONSTRAINTS_PORT GcDbAssocLoftedSurfaceActionBody : public GcDbAssocPathBasedSurfaceActionBody
{
public:
  enum ProfileType {
    kStartCrossSection = 0x01,
    kEndCrossSection = 0x02,
    kStartGuide = 0x04,
    kEndGuide = 0x08
  };
  GCRX_DECLARE_MEMBERS(GcDbAssocLoftedSurfaceActionBody);

  explicit GcDbAssocLoftedSurfaceActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  Gcad::ErrorStatus getContinuity(ProfileType type, int &continuity, GcString& expression = dummyString(),
    GcString& evaluatorId = dummyString()) const;
  Gcad::ErrorStatus setContinuity(ProfileType type, int continuity, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());

  Gcad::ErrorStatus getBulge(ProfileType type, double &bulge, GcString& expression = dummyString(),
    GcString& evaluatorId = dummyString()) const;
  Gcad::ErrorStatus setBulge(ProfileType type, double bulge, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());

  static Gcad::ErrorStatus createInstance(const GcDbObjectId& resultingSurfaceId,
    const GcArray<GcDbGeomRef *>& crossSections,
    const GcArray<GcDbPathRef>& guideCurves,
    const GcDbPathRef& pathCurve,
    const GcDbLoftOptions& loftOptions,
    const GcArray<int>& continuityArray,
    const GcArray<double>& bulgeArray,
    bool bEnabled,
    GcDbObjectId& createdActionId);
};

#pragma pack (pop)