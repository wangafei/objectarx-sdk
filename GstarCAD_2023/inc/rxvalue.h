/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "gcdbport.h"
#include "dbintar.h"
#include "rxvaluetype.h"
#include "rxmember.h"

template<typename ValueType>
ValueType* rxvalue_cast(GcRxValue* value) throw();
template<typename ValueType>
ValueType * rxenum_cast(GcRxValue * value) throw();

class GcRxValue
{
public:
  GcRxValue() throw()
    :m_type(GcRxValueType::Desc<void>::value())
  {
    memset(&m_value, 0, sizeof(m_value));
  }

  GcRxValue(const GcRxValue& rhs) throw()
    :m_type(rhs.m_type)
  {
    init(rhs, false);
  }

  GcRxValue(const GcRxValueType& type, const GcRxValue& value) throw()
    :m_type(type)
  {
    init(value, false);
  }

  const GcRxValue& operator=(const GcRxValue& rhs) throw()
  {
    if (this == &rhs)
      return *this;
    if (type() != rhs.type())
    {
      if (!type().isBlittable())
        type().nonBlittable()->destruct(valuePtr());
      if (!isInlined() && rhs.isInlined())
        deallocate(m_value.m_ptr);
#pragma push_macro("new")
#undef new
      ::new ((Storage*)this) GcRxValue(rhs, !isInlined() && !rhs.isInlined());
#pragma pop_macro("new")
      return *this;
    }
    bool blittable = rhs.type().isBlittable();
    bool inlined = rhs.isInlined();
    if (blittable && inlined)
    {
      memcpy_s(this, sizeof(GcRxValue), &rhs, sizeof(GcRxValue));
      return *this;
    }
    if (inlined)
      type().nonBlittable()->assign(inlineValuePtr(), rhs.inlineValuePtr());
    else
      setNonInlineValue(rhs.nonInlineValuePtr(), blittable, true, true);
    return *this;
  }

  ~GcRxValue() throw()
  {
    if (!type().isBlittable())
      type().nonBlittable()->destruct(valuePtr());
    if (!isInlined())
      deallocate(m_value.m_ptr);
  }

  const GcRxValueType& type() const throw()
  {
    return m_type;
  }

  bool isEmpty() const throw() { return *this == empty(); }

  GCBASE_PORT static const GcRxValue& empty() throw();

  bool isVaries() const throw() { return *this == varies(); }

  GCBASE_PORT static const GcRxValue& varies() throw();

  GCBASE_PORT int toString(GCHAR* buffer, size_t sizeInGCHARs, GcRxValueType::StringFormat format = GcRxValueType::kStringFormatGlobal) const throw();

  GCBASE_PORT bool operator==(const GcRxValue& value) const throw()
  {
    if (type() != value.type())
      return false;
    return type().equalTo(valuePtr(), value.valuePtr());
  }

  template <typename ValueType>
  GcRxValue(const ValueType& value) throw()
    :m_type(GcRxValueType::Desc<ValueType>::value())
  {
    GCRXVALUE_ASSERT(m_type.isBlittable());
    initBlittable<sizeof(ValueType) <= 24>(&value, sizeof(ValueType));
  }

  template<typename ValueType>
  friend ValueType* rxvalue_cast(GcRxValue* value) throw()
  {
    return value && GcRxValueType::Desc<ValueType>::value() == value->type() ? (ValueType*)(value->valuePtr__<sizeof(ValueType) <= 24>()) : 0;
  }

  template<typename ValueType>
  friend ValueType * rxenum_cast(GcRxValue * value) throw()
  {
    GCRXVALUE_ASSERT(value == NULL || value->isVaries() || value->type().isEnum());
    return value &&
      value->type().isEnum() &&
      GcRxValueType::Desc<ValueType>::value() == value->type().enumeration()->getAt(0).type() ? (ValueType*)(value->valuePtr__<sizeof(ValueType) <= 24>()) : 0;
  }
  template<typename ValueType>
  GcRxValue& operator=(const ValueType & rhs) throw()
  {
    *this = GcRxValue(rhs);
    return *this;
  }

  template<typename ValueType>
  friend inline const ValueType * rxvalue_cast(const GcRxValue * value) throw()
  {
    return rxvalue_cast<ValueType>(const_cast<GcRxValue*>(value));
  }

