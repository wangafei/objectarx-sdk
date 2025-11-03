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


#ifndef _OdErrorContextWithId_h_Included_
#define _OdErrorContextWithId_h_Included_

#include "OdErrorContext.h"

/** Description:
    This class implements an OdErrorContext objects with the handles and Object IDs
    of the objects related to the errors.
    
    Library: TD_Root
    {group:Error_Classes} 
*/
class OdErrorContextWithId : public OdErrorContext
{
  OdDbStub*   m_id;
  OdDbHandle  m_handle;
  OdResult    m_res;
protected:
  OdErrorContextWithId() {}
public:
  /** Description:
    Initializes this ErrorContext object from the specified parameters.
    Arguments:
    code (I) OdResult *code*.
    objectId (I) Object ID of the object with the error.
  */
  OdSmartPtr<OdErrorContext> init(OdResult code, const OdDbObjectId& objectId)
  {
    ODA_ASSERT_ONCE(   code == eOk
                    || code == eDuplicateRecordName); // is used in reading DXF vAC12 or earlier
    m_id = objectId;
    m_handle = objectId.getHandle();
    m_res = code;
    return this;
  }
  /**
    Remarks:
    The default implementation of this function returns a string in the following format:
                
                    <Message> object: <Handle>
  */
  OdString description() const
  {
    OdString s = odSystemServices()->formatMessage((OdMessage)m_res);
    s += OD_T(" object: ");
    s += odDbGetHandleName(m_handle);
    return s;
  }
  OdResult code() const { return m_res; }

  /** Description:
    Returns the *handle* associated with this ErrorContext object.
    
    Note:
    The exception handler is responsible for assuring that
    handle() is valid at the time of handling the exception.
  */
  OdDbHandle handle() const { return m_handle; }
  
  /** Description:
    Returns the Object ID associated with this ErrorContext object.
    
    Note:
    The exception handler is responsible for assuring that
    id() is valid at the time of handling the exception.
  */
  OdDbObjectId id() const { return m_id; }
};

#endif
