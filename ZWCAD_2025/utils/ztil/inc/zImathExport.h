
#ifndef Z_IMATHEXPORT_H
#define Z_IMATHEXPORT_H

#include "zImathConfig.h"

#if defined(IMATH_DLL)

#  if defined(IMATH_EXPORTS)
#    define IMATH_EXPORT __declspec(dllexport)
#    define IMATH_EXPORT_CONST extern __declspec(dllexport)
#  else
#    define IMATH_EXPORT __declspec(dllimport)
#    define IMATH_EXPORT_CONST extern __declspec(dllimport)
#  endif

#  define IMATH_EXPORT_TYPE
#  define IMATH_EXPORT_ENUM
#  define IMATH_EXPORT_TEMPLATE_TYPE

#else

#  ifdef IMATH_PUBLIC_SYMBOL_ATTRIBUTE
#    define IMATH_EXPORT IMATH_PUBLIC_SYMBOL_ATTRIBUTE
#    define IMATH_EXPORT_CONST extern const IMATH_PUBLIC_SYMBOL_ATTRIBUTE
#  else
#    define IMATH_EXPORT
#    define IMATH_EXPORT_CONST extern const
#  endif

#  ifdef IMATH_PUBLIC_TYPE_VISIBILITY_ATTRIBUTE
#    define IMATH_EXPORT_ENUM IMATH_PUBLIC_TYPE_VISIBILITY_ATTRIBUTE
#    define IMATH_EXPORT_TEMPLATE_TYPE IMATH_PUBLIC_TYPE_VISIBILITY_ATTRIBUTE
#    define IMATH_EXPORT_TYPE IMATH_PUBLIC_TYPE_VISIBILITY_ATTRIBUTE
#  else
#    define IMATH_EXPORT_ENUM
#    define IMATH_EXPORT_TEMPLATE_TYPE IMATH_EXPORT
#    define IMATH_EXPORT_TYPE IMATH_EXPORT
#  endif

#endif

#endif
