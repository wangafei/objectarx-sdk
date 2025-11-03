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




#ifndef _ODDBSYMBOLTABLE_INCLUDED
#define _ODDBSYMBOLTABLE_INCLUDED

#include "TD_PackPush.h"

#include "DbObject.h"
#include "DbDatabase.h"

class OdDbSymbolTableRecord;
class OdDbSymbolTableIterator;

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbSymbolTableIterator object pointers.
*/
typedef OdSmartPtr<OdDbSymbolTableIterator> OdDbSymbolTableIteratorPtr;
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbSymbolTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbSymbolTableRecord> OdDbSymbolTableRecordPtr;

/** Description:
    This class implements OdError objects with Result codes of eDuplicateRecordName errors, 
    and the Object IDs of the objects related to the errors.
    
    Library: TD_Db
    {group:Error_Classes} 
*/
class TOOLKIT_EXPORT OdError_DuplicateRecordName : public OdError
{
public:
  /** Arguments:
    existingRecordId (I) Object ID of the existing record.
  */
  OdError_DuplicateRecordName(   
    OdDbObjectId existingRecId);
  /** Description:
    Returns the Object ID of the existing record.
  */
  OdDbObjectId existingRecordId() const;
};

/** Description:
    This class is the base class for all SymbolTable objects in an OdDbDatabase instance.

    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbSymbolTable : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbSymbolTable);
protected:
  /** Note:
    Teigha applications typically will not use this constructor, insofar as 
    this class is a base class.
  */
  OdDbSymbolTable();

public:
  typedef OdDbSymbolTableRecord RecordType;

  virtual ~OdDbSymbolTable();
  
  /** Description:
    Searches the SymbolTable object for the specified SymbolTableRecord.

    Arguments:
    recordName (I) Record name.
    openMode (I) Mode in which to open the record.
    getErasedRecord (I) If and only if true, *erased* records will be opened or retrieved.

    Remarks:
    Returns a SmartPointer to the object if successful, otherwise a null SmartPointer.
  */
  virtual OdDbSymbolTableRecordPtr getAt(
    const OdChar* recordName,
    OdDb::OpenMode openMode, 
    bool getErasedRecord = false) const;

  virtual OdDbObjectId getAt(
    const OdChar* recordName, 
    bool getErasedRecord = false) const;

  OdResult getAt ( // 派生类应该重新实现类似函数
    const OdChar * recordName,
    OdDbSymbolTableRecord*& pRec,
    OdDb::OpenMode openMode,
    bool openErasedRec = false) const;

  OdResult getAt ( // 派生类无需重新实现
    const OdChar * recordName,
    OdDbObjectId& recordId,
    bool getErasedRecord = false) const;
  /** Description:
    Returns true if and only if this SymbolTable object *has* an record with the specified *name* or Object ID.

    Arguments:
    recordName (I) Record *name*.
    objectId (I) Object ID.
  */
  virtual bool has(const OdChar * recordName) const;
  virtual bool has(const OdDbObjectId& objectId) const;

  /** Description:
    Returns an Iterator object that can be used to traverse this SymbolTable object.

    Arguments:
    atBeginning (I) True to start at the beginning, false to start at the end. 
    skipDeleted (I) If and only if true, deleted records are skipped.
  */
  virtual OdDbSymbolTableIteratorPtr newIterator( 
    bool atBeginning = true, 
    bool skipDeleted = true) const;

  OdResult newIterator ( // 派生类应该重新实现类似函数
    OdDbSymbolTableIterator*& pIterator,
    bool atBeginning = true,
    bool skipDeleted = true) const;
  /** Description:
    Adds the specified record to this SymbolTable object.

    Arguments:
    pRecord (I) Pointer to the record to add.

    Remarks:
    Returns the Object ID of the newly added record.
  */
  virtual OdDbObjectId add(
    ODSYSDEF,
    OdDbSymbolTableRecord* pRecord);

  OdResult add ( // 派生类应该重新实现
    OdDbObjectId& recordId, 
    OdDbSymbolTableRecord* pRecord);

  OdResult add ( // 派生类无需重新实现
    OdDbSymbolTableRecord* pRecord);
  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfIn(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOut(
    OdDbDxfFiler* pFiler,
    OdBool allXdFlag = kTrue,
    unsigned char* regAppTable = NULL) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbSymbolTable object pointers.
*/
typedef OdSmartPtr<OdDbSymbolTable> OdDbSymbolTablePtr;

class OdDbSymbolTableIteratorImpl;

/** Description:
    This class implements bidirectional Iterators for OdDbSymbolTable objects in an OdDbDatabase instance.

    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbSymbolTableIterator : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbSymbolTableIterator);

  /** Description:
    Sets this Iterator object to reference the SymbolTableRecord that it would normally return first.
     
    Remarks:
    Allows multiple traversals of the iterator list.

    Arguments:
    atBeginning (I) True to start at the beginning, false to start at the end. 
    skipErased (I) If and only if true, *erased* records are skipped.
  */  
  virtual void start(
    bool atBeginning = true, 
    bool skipErased = true);

  /** Description:
    Returns true if and only if the traversal by this Iterator object is complete.
  */  
  virtual bool done() const;

  /** Description:
    Returns the Object ID of the record currently referenced by this Iterator object.
  */
  virtual OdDbObjectId getRecordId() const;

  /** Description:
    Opens the record currently referenced by this Iterator object.

    Arguments:
    openMode (I) Mode in which to open the record.
    openErasedRecord (I) If and only if true, *erased* records will be opened.

    Remarks:
    Returns a SmartPointer to the opened record if successful, otherwise a null SmartPointer.
  */
  virtual OdDbSymbolTableRecordPtr getRecord(
    OdDb::OpenMode openMode = OdDb::kForRead,
    bool openErasedRecord = false) const;

  OdResult getRecordId ( // 派生类无需重新实现
    OdDbObjectId& id) const;

  OdResult getRecord (   // 派生类应该重新实现类似函数(using)
    OdDbSymbolTableRecord*& pRecord,
    OdDb::OpenMode openMode,
    bool openErasedRec = false) const;
  /** Description:
    Steps this Iterator object.

    Arguments:
    forward (I) True to step *forward*, false to step backward.
    skipErased (I) If and only if true, *erased* records are skipped.
  */
  virtual void step(
    bool forward = true, 
    bool skipErased = true);

  /** Description:
    Positions this Iterator object at the specified record.
    Arguments:
    objectId (I) Object ID of the record.
    pRecord (I) Pointer to the record.
  */  
  OdResult seek(
    const OdDbObjectId& ObjectId);
  OdResult seek( // 对象指针支持向下转换，因此无需重新实现
    const OdDbSymbolTableRecord* pRecord);

  virtual ~OdDbSymbolTableIterator();
protected:
  friend class OdDbSymbolTable;

  OdDbSymbolTableIterator();
  OdDbSymbolTableIterator(
    OdDbSymbolTableIteratorImpl* pImpl);

  OdDbSymbolTableIteratorImpl* m_pImpl;
};

#include "TD_PackPop.h"

#endif // _ODDBSYMBOLTABLE_INCLUDED

