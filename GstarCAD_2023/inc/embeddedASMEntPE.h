/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcdbport.h"
#include "rxobject.h"

class GcDbEmbeddedASMEntPropsPE : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbEmbeddedASMEntPropsPE);
  GCDB_PORT virtual void setIsEmbeddedEnt(GcDbObject* pObj, bool bIsEmbedded = true);
};
