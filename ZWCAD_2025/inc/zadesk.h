
#ifndef   _ZADESK_H
#define   _ZADESK_H

#if defined(__cplusplus)
#include <cstdint>
#else
#include <stdint.h>
#endif
#include <stddef.h>
#include "zAdAChar.h" 

#define ZSoft_Boolean_is_bool 1
#define ZSoft_Int32_is_int 1

#pragma pack (push, 8)

#if defined(_MSC_VER)
#ifndef _ZSOFT_CROSS_PLATFORM_
    #define _ZSOFT_WINDOWS_ 1
#endif
#elif defined(__clang__)
#if defined(_ZSOFT_MAC_)
    #define __w64
#endif

#endif

#if (defined(_MSC_VER) && defined(_WIN64)) || (defined(__clang__) && defined(__LP64__))
#define _ZC64    1
#endif

#if defined(__cplusplus)
struct ZSoft
{

    typedef int8_t      Int8;
    typedef int16_t     Int16;

    typedef uint8_t     UInt8;
    typedef uint16_t    UInt16;

    typedef int32_t     Int32;
    typedef uint32_t    UInt32;

    typedef int64_t     Int64;
    typedef uint64_t    UInt64;

    typedef unsigned char  uchar;
    typedef unsigned short ushort;
    typedef unsigned int   uint;

#if !defined(_WIN64) && !defined (_ZC64)
    static_assert(sizeof(void*) == 4, "pointer size in 32-bit windows build ?");
    typedef int32_t             LongPtr;
    typedef uint32_t            ULongPtr;
    typedef int32_t             IntPtr;
    typedef uint32_t            UIntPtr;
#else

    static_assert(sizeof(void*) == 8, "pointer size in 64-bit build ?");
    typedef int64_t             LongPtr;
    typedef uint64_t            ULongPtr;
    typedef int64_t             IntPtr;
    typedef uint64_t            UIntPtr;

#endif

    typedef LongPtr IntDbId;
    typedef IntPtr GsMarker;

    typedef bool       Boolean;
    static const bool kFalse = false;
    static const bool kTrue = true;

    using Time64 = int64_t;

    using ColorRef = uint32_t;
    using RGBQuad  = uint32_t;
};
#endif

#undef NULL
#define NULL 0

#ifdef _ZSOFT_MAC_
#ifdef nil
#undef nil
#endif
#define nil __DARWIN_NULL
#endif

#pragma pack (pop)

#if defined(_MSC_VER)
    #define ZSOFT_NO_VTABLE             __declspec(novtable)
    #define ZSOFT_STDCALL               __stdcall
    #define ZSOFT_DEPRECATED            __declspec(deprecated)
    #define ZSOFT_DEPRECATED_MSG(MSG)   __declspec(deprecated(MSG))
    #define ZSOFT_DATA_IMPORT         __declspec(dllimport)
    #define ZSOFT_PACK_BEGIN __pragma(pack(push,1))
    #define ZSOFT_PACK_END __pragma(pack(pop))
    #define ZSOFT_HIDDEN_SYMBOL 

    #define ZSOFT_DLLEXPORT __declspec(dllexport)
    #define ZSOFT_DLLIMPORT __declspec(dllimport)
    #define ZSOFT_FORCE_INLINE __forceinline
#else
    #define ZSOFT_NO_VTABLE

    #if defined(__LP64__) || defined(__clang__)
    #define ZSOFT_STDCALL
    #else
    #define ZSOFT_STDCALL         __attribute__((stdcall))   
    #endif

    #define ZSOFT_DEPRECATED          __attribute__((__deprecated__))
    #define ZSOFT_DEPRECATED_MSG(MSG) __attribute__((__deprecated__))
    #define ZSOFT_DATA_IMPORT         extern

    #define __declspec(method) __declspec_##method
    #define _declspec(method) __declspec_##method

    #define __declspec_selectany      __attribute__ ((__weak__))

    #define __declspec_dllexport      __attribute__ ((__visibility__("default")))
    #define __declspec_dllimport

    #define __declspec_noinline       __attribute__ ((__noinline__))
    #define __declspec_noreturn       __attribute__ ((__noreturn__))
    #define __declspec_deprecated     __attribute__ ((__deprecated__))
    #define __declspec_novtable
    #define __declspec_allocate(name) __attribute__ ((section("__DATA," name)))
    #define ZSOFT_PACK_BEGIN
    #define ZSOFT_PACK_END __attribute__((packed))
    #define ZSOFT_HIDDEN_SYMBOL   __attribute__ ((visibility("hidden"))) 
