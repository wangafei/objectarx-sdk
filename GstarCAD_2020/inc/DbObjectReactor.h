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




#ifndef _DB_OBJECT_REACTOR_INCLUDED_
#define _DB_OBJECT_REACTOR_INCLUDED_

#include "TD_PackPush.h"

#include "RxObject.h"
#include "OdArrayPreDef.h"

class OdDbEntity;

/** Description:
    This class is the base class for custom classes that receive notification
    of OdDbObject events.

    Note:
    The default implementations of all methods in this class do nothing but return.

    Library:
    TD_Db
        
    {group:OdDb_Classes}
*/
class ODRX_ABSTRACT TOOLKIT_EXPORT OdDbObjectReactor : public OdRxObject
{
protected:
  OdDbObjectReactor() {}
public:
  ODRX_DECLARE_MEMBERS(OdDbObjectReactor);
  
  /**
    Description:
    Not called.
  */  
  virtual void cancelled(
    const OdDbObject* pObject);

  /**
    Description:
    Notification function called whenever the notifying object *has* had its clone() member function called. 
    
    Arguments:
    pObject (I) Pointer to the notifying object.
    pNewObject (I) Pointer to the object resulting from the copy.

    Remarks:
    The default implementation of this function does nothing.  This function can be
    overridden in custom classes.
  */
  virtual void copied(
    const OdDbObject* pObject, 
    const OdDbObject* pNewObject);

  /** 
    Description:
    Notification function called whenever an object *has* been *erased* or unerased.

    Arguments:
    pObject (I) Pointer to the object that was erased/unerased.
    erasing (I) True if and only if this object is being *erased*.
    
    Remarks:
    The default implementation of this function does nothing.  This function can be
    overridden in custom classes.
  */
  virtual void erased(
    const OdDbObject* pObject, 
    OdBool erasing = kTrue);

  /** 
    Description:
    Notification function called just before an object is deleted from memory. 
    
    Arguments:
    pObject (I) Pointer to the object that is being deleted.

    Remarks:
    The default implementation of this function does nothing.  This function can be
    overridden in custom classes.
  */
  virtual void goodbye(
    const OdDbObject* pObject);

  /** 
    Description:
    Notification function called whenever an object is opened for modify OdDb::kForWrite.

    Arguments:
    pObject (I) Pointer to the object that is being opened.

    Remarks:
    The default implementation of this function does nothing.  This function can be
    overridden in custom classes.
  */
  virtual void openedForModify(
    const OdDbObject* pObject);

  /** Description:
      Notification function called whenever an object is opened OdDb::kForWrite, a function
      *has* been called that could modify the contents of this object, and this object is now being
      closed.

      Arguments:
      pObject (I) Pointer to the object that is being closed after being *modified*.

      Remarks:
      The default implementation of this function does nothing.  This function can be
      overridden in custom classes.
  */
  virtual void modified(
    const OdDbObject* pObject);

  /**
    Description:
    Notification function called whenever an object derived from OdDbEntity is *modified*.
    
    Arguments:
    pObject (I) Pointer to the *modified* object.
    
    Remarks:
    The default implementation of this function does nothing.  This function can be
    overridden in custom classes.
    
    This function is called whenever the following has occurred.
    
    1)  The calling object is opened OdDb::kForWrite.
    
    2)  One of its member functions either
    
        a Calls its assertWriteEnabled with recordModified == true.
        
        b Calls its recordGraphicsModified(true).
    
    3) The calling object is being closed.
    
    This function is called whenever the object as been *modified*. It therefore
    indicates only that the graphics for it may have changed.
            
  */
  virtual void modifiedGraphics(
    const OdDbEntity* pEntity/*const OdDbObject* pObject*/);

