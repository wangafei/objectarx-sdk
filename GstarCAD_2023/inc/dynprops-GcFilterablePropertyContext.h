/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

typedef
#ifdef _GSOFT_WINDOWS_
__declspec(uuid("00852954-369B-45C8-A2B5-BA0F55E5F81F"))
#endif
enum GcFilterablePropertyContext
{
  gcQuickPropertiesContext = 0,
  gcTooltipContext = 1
} GcFilterablePropertyContext;