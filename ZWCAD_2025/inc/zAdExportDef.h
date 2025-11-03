

#pragma once

#ifdef  _ZDAF_BUILD
#  define   ZDAF_PORT  __declspec(dllexport)
#else
#  define   ZDAF_PORT  __declspec(dllimport)
#endif