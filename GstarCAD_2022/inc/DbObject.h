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




#ifndef _ODDBXOBJECT_INCLUDED_
#define _ODDBXOBJECT_INCLUDED_ /* {Secret} */

#include "TD_PackPush.h"

#include "OdDb.h"
#include "Gi/GiDrawable.h"
#include "DbObjectId.h"
#include "OdString.h"
#include "DbObjectReactor.h"
#include "IdArrays.h"
#include "ResBuf.h"
#include "DebugStuff.h"

class OdDbFiler;
class OdDbDwgFiler;
class OdDbDxfFiler;
class OdGiDrawableTraits;
class OdGiWorldDraw;
class OdGiViewportDraw;
class OdGsNode;
class OdDbObjectImpl;
class OdDbEntity;
class OdDbDatabase;
class OdDbIdMapping;
class OdDbAuditInfo;
class OdGeMatrix3d;
class OdDbObjStorage;
class OdString;
class OdGePoint3d;
class OdBinaryData;
class OdDbIdPair;
class OdDbField;
class OdDbDictionary;
class OdDbXrecord;

typedef OdArray<void*> OdDbVoidPtrArray;

/** Description:
This template class is a specialization of the OdSmartPtr class for OdDbXrecord object pointers.
*/
typedef OdSmartPtr<OdDbXrecord> OdDbXrecordPtr;

/** Description:
    Declares the member functions for classes derived from OdDbObject. 
        
    Arguments:
    ClassName (I) Name of the derived class.
    
    Remarks:
    Classes derived 
    from OdDbObject should invoke this macro in their class definitions, 
    passing the name of the derived class.
*/
#define ODDB_DECLARE_MEMBERS(ClassName)\
protected:                                \
  ClassName(OdDbObjectImpl* pImpl);       \
public:                                   \
ODRX_DECLARE_MEMBERS (ClassName)

/**
  Description:
  Creates a new instance of a derived class,
  and returns a SmartPointer to it, *without*
  incrementing the reference count of the new
  object.
  
  Arguments:
  ClassName (I) Name of the derived class.
*/
#define DBOBJECT_CONSTR(ClassName) OdSmartPtr<ClassName> (new ClassName, kOdRxObjAttach)


/** Description:
    This class implements OdError objects with Result codes of eXdataSizeExceeded,
    and the Object IDs of the objects related to the errors.
    
    Library: TD_Db
    {group:Error_Classes} 
*/
class TOOLKIT_EXPORT OdError_XdataSizeExceeded : public OdError
{
public:
  /**
    Arguments:
    objectId (I) Object ID of the object with the error.
  */
  OdError_XdataSizeExceeded(
    const OdDbObjectId& objectId);
};
                            

/** Description: 
  
    {group:TD_Namespaces}
*/

/** 
    Description
    This class is the base class for all objects contained in an OdDbDatabase instance (OdDb objects).

    Remarks:
    
    Creating and Deleting Database Objects
    
    o  Database objects are normally created by calling OdDbXXXXX::createObject().
       When an object is created, it will be in kOpenForWrite *mode*.  The delete
       operator should never be called on *database* objects.  Instead, erase()
       should be called, which marks the object as *erased*.
    o  OdDbObject instances should be created by calling the createObject() method.
    o  OdDbObject instances are created in kOpenForWrite *mode*.  
    o  Depending on other OdDbObject instances while constructing or deleting instances is prohibited.
    o  OdDbObject instances should be deleted from an OdDbDatabase with erase().
    o  Never access a pointer to a closed object.
    o  The delete operator must never be called on OdDbObject instances. Instead, the erase() method
       should be called, which marks this object as *erased*.
    
    Accessing Database Objects
    
    o  Database objects must be opened before they can be accessed.  
    o  Given a valid OdDbObjectId, a *database* object is opened by calling OdDbObjectId::safeOpenObject().  
    o  Database objects should be opened in the most restrictive *mode* possible, and should be released 
       immediately when access is no longer needed.
       
    Object may be opened in any one of the following modes:
    
    @table
    Mode              Description
    OdDb::kForRead    Allows operations that do not modify this object.  
                      A *database* object can be opened in this mode any number of times (simultaneously), 
                      if has not open in OdDb::kForWrite or OdDb::kForNotify *mode*.  
                      An exception will be thrown if any type of write operation is attempted 
                      on an object open in this *mode*.
    OdDb::kForWrite   Allows read and write operations to be performed on this object.  
                      An *database* object can be opened in this *mode* only if it is not
                      already open in any *mode*.
    OdDb::kForNotify  This object is opened for notification purposes.  
                      A *database* object can be opened in this *mode* so long as it is 
                      not already open in kNotify *mode*.
    
    See Also:
    o  OdDbObjectId
    o  OdDbDatabase

    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbObject : public OdGiDrawable
{
public:
  ODDB_DECLARE_MEMBERS(OdDbObject);

protected:
  OdDbObject();
public:
  virtual ~OdDbObject();
  
  virtual OdResult close();
  /** 
    Description:
    Increments the reference count of this object.
  */
  void addRef();

  /** Description:
    Decrements the reference count of this object.
    Remarks:
    This object is deleted when the reference count reaches zero.
  */
  void release();

  /** Description:
      Returns the reference count of this object.
  */
  long numRefs() const;

  /** 
    Description:
    Returns the Object ID of this object.
    
    Remarks:
    Returns a null ID if this object has not been added to a *database*.
  */
  OdDbObjectId objectId() const;
  
  /** 
    Description:
    Returns the persistent *handle* of this *database* object.
  */
  OdDbHandle getDbHandle() const;
  
  void getOdDbHandle(OdDbHandle& handle) const
  { handle = getDbHandle(); }
  /** 
    Description:
    Returns the persistent *handle* of this *database* object.
  */
  OdDbHandle handle() const 
  { return getDbHandle (); }
  
  /** 
    Description:
    Returns the Object ID of this object's owner.
    
    Remarks:
    Returns a null ID if this object has not been added to a *database*,
    or if OdDbObject::setOwnerId has not been called.
    
    Throws:
    @table
    Exception        Cause
    eNotInDatabase   objectId().isNull()
  */
  OdDbObjectId ownerId() const;
  
  /** 
    Description:
    Sets this object's *ownerId* data member. 
    
    Arguments:
    ownerId (I) Owner's objectId.
    
    Remarks:
    This function lets this object know its owner; it does *not*
    notify the owner. 
    
    Throws:
    @table
    Exception             Cause
    eNotInDatabase        Owner is not in the *database*.
  */
  virtual OdResult setOwnerId(
    OdDbObjectId ownerId);
    
  /** 
    Description:
    Returns the OdDbDatabase that contains this object.
  */
  OdDbDatabase* database() const;
  
  /** 
    Description:
    Creates an OdDbDictionary extension dictionary of this object.

    Remarks:
    If this object's extension dictionary *has* been *erased*, it will
    be unerased.  
    
    An object owns its extension dictionary.
  */
  OdResult createExtensionDictionary();
  
  
  /** 
    Description:
    Returns the Object ID of this object's extension dictionary.  
    
    Remarks:
    Returns a null ID if this object does not have an extension dictionary, 
    or if its extension dictionary *has* been *erased*.
  */
  OdDbObjectId extensionDictionary() const;
  
  /** 
    Description:
    Releases and erases this object's extension dictionary if it exists and is empty. 
    
    Remarks:
    Returns true if and only if either the dictionary did not exist or was released.
  */
  OdResult releaseExtensionDictionary();  

  // Opens/creates/unerases Xdictionary, and retrieves/creates Xrecord for the given name
  //
  
  /** Description:
    Creates or retrieves the specified Xrecord in this object's extension dictionary.

    Arguments:
    xrecordName (I) Xrecord name.
    style (I) Merge *style*.
    
    Remarks:
    Returns a SmartPointer to the specified Xrecord.
    
    o  If the extension dictionary has been *erased*, it is unerased.
    o  If the extension dictionary does not exist, it is created.
    o  If the specified Xrecord does not exist, it is created.
  */
  OdDbXrecordPtr createXrecord(
    const OdString& xrecordName, 
    OdDb::DuplicateRecordCloning style = OdDb::kDrcIgnore);

	//Gcad(Add)
	OdResult setBinaryData(const OdChar* key, long size, const char * data);
	OdResult getBinaryData(const OdChar* key, long & size, char *& data) const;

	//OdUInt32 getData();
	//void     setData(OdUInt32 n);
  /** 
    Description:
    Upgrades this object from OdDb::kForRead to OdDb::kForWrite if there is only one reader, and
    returns isWriteEnabled();
  */
  OdResult upgradeOpen();
  OdResult upgradeOpen(ODSYSDEF);
  OdResult upgradeFromNotify(OdBool& wasWritable);

  /** PMK:
    This function should return isWriteEnabled().
  */
  
  /** 
    Description:
    Downgrades this object from OdDb::kForWrite to OdDb::kForRead, and
    returns isReadEnabled();
     
    Remarks: 
    Any pending changes to this object are committed to the *database*. 
  */
  OdResult downgradeOpen();
  OdResult downgradeToNotify(OdBool wasWritable);

  /** PMK:
    This function should return isReadEnabled();
  */
    
  /** 
    Description:
    Notification function called by the Teigha framework immediately before an object is opened. 

    Arguments:
    mode (I) Mode in which the object is being opened.
    
    Remarks:
    This function is notified just before an object is to be opened; giving this function
    the ability to cancel the object being opened.
         
    Returns eOk if and only if open() is to continue.

    Overriding this function in a child class allows a child instance to be notified each time an
    object is opened.

    When overriding this function:
    
    1)  If the OdDbObject's state is incorrect, return 
        something other than eOk.
    
    2)  If the parent class's subOpen() returns anything
        other than eOk, immediately return it. 
    
    3)  If other actions are required before open, do them.
    
    4)  Return eOk.
    
    The default implementation of this function does nothing but return eOk.  This function can be
    overridden in custom classes.
  */
  virtual OdResult subOpen(
    OdDb::OpenMode mode);
  /**
    Description:
    Notification function called whenever the notifying object has had its cancel() member function called. 
    
    Arguments:
    pObject (I) Pointer to the object sending the notification.

    Remarks:
    The default implementation of this function does nothing.  This function can be
    overridden in custom classes.

    When this function is called, pObject points to the object sending the notification.
     
    The sending object is open kOpenForRead.
  */  
