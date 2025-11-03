

#ifndef ZCPLOBJECT_H
#define ZCPLOBJECT_H

#include "zrxobject.h"
#include "zAcHeapOpers.h"
#include "zacpl.h"

class ZcPlObjectImp;
class ZcPlSystemInternals;

class ZCPL_PORT ZSOFT_NO_VTABLE ZcPlObject : public ZcRxObject, public ZcHeapOperators
{
public:
    ZCRX_DECLARE_MEMBERS(ZcPlObject);
    
    virtual ~ZcPlObject();

protected:
    ZcPlObject();
    ZcPlObject(ZcPlSystemInternals*);

private:
    friend class ZcPlSystemInternals;
#pragma push_macro("mpPlObjectImp")
#undef mpPlObjectImp
    ZcPlObjectImp*  mpPlObjectImp;
#pragma pop_macro("mpPlObjectImp")

};

#define ZCPL_DECLARE_MEMBERS(CLASS_NAME) \
private: \
    friend class ZcPlSystemInternals; \
protected: \
    CLASS_NAME(ZcPlSystemInternals*); \
public: \
    ZCPL_PORT virtual ZcRxClass* isA() const; \
    ZCPL_PORT static ZcRxClass* gpDesc; \
    ZCPL_PORT static ZcRxClass* desc(); \
    ZCPL_PORT static CLASS_NAME* cast(const ZcRxObject* inPtr) \
        { return ((inPtr == NULL) || !inPtr->isKindOf(CLASS_NAME::desc())) \
          ? NULL : (CLASS_NAME*)inPtr; }; \
    ZCPL_PORT static void rxInit(); \
    ZCPL_PORT static void rxInit(AppNameChangeFuncPtr);

#ifndef _ZCPL_BUILD
#define ZCPL_NO_CONS_DEFINE_MEMBERS ZCRX_NO_CONS_DEFINE_MEMBERS
#else
#define ZCPL_NO_CONS_DEFINE_MEMBERS ZCRX_NO_CONS_DEFINE_MEMBERS_AUTO
#endif

#define ZCPL_DEFINE_MEMBERS(CLASS_NAME, BASE_CLASS) \
ZCPL_NO_CONS_DEFINE_MEMBERS(CLASS_NAME, BASE_CLASS) \
CLASS_NAME::CLASS_NAME(ZcPlSystemInternals* pInternals) \
: BASE_CLASS(pInternals) \
{ \
}
        
#endif 
