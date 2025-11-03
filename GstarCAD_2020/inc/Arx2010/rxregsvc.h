#pragma once

#define acrxLoadModule                            gcrxLoadModule
#define gcrxLoadModule                            odrxLoadModule
#define acrxLoadApp                               gcrxLoadApp
#define gcrxLoadApp                               odrxLoadApp
#define acrxUnloadModule                          gcrxUnloadModule
#define gcrxUnloadModule                          odrxUnloadModule
#define acrxUnloadApp                             gcrxUnloadApp
#define gcrxUnloadApp                             odrxUnloadApp
  
#define acrxLoadedApps                            gcrxLoadedApps
#define gcrxLoadedApps                            odrxLoadedApps
#define acrxAppIsLoaded                           gcrxAppIsLoaded
#define gcrxAppIsLoaded                           odrxAppIsLoaded
    
#define acrxRegisterApp                           gcrxRegisterApp
#define acrxUnregisterApp                         gcrxUnregisterApp

#define acrxGetServiceSymbolAddr                  gcrxGetServiceSymbolAddr
#define gcrxGetServiceSymbolAddr                  odrxGetServiceSymbolAddr
#define acrxRegisterService                       gcrxRegisterService
#define gcrxRegisterService                       odrxRegisterService
#define acrxServiceIsRegistered                   gcrxServiceIsRegistered
#define gcrxServiceIsRegistered                   odrxServiceIsRegistered

#define acrxUnlockApplication                     gcrxUnlockApplication
#define gcrxUnlockApplication                     odrxUnlockApplication
#define acrxApplicationIsLocked                   gcrxApplicationIsLocked
#define gcrxApplicationIsLocked                   odrxApplicationIsLocked
#define acrxLockApplication                       gcrxLockApplication
#define gcrxLockApplication                       odrxLockApplication

#define acrxRegisterAppMDIAware                   gcrxRegisterAppMDIAware
#define gcrxRegisterAppMDIAware                   odrxRegisterAppMDIAware
#define acrxIsAppMDIAware                         gcrxIsAppMDIAware
#define gcrxIsAppMDIAware                         odrxIsAppMDIAware
#define acrxRegisterAppNotMDIAware                gcrxRegisterAppNotMDIAware
#define gcrxRegisterAppNotMDIAware                odrxRegisterAppNotMDIAware

#define acrxObjectDBXRegistryKey                  gcrxObjectDBXRegistryKey
#define acrxProductKey                            gcrxProductKey
#define acrxProductLCID                           gcrxProductLCID


#include "rxdlinkr.h"
#include "adesk.h"
#include "../rxregsvc.h"
#include "../DynamicLinker.h"
