/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#ifdef  GCDB_API
#include "gsoft.h"
#if defined(__linux__)
  #define   GCDB_PORT GSOFT_EXPORT
  #define   GCDB_PORT_GLOBAL     __attribute__ ((__visibility__("default"))) 
  #define   GCDB_PORT_STATIC
#else
  #define   GCDB_PORT GSOFT_EXPORT
  #define   GCDB_PORT_GLOBAL     _declspec(dllexport)
  #define   GCDB_PORT_STATIC
#endif
#else
#if defined(__linux__)
  #define   GCDB_PORT
  #define   GCDB_PORT_GLOBAL
  #define   GCDB_PORT_STATIC
#else
  #define   GCDB_PORT
  #define   GCDB_PORT_GLOBAL     _declspec(dllimport)
  #define   GCDB_PORT_STATIC
#endif
#endif

#if defined(__linux__)
#ifdef DYNBLOCKS_API
#define DYNBLOCKS_PORT         __attribute__ ((__visibility__("default")))
#else
#define DYNBLOCKS_PORT
#endif

#ifdef DBPOINTCLOUDOBJ_API
#define DBPOINTCLOUDOBJ_PORT   __attribute__ ((__visibility__("default")))
#else
#define DBPOINTCLOUDOBJ_PORT
#endif

#else
#ifdef DYNBLOCKS_API
  #define DYNBLOCKS_PORT         _declspec(dllexport)
#else
  #define DYNBLOCKS_PORT
#endif

#ifdef DBPOINTCLOUDOBJ_API
  #define DBPOINTCLOUDOBJ_PORT   _declspec(dllexport)
#else
  #define DBPOINTCLOUDOBJ_PORT   _declspec(dllimport)
#endif
#endif
