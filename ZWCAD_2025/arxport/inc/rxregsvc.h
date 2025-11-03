
#ifndef __RXREGSVC_H__
#define __RXREGSVC_H__

#include "rxdlinkr.h"
#include "adesk.h"
#include "acarray.h"
#include "PAL/api/AcLocale.h"

#include "../../inc/zrxregsvc.h"

#ifndef acrxProductLocale
#define acrxProductLocale	zcrxProductLocale
#endif //#ifndef acrxProductLocale   

#ifndef AcArray
#define AcArray	ZcArray
#endif //#ifndef AcArray   

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT		ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT

#ifndef acrxLoadAutoloadApps
#define acrxLoadAutoloadApps		zcrxLoadAutoloadApps
#endif //#ifndef acrxLoadAutoloadApps

#ifndef acrxUnloadAutoloadApps
#define acrxUnloadAutoloadApps		zcrxUnloadAutoloadApps
#endif //#ifndef acrxUnloadAutoloadApps

#ifndef AcLocale
#define AcLocale		ZcLocale
#endif //#ifndef AcLocale

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ADESK_STDCALL
#define ADESK_STDCALL		ZSOFT_STDCALL
#endif //#ifndef ADESK_STDCALL

#ifndef AcadApp
#define AcadApp		ZcadApp
#endif //#ifndef AcadApp

#ifndef acrxAppIsLoaded
#define acrxAppIsLoaded		zcrxAppIsLoaded
#endif //#ifndef acrxAppIsLoaded

#ifndef acrxApplicationIsLocked
#define acrxApplicationIsLocked		zcrxApplicationIsLocked
#endif //#ifndef acrxApplicationIsLocked

#ifndef acrxGetServiceSymbolAddr
#define acrxGetServiceSymbolAddr		zcrxGetServiceSymbolAddr
#endif //#ifndef acrxGetServiceSymbolAddr

#ifndef acrxIsAppMDIAware
#define acrxIsAppMDIAware		zcrxIsAppMDIAware
#endif //#ifndef acrxIsAppMDIAware

#ifndef acrxLoadApp
#define acrxLoadApp		zcrxLoadApp
#endif //#ifndef acrxLoadApp

#ifndef acrxLoadModule
#define acrxLoadModule		zcrxLoadModule
#endif //#ifndef acrxLoadModule

#ifndef acrxLoadedApps
#define acrxLoadedApps		zcrxLoadedApps
#endif //#ifndef acrxLoadedApps

#ifndef acrxLockApplication
#define acrxLockApplication		zcrxLockApplication
#endif //#ifndef acrxLockApplication

#ifndef acrxObjectDBXRegistryKey
#define acrxObjectDBXRegistryKey		zcrxObjectDBXRegistryKey
#endif //#ifndef acrxObjectDBXRegistryKey

#ifndef acrxProductKey
#define acrxProductKey		zcrxProductKey
#endif //#ifndef acrxProductKey

#ifndef acrxProductLCID
#define acrxProductLCID		zcrxProductLCID
#endif //#ifndef acrxProductLCID

#ifndef acrxRegisterApp
#define acrxRegisterApp		zcrxRegisterApp
#endif //#ifndef acrxRegisterApp

#ifndef acrxRegisterAppMDIAware
#define acrxRegisterAppMDIAware		zcrxRegisterAppMDIAware
#endif //#ifndef acrxRegisterAppMDIAware

#ifndef acrxRegisterAppNotMDIAware
#define acrxRegisterAppNotMDIAware		zcrxRegisterAppNotMDIAware
#endif //#ifndef acrxRegisterAppNotMDIAware

#ifndef acrxRegisterService
#define acrxRegisterService		zcrxRegisterService
#endif //#ifndef acrxRegisterService

#ifndef acrxServiceIsRegistered
#define acrxServiceIsRegistered		zcrxServiceIsRegistered
#endif //#ifndef acrxServiceIsRegistered

#ifndef acrxUnloadApp
#define acrxUnloadApp		zcrxUnloadApp
#endif //#ifndef acrxUnloadApp

#ifndef acrxUnloadModule
#define acrxUnloadModule		zcrxUnloadModule
#endif //#ifndef acrxUnloadModule

#ifndef acrxUnlockApplication
#define acrxUnlockApplication		zcrxUnlockApplication
#endif //#ifndef acrxUnlockApplication

#ifndef acrxUnregisterApp
#define acrxUnregisterApp		zcrxUnregisterApp
#endif //#ifndef acrxUnregisterApp

#endif //#ifndef __RXREGSVC_H__
