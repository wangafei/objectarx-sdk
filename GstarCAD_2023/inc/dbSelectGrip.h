/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _DBSELECTGRIP_H
#define _DBSELECTGRIP_H

#include "gcdb.h"
#include "dbmain.h"

#pragma pack (push, 8)

class GSOFT_NO_VTABLE GcDbSelectGrip : public GcRxObject {
public:
  GCRX_DECLARE_MEMBERS(GcDbSelectGrip);

  virtual bool SelectGrip(const GcDbEntity * pEnt,
    const GcGiViewportDraw* pVd,
    const void * pAppData) = 0;
};

#pragma pack (pop)

#endif  