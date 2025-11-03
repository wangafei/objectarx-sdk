/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#include "GdGChar.h"
#include "gcadstrc.h"
#include "GcDbCore2dDefs.h"

#pragma once
class GcString;

class GcDbManagedHost
{
public:
  virtual int  version() { return 1; }
  virtual Gcad::ErrorStatus load(const GCHAR * fname) = 0;
  virtual bool loadIndirectString(const GcString& resAssemblyPath, const GcString& cmdString, GcString& localCmd) = 0;
  virtual bool isLoaded() = 0;
};

GCCORE_PORT GcDbManagedHost*  GSOFT_STDCALL gcdbGetManagedHost();
GCCORE_PORT Gcad::ErrorStatus GSOFT_STDCALL gcdbSetManagedHost(GcDbManagedHost* pHost);