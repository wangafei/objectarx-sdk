/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocActionParam.h"
#include "GcDbGeomRef.h"
#pragma pack (push, 8)

class GcDbAssocFaceActionParam : public GcDbAssocActionParam
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocFaceActionParam, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcDbAssocFaceActionParam(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus setFaceRef(const GcDbFaceRef& faceRef, bool isReadDependency = true, bool isWriteDependency = false, int dependencyOrder = 0);
  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus getFaceRef(GcArray<GcDbFaceRef>& faceRefs) const;
  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus setFaceSubentityGeometry(const GcGeSurface* pNewFaceSurface);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus         getDependentOnCompoundObject(GcDbCompoundObjectId& compoundId) const;
};

#pragma pack (pop)