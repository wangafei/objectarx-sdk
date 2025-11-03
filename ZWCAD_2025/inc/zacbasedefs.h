#pragma once

#ifndef _ZACBASEDEFS_H_H
#define _ZACBASEDEFS_H_H

#if defined(_MSC_VER)
    #ifdef ZCBASE_API
        #define ZCBASE_PORT _declspec(dllexport)
    #else
        #define ZCBASE_PORT
    #endif
#elif defined(__clang__)

    #define ZCBASE_PORT
#else
    #error Visual C++ or Clang compiler is required.
#endif

#endif