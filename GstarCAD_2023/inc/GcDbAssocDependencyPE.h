/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbCompoundObjectId.h"
#include "GcDbAssocGlobal.h"
#pragma pack (push, 8)

class GcDbAssocDependencyPE : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocDependencyPE, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT virtual bool allowsDependencies(const GcDbObject*          pObject,
    bool                       isWriteDependency,
    const GcRxClass*           pActionBodyOrActionClass,
    const GcDbAssocDependency* pDependency,
    const GcRxObject*          pContext) const = 0;

  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus redirectDependencyAttachment(GcDbObject*                 pObject,
    const GcDbCompoundObjectId& compoundObjectId,
    GcDbAssocDependency*        pDependency,
    GcDbCompoundObjectId&       redirectedCompoundObjectId)
  {
    GSOFT_UNREFED_PARAM(pDependency);
    GSOFT_UNREFED_PARAM(pObject);
    redirectedCompoundObjectId = compoundObjectId;
    return Gcad::eOk;
  }
};

#pragma pack (pop)