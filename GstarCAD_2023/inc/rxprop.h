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
#include "rxmember.h"

#define GXRES_RESOURCE_HINT             0
#define GCAXTLB_RESOURCE_HINT           1
#define GCAUTHENTITIESTLB_RESOURCE_HINT 2
#define GCOPMRES_RESOURCE_HINT          3
#define GCSCENERES_RESOURCE_HINT        4

class GcRxValue;
class GcRxValueType;
class GcRxClass;
class GcRxObject;
class GcRxAttributeCollection;
class GcRxPropertyBaseImp;
class GcRxValueIteratorImp;
class GcRxPropertyIteratorImp;
class GcRxPropertyQueryContextImp;
class GcRxPropertyQueryEngineImp;
class GcRxDictionaryPropertyImp;
class GcRxPropertyImp;
class GcRxCollectionPropertyImp;
class GcRxIndexedPropertyImp;

class GCBASE_PORT GcRxPropertyBase : public GcRxMember
{
public:
  GCRX_DECLARE_MEMBERS(GcRxPropertyBase);
  bool isReadOnly(const GcRxObject* pO) const;
protected:
  ~GcRxPropertyBase();
  GcRxPropertyBase(GcRxPropertyBaseImp*);
};

class GCBASE_PORT GcRxProperty : public GcRxPropertyBase
{
public:
  GCRX_DECLARE_MEMBERS(GcRxProperty);
  Gcad::ErrorStatus getValue(const GcRxObject* pO, GcRxValue& value) const;
  Gcad::ErrorStatus setValue(GcRxObject* pO, const GcRxValue& value) const;

protected:
  ~GcRxProperty();
  GcRxProperty(const GCHAR* name, const GcRxValueType& type, const GcRxObject* owner = NULL) throw();

  virtual Gcad::ErrorStatus subGetValue(const GcRxObject* pO, GcRxValue& value) const;
  virtual Gcad::ErrorStatus subSetValue(GcRxObject* pO, const GcRxValue& value) const;

  friend class GcRxPropertyImp;
  friend class GcRxPropertyOverrule;
  GcRxProperty(GcRxPropertyImp*);
};

class GCBASE_PORT GcRxPropertyOverrule : public GcRxMemberOverrule
{
public:
  GCRX_DECLARE_MEMBERS(GcRxPropertyOverrule);
  virtual Gcad::ErrorStatus getValue(const GcRxProperty* pProp, const GcRxObject* pO, GcRxValue& value) const;
  virtual Gcad::ErrorStatus setValue(const GcRxProperty* pProp, GcRxObject* pO, const GcRxValue& value) const;
};

class GcRxPromotingQueryContext : public GcRxMemberQueryContext
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxPromotingQueryContext, GCBASE_PORT);
};

class GCBASE_PORT GcRxValueIterator : public Pimpl::ApiPart<void, GcRxValueIteratorImp>
{
public:
  virtual ~GcRxValueIterator();

  virtual bool done();
  virtual bool next();

  virtual GcRxValue current() const;
protected:
  GcRxValueIterator();

private:
  friend class GcRxValueIteratorImp;
  GcRxValueIterator(GcRxValueIteratorImp*);
};

class GCBASE_PORT GcRxCollectionProperty : public GcRxPropertyBase
{
public:
  GCRX_DECLARE_MEMBERS(GcRxCollectionProperty);

  GcRxValueIterator* newValueIterator(const GcRxObject* pO) const;

  Gcad::ErrorStatus tryGetCount(const GcRxObject* pO, int& count) const;
protected:
  ~GcRxCollectionProperty();
  virtual GcRxValueIterator* subNewValueIterator(const GcRxObject* pO) const;

  virtual Gcad::ErrorStatus subTryGetCount(const GcRxObject* pO, int& count) const;

  GcRxCollectionProperty(const GCHAR* name, const GcRxValueType& type, const GcRxObject* owner = NULL);

  friend class GcRxCollectionPropertyImp;
  friend class GcRxCollectionPropertyOverrule;
  GcRxCollectionProperty(GcRxCollectionPropertyImp* pImp);
};

class GCBASE_PORT GcRxCollectionPropertyOverrule : public GcRxMemberOverrule
{
public:
  GCRX_DECLARE_MEMBERS(GcRxCollectionPropertyOverrule);
  virtual GcRxValueIterator* newValueIterator(const GcRxCollectionProperty* pProp, const GcRxObject* pO) const;
  virtual Gcad::ErrorStatus tryGetCount(const GcRxCollectionProperty* pProp, const GcRxObject* pO, int& count) const;
};

class GCBASE_PORT GcRxIndexedProperty : public GcRxCollectionProperty
{
public:
  GCRX_DECLARE_MEMBERS(GcRxIndexedProperty);
  Gcad::ErrorStatus getValue(const GcRxObject* pO, int index, GcRxValue& value) const;
  Gcad::ErrorStatus setValue(GcRxObject* pO, int index, const GcRxValue& value) const;
  Gcad::ErrorStatus insertValue(GcRxObject* pO, int index, const GcRxValue& value) const;
  Gcad::ErrorStatus removeValue(GcRxObject* pO, int index) const;

protected:
  ~GcRxIndexedProperty();
  virtual Gcad::ErrorStatus subGetValue(const GcRxObject* pO, int index, GcRxValue& value) const;
  virtual Gcad::ErrorStatus subSetValue(GcRxObject* pO, int index, const GcRxValue& value) const;
  virtual Gcad::ErrorStatus subInsertValue(GcRxObject* pO, int index, const GcRxValue& value) const;
  virtual Gcad::ErrorStatus subRemoveValue(GcRxObject* pO, int index) const;

  GcRxIndexedProperty(const GCHAR* name, const GcRxValueType& type, const GcRxObject* owner = NULL);

private:
  friend class GcRxIndexedPropertyImp;
  GcRxIndexedProperty(GcRxIndexedPropertyImp* pImp);
};

class GCBASE_PORT GcRxDictionaryProperty : public GcRxCollectionProperty
{
public:
  GCRX_DECLARE_MEMBERS(GcRxDictionaryProperty);
  Gcad::ErrorStatus getValue(const GcRxObject* pO, const GCHAR* key, GcRxValue& value) const;
  Gcad::ErrorStatus setValue(GcRxObject* pO, const GCHAR* key, const GcRxValue& value) const;

protected:
  ~GcRxDictionaryProperty();
  virtual Gcad::ErrorStatus subGetValue(const GcRxObject* pO, const GCHAR* key, GcRxValue& value) const;
  virtual Gcad::ErrorStatus subSetValue(GcRxObject* pO, const GCHAR* key, const GcRxValue& value) const;

  GcRxDictionaryProperty(const GCHAR* name, const GcRxValueType& type, const GcRxObject* owner = NULL);

private:
  friend class GcRxDictionaryPropertyImp;
  GcRxDictionaryProperty(GcRxDictionaryPropertyImp* pImp);
};
