
#pragma once

#include "zacbasedefs.h"
#include "zadesk.h"
#include "zacadstrc.h"
#include "zpimplapi.h"
#include "zAcString.h"
#include "zacarray.h"
#include "zrxoverrule.h"

class ZcRxMemberImp;
class ZcRxMemberCollectionImp;
class ZcRxValue;
class ZcRxValueType;
class ZcRxAttributeCollection;
class ZcRxMemberIteratorImp;
class ZcRxMemberQueryContextImp;
class ZcRxMemberQueryEngineImp;
class ZcRxPromotingQueryContext;

class ZcRxMember : public Pimpl::ApiPart<ZcRxObject, ZcRxMemberImp>
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxMember, ZCBASE_PORT);

    ZCBASE_PORT const ZTCHAR* name() const throw();

    ZCBASE_PORT ZcString localName() const throw();

    ZCBASE_PORT const ZcRxValueType& type()const throw();

    ZCBASE_PORT const ZcRxAttributeCollection& attributes() const throw();

    ZCBASE_PORT ZcRxAttributeCollection& attributes() throw();

    ZCBASE_PORT const ZcRxObject* owner() const throw();

    ZCBASE_PORT const ZcArray<const ZcRxMember*>* children() const throw();

    ZCBASE_PORT static void deleteMember(const ZcRxMember* pMember) throw();

#pragma push_macro("new")
#undef new

    ZCBASE_PORT static void* operator new(size_t size);

    ZCBASE_PORT static void* operator new(size_t size, const char *pFName, int nLine);
#pragma pop_macro("new")
protected:
    friend class ZcRxMemberImp;
    ZCBASE_PORT virtual ~ZcRxMember() throw();
    ZCBASE_PORT ZcRxMember(ZcRxMemberImp*) throw();

    ZCBASE_PORT virtual ZcString subLocalName() const;

    ZCBASE_PORT virtual Zcad::ErrorStatus subChildren(ZcArray<const ZcRxMember*>& children) const;
#ifndef __clang__
protected:
#else
public:
#endif
#pragma push_macro("delete")
#undef delete

    ZCBASE_PORT static void operator delete(void *p);
    ZCBASE_PORT static void operator delete(void *p, const char *pFName, int nLine);
    ZCBASE_PORT static void operator delete[](void *p);
    ZCBASE_PORT static void operator delete[](void *p, const char *pFName, int nLine);
#pragma pop_macro("delete")    
private:
#pragma push_macro("new")
#undef new
    
    static void* operator new[](size_t size);
    static void* operator new[](size_t size, const char *pFName, int nLine);
#pragma pop_macro("new")    

    ZCBASE_PORT virtual Zcad::ErrorStatus subChildrenEx(ZcArray<const ZcRxMember*>*& pChildren) const;
};

class ZcRxEnumTag : public ZcRxMember
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxEnumTag, ZCBASE_PORT);

    ZCBASE_PORT ZcRxEnumTag(const ZTCHAR* name, const ZcRxValue& value) throw();

    ZCBASE_PORT const ZcRxValue& value() const;

    ZCBASE_PORT ZcString alternateLocalName() const;
protected:

    ZCBASE_PORT ~ZcRxEnumTag();

    ZCBASE_PORT virtual ZcString subAlternateLocalName() const;
};

class ZCBASE_PORT ZcRxMemberCollection : public Pimpl::ApiPart<void, ZcRxMemberCollectionImp>
{
public:

    virtual ~ZcRxMemberCollection();

    virtual int count() const;

    virtual ZcRxMember* getAt(int index) const;

protected:

    ZcRxMemberCollection();

private:
    friend class ZcRxMemberCollectionImp;
    ZcRxMemberCollection(ZcRxMemberCollectionImp* pImp);
};

class ZCBASE_PORT ZcRxMemberCollectionBuilder : public Pimpl::ApiPart<void, ZcRxMemberCollectionImp>
{
public:

    Zcad::ErrorStatus add(ZcRxMember* member);

