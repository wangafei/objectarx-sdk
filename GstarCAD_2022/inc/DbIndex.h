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




#ifndef OD_DBINDEX_H
#define OD_DBINDEX_H

#include "TD_PackPush.h"

class OdDbDate;
class OdDbIndexIterator; 
class OdDbFilter;
class OdDbIndexUpdateData;
class OdDbBlockChangeIterator;
class OdDbBlockTableRecord;
class OdDbBlockChangeIteratorImpl;
class OdDbIndexUpdateDataImpl;
class OdDbIndexUpdateDataIteratorImpl;
class OdDbFilteredBlockIterator;

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbFilteredBlockIterator object pointers.
*/
typedef OdSmartPtr<OdDbFilteredBlockIterator> OdDbFilteredBlockIteratorPtr;

#include "DbFilter.h"

//Gcad(Modify): void->OdResult
extern OdResult processBTRIndexObjects(
  OdDbBlockTableRecord* pBlock, 
  int indexCtlVal,
  OdDbBlockChangeIterator* pBlkChgIter,
  OdDbIndexUpdateData* pIdxUpdData);


/** Description:
    This class iterates through changed entities in an OdDbBlockTableRecord instance.
    
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbBlockChangeIterator
{
private:
  friend class OdDbBlockChangeIteratorImpl;
  OdDbBlockChangeIteratorImpl* m_pImpl;
  OdDbBlockChangeIterator() : m_pImpl(0) {}
  OdDbBlockChangeIterator(
    const OdDbBlockChangeIterator&);
public:

  /** Description:
    Sets this Iterator object to reference the entity that it would normally return first.
     
    Remarks:
    Allows multiple traversals of the iterator list.
  */  
  void start();

  /** Description:
    Returns the Object ID of the entity currently referenced by this Iterator object.
  */  
  OdDbObjectId id() const;
  
  /** Description:
    Sets this Iterator object to reference the entity following the current entity.
  */  
  void next();

  /** Description:
    Returns true if and only if the traversal by this Iterator object is complete.
  */  
  bool done(); 
  
  /** Description:
    Returns the Object ID of the entity currently referenced by this Iterator object, 
    and the *flags* and *data* associated with it.
    
    Arguments:
    currentId (O) Receives the current Object ID.
    flags (O) Receives the 8-bit *flags*.
    data (O) Receives the 32-bit *data*

    Gcad(Modify): returns:void->OdResult
  */  
  OdResult curIdInfo(
    OdDbObjectId& currentId, 
    OdUInt8& flags, 
    OdUInt32& data) const;
    
  /** Description:
    Sets the *flags* and *data* associated with the object currently referenced by this Iterator object.
    
    Arguments:
    flags (I) Current object 8-bit *flags*.
    data (I) Current object 32-bit *data*

    Gcad(Modify): returns:void->OdResult
  */  
  OdResult setCurIdInfo(
    OdUInt8 flags, 
    OdUInt32 data);
  
  /** Description:
    Returns the OdDbIndexUpdateData object associating Object IDs to *data* and *flags*. 
  */
  OdDbIndexUpdateData* updateData() const;
  
  /** Description:
    Clears the processed bit (0x04) of the flags of entities being traversed.
  */
  void clearProcessedFlags();
};

