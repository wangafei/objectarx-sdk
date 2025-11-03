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




#ifndef ODDBBLOCKITERATOR_H
#define ODDBBLOCKITERATOR_H

#include "RxObject.h"
#include "OdArrayPreDef.h"

class OdDbObjectId;
class OdDbFilter;
class OdDbBlockTableRecord;
class OdDbBlockIterator;
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbBlockIterator object pointers.
*/
typedef OdSmartPtr<OdDbBlockIterator> OdDbBlockIteratorPtr;

/** Description:
    This class implements Iterator objects that traverse entries in OdDbBlockTableRecord objects in an OdDbDatabase instance.
  
    Remarks:
    Instances are returned by OdDbBlockTableRecord::newIterator().

    {group:OdDb_Classes}
*/
class  TOOLKIT_EXPORT OdDbBlockIterator : public OdRxObject
{
protected: 
  OdDbBlockIterator() {}
public:
  ODRX_DECLARE_MEMBERS(OdDbBlockIterator);
  
  /** Description:
    Sets this Iterator object to reference the OdDbBlock that it would normally return first.
     
    Remarks:
    Allows multiple traversals of the Iterator list.

    Gcad(Modify): returns:void->OdResult
  */  
  virtual OdResult start() = 0;
  
  /** Description:
    Returns the Object ID of the next object, and increments this Iterator object.
  */
  virtual OdDbObjectId next() = 0;
  
  /** Description:
    Returns the Object ID of the record currently referenced by this Iterator object.
  */
  virtual OdDbObjectId id() const = 0;
  
  /** Description:
    Positions this Iterator object at the specified record.
    Arguments:
    objectId (I) Object ID of the record.
    Remarks:
    Returns true if and only if successful.

    Gcad(Modify): returns:bool->OdResult
  */  
  virtual OdResult seek(
    OdDbObjectId objectId) = 0;

 /** Description:
    Returns an Iterator object that can be used to traverse the specified Block Table Record.

    Arguments:
    pBtr (I) Pointer the Block Table Record to traverse.
  */
  static OdDbBlockIteratorPtr newBlockIterator(
    const OdDbBlockTableRecord* pBtr);

 /** Description:
    Returns an Iterator object that can be used to traverse queries defined by OdDbFilter objects 
    applied to the specified Block Table Record.

    Arguments:
    pBtr (I) Pointer the Block Table Record to traverse.
    pFilter (I) Pointer to the filter.
  */
  static OdDbBlockIteratorPtr newFilteredIterator(
      const OdDbBlockTableRecord* pBtr, 
      const OdDbFilter* pFilter);

 /** Description:
    Returns an Iterator object that can be used to traverse queries defined by an 
    array of OdDbFilter objects 
    applied to the specified Block Table Record.

    Arguments:
    pBtr (I) Pointer the Block Table Record to traverse.
    filters (I) Array of pointers to filter objects.
  */
  static OdDbBlockIteratorPtr newCompositeIterator(
      const OdDbBlockTableRecord* pBtr, 
      const OdArray<OdSmartPtr<OdDbFilter> >& filters);

  virtual void addRef(){}
  virtual void release(){}
};
/** Description:
  This class implements Iterator objects that traverse queries defined by OdDbFilter objects 
  on Block Table Records.

  Library:
  TD_Db

  Remarks:
  This class is used by OdDbCompositeFilteredBlockIterator.
  {group:OdDb_Classes}
*/
class  TOOLKIT_EXPORT OdDbFilteredBlockIterator : public OdDbBlockIterator
{
protected: 
  OdDbFilteredBlockIterator() {}
public:
  ODRX_DECLARE_MEMBERS(OdDbFilteredBlockIterator);
  
  virtual ~OdDbFilteredBlockIterator() {}

  virtual OdResult start() = 0;
  virtual OdDbObjectId next() = 0;
  virtual OdDbObjectId id() const = 0;
  virtual OdResult seek(OdDbObjectId id) = 0;

  /** Description:
    Returns the estimated fraction [0.0 .. 1.0] of the contents that will
    be selected by the OdDbFilter query.  
    
    Remarks:
    Used to order the OdDbFilteredBlockIterator objects during a block traversal.
    
    o  0.0 forces the iterator to be used first.
    o  1.0 forces the iterator to be used last. 

    The filters with the fewest hits will be applied first.     
  */
  virtual double estimatedHitFraction() const = 0;
  
  /** Description:
    Returns true if and only if specified object passes the OdDbFilter query.
    
    Arguments:
    objectId (I) Object ID of the entity to be tested.
  */

  /** Gcad(Add): 添加兼容函数接口
  */
  virtual OdResult accepts(
    OdDbObjectId objectId, 
    OdBool& idPassesFilter) const = 0;

  /** Description:
    Returns true if and only if the Index iterator, when not the primary iterator,
    is to buffer its output.
    
    Remarks:
    When false, only the first index/filter pair is traversed, with subsequent pairs
    queried via accepts().

    If true, after all the IDs from the previous  
    iterator have been added to the buffer, the start(), next() and id() of this iterator are be used
    iterate through the data.
  */  
  virtual OdBool buffersForComposition() const;
  
  /** Description:
    Adds the specified Object ID to the buffer of an Index iterator.
    
    Arguments:
    objectId (I) Object ID of the entity to be added.
    
    See Also:
    buffersForComposition    

    Gcad(Modify): returns:void->OdResult
  */
  virtual OdResult addToBuffer(
    OdDbObjectId objectId);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbFilteredBlockIterator object pointers.
*/
typedef OdSmartPtr<OdDbFilteredBlockIterator> OdDbFilteredBlockIteratorPtr;


#endif // ODDBBLOCKITERATOR_H

