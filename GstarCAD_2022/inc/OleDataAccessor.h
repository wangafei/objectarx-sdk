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

#ifndef _ODBDOLE2FRAME_INCLUDED_
#define _ODBDOLE2FRAME_INCLUDED_

#include "TD_PackPush.h"

class OdDbOle2Frame;

  /** Description:
      Was not accessible in DD1.12 (OdDbOle2FrameImpl::m_UnknownFromDWG)
  */

OdInt32 odbdOle2FrameUnknown0(const OdDbOle2Frame* pOle2Frame);

  /** Description:
      Stil unknown. OdDbOle2Frame::getUnknown1() in DD1.12
  */
OdUInt8 odbdOle2FrameUnknown1(const OdDbOle2Frame* pOle2Frame);

  /** Description:
      Stil unknown. OdDbOle2Frame::getUnknown2() in DD1.12
  */
OdUInt8 odbdOle2FrameUnknown2(const OdDbOle2Frame* pOle2Frame);

void odbdOle2FrameSetUnknown(OdDbOle2Frame* pOle2Frame, OdInt32 unk0, OdUInt8 unk1, OdUInt8 unk2);

  /** Description:
      OdDbOle2Frame::getPixelWidth() in DD1.12
  */
OdUInt16 odbdOle2FrameHimetricWidth(const OdDbOle2Frame* pOle2Frame);

  /** Description:
      OdDbOle2Frame::getPixelHeight() in DD1.12
  */
OdUInt16 odbdOle2FrameHimetricHeight(const OdDbOle2Frame* pOle2Frame);

  /** Description:
      OdDbOle2Frame::setPixelWidth/Height() in DD1.12
  */
void odbdOle2FrameSetHimetricSize(OdDbOle2Frame* pOle2Frame, OdUInt16 w, OdUInt16 h);

#include "TD_PackPop.h"

#endif // #ifndef _ODBDOLE2FRAME_INCLUDED_
