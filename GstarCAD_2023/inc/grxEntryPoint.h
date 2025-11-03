/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gccmd.h"
#include "gds.h"
#include "dbxEntryPoint.h"
#ifdef __ATLCOM_H__
#include "dynpropmgr.h"
#endif

struct _GRXCOMMAND_ENTRY
{
  const GCHAR    *pszCmdGroupName;
  const GCHAR    *pszCmdGlobalName;
  const GCHAR    *pszCmdLocalName;
  Gsoft::Int32    commandFlags;
  GcRxFunctionPtr pCmdFct;
  GcEdUIContext  *pUIContext;
  UINT            localNameID;
};

#pragma section("GRXCOMMAND$__a", read, shared)
#pragma section("GRXCOMMAND$__z", read, shared)
#pragma section("GRXCOMMAND$__m", read, shared)

#ifndef _GSOFT_MAC_
#define GRXCOMMAND_FIRST_ENTRYNAME "GRXCOMMAND$__a"
#else
#define GRXCOMMAND_FIRST_ENTRYNAME "GRXCOMMAND$__m"
#endif
#define GRXCOMMAND_LAST_ENTRYNAME "GRXCOMMAND$__z"

extern "C"
{
  __declspec(selectany) __declspec(allocate(GRXCOMMAND_FIRST_ENTRYNAME)) _GRXCOMMAND_ENTRY* __pGrxCmdMapEntryFirst = NULL;
  __declspec(selectany) __declspec(allocate(GRXCOMMAND_LAST_ENTRYNAME)) _GRXCOMMAND_ENTRY* __pGrxCmdMapEntryLast = NULL;
}

#ifndef _GSOFT_MAC_
#if defined(_WIN64) || defined(_GC64)
#define GCED_GRXCOMMAND_ENTRY_PRAGMA(group,globCmd) __pragma(comment(linker, "/include:__pGrxCmdMap_" #group #globCmd)) ;
#else
#define GCED_GRXCOMMAND_ENTRY_PRAGMA(group,globCmd) __pragma(comment(linker, "/include:___pGrxCmdMap_" #group #globCmd)) ;
#endif
#else
#define GCED_GRXCOMMAND_ENTRY_PRAGMA(group,globCmd)
#endif

#define GCED_GRXCOMMAND_ENTRY_AUTO(classname, group, globCmd, locCmd, cmdFlags, UIContext) \
    __declspec(selectany) _GRXCOMMAND_ENTRY __GrxCmdMap_##group##globCmd = { _RXST(#group), _RXST(#globCmd), _RXST(#locCmd), cmdFlags, classname::group ##globCmd, UIContext, 0 } ; \
    extern "C" __declspec(allocate("GRXCOMMAND$__m")) __declspec(selectany) _GRXCOMMAND_ENTRY*  __pGrxCmdMap_##group##globCmd = &__GrxCmdMap_##group##globCmd ; \
    GCED_GRXCOMMAND_ENTRY_PRAGMA(group, globCmd)

#define GCED_GRXCOMMAND_ENTRYBYID_AUTO(classname, group, globCmd, locCmdId, cmdFlags, UIContext) \
    __declspec(selectany) _GRXCOMMAND_ENTRY __GrxCmdMap_##group##globCmd = { _RXST(#group), _RXST(#globCmd), NULL, cmdFlags, classname::group ##globCmd, UIContext, locCmdId } ; \
    extern "C" __declspec(allocate("GRXCOMMAND$__m")) __declspec(selectany) _GRXCOMMAND_ENTRY*  __pGrxCmdMap_##group##globCmd = &__GrxCmdMap_##group##globCmd ; \
    GCED_GRXCOMMAND_ENTRY_PRAGMA(group, globCmd)

struct _GDSSYMBOL_ENTRY
{
  const GCHAR *pszName;
  int(*fptr) ();
  bool bRegFunc;
  UINT nameID;
};

#pragma section("GDSSYMBOL$__a", read, shared)
#pragma section("GDSSYMBOL$__z", read, shared)
#pragma section("GDSSYMBOL$__m", read, shared)

#ifndef _GSOFT_MAC_
#define GDSSYMBOL_FIRST_ENTRYNAME "GDSSYMBOL$__a"
#else
#define GDSSYMBOL_FIRST_ENTRYNAME "GDSSYMBOL$__m"
#endif
#define GDSSYMBOL_LAST_ENTRYNAME "GDSSYMBOL$__z"

