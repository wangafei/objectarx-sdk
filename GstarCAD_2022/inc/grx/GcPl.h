#ifndef GCPL_H
#define GCPL_H

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// Note: _ACPL_BUILD should be defined only when building the DLL.

#ifdef  _GCPL_BUILD
#  define   GCPL_PORT  __declspec(dllexport)
#else
#  define GCPL_PORT __declspec(dllimport)
#endif


#endif // ACPL_H
