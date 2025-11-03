

#ifndef _ZcExtensionModule_h
#define _ZcExtensionModule_h

#if _MSC_VER >= 1000
#pragma once
#endif 

class CZcExtensionModule {
public:
                CZcExtensionModule ();
                ~CZcExtensionModule ();

protected:
        BOOL    m_bAttached;
        HINSTANCE m_hDefaultResource;
        HINSTANCE m_hModuleResource;
#ifndef _ZSOFT_MAC_
        AFX_EXTENSION_MODULE m_module;
#endif

public:
        BOOL    Attached ();
        HINSTANCE DefaultResourceInstance ();
        HINSTANCE ModuleResourceInstance ();

        BOOL    AttachInstance (HINSTANCE hInst);

        void    DetachInstance ();
};

inline CZcExtensionModule::CZcExtensionModule () :
    m_bAttached(FALSE),
    m_hDefaultResource(NULL),
    m_hModuleResource(NULL)
{
#ifndef _ZSOFT_MAC_
    m_module.bInitialized = FALSE;
    m_module.hModule = NULL;
    m_module.hResource = NULL;
    m_module.pFirstSharedClass = NULL;
    m_module.pFirstSharedFactory = NULL;
#endif
}

inline CZcExtensionModule::~CZcExtensionModule ()
{
}

inline BOOL CZcExtensionModule::Attached ()
{
    return m_bAttached;
}

inline BOOL CZcExtensionModule::AttachInstance (HINSTANCE hInst)
{
    if (m_bAttached)
        return FALSE;
#ifndef _ZSOFT_MAC_
    m_bAttached = AfxInitExtensionModule(m_module, hInst);
#else
    m_bAttached = true;
#endif
    if (m_bAttached) {
        m_hDefaultResource = AfxGetResourceHandle();
        m_hModuleResource = hInst;
#ifndef _ZSOFT_MAC_
        new CDynLinkLibrary(m_module);
#endif
    }
    return m_bAttached;
}

inline HINSTANCE CZcExtensionModule::DefaultResourceInstance ()
{
    return m_hDefaultResource;
}

inline void CZcExtensionModule::DetachInstance ()
{
    if (m_bAttached) {
#ifndef _ZSOFT_MAC_
        AfxTermExtensionModule(m_module);
#endif
        m_bAttached = FALSE;
    }
}

inline HINSTANCE CZcExtensionModule::ModuleResourceInstance ()
{
    return m_hModuleResource;
}

class CZcModuleResourceOverride {
public:
                    CZcModuleResourceOverride ();
                    CZcModuleResourceOverride (HINSTANCE hInst);
                    ~CZcModuleResourceOverride ();
                    static HINSTANCE ResourceInstance() { return m_extensionModule.ModuleResourceInstance(); }
private:
static  CZcExtensionModule& m_extensionModule;
HINSTANCE m_previousResourceInstance;
};

inline CZcModuleResourceOverride::CZcModuleResourceOverride ()
									    : CZcModuleResourceOverride(NULL)
{
}

inline CZcModuleResourceOverride::CZcModuleResourceOverride (HINSTANCE hInst)
{
    m_previousResourceInstance = AfxGetResourceHandle();
    HINSTANCE hInstanceToSet = m_extensionModule.ModuleResourceInstance();
    if (hInst)
        hInstanceToSet = hInst;
    AfxSetResourceHandle(hInstanceToSet);
}

inline CZcModuleResourceOverride::~CZcModuleResourceOverride ()
{
    ASSERT(m_previousResourceInstance);
    AfxSetResourceHandle(m_previousResourceInstance);
    m_previousResourceInstance = NULL;
}

#define ZC_DECLARE_EXTENSION_MODULE(exm)        \
    extern CZcExtensionModule exm;

#define ZC_IMPLEMENT_EXTENSION_MODULE(exm)      \
    CZcExtensionModule exm;                     \
    CZcExtensionModule& CZcModuleResourceOverride::m_extensionModule = exm;

#endif
