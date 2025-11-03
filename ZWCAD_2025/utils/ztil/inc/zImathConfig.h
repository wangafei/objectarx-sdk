
#ifndef Z_IMATH_CONFIG_H
#define Z_IMATH_CONFIG_H 1

#pragma once

#define IMATH_HALF_USE_LOOKUP_TABLE

#define IMATH_INTERNAL_NAMESPACE_CUSTOM 0
#define IMATH_INTERNAL_NAMESPACE Imath_3_2

#define IMATH_NAMESPACE_CUSTOM 0
#define IMATH_NAMESPACE Imath

#define IMATH_VERSION_STRING "3.2.0"
#define IMATH_PACKAGE_STRING "Imath 3.2.0-dev"

#define IMATH_VERSION_MAJOR 3
#define IMATH_VERSION_MINOR 2
#define IMATH_VERSION_PATCH 0
#define IMATH_VERSION_RELEASE_TYPE "-dev"

#define IMATH_VERSION_HEX                                                      \
    ((uint32_t (IMATH_VERSION_MAJOR) << 24) |                                  \
     (uint32_t (IMATH_VERSION_MINOR) << 16) |                                  \
     (uint32_t (IMATH_VERSION_PATCH) << 8))

#define IMATH_LIB_VERSION_STRING "29.0.0"

#define IMATH_USE_NOEXCEPT 1
#if IMATH_USE_NOEXCEPT
#    define IMATH_NOEXCEPT noexcept
#else
#    define ZIMATH_NOEXCEPT
#endif

#ifndef IMATH_FOREIGN_VECTOR_INTEROP
#    if defined(__GNUC__) && __GNUC__ == 4 && !defined(__clang__)
#        define IMATH_FOREIGN_VECTOR_INTEROP 0
#    else
#        define IMATH_FOREIGN_VECTOR_INTEROP 1
#    endif
#endif

#ifdef __CUDACC__
#    define IMATH_HOSTDEVICE __host__ __device__
#else
#    define IMATH_HOSTDEVICE
#endif

#if defined(__GNUC__) || defined(__clang__) || defined(__INTEL_COMPILER)
#    ifdef __cplusplus
#        define IMATH_LIKELY(x) (__builtin_expect (static_cast<bool> (x), true))
#        define IMATH_UNLIKELY(x)                                              \
            (__builtin_expect (static_cast<bool> (x), false))
#    else
#        define IMATH_LIKELY(x) (__builtin_expect ((x), 1))
#        define IMATH_UNLIKELY(x) (__builtin_expect ((x), 0))
#    endif
#else
#    define IMATH_LIKELY(x) (x)
#    define IMATH_UNLIKELY(x) (x)
#endif

#ifndef __has_attribute
#    define __has_attribute(x) 0
#endif

#if defined(_MSC_VER)
#    define IMATH_DEPRECATED(msg) __declspec(deprecated (msg))
#elif defined(__cplusplus) && __cplusplus >= 201402L
#    define IMATH_DEPRECATED(msg) [[deprecated (msg)]]
#elif defined(__GNUC__) || defined(__clang__)
#    define IMATH_DEPRECATED(msg) __attribute__ ((deprecated (msg)))
#else
#    define IMATH_DEPRECATED(msg)
#endif

#define IMATH_ENABLE_API_VISIBILITY

#if !defined(_MSC_VER) && defined(IMATH_ENABLE_API_VISIBILITY)
#    define IMATH_PUBLIC_SYMBOL_ATTRIBUTE                                      \
        __attribute__ ((__visibility__ ("default")))
#    define IMATH_PRIVATE_SYMBOL_ATTRIBUTE                                     \
        __attribute__ ((__visibility__ ("hidden")))

#    if __has_attribute(__type_visibility__)
#        define IMATH_PUBLIC_TYPE_VISIBILITY_ATTRIBUTE                         \
            __attribute__ ((__type_visibility__ ("default")))
#    endif
#endif

#endif