  template<typename ValueType>
  friend inline const ValueType * rxenum_cast(const GcRxValue * value) throw()
  {
    return rxenum_cast<ValueType>(const_cast<GcRxValue*>(value));
  }

  GCBASE_PORT static const GcRxValue* unbox(const GcRxObject* pO) throw();
  GCBASE_PORT static GcRxValue*       unbox(GcRxObject* pO) throw();
  GCBASE_PORT const GcRxEnumTag*      getEnumTag() const throw();

  GCBASE_PORT size_t serializeOut(void* pBytes, size_t& maxBytesToWrite) const throw();
  GCBASE_PORT size_t serializeIn(const void* pBytes, size_t maxBytesToRead) throw();

private:
#pragma region Implementation
  bool isInlined() const
  {
    return type().size() <= sizeof(m_value);
  }
  const void* nonInlineValuePtr() const { return m_value.m_ptr; }
  void*       nonInlineValuePtr() { return m_value.m_ptr; }
  const void* inlineValuePtr() const { return &m_value; }
  void*       inlineValuePtr() { return &m_value; }
  const void* valuePtr() const
  {
    if (isInlined())
      return inlineValuePtr();
    else
      return nonInlineValuePtr();
  }
  template <bool Inlined>
  void* valuePtr__();
  template <bool Inlined>
  void initBlittable(const void* value, size_t size);

  template<typename T, bool inlined>
  class InitNonBlittable
  {
  public:
    static void init(GcRxValue& rxValue, const T& value);
  };
  template<typename T>
  class InitNonBlittable<T, true>
  {
  public:
    static void init(GcRxValue& rxValue, const T& value);
  };
  template<typename T>
  class InitNonBlittable<T, false>
  {
  public:
    static void init(GcRxValue& rxValue, const T& value);
  };

  template <typename T>
  void initNonBlittable(const T& value)
  {
    InitNonBlittable<T, sizeof(value) <= sizeof(m_value) >::init(*this, value);
  }

  void init(const GcRxValue& rhs, bool realloc)
  {
    bool blittable = type().isBlittable();
    bool inlined = isInlined();
    if (blittable && inlined)
    {
      memcpy_s(&m_value, sizeof(m_value), &rhs.m_value, sizeof(m_value));
      return;
    }
    if (inlined)
      type().nonBlittable()->construct(inlineValuePtr(), rhs.inlineValuePtr());
    else
      setNonInlineValue(rhs.nonInlineValuePtr(), blittable, false, realloc);
  }
  void setNonInlineValue(const void* value, bool blittable, bool assignment, bool realloc)
  {
    GCRXVALUE_ASSERT(blittable == type().isBlittable());
    GCRXVALUE_ASSERT(!isInlined());
    unsigned int newSize = type().size();
    realloc = realloc || assignment;
    if (realloc)
      m_value.m_ptr = reallocate(newSize, m_value.m_ptr);
    else
      m_value.m_ptr = allocate(newSize);

    if (blittable)
      memcpy_s(nonInlineValuePtr(), newSize, value, newSize);
    else if (assignment)
      type().nonBlittable()->assign(nonInlineValuePtr(), value);
    else
      type().nonBlittable()->construct(nonInlineValuePtr(), value);
  }
  GcRxValue(const GcRxValue& rhs, bool realloc)
    :m_type(rhs.m_type)
  {
    init(rhs, realloc);
  }
  const GcRxValueType& m_type;
#ifndef _GC64
  int padding;
#endif
  union InlineStorage
  {
    double  m_point[3];
    void*   m_ptr;
    char    m_int8;
    short   m_int16;
    int     m_int32;
    int64_t m_int64;
    float   m_real32;
    double  m_real64;
  } m_value;
  GCBASE_PORT void* allocate(size_t size) const;
  GCBASE_PORT void* reallocate(size_t size, void* p) const;
  GCBASE_PORT void  deallocate(void* p) const;

#pragma endregion
};

static_assert(sizeof(GcRxValue) == 32, "Size mismatch.");

template<>
struct GcRxValueType::Desc< const GCHAR* >
{
  GCBASE_PORT static const GcRxValueType& value() throw();
  GCBASE_PORT static void del();
};