/** Description:
    This class associates Index specific flags and data with an OdDbObjectId. 
    
    Library:
    TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbIndexUpdateData 
{
  friend class OdDbIndexUpdateDataImpl;
  OdDbIndexUpdateDataImpl* m_pImpl;
  OdDbIndexUpdateData() : m_pImpl(0) {}
  OdDbIndexUpdateData(
    const OdDbIndexUpdateData&);
public:
  enum UpdateFlags 
  { 
    kModified   = 1, // Modified RO
    kDeleted    = 2, // Deleted RO
    kProcessed  = 4, // Processed RW
    kUnknownKey = 8  // Unknown key
  };
  /** Description:
    Returns the Object ID of the OdDbBlockTableRecord instance that owns this OdDbIndexUpdateData object.
  */
  OdDbObjectId objectBeingIndexedId() const;

  
  /** Description:
    Adds the specified Object ID to this OdDbIndexUpdateData object.

    Arguments:
    Object ID (I) Object ID to be added.

    Gcad(Modify): returns:void->OdResult
  */
  OdResult addId(
    OdDbObjectId objectId);
  
  /** Description:
    Sets the *flags* associated with the specified Object ID in this OdDbIndexUpdateData object.
    
    Arguments:
    objectID (I) Object ID.
    flags (I) 8-bit *flags*.
    
    Remarks:
    Returns true if and only if successful.

    Gcad(Modify): returns:bool->OdResult
  */
  OdResult setIdFlags(
	  OdDbObjectId objectId, 
	  OdUInt8 flags);

  /** Description:
    Sets the *data* associated with the specified Object ID in this OdDbIndexUpdateData object.
    
    Arguments:
    objectID (I) Object ID.
    data (I) 32-bit *data*.
    
    Remarks:
    Returns true if and only if successful.

    Gcad(Modify): returns:bool->OdResult
  */
  OdResult setIdData(
    OdDbObjectId objectId, 
    OdUInt32 data);

  /** Description:
    Returns the *data* associated with the specified Object ID in this OdDbIndexUpdateData object.
    
    Arguments:
    objectID (I) Object ID.
    data (O) 32-bit *data*.
    
    Remarks:
    Returns true if and only if successful.

    Gcad(Modify): returns:bool->OdResult
  */
  OdResult getIdData(
    OdDbObjectId objectId, 
    OdUInt32& data) const;

  /** Description:
    Returns the *flags* associated with the specified Object ID in this OdDbIndexUpdateData object.
    
    Arguments:
    objectID (I) Object ID.
    flags (O) Receives the 8-bit *flags*.
    
    Remarks:
    Returns true if and only if successful.

    Gcad(Modify): returns:bool->OdResult
  */
  OdResult getIdFlags( 
    OdDbObjectId objectId, 
    OdUInt8& flags) const; 

  /** Description:
    Returns the *flags* and *data* associated with the specified Object ID in this OdDbIndexUpdateData object.
    
    Arguments:
    objectID (I) Object ID.
    flags (O) Receives the 8-bit *flags*.
    data (O) Receives the 32-bit *data*.
    
    Remarks:
    Returns true if and only if successful.

    Gcad(Modify): returns:bool->OdResult
  */
  OdResult getFlagsAndData( 
    OdDbObjectId objectId, 
    OdUInt8& flags, 
    OdUInt32& data) const;
};

/** Description:
    This class iterates through OdDbIndexUpdateData instances.    

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
// Gcad(TODO): OdDbIndexUpdateDataIterator好像仅定义，还未实现
class TOOLKIT_EXPORT OdDbIndexUpdateDataIterator
{
  friend class OdDbIndexUpdateDataIteratorImpl;
  OdDbIndexUpdateDataIteratorImpl* m_pImpl;

public:
  OdDbIndexUpdateDataIterator(
    const OdDbIndexUpdateData* pIndexUpdateData);

  ~OdDbIndexUpdateDataIterator();
  
  /** Description:
    Sets this Iterator object to reference the entity that it would normally return first.
     
    Remarks:
    Allows multiple traversals of the iterator list.
  */  
  void start();

  /** Description:
    Returns the Object ID of the entity currently referenced by this Iterator object.
  */  
  OdDbObjectId id() const;
  
 /** Description:
    Sets this Iterator object to reference the entity following the current entity.
  */  
  void next();

  /** Description:
    Returns true if and only if the traversal by this Iterator object is complete.
  */  
  bool done(); 
  
  /** Description:
    Returns the Object ID of the entity currently referenced by this Iterator object, 
    and the *flags* and *data* associated with it.
    
    Arguments:
    currentId (O) Receives the current Object ID.
    flags (O) Receives the 8-bit *flags*.
    data (O) Receives the 32-bit *data*

    Gcad(Modify): returns:void->OdResult
  */  
  OdResult currentData(
    OdDbObjectId& currentId, 
    OdUInt8& flags, 
    OdUInt32& data) const;
};


