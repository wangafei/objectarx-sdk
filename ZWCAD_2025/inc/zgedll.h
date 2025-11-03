
#ifndef ZC_GEDLL_H
#define ZC_GEDLL_H

#include "zadesk.h"
#if defined(_MSC_VER)
#pragma warning(disable:4251)
#pragma warning(disable:4273)
#pragma warning(disable:4275)
#endif

#ifdef  ZCGE_INTERNAL
#define GE_DLLEXPIMPORT __declspec(dllexport)
#define GE_DLLDATAEXIMP __declspec(dllexport)
#else

#define GE_DLLEXPIMPORT

#define GE_DLLDATAEXIMP __declspec(dllimport)
#endif

#ifdef  ZCGX_INTERNAL
#define GX_DLLEXPIMPORT __declspec(dllexport)
#else

#define GX_DLLEXPIMPORT
#endif

#endif
