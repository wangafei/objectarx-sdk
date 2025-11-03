/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#define GD_UNICODE 1

#if defined(__cplusplus) && defined(_MSC_VER) && !defined(_NATIVE_WCHAR_T_DEFINED)
#error Please use native wchar_t type (/Zc:wchar_t)
#endif

typedef wchar_t GCHAR;

#define _GCRX_T(x)      L ## x
#define GCRX_T(x)      _GCRX_T(x)