extern "C"
{
  __declspec(selectany) __declspec(allocate(GDSSYMBOL_FIRST_ENTRYNAME)) _GDSSYMBOL_ENTRY* __pGdsSymbolMapEntryFirst = NULL;
  __declspec(selectany) __declspec(allocate(GDSSYMBOL_LAST_ENTRYNAME)) _GDSSYMBOL_ENTRY* __pGdsSymbolMapEntryLast = NULL;
}

#ifndef _GSOFT_MAC_
#if defined(_WIN64) || defined(_GC64)
#define GCED_GDSSYMBOL_ENTRY_PRAGMA(name) __pragma(comment(linker, "/include:__pGdsSymbolMap_" #name)) ;
#else
#define GCED_GDSSYMBOL_ENTRY_PRAGMA(name) __pragma(comment(linker, "/include:___pGdsSymbolMap_" #name)) ;
#endif
#else
#define GCED_GDSSYMBOL_ENTRY_PRAGMA(name)
#endif

#define GCED_GDSSYMBOL_ENTRY_AUTO(classname, name, regFunc) \
    __declspec(selectany) _GDSSYMBOL_ENTRY __GdsSymbolMap_##name = { _RXST(#name), classname::gds_ ##name, regFunc, -1 } ; \
    extern "C" __declspec(allocate("GDSSYMBOL$__m")) __declspec(selectany) _GDSSYMBOL_ENTRY* __pGdsSymbolMap_##name = &__GdsSymbolMap_##name ; \
    GCED_GDSSYMBOL_ENTRY_PRAGMA(name)
#define GCED_GDSCOMMAND_ENTRY_AUTO(classname, name, regFunc) \
    __declspec(selectany) _GDSSYMBOL_ENTRY __GdsSymbolMap_##name = { _RXST("c:") _RXST(#name), classname::gds_ ##name, regFunc, -1 } ; \
    extern "C" __declspec(allocate("GDSSYMBOL$__m")) __declspec(selectany) _GDSSYMBOL_ENTRY* __pGdsSymbolMap_##name = &__GdsSymbolMap_##name ; \
    GCED_GDSSYMBOL_ENTRY_PRAGMA(name)

#define GCED_GDSSYMBOL_ENTRYBYID_AUTO(classname, name, nameId, regFunc) \
    __declspec(selectany) _GDSSYMBOL_ENTRY __GdsSymbolMap_##name = { NULL, classname::gds_ ##name, regFunc, nameId } ; \
    extern "C" __declspec(allocate("GDSSYMBOL$__m")) __declspec(selectany) _GDSSYMBOL_ENTRY* __pGdsSymbolMap_##name = &__GdsSymbolMap_##name ; \
    GCED_GDSSYMBOL_ENTRY_PRAGMA(name)
#define GCED_GDSCOMMAND_ENTRYBYID_AUTO(classname, name, nameId, regFunc) \
    GCED_GDSSYMBOL_ENTRYBYID_AUTO(classname, name, nameId, regFunc)

class GcRxGrxApp : public GcRxDbxApp
{
#ifdef __ATLCOM_H__
protected:
  GcRxDynPropManager *m_pDynPropManager;
#endif

public:
#ifdef __ATLCOM_H__
  GcRxGrxApp() : GcRxDbxApp(), m_pDynPropManager(NULL) {}
#else
  GcRxGrxApp() : GcRxDbxApp() {}
#endif

  virtual GcRx::AppRetCode On_kInitAppMsg(void *pkt)
  {
    GcRx::AppRetCode retCode = GcRxDbxApp::On_kInitAppMsg(pkt);
#ifdef __ATLCOM_H__
    m_pDynPropManager = new GcRxDynPropManager;
#endif
    _GRXCOMMAND_ENTRY **ppGrxCmdMapEntryFirst = &__pGrxCmdMapEntryFirst + 1;
    _GRXCOMMAND_ENTRY **ppGrxCmdMapEntryLast = &__pGrxCmdMapEntryLast;
    GCHAR buffer[133];
    for (_GRXCOMMAND_ENTRY **ppEntry = ppGrxCmdMapEntryFirst; ppEntry < ppGrxCmdMapEntryLast; ppEntry++)
    {
      if (*ppEntry != NULL)
      {
        if ((*ppEntry)->pszCmdLocalName == NULL)
          ::LoadString(m_hdllInstance, (*ppEntry)->localNameID, buffer, 132);
        gcedRegCmds->addCommand(
          (*ppEntry)->pszCmdGroupName,
          (*ppEntry)->pszCmdGlobalName,
          (*ppEntry)->pszCmdLocalName == NULL ? buffer : (*ppEntry)->pszCmdLocalName,
          (*ppEntry)->commandFlags,
          (*ppEntry)->pCmdFct,
          (*ppEntry)->pUIContext,
          -1,
          ((*ppEntry)->commandFlags & GCRX_CMD_SESSION) ? NULL : m_hdllInstance,
          NULL);
      }
    }
    return (retCode);
  }

