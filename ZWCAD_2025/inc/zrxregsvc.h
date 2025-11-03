
#ifndef   _ZRXREGSVC_H
#define   _ZRXREGSVC_H 1

#include "zrxdlinkr.h"
#include "zadesk.h"
#include "zacarray.h"

#pragma pack (push, 8)

bool zcrxLoadModule(const ZTCHAR * moduleName, bool printit, bool asCmd=false);

bool zcrxLoadApp(const ZTCHAR * appname, bool asCmd=false);

bool zcrxUnloadModule(const ZTCHAR * moduleName, bool asCmd=false);

bool zcrxUnloadApp(const ZTCHAR * appName, bool asCmd=false);

const ZTCHAR * zcrxProductKey(); 

ZCBASE_PORT ZcArray<wchar_t *> * zcrxLoadedApps();

ZCBASE_PORT bool zcrxLoadAutoloadApps(const ZTCHAR * appname);

ZCBASE_PORT bool zcrxUnloadAutoloadApps(const ZTCHAR * appname);

ZCBASE_PORT bool zcrxAppIsLoaded(const ZTCHAR  *pAppName);

const ZTCHAR * zcrxObjectDBXRegistryKey();

ZSoft::UInt32 zcrxProductLCID(); 

class ZcLocale;

ZCBASE_PORT ZcLocale zcrxProductLocale();

ZCBASE_PORT
ZcadApp::ErrorStatus zcrxRegisterApp(ZcadApp::LoadReasons alr,
        const ZTCHAR  *logicalName);

ZCBASE_PORT
ZcadApp::ErrorStatus zcrxUnregisterApp(const ZTCHAR  *logicalname);

void * zcrxGetServiceSymbolAddr(const ZTCHAR * serviceName, const ZTCHAR * symbol);

void* zcrxRegisterService(const ZTCHAR * serviceName);

ZCBASE_PORT ZcRxService* zcrxRegisterService(const ZTCHAR* serviceName, ZcRxService* pSvc);

bool zcrxServiceIsRegistered(const ZTCHAR * serviceName);

bool zcrxUnlockApplication(void* appId);

bool zcrxApplicationIsLocked(const ZTCHAR * modulename);

bool zcrxLockApplication(void* appId);

bool zcrxIsAppMDIAware(const ZTCHAR  * moduleName);

bool zcrxRegisterAppMDIAware(void* appId);

bool zcrxRegisterAppNotMDIAware(void* appId);

#pragma pack (pop)
#endif
