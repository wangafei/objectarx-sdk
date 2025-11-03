#pragma once
#include "../OdaCommon.h"

typedef OdChar GCHAR;

#ifndef GD_UNICODE
#define GD_UNICODE
#endif

#ifndef _GCRX_T
#define _GCRX_T(x) L ## x
#define GCRX_T(x) _GCRX_T(x)
#endif