//   virtual void cancelled (
//      const OdDbObject* pObject);
    
  

  /**
    Description:
    Called from within cancel() before any other functions. 
    
    Remarks:
    This function is notified just before the current open operation is to be cancelled, giving this function
    the ability to cancel the cancel.

    Returns eOk if and only if cancel() is to continue.
         
    When overriding this function:
    
    1)  If the OdDbObject's state is incorrect, return 
        something other than eOk.
    
    2)  If the parent class's subCancel() returns anything
        other than eOk, immediately return it. 
    
    3)  If other actions are required before cancel, do them.
    
    4)  Return eOk.

    If you must make changes to this object's state, either make them after
    step 2, or roll them back if step 2 returns other than eOk. 
    
    The default implementation of this function does nothing but return eOk.  This function can be
    overridden in custom classes.
    
  */  
	 OdResult cancel();
   virtual OdResult subCancel();
  /** PMK:
    This function must return value.
  */

  /** 
    Description:
    Called as the first operation as this object is being closed, for
    *database* -resident objects only. 
    
    Remarks:
    This function is notified just before the current open operation is to be closed, giving this function
    the ability to cancel the close.
    
    Returns eOk if and only if close() is to continue.
         
    When overriding this function:
    
    1)  If the OdDbObject's state is incorrect, return 
        something other than eOk.
    
    2)  If the parent class's subClose() returns anything
        other than eOk, immediately return it. 
    
    3)  If other actions are required before close, do them.
    
    4)  Return eOk.

    If you must make changes to this object's state, either make them after
    step 2, or roll them back if step 2 returns false. 
    
    The default implementation of this function does nothing but return eOk.  This function can be
    overridden in custom classes.
  */
  OdResult closeAndPage(OdBool onlyWhenClean = kTrue);
  virtual OdResult subClose();
  /** PMK:
    This function must return  true if and only if close() is to continue.
  */
  
  /** 
    Description:
    Sets the *erased* *mode* of this object. 
    
    Arguments:
    eraseIt (I) Boolean to specify if object is to be *erased* or unerased.
                
    Remarks:
    Erased objects are not deleted from the *database* or from memory.
    
    Erased objects are not filed when the *database* is saved or sent to a DXF file.
  */
  OdResult erase(
    OdBool eraseIt = kTrue);
  
  /** 
    Description:
    Called as the first operation as this object is being *erased* or unerased. 

    Arguments:
    erasing (I) A copy of the erasing argument passed to erase().

    Remarks:
    This function is notified just before the current object is to be *erased*, giving this function
    the ability to cancel the erase.
         
    Returns eOk if and only if erase() is to continue.

    When overriding this function:
    
    1)  If the OdDbObject's state is incorrect, return 
        something other than eOk.
    
    2)  If the parent class's subErase() returns anything
        other than eOk, immediately return it. 
    
    3)  If other actions are required before erase, do them.
    
    4)  Return eOk.

    If you must make changes to this object's state, either make them after
    step 2, or roll them back if step 2 returns other than eOk. 
    
    The default implementation of this function does nothing but return eOk.  This function can be
    overridden in custom classes.
    
  */
  virtual OdResult subErase(
    OdBool erasing);
  
  /** 
    Description:
    Replaces this *database* -resident (DBRO) object with the specified non- *database* -resident (NDBRO) object,
    while retaining this object's *objectId*, *handle*, *owner*, and reactor list.
   
    Arguments:
    pNewObject (I) Pointer to the object with which to replace this object in the *database*.
    keepXData (I) This object's XData will be retained if and only if keepXData is true.
    keepExtDict (I) This object's extension dictionary will be retained if and only if keepExtDict is true.
                    
    Remarks:
    This object must be open OdDb::kForWrite. 
    
    The replacement object will opened OdDb::kForWrite, and must be closed.
    
    It is up to the caller to delete the replaced (this) object.
    
    Throws:
    @table
    Exception               Cause
    eIllegalReplacement     This object is NDBRO or NewObject is DBRO.
  */
  OdResult handOverTo(
    OdDbObject* pNewObject, 
    OdBool keepXData = kTrue,
    OdBool keepExtDict = kTrue);
  
  /** 
    Description:
    Called as the first operation of the handOverTo function.  
    
    Arguments:    
    pNewObject (I) Pointer to the object with which to replace this object in the *database*.

    Remarks:
    This function allows custom classes to populate the new object.

    Remarks:
    Overriding this function in a child class allows a child instance to be notified each time an
    object is handed over.
    
    This function is notified just before an object is to be handed over; giving this function
    the ability to cancel the handover.
         
    When overriding this function:
    
    1)  If the OdDbObject's state is incorrect, return 
        something other than eOk.
    
    2)  If the parent class's subHandover() returns anything
        other than eOk, immediately return it. 
    
    3)  If other actions are required before handover, do them.
    
    4)  Return eOk.
    
    If you must make changes to this object's state, either make them after
    step 2, or roll them back if step 2 returns other than eOk. 
   
    The default implementation of this function does nothing but return eOk.  This function can be
    overridden in custom classes.

  */
  virtual OdResult subHandOverTo(
    OdDbObject* pNewObject);
  
  /** 
    Description:
    Swaps the objectIDs, handles, XData,and extension dictionary between
    this object and another object.

    Arguments:
    otherId (I) Object ID of object with which to swap.
    swapXdata (I) XData will be swapped if and only if swapXData is true.
    swapExtDict (I) Extension dictionaries will be swapped if and only if swapExtDict is true.
    
    Throws:
    @table
    Exception               Cause
    eIllegalReplacement     Either object is NDBRO.
  */
  OdResult swapIdWith(
    OdDbObjectId otherId, 
    OdBool swapXdata = kFalse,
    OdBool swapExtDict = kFalse);
  
  /**
    Description:
    Called as the first operation of swapIdWith

    Arguments:
    otherId (I) Object ID to be swapped with this object's Object ID.
    swapXdata (I) If and only if true, extended data are swapped.
    swapExtDict (I) If and only if true, extension dictionaries are swapped.

    Remarks:      
    This function is notified just before an object is to be opened; giving this function
    the ability to cancel the object being swapped.
         
    Returns eOk if and only if subSwapIdWith() is to continue.
    
    When overriding this function:
    
    1)  If the OdDbObject's state is incorrect, return 
        something other than eOk.
    
    2)  If the parent class's subSwapIdWith() returns anything
        other than eOk, immediately return it. 
    
    3)  If other actions are required before swapping IDs, do them.
    
    4)  Return eOk.
    
    If you must make changes to this object's state, either make them after
    step 2, or roll them back if step 2 returns other than eOk. 

    The default implementation of this function does nothing but return eOk.  This function can be
    overridden in custom classes.
 
  */
	virtual OdResult subSwapIdWith(
    OdDbObjectId otherId, // const OdDbObjectId& otherId
    OdBool swapXdata = kFalse,
    OdBool swapExtDict = kFalse);

  virtual OdResult swapReferences(const OdDbIdMapping& idMap);
  virtual void cancelled(const OdDbObject* dbObj);
  /** PMK:
    This function serves no purpose if it does not return a value.
  */
    
  /** 
    Description:
    Perform an *audit* operation on this object.

    Arguments:
    pAuditInfo (I) Pointer to an OdDbAuditInfo object.
    
    Remarks:
    The specified OdDbAuditInfo object controls the *audit*, and receives the *audit* status.
    
    When overriding this function for a custom class, first call OdDbObject::audit(pAuditInfo) 
    to validate the *audit* operation.
  */
	virtual OdResult audit(
    OdDbAuditInfo* pAuditInfo);
  
  /** 
    Description:
    Reads the .dwg file format data of this object from the specified file.
       
    Arguments:   
    pFiler (I) Pointer to the filer from which the data are to be read.
    
    Remarks:
    This function calls dwgInFields(pFiler),
    then loads any Xdata associated with this object.
  */
  OdResult dwgIn(
    OdDbDwgFiler* pFiler);
  
  /** 
    Description:
    Writes the .dwg file format data of this object to the specified filer. 
    
    Arguments:
    pFiler (I) Pointer to the filer to which the data are to be written.
    
    Remarks:
    This function calls this object's dwgOutFields() function,
    writes loads any Xdata associated with this object.
  */
  OdResult dwgOut(
    OdDbDwgFiler* pFiler) const;
  
  /** 
    Description:
    Reads the DXF format data of this object from the specified filer. 
    
    Arguments:
    pFiler (I) Pointer to the filer from which the data are to be read.
    
    Remarks:
    Returns the filer status.

    This function calls this object's dxfInFields(pFiler),
    then loads any Xdata associated with this object.
  */
  virtual OdResult dxfIn(
    OdDbDxfFiler* pFiler);
  
  /** 
    Description:
    Writes the DXF format data of this object to the specified filer. 
    
    Arguments:
    pFiler (I) Pointer to the filer to which the data are to be written.
    
    Remarks:
    This function calls this object's dxfOutFields(pFiler) function,
    writes any Xdata associated with this object.
  */
  virtual OdResult dxfOut(
    OdDbDxfFiler* pFiler,
    OdBool allXdFlag = kTrue,
    unsigned char* regAppTable = NULL) const;
  
  /** 
    Description:
    Reads the .dwg file data of this object. 

    Arguments:
    pFiler (I) Filer object from which data are read.
    
    Remarks:
    Returns the filer status.
    
    This function is called by dwgIn() to allow the object to read its data.

    When overriding this function:
     
    
    1)  Call assertWriteEnabled(). 
    2)  Call the parent class's dwgInFields(pFiler). 
    3)  If it returns eOK, continue; otherwise return whatever the parent's dwgInFields(pFiler) returned. 
    4)  Call the OdDbDwgFiler(pFiler) methods to read each of the object's data items in the order they were written.
    5)  Return pFiler->filerStatus().
  */
  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);
  
  /** 
    Description:
    Writes the .dwg file data of this object. 

    Arguments:
    pFiler (I) Pointer to the filer to which data are written.
    
    Remarks:
   
    This function is called by dwgIn() to allow the object to write its data.

    When overriding this function:
     
    
    1)  Call assertReadEnabled(). 
    2)  Call the parent class's dwgOutFields(pFiler). 
    3)  Call the OdDbDwgFiler(pFiler) methods to write each of the object's data items in the order they were written.
  */
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;
  
  /** 
    Description:
    Reads the DXF data of this object. 
    
    Arguments:
    pFiler (I) Pointer to the filer from which data are read.
    
    Remarks:
    Returns the filer status.
    
    This function is called by dxfIn() to allow the object to read its data.

    When overriding this function:
     
    
    1)  Call assertWriteEnabled(). 
    2)  Call the parent class's dwgInFields(pFiler). 
    3)  If it returns eOK, continue; otherwise return whatever the parent's dxfInFields(pFiler) returned. 
    4)  Call the OdDbDxfFiler(pFiler) methods to read each of the object's data items in the order they were written.
    5)  Return pFiler->filerStatus().
  */
  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);
  
  /** 
    Description:
    Writes the DXF data of this object.

    Arguments:
    pFiler (I) Pointer to the filer to which data are to be written.
    
    Remarks:
    
    This function is called by dxfOut() to allow the object to write its data.

    When overriding this function:
     
    
    1)  Call assertReadEnabled(). 
    2)  Call the parent class's dxfOutFields(pFiler). 
    4)  Use pFiler to call the OdDbDxfFiler methods to write each of the object's data items in the order they were written.
  */
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;
  
  /** 
    Description:
    Reads the DXF R12 format data of this object. 

    Arguments:
    pFiler (I) Pointer to the filer from which data are to be read.
    
    Remarks:
    Returns the filer status.

    This function is called by dxfIn() to allow the object to read its data.

    When overriding this function:
    
    1)  Call assertWriteEnabled(). 
    2)  Call the parent class's dxfInFields_R12(pFiler). 
    3)  If it returns eOK, continue; otherwise return whatever the parent's dxfOutFields_R12(pFiler) returned. 
    4)  Call the OdDbDxfFiler(pFiler) methods to read each of the object's data items in the order they were written.
    5)  Return pFiler->filerStatus().
  */
  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);
  
  /** 
    Description:
    Writes the DXF data of this object. 

    Arguments:
    pFiler (I) Pointer to the filer to which data are to be written.
    
    Remarks:
    Returns the filer status.

    This function is called by dxfOut() to allow the object to write its data.

    When overriding this function:
     
    
    1)  Call assertReadEnabled(). 
    2)  Call the parent class's dxfOutFields(pFiler). 
    3)  Use pFiler to call the OdDbDxfFiler methods to write each of the object's data items in the order they were written.
  */
  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;
  
  /**
    Description:
    Returns the merge style of this object.
  */
  virtual OdDb::DuplicateRecordCloning mergeStyle() const;
  
  /** 
    Description:
    Returns a linked list of ResBufs containing
    a copy of the XData of this object.

    Arguments:
    regappName (I) Registered application for which to return XData. 

    Remarks:
    If regappName is empty, all XData of this object will be returned.

    If regappName is not empty, XData for only that application will be
    returned.

    Returns a null SmartPointer if there are no XData.
  */
  OdResBufPtr xDataPtr(
    const OdString &regappName = OdString::kEmpty) const;
  
  /** 
    Description:
    Sets the XData of this object.
    
    Arguments:
    pRb (I) A pointer to the ResBuf list containing the XData.
    
    Remarks:
    The sublist for each RegApp, and the ResBuf list itself, must begin with a ResBuf with 
    resbuf.restype == kDxfRegAppName and resbuf.rstring == a valid regAppName string. 
    
    Any existing XData for the specified regAppName will be replaced.
    
    To remove the regAppName and its XData, just provide the regAppName with no data. 
    
    If you override this method, you should supermessage this classes parent class
    to add add the XData to the object.
  */
  virtual void setXDataPtr( // Gcad(Modify): OdResBuf=>resbuf.
    const OdResBuf* pRb);

  /** 
    Description:
    Returns a linked list of resbuf containing
    a copy of the XData of this object.

    Arguments:
    regappName (I) Registered application for which to return XData. 

    Remarks:
    If regappName is NULL, all XData of this object will be returned.

    If regappName is not empty, XData for only that application will be
    returned.

    Returns a null SmartPointer if there are no XData.
  */
   virtual resbuf* xData( 
     const OdChar* regappName = NULL) const;

  /** 
    Description:
    Sets the XData of this object.
    
    Arguments:
    pRb (I) A pointer to the resbuf list containing the XData.
    
    Remarks:
    The sublist for each RegApp, and the ResBuf list itself, must begin with a ResBuf with 
    resbuf.restype == kDxfRegAppName and resbuf.rstring == a valid regAppName string. 
    
    Any existing XData for the specified regAppName will be replaced.
    
    To remove the regAppName and its XData, just provide the regAppName with no data. 
    
    If you override this method, you should supermessage this classes parent class
    to add add the XData to the object.

  */
   virtual OdResult setXData( // Gcad(Add): OdResBuf=>resbuf.
     const resbuf* pRb);

  /** PMK
    Where is the mechanism for registering a regAppName?
      
    This function should return a value; at least a bool.

    ObjectArx:
    Returns Acad::eOk if the XData is successfully added to the object. 
    If there is insufficient space in the XData area of the object, 
    then Acad::eXdataSizeExceeded are returned. 
    If any of the regappNames in XData are not in the APPID table, 
    then Acad::eRegappIdNotFound is returned. 
  */   
     
  /** 
    Description:
    Returns true if and only if this object's *erased* status *has* been toggled since it was opened.
  */
  OdBool isEraseStatusToggled() const;
  
  /** 
    Description:
    Returns true if and only if this object is marked as *erased*.
  */
  OdBool isErased() const;
  
  /** 
    Description:
    Returns true if and only if this object is open OdDb::kForRead.
  */
  OdBool isReadEnabled() const;
  
  /** 
    Description:
    Returns true if and only if this object is open OdDb::kForWrite.
  */
  OdBool isWriteEnabled() const;
  
  /** 
    Description:
    Returns true if and only if this object is open OdDb::kForNotify.
  */
  OdBool isNotifyEnabled() const;
  
  /** 
    Description:
    Returns true if and only if this object's assertWriteEnabled() *has* been called since 
    it was opened.
  */
  OdBool isModified() const;

  /** Description:
  */
