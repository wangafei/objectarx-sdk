/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#ifndef GCPAL_DEF_H
#define GCPAL_DEF_H

#if defined(_MSC_VER) 
    #ifdef  GCPAL_API
        #define   GCPAL_PORT _declspec(dllexport)
    #else
        #define   GCPAL_PORT
        #ifndef GCPAL_SUPPRESS_LIB_DIRECTIVE
        #ifndef _GSOFT_CROSS_PLATFORM_
        #endif
        #endif
    #endif
#elif defined(__clang__) || defined(__linux__)
  #define   GCPAL_PORT __attribute__ ((__visibility__("default")))
#else
    #error Visual C++ or Clang compiler is required.
#endif

#if defined(GCPAL_API) || !defined(_GSOFT_CROSS_PLATFORM_) || defined(GCPAL_TEST)
#define GC_NON_CROSS_PLATFORM_API
#endif

#endif