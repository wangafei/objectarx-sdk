///////////////////////////////////////////////////////////////////////////

// Primary authors:
//     Florian Kainz <kainz@ilm.com>
//     Rod Bogart <rgb@ilm.com>

//---------------------------------------------------------------------------
//
//	half -- a 16-bit floating point number class:
//
//	Type half can represent positive and negative numbers whose
//	magnitude is between roughly 6.1e-5 and 6.5e+4 with a relative
//	error of 9.8e-4; numbers smaller than 6.1e-5 can be represented
//	with an absolute error of 6.0e-8.  All integers from -2048 to
//	+2048 can be represented exactly.
//
//	Type half behaves (almost) like the built-in C++ floating point
//	types.  In arithmetic expressions, half, float and double can be
//	mixed freely.  Here are a few examples:
//
//	    half a (3.5);
//	    float b (a + sqrt (a));
//	    a += b;
//	    b += a;
//	    b = a + 7;
//
//	Conversions from half to float are lossless; all half numbers
//	are exactly representable as floats.
//
//	Conversions from float to half may not preserve the float's
//	value exactly.  If a float is not representable as a half, the
//	float value is rounded to the nearest representable half.  If
//	a float value is exactly in the middle between the two closest
//	representable half values, then the float value is rounded to
//	the half with the greater magnitude.
//
//	Overflows during float-to-half conversions cause arithmetic
//	exceptions.  An overflow occurs when the float value to be
//	converted is too large to be represented as a half, or if the
//	float value is an infinity or a NAN.
//
//	The implementation of type half makes the following assumptions
//	about the implementation of the built-in C++ types:
//
//	    float is an IEEE 754 single-precision number
//	    sizeof (float) == 4
//	    sizeof (unsigned int) == sizeof (float)
//	    alignof (unsigned int) == alignof (float)
//	    sizeof (unsigned short) == 2
//
//---------------------------------------------------------------------------
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif

#ifndef Z_HALF_H_
#define Z_HALF_H_

#include "zImathExport.h"
#include "zImathNamespace.h"
#include "zImathPlatform.h"

#ifdef _WIN32
#        include <intrin.h>
#elif defined(__x86_64__)
#        include <x86intrin.h>
#endif

#include <stdint.h>
#include <stdio.h>

#ifdef IMATH_HALF_ENABLE_FP_EXCEPTIONS
#    include <fenv.h>
#endif

//-------------------------------------------------------------------------
// Limits
//
// Visual C++ will complain if HALF_MIN, HALF_NRM_MIN etc. are not float
// constants, but at least one other compiler (gcc 2.96) produces incorrect
// results if they are.
//-------------------------------------------------------------------------

#if (defined _WIN32 || defined _WIN64) && defined _MSC_VER

#define HALF_DENORM_MIN 5.96046448e-08f // Smallest positive denormalized half

#define HALF_NRM_MIN	6.10351562e-05f	// Smallest positive normalized half

#define HALF_MIN	6.10351562e-05f// Smallest positive half

#define HALF_MAX	65504.0f	// Largest positive half

#define HALF_EPSILON	0.00097656f	// Smallest positive e for which
                  // half (1.0 + e) != half (1.0)
#else

#define HALF_DENORM_MIN	5.96046448e-08	// Smallest positive half

#define HALF_NRM_MIN	6.10351562e-05	// Smallest positive normalized half

#define HALF_MIN 6.10351562e-05f // Smallest positive normalized half

#define HALF_MAX	65504.0		// Largest positive half

#define HALF_EPSILON	0.00097656	// Smallest positive e for which
                  // half (1.0 + e) != half (1.0)
#endif


#define HALF_MANT_DIG	11		// Number of digits in mantissa
                    // (significand + hidden leading 1)

#define HALF_DIG	2		// Number of base 10 digits that
                    // can be represented without change

/// Number of base-10 digits that are necessary to uniquely represent
/// all distinct values:
/// 
/// ``ceil(HALF_MANT_DIG * log10(2) + 1) => 4.31... -> 5``
#define HALF_DECIMAL_DIG 5

#define HALF_RADIX	2		// Base of the exponent

#define HALF_DENORM_MIN_EXP	-13		// Minimum negative integer such that
                    // HALF_RADIX raised to the power of
                    // one less than that integer is a
                    // normalized half

