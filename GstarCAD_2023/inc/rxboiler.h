/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_RXBOILER_H
#define GC_RXBOILER_H

#include "GdGChar.h"
#include "rxnames.h"
#include "gcbasedefs.h"
#pragma pack (push, 8)

class GcRxClass;
GCBASE_PORT GcRxClass * gcrxFindGcRxClass(const GCHAR *pClassName);

#define GCRX_AUTO_INIT_QUEUE_EXPR(CLASS_NAME) gcrxQueueClassForInitialization(&CLASS_NAME::gpDesc, &CLASS_NAME::rxInit)

#ifdef GCRX_AUTO_INIT 
#define GCRX_AUTO_INIT_DEFAULT(CLASS_NAME) GCRX_AUTO_INIT_QUEUE_EXPR(CLASS_NAME)
#else
#define GCRX_AUTO_INIT_DEFAULT(CLASS_NAME) nullptr
#endif

#define GCRX_DEFINE_GPDESC(CLASS_NAME, AUTOINIT) \
    GcRxClass* CLASS_NAME::gpDesc = AUTOINIT(CLASS_NAME);

#define GCRX_DECLARE_GPDESC(CLASS_NAME) \
    static GcRxClass* gpDesc; 

class GcRxObject;
template <typename T>
static GcRxObject* gcrxInstantiateClass() { return new T(); }

