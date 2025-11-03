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


#ifndef _OD_RXDYNAMICMODULE_H_
#define _OD_RXDYNAMICMODULE_H_

#include "RxModule.h"
#include "TDVersion.h"
#include "OdString.h"

#include "TD_PackPush.h"

/** Description:
    This class manages Static RxModules.
    Remarks:
    {group:OdRx_Classes} 
*/
template<class T, class TInterface = T>
class OdRxStaticModule : public T
{
  ODRX_HEAP_OPERATORS();

  long      m_nLockCount;
  OdString  m_sName;

  OdRxStaticModule(const OdString& sName)
    : m_nLockCount(0)
    , m_sName(sName)
  { }
  void addRef() 
  { 
    ++m_nLockCount; 
  }
  void release() 
  { 
    ODA_ASSERT(m_nLockCount); 
    --m_nLockCount; 
  }
  long numRefs() const { return m_nLockCount; }
public:
  /** Description:
    Returns the system data for this Static RxModule object.
    Remarks:
    The default implementation does nothing but return a null pointer.
  */
  void* sysData() { return 0; }
  
  /** Description:
    Creates a new Static RxModule with the specified *name*.
    Arguments:
    name (I) Module *name*.
    Remarks:
    Returns a pointer to the new object.
  */
  static OdRxModule* createModule(const OdString& name)
  {
    return new OdRxStaticModule(name);
  }

  /** Description:
    Deletes this Static RxModule object.
  */
  void deleteModule() { delete this; }

  /** Description:
    Returns the *name* of this RxStaticModule object.
  */
  OdString moduleName() const { return m_sName; }
};

typedef OdRxModule* (*StaticModuleEntryPoint)(const OdString& szModuleName);

#define ODRX_STATIC_MODULE_ENTRY_POINT(_UserModuleClass) odrxCreateModuleObject_For_##_UserModuleClass

/** Description:
    This macro is used to create an entry point function for a custom application which 
    are linked in statically to a Teigha client application.
*/
#define ODRX_DECLARE_STATIC_MODULE_ENTRY_POINT(_UserModuleClass) \
OdRxModule* ODRX_STATIC_MODULE_ENTRY_POINT(_UserModuleClass)(const OdString& szModuleName)

/** Description:
  {group:Structs}
*/      
struct STATIC_MODULE_DESC
{
  const wchar_t*           szAppName;
  StaticModuleEntryPoint  entryPoint;
};

/** Description: 
    Defines the start of the static module map, which contains entries for all
    custom Teigha modules that are linked in statically to a Teigha client
    application.
*/
#define ODRX_BEGIN_STATIC_MODULE_MAP() \
STATIC_MODULE_DESC g_ODRX_STATIC_MODULE_MAP[] = {

/** Description: 
    defines the entry in the static module map, which contains entries for all
    custom Teigha modules that are linked in statically to a Teigha client
    application.

    Arguments:
    AppName (I) Registered application name, that can be later passed to 
      OdRxDynamicLinker::loadModule to load the static application.
    ModuleClassName (I) Name of the C++ class derived from OdRxModule, that 
      implements support for this module.
*/
#define ODRX_DEFINE_STATIC_APPLICATION(AppName, ModuleClassName) \
{ AppName, ODRX_STATIC_MODULE_ENTRY_POINT(ModuleClassName) },

/** Description: 
*/
#define ODRX_DEFINE_STATIC_APPMODULE(moduleName, ModuleClassName) \
ODRX_DEFINE_STATIC_APPLICATION(moduleName, ModuleClassName)

/** Description: 
    Defines the end of the static module map, which contains entries for all
    custom Teigha modules that are linked in statically to a Teigha client
    application.
*/
#define ODRX_END_STATIC_MODULE_MAP() \
{ 0, 0 } };

FIRSTDLL_EXPORT void odrxInitStaticModuleMap(STATIC_MODULE_DESC* pMap);

#define ODRX_INIT_STATIC_MODULE_MAP() odrxInitStaticModuleMap(g_ODRX_STATIC_MODULE_MAP)



#define ODRX_DEFINE_STATIC_MODULE(_UserModuleClass)\
ODRX_DECLARE_STATIC_MODULE_ENTRY_POINT(_UserModuleClass)\
{\
  return OdRxStaticModule<_UserModuleClass >::createModule(szModuleName);\
}



