/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gsoft.h"
#include "gcadstrc.h"
#include "gcestext.h"
#include "gcutasrt.h"

#ifdef NDEBUG

#define eOkTest(x) ((x) == Gcad::eOk)
#define eOkCheck(x) (x)
#define eOkVerify(x) ((x) == Gcad::eOk)

#else   

inline Gcad::ErrorStatus eOkCheck_imp(
  const GCHAR *condition,
  const GCHAR *fname,
  int         lineno,
  Gcad::ErrorStatus es)
{
  if (es != Gcad::eOk) {
    gcutAssertMessage(condition, fname, lineno,
      gcadErrorStatusText(es));
  }
  return es;
}

#define eOkTest(x) ((x) == Gcad::eOk)

#define eOkCheck(x) eOkCheck_imp(GCRX_T(# x), GCRX_T(__FILE__), __LINE__, (x))

#define eOkVerify(x) (eOkCheck(x) == Gcad::eOk)

#endif 