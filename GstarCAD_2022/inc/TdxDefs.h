/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////

#ifndef TDXDEFS_INCLUDE
#define TDXDEFS_INCLUDE

#include "OdPlatformSettings.h"

#include "TD_PackPush.h"

#define RQSAVE     14
#define RQEND      15
#define RQQUIT     16
#define RQCFG      22

#define RQXLOAD    100
#define RQXUNLD    101
#define RQSUBR     102
#define RQHUP      105
#define RQXHELP    118

#define RSRSLT     1
#define RSERR      3

#define RTNONE     5000
#define RTREAL     5001
#define RTPOINT    5002
#define RTSHORT    5003
#define RTANG      5004
#define RTSTR      5005
#define RTENAME    5006
#define RTPICKS    5007
#define RTORINT    5008
#define RT3DPOINT  5009
#define RTLONG     5010
#define RTVOID     5014
#define RTLB       5016
#define RTLE       5017
#define RTDOTE     5018
#define RTNIL      5019
#define RTDXF0     5020
#define RTT        5021
#define RTBINARY   5022
#define RTRESBUF   5023
#define RTMODELESS 5027

#define RTLONG_PTR 5030
#define RTINT64    5031

#define RTCOROUTINEINFO 5035

#define RTNORM           ( 5100)
#define RTERROR          (-5001)
#define RTCAN            (-5002)
#define RTREJ            (-5003)
#define RTFAIL           (-5004)
#define RTKWORD          (-5005)
#define RTINPUTTRUNCATED (-5008)

#ifndef WM_GCAD_KEEPFOCUS
#ifndef WM_USER
#define WM_GCAD_KEEPFOCUS (0x0400+0x6D01)
#else
#define WM_GCAD_KEEPFOCUS (WM_USER+0x6D01)
#endif   
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef EOS
#define EOS __OD_T('\0')
#endif

#ifdef X
#undef X
#endif
#ifdef Y
#undef Y
#endif
#ifdef Z
#undef Z
#endif
#ifdef T
#undef T
#endif

#ifndef _XYZT_DEFINED
#define _XYZT_DEFINED
enum { X = 0, Y = 1, Z = 2 };
enum { T = 3 };
#endif

#define PAUSE __OD_T("\\")

enum
{
  RSG_NONULL      = 0x01,
  RSG_NOZERO      = 0x02,
  RSG_NONEG       = 0x04,
  RSG_NOLIM       = 0x08,
  RSG_GETZ        = 0x10,
  RSG_DASH        = 0x20,

  RSG_2D          = 0x40,

  RSG_OTHER       = 0x80,
  RSG_DDISTFIRST  = 0x100,
  RSG_TRACKUCS    = 0x200,
  RSG_NOORTHOZ    = 0x400,
  RSG_NOOSNAP     = 0x800,

  RSG_NOPMENU		= 0x1000,
  RSG_NOCANCEL	= 0x2000,
  RSG_NOVIEWCHG	= 0x4000,
  RSG_NODOCCHG	= 0x8000,
};

enum
{
  INP_NNULL   = RSG_NONULL,
  INP_NZERO   = RSG_NOZERO,
  INP_NNEG    = RSG_NONEG,
  INP_NLIM    = RSG_NOLIM,
  INP_DASH    = RSG_DASH,
  INP_NZCOORD = RSG_2D
};

enum SelectorType
{
  SELECT_TYPE_FREE = 0,
  SELECT_TYPE_PICK,
  SELECT_TYPE_WPOLY,
  SELECT_TYPE_CPOLY,
  SELECT_TYPE_FENCE,
  SELECT_TYPE_SUBENTITY,
  SELECT_TYPE_BAG,
  SELECT_TYPE_LAST,
  SELECT_TYPE_LEAF,
  SELECT_TYPE_GROUP,
  SELECT_TYPE_PASTE,
  SELECT_TYPE_HATCHASC,
  SELECT_TYPE_NRVP,
  SELECT_TYPE_OCCLASS
};

typedef double    tdx_real;
typedef tdx_real  tdx_point[3];
#if !defined(_WIN64) && !defined(__LP64__) && !defined(_AC64)
typedef __w64 long tdx_name[2];
typedef __w64 long *tdx_namep;
#else
typedef __int64 tdx_name[2];
typedef __int64 *tdx_namep;
#endif
typedef tdx_real  tdx_matrix[4][4];
typedef tdx_real *tdx_pointp;


struct tdx_binary
{
  short clen;
  char *buf;
};

union tdx_uval
{
  tdx_real rreal;
  tdx_real rpoint[3];
  short    rint;
  OdChar  *rstring;
#if !defined(_WIN64) && !defined(__LP64__) && !defined(_AC64)
  __w64 long  rlname[2];
  __w64 long  mnLongPtr;  // use this instead of rlong for pointers
#else
  __int64     rlname[2];
  __int64     mnLongPtr;  // use this instead of rlong for pointers
#endif

#ifdef __LP64__
  int         rlong;      // a 32-bit integer value
#else
  long        rlong;      // a 32-bit integer value
#endif

  __int64  mnInt64;
  __int64  rhuge;
  struct tdx_binary rbinary;
  unsigned char ihandle[8];
}; 

struct resbuf
{
  struct resbuf *rbnext;
  short restype;
  union tdx_uval resval;
};

typedef struct resbuf *PRESBUF;
typedef const struct resbuf *PCRESBUF;

#include "TD_PackPop.h"

#endif