/** Description:
    The class is the base class for all OdDb Index objects.

    Library:
    TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbIndex : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbIndex);

  OdDbIndex();
  virtual ~OdDbIndex();
  
  /** Description:
    Creates an Iterator object that provides access to the entities in this Index object.
    
    Arguments:
    pFilter (I) Pointer to the filter to be applied to this Index object.

    Gcad(Internal): 修改函数接口为内部函数
    隐藏模式, 隐藏函数, 仅内部使用
  */ 
  OdDbFilteredBlockIteratorPtr newIterator(
    ODSYSDEF,
    const OdDbFilter* pFilter) const;

  /** Gcad(Add): 增加兼容函数接口
    封装模式, 虚函数, 参数须一致, 仅DRX派生类可选择重载
  */
  virtual OdDbFilteredBlockIterator* newIterator(
    const OdDbFilter* pFilter) const;
 
  /** Description:
    Fully rebuilds this Index object from the entities in the block table record object.
    Arguments:
    pIdxData (I) Pointer to the OdDbIndexUpdateData object to be used in the rebuild. 

    Gcad(Modify): returns:void->OdResult
  */ 
  virtual OdResult rebuildFull(
    OdDbIndexUpdateData* pIdxData);

  /** Gcad(TODO): DD 定义在 OdDbIndexUpdateData*/
  virtual OdDbObjectId objectBeingIndexedId() const{return OdDbObjectId();};

  /** Description:
    Sets the Julian *lastUpdatedAt* timestamp for this Index object.
    
    Arguments:
    time (I) Julian date.
  */
  void setLastUpdatedAt(
    const OdDbDate& time);
    
  /** Description:
    Returns the Julian *lastUpdatedAt* timestamp for this Index object.
  */
  OdDbDate lastUpdatedAt() const;
  
  /** Description:
    Sets the UT *lastUpdatedAt* timestamp for this Index object.
    
    Arguments:
    time (I) UT date.
  */
  void setLastUpdatedAtU(
    const OdDbDate& time);
    
  /** Description:
    Returns the UT *lastUpdatedAt* timestamp for this Index object.
  */
  OdDbDate lastUpdatedAtU() const;
  
  /** Description:
    Returns true if and only if this Index object is up to date.
  */
  OdBool isUptoDate() const; 
  
  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields( // Gcad(Modify)
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields( // Gcad(Modify)
    OdDbDxfFiler* pFiler) const;

protected:
 
  /** Description:
    Called by OdDbIndexFilterManager::updateIndexes() when only modifications are being registered. 

    Arguments:
    iterator (I) Iterator of *modified* entities.
    
    Remarks:
    Modified entities includes added, deleted, and changed entities.
    
    Note:
    This class must be implemented in custom classes derived from OdDbIndex. A full rebuild may be performed if desired.

    Gcad(Modify): returns:void->OdResult
  */
  virtual OdResult rebuildModified(
    OdDbBlockChangeIterator* iterator);
  
  friend class OdDbIndexImpl;
  friend OdResult processBTRIndexObjects(
    OdDbBlockTableRecord* pBTR, 
    int indexCtlVal, 
    OdDbBlockChangeIterator* pBlkChgIter, 
    OdDbIndexUpdateData* pIdxUpdData );
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbIndex object pointers.
*/
typedef OdSmartPtr<OdDbIndex> OdDbIndexPtr;

class OdDbBlockTableRecord;
class OdDbBlockReference;

/** Description:
    This namespace provides functions pertaining to indices and filters.
    
    Library:
    TD_Db
    
    {group:TD_Namespaces}
*/
namespace OdDbIndexFilterManager
{
  /** Description:
    Updates all Index objects associated with all block table record objects in the specified
    OdDbDatabase object.
    
    Arguments:
    pDb (I) Pointer to the *database* object.

    Gcad(Modify): returns:void->OdResult
  */
  TOOLKIT_EXPORT OdResult updateIndexes(
    OdDbDatabase* pDb);
  
  /** Description:
    Adds the specified Index object to the specified block table record object.
    
    Arguments:
    pBTR (I) Pointer to the block table record object.
    pIndex (I) Pointer to the Index object.
    
    Remarks:
    An *index* of the same OdRxClass as the specified *index* will be deleted.

    Gcad(Modify): returns:void->OdResult
  */
  TOOLKIT_EXPORT OdResult addIndex(
    OdDbBlockTableRecord* pBTR, 
    OdDbIndex* pIndex);
  
  /** Description:
    Removes the specified Index object from the specified block table record object.
    
    Arguments:
    pBTR (I) Pointer to the Block Table Record.
    key (I) Class descriptor to specify the *index*.

    Gcad(Modify): returns:void->OdResult
  */
  TOOLKIT_EXPORT OdResult removeIndex(
    OdDbBlockTableRecord* pBTR, 
    const OdRxClass* key);

  
  /** Description:
    Returns the specified Index object.
    
    Arguments:
    pBTR (I) Pointer to the block table record object.
    key (I) Class descriptor to specify the *index* object.
    readOrWrite (I) Mode in which to open the *index* object.
  */
  TOOLKIT_EXPORT OdDbIndexPtr getIndex(
    const OdDbBlockTableRecord* pBTR, 
    const OdRxClass* key, 
    OdDb::OpenMode readOrWrite = OdDb::kForRead);

  /** Gcad(Add): 增加兼容函数接口
  */
  TOOLKIT_EXPORT OdResult getIndex( 
	  const OdDbBlockTableRecord* pBTR,
	  const OdRxClass* key,
	  OdDb::OpenMode readOrWrite,
	  OdDbIndex*& pIndex);

  /** 
    Arguments:
    btrIndex (I) Position of the Index object within the block table record object.
  */  
  TOOLKIT_EXPORT OdDbIndexPtr getIndex(
    const OdDbBlockTableRecord* pBTR, 
    int btrIndex, 
    OdDb::OpenMode readOrWrite = OdDb::kForRead);

  /** Gcad(Add): 增加兼容函数接口
  */
  TOOLKIT_EXPORT OdResult getIndex(
	  const OdDbBlockTableRecord* pBTR,
	  int btrIndex,
	  OdDb::OpenMode readOrWrite,
	  OdDbIndex*& pIndex);
  
  /** Description:
    Returns the number of indices associated with the block table record object.
    
    Arguments:
    pBTR (I) Pointer to the block table record object.
  */
  TOOLKIT_EXPORT int numIndexes(
    const OdDbBlockTableRecord* pBTR);
  
  /** Description:
    Adds the specified Filter object to the specified block reference entity.
    
    Arguments:
    pBlkRef (I) Pointer to the block reference entity.
    pFilter (I) Pointer to the Filter object.
    
    Remarks:
    An filter of the same OdRxClass as the specified filter will be deleted.

    Gcad(Modify): returns:void->OdResult
  */
  TOOLKIT_EXPORT OdResult addFilter(
    OdDbBlockReference* pBlkRef, 
    OdDbFilter* pFilter);
  
  /** Description:
    Removes the specified Filter object from the specified block reference entity.
    
    Arguments:
    pBlkRef (I) Pointer to the block reference entity.
    key (I) Class descriptor to specify the filter.

    Gcad(Modify): returns:void->OdResult
  */
  TOOLKIT_EXPORT OdResult removeFilter(
    OdDbBlockReference* pBlkRef, 
    const OdRxClass* key);
  
  /** Description:
    Returns the specified Filter object.
    
    Arguments:
    pBlkRef (I) Pointer to the block reference entity.
    key (I) Class descriptor to specify the filter object.
    readOrWrite (I) Mode in which to open the filter object.
  */
  TOOLKIT_EXPORT OdDbFilterPtr getFilter(
    const OdDbBlockReference* pBlkRef, 
    const OdRxClass* key, 
    OdDb::OpenMode readOrWrite);

  /** Gcad(Add): 增加兼容函数接口
  */
  TOOLKIT_EXPORT OdResult getFilter(
	  const OdDbBlockReference* pBlkRef,
	  const OdRxClass* key,
	  OdDb::OpenMode readOrWrite,
	  OdDbFilter*& pFilter);
  
  /** 
    Arguments:
    btrIndex (I) Position of the Index object within the block table record object.
  */  
  TOOLKIT_EXPORT OdDbFilterPtr getFilter(
    const OdDbBlockReference* pBlkRef, 
    int btrIndex, 
    OdDb::OpenMode readOrWrite);

  /** Gcad(Add): 增加兼容函数接口
  */
  TOOLKIT_EXPORT OdResult getFilter(
    const OdDbBlockReference* pBlkRef, 
    int btrIndex, 
    OdDb::OpenMode readOrWrite,
	OdDbFilter*& pFilter);
  
  /** Description:
    Returns the number of indices associated with the block reference entity.
    
    Arguments:
    pBlkRef (I) Pointer to the block reference entity.
  */
  TOOLKIT_EXPORT int numFilters(
    const OdDbBlockReference* pBlkRef);
}

#include "TD_PackPop.h"

#endif // OD_DBINDEX_H

