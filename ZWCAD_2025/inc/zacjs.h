#ifndef   _ZACJS_H
#define   _ZACJS_H

#ifdef  _ZCJSCORESTUB
    #define ZCJSCORESTUB_PORT   __declspec(dllexport)
#else
    #define ZCJSCORESTUB_PORT   __declspec(dllimport)
#endif

typedef char* (*ZcJsFunctionPtr)    (const char*);

#define ZCJS_FUNC_INVOKEINDOC       0x00000001
#define ZCJS_FUNC_HANDLE_NULLDOC    0x00000002

#define ZCJSCORESTUB_DEFUN  "zcjsDefun"
typedef Zcad::ErrorStatus (*ZCJSCORESTUB_DEFUN_PROC)(const TCHAR* name, ZcJsFunctionPtr funcAddr, ZSoft::Int32 funcFlags);

extern "C" ZCJSCORESTUB_PORT Zcad::ErrorStatus zcjsDefun    (const TCHAR* name, ZcJsFunctionPtr funcAddr, ZSoft::Int32 funcFlags = 0);

extern "C" ZCJSCORESTUB_PORT Zcad::ErrorStatus zcjsInvokeAsync  (const TCHAR* name,
                                                                 const TCHAR* jsonArgs);

extern "C" ZCJSCORESTUB_PORT Zcad::ErrorStatus zcjsInvokeAsyncA (const char* name,
                                                                 const char* jsonArgs);
#endif