#if defined(_TOOLKIT_IN_DLL_) && !defined(__MWERKS__) ////////////////////////////////////////////////////////////////////////////////

//IR.111706. MacOS X dynamic library loading.
#if defined(__GNUC__) && defined(__APPLE__) // GNU compiler MacOS X

#define ODRX_STATIC_MODULE_PATH "{5CEAD1EF-4D33-48fe-99E4-E09176BCF088}/"

#define ODRX_STATIC_APP_MODULE_NAME(AppName) (OdString(ODRX_STATIC_MODULE_PATH) + AppName + DEFAULT_MODULE_EXTENSION_DOT_W)

void deleteModuleObject();

/** Description:
This class manages Mac Rx modules.
{group:OdRx_Classes} 
*/
template<class T, class TInterface = T>
class OdRxMacModule : public T
{
  long    m_nLockCount;
  void *m_hModule;
  const OdString m_name;

  OdRxMacModule(void *hModule, const OdString name)
    : m_nLockCount(0)
    , m_hModule(hModule)
    , m_name(name)
  {}
  void addRef() 
  { 
    ++m_nLockCount; 
  }
  void release() 
  { 
    ODA_ASSERT(m_nLockCount); 
    --m_nLockCount; 
  }
  long numRefs() const { return m_nLockCount; }
  ODRX_HEAP_OPERATORS();
public:
  /** Description:
  Returns the system data for this Win32 RxModule object.
  */
  void* sysData() { return m_hModule; }

  /** Description:
  Creates a new Mac RxModule with the specified *name*.
  Arguments:
  hModule (I) Module handle.
  Remarks:
  Returns a pointer to the new object.
  */
  static OdRxMacModule* createModule(void *hModule, const OdString name) 
  { 
    return new OdRxMacModule(hModule, name); 
  }

  void deleteModule()
  {
    deleteModuleObject();
    delete this;
  }

  /** Description:
  Returns the *name* of this RxStaticModule object.
  */
  OdString moduleName() const
  {
    return m_name;
  }
};

/** Description:
Creates the entry point function for a Teigha custom application.
*/
#define ODRX_DEFINE_DYNAMIC_MODULE(_UserModuleClass)\
  static OdRxModule* g_pSingletonModule = 0;\
  extern "C" { \
  __attribute__ ((visibility("default"))) \
  OdRxModule* odrxCreateModuleObject(void *hModule, OdChar *name)\
{\
  if(!g_pSingletonModule)\
{\
  g_pSingletonModule = OdRxMacModule<_UserModuleClass >::createModule(hModule, name);\
  hModule = NULL;\
}\
  return g_pSingletonModule;\
}\
  void odrxGetAPIVersion(int& nMajorVersion, int& nMinorVersion,\
  int& nMajorBuildVersion, int& nMinorBuildVersion)\
{\
  nMajorVersion       = TD_MAJOR_VERSION;\
  nMinorVersion       = TD_MINOR_VERSION;\
  nMajorBuildVersion  = TD_MAJOR_BUILD;\
  nMinorBuildVersion  = TD_MINOR_BUILD;\
}\
}\
  void deleteModuleObject()\
{\
  g_pSingletonModule = NULL;\
}

#elif defined(__GNUC__)

#define ODRX_STATIC_MODULE_PATH "{5CEAD1EF-4D33-48fe-99E4-E09176BCF088}/"

#define ODRX_STATIC_APP_MODULE_NAME(AppName) (OdString(ODRX_STATIC_MODULE_PATH) + AppName + DEFAULT_MODULE_EXTENSION_DOT_W)

void deleteModuleObject();

/** Description:
This class manages Unix Rx modules.
{group:OdRx_Classes} 
*/
template<class T, class TInterface = T>
class OdRxUnixModule : public T
{
  long    m_nLockCount;
  void *m_hModule;
  const OdString m_name;
protected:
  OdRxUnixModule(void *hModule, const OdString name)
    : m_nLockCount(0)
    , m_hModule(hModule)
    , m_name(name)
  {}
private:
  void addRef() 
  { 
    ++m_nLockCount; 
  }
  void release() 
  { 
    ODA_ASSERT(m_nLockCount); 
    --m_nLockCount; 
  }
  long numRefs() const { return m_nLockCount; }
  ODRX_HEAP_OPERATORS();
public:
  /** Description:
  Returns the system data for this Unix RxModule object.
  */
  void* sysData() { return m_hModule; }
  