template<>
struct GcRxValueType::Desc< const char* >
{
  GCBASE_PORT static const GcRxValueType& value() throw();
  GCBASE_PORT static void del();
};

template <>
inline GcRxValue::GcRxValue(const GCHAR* const & value) throw()
  :m_type(GcRxValueType::Desc<const GCHAR*>::value())
{
  memcpy_s(&m_value, sizeof(const GCHAR*), &value, sizeof(const GCHAR*));
}
template<>
inline GcRxValue& GcRxValue::operator=(const GCHAR* const & rhs) throw()
{
  *this = GcRxValue(rhs);
  return *this;
}
#if defined(__loongarch64) || defined(__sw_64__)//yhql-sp1 //龙芯loongarch64需要 //gcc8.3.0
template<const GCHAR*>
inline const GCHAR * const* rxvalue_cast(const GcRxValue* value) throw()
#else
template<>
inline const GCHAR * const* rxvalue_cast<const GCHAR*>(const GcRxValue * value) throw()
#endif
{
  return value && GcRxValueType::Desc<const GCHAR*>::value() == value->type() ? (const GCHAR* const*)&(value->m_value) : 0;
}
#if defined(__loongarch64) || defined(__sw_64__)//yhql-sp1 //龙芯loongarch64需要
template<void*>
inline const void* rxvalue_cast(const GcRxValue* value) throw()
#else
template<>
inline const void* rxvalue_cast<void>(const GcRxValue * value) throw()
#endif
{
  return value ? value->valuePtr() : 0;
}

template<>
inline void* GcRxValue::valuePtr__<true>()
{
  GCRXVALUE_ASSERT(isInlined());
  return inlineValuePtr();
}
template <>
inline void* GcRxValue::valuePtr__<false>()
{
  GCRXVALUE_ASSERT(!isInlined());
  return nonInlineValuePtr();
}

template <>
inline void GcRxValue::initBlittable<true>(const void* value, size_t size)
{
  GCRXVALUE_ASSERT(type().isBlittable());
  GCRXVALUE_ASSERT(isInlined());
  memcpy_s(inlineValuePtr(), size, value, size);
}
template <>
inline void GcRxValue::initBlittable<false>(const void* value, size_t size)
{
  GCRXVALUE_ASSERT(type().isBlittable());
  GCRXVALUE_ASSERT(!isInlined());
  m_value.m_ptr = allocate(size);
  memcpy_s(nonInlineValuePtr(), size, value, size);
}

template<typename T>
inline void GcRxValue::InitNonBlittable< T, true>::init(GcRxValue& rxValue, const T& value)
{
  ::new ((Storage*)(rxValue.inlineValuePtr())) T(value);
}

template<typename T>
inline void GcRxValue::InitNonBlittable< T, false>::init(GcRxValue& rxValue, const T& value)
{
  rxValue.setNonInlineValue(&value, false, false, false);
}

class GcRxBoxedValue : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxBoxedValue, GCBASE_PORT);

  GCBASE_PORT virtual const GcRxValue* value() const = 0;
  GCBASE_PORT virtual GcRxValue*       value() = 0;

  GCBASE_PORT static GcRxBoxedValue* newBoxedValueOnHeap(const GcRxValue& value);

  GCBASE_PORT GcRxObject*       clone() const override;
  GCBASE_PORT Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;
  GCBASE_PORT Gsoft::Boolean    isEqualTo(const GcRxObject * other) const override;
  GCBASE_PORT GcRx::Ordering    comparedTo(const GcRxObject * other) const override;

  GCBASE_PORT const GcRxObject* rxObject() const;
  GCBASE_PORT GcRxObject*       rxObject();
};


class GcRxBoxedValueOnStack : public GcRxBoxedValue
{
  GcRxValue& m_value;
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxBoxedValueOnStack, GCBASE_PORT);

  GCBASE_PORT GcRxBoxedValueOnStack(const GcRxValue& value);

  GCBASE_PORT const GcRxValue* value() const override;
  GCBASE_PORT GcRxValue*       value() override;
};

#pragma region GcString
class GcString;
template<>
GCBASE_PORT GcRxValue::GcRxValue(const GcString& str) throw();
#pragma endregion


