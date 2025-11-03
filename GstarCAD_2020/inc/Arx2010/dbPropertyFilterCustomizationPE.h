#pragma once

#define AcDbPropertyFilterCustomizationPE  GcDbPropertyFilterCustomizationPE
#define GcDbPropertyFilterCustomizationPE  OdDbPropertyFilterCustomizationPE

#include "acdb.h"
#include "dynprops.h"

#pragma pack (push, 8)

class OdFilterablePropertyContext;

class OdDbPropertyFilterCustomizationPE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbPropertyFilterCustomizationPE);

  virtual bool vetoCustomization(OdFilterablePropertyContext context, OdRxClass* pCls) const = 0;

  virtual bool createObject(OdDbDatabase* pDb, OdRxClass* pCls, OdDbEntity** ppEnt, OdDbObjectId& objId, const OdString& sGUID) const = 0;
};

#pragma pack (pop)