  virtual GcRx::AppRetCode On_kUnloadAppMsg(void *pkt)
  {
    GcRx::AppRetCode retCode = GcRxDbxApp::On_kUnloadAppMsg(pkt);
#ifdef __ATLCOM_H__
    if (m_pDynPropManager != NULL)
    {
      delete m_pDynPropManager;
      m_pDynPropManager = NULL;
    }
#endif
    _GRXCOMMAND_ENTRY **ppGrxCmdMapEntryFirst = &__pGrxCmdMapEntryFirst + 1;
    _GRXCOMMAND_ENTRY **ppGrxCmdMapEntryLast = &__pGrxCmdMapEntryLast;
    for (_GRXCOMMAND_ENTRY **ppEntry = ppGrxCmdMapEntryFirst; ppEntry < ppGrxCmdMapEntryLast; ppEntry++)
    {
      if (*ppEntry != NULL)
      {
        gcedRegCmds->removeCmd((*ppEntry)->pszCmdGroupName, (*ppEntry)->pszCmdGlobalName);
      }
    }
    return (retCode);
  }

  virtual GcRx::AppRetCode On_kLoadDwgMsg(void *pkt)
  {
    GcRx::AppRetCode retCode = GcRxDbxApp::On_kLoadDwgMsg(pkt);
    _GDSSYMBOL_ENTRY **ppGdsSymbolMapEntryFirst = &__pGdsSymbolMapEntryFirst + 1;
    _GDSSYMBOL_ENTRY **ppGdsSymbolMapEntryLast = &__pGdsSymbolMapEntryLast;
    GCHAR buffer[133];
    int param = 0;
    for (_GDSSYMBOL_ENTRY **ppEntry = ppGdsSymbolMapEntryFirst; ppEntry < ppGdsSymbolMapEntryLast; ppEntry++)
    {
      if (*ppEntry != NULL)
      {
        if ((*ppEntry)->pszName == NULL)
          ::LoadString(m_hdllInstance, (*ppEntry)->nameID, buffer, 132);
        gcedDefun((*ppEntry)->pszName == NULL ? buffer : (*ppEntry)->pszName, param);
        if ((*ppEntry)->bRegFunc == true)
          gcedRegFunc((*ppEntry)->fptr, param);
        param++;
      }
    }
    return (retCode);
  }

  virtual GcRx::AppRetCode On_kUnloadDwgMsg(void *pkt)
  {
    GcRx::AppRetCode retCode = GcRxDbxApp::On_kUnloadDwgMsg(pkt);
    _GDSSYMBOL_ENTRY **ppGdsSymbolMapEntryFirst = &__pGdsSymbolMapEntryFirst + 1;
    _GDSSYMBOL_ENTRY **ppGdsSymbolMapEntryLast = &__pGdsSymbolMapEntryLast;
    GCHAR buffer[133];
    int param = 0;
    for (_GDSSYMBOL_ENTRY **ppEntry = ppGdsSymbolMapEntryFirst; ppEntry < ppGdsSymbolMapEntryLast; ppEntry++)
    {
      if (*ppEntry != NULL)
      {
        if ((*ppEntry)->pszName == NULL)
          ::LoadString(m_hdllInstance, (*ppEntry)->nameID, buffer, 132);
        gcedUndef((*ppEntry)->pszName == NULL ? buffer : (*ppEntry)->pszName, param++);
      }
    }
    return (retCode);
  }

  virtual GcRx::AppRetCode On_kInvkSubrMsg(void *pkt)
  {
    GcRx::AppRetCode retCode = GcRxDbxApp::On_kInvkSubrMsg(pkt);
    int param = gcedGetFunCode();
    _GDSSYMBOL_ENTRY **ppGdsSymbolMapEntryFirst = &__pGdsSymbolMapEntryFirst + 1;
    _GDSSYMBOL_ENTRY **ppGdsSymbolMapEntryLast = &__pGdsSymbolMapEntryLast;
    int paramIter = 0;
    for (_GDSSYMBOL_ENTRY **ppEntry = ppGdsSymbolMapEntryFirst; ppEntry < ppGdsSymbolMapEntryLast; ppEntry++)
    {
      if (*ppEntry != NULL)
      {
        if (paramIter++ == param)
        {
          (*((*ppEntry)->fptr)) ();
          break;
        }
      }
    }
    return (retCode);
  }
};
