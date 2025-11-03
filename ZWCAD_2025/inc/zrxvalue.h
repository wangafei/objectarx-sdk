
#pragma once
#include "zacdbport.h"
#include "zdbintar.h"
#include "zrxvaluetype.h"
#include "zrxmember.h"

template<typename ValueType>
ValueType* rxvalue_cast(ZcRxValue* value) throw();
template<typename ValueType>
ValueType * rxenum_cast(ZcRxValue * value) throw();

class ZCBASE_PORT ZcRxValue
{
public:

    ZcRxValue() throw()
        :m_type(ZcRxValueType::Desc<void>::value())
    {
        memset(&m_value,0,sizeof(m_value));
    }

    ZcRxValue(const ZcRxValue& rhs) throw()
        :m_type(rhs.m_type)
    {
        init(rhs, false);
    }

    ZcRxValue(const ZcRxValueType& type, const ZcRxValue& value) throw()
        :m_type(type)
    {
        init(value, false);
    }

    const ZcRxValue& operator=(const ZcRxValue& rhs) throw()
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
			::new ((ZwRx::Storage*)this) ZcRxValue(rhs, !isInlined() && !rhs.isInlined());
#pragma pop_macro("new")
            return *this;
        }
        bool blittable = rhs.type().isBlittable();
        bool inlined = rhs.isInlined();
        if (blittable && inlined)
        {
            memcpy_s(this,sizeof(ZcRxValue),&rhs,sizeof(ZcRxValue));
            return *this;
        }

        if (inlined)
            type().nonBlittable()->assign(inlineValuePtr(),rhs.inlineValuePtr());
        else
            setNonInlineValue(rhs.nonInlineValuePtr(), blittable, true, true);
        return *this;
    }

    ~ZcRxValue() throw()
    {

        if (!type().isBlittable())
            type().nonBlittable()->destruct(valuePtr());

        if (!isInlined())
            deallocate(m_value.m_ptr);
    }

    const ZcRxValueType& type() const throw()
    {
        return m_type;
    }

    bool isEmpty() const throw() {return *this == empty();}

    static const ZcRxValue& empty() throw();

    bool isVaries() const throw() { return *this == varies();}

    static const ZcRxValue& varies() throw();

    int toString(ZTCHAR* buffer, size_t sizeInZTCHARs, ZcRxValueType::StringFormat format=ZcRxValueType::kStringFormatGlobal) const throw();

    bool operator==(const ZcRxValue& value) const throw()
    {
        if (type()!=value.type())
            return false;
        return type().equalTo(valuePtr(), value.valuePtr());
    }

    template <typename ValueType>
    ZcRxValue(const ValueType& value) throw()
        :m_type(ZcRxValueType::Desc<ValueType>::value())
    {

        ZCRXVALUE_ASSERT(m_type.isBlittable());
        initBlittable<sizeof(ValueType)<=24>(&value,sizeof(ValueType));
    }

    template<typename ValueType>
    friend ValueType* rxvalue_cast(ZcRxValue* value) throw()
    {
        return value && ZcRxValueType::Desc<ValueType>::value() == value->type()? (ValueType*)(value->valuePtr__<sizeof(ValueType)<=24>()) : 0;
    }

    template<typename ValueType>
    friend ValueType * rxenum_cast(ZcRxValue * value) throw()
    {
        ZCRXVALUE_ASSERT(value == NULL || value->isVaries() || value->type().isEnum());
        return value &&
               value->type().isEnum() &&
               ZcRxValueType::Desc<ValueType>::value() == value->type().enumeration()->getAt(0).type() ? (ValueType*)(value->valuePtr__<sizeof(ValueType)<=24>()) : 0;
    }

     template<typename ValueType>
    ZcRxValue& operator=(const ValueType & rhs) throw()
    {
        *this = ZcRxValue(rhs);
        return *this;
    }

    template<typename ValueType>
    friend inline const ValueType * rxvalue_cast(const ZcRxValue * value) throw()
    {
        return rxvalue_cast<ValueType>(const_cast<ZcRxValue*>(value));
    }

    template<typename ValueType>
    friend inline const ValueType * rxenum_cast(const ZcRxValue * value) throw()
    {
        return rxenum_cast<ValueType>(const_cast<ZcRxValue*>(value));
    }

    static const ZcRxValue* unbox(const ZcRxObject* pO) throw();

    static ZcRxValue* unbox(ZcRxObject* pO) throw();

    const ZcRxEnumTag* getEnumTag() const throw();

    size_t serializeOut(void* pBytes, size_t& maxBytesToWrite) const throw();

    size_t serializeIn(const void* pBytes, size_t maxBytesToRead) throw();