#define HALF_MAX_EXP	16		// Maximum positive integer such that
                    // HALF_RADIX raised to the power of
                    // one less than that integer is a
                    // normalized half

#define HALF_DENORM_MIN_10_EXP	-4		// Minimum positive integer such
                    // that 10 raised to that power is
                    // a normalized half

#define HALF_MAX_10_EXP	4		// Maximum positive integer such
                    // that 10 raised to that power is
                    // a normalized half

/// a type for both C-only programs and C++ to use the same utilities
typedef union imath_half_uif
{
    uint32_t i;
    float f;
} imath_half_uif_t;

/// a type for both C-only programs and C++ to use the same utilities
typedef uint16_t imath_half_bits_t;

#if !defined(__cplusplus) && !defined(__CUDACC__)
/// if we're in a C-only context, alias the half bits type to half
typedef imath_half_bits_t half;
#endif

#if !defined(IMATH_HALF_NO_LOOKUP_TABLE)
#    if defined(__cplusplus)
extern "C"
#    else
extern
#    endif
IMATH_EXPORT const imath_half_uif_t* imath_half_to_float_table;
#endif

///
/// Convert half to float
///

static inline float
imath_half_to_float(imath_half_bits_t h)
{
#if defined(__F16C__)
    // NB: The intel implementation does seem to treat NaN slightly
    // different than the original toFloat table does (i.e. where the
    // 1 bits are, meaning the signalling or not bits). This seems
    // benign, given that the original library didn't really deal with
    // signalling vs non-signalling NaNs
#    ifdef _MSC_VER
    /* msvc does not seem to have cvtsh_ss :( */
    return _mm_cvtss_f32(_mm_cvtph_ps(_mm_set1_epi16(h)));
#    else
    return _cvtsh_ss(h);
#    endif
#elif defined(IMATH_HALF_USE_LOOKUP_TABLE) && !defined(IMATH_HALF_NO_LOOKUP_TABLE)
    return imath_half_to_float_table[h].f;
#else
    imath_half_uif_t v;
    // this code would be clearer, although it does appear to be faster
    // (1.06 vs 1.08 ns/call) to avoid the constants and just do 4
    // shifts.
    //
    uint32_t hexpmant = ((uint32_t)(h) << 17) >> 4;
    v.i = ((uint32_t)(h >> 15)) << 31;

    // the likely really does help if most of your numbers are "normal" half numbers
    if (IMATH_LIKELY((hexpmant >= 0x00800000)))
    {
        v.i |= hexpmant;
        // either we are a normal number, in which case add in the bias difference
        // otherwise make sure all exponent bits are set
        if (IMATH_LIKELY((hexpmant < 0x0f800000)))
            v.i += 0x38000000;
        else
            v.i |= 0x7f800000;
    }
    else if (hexpmant != 0)
    {
        // exponent is 0 because we're denormal, don't have to extract
        // the mantissa, can just use as is
        //
        //
        // other compilers may provide count-leading-zeros primitives,
        // but we need the community to inform us of the variants
        uint32_t lc;
#    if defined(_MSC_VER) && (_M_IX86 || _M_X64)
        lc = __lzcnt(hexpmant);
#    elif defined(__GNUC__) || defined(__clang__)
        lc = (uint32_t)__builtin_clz(hexpmant);
#    else
        lc = 0;
        while (0 == ((hexpmant << lc) & 0x80000000))
            ++lc;
#    endif
        lc -= 8;
        // so nominally we want to remove that extra bit we shifted
        // up, but we are going to add that bit back in, then subtract
        // from it with the 0x38800000 - (lc << 23)....
        //
        // by combining, this allows us to skip the & operation (and
        // remove a constant)
        //
        // hexpmant &= ~0x00800000;
        v.i |= 0x38800000;
        // lc is now x, where the desired exponent is then
        // -14 - lc
        // + 127 -> new exponent
        v.i |= (hexpmant << lc);
        v.i -= (lc << 23);
    }
    return v.f;
#endif
}

///
/// Convert half to float
///
/// Note: This only supports the "round to even" rounding mode, which
/// was the only mode supported by the original OpenEXR library
///

