/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _GSOFT_H
#define   _GSOFT_H

#if defined(__cplusplus)
#include <cstdint>
#else
#include <stdint.h>
#endif
#include <stddef.h>
#include "GdGChar.h"

#define Gsoft_Boolean_is_bool 1
#define Gsoft_Int32_is_int    1

#pragma pack (push, 8)

#if defined(_MSC_VER)
#ifndef _GSOFT_CROSS_PLATFORM_
#define _GSOFT_WINDOWS_ 1
#endif
#elif defined(__clang__)
#if defined(_GSOFT_MAC_)
#define __w64
#endif

#endif

#if (defined(_MSC_VER) && defined(_WIN64)) || (defined(__clang__) && defined(__LP64__)) || (defined(__linux__) && defined(__LP64__))
#define _GC64 1
#endif

#if defined(__cplusplus)
struct Gsoft
{
#if defined(__linux__)
  typedef signed char               Int8;
  typedef short                     Int16;

  typedef unsigned char             UInt8;
  typedef unsigned short            UInt16;
  typedef int                       Int32;
  typedef unsigned int              UInt32;

  typedef long long                 Int64;
  typedef unsigned long long        UInt64;

  typedef int                       Int32_t;
  typedef long long                 int64_t;

#else
  typedef int8_t      Int8;
  typedef int16_t     Int16;

  typedef uint8_t     UInt8;
  typedef uint16_t    UInt16;

  typedef int32_t     Int32;
  typedef uint32_t    UInt32;

  typedef int64_t     Int64;
  typedef uint64_t    UInt64;
#endif
  typedef unsigned char  uchar;
  typedef unsigned short ushort;
  typedef unsigned int   uint;

#if (defined(_MSC_VER) && !defined(_WIN64) && !defined (_GC64)) || (defined(__linux__) && !defined(__LP64__) && !defined (_GC64))
  static_assert(sizeof(void *) == 4, "ptr size in 32-bit windows build?");
  typedef int32_t             LongPtr;
  typedef uint32_t            ULongPtr;
  typedef int32_t             IntPtr;
  typedef uint32_t            UIntPtr;
#else
  static_assert(sizeof(void *) == 8, "ptr size in 64-bit build?");
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
};
#endif 
#undef NULL
#define NULL 0

#ifdef _GSOFT_MAC_
#ifdef nil
#undef nil
#endif
#define nil __DARWIN_NULL
#endif

#pragma pack (pop)

#if defined(_MSC_VER)
#define GSOFT_NO_VTABLE           __declspec(novtable)
#define GSOFT_STDCALL             __stdcall
#define GSOFT_DEPRECATED          __declspec(deprecated)
#define GSOFT_DEPRECATED_MSG(MSG) __declspec(deprecated(MSG))
#define GSOFT_DATA_IMPORT         __declspec(dllimport)
#define GSOFT_PACK_BEGIN          __pragma(pack(push,1))
#define GSOFT_PACK_END            __pragma(pack(pop))
#define GSOFT_HIDDEN_SYMBOL
#else
#define GSOFT_NO_VTABLE

#if defined(__LP64__) || defined(__clang__)
#define GSOFT_STDCALL
#else
#define GSOFT_STDCALL         __attribute__((stdcall))
#endif

#define GSOFT_DEPRECATED          __attribute__((__deprecated__))
#define GSOFT_DEPRECATED_MSG(MSG) __attribute__((__deprecated__))
#define GSOFT_DATA_IMPORT         extern

#define __declspec(method)        __declspec_##method
#define _declspec(method)         __declspec_##method

#define __declspec_selectany      __attribute__ ((__weak__))

#define __declspec_dllexport      __attribute__ ((__visibility__("default")))
#define __declspec_dllimport      

#define __declspec_noinline       __attribute__ ((__noinline__))
#define __declspec_noreturn       __attribute__ ((__noreturn__))
#define __declspec_deprecated     __attribute__ ((__deprecated__))
#define __declspec_novtable
#define __declspec_allocate(name) __attribute__ ((section("__DATA," name)))
#define GSOFT_PACK_BEGIN
#define GSOFT_PACK_END            __attribute__((packed))
#define GSOFT_HIDDEN_SYMBOL       __attribute__ ((visibility("hidden")))
#endif

#if defined(_MSC_EXTENSIONS) || defined (__clang__)
#define GSOFT_OVERRIDE  override
#if defined(_MSC_VER) && (_MSC_VER <= 1600) 
#define GSOFT_SEALED sealed
#else
#define GSOFT_SEALED final
#endif
#else
#define GSOFT_OVERRIDE
#define GSOFT_SEALED
#endif

#define MIGRATION_ERRORS

#if defined(_MSC_VER) && defined (MIGRATION_ERRORS) || defined(__clang__)
#define GSOFT_SEALED_VIRTUAL virtual
#if !defined(GSOFT_SEALED)
#define GSOFT_SEALED sealed
#endif
#else
#define GSOFT_SEALED_VIRTUAL
#if !defined(GSOFT_SEALED)
#define GSOFT_SEALED sealed
#endif
#endif

#if defined(__INTEL_COMPILER) || defined (_MSC_VER)
#define GSOFT_FORCE_INLINE __forceinline
#else
#define GSOFT_FORCE_INLINE inline
#endif

#ifdef _GSOFT_WINDOWS_
#define VA_ARG_WCHAR(ap, t)      va_arg(ap, wchar_t)
#else
#define VA_ARG_WCHAR(ap, t)      va_arg(ap, int)
#endif

#ifdef _GSOFT_UNITTEST_
#ifdef GSOFT_SEALED
#undef GSOFT_SEALED
#endif
#define GSOFT_SEALED
#endif

#ifdef _MSC_VER
#define GSOFT_UNREFED_PARAM(x) x
#elif defined(__clang__) || defined(__linux__)
#define GSOFT_UNREFED_PARAM(x) (void)(x);
#else
#error Unknown compiler.
#endif

#ifdef _MSC_VER
#define GSOFT_UNREACHABLE __assume(false)
#elif defined(__clang__) || defined(__linux__)
#define GSOFT_UNREACHABLE __builtin_unreachable()
#else
#error Unknown compiler.
#endif

#ifdef _GSOFT_WEB_
#define GSOFT_EXPORT
#else
#define GSOFT_EXPORT __declspec(dllexport)
#endif

#endif
