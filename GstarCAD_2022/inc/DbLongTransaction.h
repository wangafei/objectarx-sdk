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


#ifndef ODDBLONGTRANSWORKSETITERATOR_INCLUDED
#define ODDBLONGTRANSWORKSETITERATOR_INCLUDED

#include "DbObject.h"

/** Description:
    This class implements Iterator objects that traverse OdDbLongTransaction worksets.

    {group:OdDb_Classes} 
*/
class ODRX_ABSTRACT TOOLKIT_EXPORT OdDbLongTransWorkSetIterator : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbLongTransWorkSetIterator);
  
  virtual ~OdDbLongTransWorkSetIterator() {};

  /** Description:
    Sets this Iterator object to reference the entity that it would normally return first.
  
    Arguments:
    incRemovedObjs (I) True to include removed objects.
    incSecondaryObjs (I) True to include secondary objects.
       
    Remarks:
    Allows multiple traversals of the iterator list.
  */  
  virtual void start(
    bool incRemovedObjs = false, 
    bool incSecondaryObjs = false) = 0; 
  
  /** Description:
    Returns true if and only if the traversal by this Iterator object is complete.
  */  
  virtual bool done() = 0;

  /** Description:
    Sets this Iterator object to reference the entity following the current entity.
  */  
  virtual void step() = 0;
  
  /** Description:
    Returns the object ID of the entity currently referenced by this Iterator object.
  */  
  virtual OdDbObjectId objectId() const = 0;
  
  /** Description:
    Returns true if and only if the entity currently referenced by this Iterator object has been erased.
    
    Note:
    The default iterators return only non-erased objects. 
  */  
  virtual bool curObjectIsErased() const = 0;

  /** Description:
    Returns true if and only if the entity currently referenced by this Iterator object has been 
    removed from the work set.

    Note:
    The default iterators return only non-removed objects.
  */  
  virtual bool curObjectIsRemoved() const = 0;

  /** Description:
    Returns true if and only if the entity currently referenced by this Iterator 
    object is a Primary object.

    Remarks:
    Primary objects are in the work set because they have been explicitly added to it.
    
    Non-Primary objects are in the work set only because they are referenced by Primary objects.
    
    Note:
    The default iterators return only Primary objects.
  */  
  virtual bool curObjectIsPrimary() const = 0;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbLongTransWorkSetIterator object pointers.
*/
typedef OdSmartPtr<OdDbLongTransWorkSetIterator> OdDbLongTransWorkSetIteratorPtr;

/** Description:
    This class implements the tracking of long transactions.
    
    Remarks:
    This class creates and appends OdcDbLongTransaction objects to the database and 
    and returns the object ID of the OdDbLongTransaction object. Destruction of the
    OdDbLongTransaction object is handled by the database.

    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbLongTransaction : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbLongTransaction);

  OdDbLongTransaction();
  ~OdDbLongTransaction();//Gcad(Add);

  enum
  {
    kSameDb        = 0, // Entities are checked out from a normal block in the current *database*.
    kXrefDb        = 1, // Entities are checked out from ModelSpace or an Xref dependent block in an Xref *database*.
    kUnrelatedDb   = 2  // Entities are checked out from ModelSpace or a block in an unrelated *database*.
  };
  
  /** Description:
    Returns the *type* of the pending long transaction:
    
    Remarks:
    type will return one of the following
    
    @table
    Name           Value   Description
    kSameDb        0       Entities are checked out from a normal block or layout in the current *database*.
    kXrefDb        1       Entities are checked out from ModelSpace or an Xref dependent block in an Xref *database*.
    kUnrelatedDb   2       Entities are checked out from ModelSpace or a block in an unrelated *database*.
    
  */
  int type() const;
  
  /** Description:
    Returns the object ID of the block from which the entities are cloned.
  */
  OdDbObjectId originBlock() const;

  /** Description:
    Returns the object ID of the block to which the entities are cloned.
  */
  OdDbObjectId destinationBlock() const;
  
  
  /** Description:
    Returns the long transaction name.
    
    Remarks:
    Returns the name of the origin block or layout.
  */
  OdString getLongTransactionName() const;
  OdResult getLongTransactionName(OdChar*&) const;

  /** Description:
    Adds the specified object to the current work set.

    Arguments:
    objectId (I) Object ID to be added.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.   
    
    objectId must be in the same *database* as the the transaction. 
    
    objectId can specify objects from either the origin block or destination block. 
    Objects from the destination block will be cloned; objects from the origin block will not.
  */
  OdResult addToWorkSet(OdDbObjectId ObjectId);
  /** Description:
    Removes the specified object from the current work set.

    Arguments:
    objectId (I) Object ID to be removed.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.   
  */
  OdResult removeFromWorkSet(OdDbObjectId id);
  
  /** Description:
    Synchronizes work set.
    Remarks:
    removeFromWorkSet() does not remove from the work set objects referenced by removed objects. 
    syncWorkSet() removes them.
  */
  OdResult syncWorkSet();
  
  /** Description:
    Creates an Iterator object that provides access to the entities in the work set.
    Arguments:
    incRemovedObjs (I) True to include removed and erased objects from the work set.
    incSecondaryObj (I) True to include objects referenced by objects in the work set.
  */
  OdDbLongTransWorkSetIteratorPtr newWorkSetIterator(
    bool incRemovedObjs = false, 
    bool incSecondaryObjs = false) const;
  
  OdResult newWorkSetIterator(
    OdDbLongTransWorkSetIterator*& pNewIter,
    bool incRemovedObjs = false,
    bool incSecondaryObjs = false) const;

  /** Description:
    Returns the object ID from which the workSetId was cloned.
    Arguments:
    workSetId (I) Work set object ID..
  */
  OdDbObjectId originObject(
    OdDbObjectId workSetId) const;

  /** Description:
    Returns true if and only if the specified object ID is in the work set.
    
    Arguments:
    objectId (I) Object ID being tested.
    getErased (I) True to return true for erased and removed objects in the work set.
  */
  bool workSetHas(
    OdDbObjectId objectId, 
    bool getErased = false) const;
  
  /** Description:
    Returns a pointer to the OdDbMapping object used for OdLongTransationReactor callbacks used for checkin/checkout.
  */
  OdDbIdMapping* activeIdMap();

  //Gcad(Add)
  void  regenWorkSetWithDrawOrder();

  //Gcad(Add)
  bool  disallowDrawOrder();

  OdResult applyPartialUndo(OdDbDwgFiler* pUndoFiler, OdRxClass* pClassObj);
  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  virtual OdResult subErase(OdBool erasing);
};

typedef OdSmartPtr<OdDbLongTransaction> OdDbLongTransactionPtr;

#endif // ODDBLONGTRANSWORKSETITERATOR_INCLUDED
