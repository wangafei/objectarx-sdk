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




#ifndef _ODDBBLOCKTABLE_INCLUDED
#define _ODDBBLOCKTABLE_INCLUDED

#include "TD_PackPush.h"

#include "DbSymbolTable.h"

class OdDbBlockTableRecord;

/** Description:
    This class implements bidirectional Iterator objects that traverse entries in OdDbBlockTable objects in an OdDbDatabase instance.

    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbBlockTableIterator : public OdDbSymbolTableIterator
{
public:
  
  ODRX_DECLARE_MEMBERS(OdDbBlockTableIterator);

  virtual OdDbSymbolTableRecordPtr getRecord(
    OdDb::OpenMode openMode = OdDb::kForRead,
    bool openErasedRecord = false) const
  {
    return OdDbSymbolTableIterator::getRecord(openMode, openErasedRecord);
  }

  /** Gcad(Add): 新增兼容非虚函数
    根据基类类似函数重新实现
  */
  OdResult getRecord(
    OdDbBlockTableRecord*& pRecord,
    OdDb::OpenMode openMode, 
    bool openErasedRec = false) const;

  OdResult seek(OdDbObjectId id);
  OdResult seek(const OdDbBlockTableRecord* pRecord);

protected:

  OdDbBlockTableIterator();
    
  OdDbBlockTableIterator(
    OdDbSymbolTableIteratorImpl* pImpl);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbBlockTableIterator object pointers.
*/
typedef OdSmartPtr<OdDbBlockTableIterator> OdDbBlockTableIteratorPtr;


/** Description:
    This class implements the BlockTable, which represents block definitions in an OdDbDatabase instance.

    Library:
    TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbBlockTable : public OdDbSymbolTable
{
public:
  ODDB_DECLARE_MEMBERS(OdDbBlockTable);

  /** Note:
    Teigha applications typically will not use this constructor, insofar as 
    the OdDbDatabase class creates its own instance.
  */
  OdDbBlockTable();
  virtual ~OdDbBlockTable();

  typedef OdDbBlockTableRecord RecordType;

  /** Description:
    Searches the BlockTable object for the specified SymbolTableRecord.

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

  /** Gcad(Add): 新增兼容非虚函数
    根据基类类似函数重新实现, 参考基类类似函数的定义
  */
  OdResult getAt (
    const OdChar * recordName,
    OdDbBlockTableRecord*& pRec,
    OdDb::OpenMode openMode,
    bool openErasedRec = false) const;

  OdResult getAt (
    const OdChar * recordName,
    OdDbObjectId& recordId,
    bool getErasedRecord = false) const
  { 
    return OdDbSymbolTable::getAt(recordName, recordId, getErasedRecord); 
  }

  /** Description:
    Returns true if and only if this BlockTable object *has* an record with the specified *name* or Object ID.

    Arguments:
    recordName (I) Record *name*.
    objectId (I) Object ID.

    Gcad(Reserve): 
    函数保留, 不做修改，注意验证 const OdDbObjectId& 和 OdDbObjectId 是否可以等价替换
  */
  virtual bool has(const OdChar * recordName) const;
  virtual bool has(const OdDbObjectId& objectId) const;

  /** Description:
    Returns an Iterator object that can be used to traverse this BlockTable object.

    Arguments:
    atBeginning (I) True to start at the beginning, false to start at the end. 
    skipDeleted (I) If and only if true, deleted records are skipped.
  */
  virtual OdDbSymbolTableIteratorPtr newIterator( 
    bool atBeginning = true, 
    bool skipDeleted = true) const;

  /** Gcad(Add): 新增兼容非虚函数
    根据基类类似函数重新实现
  */
  OdResult newIterator(
    OdDbBlockTableIterator*& pIterator,
    bool atBeginning = true,
    bool skipDeleted = true) const;

  /** Description:
    Adds the specified record to this BlockTable object.

    Arguments:
    pRecord (I) Pointer to the record to add.

    Remarks:
    Returns the Object ID of the newly added record.

    Gcad(Internal): 冲突, 需要调整DD库
  */
  virtual OdDbObjectId add(
    ODSYSDEF,
    OdDbSymbolTableRecord* pRecord);

  /** Gcad(Add): 新增兼容非虚函数
    根据基类类似函数重新实现.
  */
  OdResult add ( 
    OdDbObjectId& recordId, 
    OdDbBlockTableRecord* pRecord);

  OdResult add ( 
    OdDbBlockTableRecord* pRecord);

  /** Description:
    Returns the Object ID of the Model Space record within this BlockTable object.
  */
  const OdDbObjectId& getModelSpaceId() const;

  /** Description:
    Returns the Object ID of the PaperSpace record within this BlockTable object.
  */
  const OdDbObjectId& getPaperSpaceId() const;

  /** in & out
  */
  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfIn(OdDbDxfFiler* pFiler);

  virtual OdResult subGetClassID(CLSID* pClsid) const;

  virtual OdResult applyPartialUndo(OdDbDwgFiler* pFiler, OdRxClass* pClass);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbBlockTable object pointers.
*/
typedef OdSmartPtr<OdDbBlockTable> OdDbBlockTablePtr;

#include "TD_PackPop.h"

#endif 

