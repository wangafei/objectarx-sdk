#ifndef _OD_DB_DBSELECTGRIP_
#define _OD_DB_DBSELECTGRIP_

#include "TD_PackPush.h"

#include "RxObject.h"

class OdDbEntity;
class OdGiViewportDraw;

class ODRX_ABSTRACT OdDbSelectGrip : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbSelectGrip);

  virtual bool SelectGrip(const OdDbEntity * pEnt,
    const OdGiViewportDraw* pVd,
    const void * pAppData) = 0;
};

ODRX_NO_CONS_DEFINE_MEMBERS(OdDbSelectGrip, OdRxObject)

#include "TD_PackPop.h"

#endif