#define GCRX_DECLARE_MEMBERS_EXPIMP(CLASS_NAME, EXPIMP) \
  friend GcRxObject* ::gcrxInstantiateClass<CLASS_NAME>(); \
  EXPIMP GcRxClass* isA() const override; \
  GCRX_DECLARE_GPDESC(CLASS_NAME); \
  EXPIMP static GcRxClass* desc(); \
  static CLASS_NAME* cast(const GcRxObject* inPtr) \
  { return ((inPtr == NULL) || !inPtr->isKindOf(CLASS_NAME::desc())) \
    ? NULL : (CLASS_NAME*)inPtr; }; \
  static void rxInit(); \
  static void rxInit(AppNameChangeFuncPtr); \
  static const wchar_t* className() { return GCRX_T(#CLASS_NAME); } \

#define GCRX_EMPTY

#define GCRX_DECLARE_MEMBERS(CLASS_NAME) \
    GCRX_DECLARE_MEMBERS_EXPIMP(CLASS_NAME, GCRX_EMPTY )

#define GCRX_DEFINE_MEMBERS_WORKER(CLASS_NAME, AUTOINIT) \
GcRxClass* CLASS_NAME::desc() \
{ \
  if (gpDesc == nullptr) \
    gpDesc = ::gcrxFindGcRxClass(GCRX_T(#CLASS_NAME)); \
  return gpDesc; \
} \
GcRxClass* CLASS_NAME::isA() const \
{ \
  if (gpDesc == nullptr) \
    gpDesc = ::gcrxFindGcRxClass(GCRX_T(#CLASS_NAME)); \
  return gpDesc; \
} \
GCRX_DEFINE_GPDESC(CLASS_NAME, AUTOINIT)

#define GCRX_DEFINE_MEMBERS(CLASS_NAME) \
GCRX_DEFINE_MEMBERS_WORKER(CLASS_NAME, GCRX_AUTO_INIT_DEFAULT)

#include "GdGChar.h"

extern "C" void GCBASE_PORT gcrx_abort(const GCHAR * format, ...);
#define GCRX_STATIC_CHECK(CLASS_NAME) \
  if (gpDesc!=nullptr) { \
    GcRxClass *pClass = ::gcrxFindGcRxClass(GCRX_T(#CLASS_NAME)); \
    if (pClass) { \
      if (gpDesc == pClass) \
        return; \
      else \
        gcrx_abort(GCRX_T("Class mismatch")); \
    } \
  }

#define GCRX_NO_CONS_DEFINE_MEMBERS_WORKER(AUTOINIT,CLASS_NAME,PARENT_CLASS) \
GCRX_DEFINE_MEMBERS_WORKER(CLASS_NAME, AUTOINIT); \
void CLASS_NAME::rxInit() { \
  GCRX_STATIC_CHECK(CLASS_NAME); \
  gpDesc = newGcRxClass(GCRX_T(#CLASS_NAME), GCRX_T(#PARENT_CLASS)); \
}

#define GCRX_NO_CONS_DEFINE_MEMBERS(CLASS_NAME,PARENT_CLASS) \
GCRX_NO_CONS_DEFINE_MEMBERS_WORKER(GCRX_AUTO_INIT_DEFAULT,CLASS_NAME, PARENT_CLASS)

#define GCRX_NO_CONS_DEFINE_MEMBERS_AUTO(CLASS_NAME,PARENT_CLASS) \
GCRX_NO_CONS_DEFINE_MEMBERS_WORKER(GCRX_AUTO_INIT_QUEUE_EXPR, CLASS_NAME,PARENT_CLASS)

#define GCRX_NO_CONS_DEFINE_MEMBERS_WITH_PROPERTIES_WORKER(AUTOINIT, CLASS_NAME,PARENT_CLASS, MAKEPROPS) \
GCRX_DEFINE_MEMBERS(CLASS_NAME); \
void CLASS_NAME::rxInit() { \
  GCRX_STATIC_CHECK(CLASS_NAME); \
  gpDesc = newGcRxClass(GCRX_T(#CLASS_NAME), GCRX_T(#PARENT_CLASS), \
    0, 0, 0, \
    0, 0, 0, 0, MAKEPROPS); \
}
#define GCRX_NO_CONS_DEFINE_MEMBERS_WITH_PROPERTIES(CLASS_NAME,PARENT_CLASS, MAKEPROPS) \
GCRX_NO_CONS_DEFINE_MEMBERS_WITH_PROPERTIES_WORKER(GCRX_AUTO_INIT_DEFAULT, CLASS_NAME,PARENT_CLASS, MAKEPROPS)

#define GCRX_NO_CONS_DEFINE_MEMBERS_WITH_PROPERTIES_AUTO(CLASS_NAME,PARENT_CLASS, MAKEPROPS) \
GCRX_NO_CONS_DEFINE_MEMBERS_WITH_PROPERTIES_WORKER(GCRX_AUTO_INIT_QUEUE_EXPR, CLASS_NAME,PARENT_CLASS, MAKEPROPS)

#define GCRX_CONS_DEFINE_MEMBERS_WORKER(AUTOINIT, CLASS_NAME,PARENT_CLASS,VERNO) \
GCRX_DEFINE_MEMBERS_WORKER(CLASS_NAME, AUTOINIT); \
void CLASS_NAME::rxInit() { \
  GCRX_STATIC_CHECK(CLASS_NAME); \
  gpDesc = newGcRxClass(GCRX_T(#CLASS_NAME), GCRX_T(#PARENT_CLASS), \
    VERNO, &gcrxInstantiateClass<CLASS_NAME>); \
}
#define GCRX_CONS_DEFINE_MEMBERS(CLASS_NAME,PARENT_CLASS,VERNO) \
GCRX_CONS_DEFINE_MEMBERS_WORKER(GCRX_AUTO_INIT_DEFAULT, CLASS_NAME, PARENT_CLASS, VERNO)

#define GCRX_CONS_DEFINE_MEMBERS_AUTO(CLASS_NAME,PARENT_CLASS,VERNO) \
GCRX_CONS_DEFINE_MEMBERS_WORKER(GCRX_AUTO_INIT_QUEUE_EXPR, CLASS_NAME, PARENT_CLASS, VERNO)

#define GCRX_DXF_DEFINE_MEMBERS(CLASS_NAME,PARENT_CLASS,DWG_VERSION,\
              MAINTENANCE_VERSION,PROXY_FLAGS,DXF_NAME,APP) \
GCRX_DEFINE_MEMBERS(CLASS_NAME); \
void CLASS_NAME::rxInit() { \
  GCRX_STATIC_CHECK(CLASS_NAME); \
  gpDesc = newGcRxClass(GCRX_T(#CLASS_NAME), GCRX_T(#PARENT_CLASS), \
    DWG_VERSION,MAINTENANCE_VERSION,PROXY_FLAGS, \
    &gcrxInstantiateClass<CLASS_NAME>, GCRX_T(#DXF_NAME), GCRX_T(#APP)); \
} \
void CLASS_NAME::rxInit(AppNameChangeFuncPtr ptr) { \
  GCRX_STATIC_CHECK(CLASS_NAME); \
  gpDesc = newGcRxClass(GCRX_T(#CLASS_NAME), GCRX_T(#PARENT_CLASS), \
    DWG_VERSION,MAINTENANCE_VERSION,PROXY_FLAGS, \
    &gcrxInstantiateClass<CLASS_NAME>, GCRX_T(#DXF_NAME), GCRX_T(#APP), ptr); \
}

#define GCRX_DXF_DEFINE_MEMBERS_WITH_PROPERTIES(CLASS_NAME,PARENT_CLASS,DWG_VERSION,\
              MAINTENANCE_VERSION,PROXY_FLAGS,DXF_NAME,APP, MAKEPROPS) \
GCRX_DEFINE_MEMBERS(CLASS_NAME); \
void CLASS_NAME::rxInit() { \
  GCRX_STATIC_CHECK(CLASS_NAME); \
  gpDesc = newGcRxClass(GCRX_T(#CLASS_NAME), GCRX_T(#PARENT_CLASS), \
    DWG_VERSION,MAINTENANCE_VERSION,PROXY_FLAGS, \
    &gcrxInstantiateClass<CLASS_NAME>, GCRX_T(#DXF_NAME), GCRX_T(#APP), NULL, MAKEPROPS); \
} \
void CLASS_NAME::rxInit(AppNameChangeFuncPtr ptr) { \
  GCRX_STATIC_CHECK(CLASS_NAME); \
  gpDesc = newGcRxClass(GCRX_T(#CLASS_NAME), GCRX_T(#PARENT_CLASS), \
    DWG_VERSION,MAINTENANCE_VERSION,PROXY_FLAGS, \
    &gcrxInstantiateClass<CLASS_NAME>, GCRX_T(#DXF_NAME), GCRX_T(#APP), ptr, MAKEPROPS); \
}
#pragma pack (pop)
#endif
