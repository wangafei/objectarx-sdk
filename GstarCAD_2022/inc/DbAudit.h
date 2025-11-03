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




#ifndef _ODDB_AUDIT_INCLUDED_
#define _ODDB_AUDIT_INCLUDED_

#include "TD_PackPush.h"

#include "OdString.h"
#include "CmColor.h"
#include "OdAuditInfo.h"

class OdDbObject;
class OdDbObjectId;
class OdDbDatabase;
class OdDbHostAppServices;

TOOLKIT_EXPORT OdString odDbGetObjectName(const OdDbObject* pObj);
TOOLKIT_EXPORT OdString odDbGetObjectIdName(const OdDbObjectId& id);
TOOLKIT_EXPORT OdString odDbGetHandleName(const OdDbHandle& handle);
TOOLKIT_EXPORT OdString odDbGenerateName(const OdDbObjectId& id, OdDbHostAppServices* pHostApp = 0);
TOOLKIT_EXPORT OdString odDbGenerateName(OdUInt32 i, OdDbHostAppServices* pHostApp = 0);
TOOLKIT_EXPORT bool     odDbAuditColorIndex(OdInt16& colorIndex, OdDbAuditInfo* pAuditInfo, OdDbHostAppServices* pHostApp = 0);
TOOLKIT_EXPORT bool     odDbAuditColor(OdCmColor& color, OdDbAuditInfo* pAuditInfo, OdDbHostAppServices* pHostApp = 0);

/** Description:
  This class tracks audit information during a *database* audit.

  Library:
  TD_Db

  {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbAuditInfo : public OdAuditInfo
{
public:
  /** Description:
    Notification function called to print error information.
    Remarks:
    Prints log information about an error detected or fixed during an audit.

    Arguments:
    name(I) Type of erroneous data found.
    value (I) Value of the bad data.
    validation (I) Reason the data were bad.
    defaultValue (I) Default *value* to which the were set.

    Note:
    As implemented, this functions does nothing.
  */
  OdDbAuditInfo();
  ~OdDbAuditInfo();

  virtual void printError(
    const OdChar * name, 
    const OdChar * value, 
    const OdChar * validation = OD_T(""), 
    const OdChar * defaultValue = OD_T(""));

  void printError(const OdDbObject* pObj,
    const OdChar* value,
    const OdChar* validation,
    const OdChar* defaultValue);
  /**
    Arguments:
    pObject (I) Pointer to the object which generated the error.

    Remarks:
    odDbGetObjectName(pObject) is used to generate the *name*.
  */
  virtual void printError(
    const OdRxObject* pObject,
    const OdChar * value, 
    const OdChar * validation = OD_T(""), 
    const OdChar * defaultValue = OD_T(""));

  OdResult fetchObject(OdDbObjectId originalObjId,
    OdDbObjectId& newObjId,
    OdRxClass* pObjClass,
    bool uneraseIfPossible = false,
    bool createIfNotFound = true,
    bool externalDbOk = false);

  OdResult updateObject(OdDbHandle handle,
    bool setFileObjIsValid,
    bool setNewObjIsValid,
    bool setFileObjClass,
    bool setNewObjClass,
    bool setNewObjId,
    bool fileObjIsValid,
    bool newObjIsValid,
    OdRxClass* pFileObjClass,
    OdRxClass* pNewObjClass,
    OdDbObjectId newObjId);
};

#include "TD_PackPop.h"

#endif // _ODDB_AUDIT_INCLUDED_

