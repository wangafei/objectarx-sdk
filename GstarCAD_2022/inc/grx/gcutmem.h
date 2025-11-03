#pragma once

#include "../OdAllocX.h"
#pragma comment(lib, "TD_Alloc.lib")

#include "gcadstrc.h" 
#include "gchar.h" 

#pragma pack (push, 8)

#define gcutNewBuffer odutNewBuffer
#define gcutNewString odutNewString
#define gcutUpdString odutUpdString
#define gcutDelBuffer odutDelBuffer
#define gcutDelString odutDelString

#pragma pack (pop)