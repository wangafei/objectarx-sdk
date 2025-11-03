/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////




// DynamicLinker.h: interface for the OdaDynamicLinkerI class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_ODADYNAMICLINKERI_H_INCLUDED_)
#define _ODADYNAMICLINKERI_H_INCLUDED_

#include "StringArray.h"

class OdRxDLinkerReactor;
class OdRxService;
class OdRxDictionary;
typedef OdSmartPtr<OdRxDictionary> OdRxDictionaryPtr;
class OdRxModule;
typedef OdSmartPtr<OdRxModule> OdRxModulePtr;
class OdRxSystemServices;
typedef OdSmartPtr<OdRxSystemServices> OdRxSystemServicesPtr;

#include "TD_PackPush.h"
#include "LoadReasons.h"

/** Description:
    This class implements Dynamic Linker services for Teigha Xtension(TX) applications:
    
    The following services are implemented:
    
    o  Loading applications by specified by application name.
    
    o  Loading and unloading modules specified by filename.
    
    o  Addition and removal of reactors from the dynamic linker reactor chain.
    
    
    Note:
    There is exactly one OdRxDynamicLinker class object. It is gloval to Teigha,
    and thus is non-instantiable for Teigha applications.
    
    A pointer to the OdRxDynamicLinker object will be returned by the
    global odrxDynamicLinker() function.

    {group:OdRx_Classes} 
*/
class FIRSTDLL_EXPORT OdRxDynamicLinker : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdRxDynamicLinker);

  /** Description:
    Adds the specified reactor to the dynamic linker reactor chain.
    Arguments:
    pReactor (I) Pointer to the reactor.
  */
  virtual void addReactor (
    OdRxDLinkerReactor* pReactor) = 0;

  /** Description:
    Removes the specified reactor to the dynamic linker reactor chain.
    Arguments:
    pReactor (I) Pointer to the reactor.
  */
  virtual void removeReactor (
    OdRxDLinkerReactor* pReactor) = 0;

  virtual bool isApplicationLocked(const OdChar* modulename) const
  {
    throw OdError(OdResult::eNotImplemented);
    return false; 
  }
  
  virtual bool isAppMDIAware(const OdChar* modulename) const
  {
    throw OdError(OdResult::eNotImplemented);
    return false; 
  }

  virtual bool isAppBusy(const OdChar* modulename) const
  {
    throw OdError(OdResult::eNotImplemented);
    return false; 
  }
  virtual void setAppBusy(const OdChar* modulename, bool bBusyFlag) const
  {
    throw OdError(OdResult::eNotImplemented);
  }

  /** Description:
    Loads the specified abstract (platform-independent) module.
    
    Remarks:
    Returns a SmartPointer to the abstract module object.
    
    Arguments:
    moduleFileName (I) Module filename to load.
    silent (I) If true, no load status message will be printed.
	asCmd (I) If asCmd is kTrue, loading can happen only once. A second attempt to load will return kFalse. 
  */
  virtual OdRxModulePtr loadModule(
    const OdString& moduleFileName, bool silent = true,bool asCmd = false) = 0;

  /** Description:
    Unoads the specified abstract (platform-independent) module.
    
    Arguments:
    moduleFileName (I) Module filename to unload.
	asCmd (I) If asCmd is kTrue, loading can happen only once. A second attempt to load will return kFalse. 
  */
  virtual bool unloadModule(
    const OdString& moduleFileName,bool asCmd = false) = 0;

	virtual const OdChar* ProductKey() const = 0;
	virtual OdUInt32 ProductLcid() const = 0;

  virtual bool unloadApp(const OdChar* appName, bool asCmd = false)
  {
    throw OdError(OdResult::eNotImplemented);
    return false; 
  }

  /** Description:
    Unoads all unreferenced modules.
  */
  virtual bool unloadUnreferenced() = 0;

  /** Description:
    Maps the specfied application name to the a module filename,
    and loads that module.

    Arguments:
    applicationName (I) TX application name.
    silent (I) If and only if true, no load status message will be printed.
  */
  virtual OdRxModulePtr loadApp(
    const OdString& applicationName,
    bool silent = true) = 0;

  virtual bool loadApp(const OdChar* appName,
    OdaApp::LoadReasons al,
    bool printit,
    bool asCmd = false)
  {
    throw OdError(OdResult::eNotImplemented);
    return false; 
  }

  /** Description:
    Returns a SmartPointer to the OdDbSystemServices instance that is used for file creation and access.
    
    See also:
    odInitialize
  */
  virtual OdRxSystemServicesPtr sysServices() const = 0;

	virtual OdRxObject* registerService (
    const OdChar * serviceName,
    OdRxService* serviceObj) = 0;

	virtual void* getSymbolAddress(
    const OdChar* serviceName, 
    const OdChar* symbol) const = 0;

  virtual bool initListedModules(const OdChar* fileName)
  {
    throw OdError(OdResult::eNotImplemented);
    return false; 
  }

  /** Description:
    Returns a SmartPointer to the OdRxDictionary instance that created by OdInitialize.
  */
  virtual OdRxDictionaryPtr sysRegistry() const = 0;

  /** Description:
    Special internal method - used for non-standard module loading only
  */
  /** { Secret } */
  virtual OdRxModule* loadModuleObj(
    OdRxModule* pModuleObj, 
    bool bSilent = true) = 0;

  void lockApplication(void *pkt);
  void unlockApplication(void *pkt);
  void registerAppMDIAware(void *pkt);
  void registerAppNotMDIAware(void *pkt);

  /** Description:
    Returns the count of loaded modules.
  */
  virtual int getModuleCount() const = 0;

  /** Description:
    Returns the specified abstract (platform-independent) module.
  */
  virtual OdRxModulePtr getModule(
    int index,
    OdString& key) const = 0;

  /** Description:
    Returns the specified abstract (platform-independent) module.
  */
  virtual OdRxModulePtr getModule(
    const OdString& key) const = 0;

  virtual void getLoadedApps(OdStringArray& res) = 0;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdRxDynamicLinker pointers.
