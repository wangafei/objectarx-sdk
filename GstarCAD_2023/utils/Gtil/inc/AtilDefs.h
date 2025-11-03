/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef ATILDEFS_H
#define ATILDEFS_H

#if !defined(_MSC_VER) || _MSC_VER>=1600
#include <stdint.h>
#endif

#if defined GCIMAGING_API
#define GTIL_EXPORT _declspec(dllexport)
#else
#define GTIL_EXPORT _declspec(dllimport)
#endif

#define GTIL_GCC_DEFAULT

#ifndef _HALF_H
#include "Half.h"
#endif

namespace Gtil
{
#ifndef Gtil_max
#define Gtil_max(a,b) ((a) >= (b) ? (a) : (b))
#define Gtil_min(a,b) (((a) < (b)) ? (a) : (b))
#endif
  enum Orientation
  {
    kTopDownLeftRight,
    kTopDownRightLeft,
    kBottomUpLeftRight,
    kBottomUpRightLeft,
    kLeftRightTopDown,
    kRightLeftTopDown,
    kLeftRightBottomUp,
    kRightLeftBottomUp
  };

  const double kPi        = 3.14159265358979323846;
  const double kTwoPi     = 6.28318530717958647692;
  const double kHalfPi    = 1.57079632679489661923;
  const double kTolerance = 1.0e-10;
  const double kEpsilon   = 1.0e-10;

#ifdef _WIN32
  typedef unsigned char Data8;
  typedef unsigned short Data16;
  typedef unsigned int Data32;
  typedef unsigned __int64 Data64;
  typedef struct _GTIL_DATA128 {
    \
      union {
      \
        struct { unsigned int a; unsigned int b; unsigned int c; unsigned int d; } ui; \
        struct { float a; float b; float c; float d; } fl; \
        struct { Data64 high64; Data64 low64; } db; \
    } value; \
      bool operator== (const struct _GTIL_DATA128& rhs) const { return (value.ui.a == rhs.value.ui.a && value.ui.b == rhs.value.ui.b && value.ui.c == rhs.value.ui.c && value.ui.d == rhs.value.ui.d); } \
        bool operator!= (const struct _GTIL_DATA128& rhs) const { return (value.ui.a != rhs.value.ui.a || value.ui.b != rhs.value.ui.b || value.ui.c != rhs.value.ui.c || value.ui.d != rhs.value.ui.d); } \
        void setToZero() { value.db.high64 = 0; value.db.low64 = 0; } \
  } Data128;

  typedef unsigned char Byte;

  typedef signed char   Int8;
  typedef unsigned char UInt8;

  typedef signed short   Int16;
  typedef unsigned short UInt16;

  typedef signed int   Int32;
  typedef unsigned int UInt32;

  typedef signed __int64   Int64;
  typedef unsigned __int64 UInt64;

#ifndef INT32_MAX
#define INT32_MAX 2147483647
#endif
#ifndef INT32_MIN
#define INT32_MIN -2147483647-1
#endif
#ifndef UINT32_MAX    
#define UINT32_MAX 4294967295
#endif
#ifndef FLOAT_MAX
#define FLOAT_MAX 1E+37 
#endif
#ifndef MAX_ALPHA
#define MAX_ALPHA 1 
#endif
#ifndef NULL
#define NULL 0
#endif

#ifdef UNICODE
  typedef wchar_t char_t;
#else
  typedef char char_t;
#endif

#else

#ifdef __INTEL_COMPILER  
  typedef unsigned char Data8;
  typedef unsigned short Data16;
  typedef unsigned int Data32;
  typedef unsigned __int64 Data64;
  typedef struct _GTIL_DATA128 {
    \
      union {
      \
        struct { unsigned int a; unsigned int b; unsigned int c; unsigned int d; } ui; \
        struct { float a; float b; float c; float d; } fl; \
        struct { Data64 high64; Data64 low64; } db; \
    } value; \
      bool operator== (const struct _GTIL_DATA128& rhs) const { return (value.ui.a == rhs.value.ui.a && value.ui.b == rhs.value.ui.b && value.ui.c == rhs.value.ui.c && value.ui.d == rhs.value.ui.d); } \
        bool operator!= (const struct _GTIL_DATA128& rhs) const { return (value.ui.a != rhs.value.ui.a || value.ui.b != rhs.value.ui.b || value.ui.c != rhs.value.ui.c || value.ui.d != rhs.value.ui.d); } \
        void setToZero() { value.db.high64 = 0; value.db.low64 = 0; } \
  } Data128;

