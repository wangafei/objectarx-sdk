/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _GCJS_H
#define   _GCJS_H

#ifdef  _GCJSCORESTUB
#define GCJSCORESTUB_PORT   __declspec(dllexport)
#else
#define GCJSCORESTUB_PORT   __declspec(dllimport)
#endif


typedef char* (*GcJsFunctionPtr)    (const char*);

#define GCJS_FUNC_INVOKEINDOC       0x00000001      
#define GCJS_FUNC_HANDLE_NULLDOC    0x00000002      


#define GCJSCORESTUB_DEFUN  "gcjsDefun"
typedef Gcad::ErrorStatus(*GCJSCORESTUB_DEFUN_PROC)(const TCHAR* name, GcJsFunctionPtr funcAddr, Gsoft::Int32 funcFlags);

extern "C" GCJSCORESTUB_PORT Gcad::ErrorStatus gcjsDefun(const TCHAR* name, GcJsFunctionPtr funcAddr, Gsoft::Int32 funcFlags = 0);

extern "C" GCJSCORESTUB_PORT Gcad::ErrorStatus gcjsInvokeAsync(const TCHAR* name,
  const TCHAR* jsonArgs);

extern "C" GCJSCORESTUB_PORT Gcad::ErrorStatus gcjsInvokeAsyncA(const char* name,
  const char* jsonArgs);
#endif 
