#pragma once

#include "rxdlinkr.h"

#define _RXST(a) _GCRX_T(a)

struct _DBX_REGISTER_OBJECT_ENTRY
{
  GcRxClass* (*desc)();
  void(*rxInit) ();
  bool bRegistered;
};

#pragma section("DBXCUSTOBJ$__a", read, shared)
#pragma section("DBXCUSTOBJ$__z", read, shared)
#pragma section("DBXCUSTOBJ$__m", read, shared)

#ifndef _ADESK_MAC_
#define DBXCUSTOBJ_FIRST_ENTRYNAME "DBXCUSTOBJ$__a"
#else
#define DBXCUSTOBJ_FIRST_ENTRYNAME "DBXCUSTOBJ$__m"
#endif
#define DBXCUSTOBJ_LAST_ENTRYNAME "DBXCUSTOBJ$__z"

extern "C" {
  __declspec(selectany) __declspec(allocate(DBXCUSTOBJ_FIRST_ENTRYNAME)) _DBX_REGISTER_OBJECT_ENTRY* __pDbxCustObjMapEntryFirst = NULL;
  __declspec(selectany) __declspec(allocate(DBXCUSTOBJ_LAST_ENTRYNAME)) _DBX_REGISTER_OBJECT_ENTRY* __pDbxCustObjMapEntryLast = NULL;
}

#if defined(_WIN64) || defined(_AC64)
#define GCDB_REGISTER_OBJECT_ENTRY_PRAGMA(classname) __pragma(comment(linker, "/include:__pDbxCustObjMap_" #classname)) ;
#else
#define GCDB_REGISTER_OBJECT_ENTRY_PRAGMA(classname) __pragma(comment(linker, "/include:___pDbxCustObjMap_" #classname)) ;
#endif

#define GCDB_REGISTER_OBJECT_ENTRY_AUTO(classname) \
    __declspec(selectany) _DBX_REGISTER_OBJECT_ENTRY __DbxCustObjMap_##classname = { classname::desc, classname::rxInit } ; \
    extern "C" __declspec(allocate("DBXCUSTOBJ$__m")) __declspec(selectany) _DBX_REGISTER_OBJECT_ENTRY* __pDbxCustObjMap_##classname = &__DbxCustObjMap_##classname ; \
    GCDB_REGISTER_OBJECT_ENTRY_PRAGMA(classname)

#define DISPATCH_PKTMSG(pktmsg) case GcRx::pktmsg: return (On_ ##pktmsg (pkt))
#define DECLARE_PKTMSG_FUNC(pktmsg) virtual GcRx::AppRetCode On_ ##pktmsg (void* /*pkt*/) { return (GcRx::kRetOK) ; }

extern HINSTANCE _hdllInstance;

class GcRxDbxApp
{
protected:
  HINSTANCE m_hdllInstance;
  bool m_bUnlocked;
  bool m_bMDIAware;

public:
  GcRxDbxApp()
    : m_hdllInstance(NULL)
    , m_bUnlocked(true)
    , m_bMDIAware(true)
  {
  }

  virtual GcRx::AppRetCode On_kInitAppMsg(void *pkt)
  {

    m_hdllInstance = _hdllInstance;
    if (m_bUnlocked)
    {
      gcrxDynamicLinker->unlockApplication(pkt);
    }

    if (m_bMDIAware)
    {
      gcrxDynamicLinker->registerAppMDIAware(pkt);
    }

    RegisterServerComponents();

    int nDbxCustObjCount = 0;

    _DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryFirst = &__pDbxCustObjMapEntryFirst + 1;
    _DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryLast = &__pDbxCustObjMapEntryLast;
    for (_DBX_REGISTER_OBJECT_ENTRY **ppEntry = ppDbxCustObjMapEntryFirst; ppEntry < ppDbxCustObjMapEntryLast; ppEntry++) {
      if (*ppEntry != NULL) {
        nDbxCustObjCount++;
        (*ppEntry)->rxInit();
        (*ppEntry)->bRegistered = true;
      }
    }

    if (nDbxCustObjCount > 0)
    {
      gcrxBuildClassHierarchy();
    }

    return (GcRx::kRetOK);
  }

  virtual GcRx::AppRetCode On_kUnloadAppMsg(void* /*pkt*/)
  {

    _DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryFirst = &__pDbxCustObjMapEntryFirst + 1;
    _DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryLast = &__pDbxCustObjMapEntryLast;
    for (_DBX_REGISTER_OBJECT_ENTRY **ppEntry = ppDbxCustObjMapEntryFirst; ppEntry < ppDbxCustObjMapEntryLast; ppEntry++) {
      if (*ppEntry != NULL && (*ppEntry)->bRegistered == true)
        DeleteClassAndDescendant(ppEntry);
    }
    return (GcRx::kRetOK);
  }