  typedef unsigned char Byte;

  typedef signed char   Int8;
  typedef unsigned char UInt8;

  typedef signed short   Int16;
  typedef unsigned short UInt16;

  typedef signed int   Int32;
  typedef unsigned int UInt32;

  typedef signed __int64   Int64;
  typedef unsigned __int64 UInt64;

#ifndef INT32_MAX
#define INT32_MAX   2147483647
#endif
#ifndef INT32_MIN
#define INT32_MIN  -2147483647-1
#endif
#ifndef UINT32_MAX
#define UINT32_MAX  4294967295
#endif
#ifndef MAX_ALPHA
#define MAX_ALPHA 1 
#endif
#ifndef FLOAT_MAX
#define FLOAT_MAX 1E+37 
#endif
#ifndef NULL
#define NULL  0
#endif

#ifdef UNICODE
  typedef wchar_t char_t;
#else
  typedef char char_t;
#endif

#else 

  typedef unsigned char Data8;
  typedef unsigned short Data16;
  typedef unsigned int Data32;
  typedef unsigned long long Data64;
  typedef struct _GTIL_DATA128 {
    \
      union {
      \
        struct { unsigned int a; unsigned int b; unsigned int c; unsigned int d; } ui; \
        struct { float a; float b; float c; float d; } fl; \
        struct { Data64 high64; Data64 low64; } db; \
    } value; \
      bool operator== (const struct _GTIL_DATA128& rhs) const { return (value.ui.a == rhs.value.ui.a && value.ui.b == rhs.value.ui.b && value.ui.c == rhs.value.ui.c && value.ui.d == rhs.value.ui.d); } \
        bool operator!= (const struct _GTIL_DATA128& rhs) const { return (value.ui.a != rhs.value.ui.a || value.ui.b != rhs.value.ui.b || value.ui.c != rhs.value.ui.c || value.ui.d != rhs.value.ui.d); } \
        void setToZero() { value.db.high64 = 0; value.db.low64 = 0; } \
  } Data128;


  typedef unsigned char Byte;

  typedef signed char   Int8;
  typedef unsigned char UInt8;

  typedef signed short   Int16;
  typedef unsigned short UInt16;

  typedef signed int   Int32;
  typedef unsigned int UInt32;

  typedef signed long long   Int64;
  typedef unsigned long long UInt64;

#ifndef INT32_MAX
#define INT32_MAX   2147483647
#endif
#ifndef INT32_MIN
#define INT32_MIN  -2147483647-1
#endif
#ifndef UINT32_MAX
#define UINT32_MAX  4294967295
#endif
#ifndef MAX_ALPHA
#define MAX_ALPHA 1 
#endif
#ifndef FLOAT_MAX
#define FLOAT_MAX 1E+37 
#endif
#ifndef NULL
#define NULL    0
#endif

#ifdef UNICODE
  typedef wchar_t char_t;
#else
  typedef char char_t;
#endif

#endif
#endif

#define DATA32_MAX UINT32_MAX

  typedef union _GTIL_LARGE_INTEGER
  {
    struct
    {
      UInt32 LowPart;
      int HighPart;
    } s;
    struct
    {
      UInt32 LowPart;
      int HighPart;
    } u;
    UInt64 QuadPart;
  } GTIL_LARGE_INTEGER;
}

#ifndef GTILVERSIONS_H
#include "GtilVersions.h"
#endif

#endif
