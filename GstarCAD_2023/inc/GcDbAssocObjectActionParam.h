/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocActionParam.h"
#pragma pack (push, 8)

class DBCONSTRAINTS_PORT GcDbAssocObjectActionParam : public GcDbAssocActionParam
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocObjectActionParam);

  explicit GcDbAssocObjectActionParam(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  Gcad::ErrorStatus getObject(GcDbCompoundObjectId& object) const;
  Gcad::ErrorStatus setObject(const GcDbCompoundObjectId& object, bool isReadDependency = true, bool isWriteDependency = false, int dependencyOrder = 0);
};

#pragma pack (pop)