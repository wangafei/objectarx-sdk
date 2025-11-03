#pragma once
#include "../DbExport.h"

#ifdef  _ADAF_BUILD
#define ADAF_PORT  __declspec(dllexport)
#else
#define ADAF_PORT  __declspec(dllimport)
#endif
