
#pragma once
#include "zacbasedefs.h"
#include "zadesk.h"
#include "zacadstrc.h"
#include "zrxmember.h"

#define ZXRES_RESOURCE_HINT 0
#define ZCAXTLB_RESOURCE_HINT 1
#define ZCAUTHENTITIESTLB_RESOURCE_HINT 2
#define ZCOPMRES_RESOURCE_HINT 3
#define ZCSCENERES_RESOURCE_HINT 4

class ZcRxValue;
class ZcRxValueType;
class ZcRxClass;
class ZcRxObject;
class ZcRxAttributeCollection;
class ZcRxPropertyBaseImp;
class ZcRxValueIteratorImp;
class ZcRxPropertyIteratorImp;
class ZcRxPropertyQueryContextImp;
class ZcRxPropertyQueryEngineImp;
class ZcRxDictionaryPropertyImp;
class ZcRxPropertyImp;
class ZcRxCollectionPropertyImp;
class ZcRxIndexedPropertyImp;

class ZcRxPropertyBase : public ZcRxMember
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxPropertyBase, ZCBASE_PORT);

    ZCBASE_PORT bool isReadOnly(const ZcRxObject* pO) const;
protected:
    ZCBASE_PORT ~ZcRxPropertyBase();
    ZCBASE_PORT ZcRxPropertyBase(ZcRxPropertyBaseImp*);
};

class ZcRxProperty : public ZcRxPropertyBase
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxProperty, ZCBASE_PORT);

    ZCBASE_PORT Zcad::ErrorStatus getValue(const ZcRxObject* pO, ZcRxValue& value) const;

    ZCBASE_PORT Zcad::ErrorStatus setValue(ZcRxObject* pO, const ZcRxValue& value) const;

protected:

    ZCBASE_PORT ~ZcRxProperty();

    ZCBASE_PORT  ZcRxProperty(const ZTCHAR* name, const ZcRxValueType& type, const ZcRxObject* owner=NULL) throw();

    ZCBASE_PORT virtual Zcad::ErrorStatus subGetValue(const ZcRxObject* pO, ZcRxValue& value) const;

    ZCBASE_PORT virtual Zcad::ErrorStatus subSetValue(ZcRxObject* pO, const ZcRxValue& value) const;

    friend class ZcRxPropertyImp;
    friend class ZcRxPropertyOverrule;
    ZcRxProperty(ZcRxPropertyImp*);
};

class ZcRxPropertyOverrule : public ZcRxMemberOverrule
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxPropertyOverrule, ZCBASE_PORT);

    ZCBASE_PORT virtual Zcad::ErrorStatus getValue(const ZcRxProperty* pProp, const ZcRxObject* pO, ZcRxValue& value) const ;

    ZCBASE_PORT virtual Zcad::ErrorStatus setValue(const ZcRxProperty* pProp, ZcRxObject* pO, const ZcRxValue& value) const ;
};

class ZcRxPromotingQueryContext: public ZcRxMemberQueryContext
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxPromotingQueryContext, ZCBASE_PORT);
};

class ZCBASE_PORT ZcRxValueIterator : public Pimpl::ApiPart<void,ZcRxValueIteratorImp>
{
public:

    virtual ~ZcRxValueIterator();

    virtual bool done();

    virtual bool next();

    virtual ZcRxValue current() const;
protected:

    ZcRxValueIterator();
private:
    friend class ZcRxValueIteratorImp;
    ZcRxValueIterator(ZcRxValueIteratorImp*);
};

class ZcRxCollectionProperty : public ZcRxPropertyBase
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxCollectionProperty, ZCBASE_PORT);

    ZCBASE_PORT ZcRxValueIterator* newValueIterator(const ZcRxObject* pO) const;

    ZCBASE_PORT Zcad::ErrorStatus tryGetCount(const ZcRxObject* pO, int& count) const;
