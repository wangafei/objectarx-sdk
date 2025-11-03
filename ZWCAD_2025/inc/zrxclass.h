#pragma once

#include "zacbasedefs.h"
#include "zrxobject.h"
#include "zAdAChar.h"

#pragma pack (push, 8)

class ZcRxMemberCollection;
class ZcRxAttributeCollection;
class ZcRxSet;
class ZcRxImpClass;
class ZcRxMemberCollectionBuilder;
typedef void (*ZcRxMemberCollectionConstructorPtr)(ZcRxMemberCollectionBuilder&, void*);


class ZcRxClass: public ZcRxObject
{
public:
	ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxClass, ZCBASE_PORT);

    ZCBASE_PORT ZcRxObject* addX(ZcRxClass*, ZcRxObject*);
    ZCBASE_PORT ZcRxObject* getX(const ZcRxClass*);
    ZCBASE_PORT ZcRxObject* delX(ZcRxClass*);
    ZCBASE_PORT ZcRxObject* queryX(const ZcRxClass*);

    ZCBASE_PORT ZcRxObject* queryX(const ZcRxClass*) const;
    ZCBASE_PORT ZcRxObject* create();
    ZCBASE_PORT const ZTCHAR* appName() const;
    ZCBASE_PORT const ZTCHAR* dxfName() const;
    ZCBASE_PORT const ZTCHAR* name() const;
    ZCBASE_PORT void        getClassVersion(int& dwgVer,
                    int& maintVer) const;
    ZCBASE_PORT int         proxyFlags() const;

    bool isDerivedFrom(const ZcRxClass*) const;
    static ZCBASE_PORT bool isDerivedFrom(const ZcRxClass *pDerived, const ZcRxClass* pBase);
    ZCBASE_PORT ZcRxClass*     myParent() const;
    ZCBASE_PORT ZcRx::Ordering comparedTo(const ZcRxObject*) const override;

    ZCBASE_PORT AppNameChangeFuncPtr appNameCallbackPtr() const;
	
    ZCBASE_PORT const ZcRxSet* descendants() const;
    ZCBASE_PORT ZcRxMemberCollection* members() const;
    ZCBASE_PORT const ZcRxAttributeCollection& attributes() const;
    ZCBASE_PORT ZcRxAttributeCollection& attributes();
	
protected:
    ZcRxClass(const ZTCHAR* name, const ZTCHAR* parent,
        ZcRxMemberCollectionConstructorPtr  memberConstruct, void* userData);
    ~ZcRxClass();
private:
    void isKindOf(void *);
	ZcRxClass();
	friend class ZcRxImpClass;
	ZcRxImpClass* m_pImp;
    ZcRxClass(const ZcRxClass &) = delete;
    ZcRxClass operator = (const ZcRxClass &) = delete;
};

ZCBASE_PORT ZcRxClass* newZcRxClass(
    const ZTCHAR* className,
    const ZTCHAR* parentClassName,
    int         proxyFlags = 0,
    ZcRxObject* (*pseudoConstructor)() = NULL,
    const ZTCHAR* dxfName = NULL,
    const ZTCHAR* appName = NULL);

ZCBASE_PORT ZcRxClass* newZcRxClass(
    const ZTCHAR* className,
    const ZTCHAR* parentClassName,
    int         dwgVer,
    int         maintVer,
    int         proxyFlags = 0,
    ZcRxObject* (*pseudoConstructor)() = NULL,
    const ZTCHAR* dxfName = NULL,
    const ZTCHAR* appName = NULL,
    AppNameChangeFuncPtr func = NULL);

ZCBASE_PORT ZcRxClass* newZcRxClass(
	const ZTCHAR* className,
	const ZTCHAR* parentClassName,
	int         dwgVer,
	int         maintVer,
	int         proxyFlags ,
	ZcRxObject* (*pseudoConstructor)() ,
	const ZTCHAR* dxfName ,
	const ZTCHAR* appName ,
	AppNameChangeFuncPtr func,
	ZcRxMemberCollectionConstructorPtr makeMembers,
	void* userData = NULL);

ZCBASE_PORT void zcrxBuildClassHierarchy();

ZSOFT_DEPRECATE_FOR_INTERNAL_USE ZCBASE_PORT void deleteZcRxClass(ZcRxClass* pClassObj);

template <class RXClass>
void deleteZcRxClass()
{
    ZSOFT_SUPPRESS_DEPRECATED
    deleteZcRxClass(RXClass::gpDesc);
    RXClass::gpDesc = nullptr;
}

inline bool ZcRxClass::isDerivedFrom(const ZcRxClass* pOtherClass) const
{
    return ZcRxClass::isDerivedFrom(this, pOtherClass);
}

inline bool ZcRxObject::isKindOf(const ZcRxClass* pOtherClass) const
{
    //return ZcRxClass::isDerivedFrom(this->isA(), pOtherClass);
    const ZcRxClass * pMyClass = this->isA();
    return pMyClass == NULL ? false : pMyClass->isDerivedFrom(pOtherClass);
}

typedef void(*RxInitFuncPtr)();
#ifndef _DEBUG
ZcRxClass* zcrxQueueClassForInitialization(ZcRxClass** pgpDesc, RxInitFuncPtr rxInit);
#else
ZcRxClass* zcrxQueueClassForInitialization(ZcRxClass** pgpDesc, RxInitFuncPtr rxInit, const wchar_t* className);
#endif
#pragma pack (pop)

