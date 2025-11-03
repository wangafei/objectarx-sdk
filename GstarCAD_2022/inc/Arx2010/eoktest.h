#pragma once

#include "acadstrc.h"
#include "acestext.h"
#include "acutasrt.h"
#include <tchar.h>

#ifdef NDEBUG

#define eOkTest(x) ((x) == eOk)
#define eOkCheck(x) (x)
#define eOkVerify(x) ((x) == eOk)

#else   // else not NDEBUG

// For use by eoktest.h only!
inline OdResult eOkCheck_imp(
    const OdChar *condition,
    const OdChar *fname,
    int         lineno,
    OdResult es)
{
    if (es != eOk) {
        gcutAssertMessage(condition, fname, lineno,
                          gcadErrorStatusText(es));
    }
    return es;
}

/// <summary>
/// Evaluates to true if value is eOk, otherwise evaluates to false.
/// </summary>
#define eOkTest(x) ((x) == eOk)

/// <summary>
/// Asserts if value is not eOk.  Evaluates to the value.
/// </summary>
#define eOkCheck(x) eOkCheck_imp(_T(# x), _T(__FILE__), __LINE__, (x))

/// <summary>
/// Asserts if value is not eOk.  Evaluates to true if value is eOk
/// otherwise evalutes to false.
/// </summary>
#define eOkVerify(x) (eOkCheck(x) == eOk)

#endif // NDEBUG
