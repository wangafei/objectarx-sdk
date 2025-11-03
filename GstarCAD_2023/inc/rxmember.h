/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcbasedefs.h"
#include "gsoft.h"
#include "gcadstrc.h"
#include "pimplapi.h"
#include "GcString.h"
#include "gcarray.h"
#include "rxoverrule.h"

class GcRxMemberImp;
class GcRxMemberCollectionImp;
class GcRxValue;
class GcRxValueType;
class GcRxAttributeCollection;
class GcRxMemberIteratorImp;
class GcRxMemberQueryContextImp;
class GcRxMemberQueryEngineImp;
class GcRxPromotingQueryContext;

class GCBASE_PORT GcRxMember : public Pimpl::ApiPart<GcRxObject, GcRxMemberImp>
{
public:
  GCRX_DECLARE_MEMBERS(GcRxMember);

  const GCHAR* name() const throw();
  GcString     localName() const throw();

  const GcRxValueType& type()const throw();

  const GcRxAttributeCollection& attributes() const throw();
  GcRxAttributeCollection&       attributes() throw();

  const GcRxObject* owner() const throw();

  const GcArray<const GcRxMember*>* children() const throw();

  static void deleteMember(const GcRxMember* pMember) throw();

#pragma push_macro("new")
#undef new
  static void* operator new(size_t size);
  static void* operator new(size_t size, const char *pFName, int nLine);
#pragma pop_macro("new")
protected:
  friend class GcRxMemberImp;
  ~GcRxMember() throw();
  GcRxMember(GcRxMemberImp*) throw();

  virtual GcString subLocalName() const;

  virtual Gcad::ErrorStatus subChildren(GcArray<const GcRxMember*>& children) const;
#ifndef __GNUC__
protected:
#else
public:
#endif
#pragma push_macro("delete")
#undef delete
  static void operator delete(void *p);
  static void operator delete(void *p, const char *pFName, int nLine);
  static void operator delete[](void *p);
  static void operator delete[](void *p, const char *pFName, int nLine);
#pragma pop_macro("delete")
private:
#pragma push_macro("new")
#undef new
  static void* operator new[](size_t size);
  static void* operator new[](size_t size, const char *pFName, int nLine);
#pragma pop_macro("new")

  virtual Gcad::ErrorStatus subChildrenEx(GcArray<const GcRxMember*>*& pChildren) const;
};

class GCBASE_PORT GcRxEnumTag : public GcRxMember
{
public:
  GCRX_DECLARE_MEMBERS(GcRxEnumTag);
  GcRxEnumTag(const GCHAR* name, const GcRxValue& value) throw();

  const GcRxValue& value() const;

  GcString alternateLocalName() const;
protected:
  ~GcRxEnumTag();
  virtual GcString subAlternateLocalName() const;
};

class GCBASE_PORT GcRxMemberCollection : public Pimpl::ApiPart<void, GcRxMemberCollectionImp>
{
public:
  virtual ~GcRxMemberCollection();

  virtual int count() const;

  virtual GcRxMember* getAt(int index) const;

protected:
  GcRxMemberCollection();

private:
  friend class GcRxMemberCollectionImp;
  GcRxMemberCollection(GcRxMemberCollectionImp* pImp);
};

class GCBASE_PORT GcRxMemberCollectionBuilder : public Pimpl::ApiPart<void, GcRxMemberCollectionImp>
{
public:
  Gcad::ErrorStatus add(GcRxMember* member);

  const GcRxClass* owner() const;
private:
  friend class GcRxMemberCollectionImp;
  GcRxMemberCollectionBuilder(GcRxMemberCollectionImp*, const GcRxClass* owner);
  ~GcRxMemberCollectionBuilder();
  const GcRxClass* m_owner;
};

class GCBASE_PORT GcRxMemberIterator : public Pimpl::ApiPart<void, GcRxMemberIteratorImp>
{
public:
  virtual ~GcRxMemberIterator();

  virtual bool done();
  virtual bool next();

  virtual GcRxMember* current() const;
  virtual GcRxMember* find(const GCHAR* name) const;

protected:
  GcRxMemberIterator();

private:
  friend class GcRxMemberIteratorImp;
  GcRxMemberIterator(GcRxMemberIteratorImp*);
};

class GCBASE_PORT GcRxMemberQueryContext : public Pimpl::ApiPart<GcRxObject, GcRxMemberQueryContextImp>
{
public:
  GCRX_DECLARE_MEMBERS(GcRxMemberQueryContext);
  GcRxMemberIterator* newMemberIterator(const GcArray<const GcRxClass*>& facets) const;

protected:
  friend class GcRxMemberQueryContextImp;

  GcRxMemberQueryContext();
  ~GcRxMemberQueryContext();

  virtual GcRxMemberIterator* subNewMemberIterator(const GcArray<const GcRxClass*>& facets) const = 0;
};

class GCBASE_PORT GcRxFacetProvider : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcRxFacetProvider);
  virtual void getFacets(const GcRxObject* pO, const GcRxMemberQueryContext* pContext, GcArray<const GcRxClass*>& facets) = 0;
};

class GCBASE_PORT GcRxMemberReactor
{
public:
  virtual ~GcRxMemberReactor() {}
  virtual void goodbye(const GcRxMember* pMember) { (pMember); }
};

class GCBASE_PORT GcRxMemberQueryEngine : public Pimpl::ApiPart<void, GcRxMemberQueryEngineImp>
{
public:
  static GcRxMemberQueryEngine* theEngine();

  GcRxMember* find(const GcRxObject* pO, const GCHAR* name, const GcRxMemberQueryContext* pContext = NULL) const;

  GcRxMemberIterator* newMemberIterator(const GcRxObject* pO, const GcRxMemberQueryContext* pContext = NULL) const;

  const GcRxMemberQueryContext* defaultContext();

  const GcRxPromotingQueryContext* promotingContext();

  Gcad::ErrorStatus addFacetProvider(GcRxFacetProvider* pProvider);
  Gcad::ErrorStatus removeFacetProvider(GcRxFacetProvider* pProvider);

  void addReactor(GcRxMemberReactor* pReactor);
  void removeReactor(GcRxMemberReactor* pReactor);

private:
  friend class GcRxMemberQueryEngineImp;
  GcRxMemberQueryEngine(GcRxMemberQueryEngineImp*);
  ~GcRxMemberQueryEngine();
};

class GCBASE_PORT GcRxMemberOverrule : public GcRxOverruleBase
{
public:
  struct Record
  {
    GcRxMember* m_pMember;
    GcRxMemberOverrule* m_pOverrule;
    Record() : m_pMember(NULL), m_pOverrule(NULL) {}
    Record(GcRxMember* pMember, GcRxMemberOverrule* pOverrule) : m_pMember(pMember), m_pOverrule(pOverrule) {}
  };
  GCRX_DECLARE_MEMBERS(GcRxMemberOverrule);
  static Gcad::ErrorStatus addOverrule(GcRxMember* pOverruledSubject, GcRxMemberOverrule* pOverrule, bool bAddAtLast = false);
  static Gcad::ErrorStatus removeOverrule(GcRxMember* pOverruledSubject, GcRxMemberOverrule* pOverrule);
  static Gcad::ErrorStatus removeOverrules(const GcArray<Record>& overrules);
};
