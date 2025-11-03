/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocSurfaceActionBody.h"
#pragma pack (push, 8)

class GcDbAssocFilletSurfaceActionBody : public GcDbAssocSurfaceActionBody
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocFilletSurfaceActionBody, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcDbAssocFilletSurfaceActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getHintPoints(GcGePoint3d hintPoints[2]) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setHintPoints(const GcGePoint3d hintPoints[2], const GcGeVector3d& viewDir);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus setRadius(double dRadius, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString());
  DBCONSTRAINTS_PORT double            radius(GcString& expression = dummyString(), GcString& evaluatorId = dummyString()) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus setTrimMode(GcDb::FilletTrimMode trimMode);
  DBCONSTRAINTS_PORT GcDb::FilletTrimMode trimMode() const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getFilletHandleData(GcGePoint3d& pt,
    GcGeVector3d& dir,
    GcGePoint3d& filletCenPt,
    GcGeVector3d& filletNormal) const;

  DBCONSTRAINTS_PORT static Gcad::ErrorStatus createInstance(const GcDbObjectId& resultingSurfaceId,
    const GcDbObjectId& inputSurfaceId1,
    const GcGePoint3d& pickPt1,
    const GcDbObjectId& inputSurfaceId2,
    const GcGePoint3d& pickPt2,
    double radius, GcDb::FilletTrimMode trimMode,
    const GcGeVector3d& viewDir,
    bool bEnabled,
    GcDbObjectId& createdActionId);
};

#pragma pack (pop)