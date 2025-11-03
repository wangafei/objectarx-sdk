#ifndef _OD_DB_R13OBJECTID_
#define _OD_DB_R13OBJECTID_

#include "DbObjectId.h"

class OdDbR13ObjectId : public OdDbObjectId
{
public:

  bool operator < (const OdDbR13ObjectId& id) const;
  bool operator > (const OdDbR13ObjectId& id) const;
  bool operator <= (const OdDbR13ObjectId& id) const;
  bool operator >= (const OdDbR13ObjectId& id) const;
  bool operator == (const OdDbR13ObjectId& id) const;
  bool operator != (const OdDbR13ObjectId& id) const;

  bool operator < (const OdDbStub* pStub) const;
  bool operator > (const OdDbStub* pStub) const;
  bool operator <= (const OdDbStub* pStub) const;
  bool operator >= (const OdDbStub* pStub) const;
  bool operator == (const OdDbStub* pStub) const;
  bool operator != (const OdDbStub* pStub) const;
};

#endif