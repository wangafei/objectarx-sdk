#pragma once

#include "TD_PackPush.h"

#include "DbSymUtl.h"

#define ODEDSYMUTIL_SERVICES_CURRENT_VERSION 100

class OdDbDatabase;

namespace OdEdSymbolUtilities
{
  enum CrSpMode
  {
    kCrEndsInput = true,
    kCrSpEndsInput = false
  };

  enum NameCaseMode
  {
    kPreserveCase = true,
    kForceToUpper = false
  };

  class Services
  {
  public:
    enum { kCurrentVersion = ODEDSYMUTIL_SERVICES_CURRENT_VERSION };
    virtual unsigned version() const = 0;

    virtual Oda::PromptStatus getCompatibleSymbolString(
      OdChar*&        pResponse,
      const OdChar*   prompt,
      OdDbDatabase* pDb) const = 0;

    virtual Oda::PromptStatus getSymbolString(
      OdChar*&      pResponse,
      const OdChar* prompt,
      bool         onlyCrEndsInput,
      bool         preserveCase) const = 0;

  };
#define ODEDSYMUTIL_SERVICESNAME_WITH_VERSION_1(n,v) n ## v

#define ODEDSYMUTIL_SERVICESNAME_WITH_VERSION(n,v) \
        ODEDSYMUTIL_SERVICESNAME_WITH_VERSION_1(n,v)

#define ODEDSYMUTIL_SERVICES_NAME \
        ODEDSYMUTIL_SERVICESNAME_WITH_VERSION( \
            servicesPtr, \
            ODEDSYMUTIL_SERVICES_CURRENT_VERSION)

  extern TOOLKIT_EXPORT const Services * ODEDSYMUTIL_SERVICES_NAME()
  {
    throw OdError(eNotImplemented);
    return NULL;
  }

  inline const Services *servicesPtr()
  {
    const Services * pSymUtil = ODEDSYMUTIL_SERVICES_NAME();
    return pSymUtil;
  }

}

namespace OdEdSymUtil = OdEdSymbolUtilities;

typedef OdEdSymbolUtilities::Services OdEdSymUtilServices;

inline const OdEdSymUtilServices *
odedSymUtil()
{
  return OdEdSymbolUtilities::servicesPtr();
}

#include "TD_PackPop.h"