//  void setModified (bool bModified);
  
  /** 
    Description:
    Returns true if and only this object's assertWriteEnabled() and setXData() have been called since it was opened.
  */
  OdBool isModifiedXData() const;
  
  /**
    Description:
    Returns true if and only if an object derived from OdDbEntity *has* been *modified*.
    
    Remarks:
    
    This function returns true if and only if an object derived from OdDbEntity
    either
    
        1) Calls assertWriteEnabled()
        
        2) Calls recordGraphicsModified(true).
  */
  OdBool isModifiedGraphics() const;
   
  /** 
    Description:
    Returns true if and only if this object has not been *closed* since it was created.
  */
  OdBool isNewObject() const;
  
  /** 
    Description:
    Returns true if and only if this object is sending notification.
  */
  OdBool isNotifying() const;
  
  /** 
    Description:
    Returns true if and only if this object is taking part in an Undo operation.
  */
  OdBool isUndoing() const;
  
//  Gcad(TODO):
  OdBool isCancelling() const;
  OdBool isTransactionResident() const; // == isDBRO()?

  /**
    Description:
    Returns true if and only if a call to close would completely close this object at this time.
    
    Remarks:
    Returns true if and only if a this object is open OdDb::kForRead with only one reader, and is not
    in a transaction.
  */  
  OdBool isReallyClosing() const;
  
  /** 
    Description:
    Returns true if and only this object is a *database* -resident object.
  */
  bool isDBRO() const;
    
  /** 
    Description:
    Throws an exception if this object is not open OdDb::kForRead.
    
    Remarks:
    This function should be used only inside member functions that do not modify this object. 
    It should be the first function called by these functions.
    
    Throws:
    @table
    Exception             Cause
    eNotOpenForRead       !isReadEnabled()
  */
  void assertReadEnabled() const;
  
  /** 
    Description:
    Throws an exception if this object is not open OdDb::kForWrite,
    and controls automatic *undo* and notification of modifications.
    
    Arguments:
    autoUndo (I) Specifies if automatic *undo* should be done.
    recordModified (I) Specifies if graphics are to be updated, and
                        "openedForModify", "modified" and "modifiedGraphics"
                        notifications are to be sent. 
    
    Remarks:
    This function should be used only inside member functions that modify this object. 
    It should be the first function called by these functions.
    
    Throws:
    @table
    Exception             Cause
    eNotOpenForWrite     !isWriteEnabled()
  */
  void assertWriteEnabled(
    OdBool autoUndo = kTrue, 
    OdBool recordModified = kTrue);
  
  /** 
    Description:
    Throws an exception if this object is not open OdDb::kForNotify.
    
    Remarks:
    This function should be used only inside member functions that are used only when this object
    is open OdDb::kForNotify. It should be the first function called by these functions.
    
    Throws:
    @table
    Exception            Cause
    eInvalidOpenState    !isNotifyEnabled()
  */
  void assertNotifyEnabled() const;
  
  bool isUndoRecordingDisabled() const;

  /** 
    Description:
    Controls the *undo* recording of this object in OdDbDatabase.

    Arguments:
    disable (I) Boolean to control *undo* recording.
    
    Remarks:
    Disabling *undo* recording does not *erase* the *undo* recording; it merely suspends it.
    Undo recording is initially off for newly created OdDbDatabase objects.
  */
  void disableUndoRecording(
    OdBool disable);
  
  /** 
    Description:
    Returns the *undo* filer associated with this object.
    
    Remarks:
    This function is typically used by custom classes using partial Undo
    to add Undo information to the filer that would be used by this
    object applyPartialUndo().
    
    Throws:
    @table
    Exception           Cause
    eNotOpenForWrite    !isWriteEnabled()
  */
  OdDbDwgFiler* undoFiler();
  
  /**
    Description:
    Notification function called each time an Undo operation is performed 
    this object is using partial Undo.
    
    Arguments:
    pUndoFiler (I) A pointer to the *undo* filer with the partial *undo* information.
    pClassObj     (I) A pointer to the OdRxClass object for the class that will *handle* the Undo.
    
    Remarks:
    An object indicates it's using the partial *undo* mechanism, if and only if
    it has set autoUndo false in all calls to assertWriteEnabled().
    
    This member function must know which types of fields to scan, 
    and must stop after reading what it it needs.

    If the class type specified by pClassObj does not matches the class of this object,
    this member function must call the parent class's applyPartialUndo() 
    and return whatever it returns.

    If it does match the class of this object, this member function must use pUndoFiler to read the *undo* data, 
    then typically use this object's set() method.
    
    Throws:
    @table
    Exception                   Cause
    eNotThatKindOfClass         pClassObj != OdDbObject::desc()
  */
  virtual OdResult applyPartialUndo(
    OdDbDwgFiler* pUndoFiler, 
    OdRxClass* pClassObj);
  
  /**
    Description:
    Adds the specified transient reactor to this object's reactor list.

    Arguments:
    pReactor (I) Pointer to the transient reactor object.

    Remarks:
    An object must be open either OdDb::kForRead or OdDb::kForWrite in order to add a transient reactor.
  */
  void addReactor(
    OdDbObjectReactor* pReactor) const;
  
  /**
    Description:
    Removes the specified transient reactor from this object's reactor list.

    Arguments:
    pReactor (I) Pointer to the transient reactor object.

    Remarks:
    An object must be open either OdDb::kForRead or OdDb::kForWrite in order to remove a transient reactor.
  */
  void removeReactor(
    OdDbObjectReactor* pReactor) const;
  
  /** 
    Description:
    Adds the specified persistent reactor to this object's reactor list.

    Arguments:
    objId (I) Object ID of the persistent reactor.

    Remarks:
    An object must be open OdDb::kForWrite in order to add a persistent reactor.

    If the persistent reactor does not have an owner, 
    it isn't saved with the drawing. Non-graphical objects used as persistent 
    reactors are typically stored in a dictionary in the Named Objects Dictionary 
    or in an extension dictionary associated with some object.
  */
  virtual OdResult addPersistentReactor(
    OdDbObjectId objId);
  
  /** 
    Description:
    Removes the specified persistent reactor from this object's reactor list.

    Arguments:
    objId (I) Object ID of the persistent reactor.

    Remarks:
    An object must be open OdDb::kForWrite in order to remove one of its persistent reactors.
  */
  virtual OdResult removePersistentReactor(
    OdDbObjectId objId);
  
  /** 
    Description:
    This method returns true if objId is the Object ID of a reactor attached to this object. Otherwise, it returns false.

    Arguments:
    objId (I) Object ID of the persistent reactor.
  */
  bool hasPersistentReactor(
    OdDbObjectId objId) const;

  /** 
    Description:
    Returns Object IDs of this object's persistent reactors.
  */
  void getPersistentReactors(OdDbObjectIdArray& ids);

  /** Gcad(ADD): 
  */
  OdDbVoidPtrArray*         reactors();
  const OdDbVoidPtrArray*   reactors() const;

  /** 
    Description:
    Returns this object's transient reactors.
  */
  OdDbObjectReactorArray getTransientReactors() const;
  
  /**
    Description:
    Allows a subobject of a complex object to notify its root object that it *has* been changed. 
    
    Arguments:
    pSubObj (I) Pointer to the *modified*subobject.

    Remarks:
    Here's how it's supposed to work:
    
    1)  The subobject class's close() calls its triggers a "modified" notification which
        calls its xmitPropagateModify().
    2)  The subobject class calls the its parent's recvPropagateModify() its object's pointer.
    3)  The owner's class's recvPropagateModify() sends a "modified" notification to the top of its class.
    
    The default implementation of this function does nothing. This function can be overridden in custom classes.
  */
  virtual void recvPropagateModify(
    const OdDbObject* pSubObj);
  
  /**
    Description:
    Allows a subobject of a complex object to notify its root object that it *has* been changed. 

    Remarks:
    This function must be called within an subobject's close() method.
    
    The owner can then propagate the notification that it *has* been been *modified*.
    
    The default implementation of this function inform the *database* 
    in which the owner resides *has* been *modified*; triggering any
    OdDbDatabaseReactors attached to it. This function can be
    overridden in custom classes.

    When overriding this function, it should: 
   
    Remarks:
    Here's how it's supposed to work:
    
    1)  The subobject class's close() calls its triggers a "modified" notification which
        calls its xmitPropagateModify().
    2)  The subobject class calls the its owner's recvPropagateModify() its object's pointer.
    3)  This owner's class's recvPropagateModify() sends a "modified" notification to the top of its class.
  */
  virtual void xmitPropagateModify() const;
  
  /** 
    Description:
    Performs a deep *clone* of this object.
    
    Arguments:
    ownerIdMap (I) Owner's ID map.

    Remarks:
    Returns a SmartPointer to the newly created *clone*,
    and adds a record to the specified ID map. 

    If the cloning operation fails, a null SmartPointer is returned.
    
    A deep *clone* is a *clone* of this object and everything it owns.
    
    This function should not be called by client code; use OdDbDatabase::deepCloneObjects() instead.

    This function can be overridden in custom classes.

    The default implementation of this function appends the cloned object to the specified owner object.   
  */
  ODRX_SEALED_VIRTUAL OdDbObjectPtr deepClone(
    OdDbIdMapping& ownerIdMap, OdDbObject*) const ODRX_SEALED;

  ODRX_SEALED_VIRTUAL OdResult deepClone(OdDbObject* pOwnerObject,
    OdDbObject*& pClonedObject,
    OdDbIdMapping& idMap,
    OdBool isPrimary = true) const ODRX_SEALED;

  virtual OdResult subDeepClone(
    OdDbObject* pOwnerObject,
    OdDbObject*& pClonedObject,
    OdDbIdMapping& idMap,
    OdBool isPrimary = true) const;
 
  /** 
    Description:
    Performs a shallow *clone* of this object. 
    
    Arguments:
    ownerIdMap (I/O) Owner's ID map.

    Remarks:
    Returns a SmartPointer to the newly created *clone*,
    and adds a record to the specified ID map. 

    If the cloning operation fails, a null SmartPointer is returned.
    
    A shallow *clone* is a *clone* of only this object.
    
    This function should not be called by client code; use OdDbDatabase::wblockCloneObjects() instead.

    The default implementation of this function calls subWblockClone() for all objects hard-referenced by this object.
    This function can be overridden in custom classes.
    
    See also:
    subDeepClone()

  */      
  ODRX_SEALED_VIRTUAL OdDbObjectPtr wblockClone(
    OdDbIdMapping& ownerIdMap, OdDbObject*) const ODRX_SEALED;

  ODRX_SEALED_VIRTUAL OdResult wblockClone(OdRxObject* pOwnerObject,
    OdDbObject*& pClonedObject,
    OdDbIdMapping& idMap,
    OdBool isPrimary = true) const ODRX_SEALED;

  virtual OdResult subWblockClone(
    OdRxObject* pOwnerObject,
    OdDbObject*& pClonedObject,
    OdDbIdMapping& idMap,
    OdBool isPrimary = true) const;  
  
  /**
    Description:
    This function appends this object to the specified owner object.
    
    Arguments:
    idPair (I) ID pair to append.
    pOwnerObject (I) Pointer to the owner object.
    ownerIdMap (I/O) Owner's ID map.
    
    Remarks:
    Adds a record to the specified ID map.     
    
    This function is used internally to subDeepClone() and subWblockClone().
    
    Throws:
    @table
    Exception              Cause
    eInvalidOwnerObject    !pOwnerObject->get()
    
  */
  virtual void appendToOwner(
    OdDbIdPair& idPair, 
    OdDbObject* pOwnerObject, 
    OdDbIdMapping& ownerIdMap);

  /** 
    Description:
    Called on a new created cloned object to indicate that its Object ID is not valid. 
    
    Remarks:
    The flags are cleared when the OdDbObject::subDeepClone or OdDbObject::subWblockClone() operation *has* been completed.
  */
  void setOdDbObjectIdsInFlux();
  
  /** Description:
      Returns true if and only if this object's Object ID is not valid because
      the OdDbObject::subDeepClone or OdDbObject::subWblockClone() have yet to be completed.
  */
  OdBool isOdDbObjectIdsInFlux() const;
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
    An object is deleted when its reference count reaches 0.

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
    Notification function called whenever a method of the
    specified subobject has called assertWriteEnabled()
    
    Arguments:
    pObject (I) Pointer to the notifying object.
    pSubObj (I) A pointer to the subobject owned by pObject.
    
    Remarks:
    Notification is made upon pObject->close() or pObject->cancel(). 
 
    Note:
    This function is called only for the modification of the following:
       
    o  Vertices of OdDb2dPolylines, OdDb3dPolylines, OdDbPolygonMeshs, and OdDbPolyFaceMeshes
    o  OdDbFaceRecords of OdDbPolyFaceMeshs 
    o  OdDbAttributes owned by OdDbBlockReferences, classes derived from OdDbBlockReference, and OdDbMInsertBlocks
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
  /** PMK:
    Do we need this function?
  */
  
  /**
    Description:
    Returns true if and only if this object is a proxy object or entity.
  */
  OdBool isAProxy() const;  

  /** 
    Description:
    Notification function called immediately before an object is closed.

    Arguments:
    objectId (I) Object ID of the object that is being closed.

    Remarks:
    The default implementation of this function does nothing.  This function can be
    overridden in custom classes.

	Gcad(Modify): OdDbObjectId& -> OdDbObjectId
  */
  virtual void objectClosed(
    const OdDbObjectId objectId);
  
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
    Copies the contents of the specified object into this object when possible.

    Arguments:
    pSource (I) Pointer to the source object.

    Remarks:
    The source object and this object need not be of the same type.  
    This function is meaningful only when implemented by custom classes.
    
    Throws:
    @table
    Exception           Cause
    eNullObjectPointer  pSource->isNull()
  */
  virtual OdResult copyFrom(
    const OdRxObject* pSource);

  /**
    Description:
    Returns true if and only if this object has its
    bit set to override the filer version.
  */     
  bool hasSaveVersionOverride() const;
  
  /**
    Description:
    Controls the flag specifying that this object
    overrides the save filer version.
    
    Arguments:
    hasSaveVersionOverride (I) Has save version override.
               
    Remarks:
    By default, objects are saved in the highest of the your object's birth version and the filer version.
  */     
  void setHasSaveVersionOverride(
    bool hasSaveVersionOverride);
  
  /**
    Description:
    Returns the drawing and maintenance *release* version into which this object must be stored.

    Arguments:
    pFiler (I) Pointer to the DWG/DXF filer to be used.
    pMaintVer (O) Receives the maintenance version. 

    Remarks:
    The default implementation of this function returns filer->dwgVersion().  This function can be
    overridden in custom classes.
    
    Do not use filer->dwgVersion() with dwg/dxf(in/out)Fields(); use self()->getObjectSaveVersion() instead. 
  */
  OdDb::DwgVersion getObjectSaveVersion(
    const OdDbFiler* pFiler,
    OdDb::MaintReleaseVer* pMaintVer = 0) const;
      
  virtual OdResult getObjectSaveVersion(const OdDbDwgFiler* pFiler, 
                                 OdDb::DwgVersion& ver,
                                 OdDb::MaintReleaseVer& maintVer);
  virtual OdResult getObjectSaveVersion(const OdDbDxfFiler* pFiler, 
                                 OdDb::DwgVersion& ver,
                                 OdDb::MaintReleaseVer& maintVer);
          OdResult getObjectBirthVersion(
                                 OdDb::DwgVersion& ver,
                                 OdDb::MaintReleaseVer& maintVer);
  /**
    Description:
    Determines the behavior for custom objects when saving to an earlier version of .dwg or .dxf file. 
    
    Arguments:
    ver (I) Drawing version to save as.
    replaceId (O) Object ID of the object replacing this object.
    exchangeXData (O) Set to true if and only if this function did not add XData to the replacement object.

    Remarks:
    This function either
    
    o Returns an OdDbObjectPtr for a non- *database* -resident (NDBRO) replacement object, setting replaceId to OdDbObjectId::kNull.
    o Returns NULL, setting replaceId for a *database* -resident (DBRO) replacement object.
    
    Custom objects can decompose themselves into other objects, adding additional XData as required. Teigha 
    transfers XData from this object to the replacement object if and only if exchangeXData is true.
    
    The default implementation returns NULL and sets replaceId to OdDbObjectId::kNull.  This function can be
    overridden in custom classes.
  */
  //Gcadt(Modify)
  OdDbObjectPtr decomposeForSave(
    OdDb::DwgVersion ver, 
    OdDbObjectId& replaceId, 
    OdBool& exchangeXData);
  virtual OdResult decomposeForSave(
    OdDb::DwgVersion ver,
    OdDbObject*& replaceObj,
    OdDbObjectId& replaceId,
    OdBool& exchangeXData);
  virtual void composeForLoad(OdDb::SaveFileType format, OdDb::DwgVersion version, OdDbAuditInfo* pAuditInfo);

  /**
    Description:
    Returns a pointer to the OdGiDrawable for the object. If the object doesn't have an associated OdGiDrawable object, this function returns NULL. 
  */
  virtual OdGiDrawable* drawable();

  /**
    Description:
    Sets the values of this object's subentity traits, and returns with the calling object's subentity traits.

    Arguments:
    pTraits (I) Pointer to the OdGiDrawableTraits object to be set.
    
    Remarks:
    When overriding subSetAttributes(), you must OR (|) the return value 
    of <base class>::subSetAttributes(pTraits) with any flags you add. 
    
    A derived class may not remove flags for any reason.
    
    The default implementation does nothing but return kDrawableNone. This function can be
    overridden in custom classes.
  */
  virtual OdUInt32 subSetAttributes(
    OdGiDrawableTraits* pTraits);
  
  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);
  
  virtual void subViewportDraw(
    OdGiViewportDraw* pVd);
  
  /**
    Description:
    Return true if and only if this object is *database* -resident (DBRO).
    
    Remarks:
    Persistent objects belong to an object that must be opened and closed.

    Non-persistent objects can be accessed through their pointers.
  */  
  virtual OdBool isPersistent() const;
  
  /**
    Returns the *database* ID corresponding to this object.
  */
  virtual OdDbObjectId id() const;
    
  /** 
    Description:
    Returns the CLSID value associated with this object.
    
    Arguments:
    pClsid (O) Pointer to the CLSID value.
    
    Remarks:
    Valid only on Windows with Teigha built as a DLL.
  */
  ODRX_SEALED_VIRTUAL OdResult getClassID(CLSID* pClsid) const ODRX_SEALED;

  // Override of OdGiDrawable
  
  /**
    Description:
    Assigns the specified OdGsNode to the calling object.

    Arguments:
    pNode (I) Pointer to the OdGsNode object.
  */
  void setGsNode(OdGsNode* pNode);

  // Override of OdGiDrawable
  
  /**
    Description:
    Returns the OdGsNode of an OdGiDrawable object.
  */
  OdGsNode* gsNode() const;

  /*
    void upgradeFromNotify (bool& wasWritable);
    void downgradeToNotify (bool wasWritable);
    OdResult closeAndPage (bool onlyWhenClean = true);
    virtual void swapReferences (const OdDbIdMapping& idMap);
    virtual OdGiDrawable* drawable ();
    OdDbObjPtrArray* reactors (); 
    virtual OdRxObjectPtr clone (OdDbIdMapping& ownerIdMap) const;
  */
  
  /**
    Description:
    Applies the 3D transformation matrix to the XData of this object.
    
    Arguments:
    xfm (I) 3D transformation matrix.
    
    Remarks:
    Applies the transformation matrix to only the following XData data types:
    
    @table
    Name                Value
    kDxfXdWorldXCoord   1011   
    kDxfXdWorldYCoord   1021   
    kDxfXdWorldZCoord   1031   
    kDxfXdWorldXDisp    1012   
    kDxfXdWorldYDisp    1022   
    kDxfXdWorldZDisp    1032   
    kDxfXdWorldXDir     1013   
    kDxfXdWorldYDir     1023   
    kDxfXdWorldZDir     1033   
    kDxfXdDist          1041   
    kDxfXdScale         1042   
  */
  OdResult xDataTransformBy(
    const OdGeMatrix3d& xfm);

  /** Description:
    Returns true if and only if this object has fields.
  */
  bool hasFields() const;
  
  /** Description:
    Returns, and optionally opens, the specified field object from the field dictionary of this object.
    
    Arguments:
    fieldName (I) Name (key) for the new entry.
    mode (I) Open *mode*.
  */
  OdDbObjectId getField(
    const OdString& fieldName) const;
  OdDbObjectPtr getField(
    const OdString& fieldName, 
    OdDb::OpenMode mode) const;

  OdResult getField(
    const OdChar * fieldName, 
    OdDbObjectId& fieldId) const;
  OdResult getField(
    const OdChar * fieldName,
    OdDbField*& pField,
    OdDb::OpenMode mode) const;
  /** Description:
    Adds the specified field to the field dictionary of this object.
    
    Arguments:
    fieldName (I) Name (key) for the new entry.
    pField (I) Pointer to the field object.
    
    Remarks:
    Returns the Object ID of the new entry.
  */
  OdDbObjectId setFieldInternal(
    const OdString& fieldName, 
    OdDbField* pField);

  OdDbObjectId setField(
    const OdString& fieldName, 
    OdDbField* pField);
  virtual OdResult setField(
    const OdChar* pFieldName, 
    OdDbField* pField,
    OdDbObjectId& fieldId);

  /** Description:
    Removes the specified field from the field dictionary of this object.
    
    Arguments:
    fieldName (I) Name (key) for the entry.
    fieldId (I) Object ID for the field.
    
    Remarks:
    If fieldId is specified, returns eOk if successful, or an appropriate error code if not.
    
    If fieldName is specified, returns the Object ID of the removed field if successful, 
    or a null Object ID if not.
  */
  virtual OdResult removeField(
    OdDbObjectId fieldId);
  OdDbObjectId removeField(
    ODSYSDEF,
    const OdString& fieldName);

  virtual OdResult removeField(
    const OdChar* pFieldName, 
    OdDbObjectId& returnId);
  virtual OdResult removeField(
    const OdChar* pFieldName);
  /** Description:
    Returns, and optionally opens, the field dictionary of this Object.
    Arguments:
    mode (I) Open *mode*.
    Remarks:
  */
  OdDbObjectId getFieldDictionary() const;
  OdDbObjectPtr getFieldDictionary(
    OdDb::OpenMode mode) const;

  OdResult getFieldDictionary(
    OdDbDictionary*& pFieldDict, 
    OdDb::OpenMode mode) const;

  /** Description:
      For Teigha internal use only
  */
  
  /* {Secret} */
  virtual OdRxClass* saveAsClass(
    OdRxClass* pClass) const;

  //internal use only.
  virtual int getUnknown(int type) const;
  virtual void setUnknown(int type, int data);

