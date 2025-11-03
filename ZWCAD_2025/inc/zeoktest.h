
#pragma once

#include "zadesk.h"
#include "zacadstrc.h"
#include "zacestext.h"
#include "zacutasrt.h"

#ifdef NDEBUG


#define eOkTest(x) ((x) == Zcad::eOk)
#define eOkCheck(x) (x)
#define eOkVerify(x) ((x) == Zcad::eOk)


#else


inline Zcad::ErrorStatus eOkCheck_imp(
    const ZTCHAR *condition,
    const ZTCHAR *fname,
    int         lineno,
    Zcad::ErrorStatus es)
{
    if (es != Zcad::eOk) {
        zcutAssertMessage(condition, fname, lineno,
                          zcadErrorStatusText(es));
    }
    return es;
}

#define eOkTest(x) ((x) == Zcad::eOk)

#define eOkCheck(x) eOkCheck_imp(ZCRX_T(# x), ZCRX_T(__FILE__), __LINE__, (x))

#define eOkVerify(x) (eOkCheck(x) == Zcad::eOk)


#endif //NDEBUG

