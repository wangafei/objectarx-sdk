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

class DBCONSTRAINTS_PORT GcDbAssocPatchSurfaceActionBody : public GcDbAssocPathBasedSurfaceActionBody
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocPatchSurfaceActionBody);

  explicit GcDbAssocPatchSurfaceActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  Gcad::ErrorStatus setConstraintPoints(const GcArray<GcDbVertexRef> & constraintPoints);
  Gcad::ErrorStatus setConstraintCurves(const GcArray<GcDbEdgeRef> & constraintCurves);

  Gcad::ErrorStatus setContinuity(int continuity, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());
  int continuity(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;
  Gcad::ErrorStatus getContinuityGripPoint(GcGePoint3d&  gripPt) const;

  Gcad::ErrorStatus setBulge(double bulge, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());
  double            bulge(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;

  static Gcad::ErrorStatus createInstance(const GcDbObjectId& patchSurfaceId,
    const GcArray<GcDbEdgeRef>& profileCurves,
    const GcArray<GcDbEdgeRef>& constraintCurves,
    const GcArray<GcDbVertexRef>&constraintPoints,
    int nContinuity,
    double dBulge,
    bool bEnabled,
    GcDbObjectId& createdActionId);
  static Gcad::ErrorStatus createInstance(const GcDbObjectId& patchSurfaceId,
    const GcArray<GcDbEdgeRef>& profileCurves,
    const GcArray<GcDbEdgeRef>& constraintCurves,
    const GcArray<GcDbVertexRef>&constraintPoints,
    bool bEnabled,
    GcDbObjectId& createdActionId);
};

#pragma pack (pop)