protected: // overridables
  virtual OdResult subGetClassID(CLSID* pClsid) const;
  virtual OdDbObjectPtr subDeepClone(OdDbIdMapping& ownerIdMap,OdDbObject*) const;
  virtual OdDbObjectPtr subWblockClone(OdDbIdMapping& ownerIdMap,OdDbObject*) const;

  friend class OdDbSystemInternals;
  friend class OdDbObjectOverrule;
  friend class OdDbPropertiesOverrule;
  friend class OdDbObjectImpl;
  OdDbObjectImpl* m_pImpl;
};

/**
  Description:
  This template class is a specialization of the 
  OdSmartPtr class for all objects contained 
  in an OdDbDatabase instance.
*/
typedef OdSmartPtr<OdDbObject> OdDbObjectPtr;


/** Description:
    Returns the data for the specified object.
        
    Arguments:
    id (I) Object ID of the object.
    pObj (I) Pointer to the object.
    regapps (I) Registered application name to retrieve extended data for. 
                May be a wildcard or comma separated list. If empty - no XData is returned.
    
    Remarks:
    Each OdResBuf in the list contains a single DXF group code and data value pertaining 
    to the object.
    
    The object is opened in kForRead mode, and the returned list of data
    is independent of the original object (it may be modified or deleted without 
    affecting the original object).  To affect changes in the original object
    via the returned OdResBuf data, oddbEntMod must be called.

    throws:
    An OdError exception will be thrown if the passed in object cannot be opened.
*/
TOOLKIT_EXPORT OdResBufPtr oddbEntGet( const OdDbObject* pObj, const OdString& regapps = OdString::kEmpty );

