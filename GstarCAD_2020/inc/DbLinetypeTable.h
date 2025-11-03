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




#ifndef _ODDBLINETYPETABLE_INCLUDED
#define _ODDBLINETYPETABLE_INCLUDED

#include "TD_PackPush.h"

#include "DbSymbolTable.h"

class OdDbLinetypeTableRecord;

/** Description:
    This class implements bidirectional Iterators for OdDbLinetypeTable instances.

    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbLinetypeTableIterator : public OdDbSymbolTableIterator
{
public:
  ODRX_DECLARE_MEMBERS(OdDbLinetypeTableIterator);

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
    OdDbLinetypeTableRecord*& pRecord,
    OdDb::OpenMode openMode, 
    bool openErasedRec = false) const;

  OdResult seek(OdDbObjectId id);
  OdResult seek(const OdDbLinetypeTableRecord* pRecord);

protected:
  OdDbLinetypeTableIterator();

  OdDbLinetypeTableIterator(
    OdDbSymbolTableIteratorImpl* pImpl);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbLinetypeTableIterator object pointers.
*/
typedef OdSmartPtr<OdDbLinetypeTableIterator> OdDbLinetypeTableIteratorPtr;


/** Description:
    This class implements the LinetypeTable, which represents linetypes in an OdDbDatabase instance.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbLinetypeTable : public OdDbSymbolTable
{
public:
  ODDB_DECLARE_MEMBERS(OdDbLinetypeTable);

  /** Note:
    Teigha applications typically will not use this constructor, insofar as 
    the OdDbDatabase class creates its own instance.
  */
  OdDbLinetypeTable();
  virtual ~OdDbLinetypeTable();

  typedef OdDbLinetypeTableRecord RecordType;

  /** Description:
    Searches the LinetypeTable object for the specified SymbolTableRecord.

    Arguments:
    recordName (I) Record name.
    openMode (I) Mode in which to open the record.
    getErasedRecord (I) If and only if true, *erased* records will be opened or retrieved.

    Remarks:
    Returns a SmartPointer to the object if successful, otherwise a null SmartPointer.
  */
  virtual OdDbObjectId getAt(
    const OdChar* recordName, 
    bool getErasedRecord = false) const;

  virtual OdDbSymbolTableRecordPtr getAt(
    const OdChar* recordName,
    OdDb::OpenMode openMode, 
    bool getErasedRecord = false) const;

  /** Gcad(Add): 新增兼容非虚函数
    根据基类类似函数重新实现, 参考基类类似函数的定义
  */
  OdResult getAt(
    const OdChar * recordName,
	OdDbLinetypeTableRecord*& pRec,
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
    Returns true if and only if this LinetypeTable object *has* an record with the specified *name* or Object ID.

    Arguments:
    recordName (I) Record *name*.
    objectId (I) Object ID.

    Gcad(Reserve): 函数保留, 不做修改
  */
  virtual bool has(const OdChar * recordName) const;
  virtual bool has(const OdDbObjectId& objectId) const;

  /** Description:
    Returns an Iterator object that can be used to traverse this LinetypeTable object.

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
    OdDbLinetypeTableIterator*& pIterator,
    bool atBeginning = true,
    bool skipDeleted = true) const;

  /** Description:
    Adds the specified record to this LinetypeTable object.

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
    OdDbLinetypeTableRecord* pRecord);

  OdResult add ( 
    OdDbLinetypeTableRecord* pRecord);


  /** Description:
    Returns the Object ID of the "ByLayer" record within this LinetypeTable object.
  */
  const OdDbObjectId& getLinetypeByLayerId() const;

  /** Description:
    Returns the Object ID of the "ByBlock" record within this LinetypeTable object.
  */
  const OdDbObjectId& getLinetypeByBlockId() const;

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfOut(
    OdDbDxfFiler* pFiler,
    OdBool allXdFlag = kTrue,
    unsigned char* regAppTable = NULL) const;

  /*
    virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
    virtual void dxfOutFields(OdDbDxfFiler* pFiler) const;
  */
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbLinetypeTable object pointers.
*/
typedef OdSmartPtr<OdDbLinetypeTable> OdDbLinetypeTablePtr;

#include "TD_PackPop.h"

#endif // _ODDBLINETYPETABLE_INCLUDED

