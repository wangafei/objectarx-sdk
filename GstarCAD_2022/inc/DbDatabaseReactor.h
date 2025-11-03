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




#ifndef _ODDBDATABASEREACTOR_INCLUDED_
#define _ODDBDATABASEREACTOR_INCLUDED_

#include "TD_PackPush.h"

#include "RxObject.h"
#include "IdArrays.h"

/** Description:
    This class is the base class for custom classes that receive notification
    of OdDbDatabase events.
    
    Remarks:
    Events consist of the addition, modification, or deletion of objects 
    from an OdDbDatabase instance.
    
    Note:
    The default implementations of all methods in this class do nothing.

    Library:
    TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDatabaseReactor : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbDatabaseReactor);
  
  OdDbDatabaseReactor() {}
  
  /** Description:
    Notification function called whenever an OdDbObject has been appended to an OdDbDatabase.
    
    Arguments:
    pDb (I) Pointer to the *database* being *modified*.
    pObject (I) Pointer to the object being appended.
    
    Remarks:
    This function is called after the operation.
  */
  virtual void objectAppended(
    const OdDbDatabase* pDb, 
    const OdDbObject* pObject);

  
  /** Description:
    Notification function called whenever an OdDbObject has been unappended from an OdDbDatabase by an Undo operation.
    
    Arguments:
    pDb (I) Pointer to the *database* being *modified*.
    pObject (I) Pointer to the object being unappended.

    Remarks:
    This function is called after the operation.
  */
  virtual void objectUnAppended(
    const OdDbDatabase* pDb, 
    const OdDbObject* pObject);

  
  /** Description:
    Notification function called whenever an OdDbObject has been reappended to an OdDbDatabase by a Redo operation.
    
    Arguments:
    pDb (I) Pointer to the *database* being *modified*.
    pObject (I) Pointer to the object being reappended.

    Remarks:
    This function is called after the operation.
  */
  virtual void objectReAppended(
    const OdDbDatabase* pDb, 
    const OdDbObject* pObject);

  
  /** Description:
    Notification function called whenever an OdDbObject is about to be *modified*.
    
    Arguments:
    pDb (I) Pointer to the *database* being *modified*.
    pObject (I) Pointer to the object being *modified*.
    
    Remarks:
    This function is called before the operations.
    
    See Also:
    objectModified
  */
  virtual void objectOpenedForModify(
    const OdDbDatabase* pDb, 
    const OdDbObject* pObject);

  
  /** Description:
    Notification function called whenever an OdDbObject has been *modified*.
    
    Arguments:
    pDb (I) Pointer to the *database* being *modified*.
    pObject (I) Pointer to the object being *modified*.
    
    Remarks:
    This function is called after the operations.

    See Also:
    objectOpenedForModify
  */
  virtual void objectModified(
    const OdDbDatabase* pDb, 
    const OdDbObject* pObject);
    
  
  /** Description:
    Notification function called whenever an OdDbObject has been *erased* or unerased.
    
    Arguments:
    pDb (I) Pointer to the *database* being *modified*.
    pObject (I) Pointer to the object being *modified*.
    erased (I) True if and only if the object is being *erased*.
    
    Remarks:
    This function is called after the operation.
  */
  virtual void objectErased(
    const OdDbDatabase* pDb, 
    const OdDbObject* pObject, 
    OdBool erased = kTrue);

  /** Description:
    Notification function called whenever a *database* -resident system variable is about to change.
    
    Arguments:
    pDb (I) Pointer to the *database* being *modified*.
    name (I) Name of the system variable being *modified*.
    
    Remarks:
    This function is called before the operation.
    
    See Also:
    headerSysVarChanged

	Gcad(Modify):const OdString&->const OdChar*
  */
  virtual void headerSysVarWillChange(
    const OdDbDatabase* pDb, 
    const OdChar* name);
/** { Secret } */
#define RO_VAR_DEF(type, name, d1, d2, r1, r2)
/** { Secret } */
#define RO_VAR_DEF_H(type, name, d1, d2, r1, r2)
/** { Secret } */
#define VAR_DEF(type, name, d1, d2, r1, r2)\
  /** Description: Notification function called whenever the ##NAME system variable is about to change. \
    Arguments: pDb (I) Pointer to the *database* being *modified*. \
    Remarks: This function is called before the operation. \
    Remarks: ##remarks \
    Notes: ##notes \
    See Also: ##see_also \
  */\
  virtual void headerSysVar_##name##_WillChange(const OdDbDatabase* pDb);

#include "SysVarDefs.h"
#undef VAR_DEF
#undef RO_VAR_DEF
#undef RO_VAR_DEF_H