static inline imath_half_bits_t
imath_float_to_half(float f)
{
#if defined(__F16C__)
#    ifdef _MSC_VER
    // msvc does not seem to have cvtsh_ss :(
    return _mm_extract_epi16(
        _mm_cvtps_ph(_mm_set_ss(f), (_MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)),
        0);
#    else
    // preserve the fixed rounding mode to nearest
    return _cvtss_sh(f, (_MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC));
#    endif
#else
    imath_half_uif_t v;
    imath_half_bits_t ret;
    uint32_t e, m, ui, r, shift;

    v.f = f;

    ui = (v.i & ~0x80000000);
    ret = ((v.i >> 16) & 0x8000);

    // exponent large enough to result in a normal number, round and return
    if (ui >= 0x38800000)
    {
        // inf or nan
        if (IMATH_UNLIKELY(ui >= 0x7f800000))
        {
            ret |= 0x7c00;
            if (ui == 0x7f800000)
                return ret;
            m = (ui & 0x7fffff) >> 13;
            // make sure we have at least one bit after shift to preserve nan-ness
            return ret | (uint16_t)m | (uint16_t)(m == 0);
        }

        // too large, round to infinity
        if (IMATH_UNLIKELY(ui > 0x477fefff))
        {
#    ifdef IMATH_HALF_ENABLE_FP_EXCEPTIONS
            feraiseexcept(FE_OVERFLOW);
#    endif
            return ret | 0x7c00;
        }

        ui -= 0x38000000;
        ui = ((ui + 0x00000fff + ((ui >> 13) & 1)) >> 13);
        return ret | (uint16_t)ui;
    }

    // zero or flush to 0
    if (ui < 0x33000001)
    {
#    ifdef IMATH_HALF_ENABLE_FP_EXCEPTIONS
        if (ui == 0)
            return ret;
        feraiseexcept(FE_UNDERFLOW);
#    endif
        return ret;
    }

    // produce a denormalized half
    e = (ui >> 23);
    shift = 0x7e - e;
    m = 0x800000 | (ui & 0x7fffff);
    r = m << (32 - shift);
    ret |= (m >> shift);
    if (r > 0x80000000 || (r == 0x80000000 && (ret & 0x1) != 0))
        ++ret;
    return ret;
#endif
}

////////////////////////////////////////

#ifdef __cplusplus

#include <iostream>

IMATH_INTERNAL_NAMESPACE_HEADER_ENTER

class DllImpExp half
{
public:
    /// A special tag that lets us initialize a half from the raw bits.
    enum IMATH_EXPORT_ENUM FromBitsTag
    {
        FromBits
    };
    //-------------
    // Constructors
    //-------------

    half () IMATH_NOEXCEPT = default;
    half (float f)IMATH_NOEXCEPT;
    /// Construct from bit-vector
    constexpr half(FromBitsTag, uint16_t bits) IMATH_NOEXCEPT;

    /// Copy constructor
    constexpr half(const half&) IMATH_NOEXCEPT = default;

    /// Move constructor
    constexpr half(half&&) IMATH_NOEXCEPT = default;

    /// Destructor
    ~half() IMATH_NOEXCEPT = default;

    //--------------------
    // Conversion to float
    //--------------------

    operator		float () const IMATH_NOEXCEPT;



    //------------
    // Unary minus
    //------------

    constexpr half		operator - () const IMATH_NOEXCEPT;


    //-----------
    // Assignment
    //-----------
    half& operator= (const half& h) IMATH_NOEXCEPT = default;

    //Move assignment
    half &      operator= (half&& h) IMATH_NOEXCEPT = default;
    half &		operator = (float f) IMATH_NOEXCEPT;

    half &		operator += (half  h) IMATH_NOEXCEPT;
    half &		operator += (float f) IMATH_NOEXCEPT;

    half &		operator -= (half  h) IMATH_NOEXCEPT;
    half &		operator -= (float f) IMATH_NOEXCEPT;

    half &		operator *= (half  h) IMATH_NOEXCEPT;
    half &		operator *= (float f) IMATH_NOEXCEPT;

    half &		operator /= (half  h) IMATH_NOEXCEPT;
    half &		operator /= (float f) IMATH_NOEXCEPT;


    //---------------------------------------------------------
    // Round to n-bit precision (n should be between 0 and 10).
    // After rounding, the significand's 10-n least significant
    // bits will be zero.
    //---------------------------------------------------------

    IMATH_CONSTEXPR14 half		round (unsigned int n) const IMATH_NOEXCEPT;


