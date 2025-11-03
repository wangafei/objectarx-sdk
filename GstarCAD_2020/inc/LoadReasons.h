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




// DynamicLinker.h: interface for the OdaDynamicLinkerI class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_ODAAPP_LOADREASONS_H_INCLUDED_)
#define _ODAAPP_LOADREASONS_H_INCLUDED_

/** Description:

    {group:TD_Namespaces}
*/
namespace OdaApp
{
  enum LoadReasons
  {
    kOnProxyDetection       = 0x01,
    kOnTeighaStartup        = 0x02,
    kOnAutoCADStartup       = 0x02,
    kOnCommandInvocation    = 0x04,
    kOnLoadRequest          = 0x08,
    kLoadDisabled           = 0x10,
    kTransparentlyLoadable  = 0x20,
    kOnIdleLoad             = 0x40
  };
};

#endif // !defined(_ODAAPP_LOADREASONS_H_INCLUDED_)