#endif

#if defined(_MSC_EXTENSIONS) || defined (__clang__)
#define ZSOFT_OVERRIDE override
    #if defined(_MSC_VER) && (_MSC_VER <= 1600)
        #define ZSOFT_SEALED sealed
    #else
        #define ZSOFT_SEALED final
    #endif
#else
    #define ZSOFT_OVERRIDE
    #define ZSOFT_SEALED
#endif

#define MIGRATION_ERRORS

#if defined(_MSC_VER) && defined (MIGRATION_ERRORS) || defined(__clang__)
    #define ZSOFT_SEALED_VIRTUAL virtual
    #if !defined(ZSOFT_SEALED)
        #define ZSOFT_SEALED sealed
    #endif
#else
    #define ZSOFT_SEALED_VIRTUAL 
    #if !defined(ZSOFT_SEALED)
         #define ZSOFT_SEALED sealed
    #endif
#endif

#if defined(__INTEL_COMPILER) || defined (_MSC_VER)
    #define ZSOFT_FORCE_INLINE __forceinline
#else
    #define ZSOFT_FORCE_INLINE inline
#endif

#ifdef _ZSOFT_WINDOWS_
#define VA_ARG_WCHAR(ap, t)      va_arg(ap, wchar_t)
#else
#define VA_ARG_WCHAR(ap, t)      va_arg(ap, int)
#endif

#ifdef _ZSOFT_UNITTEST_
#ifdef ZSOFT_SEALED
    #undef ZSOFT_SEALED
#endif
#define ZSOFT_SEALED
#endif

#ifdef _MSC_VER
#define ZSOFT_UNREFED_PARAM(x) x
#elif defined(__clang__)
#define ZSOFT_UNREFED_PARAM(x) (void)(x);
#else
#error Unknown compiler.
#endif

#ifdef _MSC_VER
#define ZSOFT_UNREACHABLE __assume(false)
#elif defined(__clang__)
#define ZSOFT_UNREACHABLE __builtin_unreachable()
#else
#error Unknown compiler.
#endif

#ifdef _MSC_VER
#define ZSOFT_FORCE_OPTNONE
#elif defined(__clang__)
    #if defined(__apple_build_version__) && ((__clang_major__ > 8) || ((__clang_major__ == 8) && (__clang_minor__ >= 1)))
        #define ZSOFT_APPLE_WITH_CLANG_8_1_OR_HIGHER
    #endif

    #if defined(__ANDROID__) || defined(ZSOFT_APPLE_WITH_CLANG_8_1_OR_HIGHER)
        #define ZSOFT_FORCE_OPTNONE __attribute__((optnone))
    #else
        #define ZSOFT_FORCE_OPTNONE
    #endif
#else
    #error Unknown compiler.
#endif

#if defined(_ZSOFT_WEB_)

    #define ZSOFT_EXPORT
#else
    #define ZSOFT_EXPORT __declspec(dllexport)
#endif

#ifdef __has_cpp_attribute
    #if __has_cpp_attribute(nodiscard)
        #define ZSOFT_NODISCARD [[nodiscard]]
    #endif
#endif
#ifndef ZSOFT_NODISCARD
    #define ZSOFT_NODISCARD
#endif

#ifdef _ZSOFT_CROSS_PLATFORM_

#define ZSOFT_DEPRECATE_FOR_INTERNAL_USE ZSOFT_DEPRECATED
#else
#define ZSOFT_DEPRECATE_FOR_INTERNAL_USE
#endif

#define ZSOFT_SUPPRESS_DEPRECATED __pragma (warning(suppress:4996))

#endif
