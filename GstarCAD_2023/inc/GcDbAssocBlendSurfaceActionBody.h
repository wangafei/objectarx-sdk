/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "dbgrip.h"
#include "GcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class GcDbLoftProfile;
class GcDbBlendOptions;

class GcDbAssocBlendSurfaceActionBody : public GcDbAssocPathBasedSurfaceActionBody
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocBlendSurfaceActionBody, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcDbAssocBlendSurfaceActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  DBCONSTRAINTS_PORT Gsoft::Int16       startEdgeContinuity(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus  setStartEdgeContinuity(Gsoft::Int16 value, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());

  DBCONSTRAINTS_PORT Gsoft::Int16       endEdgeContinuity(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus  setEndEdgeContinuity(Gsoft::Int16 value, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());

  DBCONSTRAINTS_PORT double             startEdgeBulge(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus  setStartEdgeBulge(double value, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());

  DBCONSTRAINTS_PORT double             endEdgeBulge(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus  setEndEdgeBulge(double value, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());

  DBCONSTRAINTS_PORT Gcad::ErrorStatus  getContinuityGripPoints(GcGePoint3d& startEdgePt,
    GcGePoint3d& endEdgePt) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus  getProfiles(GcDbLoftProfile* & pStartProfile,
    GcDbLoftProfile* & pEndProfile) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus  getBlendOptions(GcDbBlendOptions& blendOptions) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus  setBlendOptions(const GcDbBlendOptions& blendOptions);

  DBCONSTRAINTS_PORT static Gcad::ErrorStatus createInstance(const GcDbObjectId& resultingSurfaceId,
    const GcDbLoftProfile* startProfile,
    const GcDbLoftProfile* endProfile,
    const GcDbBlendOptions& blendOptions,
    bool bEnabled,
    GcDbObjectId& createdActionId);
};

#pragma pack (pop)