/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocEdgeActionParam.h"
#include "GcDbAssocCompoundActionParam.h"
#pragma pack (push, 8)

class GcDbAssocAsmBodyActionParam : public GcDbAssocActionParam
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocAsmBodyActionParam, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcDbAssocAsmBodyActionParam(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus setBody(const GcDbEntity* pAsmEntity, bool isReadDependency = true, bool isWriteDependency = false, int dependencyOrder = 0);
  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus setBody(GcDbObjectId asmEntityId, bool isReadDependency = true, bool isWriteDependency = false, int dependencyOrder = 0);
  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus setBody(void* pAsmBody, bool makeCopy);
  DBCONSTRAINTS_PORT virtual void* body(bool makeCopy) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getDependentOnCompoundObject(GcDbCompoundObjectId& compoundId) const;
};

#pragma pack (pop)