/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEDLL_H
#define GC_GEDLL_H

#include "gsoft.h"
#if defined(_MSC_VER)
#pragma warning(disable:4251)
#pragma warning(disable:4273)
#pragma warning(disable:4275)
#endif

#ifdef  GCGE_INTERNAL
#define GE_DLLEXPIMPORT GSOFT_EXPORT
#define GE_DLLDATAEXIMP __declspec(dllexport)
#else
#define GE_DLLEXPIMPORT
#define GE_DLLDATAEXIMP __declspec(dllimport)
#endif

#ifdef  GCGX_INTERNAL
#define GX_DLLEXPIMPORT __declspec(dllexport)
#else
#define GX_DLLEXPIMPORT
#endif


#endif 