#ifndef _GCPLOBJECT_H
#define _GCPLOBJECT_H

#include "rxobject.h"
//#include "GcHeapOpers.h"
#include "Gcpl.h"

class GcPlObjectImp;

class GcPlObject : public GcRxObject//, public GcHeapOperators
{
public:
    GCRX_DECLARE_MEMBERS(GcPlObject);

    GCPL_PORT virtual ~GcPlObject();

protected:
    GcPlObject();
    GcPlObject(GcPlObjectImp*);

private:
    friend class GcPlObjectImp;
    GcPlObjectImp*  mpPlObjectImp;
};

// This macro is NOT intended for application-defined classes derived
// from AcPlObject when declaring their class header.  This macro declares
// an internally used form of constructor, which takes the
// AcPlSystemInternals* argument.  Rx applications should not define
// such constructors for their database object classes, but they should
// be ignored by the system anyway.
//
// Application-defined classes are advised to use the ACRX_DECLARE_MEMBERS
// macro instead, and to consult the documentation for related definitions.
//
#define GCPL_DECLARE_MEMBERS(CLASS_NAME) \
private: \
    friend class GcPlObjectImp;\
protected: \
    CLASS_NAME(GcPlObjectImp*); \
public: \
    GCPL_PORT virtual GcRxClass* isA() const; \
    GCPL_PORT static GcRxClass* g_pDesc; \
    GCPL_PORT static GcRxClass* desc(); \
    GCPL_PORT static CLASS_NAME* cast(const GcRxObject* inPtr) \
{ return ((inPtr == NULL) || !inPtr->isKindOf(CLASS_NAME::desc())) \
    ? NULL : (CLASS_NAME*)inPtr; }; \
    GCPL_PORT static void rxInit(); \
    GCPL_PORT static void rxUninit();\
    GCPL_PORT virtual OdRxObject* queryX(const OdRxClass* protocolClass) const;\
    GCPL_PORT static OdRxObjectPtr pseudoConstructor(); 
    

// Use this macro to define members of classes derived from AcPlObject
#define GCPL_DEFINE_MEMBERS(CLASS_NAME, BASE_CLASS) \
    GCRX_NO_CONS_DEFINE_MEMBERS(CLASS_NAME, BASE_CLASS) \
    CLASS_NAME::CLASS_NAME(GcPlObjectImp* pInternals) \
    : BASE_CLASS(pInternals) \
{ \
}

#endif // _GCPLOBJECT_H
