/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class GcDbSurface;
#include "dbsurf.h" 

class GcDbAssocExtendSurfaceActionBody : public GcDbAssocPathBasedSurfaceActionBody
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocExtendSurfaceActionBody, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcDbAssocExtendSurfaceActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus setDistance(double distance, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());
  DBCONSTRAINTS_PORT double            distance(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;

  DBCONSTRAINTS_PORT static Gcad::ErrorStatus createInstance(const GcDbObjectId& resultingSurfaceId,
    const GcArray<GcDbEdgeRef>& extendEdges,
    double distance,
    GcDbSurface::EdgeExtensionType option,
    bool bEnabled,
    GcDbObjectId& createdActionId);
};

#pragma pack (pop)