#pragma once
#include "OdaCommon.h"
#include "rxdlinkr.h"

TOOLKIT_EXPORT const OdChar* gcrxProductKey();
unsigned long gcrxProductLCID();

GcadApp::ErrorStatus gcrxRegisterApp(GcadApp::LoadReasons alr,  const OdChar *logicalName,bool bDwgU = false);
GcadApp::ErrorStatus gcrxUnregisterApp(const OdChar *logicalname, bool bDwgU = false);

FIRSTDLL_EXPORT bool odrxRegisterAppMDIAware(void* appId);
FIRSTDLL_EXPORT bool odrxIsAppMDIAware(const OdChar * moduleName);
FIRSTDLL_EXPORT bool odrxRegisterAppNotMDIAware(void* appId);

#define	gcrxLoadModule	odrxLoadModule
#define	gcrxLoadApp	odrxLoadApp
#define	gcrxUnloadModule	odrxUnloadModule
#define	gcrxUnloadApp	odrxUnloadApp
		
#define	gcrxLoadedApps	odrxLoadedApps
#define	gcrxAppIsLoaded	odrxAppIsLoaded

#define	gcrxGetServiceSymbolAddr	odrxGetServiceSymbolAddr
#define	gcrxRegisterService	odrxRegisterService
#define	gcrxServiceIsRegistered	odrxServiceIsRegistered

#define	gcrxUnlockApplication	odrxUnlockApplication
#define	gcrxApplicationIsLocked	odrxApplicationIsLocked
#define	gcrxLockApplication	odrxLockApplication

#define gcrxRegisterAppMDIAware odrxRegisterAppMDIAware
#define gcrxIsAppMDIAware odrxIsAppMDIAware	
#define gcrxRegisterAppNotMDIAwareodrxRegisterAppNotMDIAware	

#define gcrxObjectDBXRegistryKey odrxObjectDBXRegistryKey