  DECLARE_PKTMSG_FUNC(kLoadDwgMsg)
  DECLARE_PKTMSG_FUNC(kUnloadDwgMsg)
  DECLARE_PKTMSG_FUNC(kInvkSubrMsg)
  DECLARE_PKTMSG_FUNC(kCfgMsg)
  DECLARE_PKTMSG_FUNC(kEndMsg)
  DECLARE_PKTMSG_FUNC(kQuitMsg)
  DECLARE_PKTMSG_FUNC(kSaveMsg)
  DECLARE_PKTMSG_FUNC(kDependencyMsg)
  DECLARE_PKTMSG_FUNC(kNoDependencyMsg)
  DECLARE_PKTMSG_FUNC(kOleUnloadAppMsg)
  DECLARE_PKTMSG_FUNC(kPreQuitMsg)
  DECLARE_PKTMSG_FUNC(kInitDialogMsg)
  DECLARE_PKTMSG_FUNC(kEndDialogMsg)
  DECLARE_PKTMSG_FUNC(kNullMsg)

  GcRx::AppRetCode gcrxEntryPoint(GcRx::AppMsgCode msg, void *pkt)
  {
    switch (msg)
    {
      DISPATCH_PKTMSG(kInitAppMsg);
      DISPATCH_PKTMSG(kUnloadAppMsg);
      DISPATCH_PKTMSG(kLoadDwgMsg);
      DISPATCH_PKTMSG(kUnloadDwgMsg);
      DISPATCH_PKTMSG(kInvkSubrMsg);
      DISPATCH_PKTMSG(kCfgMsg);
      DISPATCH_PKTMSG(kEndMsg);
      DISPATCH_PKTMSG(kQuitMsg);
      DISPATCH_PKTMSG(kSaveMsg);
      DISPATCH_PKTMSG(kDependencyMsg);
      DISPATCH_PKTMSG(kNoDependencyMsg);
      DISPATCH_PKTMSG(kOleUnloadAppMsg);
      DISPATCH_PKTMSG(kPreQuitMsg);
      DISPATCH_PKTMSG(kInitDialogMsg);
      DISPATCH_PKTMSG(kEndDialogMsg);
      DISPATCH_PKTMSG(kNullMsg);
    }
    return (GcRx::kRetOK);
  }

  virtual void RegisterServerComponents() = 0;

  HINSTANCE &GetModuleInstance()
  {
    return (m_hdllInstance);
  }

private:
  void DeleteClassAndDescendant(_DBX_REGISTER_OBJECT_ENTRY **ppEntry)
  {
    _DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryFirst = &__pDbxCustObjMapEntryFirst + 1;
    _DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryLast = &__pDbxCustObjMapEntryLast;
    for (_DBX_REGISTER_OBJECT_ENTRY **ppEntry2 = ppDbxCustObjMapEntryFirst; ppEntry2 < ppDbxCustObjMapEntryLast; ppEntry2++) {
      if (*ppEntry2 != NULL && *ppEntry2 != *ppEntry && (*ppEntry2)->bRegistered == true) {
        if ((*ppEntry2)->desc()->myParent() == (*ppEntry)->desc())
          DeleteClassAndDescendant(ppEntry2);
      }
    }
    deleteGcRxClass((*ppEntry)->desc());
    (*ppEntry)->bRegistered = false;
  }
};


GcRxDbxApp *gcrxGetApp();

#define IMPLEMENT_GRX_ENTRYPOINT_STD(classname) \
  HINSTANCE _hdllInstance =NULL ; \
  class classname entryPointObject ; \
  GcRxDbxApp *gcrxGetApp () { return (&entryPointObject) ; } \
  extern "C" GcRx::AppRetCode __declspec(dllexport) gcrxEntryPoint (GcRx::AppMsgCode msg, void *pkt) \
  { \
    return (entryPointObject.gcrxEntryPoint (msg, pkt)) ; \
  }

#define IMPLEMENT_GRX_ENTRYPOINT_CLR(classname) IMPLEMENT_GRX_ENTRYPOINT_STD(classname)
#define IMPLEMENT_GRX_ENTRYPOINT(classname)     IMPLEMENT_GRX_ENTRYPOINT_STD(classname)

