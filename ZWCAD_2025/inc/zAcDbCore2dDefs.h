#pragma once

#if defined (ZCDBCORE2D_API)
    #include "zadesk.h"
    #define   ZCDBCORE2D_PORT _declspec(dllexport)
    #define   ZCDBCORE2D_DATA_PORT _declspec(dllexport)
#else
#if defined (ZCDBCORE2D_STATIC)
    #define   ZCDBCORE2D_PORT
    #define   ZCDBCORE2D_DATA_PORT
#else
    #define ZCDBCORE2D_PORT
    #define ZCDBCORE2D_DATA_PORT _declspec(dllimport)
#endif
#endif
