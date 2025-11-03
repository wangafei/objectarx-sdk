/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _rxdlinkr_h
#define _rxdlinkr_h 1

class GcRxDLinkerReactor;
class GcRxService;
class GcLocale;

#include "rxobject.h"
#include "GdGChar.h"

#pragma pack (push, 8)

struct GcadApp
{
  enum LoadReasons
  {
    kOnProxyDetection      = 0x01,
    kOnGscadStartup        = 0x02,
    kOnCommandInvocation   = 0x04,
    kOnLoadRequest         = 0x08,
    kLoadDisabled          = 0x10,
    kTransparentlyLoadable = 0x20,
    kOnIdleLoad            = 0x40
  };

  enum ErrorStatus
  {
    eOk              = 0,
    eInvalidKey      = 1,
    eInvalidSubKey   = 2,
    eKeyNotFound     = 3,
    eOutOfMemory     = 4,
    eInvalidValue    = 5,
    eValueNotFound   = 6,
    eKeyExists       = 7,
    eRegAccessDenied = 8,
    eRejected        = 9,
    eUnknownError    = 10
  };
};

class GCBASE_PORT GcRxDynamicLinker : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcRxDynamicLinker);

  virtual void*       getSymbolAddress(const GCHAR * serviceName, const char * symbol) const = 0;
  virtual void*       getSymbolAddress(const GCHAR * serviceName, const GCHAR * symbol) const = 0;

  virtual bool        initListedModules(const GCHAR * fileName) = 0;
  virtual bool        loadModule(const GCHAR * fileName, bool printit, bool asCmd = false) = 0;
  virtual bool        loadApp(const GCHAR  * appName, GcadApp::LoadReasons al, bool printit, bool asCmd = false) = 0;

  virtual GcRxObject* registerService(const GCHAR * serviceName, GcRxService* serviceObj) = 0;

  virtual bool        unloadModule(const GCHAR * fileName, bool asCmd = false) = 0;
  virtual bool        unloadApp(const GCHAR * appName, bool asCmd = false) = 0;

  virtual void        addReactor(GcRxDLinkerReactor* newReactor) = 0;
  virtual void        removeReactor(GcRxDLinkerReactor* oldReactor) = 0;

  virtual bool        isApplicationLocked(const GCHAR * modulename) const = 0;
  virtual bool        lockApplication(void* appId) const = 0;
  virtual bool        unlockApplication(void* appId) const = 0;

  virtual bool        isAppMDIAware(const GCHAR * modulename) const = 0;
  virtual bool        registerAppMDIAware(void* appId) const = 0;
  virtual bool        registerAppNotMDIAware(void* appId) const = 0;

  virtual bool        isAppBusy(const GCHAR * modulename) const = 0;
  virtual void        setAppBusy(const GCHAR * modulename, bool bBusyFlag) const = 0;

  virtual GcLocale    ProductLocale() const = 0;

  virtual GcadApp::ErrorStatus registerApp(GcadApp::LoadReasons alr, const GCHAR  *logicalName, void* entryPoint = nullptr) = 0;
  virtual GcadApp::ErrorStatus unregisterApp(const GCHAR  *logicalName) = 0;
};

#define gcrxDynamicLinker                                               \
GcRxDynamicLinker::cast(gcrxSysRegistry()->at(GCRX_DYNAMIC_LINKER))

class GCBASE_PORT GcRxDLinkerReactor : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcRxDLinkerReactor);
  virtual void rxAppWillBeLoaded(const GCHAR  * moduleName);
  virtual void rxAppLoaded(const GCHAR  * moduleName);
  virtual void rxAppLoadAborted(const GCHAR  * moduleName);

  virtual void rxAppWillBeUnloaded(const GCHAR  * moduleName);
  virtual void rxAppUnloaded(const GCHAR  * moduleName);
  virtual void rxAppUnloadAborted(const GCHAR  * moduleName);
};

#pragma pack (pop)
#endif
