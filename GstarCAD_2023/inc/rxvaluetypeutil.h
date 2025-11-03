/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "rxmember.h"
#include "rxvalue.h"
#include "gcarray.h"

template<typename ValueType>
class GcRxValueTypePOD : public GcRxValueType
{
public:
  GcRxValueTypePOD(const GCHAR* name, GcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL) :GcRxValueType(name, sizeof(ValueType), memberConstruct, userData) {}
  GcRxValueTypePOD(const GCHAR* name, const IGcRxEnumeration& pEnum, GcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL) :GcRxValueType(name, pEnum, sizeof(ValueType), memberConstruct, userData) {}
  GcRxValueTypePOD(const GCHAR* name, const IGcRxReferenceType& pRef, GcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL) :GcRxValueType(name, pRef, sizeof(ValueType), memberConstruct, userData) {}

  int  subToString(const void* instance, GCHAR* buffer, size_t sizeInGCHARs, GcRxValueType::StringFormat format) const override;
  bool subEqualTo(const void* a, const void* b) const override;
};

#ifdef __GNUC__
template<typename ValueType>
int GcRxValueTypePOD<ValueType>::subToString(const void* instance, GCHAR* buffer, size_t sizeInGCHARs, GcRxValueType::StringFormat format) const
{
  return -1;
}
template<typename ValueType>
bool GcRxValueTypePOD<ValueType>::subEqualTo(const void* a, const void* b) const
{
  return false;
}
#endif

#pragma warning(push)
#pragma warning(disable: 4355) 
template<typename ValueType>
class GcRxEnumType : public GcRxValueTypePOD<ValueType>, public IGcRxEnumeration
{
  GcArray<const GcRxEnumTag*> m_tags;
public:
  GcRxEnumType(const GCHAR* name, GcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL)
    :GcRxValueTypePOD<ValueType>(name, *this, memberConstruct, userData) {}
  ~GcRxEnumType()
  {
    for (int i = m_tags.length() - 1; i >= 0; i--)
      GcRxMember::deleteMember(m_tags[i]);
  }
  int count() const override
  {
    return m_tags.length();
  }
  const GcRxEnumTag& getAt(int i) const override
  {
    return *m_tags[i];
  }
  void append(GcRxEnumTag& tag)
  {
    m_tags.append(&tag);
    void gcdbImpSetOwnerForEnumTag(const GcRxClass*, GcRxEnumTag*);
    gcdbImpSetOwnerForEnumTag(this, &tag);
  }
#ifdef __GNUC__
  int  subToString(const void* instance, GCHAR* buffer, size_t sizeInGCHARs, GcRxValueType::StringFormat format) const override;
  bool subEqualTo(const void* a, const void* b) const override;
#endif
};
#pragma warning(pop)

template<typename T>
class GcRxNonBlittableType : public GcRxValueType
{
  class NonBlittable : public IGcRxNonBlittableType
  {
    void construct(void* dest, const void* source) const override
    {
      ::new ((GcRxValue*)dest) T(*(T*)source);
    }
    void assign(void* dest, const void* source) const override
    {
      ((T*)dest)->operator =(*(T*)source);
    }
    void destruct(const void* instance) const override
    {
      ((T*)instance)->~T();
    }
  } m_nonBlittable;
  int  subToString(const void* instance, GCHAR* buffer, size_t sizeInGCHARs, GcRxValueType::StringFormat format) const override;
  bool subEqualTo(const void* a, const void* b) const override;
public:
  GcRxNonBlittableType(const GCHAR* name, const GCHAR* parent, GcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL) :GcRxValueType(name, parent, m_nonBlittable, sizeof(T), memberConstruct, userData) {}
  GcRxNonBlittableType(const GCHAR* name, GcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL) :GcRxValueType(name, m_nonBlittable, sizeof(T), memberConstruct, userData) {}
  GcRxNonBlittableType(const GCHAR* name, const IGcRxEnumeration& enumeration, GcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL) :GcRxValueType(name, enumeration, m_nonBlittable, sizeof(T), memberConstruct, userData) {}
  GcRxNonBlittableType(const GCHAR* name, const IGcRxObjectValue& rxObjValue, GcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL) :GcRxValueType(name, rxObjValue, m_nonBlittable, sizeof(T), memberConstruct, userData) {}
};
