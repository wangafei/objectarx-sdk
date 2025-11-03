/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#if defined(__linux__)

#include "gsoft.h"
#if defined (GCDBCORE2D_API)
#define   GCDBCORE2D_PORT GSOFT_EXPORT
#define   GCDBCORE2D_DATA_PORT __declspec_dllexport
#else
#if defined (GCDBCORE2D_STATIC)
#define   GCDBCORE2D_PORT 
#define   GCDBCORE2D_DATA_PORT
#else
#define GCDBCORE2D_PORT
#define GCDBCORE2D_DATA_PORT __declspec_dllimport
#endif
#endif

#ifdef DBCONSTRAINTS_API
#  define DBCONSTRAINTS_PORT __declspec_dllexport
#else
#  define DBCONSTRAINTS_PORT __declspec_dllimport
#endif

#ifndef GCRX_DLL_DECL
#ifdef _GCRX_MODULE_
#  define GCRX_DLL_DECL __declspec_dllexport
#else
#  define GCRX_DLL_DECL __declspec_dllimport
#endif
#endif

#else

#if defined (GCDBCORE2D_API)
    #include "gsoft.h"
    #define   GCDBCORE2D_PORT GSOFT_EXPORT
    #define   GCDBCORE2D_DATA_PORT _declspec(dllexport)
#else
#if defined (GCDBCORE2D_STATIC)
    #define   GCDBCORE2D_PORT 
    #define   GCDBCORE2D_DATA_PORT
#else
    #define GCDBCORE2D_PORT
    #define GCDBCORE2D_DATA_PORT _declspec(dllimport)
#endif
#endif

#ifndef GCRX_DLL_DECL
#ifdef _GCRX_MODULE_
#  define GCRX_DLL_DECL __declspec(dllexport)
#else
#  define GCRX_DLL_DECL __declspec(dllimport)
#endif
#endif

#ifdef DBCONSTRAINTS_API
#  define DBCONSTRAINTS_PORT __declspec(dllexport)
#else
#  define DBCONSTRAINTS_PORT __declspec(dllimport)
#endif

#endif
