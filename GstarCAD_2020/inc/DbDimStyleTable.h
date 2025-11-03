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




#ifndef _ODDBDIMSTYLETABLE_INCLUDED
#define _ODDBDIMSTYLETABLE_INCLUDED

#include "TD_PackPush.h"

#include "DbSymbolTable.h"

class OdDbDimStyleTableRecord;
class OdDbDimStyleTableIterator;

/** Gcad(Add): 增加 DD 库缺少的 OdDbDimStyleTableIterator 类
  重新实现兼容的 getRecord() 非虚函数
*/
class TOOLKIT_EXPORT OdDbDimStyleTableIterator : public OdDbSymbolTableIterator
{
public:
  ODRX_DECLARE_MEMBERS(OdDbDimStyleTableIterator);

  virtual OdDbSymbolTableRecordPtr getRecord(
    OdDb::OpenMode openMode = OdDb::kForRead,
    bool openErasedRecord = false) const
  {
    return OdDbSymbolTableIterator::getRecord(openMode, openErasedRecord);
  }

  OdResult getRecord(
    OdDbDimStyleTableRecord*& pRecord,
    OdDb::OpenMode openMode, 
    bool openErasedRec = false) const;

  OdResult seek(OdDbObjectId id);
  OdResult seek(const OdDbDimStyleTableRecord* pRecord);

protected:
  OdDbDimStyleTableIterator();
    
  OdDbDimStyleTableIterator(
    OdDbSymbolTableIteratorImpl* pImpl);
};

typedef OdSmartPtr<OdDbDimStyleTableIterator> OdDbDimStyleTableIteratorPtr;

/** Description:
    This class implements the DimensionStyleTable, which represents dimension styles in an OdDbDatabase instance.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDimStyleTable: public OdDbSymbolTable
{
public:
  ODDB_DECLARE_MEMBERS(OdDbDimStyleTable);

  /** Note:
    Teigha applications typically will not use this constructor, insofar as 
    the OdDbDatabase class creates its own instance.
  */
  OdDbDimStyleTable();
  virtual ~OdDbDimStyleTable();

  /****************************************
   * Gcad(Add): 新增兼容函数         *
   *--------------------------------------*/
  typedef OdDbDimStyleTableRecord RecordType;

  virtual OdDbSymbolTableRecordPtr getAt(
    const OdChar* recordName,
    OdDb::OpenMode openMode, 
    bool getErasedRecord = false) const
  {
    return OdDbSymbolTable::getAt(recordName, openMode, getErasedRecord);
  }

  virtual OdDbObjectId getAt(
    const OdChar* recordName, 
    bool getErasedRecord = false) const
  {
    return OdDbSymbolTable::getAt(recordName, getErasedRecord);
  }

  OdResult getAt (
    const OdChar * recordName,
    OdDbObjectId& recordId,
    bool getErasedRecord = false) const
  {
    return OdDbSymbolTable::getAt(recordName, recordId, getErasedRecord);
  }

  // 根据基类类似函数重新实现
  OdResult getAt (
    const OdChar * recordName,
    OdDbDimStyleTableRecord*& pRec,
    OdDb::OpenMode openMode,
    bool openErasedRec = false) const;

  bool has(const OdChar* name) const;
  bool has(OdDbObjectId id) const;

  virtual OdDbSymbolTableIteratorPtr newIterator( 
    bool atBeginning = true, 
    bool skipDeleted = true) const;

  // 根据基类类似函数重新实现
  OdResult newIterator (
    OdDbDimStyleTableIterator*& pIterator,
    bool atBeginning = true,
    bool skipDeleted = true) const;

  OdResult add ( 
    OdDbObjectId& recordId, 
    OdDbDimStyleTableRecord* pRecord);

  OdResult add ( 
    OdDbDimStyleTableRecord* pRecord);
  /*--------------------------------------*
   *         finish                       *
   ****************************************/


  /** Description:
    Adds the specified record to this SymbolTable object.

    Arguments:
    pRecord (I) Pointer to the record to add.

    Remarks:
    Returns the Object ID of the newly added record.

    Gcad(Internal): 冲突, 需要调整DD库
  */
  virtual OdDbObjectId add(
    ODSYSDEF,
    OdDbSymbolTableRecord* pRecord);

  /** in & out
  */
  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbDimStyleTable object pointers.
*/
typedef OdSmartPtr<OdDbDimStyleTable> OdDbDimStyleTablePtr;

#include "TD_PackPop.h"

#endif // _ODDBDIMSTYLETABLE_INCLUDED

