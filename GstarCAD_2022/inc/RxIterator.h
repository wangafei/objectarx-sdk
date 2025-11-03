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




#ifndef _ODRXITERATOR_H_
#define _ODRXITERATOR_H_

#include "RxObject.h"

#include "TD_PackPush.h"

/** Description
  This class is the abstract base class for OdDbDictionaryIterator and OdRxDictionaryIterator objects.

  Library:
  TD_Db
  
  {group:OdRx_Classes} 
*/
class FIRSTDLL_EXPORT OdRxIterator : public OdRxObject
{
public:

  OdRxIterator() {}

  ODRX_DECLARE_MEMBERS(OdRxIterator);
  
  /** Description:
    Returns true if and only if the traversal by this Iterator *object* is complete.
  */  
  virtual OdBool done() const = 0;

  /** Description:
    Sets this Iterator *object* to reference the entry following the current entry.

    Remarks:
    Returns true if and only if not at the end of the list.
  */
  virtual OdBool next() = 0;

  /** Description:
    Returns the RxObject pointed to by this Iterator *object*. 
  */
  virtual OdRxObject* object() const = 0;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdRxIterator object pointers.
*/
typedef OdSmartPtr<OdRxIterator> OdRxIteratorPtr;

#include "TD_PackPop.h"

#endif // _ODRXITERATOR_H_