#pragma region GcGeMatrix3d
class GcGeMatrix3d;
template<>
struct GcRxValueType::Desc<GcGeMatrix3d>
{
  GCBASE_PORT static const GcRxValueType& value() throw();
  GCBASE_PORT static void del();
};

template<>
GCBASE_PORT GcRxValue::GcRxValue(const GcGeMatrix3d& m) throw();

template<>
GCBASE_PORT GcGeMatrix3d* rxvalue_cast<GcGeMatrix3d>(GcRxValue* value) throw();
#pragma endregion

#pragma region GcCmColor
class GcCmColor;

template<>
struct GcRxValueType::Desc<GcCmColor>
{
  GCDB_PORT static const GcRxValueType& value() throw();
  GCDB_PORT static void del();
};

template<>
GCDB_PORT GcRxValue::GcRxValue(const GcCmColor& clr) throw();
#pragma endregion

#pragma region GcDbDate
class GcDbDate;
template<>
struct GcRxValueType::Desc<GcDbDate>
{
  GCDB_PORT static const GcRxValueType& value() throw();
  GCDB_PORT static void del();
};

template<>
GCDB_PORT GcRxValue::GcRxValue(const GcDbDate& str) throw();
#pragma endregion

#pragma region GcUnderlayLayer
class GcUnderlayLayer;
template<>
struct GcRxValueType::Desc<GcUnderlayLayer>
{
  GCDB_PORT static const GcRxValueType& value() throw();
  static void del();
};

template<>
GCDB_PORT GcRxValue::GcRxValue(const GcUnderlayLayer& str) throw();
#pragma endregion

#pragma region GcGiMaterialColor
class GcGiMaterialColor;
template<>
struct GcRxValueType::Desc<GcGiMaterialColor>
{
  GCBASE_PORT static const GcRxValueType& value() throw();
  GCBASE_PORT static void del();
};

template<>
GCBASE_PORT GcRxValue::GcRxValue(const GcGiMaterialColor& clr) throw();
#pragma endregion

#pragma region GcGiMaterialMap
class GcGiMaterialMap;
template<>
struct GcRxValueType::Desc<GcGiMaterialMap>
{
  GCDB_PORT static const GcRxValueType& value() throw();
  static void del();
};

template<>
GCDB_PORT GcRxValue::GcRxValue(const GcGiMaterialMap& clr) throw();
#pragma endregion

#pragma region GcDbSweepOptions
class GcDbSweepOptions;
template<>
struct GcRxValueType::Desc<GcDbSweepOptions>
{
  GCDB_PORT static const GcRxValueType& value() throw();
  GCDB_PORT static void del();
};

template<>
GCDB_PORT GcRxValue::GcRxValue(const GcDbSweepOptions& sweepOptions) throw();
#pragma endregion


#pragma region GcDbLoftOptions
class GcDbLoftOptions;
template<>
struct GcRxValueType::Desc<GcDbLoftOptions>
{
  GCDB_PORT static const GcRxValueType& value() throw();
  GCDB_PORT static void del();
};

template<>
GCDB_PORT GcRxValue::GcRxValue(const GcDbLoftOptions& loftOptions) throw();
#pragma endregion

#pragma region GcGiShadowParameters
class GcGiShadowParameters;
template<>
struct GcRxValueType::Desc<GcGiShadowParameters>
{
  GCBASE_PORT static const GcRxValueType& value() throw();
  GCBASE_PORT static void del();
};

template<>
GCBASE_PORT GcRxValue::GcRxValue(const GcGiShadowParameters& v) throw();
#pragma endregion

#pragma region GcGiSkyParameters
class GcGiSkyParameters;
template<>
struct GcRxValueType::Desc<GcGiSkyParameters>
{
  GCBASE_PORT static const GcRxValueType& value() throw();
  GCBASE_PORT static void del();
};

template<>
GCBASE_PORT GcRxValue::GcRxValue(const GcGiSkyParameters& v) throw();
#pragma endregion

#pragma region GcGiToneOperatorParameters
class GcGiToneOperatorParameters;
template<>
struct GcRxValueType::Desc<GcGiToneOperatorParameters>
{
  GCDB_PORT static const GcRxValueType& value() throw();
  static void del();
};

