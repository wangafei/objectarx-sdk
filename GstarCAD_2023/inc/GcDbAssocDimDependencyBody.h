/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocDimDependencyBodyBase.h"

class GcDbAssocDimDependencyBody : public GcDbAssocDimDependencyBodyBase
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocDimDependencyBody, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcDbAssocDimDependencyBody();
  DBCONSTRAINTS_PORT ~GcDbAssocDimDependencyBody();

  DBCONSTRAINTS_PORT GcString getEntityTextOverride() const override;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setEntityTextOverride(const GcString& newText) override;

  DBCONSTRAINTS_PORT double getEntityMeasurementOverride() const override;
  DBCONSTRAINTS_PORT bool isEntityAttachmentChangedOverride() const override;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus updateDependentOnObjectOverride() override;

  DBCONSTRAINTS_PORT static Gcad::ErrorStatus createAndPostToDatabase(const GcDbObjectId& dimId,
      GcDbObjectId&       dimDepId,
      GcDbObjectId&       dimDepBodyId);
};