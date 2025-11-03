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




//   OdOle.h
//

#ifndef _ODOLEAUTO_H_
#define _ODOLEAUTO_H_

#include <wtypes.h>
#include "DbDatabase.h"
struct IUnknown;
struct IDispatch;

/** Description:
    This class maintains a link between an object and its respective COM wrapper.
    Library: TD_Db
    {group:Other_Classes}
*/
class OdOxOleLinkManager
{
public:
  /** Description:
    Returns the IUnknown of the COM wrapper for the specified *database* or *database* -resident object.
    Arguments:
    pObject (I) Pointer to the object.
    Remarks:
    Returns NULL if no wrapper is found.
  */
  virtual IUnknown* GetIUnknown(OdDbObject* pObject) = 0;

  /** Description:
    Sets the link between the specified *database* or *database* -resident object and the specified COM wrapper.
    Arguments:
    pObject (I) Pointer to the object.
    pIUnknown (I) Pointer to the COM wrapper.
    Remarks:
    If pIUnknown is NULL, the link is removed.
  */
  virtual bool SetIUnknown(OdDbObject* pObject, IUnknown* pIUnknown = 0) = 0;

  /**
    Arguments:
    pDb (I) Pointer to the *database*.
  */
  virtual IUnknown* GetIUnknown(OdDbDatabase * pDb) = 0;

  /**
    Arguments:
    pDb (I) Pointer to the *database*.
  */
  virtual bool SetIUnknown(OdDbDatabase * pDb, IUnknown* pIUnknown = 0) = 0;

  /** Description:
    Return the IDispatch of the document to which the specified *database* belongs.
    Arguments:
    pDb (I) Pointer to the database.
    Remarks:
    Returns NULL if the *database* does not belong to a document.
  */
  virtual IDispatch* GetDocIDispatch(OdDbDatabase * pDatabase) = 0;

  /** Description:
    Sets the link between the specified *database* and the specified *document* to which it belongs..
    Arguments:
    pDb (I) Pointer to the database.
    pIDispatch (I) Pointer to the IDispatch of the document..
    Remarks:
    If IDispatch is NULL, the link is removed.
  */
  virtual bool SetDocIDispatch(OdDbDatabase * pDatabase, IDispatch* pIDispatch = 0) = 0;
};

TOOLKIT_EXPORT OdOxOleLinkManager* OdOxGetOleLinkManager(void);

#endif // _ODOLEAUTO_H_


