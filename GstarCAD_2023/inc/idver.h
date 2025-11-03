/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _IDVER_H
#define   _IDVER_H

#include "id.h"

#ifndef GC_BLDENV
#define GCADV_BLDMAJOR  0
#define GCADV_BLDMINOR  0
#define GCADV_BLDBRANCH 0
#define GCADV_BLDSTREAM O
#else
#include "_idver.h"
#endif

#define VALUE2STR(x) #x
#define ID2STR(a) ID2STR__1(a)
#define ID2STR__1(a) VALUE2STR(a)

#define GCADV_RCFILEVER1 GCADV_RELMAJOR
#define GCADV_RCFILEVER2 GCADV_RELMINOR
#define GCADV_RCFILEVER3 GCADV_BLDMAJOR
#define GCADV_RCFILEVER4 GCADV_BLDMINOR
#define GCADV_RCFILEVER5 GCADV_BLDBRANCH

#define GCADV_RCFILEVER1_CORRECTION (6 + GCADV_RCFILEVER1)

#define GCADV_RCFILEVERSTR ID2STR(GCADV_RCFILEVER1) "." \
                ID2STR(GCADV_RCFILEVER2) "." \
                ID2STR(GCADV_RCFILEVER3) "." \
                ID2STR(GCADV_RCFILEVER5) "." \
                ID2STR(GCADV_RCFILEVER4)

#define GCADV_PRODVERSION "R" GCADV_RCFILEVERSTR

#if defined(_MSC_VER) || defined(UNICODE)
#define GCADV_VERNUM  GCRX_T(ID2STR(GCADV_BLDSTREAM)) GCRX_T(".") \
                      GCRX_T(ID2STR(GCADV_BLDMAJOR)) GCRX_T(".") \
                      GCRX_T(ID2STR(GCADV_BLDBRANCH)) GCRX_T(".") \
                      GCRX_T(ID2STR(GCADV_BLDMINOR))
#else
#define GCADV_VERNUM ID2STR(GCADV_BLDSTREAM) "." \
                     ID2STR(GCADV_BLDMAJOR) "." \
                     ID2STR(GCADV_BLDBRANCH) "." \
                     ID2STR(GCADV_BLDMINOR)
#endif

#if defined(_MSC_VER) || defined(UNICODE)
#define GCADV_VERNAME GCRX_T(ID2STR(GCADV_RELMAJOR)) GCRX_T(".") \
                      GCRX_T(ID2STR(GCADV_RELMINOR))
#else
#define GCADV_VERNAME ID2STR(GCADV_RELMAJOR) "." \
                      ID2STR(GCADV_RELMINOR)
#endif

#if defined(PRODUCTION)
#define GCADV_VERFULL     GCADV_VERNAME
#else
#define GCADV_VERFULL     GCADV_VERNUM
#endif

#define GCADV_BLDVERSTR   GCADV_VERNUM

#define GCAD_COPYRIGHT    ""
#define GCAD_COPYRIGHT_YEAR   "2023"

#define GCAD_TLBVERSION_MAJOR   1
#define GCAD_TLBVERSION_MINOR   0
#define GCAD_TLBVERSION         GCAD_TLBVERSION_MAJOR.GCAD_TLBVERSION_MINOR

#ifdef _MSC_VER
#define GCAD_TLBVERSIONSTR      GCRX_T(ID2STR(GCAD_TLBVERSION_MAJOR)) GCRX_T(".") \
                                GCRX_T(ID2STR(GCAD_TLBVERSION_MINOR))
#else
#define GCAD_TLBVERSIONSTR      ID2STR(GCAD_TLBVERSION_MAJOR) "." \
                                ID2STR(GCAD_TLBVERSION_MINOR)
#endif

#define GCDB_TLBVERSION_MAJOR   1
#define GCDB_TLBVERSION_MINOR   0
#define GCDB_TLBVERSION         GCDB_TLBVERSION_MAJOR.GCDB_TLBVERSION_MINOR

#ifdef _MSC_VER
#define GCDB_TLBVERSIONSTR      GCRX_T(ID2STR(GCDB_TLBVERSION_MAJOR)) GCRX_T(".") \
                                GCRX_T(ID2STR(GCDB_TLBVERSION_MINOR))
#else
#define GCDB_TLBVERSIONSTR      ID2STR(GCDB_TLBVERSION_MAJOR) "." \
                                ID2STR(GCDB_TLBVERSION_MINOR)
#endif

#endif
