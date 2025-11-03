

#pragma once

#ifndef ZDHOSTABLEUI_H
#define ZDHOSTABLEUI_H
#include "zadesk.h"

#ifdef  ZDHOSTABLE_API
#define ZDHOSTABLE_PORT __declspec(dllexport)
#else
#define ZDHOSTABLE_PORT
#endif


#endif 
