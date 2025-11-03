#ifndef _ZD_DBAUDITRECREATE_H
#define _ZD_DBAUDITRECREATE_H 1

#include "zacdb.h"

class ZCDB_PORT  ZcDbAuditRecreatePE : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAuditRecreatePE);
    virtual bool replace(ZcDbObject*&   pNewObj,
                         ZcDbObjectId   originalObjId,
                         ZcRxClass*     pObjClass,
                         ZcDbDatabase*  pDb,
                         ZcDbAuditInfo* pAuditInfo)
    {
		
		ZSOFT_UNREFED_PARAM(pNewObj);	ZSOFT_UNREFED_PARAM(originalObjId);
		ZSOFT_UNREFED_PARAM(pObjClass);	ZSOFT_UNREFED_PARAM(pDb);
		ZSOFT_UNREFED_PARAM(pAuditInfo);
		
		return false; 
	};
    virtual bool redirect(ZcDbObjectId&  newObjId,
                          ZcDbObjectId   originalObjId,
                          ZcRxClass*     pObjClass,
                          ZcDbDatabase*  pDb,
                          ZcDbAuditInfo* pAuditInfo)
    {
		
		ZSOFT_UNREFED_PARAM(newObjId); ZSOFT_UNREFED_PARAM(originalObjId);
		ZSOFT_UNREFED_PARAM(pObjClass); ZSOFT_UNREFED_PARAM(pDb);
		ZSOFT_UNREFED_PARAM(pAuditInfo);
		
		return false; 
	};

};

#endif 
