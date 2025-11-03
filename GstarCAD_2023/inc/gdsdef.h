/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gdsdef_h
#define _gdsdef_h 1

#include "gsoft.h"

#define TRUE    1
#define FALSE   0
#ifndef EOS
#define EOS     GCRX_T('\0')
#endif

#pragma pack(push, 8)

typedef double   gds_real;
typedef gds_real gds_point[3];
#if (defined(_MSC_VER) && defined(_WIN64)) || (defined(__clang__) && defined(__LP64__)) || defined(__linux__)
typedef int64_t gds_name[2];
typedef int64_t *gds_namep;
#else
typedef int32_t gds_name[2];
typedef int32_t *gds_namep;
#endif
typedef gds_real gds_matrix[4][4];

typedef gds_real *gds_pointp;


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

#define PAUSE GCRX_T("\\")


enum {
  RSG_NONULL = 0x0001,
  RSG_NOZERO = 0x0002,
  RSG_NONEG = 0x0004,
  RSG_NOLIM = 0x0008,
  RSG_GETZ = 0x0010,
  RSG_DASH = 0x0020,
  RSG_2D = 0x0040,
  RSG_OTHER = 0x0080,
  RSG_DDISTFIRST = 0x0100,
  RSG_TRACKUCS = 0x0200,
  RSG_NOORTHOZ = 0x0400,
  RSG_NOOSNAP = 0x0800,
  RSG_NODDIST = 0x1000,
};

enum {
  INP_NNULL = RSG_NONULL,
  INP_NZERO = RSG_NOZERO,
  INP_NNEG = RSG_NONEG,
  INP_NLIM = RSG_NOLIM,
  INP_DASH = RSG_DASH,
  INP_NZCOORD = RSG_2D
};

enum SelectorType {
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

struct gds_binary {
  short clen;
  char *buf;
};

union gds_u_val {
  gds_real rreal;
  gds_real rpoint[3];
  short rint;
  GCHAR *rstring;
#if !defined(_WIN64) && !defined(_GC64)
  int32_t  rlname[2];
  int32_t  mnLongPtr;
#else
  int64_t     rlname[2];
  int64_t     mnLongPtr;
#endif

  int32_t     rlong;
  int64_t     mnInt64;
  struct gds_binary rbinary;
  unsigned char ihandle[8];
};

struct resbuf {
  struct resbuf *rbnext;
  short restype;
  union gds_u_val resval;
};

typedef struct resbuf *pResbuf;
typedef const struct resbuf *kpResbuf;

#pragma pack(pop)

#endif