/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _RXREGSVC_H
#define   _RXREGSVC_H 1

#include "gccoredefs.h"
#include "rxdlinkr.h"
#include "gsoft.h"
#include "gcarray.h"

#pragma pack (push, 8)

GCBASE_PORT bool gcrxLoadModule(const GCHAR * moduleName, bool printit, bool asCmd = false);
GCCORE_PORT bool gcrxLoadApp(const GCHAR * appname, bool asCmd = false);
GCBASE_PORT bool gcrxUnloadModule(const GCHAR * moduleName, bool asCmd = false);
GCBASE_PORT bool gcrxUnloadApp(const GCHAR * appName, bool asCmd = false);

GCBASE_PORT GcArray<wchar_t *> * gcrxLoadedApps();

GCCORE_PORT bool gcrxLoadAutoloadApps(const GCHAR * appname);
GCCORE_PORT bool gcrxUnloadAutoloadApps(const GCHAR * appname);
GCBASE_PORT bool gcrxAppIsLoaded(const GCHAR  *pAppName);

GCCORE_PORT const GCHAR * gcrxObjectDBXRegistryKey();

class GcLocale;
GCCORE_PORT GcLocale gcrxProductLocale();

GCCORE_PORT GcadApp::ErrorStatus gcrxRegisterApp(GcadApp::LoadReasons alr, const GCHAR  *logicalName);
GCCORE_PORT GcadApp::ErrorStatus gcrxUnregisterApp(const GCHAR  *logicalname);

GCBASE_PORT void *       gcrxGetServiceSymbolAddr(const GCHAR * serviceName, const GCHAR * symbol);
GCBASE_PORT void *       gcrxRegisterService(const GCHAR * serviceName);
GCBASE_PORT GcRxService* gcrxRegisterService(const GCHAR* serviceName, GcRxService* pSvc);
GCBASE_PORT bool         gcrxServiceIsRegistered(const GCHAR * serviceName);

GCBASE_PORT bool gcrxUnlockApplication(void* appId);
GCBASE_PORT bool gcrxApplicationIsLocked(const GCHAR * modulename);
GCBASE_PORT bool gcrxLockApplication(void* appId);
GCCORE_PORT bool gcrxIsAppMDIAware(const GCHAR  * moduleName);
GCCORE_PORT bool gcrxRegisterAppMDIAware(void* appId);
GCCORE_PORT bool gcrxRegisterAppNotMDIAware(void* appId);

#pragma pack (pop)
#endif