private:
#pragma region Implementation
    bool isInlined() const
    {
        return type().size() <= sizeof(m_value);
    }
    const void* nonInlineValuePtr() const { return m_value.m_ptr;}
    void* nonInlineValuePtr() { return m_value.m_ptr;}
    const void* inlineValuePtr() const {return &m_value;}
    void* inlineValuePtr() {return &m_value;}
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
        static void init(ZcRxValue& rxValue, const T& value);
    };
    template<typename T>
    class InitNonBlittable<T, true>
    {
    public:
        static void init(ZcRxValue& rxValue,const T& value);
    };
    template<typename T>
    class InitNonBlittable<T, false>
    {
    public:
        static void init(ZcRxValue& rxValue,const T& value);
    };

    template <typename T>
    void initNonBlittable(const T& value)
    {
        InitNonBlittable<T, sizeof(value)<=sizeof(m_value) >::init(*this,value);
    }

    void init(const ZcRxValue& rhs, bool realloc)
    {
        bool blittable = type().isBlittable();
        bool inlined = isInlined();
        if (blittable && inlined)
        {
            memcpy_s(&m_value,sizeof(m_value), &rhs.m_value,sizeof(m_value));
            return;
        }

        if (inlined)
            type().nonBlittable()->construct(inlineValuePtr(),rhs.inlineValuePtr());
        else
            setNonInlineValue(rhs.nonInlineValuePtr(), blittable, false, realloc);
    }
    void setNonInlineValue(const void* value, bool blittable, bool assignment, bool realloc)
    {
        ZCRXVALUE_ASSERT(blittable == type().isBlittable());
        ZCRXVALUE_ASSERT(!isInlined());
        unsigned int newSize = type().size();
        realloc = realloc || assignment;
        if (realloc)
            m_value.m_ptr = reallocate(newSize, m_value.m_ptr);
        else
            m_value.m_ptr = allocate(newSize);

        if (blittable)
            memcpy_s(nonInlineValuePtr(),newSize,value,newSize);
        else if (assignment)
            type().nonBlittable()->assign(nonInlineValuePtr(), value);
        else
            type().nonBlittable()->construct(nonInlineValuePtr(),value);
    }
    ZcRxValue(const ZcRxValue& rhs, bool realloc)
        :m_type(rhs.m_type)
    {
        init(rhs, realloc);
    }
    const ZcRxValueType& m_type;
#ifndef _ZC64
    int padding;
#endif
    union InlineStorage
    {
        double m_point[3];
        void* m_ptr;
        char  m_int8;
        short m_int16;
        int   m_int32;
        int64_t m_int64;
        float m_real32;
        double m_real64;
    } m_value;
    void* allocate(size_t size) const;
    void* reallocate(size_t size, void* p) const;
    void  deallocate(void* p) const;

#pragma endregion
};

static_assert(sizeof(ZcRxValue)==32, "Size mismatch.");

template<>
struct ZcRxValueType::Desc< const ZTCHAR* >
{
    ZCBASE_PORT static const ZcRxValueType& value() throw();
    static void del();
};

template<>
struct ZcRxValueType::Desc< const char* >
{
    ZCBASE_PORT static const ZcRxValueType& value() throw();
    static void del();
};

template <>
inline ZcRxValue::ZcRxValue(const ZTCHAR* const & value) throw()
    :m_type(ZcRxValueType::Desc<const ZTCHAR*>::value())
{
    memcpy_s(&m_value,sizeof(const ZTCHAR*), &value,sizeof(const ZTCHAR*));
}
template<>
inline ZcRxValue& ZcRxValue::operator=(const ZTCHAR* const & rhs) throw()
{
    *this = ZcRxValue(rhs);
    return *this;
}
template<>
inline const ZTCHAR * const* rxvalue_cast<const ZTCHAR*>(const ZcRxValue * value) throw()
{
    return value && ZcRxValueType::Desc<const ZTCHAR*>::value() == value->type()? (const ZTCHAR* const*)&(value->m_value) : 0;
}

