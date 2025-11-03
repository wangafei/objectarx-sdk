
#ifndef _ZADUI_PORT_H_H
#define _ZADUI_PORT_H_H
#pragma once


//NPD_ZDUI
#ifdef  _ZDUI_BUILD
#  define   ZDUI_PORT  __declspec(dllexport)
#else
#  define   ZDUI_PORT  
#endif


#ifdef ZSOFT_NO_VTABLE
#define ZDUI_NO_VTABLE ZSOFT_NO_VTABLE
#else
#ifdef _MSC_VER
#define ZDUI_NO_VTABLE __declspec(novtable)
#else
#define ZDUI_NO_VTABLE
#endif 
#endif 



#endif //_ZADUI_PORT_H_H