template<>
GCDB_PORT GcRxValue::GcRxValue(const GcGiToneOperatorParameters& v) throw();
#pragma endregion

#pragma region GcGiPhotographicExposureParameters
class GcGiPhotographicExposureParameters;
template<>
struct GcRxValueType::Desc<GcGiPhotographicExposureParameters>
{
  GCDB_PORT static const GcRxValueType& value() throw();
  static void del();
};

template<>
GCDB_PORT GcRxValue::GcRxValue(const GcGiPhotographicExposureParameters& v) throw();
#pragma endregion

#pragma region GcGiLightAttenuation
class GcGiLightAttenuation;
template<>
struct GcRxValueType::Desc<GcGiLightAttenuation>
{
  GCBASE_PORT static const GcRxValueType& value() throw();
  GCBASE_PORT static void del();
};

template<>
GCBASE_PORT GcRxValue::GcRxValue(const GcGiLightAttenuation& v) throw();
#pragma endregion

#pragma region GcDbMText*
class GcDbMText;
template<>
struct GcRxValueType::Desc<GcDbMText*>
{
  GCDB_PORT static const GcRxValueType& value() throw();
  static void del();
};

template<>
GCDB_PORT GcRxValue::GcRxValue(GcDbMText* const& pMText) throw();

#if defined(__loongarch64) || defined(__sw_64__) //yhql-sp1 //龙芯loongarch64需要
template<GcDbMText*>
GCDB_PORT GcDbMText* const* rxvalue_cast(const GcRxValue * value) throw();
#else
template<>
GCDB_PORT GcDbMText* const* rxvalue_cast<GcDbMText*>(const GcRxValue * value) throw();
#endif
#pragma endregion

#pragma region GcDbTableCellBlockReference
class GcDbTableCellBlockReference;
template<>
struct GcRxValueType::Desc<GcDbTableCellBlockReference>
{
  GCDB_PORT static const GcRxValueType& value() throw();
  static void del();
};

template<>
GCDB_PORT GcRxValue::GcRxValue(const GcDbTableCellBlockReference& tableCellBlkRef) throw();
#pragma endregion

#pragma region GcDbBlockParamValueSet
class GcDbBlockParamValueSet;
template<>
struct GcRxValueType::Desc<GcDbBlockParamValueSet>
{
  GCDB_PORT static const GcRxValueType& value() throw();
  static void del();
};

template<>
GCDB_PORT GcRxValue::GcRxValue(const GcDbBlockParamValueSet& blcParamValueSet) throw();
#pragma endregion

#pragma region GcDbBlkParamValueSetValuesArray
typedef GcArray<double> GcDbBlkParamValueSetValuesArray;
template<>
struct GcRxValueType::Desc<GcDbBlkParamValueSetValuesArray>
{
  GCBASE_PORT static const GcRxValueType& value() throw();
  GCBASE_PORT static void del();
};

template<>
GCBASE_PORT GcRxValue::GcRxValue(const GcDbBlkParamValueSetValuesArray& blockParamValueSetArr) throw();
#pragma endregion

#pragma region GcDbIntArray
template<>
struct GcRxValueType::Desc<GcDbIntArray>
{
  GCBASE_PORT static const GcRxValueType& value() throw();
  GCBASE_PORT static void del();
};

template<>
GCBASE_PORT GcRxValue::GcRxValue(const GcDbIntArray& intArr) throw();
#pragma endregion

#pragma region DimFillColor
struct DimFillColor;
template<>
struct GcRxValueType::Desc<DimFillColor>
{
  GCDB_PORT static const GcRxValueType& value() throw();
  static void del();
};

template<>
GCDB_PORT GcRxValue::GcRxValue(const DimFillColor& dimFillColor) throw();
#pragma endregion

#pragma region GcStringArray
typedef GcArray<GcString, GcArrayObjectCopyReallocator<GcString>> GcStringArray;
template<>
struct GcRxValueType::Desc<GcStringArray>
{
  GCBASE_PORT static const GcRxValueType& value() throw();
  GCBASE_PORT static void del();
};

template<>
GCBASE_PORT GcRxValue::GcRxValue(const GcStringArray& stringArray) throw();
#pragma endregion
