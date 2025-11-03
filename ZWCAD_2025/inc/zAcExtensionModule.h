

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
        BOOL    Attached () const;
        HINSTANCE DefaultResourceInstance () const;
        HINSTANCE ModuleResourceInstance () const;

        BOOL    AttachInstance(HINSTANCE hExtInst, HINSTANCE hResInst);

        BOOL    AttachInstance(HINSTANCE hExtInst)
        {
            return this->AttachInstance(hExtInst, hExtInst);
        }

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

inline BOOL CZcExtensionModule::Attached () const
{
    return m_bAttached;
}

inline BOOL CZcExtensionModule::AttachInstance (HINSTANCE hExtInst, HINSTANCE hResInst)
{
    ASSERT(hExtInst != nullptr);
    ASSERT(hResInst != nullptr);
    if (m_bAttached)
        return FALSE;
#ifndef _ZSOFT_MAC_
    ASSERT(!m_module.bInitialized);
    m_bAttached = AfxInitExtensionModule(m_module, hExtInst);
#else
    m_bAttached = true;
#endif
    ASSERT(this->m_hDefaultResource == nullptr);
    ASSERT(this->m_hModuleResource == nullptr);
    if (m_bAttached) {
        this->m_hDefaultResource = AfxGetResourceHandle();
        this->m_hModuleResource = hResInst;
#ifndef _ZSOFT_MAC_
        ASSERT(this->m_module.hModule == hExtInst);
        ASSERT(this->m_module.hResource == hExtInst);
        this->m_module.hResource = hResInst;
        new CDynLinkLibrary(m_module);
#endif
    }
    return m_bAttached;
}

inline HINSTANCE CZcExtensionModule::DefaultResourceInstance () const
{
    return m_hDefaultResource;
}

inline void CZcExtensionModule::DetachInstance ()
{
    if (m_bAttached) {
#ifndef _ZSOFT_MAC_
        AfxTermExtensionModule(m_module);
#endif
        this->m_hDefaultResource = nullptr;
        this->m_hModuleResource = nullptr;
        m_bAttached = FALSE;
    }
}

inline HINSTANCE CZcExtensionModule::ModuleResourceInstance () const
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
