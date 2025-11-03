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

#ifndef _RXOVERRULE_H
#define _RXOVERRULE_H

#include "RxObject.h"

#include "TD_PackPush.h"
class OdRxOverruleIterator;

/** Description:
    
    Library: TD_Db
    {group:OdRx_Classes} 
*/
class FIRSTDLL_EXPORT OdRxOverrule : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdRxOverrule);
  virtual ~OdRxOverrule();
  virtual bool isApplicable(const OdRxObject* pOverruledSubject) const = 0;
  static OdResult addOverrule(OdRxClass* pClass, OdRxOverrule* pOverrule, bool bAddAtLast = false);
  static OdResult removeOverrule(OdRxClass* pClass, OdRxOverrule* pOverrule);
  static void setIsOverruling(bool bIsOverruling);
  static bool isOverruling()
  {
    return s_bIsOverruling;
  }
  static bool hasOverrule(const OdRxObject* pSubject, OdRxClass* pOverruleClass);
private:
  OdRxOverruleIterator* m_pIter;
  FIRSTDLL_EXPORT_STATIC static bool s_bIsOverruling;
  friend class OdRxOverruleInternals;
};

#include "TD_PackPop.h"
#endif  // _RXOVERRULE_H