protected:

    ZCBASE_PORT ~ZcRxCollectionProperty();

    ZCBASE_PORT virtual ZcRxValueIterator* subNewValueIterator(const ZcRxObject* pO) const;

    ZCBASE_PORT virtual Zcad::ErrorStatus subTryGetCount(const ZcRxObject* pO, int& count) const;

    ZCBASE_PORT ZcRxCollectionProperty(const ZTCHAR* name, const ZcRxValueType& type, const ZcRxObject* owner = NULL);

    friend class ZcRxCollectionPropertyImp;
    friend class ZcRxCollectionPropertyOverrule;
    ZcRxCollectionProperty(ZcRxCollectionPropertyImp* pImp);
};

class ZcRxCollectionPropertyOverrule : public ZcRxMemberOverrule
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxCollectionPropertyOverrule, ZCBASE_PORT);
    ZCBASE_PORT virtual ZcRxValueIterator* newValueIterator(const ZcRxCollectionProperty* pProp, const ZcRxObject* pO) const;
    ZCBASE_PORT virtual Zcad::ErrorStatus tryGetCount(const ZcRxCollectionProperty* pProp, const ZcRxObject* pO, int& count) const;
};

class ZcRxIndexedProperty : public ZcRxCollectionProperty
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxIndexedProperty, ZCBASE_PORT);

    ZCBASE_PORT Zcad::ErrorStatus getValue(const ZcRxObject* pO, int index, ZcRxValue& value) const;

    ZCBASE_PORT Zcad::ErrorStatus setValue(ZcRxObject* pO, int index, const ZcRxValue& value) const;

    ZCBASE_PORT Zcad::ErrorStatus insertValue(ZcRxObject* pO, int index, const ZcRxValue& value) const;

    ZCBASE_PORT Zcad::ErrorStatus removeValue(ZcRxObject* pO, int index) const;
protected:

    ZCBASE_PORT ~ZcRxIndexedProperty();

	ZCBASE_PORT virtual Zcad::ErrorStatus subGetValue(const ZcRxObject* pO, int index, ZcRxValue& value) const;

    ZCBASE_PORT virtual Zcad::ErrorStatus subSetValue(ZcRxObject* pO, int index, const ZcRxValue& value) const;

    ZCBASE_PORT virtual Zcad::ErrorStatus subInsertValue(ZcRxObject* pO, int index, const ZcRxValue& value) const;

    ZCBASE_PORT virtual Zcad::ErrorStatus subRemoveValue(ZcRxObject* pO, int index) const;

    ZCBASE_PORT ZcRxIndexedProperty(const ZTCHAR* name, const ZcRxValueType& type, const ZcRxObject* owner= NULL);
private:
    friend class ZcRxIndexedPropertyImp;
	ZCBASE_PORT ZcRxIndexedProperty(ZcRxIndexedPropertyImp* pImp);

};

class ZcRxDictionaryProperty : public ZcRxCollectionProperty
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxDictionaryProperty, ZCBASE_PORT);

    ZCBASE_PORT Zcad::ErrorStatus getValue(const ZcRxObject* pO, const ZTCHAR* key, ZcRxValue& value) const;

    ZCBASE_PORT Zcad::ErrorStatus setValue(ZcRxObject* pO, const ZTCHAR* key, const ZcRxValue& value) const;

protected:

    ZCBASE_PORT ~ZcRxDictionaryProperty();

    ZCBASE_PORT virtual Zcad::ErrorStatus subGetValue(const ZcRxObject* pO, const ZTCHAR* key, ZcRxValue& value) const;

    ZCBASE_PORT virtual Zcad::ErrorStatus subSetValue(ZcRxObject* pO, const ZTCHAR* key, const ZcRxValue& value) const;

    ZCBASE_PORT ZcRxDictionaryProperty(const ZTCHAR* name, const ZcRxValueType& type, const ZcRxObject* owner=NULL);

private:
    friend class ZcRxDictionaryPropertyImp;
	ZCBASE_PORT ZcRxDictionaryProperty(ZcRxDictionaryPropertyImp* pImp);
};
