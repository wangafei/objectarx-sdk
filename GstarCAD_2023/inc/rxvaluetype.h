/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "gcbasedefs.h"
#include <memory.h>
#include <type_traits>
#include "gcutasrt.h"
#include "rxclass.h"

class GcRxProperty;
class GcRxValue;
#ifdef NDEBUG
#define GCRXVALUE_ASSERT(x)
#else
#define GCRXVALUE_ASSERT(x) if (!(x)) gcutAssertMessage(GCRX_T(#x), GCRX_T(__FILE__), __LINE__, 0 ); else
#endif
class IGcRxNonBlittableType
{
public:
  virtual void construct(void* dest, const void* source) const = 0;
  virtual void assign(void* dest, const void* source) const = 0;
  virtual void destruct(const void* instance) const = 0;
};

class GcRxEnumTag;
class IGcRxEnumeration
{
public:
  virtual int count() const = 0;
  virtual const GcRxEnumTag& getAt(int index) const = 0;
};

class IGcRxReferenceType
{
public:
  enum OpenMode
  {
    kForRead = 0,
    kForWrite = 1,
    kForNotify = 2
  };
  virtual GcRxObject*       beginDereferencing(const GcRxValue& value, OpenMode mode) const = 0;
  virtual Gcad::ErrorStatus endDereferencing(GcRxObject* pO) const = 0;
};

class IGcRxObjectValue
{
public:
  virtual const GcRxObject* getRxObject(const GcRxValue& value) const = 0;
};
class GcRxValueType :public GcRxClass
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxValueType, GCBASE_PORT);

  GCBASE_PORT ~GcRxValueType();

  bool operator==(const GcRxValueType& rhs) const
  {
    return this == &rhs;
  }

  bool operator!=(const GcRxValueType& rhs) const
  {
    return this != &rhs;
  }

  GCBASE_PORT static __declspec(noreturn) void badCast();

  unsigned int size() const { return m_size; }

  bool isBlittable() const { return m_pNonBlittable == 0; }
  bool isEnum() const { return m_pEnum != 0; }
  bool isReference() const { return m_pRef != 0; }

  const IGcRxNonBlittableType* nonBlittable() const { return m_pNonBlittable; }
  const IGcRxEnumeration*      enumeration() const { return m_pEnum; }
  const IGcRxReferenceType*    reference() const { return m_pRef; }
  const IGcRxObjectValue*      rxObjectValue() const { return m_pRxObjValue; }
  enum StringFormat
  {
    kStringFormatGlobal = 0,
    kStringFormatCurrent = 1,
  };

  int toString(const void* instance, GCHAR* buffer, size_t sizeInGCHARs, StringFormat format) const
  {
    GCRXVALUE_ASSERT(instance != NULL);
    if (instance == NULL)
      return -1;
    GCRXVALUE_ASSERT((sizeInGCHARs == 0) == (buffer == NULL));
    if ((sizeInGCHARs == 0) != (buffer == NULL))
      return -1;
    return subToString(instance, buffer, sizeInGCHARs, format);
  }

  bool equalTo(const void* a, const void* b) const
  {
    GCRXVALUE_ASSERT(a != NULL);
    if (a == NULL)
      return false;
    GCRXVALUE_ASSERT(b != NULL);
    if (b == NULL)
      return false;
    return subEqualTo(a, b);
  }

  template<typename ValueType>
  struct Desc
  {
    static const GcRxValueType& value() throw();
    static void del();
  };

protected:
  GCBASE_PORT GcRxValueType(const GCHAR* name, const GCHAR* parent, const IGcRxNonBlittableType& nonBlittable, unsigned int size, GcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL);
  GCBASE_PORT GcRxValueType(const GCHAR* name, unsigned int size, GcRxMemberCollectionConstructorPtr memberConstruct, void *userData = NULL);
  GCBASE_PORT GcRxValueType(const GCHAR* name, const IGcRxNonBlittableType& pNonBlittable, unsigned int size, GcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL);
  GCBASE_PORT GcRxValueType(const GCHAR* name, const IGcRxEnumeration& pEnum, unsigned int size, GcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL);
  GCBASE_PORT GcRxValueType(const GCHAR* name, const IGcRxEnumeration& pEnum, const IGcRxNonBlittableType& pNonBlittable, unsigned int size, GcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL);
  GCBASE_PORT GcRxValueType(const GCHAR* name, const IGcRxEnumeration* pEnum, const IGcRxNonBlittableType* pNonBlittable, unsigned int size, GcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL);
  GCBASE_PORT GcRxValueType(const GCHAR* name, const IGcRxReferenceType& pRef, unsigned int size, GcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL);
  GCBASE_PORT GcRxValueType(const GCHAR* name, const IGcRxObjectValue& rxObjValue, const IGcRxNonBlittableType& pNonBlittable, unsigned int size, GcRxMemberCollectionConstructorPtr memberConstruct, void* userData = NULL);

private:
  virtual int  subToString(const void* instance, GCHAR* buffer, size_t sizeInGCHARs, StringFormat format) const = 0;
  virtual bool subEqualTo(const void* a, const void* b) const = 0;
  GcRxValueType(const GcRxValueType& rhs);
  GcRxValueType& operator=(const GcRxValueType& rhs);

  IGcRxNonBlittableType* m_pNonBlittable;
  IGcRxEnumeration*      m_pEnum;
  IGcRxReferenceType*    m_pRef;
  IGcRxObjectValue*      m_pRxObjValue;
  void*                  m_unused1;
  unsigned int           m_size;
};

template<> struct GcRxValueType::Desc<void>
{
  GCBASE_PORT static const GcRxValueType& value() throw();
  static void del();
};

class Storage;

#pragma push_macro("new")
#undef new
inline void* operator new(size_t size, Storage* loc) { GSOFT_UNREFED_PARAM(size); return loc; }
#pragma pop_macro("new")

#pragma push_macro("delete")
#undef delete
inline void operator delete(void* p, Storage* loc) { GSOFT_UNREFED_PARAM(p); (loc); }
#pragma pop_macro("delete")
