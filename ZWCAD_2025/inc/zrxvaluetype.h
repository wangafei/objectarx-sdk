
#pragma once
#include "zacbasedefs.h"
#include <memory.h>
#include <type_traits>
#include "zacutasrt.h"
#include "zrxclass.h"

class ZcRxProperty;
class ZcRxValue;
#ifdef NDEBUG
#define ZCRXVALUE_ASSERT(x)
#else
#define ZCRXVALUE_ASSERT(x) if (!(x)) zcutAssertMessage(ZCRX_T(#x), ZCRX_T(__FILE__), __LINE__, 0 ); else
#endif

class IZcRxNonBlittableType
{
public:

    virtual void construct(void* dest, const void* source) const = 0;

    virtual void assign(void* dest, const void* source) const = 0;

    virtual void destruct(const void* instance) const =0;
};

class ZcRxEnumTag;
class IZcRxEnumeration
{
public:

    virtual int count() const = 0;

    virtual const ZcRxEnumTag& getAt(int index) const = 0;
};

class IZcRxReferenceType
{
public:
    enum OpenMode          { kForRead           = 0,
                            kForWrite          = 1,
                            kForNotify         = 2 };

    virtual ZcRxObject* beginDereferencing(const ZcRxValue& value, OpenMode mode) const = 0;

    virtual Zcad::ErrorStatus endDereferencing(ZcRxObject* pO) const = 0;
};

class IZcRxObjectValue
{
public:
    virtual const ZcRxObject* getRxObject(const ZcRxValue& value) const = 0;
};

class ZcRxValueType :public ZcRxClass
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxValueType, ZCBASE_PORT);

    ZCBASE_PORT ~ZcRxValueType();

    bool operator==(const ZcRxValueType& rhs) const
    {
        return this == &rhs;
    }

    bool operator!=(const ZcRxValueType& rhs) const
    {
        return this != &rhs;
    }

    ZCBASE_PORT static __declspec(noreturn) void badCast();

    unsigned int size() const { return m_size;}

    bool isBlittable() const { return m_pNonBlittable==0;}

    bool isEnum() const {return m_pEnum!=0;}

    bool isReference() const { return m_pRef!=0;}

    const IZcRxNonBlittableType* nonBlittable() const {return m_pNonBlittable;}

    const IZcRxEnumeration* enumeration() const {return m_pEnum;}

    const IZcRxReferenceType* reference() const {return m_pRef;}

    const IZcRxObjectValue* rxObjectValue() const {return m_pRxObjValue;}

    enum StringFormat
    {
        kStringFormatGlobal = 0,
        kStringFormatCurrent = 1,
    };

    int toString(const void* instance, ZTCHAR* buffer, size_t sizeInZTCHARs, StringFormat format) const
    {
        ZCRXVALUE_ASSERT(instance!=NULL);
        if (instance==NULL)
            return -1;
        ZCRXVALUE_ASSERT((sizeInZTCHARs==0) == (buffer==NULL));
        if ((sizeInZTCHARs==0) != (buffer==NULL))
            return -1;

        return subToString(instance, buffer, sizeInZTCHARs, format);
    }

    bool equalTo(const void* a, const void* b) const
    {
        ZCRXVALUE_ASSERT(a!=NULL);
        if (a==NULL)
            return false;
        ZCRXVALUE_ASSERT(b!=NULL);
        if (b==NULL)
            return false;
        return subEqualTo(a, b);
    }

    template<typename ValueType>
    struct Desc
    {
        static const ZcRxValueType& value() throw();
        static void del();
    };
protected:

    ZCBASE_PORT ZcRxValueType(const ZTCHAR* name, const ZTCHAR* parent, const IZcRxNonBlittableType& nonBlittable, unsigned int size, ZcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL);

    ZCBASE_PORT ZcRxValueType(const ZTCHAR* name, unsigned int size, ZcRxMemberCollectionConstructorPtr memberConstruct, void *userData = NULL);

    ZCBASE_PORT ZcRxValueType(const ZTCHAR* name, const IZcRxNonBlittableType& pNonBlittable, unsigned int size, ZcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL);

    ZCBASE_PORT ZcRxValueType(const ZTCHAR* name, const IZcRxEnumeration& pEnum, unsigned int size, ZcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL);

    ZCBASE_PORT ZcRxValueType(const ZTCHAR* name, const IZcRxEnumeration& pEnum, const IZcRxNonBlittableType& pNonBlittable, unsigned int size, ZcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL);
    ZCBASE_PORT ZcRxValueType(const ZTCHAR* name, const IZcRxEnumeration* pEnum, const IZcRxNonBlittableType* pNonBlittable, unsigned int size, ZcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL);

    ZCBASE_PORT ZcRxValueType(const ZTCHAR* name, const IZcRxReferenceType& pRef, unsigned int size, ZcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL);

    ZCBASE_PORT ZcRxValueType(const ZTCHAR* name, const IZcRxObjectValue& rxObjValue, const IZcRxNonBlittableType& pNonBlittable, unsigned int size, ZcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL);
private:
    virtual int subToString(const void* instance, ZTCHAR* buffer, size_t sizeInZTCHARs, StringFormat format) const = 0;
    virtual bool subEqualTo(const void* a, const void* b) const = 0;
    ZcRxValueType(const ZcRxValueType& rhs);
    ZcRxValueType& operator=(const ZcRxValueType& rhs);

    IZcRxNonBlittableType* m_pNonBlittable = nullptr;
    IZcRxEnumeration* m_pEnum = nullptr;
    IZcRxReferenceType* m_pRef = nullptr;
    IZcRxObjectValue* m_pRxObjValue = nullptr;
    void* m_unused1 = nullptr;
    unsigned int m_size = 0;

};

template<> struct ZcRxValueType::Desc<void>
{
    ZCBASE_PORT static const ZcRxValueType& value() throw();
    static void del();
};

namespace ZwRx {
	class Storage;
}
#pragma push_macro("new")
#undef new

inline void* operator new(size_t size, ZwRx::Storage* loc) { ZSOFT_UNREFED_PARAM(size); return loc;}
#pragma pop_macro("new")

#pragma push_macro("delete")
#undef delete
inline void operator delete(void* p, ZwRx::Storage* loc) { ZSOFT_UNREFED_PARAM(p); ZSOFT_UNREFED_PARAM(loc); }
#pragma pop_macro("delete")

