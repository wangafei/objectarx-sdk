/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#ifndef  GCBASEDEFS_H
#define  GCBASEDEFS_H
#if defined(_MSC_VER)
#ifdef  GCBASE_API
#define GCBASE_PORT _declspec(dllexport)
#define GCBASE_STATIC_PORT
#else
#define GCBASE_PORT _declspec(dllimport)
#define GCBASE_STATIC_PORT
#endif 
#else
#ifdef  GCBASE_API
#define GCBASE_PORT __attribute__ ((__visibility__("default")))
#define GCBASE_STATIC_PORT
#else
#define GCBASE_PORT
#define GCBASE_STATIC_PORT
#endif 
#endif 

#endif 