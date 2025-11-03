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




#ifndef __ODDRAWABLEIMPL_H__
#define __ODDRAWABLEIMPL_H__

class OdGsNode;
class OdGiViewportDraw;
class OdDbStub;

#include "../Gs/GsModel.h"

/** Description:

    {group:OdGi_Classes} 
*/
template<class T = OdGiDrawable>
class OdGiDrawableImpl : public T
{
  OdGsNode* m_pGsNode;
public:
  OdGiDrawableImpl() : m_pGsNode(0) {}
  
  ~OdGiDrawableImpl() { if(m_pGsNode) m_pGsNode->setDrawableNull(); }

  void setGsNode(OdGsNode* pGsNode) { m_pGsNode = pGsNode; }
  OdGsNode* gsNode() const { return m_pGsNode; }

  void subViewportDraw(OdGiViewportDraw* ) {}
  
  OdBool isPersistent() const { return kFalse; }

  OdDbObjectId id() const { return OdDbObjectId(0); }
};

#endif // __ODDRAWABLEIMPL_H__

