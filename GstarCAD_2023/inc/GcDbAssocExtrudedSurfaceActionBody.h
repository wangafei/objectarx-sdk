/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocPathBasedSurfaceActionBody.h"
#pragma pack (push, 8)

class GcDbSweepOptions;

class GcDbAssocExtrudedSurfaceActionBody : public GcDbAssocPathBasedSurfaceActionBody
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocExtrudedSurfaceActionBody, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcDbAssocExtrudedSurfaceActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus setTaperAngle(double dTaperAngle, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());
  DBCONSTRAINTS_PORT double            taperAngle(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus setHeight(double dHeight, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());
  DBCONSTRAINTS_PORT double            height(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;

  DBCONSTRAINTS_PORT static Gcad::ErrorStatus createInstance(const GcDbObjectId& resultingSurfaceId,
    const GcDbPathRef& inputPath,
    const GcGeVector3d& directionVec,
    const GcDbSweepOptions& sweptOptions,
    bool  bEnabled,
    GcDbObjectId& createdActionId);
};

#pragma pack (pop)