    //--------------------------------------------------------------------
    // Classification:
    //
    //	h.isFinite()		returns true if h is a normalized number,
    //				a denormalized number or zero
    //
    //	h.isNormalized()	returns true if h is a normalized number
    //
    //	h.isDenormalized()	returns true if h is a denormalized number
    //
    //	h.isZero()		returns true if h is zero
    //
    //	h.isNan()		returns true if h is a NAN
    //
    //	h.isInfinity()		returns true if h is a positive
    //				or a negative infinity
    //
    //	h.isNegative()		returns true if the sign bit of h
    //				is set (negative)
    //--------------------------------------------------------------------

    constexpr bool		isFinite () const IMATH_NOEXCEPT;
    constexpr bool		isNormalized () const IMATH_NOEXCEPT;
    constexpr bool		isDenormalized () const IMATH_NOEXCEPT;
    constexpr bool		isZero () const IMATH_NOEXCEPT;
    constexpr bool		isNan () const IMATH_NOEXCEPT;
    constexpr bool		isInfinity () const IMATH_NOEXCEPT;
    constexpr bool		isNegative () const IMATH_NOEXCEPT;


    //--------------------------------------------
    // Special values
    //
    //	posInf()	returns +infinity
    //
    //	negInf()	returns -infinity
    //
    //	qNan()		returns a NAN with the bit
    //			pattern 0111111111111111
    //
    //	sNan()		returns a NAN with the bit
    //			pattern 0111110111111111
    //--------------------------------------------

    static constexpr half		posInf () IMATH_NOEXCEPT;
    static constexpr half		negInf () IMATH_NOEXCEPT;
    static constexpr half		qNan () IMATH_NOEXCEPT;
    static constexpr half		sNan () IMATH_NOEXCEPT;


    //--------------------------------------
    // Access to the internal representation
    //--------------------------------------

    IMATH_EXPORT constexpr unsigned short	bits () const IMATH_NOEXCEPT;
    IMATH_EXPORT IMATH_CONSTEXPR14 void		setBits (unsigned short bits)IMATH_NOEXCEPT;


  public:
    static_assert (sizeof(float) == sizeof(uint32_t),
        "Assumption about the size of floats correct");
    using uif = imath_half_uif;

  private:

    constexpr uint16_t mantissa() const IMATH_NOEXCEPT;
    constexpr uint16_t exponent() const IMATH_NOEXCEPT;

    unsigned short	_h;

    //---------------------------------------------------
    // Windows dynamic libraries don't like static
    // member variables.
    //---------------------------------------------------
#ifndef OPENEXR_DLL
    static const uif	        _toFloat[1 << 16];
    static const unsigned short _eLut[1 << 9];
#endif
};

#if defined(OPENEXR_DLL)
    //--------------------------------------
    // Lookup tables defined for Windows DLL
    //--------------------------------------
    #if defined(HALF_EXPORTS)
        extern __declspec(dllexport) half::uif		_toFloat[1 << 16];
        extern __declspec(dllexport) unsigned short	_eLut[1 << 9];
    #else
        extern __declspec(dllimport) half::uif		_toFloat[1 << 16];
        extern __declspec(dllimport) unsigned short	_eLut[1 << 9];
    #endif
#endif


