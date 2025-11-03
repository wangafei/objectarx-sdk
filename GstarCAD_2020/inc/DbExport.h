/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////




/*  DbExport.h

*/
#ifndef _DB_EXPORT_DEFINED
#define _DB_EXPORT_DEFINED

#include "OdPlatformSettings.h"

#ifdef ODA_DB_EXPORTS
  #define TOOLKIT_EXPORT            OD_TOOLKIT_EXPORT
  #define TOOLKIT_EXPORT_GLOBAL     OD_DLL_EXPORT
  #define TOOLKIT_EXPORT_STATIC     OD_STATIC_EXPORT
#else
  #define TOOLKIT_EXPORT            OD_TOOLKIT_IMPORT
  #define TOOLKIT_EXPORT_GLOBAL     OD_DLL_IMPORT
  #define TOOLKIT_EXPORT_STATIC     OD_STATIC_IMPORT
#endif


#ifdef ODAFIRST_DLL_EXPORTS
  #define FIRSTDLL_EXPORT           OD_TOOLKIT_EXPORT
  #define FIRSTDLL_EXPORT_STATIC    OD_STATIC_EXPORT
#else
  #define FIRSTDLL_EXPORT           OD_TOOLKIT_IMPORT
  #define FIRSTDLL_EXPORT_STATIC    OD_STATIC_IMPORT
#endif

#ifdef GCED_EXPORTS
#define GCED_DLL_DECL OD_TOOLKIT_EXPORT
#else
#define GCED_DLL_DECL OD_TOOLKIT_IMPORT
#endif

#ifdef GCDB_EXPORTS
#define GCDB_DLL_DECL OD_TOOLKIT_EXPORT
#else
#define GCDB_DLL_DECL OD_TOOLKIT_IMPORT
#endif

#ifdef GCAP_EXPORTS
#define GCAP_DLL_DECL OD_TOOLKIT_EXPORT
#else
#define GCAP_DLL_DECL OD_TOOLKIT_IMPORT
#endif

#ifdef GCUT_EXPORTS
#define GCUT_DLL_DECL OD_TOOLKIT_EXPORT
#else
#define GCUT_DLL_DECL OD_TOOLKIT_IMPORT
#endif

#ifdef GCAD_EXPORTS
#define GCAD_DLL_DECL OD_TOOLKIT_EXPORT
#else
#define GCAD_DLL_DECL OD_TOOLKIT_IMPORT
#endif

#ifdef  _GDUI_BUILD
#define GCUI_DLL_DECL  OD_TOOLKIT_EXPORT
#else
#define GCUI_DLL_DECL  OD_TOOLKIT_EXPORT
#endif

//////////////////////////////////////////////////////////////////////////

#endif  /* _DB_EXPORT_DEFINED */



