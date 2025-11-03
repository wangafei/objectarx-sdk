/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCPLOBJECT_H
#define GCPLOBJECT_H

#include "rxobject.h"
#include "GcHeapOpers.h"
#include "GcPl.h"

class GcPlObjectImp;
class GcPlSystemInternals;

class GSOFT_NO_VTABLE GcPlObject : public GcRxObject, public GcHeapOperators
{
public:
  GCRX_DECLARE_MEMBERS(GcPlObject);
  GCPL_PORT virtual ~GcPlObject();

protected:
  GcPlObject();
  GcPlObject(GcPlSystemInternals*);

private:
  friend class GcPlSystemInternals;
#pragma push_macro("mpPlObjectImp")
#undef mpPlObjectImp
  GcPlObjectImp*  mpPlObjectImp;
#pragma pop_macro("mpPlObjectImp")
};

#define GCPL_DECLARE_MEMBERS(CLASS_NAME) \
private: \
    friend class GcPlSystemInternals; \
protected: \
    CLASS_NAME(GcPlSystemInternals*); \
public: \
    GCPL_PORT virtual GcRxClass* isA() const; \
    GCPL_PORT static GcRxClass* gpDesc; \
    GCPL_PORT static GcRxClass* desc(); \
    GCPL_PORT static CLASS_NAME* cast(const GcRxObject* inPtr) \
        { return ((inPtr == NULL) || !inPtr->isKindOf(CLASS_NAME::desc())) \
          ? NULL : (CLASS_NAME*)inPtr; }; \
    GCPL_PORT static void rxInit(); \
    GCPL_PORT static void rxInit(AppNameChangeFuncPtr);

#ifndef _GCPL_BUILD
#define GCPL_NO_CONS_DEFINE_MEMBERS GCRX_NO_CONS_DEFINE_MEMBERS
#else
#define GCPL_NO_CONS_DEFINE_MEMBERS GCRX_NO_CONS_DEFINE_MEMBERS_AUTO
#endif

#define GCPL_DEFINE_MEMBERS(CLASS_NAME, BASE_CLASS) \
GCPL_NO_CONS_DEFINE_MEMBERS(CLASS_NAME, BASE_CLASS) \
CLASS_NAME::CLASS_NAME(GcPlSystemInternals* pInternals) \
: BASE_CLASS(pInternals) \
{ \
}

#endif 