  /** Description:
  Creates a new Mac RxModule with the specified *name*.
  Arguments:
  hModule (I) Module handle.
  Remarks:
  Returns a pointer to the new object.
  */
  static OdRxUnixModule* createModule(void *hModule, const OdString name) 
  { 
    return new OdRxUnixModule(hModule, name); 
  }

  void deleteModule()
  {
    deleteModuleObject();
    delete this;
  }

  /** Description:
  Returns the *name* of this RxStaticModule object.
  */
  OdString moduleName() const
  {
    return m_name;
  }
};

/** Description:
Creates the entry point function for a Teigha custom application.
*/

#define ODRX_DEFINE_DYNAMIC_MODULE(_UserModuleClass)\
  static OdRxModule* g_pSingletonModule = 0;\
\
class OdRxUnixModule##_UserModuleClass : public OdRxUnixModule<_UserModuleClass>\
{\
  ODRX_HEAP_OPERATORS();\
  OdRxUnixModule##_UserModuleClass(void *hModule, const OdString name)\
    : OdRxUnixModule<_UserModuleClass>(hModule, name)\
  {\
  }\
public:\
  static _UserModuleClass* createModule(void *hModule, const OdString name) \
  { \
    return new OdRxUnixModule##_UserModuleClass(hModule, name);\
  }\
\
  virtual void deleteModule()\
  {\
    g_pSingletonModule = 0;\
    delete this;\
  }\
};\
\
  extern "C" { \
  __attribute__ ((visibility("default"))) \
  OdRxModule* odrxCreateModuleObject(void *hModule, OdChar *name)\
{\
  if(!g_pSingletonModule)\
{\
  g_pSingletonModule = OdRxUnixModule##_UserModuleClass::createModule(hModule, name);\
  hModule = NULL;\
}\
  return g_pSingletonModule;\
}\
  __attribute__ ((visibility("default"))) \
  void odrxGetAPIVersion(int& nMajorVersion, int& nMinorVersion,\
  int& nMajorBuildVersion, int& nMinorBuildVersion)\
{\
  nMajorVersion       = TD_MAJOR_VERSION;\
  nMinorVersion       = TD_MINOR_VERSION;\
  nMajorBuildVersion  = TD_MAJOR_BUILD;\
  nMinorBuildVersion  = TD_MINOR_BUILD;\
}\
}\
  void deleteModuleObject()\
{\
  g_pSingletonModule = NULL;\
}\

#else //defined(__GNUC__)

#define ODRX_STATIC_MODULE_PATH "{5CEAD1EF-4D33-48fe-99E4-E09176BCF088}/"

#define ODRX_STATIC_APP_MODULE_NAME(AppName) (OdString(ODRX_STATIC_MODULE_PATH) + AppName + DEFAULT_MODULE_EXTENSION_DOT_W)

#ifdef __BORLANDC__
/** Description:
	This class manages Win32 Rx modules.
	{group:OdRx_Classes}
*/
template<class T, class TInterface = T>
class OdRxWin32Module : public T
{
  long    m_nLockCount;
  HMODULE m_hModule;
  const OdString m_sModuleName;
  OdRxWin32Module() : m_nLockCount(0) { }
  void addRef()
  {
	++m_nLockCount;
  }
  void release()
  {
	ODA_ASSERT(m_nLockCount);
	--m_nLockCount;
  }
  long numRefs() const { return m_nLockCount; }
  OdRxWin32Module(HMODULE hModule , const OdString name )
	: m_nLockCount(0)
	, m_hModule(hModule)
	, m_sModuleName(name)
  {}
  ODRX_HEAP_OPERATORS();
public:
  /** Description:
	Returns the system data for this Win32 RxModule object.
  */
  void* sysData() { return reinterpret_cast<void*>(m_hModule); }

  /** Description:
	Creates a new Win32 RxModule with the specified *name*.
	Arguments:
	hModule (I) Module handle.
	Remarks:
	Returns a pointer to the new object.
  */
  static OdRxWin32Module* createModule(HMODULE hModule, const OdString name ) { return new OdRxWin32Module(hModule,name); }

  void deleteModule()
  {
	g_pSingletonModule = 0;
	delete this;
  }

  /** Description:
	Returns the *name* of this RxStaticModule object.
  */
  OdString moduleName() const
  {
	return m_sModuleName;
  }
};

