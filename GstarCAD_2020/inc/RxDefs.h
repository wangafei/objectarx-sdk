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




// ODA typedefs
#ifndef _RX_DEFS_
#define _RX_DEFS_

/** Description:

    {group:TD_Namespaces}
*/
namespace OdRx
{
  enum DictIterType
  {
    kDictSorted = 0,
    kDictCollated,
    kDictReversed
  };
  
  enum AppMsgCode
  {
    kNullMsg         = 0,
    kInitAppMsg      = 1,
    kUnloadAppMsg    = 2,
    kLoadDwgMsg      = 3,
    kUnloadDwgMsg    = 4,
    kInvkSubrMsg     = 5,
    kCfgMsg          = 6,
    kEndMsg          = 7,
    kQuitMsg         = 8,
    kSaveMsg         = 9,
    kDependencyMsg   = 10,
    kNoDependencyMsg = 11,
    kOleUnloadAppMsg = 12,
    kPreQuitMsg      = 13,
    kInitDialogMsg   = 14,
    kEndDialogMsg    = 15,
	kSuspendMsg      = 16,
	kInitTabGroupMsg = 17,
	kEndTabGroupMsg  = 18
  }; 
  
  enum AppRetCode
  {
    kRetOK = 0,
    kRetError = 3
  };
}

#ifndef kLoadADSMsg
#define kLoadADSMsg kLoadDwgMsg
#define kUnloadADSMsg kUnloadDwgMsg
#endif

class OdRxClass;
typedef void (*AppNameChangeFuncPtr)(const OdRxClass* classObj, char*& newAppName, int saveVer);

#endif // _RX_DEFS_

