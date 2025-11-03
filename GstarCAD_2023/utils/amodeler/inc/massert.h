/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_MASSERT_H
#define GMODELER_INC_MASSERT_H

#if defined(WIN32) || defined(WIN64)
#include <tchar.h>
#endif

GMODELER_NAMESPACE_BEGIN

#ifdef _DEBUG

#define MASSERT(x) GMODELER_NAMESPACE::assertFunction(x, _T(__FILE__), __LINE__, _T(#x))
#define FAIL       GMODELER_NAMESPACE::assertFunction(0, _T(__FILE__), __LINE__, _T("FAIL"))

#else

#define MASSERT(x)
#define FAIL
#endif

DllImpExp extern void assertFunction(int ex, const wchar_t* file, int line, const wchar_t* str = 0);

GMODELER_NAMESPACE_END
#endif
