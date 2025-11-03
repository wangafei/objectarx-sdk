/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GcExtensionModule_h
#define _GcExtensionModule_h

#if _MSC_VER >= 1000
#pragma once
#endif 

class CGcExtensionModule {
public:
  CGcExtensionModule();
  ~CGcExtensionModule();

protected:
  BOOL    m_bAttached;
  HINSTANCE m_hDefaultResource;
  HINSTANCE m_hModuleResource;
#ifndef _GSOFT_MAC_
  AFX_EXTENSION_MODULE m_module;
#endif

public:
  BOOL      Attached();
  HINSTANCE DefaultResourceInstance();
  HINSTANCE ModuleResourceInstance();
  BOOL      AttachInstance(HINSTANCE hInst);
  void      DetachInstance();
};

inline CGcExtensionModule::CGcExtensionModule() :
  m_bAttached(FALSE),
  m_hDefaultResource(NULL),
  m_hModuleResource(NULL)
{
#ifndef _GSOFT_MAC_
  m_module.bInitialized = FALSE;
  m_module.hModule = NULL;
  m_module.hResource = NULL;
  m_module.pFirstSharedClass = NULL;
  m_module.pFirstSharedFactory = NULL;
#endif
}

inline CGcExtensionModule::~CGcExtensionModule()
{
}

inline BOOL CGcExtensionModule::Attached()
{
  return m_bAttached;
}

inline BOOL CGcExtensionModule::AttachInstance(HINSTANCE hInst)
{
  if (m_bAttached)
    return FALSE;
#ifndef _GSOFT_MAC_
  m_bAttached = AfxInitExtensionModule(m_module, hInst);
#else
  m_bAttached = true;
#endif
  if (m_bAttached) {
    m_hDefaultResource = AfxGetResourceHandle();
    m_hModuleResource = hInst;
#ifndef _GSOFT_MAC_
    new CDynLinkLibrary(m_module);
#endif
  }
  return m_bAttached;
}

inline HINSTANCE CGcExtensionModule::DefaultResourceInstance()
{
  return m_hDefaultResource;
}

inline void CGcExtensionModule::DetachInstance()
{
  if (m_bAttached) {
#ifndef _GSOFT_MAC_
    AfxTermExtensionModule(m_module);
#endif
    m_bAttached = FALSE;
  }
}

inline HINSTANCE CGcExtensionModule::ModuleResourceInstance()
{
  return m_hModuleResource;
}

class CGcModuleResourceOverride {
public:
  CGcModuleResourceOverride();
  CGcModuleResourceOverride(HINSTANCE hInst);
  ~CGcModuleResourceOverride();
  static HINSTANCE ResourceInstance() { return m_extensionModule.ModuleResourceInstance(); }
private:
  static  CGcExtensionModule& m_extensionModule;
  HINSTANCE m_previousResourceInstance;
};

inline CGcModuleResourceOverride::CGcModuleResourceOverride()
  : CGcModuleResourceOverride(NULL)
{
}

inline CGcModuleResourceOverride::CGcModuleResourceOverride(HINSTANCE hInst)
{
  m_previousResourceInstance = AfxGetResourceHandle();
  HINSTANCE hInstanceToSet = m_extensionModule.ModuleResourceInstance();
  if (hInst)
    hInstanceToSet = hInst;
  AfxSetResourceHandle(hInstanceToSet);
}

inline CGcModuleResourceOverride::~CGcModuleResourceOverride()
{
  ASSERT(m_previousResourceInstance);
  AfxSetResourceHandle(m_previousResourceInstance);
  m_previousResourceInstance = NULL;
}

#define GC_DECLARE_EXTENSION_MODULE(exm)        \
  extern CGcExtensionModule exm;

#define GC_IMPLEMENT_EXTENSION_MODULE(exm)      \
  CGcExtensionModule exm;                     \
  CGcExtensionModule& CGcModuleResourceOverride::m_extensionModule = exm;

#endif