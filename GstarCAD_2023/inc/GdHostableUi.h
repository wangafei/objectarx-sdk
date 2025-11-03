/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#ifndef GDHOSTABLEUI_H
#define GDHOSTABLEUI_H
#include "gsoft.h"

#ifdef  GDHOSTABLE_API
#define GDHOSTABLE_PORT __declspec(dllexport)
#else
#define GDHOSTABLE_PORT
#endif


#endif 