  /**
    Description:
    Notification function called whenever a method of the
    specified subobject has called assertWriteEnabled()
    
    Arguments:
    pObject (I) Pointer to the notifying object.
    pSubObj (I) A pointer to the subobject owned by pObject.
    
    Remarks:
    Notification is made upon pObject->close() or pObject->cancel(). 
 
    Note:
    This function is called only for the modification of the following:
       
    Vertices of OdDb2dPolylines, OdDb3dPolylines, OdDbPolygonMeshs, and OdDbPolyFaceMeshes
    OdDbFaceRecords of OdDbPolyFaceMeshs 
    OdDbAttributes owned by OdDbBlockReferences, classes derived from OdDbBlockReference, and OdDbMInsertBlocks
  */
  virtual void subObjModified(
    const OdDbObject* pObject, 
    const OdDbObject* pSubObj);
  /**
    Description:
    Notification function called whenever the notifying
    object is in the midst an Undo operation that
    is undoing modifications.
    
    Arguments:
    pObject (I) Pointer to the notifying object.
    
    Remarks:
    The notifying object is open OdDb::kForRead.
    
    The default implementation of this function does nothing.  This function can be
    overridden in custom classes.
  */
  virtual void modifyUndone(
    const OdDbObject* pObject);

  /**
    Description:
    Notification function called whenever the XData *has* been written
    to the notifying object.
    
    Arguments:
    pObject (I) Pointer to the notifying object.
    
    Remarks:
    Notification is made upon pObject->close() or pObject->cancel(). 

    The notifying object is open OdDb::kForRead.
    
    The default implementation of this function does nothing.  This function can be
    overridden in custom classes.
  */
  virtual void modifiedXData(
    const OdDbObject* pObject);

  /**
    Description:
    Notification function called whenever the Undo process
    processes the appending of the notifying object to the *database*.
    
    Arguments:
    pObject (I) Pointer to the notifying object.
    
    Remarks:
    The notifying object is marked as *erased*. It is not removed the *database*, and can be unerased,
    even 'before' it was created. 
    
    The default implementation of this function does nothing.  This function can be
    overridden in custom classes.
  */
  virtual void unappended(
    const OdDbObject* pObject);

  /**
    Description:
    Notification function called whenever a Redo process
    processes the reappending of the notifying object to the *database*.
    
    Arguments:
    pObject (I) Pointer to the notifying object.
    
    Remarks:
    
    The default implementation of this function does nothing.  This function can be
    overridden in custom classes.
  */
  virtual void reappended(
    const OdDbObject* pObject);

  /** Description:
    Notification function called immediately before an object is closed.

    Arguments:
    objectId (I) Object ID of the object that is being closed.

    Remarks:
    The default implementation of this function does nothing.  This function can be
    overridden in custom classes.
  */
  virtual void objectClosed( // Gcad(Modify)
    const OdDbObjectId objectId);

  /** Description:
    Returns the first transient reactor of the specified class
    that is attached to the specified object.

    Arguments:
    pObject (I) Pointer to the notifying object.
    pKeyClass (I) Pointer to the class desciption.
  */
  static OdDbObjectReactor* findReactor(
    const OdDbObject* pObject, 
    const OdRxClass* pKeyClass);
};
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbObjectReactor object pointers.
*/
typedef OdSmartPtr<OdDbObjectReactor> OdDbObjectReactorPtr;
/** Description:
    This template class is a specialization of the OdArray class for OdDbObjectReactor object SmartPointers.
*/
typedef OdArray<OdDbObjectReactorPtr> OdDbObjectReactorArray;

// Gcad(Modify): OdDbEntityReactor
class OdDbEntityReactor: public OdDbObjectReactor
{
public:
	virtual void modifiedGraphics(const OdDbEntity* /*pEntity*/) {}
    virtual void dragCloneToBeDeleted (const OdDbEntity* /*pOriginal*/,
                     const OdDbEntity* /*pClone*/) {}
protected:
	OdDbEntityReactor() {}
};

#include "TD_PackPop.h"

#endif // _DB_OBJECT_REACTOR_INCLUDED_
