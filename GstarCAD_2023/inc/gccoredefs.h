/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#ifndef GCCOREDEFS_H
#define GCCOREDEFS_H

#ifdef _MSC_VER

#ifndef GCCORE_PORT
#ifdef GCCORE_API
  #include "gsoft.h"
  #define GCCORE_PORT GSOFT_EXPORT
  #define GCCORE_DATA_PORT _declspec(dllexport)
  #define GCCORE_STATIC_DATA_PORT _declspec(dllexport) static
#else
  #define GCCORE_PORT
  #define GCCORE_DATA_PORT _declspec(dllimport)
  #define GCCORE_STATIC_DATA_PORT _declspec(dllimport) static
#endif
#endif

#else

#if defined(__linux__)

#ifndef GCCORE_PORT
#ifdef GCCORE_API
#include "gsoft.h"
#define GCCORE_PORT         GSOFT_EXPORT
#define GCCORE_DATA_PORT    __attribute__ ((__visibility__("default")))
#define GCCORE_STATIC_DATA_PORT  __attribute__ ((__visibility__("default"))) static
#else
#define GCCORE_PORT
#define GCCORE_DATA_PORT
#define GCCORE_STATIC_DATA_PORT static
#endif
#endif

#else

#define GCCORE_PORT
#define GCCORE_DATA_PORT
#define GCCORE_STATIC_DATA_PORT static

#endif

#endif


#if defined(__linux__)

#ifdef GCGS_API
#define GCGS_PORT         __attribute__ ((__visibility__("default")))
#define GCGS_STATIC_PORT  __attribute__ ((__visibility__("default"))) static
#else
#define GCGS_PORT
#define GCGS_STATIC_PORT  static
#endif

#else

#ifdef GCGS_API
#define GCGS_PORT _declspec(dllexport)
#define GCGS_STATIC_PORT _declspec(dllexport) static
#else
#define GCGS_PORT _declspec(dllimport)
#define GCGS_STATIC_PORT _declspec(dllimport) static
#endif

#endif 

#endif