*/
typedef OdSmartPtr<OdRxDynamicLinker> OdRxDynamicLinkerPtr;


/** Description:
    Returns the Teigha global dynamic linker.
*/
FIRSTDLL_EXPORT OdRxDynamicLinker* odrxDynamicLinker();

FIRSTDLL_EXPORT const OdChar* odrxObjectDBXRegistryKey();

FIRSTDLL_EXPORT bool odrxLoadModule(const OdChar * moduleName, bool printit, bool asCmd=false);
FIRSTDLL_EXPORT bool odrxUnloadModule(const OdChar* moduleName,bool asCmd = false);

FIRSTDLL_EXPORT bool odrxLoadApp(const OdChar* appname, bool asCmd = false);
FIRSTDLL_EXPORT bool odrxAppIsLoaded(const OdChar* appname);
FIRSTDLL_EXPORT bool odrxUnloadApp(const OdChar* appname, bool asCmd = false);
FIRSTDLL_EXPORT OdArray<wchar_t *>* odrxLoadedApps();
FIRSTDLL_EXPORT OdString odrxModuleName(const OdString& appname);

FIRSTDLL_EXPORT bool odrxLockApplication(void* appId);
FIRSTDLL_EXPORT bool odrxApplicationIsLocked(const OdChar* modulename);
FIRSTDLL_EXPORT bool odrxUnlockApplication(void* appId);

FIRSTDLL_EXPORT void* odrxRegisterService(const OdChar* serviceName);
FIRSTDLL_EXPORT void* odrxGetServiceSymbolAddr(const OdChar* serviceName, const OdChar* symbol);
FIRSTDLL_EXPORT bool  odrxServiceIsRegistered(const OdChar * serviceName);

#include "TD_PackPop.h"

#endif // !defined(_ODADYNAMICLINKERI_H_INCLUDED_)

