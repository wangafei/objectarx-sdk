/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gdslib_h
#define _gdslib_h 1

#ifdef _WINDOWS
#define WIN 1
#endif

#ifdef WINVER
#define WIN 1
#endif

#ifdef _MSC_VER
#define MICROSOFT 1
#endif

#include "gds.h"
#include "gdscodes.h"
#pragma pack (push, 8)

#ifdef __cplusplus


GCBASE_PORT bool gcrxUnlockApplication(void* appId);
GCBASE_PORT bool gcrxApplicationIsLocked(const GCHAR* modulename);
GCBASE_PORT bool gcrxLockApplication(void* appId);

#endif 

#pragma pack (pop)

#endif 
