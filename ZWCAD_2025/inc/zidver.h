
#ifndef   _ZIDVER_H
#define   _ZIDVER_H

#include "zidrelver.h"

#if defined(_ZSOFT_CROSS_PLATFORM_)
#error Fabric code should not include zidver.h
#endif

#if defined(ZC_BLDENV)
    #include "_zidver.h"
#else

    #define ZCADV_BLDMAJOR  0
    #define ZCADV_BLDMINOR  0
    #define ZCADV_BLDBRANCH 0
    #define ZCADV_BLDSTREAM DevelopmentBranch
#endif

#define ZCADV_RCFILEVER3 ZCADV_BLDMAJOR
#define ZCADV_RCFILEVER4 ZCADV_BLDMINOR
#define ZCADV_RCFILEVER5 ZCADV_BLDBRANCH

#define ZCADV_RCFILEVERSTR ID2STR(ZCADV_RCFILEVER1) "." \
                ID2STR(ZCADV_RCFILEVER2) "." \
                ID2STR(ZCADV_RCFILEVER3) "." \
                ID2STR(ZCADV_RCFILEVER5) "." \
                ID2STR(ZCADV_RCFILEVER4)

#define ZCADV_PRODVERSION "R" ZCADV_RCFILEVERSTR

#if defined(_MSC_VER) || defined(UNICODE)

#define ZCADV_VERNUM  ZCRX_T(ID2STR(ZCADV_BLDSTREAM)) ZCRX_T(".") \
                      ZCRX_T(ID2STR(ZCADV_BLDMAJOR)) ZCRX_T(".") \
                      ZCRX_T(ID2STR(ZCADV_BLDBRANCH)) ZCRX_T(".") \
                      ZCRX_T(ID2STR(ZCADV_BLDMINOR))
#else

#define ZCADV_VERNUM ID2STR(ZCADV_BLDSTREAM) "." \
                     ID2STR(ZCADV_BLDMAJOR) "." \
                     ID2STR(ZCADV_BLDBRANCH) "." \
                     ID2STR(ZCADV_BLDMINOR)
#endif

#if defined(PRODUCTION)
#define ZCADV_VERFULL     ZCADV_VERNAME
#else
#define ZCADV_VERFULL     ZCADV_VERNUM
#endif

#define ZCADV_BLDVERSTR   ZCADV_VERNUM

#endif
