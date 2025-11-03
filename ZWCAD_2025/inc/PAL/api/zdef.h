
#pragma once

#ifndef ZCPAL_DEF_H
#define ZCPAL_DEF_H

#if defined(_MSC_VER)
    #ifdef  ZCPAL_API
        #define   ZCPAL_PORT _declspec(dllexport)
    #else

        #define   ZCPAL_PORT
        #ifndef ZCFABRIC_WINRT
            #pragma comment(lib, "ZwPAL.lib")
        #endif
    #endif
#elif defined(__clang__)
    #ifdef  ZCPAL_API
        #define   ZCPAL_PORT
    #else
        #define   ZCPAL_PORT
        #pragma comment(lib, "ZwPAL.lib")
    #endif
#else
    #error Visual C++ or Clang compiler is required.
#endif

#if defined(ZCPAL_API) || !defined(_ZSOFT_CROSS_PLATFORM_) || defined(ZCPAL_TEST)
#define ZC_NON_CROSS_PLATFORM_API
#endif

#endif
