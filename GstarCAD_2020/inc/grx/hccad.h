#ifndef _HCCAD_H_
#define _HCCAD_H_

#include "../OdaCommon.h"
#include "../StringArray.h"
#include "gchar.h"

#pragma pack (push, 8)

#define _GCAD_WINDOWS_ 1
#define _GRX_CUSTOM_DRAG_N_DROP_

#ifdef OdBool_is_bool
#define Hccad_Boolean_is_bool
#endif

namespace Hccad
{
  typedef OdInt8    Int8;
  typedef OdInt16   Int16;
  typedef OdInt32   Int32;
  typedef OdSize    size_type;
  typedef OdUInt8   UInt8;
  typedef OdUInt16  UInt16;
  typedef OdUInt32  UInt32;
  typedef OdInt64   Int64;
  typedef OdUInt64  UInt64;

  typedef unsigned char  uchar;
  typedef unsigned short ushort;
  typedef unsigned int   uint;
  typedef unsigned long  ulong;

  typedef OdBool Boolean;
  enum 
  {
    kFalse = ::kFalse, 
    kTrue  = ::kTrue,
  };

#ifdef _WIN64
  typedef unsigned __int64    Size_t;
  typedef __int64             SSize_t;
#else
  typedef unsigned long       Size_t;
  typedef long                SSize_t;
#endif

  typedef __w64 OdLongPtr     LongPtr;
  typedef __w64 OdULongPtr    ULongPtr;

  typedef __w64 OdIntPtr      IntPtr;
  typedef __w64 OdUIntPtr     UIntPtr;

  typedef LongPtr             IntDbId;
  typedef IntPtr              GsMarker;
};

#ifndef NULL
#define NULL 0
#endif

#pragma pack (pop)

typedef char                  LEGACY_CHAR;
typedef char*                 LEGACY_STRING;
typedef const                 char* LEGACY_STRING_CONST;
typedef unsigned short        WIDE_CHAR;
typedef unsigned short*       WIDE_STRING;
typedef const unsigned short* WIDE_STRING_CONST;
typedef char*                 MEMORY_POINTER;
typedef const char*           MEMORY_POINTER_CONST;
typedef unsigned char         GC_BYTE;

#define HCCAD_NO_VTABLE __declspec(novtable)
#define HCCAD_STDCALL   __stdcall

//For Internal Use Only
typedef Hccad::Int8        GINT8;
typedef Hccad::Int16       GINT16;
typedef Hccad::Int32       GINT32;
typedef Hccad::Int64       GINT64;

typedef Hccad::UInt8       GUINT8;
typedef Hccad::UInt16      GUINT16;
typedef Hccad::UInt32      GUINT32;
typedef Hccad::UInt64      GUINT64;

typedef Hccad::UInt8       GBYTE;
typedef Hccad::UInt16      GWORD;
typedef Hccad::UInt32      GDWORD;
typedef Hccad::UInt64      GQWORD;

typedef Hccad::size_type   GSIZE;
typedef Hccad::Boolean     GBOOL;

#define GC_PI  OdaPI
#define GC_PI2 OdaPI2
#define GC_PI4 OdaPI4
#define GC_2PI (OdaPI + OdaPI)

#endif