/** Description:
    Creates the entry point function for a Teigha custom application.
*/
#define ODRX_DEFINE_DYNAMIC_MODULE(_UserModuleClass)\
static OdRxModule* g_pSingletonModule = 0;\
  extern "C" {\
__declspec(dllexport) OdRxModule* odrxCreateModuleObject(HMODULE& hModule, const OdChar *name)\
{\
  if(!g_pSingletonModule)\
  {\
    g_pSingletonModule = OdRxWin32Module<_UserModuleClass >::createModule(hModule, name);\
    hModule = 0;\
  }\
  return g_pSingletonModule;\
}\
__declspec(dllexport) void odrxGetAPIVersion(int& nMajorVersion, int& nMinorVersion,\
                                             int& nMajorBuildVersion, int& nMinorBuildVersion)\
{\
  nMajorVersion       = TD_MAJOR_VERSION;\
  nMinorVersion       = TD_MINOR_VERSION;\
  nMajorBuildVersion  = TD_MAJOR_BUILD;\
  nMinorBuildVersion  = TD_MINOR_BUILD;\
}\
}\

#else //__BORLANDC__

/** Description:
	This class manages Win32 Rx modules.
	{group:OdRx_Classes}
*/
template<class T, class TInterface = T>
class OdRxWin32Module : public T
{
  long    m_nLockCount;
  HMODULE m_hModule;
  OdRxWin32Module() : m_nLockCount(0) { }
  void addRef()
  {
	++m_nLockCount;
  }
  void release()
  {
	ODA_ASSERT(m_nLockCount);
	--m_nLockCount;
  }
  long numRefs() const { return m_nLockCount; }
  OdRxWin32Module(HMODULE hModule )
	: m_nLockCount(0)
	, m_hModule(hModule)
  {}
  ODRX_HEAP_OPERATORS();
public:
  /** Description:
	Returns the system data for this Win32 RxModule object.
  */
  void* sysData() { return reinterpret_cast<void*>(m_hModule); }

  /** Description:
	Creates a new Win32 RxModule with the specified *name*.
    Arguments:
    hModule (I) Module handle.
    Remarks:
	Returns a pointer to the new object.
  */
  static OdRxWin32Module* createModule(HMODULE hModule) { return new OdRxWin32Module(hModule); }

  void deleteModule()
  {
    g_pSingletonModule = 0;
    delete this;
  }

  /** Description:
    Returns the *name* of this RxStaticModule object.
  */
  OdString moduleName() const
  {
	wchar_t buffer[_MAX_PATH];
	::GetModuleFileNameW(m_hModule, buffer, _MAX_PATH );
	return buffer;
  }
};


/** Description:
    Creates the entry point function for a Teigha custom application.
*/
#define ODRX_DEFINE_DYNAMIC_MODULE(_UserModuleClass)\
static OdRxModule* g_pSingletonModule = 0;\
  extern "C" {\
__declspec(dllexport) OdRxModule* odrxCreateModuleObject(HMODULE& hModule)\
{\
  if(!g_pSingletonModule)\
  {\
    g_pSingletonModule = OdRxWin32Module<_UserModuleClass >::createModule(hModule);\
    hModule = 0;\
  }\
  return g_pSingletonModule;\
}\
__declspec(dllexport) void odrxGetAPIVersion(int& nMajorVersion, int& nMinorVersion,\
                                             int& nMajorBuildVersion, int& nMinorBuildVersion)\
{\
  nMajorVersion       = TD_MAJOR_VERSION;\
  nMinorVersion       = TD_MINOR_VERSION;\
  nMajorBuildVersion  = TD_MAJOR_BUILD;\
  nMinorBuildVersion  = TD_MINOR_BUILD;\
}\
}\

#endif //__BORLANDC__



#endif //defined(__GNUC__) && defined(__APPLE__)

#else //#ifdef _TOOLKIT_IN_DLL_ ////////////////////////////////////////////////////////////////////////////////

#define ODRX_STATIC_MODULE_PATH ""

#define ODRX_STATIC_APP_MODULE_NAME(AppName) AppName

#define ODRX_DEFINE_DYNAMIC_MODULE(_UserModuleClass) ODRX_DEFINE_STATIC_MODULE(_UserModuleClass)


#endif //#ifdef _TOOLKIT_IN_DLL_ ////////////////////////////////////////////////////////////////////////////////


#include "TD_PackPop.h"

#endif // _OD_RXDYNAMICMODULE_H_