template<>
inline const void* rxvalue_cast<void>(const ZcRxValue * value) throw()
{
    return value ? value->valuePtr() : 0;
}

template<>
inline void* ZcRxValue::valuePtr__<true>()
{
    ZCRXVALUE_ASSERT(isInlined());
    return inlineValuePtr();
}
template <>
inline void* ZcRxValue::valuePtr__<false>()
{
    ZCRXVALUE_ASSERT(!isInlined());
    return nonInlineValuePtr();
}

template <>
inline void ZcRxValue::initBlittable<true>(const void* value, size_t size)
{
    ZCRXVALUE_ASSERT(type().isBlittable());
    ZCRXVALUE_ASSERT(isInlined());
    memcpy_s(inlineValuePtr(), size, value, size);
}
template <>
inline void ZcRxValue::initBlittable<false>(const void* value, size_t size)
{
    ZCRXVALUE_ASSERT(type().isBlittable());
    ZCRXVALUE_ASSERT(!isInlined());
    m_value.m_ptr = allocate(size);
    memcpy_s(nonInlineValuePtr(),size,value,size);
}

template<typename T>
inline void ZcRxValue::InitNonBlittable< T, true>::init(ZcRxValue& rxValue, const T& value)
{

    ::new ((ZwRx::Storage*)(rxValue.inlineValuePtr())) T(value);
}

template<typename T>
inline void ZcRxValue::InitNonBlittable< T, false>::init(ZcRxValue& rxValue, const T& value)
{
    rxValue.setNonInlineValue(&value,false,false, false);
}

class ZcRxBoxedValue : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxBoxedValue, ZCBASE_PORT);

    virtual const ZcRxValue* value() const = 0;

    virtual ZcRxValue* value() = 0;

    ZCBASE_PORT static ZcRxBoxedValue* newBoxedValueOnHeap(const ZcRxValue& value);

    ZCBASE_PORT virtual ZcRxObject*       clone() const override;

    ZCBASE_PORT virtual Zcad::ErrorStatus copyFrom(const ZcRxObject* other) override;

    ZCBASE_PORT virtual ZSoft::Boolean    isEqualTo(const ZcRxObject * other) const override;

    ZCBASE_PORT virtual ZcRx::Ordering    comparedTo(const ZcRxObject * other) const override;

    ZCBASE_PORT const ZcRxObject* rxObject() const;
    ZCBASE_PORT ZcRxObject* rxObject();
};

class ZcRxBoxedValueOnStack : public ZcRxBoxedValue
{
    ZcRxValue& m_value;
public:
    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcRxBoxedValueOnStack, ZCBASE_PORT);

    ZCBASE_PORT ZcRxBoxedValueOnStack(const ZcRxValue& value);

    ZCBASE_PORT virtual const ZcRxValue* value() const override;

    ZCBASE_PORT virtual ZcRxValue* value() override;
};

#pragma region ZcString
class ZcString;

template<>
ZCBASE_PORT ZcRxValue::ZcRxValue(const ZcString& str) throw();
#pragma endregion

#pragma region ZcGeMatrix3d
class ZcGeMatrix3d;
template<>
struct ZcRxValueType::Desc<ZcGeMatrix3d>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
    static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcGeMatrix3d& m) throw();

template<>
ZCDBCORE2D_PORT ZcGeMatrix3d* rxvalue_cast<ZcGeMatrix3d>(ZcRxValue* value) throw();
#pragma endregion

#pragma region ZcCmColor
class ZcCmColor;

template<>
struct ZcRxValueType::Desc<ZcCmColor>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
    static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcCmColor& clr) throw();
#pragma endregion

#pragma region ZcDbDate
class ZcDbDate;
template<>
struct ZcRxValueType::Desc<ZcDbDate>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
    static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcDbDate& str) throw();
#pragma endregion

#pragma region ZcUnderlayLayer
class ZcUnderlayLayer;
template<>
struct ZcRxValueType::Desc<ZcUnderlayLayer>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
    static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcUnderlayLayer& str) throw();
#pragma endregion

