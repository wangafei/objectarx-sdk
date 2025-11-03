#pragma once
#include "TD_PackPush.h"

#include "RxObject.h"

class OdDbAuditInfo;

class TOOLKIT_EXPORT OdDbAuditRecreatePE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbAuditRecreatePE);
  virtual bool replace(OdDbObject*& pNewObj,
    OdDbObjectId originalObjId,
    OdRxClass* pObjClass,
    OdDbDatabase* pDb,
    OdDbAuditInfo* pAuditInfo);

  virtual bool redirect(OdDbObjectId& newObjId,
    OdDbObjectId originalObjId,
    OdRxClass* pObjClass,
    OdDbDatabase* pDb,
    OdDbAuditInfo* pAuditInfo);
};