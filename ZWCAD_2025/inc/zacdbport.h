#pragma once

#ifdef  ZCDB_API
    #define   ZCDB_PORT _declspec(dllexport)
#else
    #define   ZCDB_PORT
#endif