//---------------------------------------------------------------------------
//
// Implementation --
//
// Representation of a float:
//
//	We assume that a float, f, is an IEEE 754 single-precision
//	floating point number, whose bits are arranged as follows:
//
//	    31 (msb)
//	    | 
//	    | 30     23
//	    | |      | 
//	    | |      | 22                    0 (lsb)
//	    | |      | |                     |
//	    X XXXXXXXX XXXXXXXXXXXXXXXXXXXXXXX
//
//	    s e        m
//
//	S is the sign-bit, e is the exponent and m is the significand.
//
//	If e is between 1 and 254, f is a normalized number:
//
//	            s    e-127
//	    f = (-1)  * 2      * 1.m
//
//	If e is 0, and m is not zero, f is a denormalized number:
//
//	            s    -126
//	    f = (-1)  * 2      * 0.m
//
//	If e and m are both zero, f is zero:
//
//	    f = 0.0
//
//	If e is 255, f is an "infinity" or "not a number" (NAN),
//	depending on whether m is zero or not.
//
//	Examples:
//
//	    0 00000000 00000000000000000000000 = 0.0
//	    0 01111110 00000000000000000000000 = 0.5
//	    0 01111111 00000000000000000000000 = 1.0
//	    0 10000000 00000000000000000000000 = 2.0
//	    0 10000000 10000000000000000000000 = 3.0
//	    1 10000101 11110000010000000000000 = -124.0625
//	    0 11111111 00000000000000000000000 = +infinity
//	    1 11111111 00000000000000000000000 = -infinity
//	    0 11111111 10000000000000000000000 = NAN
//	    1 11111111 11111111111111111111111 = NAN
//
// Representation of a half:
//
//	Here is the bit-layout for a half number, h:
//
//	    15 (msb)
//	    | 
//	    | 14  10
//	    | |   |
//	    | |   | 9        0 (lsb)
//	    | |   | |        |
//	    X XXXXX XXXXXXXXXX
//
//	    s e     m
//
//	S is the sign-bit, e is the exponent and m is the significand.
//
//	If e is between 1 and 30, h is a normalized number:
//
//	            s    e-15
//	    h = (-1)  * 2     * 1.m
//
//	If e is 0, and m is not zero, h is a denormalized number:
//
//	            S    -14
//	    h = (-1)  * 2     * 0.m
//
//	If e and m are both zero, h is zero:
//
//	    h = 0.0
//
//	If e is 31, h is an "infinity" or "not a number" (NAN),
//	depending on whether m is zero or not.
//
//	Examples:
//
//	    0 00000 0000000000 = 0.0
//	    0 01110 0000000000 = 0.5
//	    0 01111 0000000000 = 1.0
//	    0 10000 0000000000 = 2.0
//	    0 10000 1000000000 = 3.0
//	    1 10101 1111000001 = -124.0625
//	    0 11111 0000000000 = +infinity
//	    1 11111 0000000000 = -infinity
//	    0 11111 1000000000 = NAN
//	    1 11111 1111111111 = NAN
//
// Conversion:
//
//	Converting from a float to a half requires some non-trivial bit
//	manipulations.  In some cases, this makes conversion relatively
//	slow, but the most common case is accelerated via table lookups.
//
//	Converting back from a half to a float is easier because we don't
//	have to do any rounding.  In addition, there are only 65536
//	different half numbers; we can convert each of those numbers once
//	and store the results in a table.  Later, all conversions can be
//	done using only simple table lookups.
//
//---------------------------------------------------------------------------


//----------------------------
// Half-from-float constructor
//----------------------------

inline half::half(float f)IMATH_NOEXCEPT
    :_h(imath_float_to_half(f))
{

}

//------------------------------------------
// Half from raw bits constructor
//------------------------------------------

inline constexpr half::half(FromBitsTag, uint16_t bits) IMATH_NOEXCEPT : _h(bits)
{}

//------------------------------------------
// Half-to-float conversion via table lookup
//------------------------------------------

inline half::operator float () const IMATH_NOEXCEPT
{
    return imath_half_to_float(_h);
}


//-------------------------
// Round to n-bit precision
//-------------------------

inline IMATH_CONSTEXPR14 half
half::round (unsigned int n) const IMATH_NOEXCEPT
{
    //
    // Parameter check.
    //

    if (n >= 10)
	return *this;

    //
    // Disassemble h into the sign, s,
    // and the combined exponent and significand, e.
    //

    unsigned short s = _h & 0x8000;
    unsigned short e = _h & 0x7fff;

    //
    // Round the exponent and significand to the nearest value
    // where ones occur only in the (10-n) most significant bits.
    // Note that the exponent adjusts automatically if rounding
    // up causes the significand to overflow.
    //

    e >>= 9 - n;
    e  += e & 1;
    e <<= 9 - n;

    //
    // Check for exponent overflow.
    //

    if (e >= 0x7c00)
    {
	//
	// Overflow occurred -- truncate instead of rounding.
	//

	e = _h;
	e >>= 10 - n;
	e <<= 10 - n;
    }

    //
    // Put the original sign bit back.
    //

    half h;
    h._h = s | e;

    return h;
}


//-----------------------
// Other inline functions
//-----------------------

inline constexpr half	
half::operator - () const IMATH_NOEXCEPT
{
    half h;
    h._h = _h ^ 0x8000;
    return h;
}


inline half &
half::operator = (float f) IMATH_NOEXCEPT
{
    *this = half (f);
    return *this;
}


inline half &
half::operator += (half h) IMATH_NOEXCEPT
{
    *this = half (float (*this) + float (h));
    return *this;
}