#pragma region ZcGiMaterialColor
class ZcGiMaterialColor;
template<>
struct ZcRxValueType::Desc<ZcGiMaterialColor>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
    static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcGiMaterialColor& clr) throw();
#pragma endregion

#pragma region ZcGiMaterialMap
class ZcGiMaterialMap;
template<>
struct ZcRxValueType::Desc<ZcGiMaterialMap>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
    static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcGiMaterialMap& clr) throw();
#pragma endregion

#pragma region ZcDbSweepOptions
class ZcDbSweepOptions;
template<>
struct ZcRxValueType::Desc<ZcDbSweepOptions>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
    static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcDbSweepOptions& sweepOptions) throw();
#pragma endregion

#pragma region ZcDbLoftOptions
class ZcDbLoftOptions;
template<>
struct ZcRxValueType::Desc<ZcDbLoftOptions>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
    static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcDbLoftOptions& loftOptions) throw();
#pragma endregion

#pragma region ZcGiShadowParameters
class ZcGiShadowParameters;
template<>
struct ZcRxValueType::Desc<ZcGiShadowParameters>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
    static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcGiShadowParameters& v) throw();
#pragma endregion

#pragma region ZcGiSkyParameters
class ZcGiSkyParameters;
template<>
struct ZcRxValueType::Desc<ZcGiSkyParameters>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
    static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcGiSkyParameters& v) throw();
#pragma endregion

#pragma region ZcGiToneOperatorParameters
class ZcGiToneOperatorParameters;
template<>
struct ZcRxValueType::Desc<ZcGiToneOperatorParameters>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
    static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcGiToneOperatorParameters& v) throw();
#pragma endregion

#pragma region ZcGiPhotographicExposureParameters
class ZcGiPhotographicExposureParameters;
template<>
struct ZcRxValueType::Desc<ZcGiPhotographicExposureParameters>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
    static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcGiPhotographicExposureParameters& v) throw();
#pragma endregion

#pragma region ZcGiLightAttenuation
class ZcGiLightAttenuation;
template<>
struct ZcRxValueType::Desc<ZcGiLightAttenuation>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
    static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcGiLightAttenuation& v) throw();
#pragma endregion

#pragma region ZcDbMText*
class ZcDbMText;
template<>
struct ZcRxValueType::Desc<ZcDbMText*>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
    static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(ZcDbMText* const& pMText) throw();

template<>
ZCDBCORE2D_PORT ZcDbMText* const* rxvalue_cast<ZcDbMText*>(const ZcRxValue * value) throw();
#pragma endregion

#pragma region ZcDbTableCellBlockReference
class ZcDbTableCellBlockReference;
template<>
struct ZcRxValueType::Desc<ZcDbTableCellBlockReference>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
	static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcDbTableCellBlockReference& tableCellBlkRef) throw();
#pragma endregion

#pragma region ZcDbBlockParamValueSet
class ZcDbBlockParamValueSet;
template<>
struct ZcRxValueType::Desc<ZcDbBlockParamValueSet>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
	static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcDbBlockParamValueSet& blcParamValueSet) throw();
#pragma endregion

#pragma region ZcDbBlkParamValueSetValuesArray
typedef ZcArray<double> ZcDbBlkParamValueSetValuesArray;
template<>
struct ZcRxValueType::Desc<ZcDbBlkParamValueSetValuesArray>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
	static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcDbBlkParamValueSetValuesArray& blockParamValueSetArr) throw();
#pragma endregion

#pragma region ZcDbIntArray
template<>
struct ZcRxValueType::Desc<ZcDbIntArray>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
    static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcDbIntArray& intArr) throw();
#pragma endregion

#pragma region DimFillColor
struct DimFillColor;
template<>
struct ZcRxValueType::Desc<DimFillColor>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
	static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const DimFillColor& dimFillColor) throw();
#pragma endregion

#pragma region ZcStringArray
typedef ZcArray<ZcString, ZcArrayObjectCopyReallocator<ZcString>> ZcStringArray;
template<>
struct ZcRxValueType::Desc<ZcStringArray>
{
    ZCDBCORE2D_PORT static const ZcRxValueType& value() throw();
	static void del();
};

template<>
ZCDBCORE2D_PORT ZcRxValue::ZcRxValue(const ZcStringArray& stringArray) throw();
#pragma endregion