    const ZcRxClass* owner() const;
private:
    friend class ZcRxMemberCollectionImp;
    ZcRxMemberCollectionBuilder(ZcRxMemberCollectionImp*, const ZcRxClass* owner);
    ~ZcRxMemberCollectionBuilder();
    const ZcRxClass* m_owner;
};

class ZCBASE_PORT ZcRxMemberIterator : public Pimpl::ApiPart<void, ZcRxMemberIteratorImp>
{
public:

    virtual ~ZcRxMemberIterator();

    virtual bool done();

    virtual bool next();

    virtual ZcRxMember* current() const;

    virtual ZcRxMember* find(const ZTCHAR* name) const;

protected:

    ZcRxMemberIterator();

private:
    friend class ZcRxMemberIteratorImp;
    ZcRxMemberIterator(ZcRxMemberIteratorImp*);
};

class ZcRxMemberQueryContext : public Pimpl::ApiPart<ZcRxObject, ZcRxMemberQueryContextImp>
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxMemberQueryContext, ZCBASE_PORT);

    ZCBASE_PORT ZcRxMemberIterator* newMemberIterator(const ZcArray<const ZcRxClass*>& facets) const;

protected:
    friend class ZcRxMemberQueryContextImp;

    ZCBASE_PORT ZcRxMemberQueryContext();

    ZCBASE_PORT virtual ~ZcRxMemberQueryContext();

    ZCBASE_PORT virtual ZcRxMemberIterator* subNewMemberIterator(const ZcArray<const ZcRxClass*>& facets) const = 0;
};

class ZcRxFacetProvider : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxFacetProvider, ZCBASE_PORT);

    ZCBASE_PORT virtual void getFacets(const ZcRxObject* pO, const ZcRxMemberQueryContext* pContext, ZcArray<const ZcRxClass*>& facets) = 0;
};

class ZCBASE_PORT ZcRxMemberReactor
{
public:

    virtual ~ZcRxMemberReactor() {}

	virtual void goodbye(const ZcRxMember* pMember) { (pMember); }
};

class ZCBASE_PORT ZcRxMemberQueryEngine: public Pimpl::ApiPart<void, ZcRxMemberQueryEngineImp>
{
public:

    static ZcRxMemberQueryEngine* theEngine();

    ZcRxMember* find(const ZcRxObject* pO, const ZTCHAR* name, const ZcRxMemberQueryContext* pContext = NULL) const;

    ZcRxMemberIterator* newMemberIterator(const ZcRxObject* pO, const ZcRxMemberQueryContext* pContext = NULL) const;

    const ZcRxMemberQueryContext* defaultContext();

    const ZcRxPromotingQueryContext* promotingContext();

    Zcad::ErrorStatus addFacetProvider(ZcRxFacetProvider* pProvider);

    Zcad::ErrorStatus removeFacetProvider(ZcRxFacetProvider* pProvider);

    void addReactor(ZcRxMemberReactor* pReactor);

    void removeReactor(ZcRxMemberReactor* pReactor);

private:
    friend class ZcRxMemberQueryEngineImp;
    ZcRxMemberQueryEngine(ZcRxMemberQueryEngineImp*);
    ~ZcRxMemberQueryEngine();

};

class ZcRxMemberOverrule : public ZcRxOverruleBase
{
public:

    struct Record
    {
        ZcRxMember* m_pMember;
        ZcRxMemberOverrule* m_pOverrule;
        Record()
            :m_pMember(NULL)
            ,m_pOverrule(NULL) {}
        Record(ZcRxMember* pMember, ZcRxMemberOverrule* pOverrule)
            :m_pMember(pMember)
            ,m_pOverrule(pOverrule) {}
    };
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxMemberOverrule, ZCBASE_PORT);

    ZCBASE_PORT static Zcad::ErrorStatus addOverrule(ZcRxMember* pOverruledSubject, ZcRxMemberOverrule* pOverrule, bool bAddAtLast = false);

    ZCBASE_PORT static Zcad::ErrorStatus removeOverrule( ZcRxMember* pOverruledSubject, ZcRxMemberOverrule* pOverrule);

    ZCBASE_PORT static Zcad::ErrorStatus removeOverrules(const ZcArray<Record>& overrules);
};

