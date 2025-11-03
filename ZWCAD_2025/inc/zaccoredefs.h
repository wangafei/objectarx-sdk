#pragma once

#ifndef _ZACCOREDEFS_H_
#define _ZACCOREDEFS_H_

#if defined(_MSC_VER) || defined(_ZSOFT_MAC_)
#ifndef ZCCORE_PORT
#ifdef ZCCORE_API
    #include "zadesk.h"
    #define ZCCORE_PORT ZSOFT_EXPORT
    #define ZCCORE_DATA_PORT _declspec(dllexport) 
    #define ZCCORE_STATIC_DATA_PORT _declspec(dllexport) static
#else
    #define ZCCORE_PORT
    #define ZCCORE_DATA_PORT _declspec(dllimport) 
    #define ZCCORE_STATIC_DATA_PORT _declspec(dllimport) static
#endif
#endif
#else
    #define ZCCORE_PORT
    #define ZCCORE_DATA_PORT
    #define ZCCORE_STATIC_DATA_PORT static
#endif

#endif
