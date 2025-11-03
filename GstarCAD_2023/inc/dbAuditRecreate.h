/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GD_DBAUDITRECREATE_H
#define _GD_DBAUDITRECREATE_H 1

#include "gcdb.h"

class GCDB_PORT GcDbAuditRecreatePE : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAuditRecreatePE);
  virtual bool replace(GcDbObject*&   pNewObj,
    GcDbObjectId   originalObjId,
    GcRxClass*     pObjClass,
    GcDbDatabase*  pDb,
    GcDbAuditInfo* pAuditInfo)
  {
    GSOFT_UNREFED_PARAM(pNewObj); GSOFT_UNREFED_PARAM(originalObjId);
    GSOFT_UNREFED_PARAM(pObjClass); GSOFT_UNREFED_PARAM(pDb);
    GSOFT_UNREFED_PARAM(pAuditInfo);
    return false;
  };
  virtual bool redirect(GcDbObjectId&  newObjId,
    GcDbObjectId   originalObjId,
    GcRxClass*     pObjClass,
    GcDbDatabase*  pDb,
    GcDbAuditInfo* pAuditInfo)
  {
    GSOFT_UNREFED_PARAM(newObjId); GSOFT_UNREFED_PARAM(originalObjId);
    GSOFT_UNREFED_PARAM(pObjClass); GSOFT_UNREFED_PARAM(pDb);
    GSOFT_UNREFED_PARAM(pAuditInfo);
    return false;
  };
};

#endif 