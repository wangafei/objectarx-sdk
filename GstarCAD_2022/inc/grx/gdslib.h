#pragma once

#ifndef _INC_STDLIB
	#include <stdlib.h>
#endif

#ifdef _WINDOWS
#define WIN 1
#endif

#ifdef WINVER
#define WIN 1
#endif

#ifdef _MSC_VER
#define MICROSOFT 1
#endif

#include "gcadstd.h"
#include "gds.h"
#include "gdscodes.h"
#include "gdsmigr.h"

#pragma pack (push, 8)

#ifdef __cplusplus

bool gcrxUnlockApplication(void* appId);
bool gcrxApplicationIsLocked(const GCHAR* modulename);
bool gcrxLockApplication(void* appId);

#endif

#pragma pack (pop)