// inline OdResBufPtr oddbEntGet( const OdDbObjectId& id );

inline OdResBufPtr oddbEntGet( const OdDbObjectId& id, const OdString& regapps = OdString::kEmpty )
{
  return oddbEntGet(id.safeOpenObject(), regapps);
}


/** Description:
    Sets the data for the specified object.
        
    Arguments:
    id (I) Object ID of the object.
    pObj (I) Pointer to the object.
    
    Remarks:
    Each OdResBuf in the list contains a single DXF group code and data value pertaining 
    to the object.
    
    throws:
    An OdError exception will be thrown if the passed in object cannot be opened in kForWrite
    mode.
*/
TOOLKIT_EXPORT OdResult oddbEntMod( OdDbObject* pObj, OdResBuf* pRb );
// inline void oddbEntMod( const OdDbObjectId& id, OdResBuf* pRb );

inline OdResult oddbEntMod( const OdDbObjectId& id, OdResBuf* pRb )
{
  return oddbEntMod(id.safeOpenObject(OdDb::kForWrite), pRb);
}

TOOLKIT_EXPORT OdDbObjectId oddbEntNext(OdDbObjectId id, OdDbDatabase* db);
TOOLKIT_EXPORT OdDbObjectId oddbEntLast(OdDbDatabase* db);


TOOLKIT_EXPORT OdResult oddbUpgradeOpen(OdDbObject* pObj);

#include "TD_PackPop.h"

#endif //_ODDBXOBJECT_INCLUDED_


