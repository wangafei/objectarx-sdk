/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once


#ifdef  _GDUI_BUILD
#  define   GDUI_PORT  __declspec(dllexport)
#else
#  define   GDUI_PORT
#endif

#ifdef GSOFT_NO_VTABLE
#define GDUI_NO_VTABLE GSOFT_NO_VTABLE
#else
#ifdef _MSC_VER
#define GDUI_NO_VTABLE __declspec(novtable)
#else
#define GDUI_NO_VTABLE
#endif 
#endif 