/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GCSYMUTL_H
#define _GCSYMUTL_H

#include <assert.h>
#include "gcadstrc.h"
#include "dbsymutl.h"
#pragma pack (push, 8)

#define GCEDSYMUTIL_SERVICES_CURRENT_VERSION 100

class GcDbDatabase;

namespace GcEdSymbolUtilities
{
  enum CrSpMode {
    kCrEndsInput = true
    , kCrSpEndsInput = false
  };

  enum NameCaseMode {
    kPreserveCase = true
    , kForceToUpper = false
  };

  class Services
  {
  public:
    enum { kCurrentVersion = GCEDSYMUTIL_SERVICES_CURRENT_VERSION };
    virtual unsigned version() const = 0;

    virtual Gcad::PromptStatus getCompatibleSymbolString(
      GCHAR*&        pResponse,
      const GCHAR*   prompt,
      GcDbDatabase * pDb) const = 0;

    virtual Gcad::PromptStatus getSymbolString(
      GCHAR*&      pResponse,
      const GCHAR* prompt,
      bool         onlyCrEndsInput,
      bool         preserveCase) const = 0;

  };

#define GCEDSYMUTIL_SERVICESNAME_WITH_VERSION_1(n,v) n ## v
#define GCEDSYMUTIL_SERVICESNAME_WITH_VERSION(n,v) \
        GCEDSYMUTIL_SERVICESNAME_WITH_VERSION_1(n,v)
#define GCEDSYMUTIL_SERVICES_NAME \
        GCEDSYMUTIL_SERVICESNAME_WITH_VERSION( \
            servicesPtr, \
            GCEDSYMUTIL_SERVICES_CURRENT_VERSION)
  GCCORE_PORT extern const Services * GCEDSYMUTIL_SERVICES_NAME();

  inline const Services *
    servicesPtr()
  {
    const Services * pSymUtil = GCEDSYMUTIL_SERVICES_NAME();
    assert(pSymUtil != 0);
    assert(pSymUtil->version() == Services::kCurrentVersion);
    return pSymUtil;
  }

}

namespace GcEdSymUtil = GcEdSymbolUtilities;

typedef GcEdSymbolUtilities::Services GcEdSymUtilServices;

inline const GcEdSymUtilServices *
gcedSymUtil()
{
  return GcEdSymbolUtilities::servicesPtr();
}

#pragma pack (pop)
#endif 