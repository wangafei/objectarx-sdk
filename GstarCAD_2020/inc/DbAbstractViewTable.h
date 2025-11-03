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




#ifndef _ODDBABSTRACTVIEWTABLE_INCLUDED
#define _ODDBABSTRACTVIEWTABLE_INCLUDED

#include "DbSymbolTable.h"

class OdDbAbstractViewTableRecord;
class OdDbAbstractViewTableIterator;

/** Gcad(Add): 增加 DD 库缺少的 OdDbAbstractViewTableIterator 类
  重新实现兼容的 getRecord() 非虚函数
*/
class TOOLKIT_EXPORT OdDbAbstractViewTableIterator : public OdDbSymbolTableIterator
{
public:
  ODRX_DECLARE_MEMBERS(OdDbAbstractViewTableIterator);

  virtual OdDbSymbolTableRecordPtr getRecord(
    OdDb::OpenMode openMode = OdDb::kForRead,
    bool openErasedRecord = false) const
  {
    return OdDbSymbolTableIterator::getRecord(openMode, openErasedRecord);
  }

  OdResult getRecord(
    OdDbAbstractViewTableRecord*& pRecord,
    OdDb::OpenMode openMode, 
    bool openErasedRec = false) const;

  OdResult seek(OdDbObjectId id);
  OdResult seek(const OdDbAbstractViewTableRecord* pRecord);

protected:
  OdDbAbstractViewTableIterator();
    
  OdDbAbstractViewTableIterator(
    OdDbSymbolTableIteratorImpl* pImpl);
};

typedef OdSmartPtr<OdDbAbstractViewTableIterator> OdDbAbstractViewTableIteratorPtr;

/** Description:
    This class is the base class for OdDbViewTable and OdDbViewportTable.

    Library:
    TD_Db

    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbAbstractViewTable : public OdDbSymbolTable
{
public:

  ODDB_DECLARE_MEMBERS(OdDbAbstractViewTable);

protected:
  /** Note:
    Teigha applications typically will not use this constructor, insofar as 
    this class is a base class.
  */
  OdDbAbstractViewTable();

public:
  virtual ~OdDbAbstractViewTable();

  /****************************************
   * Gcad(Add): 新增兼容函数         *
   *--------------------------------------*/
  typedef OdDbAbstractViewTableRecord RecordType;

  virtual OdDbSymbolTableRecordPtr getAt(
    const OdChar*recordName,
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
    const OdChar *recordName,
    OdDbObjectId& recordId,
    bool getErasedRecord = false) const
  {
    return OdDbSymbolTable::getAt(recordName, recordId, getErasedRecord);
  }

  // 根据基类类似函数重新实现
  OdResult getAt (
    const OdChar * recordName,
    OdDbAbstractViewTableRecord*& pRec,
    OdDb::OpenMode openMode,
    bool openErasedRec = false) const;

  virtual OdDbSymbolTableIteratorPtr newIterator( 
    bool atBeginning = true, 
    bool skipDeleted = true) const;

  // 根据基类类似函数重新实现
  OdResult newIterator (
    OdDbAbstractViewTableIterator*& pIterator,
    bool atBeginning = true,
    bool skipDeleted = true) const;

  virtual OdDbObjectId add(
    ODSYSDEFNAME,
    OdDbSymbolTableRecord* pRecord)
  {
    return OdDbSymbolTable::add(ODSYSNAME, pRecord);
  }

  OdResult add ( 
    OdDbObjectId& recordId, 
    OdDbAbstractViewTableRecord* pRecord);

  OdResult add ( 
    OdDbAbstractViewTableRecord* pRecord);
  /*--------------------------------------*
   *         finish                       *
   ****************************************/

//  void getAt(const OdChar* entryName, OdDbAbstractViewTableRecord** pRec,
//    OdDb::OpenMode openMode, bool openErasedRec = false) const;

//  OdDbObjectId getAt(const OdChar* entryName, bool getErasedRecord = false) const;

  bool has(const OdChar* name) const;
  bool has(const OdDbObjectId& id) const;

//  void newIterator(OdDbAbstractViewTableIterator** pIterator,
//    bool atBeginning = true, bool skipDeleted = true) const;

//  virtual const OdDbObjectId& add(OdDbSymbolTableRecord* pRecord);

};

#endif // _ODDBABSTRACTVIEWTABLE_INCLUDED