/** { Secret } */
#define VAR_DEF(type, name, dxf, d1, d2, r1, r2)\
  /** Description: Notification function called whenever the DIM##NAME system variable is about to change. \
    Arguments: pDb (I) Pointer to the *database* being *modified*. \
    Remarks: This function is called before the operation. \
    Remarks: ##remarks \
    Notes: ##notes \
    See Also: ##see_also \
  */ \
  virtual void headerSysVar_dim##name##_WillChange(const OdDbDatabase* pDb);

#include "DimVarDefs.h"
#undef VAR_DEF


  /** Description:
    Notification function called whenever a *database* -resident system variable has changed.
    
    Arguments:
    pDb (I) Pointer to the *database* being *modified*.
    name (I) Name of the system variable being *modified*.
    
    Remarks:
    This function is called after the operation.
    
    See Also:
    headerSysVarWillChange

	Gcad(Modify):const OdString&->const OdChar*
	//bool bSuccess
  */
  virtual void headerSysVarChanged(
    const OdDbDatabase* pDb, 
    const OdChar* name,
    OdBool bSuccess);

/** { Secret } */
#define VAR_DEF(type, name, d1, d2, r1, r2)\
  /** Description: Notification function called whenever the ##NAME system variable has been changed. \
    Arguments: pDb (I) Pointer to the *database* being *modified*. \
    Remarks: This function is called after the operation. \
    Remarks: ##remarks \
    Notes: ##notes \
    See Also: ##see_also \
  */ \
  virtual void headerSysVar_##name##_Changed(const OdDbDatabase* pDb);

#include "SysVarDefs.h"
#undef VAR_DEF

/** { Secret } */
#define VAR_DEF(type, name, dxf, d1, d2, r1, r2)\
  /** Description: Notification function called whenever the DIM##NAME system variable has been changed. \
    Arguments: pDb (I) Pointer to the *database* being *modified*. \
    Remarks: This function is called after the operation. \
    Remarks: ##remarks \
    Notes: ##notes \
    See Also: ##see_also \
  */ \
  virtual void headerSysVar_dim##name##_Changed(const OdDbDatabase* pDb);

#include "DimVarDefs.h"
#undef VAR_DEF

  /** Description:
    Notification function called after the specified application is loaded and all its proxy
    objects are resurrected.
    
    Arguments:
    pDb (I) Pointer to the *database* being *modified*.
    appname (I) Name of the resurrecting application.
    objectIds (I) Object IDs of the resurrected objects.

	Gcad(Modify):const OdString&->const OdChar*
  */
  virtual void proxyResurrectionCompleted(
    const OdDbDatabase* pDb,
    const OdChar* appname, 
    OdDbObjectIdArray& objectIds);

  /** Description:
    Notification function called whenever a *database* is about to be deleted from memory.
    Arguments:
    pDb (I) Pointer to the *database* being *deleted*.

    Remarks:
    This function is called before the operation.
  */
  virtual void goodbye(
    const OdDbDatabase* pDb);
};
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbDatabaseReactor object pointers.
*/
typedef OdSmartPtr<OdDbDatabaseReactor> OdDbDatabaseReactorPtr;



//For internal use only.
class TOOLKIT_EXPORT OdDbDatabaseReactor2 : public OdDbDatabaseReactor
{
public:
  ODRX_DECLARE_MEMBERS(OdDbDatabaseReactor2);

   /** Description:
    Notification function called whenever a *database* is about to be saved to a .dwg file.
    
    Arguments:
    pDb (I) Pointer to the *database* to be saved.
    intendedName (I) Intended *name* of the .dwg file.
    
    Remarks:
    This function is called before the operation, and before the user 
    has had a chance to modify the filename. The file may not have the intendedName.
    
    See Also:
    o  abortSave
    o  saveComplete
  */
  virtual void beginSave(
    OdDbDatabase* pDb, 
    const OdChar* intendedName) = 0;

  /** Description:
    Notification function called whenever a *database* has been saved 
    to a .dwg file.
    
    Arguments:
    pDb (I) Pointer to the *database* saved.
    actualName (I) Actual *name* of the .dwg file.
    
    Remarks:
    This function is called after the operation, but before the *database* is constructed.
    
    See Also:
    o  abortSave
    o  beginSave
  */
  virtual void saveComplete(
    OdDbDatabase* pDb, 
    const OdChar* actualName) = 0;

  /** Description:
    Notification function called whenever the save of a *database* has failed.
    
    Arguments:
    pDb (I) Pointer to the *database* being saved.
    
    Remarks:
    This function is called after the operation.

    See Also:
    o  beginSave
    o  saveComplete
  */
  virtual void abortSave(
    OdDbDatabase* pDb) = 0;
};

#include "TD_PackPop.h"

#endif // _ODDBDATABASEREACTOR_INCLUDED_