inline half &
half::operator += (float f) IMATH_NOEXCEPT
{
    *this = half (float (*this) + f);
    return *this;
}


inline half &
half::operator -= (half h) IMATH_NOEXCEPT
{
    *this = half (float (*this) - float (h));
    return *this;
}


inline half &
half::operator -= (float f) IMATH_NOEXCEPT
{
    *this = half (float (*this) - f);
    return *this;
}


inline half &
half::operator *= (half h) IMATH_NOEXCEPT
{
    *this = half (float (*this) * float (h));
    return *this;
}


inline half &
half::operator *= (float f) IMATH_NOEXCEPT
{
    *this = half (float (*this) * f);
    return *this;
}


inline half &
half::operator /= (half h) IMATH_NOEXCEPT
{
    *this = half (float (*this) / float (h));
    return *this;
}

inline half&
half::operator/= (float f) IMATH_NOEXCEPT
{
    *this = half(float(*this) / f);
    return *this;
}

inline constexpr uint16_t
half::mantissa() const IMATH_NOEXCEPT
{
    return _h & 0x3ff;
}

inline constexpr uint16_t
half::exponent() const IMATH_NOEXCEPT
{
    return (_h >> 10) & 0x001f;
}

inline constexpr bool
half::isFinite () const IMATH_NOEXCEPT
{
    unsigned short e = (_h >> 10) & 0x001f;
    return e < 31;
}


inline constexpr bool
half::isNormalized () const IMATH_NOEXCEPT
{
    unsigned short e = (_h >> 10) & 0x001f;
    return e > 0 && e < 31;
}


inline constexpr bool
half::isDenormalized () const IMATH_NOEXCEPT
{
    unsigned short e = (_h >> 10) & 0x001f;
    unsigned short m =  _h & 0x3ff;
    return e == 0 && m != 0;
}


inline constexpr bool
half::isZero () const IMATH_NOEXCEPT
{
    return (_h & 0x7fff) == 0;
}


inline constexpr bool
half::isNan () const IMATH_NOEXCEPT
{
    unsigned short e = (_h >> 10) & 0x001f;
    unsigned short m =  _h & 0x3ff;
    return e == 31 && m != 0;
}


inline constexpr bool
half::isInfinity () const IMATH_NOEXCEPT
{
    unsigned short e = (_h >> 10) & 0x001f;
    unsigned short m =  _h & 0x3ff;
    return e == 31 && m == 0;
}


inline constexpr bool
half::isNegative () const IMATH_NOEXCEPT
{
    return (_h & 0x8000) != 0;
}


inline constexpr half
half::posInf () IMATH_NOEXCEPT
{
    half h;
    h._h = 0x7c00;
    return h;
}


inline constexpr half
half::negInf () IMATH_NOEXCEPT
{
    half h;
    h._h = 0xfc00;
    return h;
}


inline constexpr half
half::qNan () IMATH_NOEXCEPT
{
    half h;
    h._h = 0x7fff;
    return h;
}


inline constexpr half
half::sNan () IMATH_NOEXCEPT
{
    half h;
    h._h = 0x7dff;
    return h;
}


inline constexpr unsigned short
half::bits () const IMATH_NOEXCEPT
{
    return _h;
}


inline IMATH_CONSTEXPR14 void
half::setBits (unsigned short bits) IMATH_NOEXCEPT
{
    _h = bits;
}

IMATH_INTERNAL_NAMESPACE_HEADER_EXIT

//-----------
// Stream I/O
//-----------

IMATH_EXPORT std::ostream &	operator << (std::ostream &os, IMATH_INTERNAL_NAMESPACE::half  h);
IMATH_EXPORT std::istream & operator >> (std::istream &is, IMATH_INTERNAL_NAMESPACE::half &h);


//----------
// Debugging
//----------

IMATH_EXPORT void printBits(std::ostream &os, IMATH_INTERNAL_NAMESPACE::half  h);
IMATH_EXPORT void printBits(std::ostream &os, float f);
IMATH_EXPORT void printBits(char  c[19], IMATH_INTERNAL_NAMESPACE::half  h);
IMATH_EXPORT void printBits(char  c[35], float f);

#    ifndef __CUDACC__
using half = IMATH_INTERNAL_NAMESPACE::half;
#    else
#        include <cuda_fp16.h>
#    endif

#undef HALF_EXPORT_CONST
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif

#endif
