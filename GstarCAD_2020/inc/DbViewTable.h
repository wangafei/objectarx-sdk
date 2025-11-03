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




#ifndef _ODDBVIEWTABLE_INCLUDED
#define _ODDBVIEWTABLE_INCLUDED

#include "TD_PackPush.h"

#include "DbAbstractViewTable.h"

class OdDbViewTableRecord;
class OdDbViewTableIterator;

class TOOLKIT_EXPORT OdDbViewTableIterator : public OdDbAbstractViewTableIterator
{
public:
  ODRX_DECLARE_MEMBERS(OdDbViewTableIterator);

  virtual OdDbSymbolTableRecordPtr getRecord(
    OdDb::OpenMode openMode = OdDb::kForRead,
    bool openErasedRecord = false) const
  {
    return OdDbAbstractViewTableIterator::getRecord(openMode, openErasedRecord);
  }

  OdResult getRecord(
    OdDbViewTableRecord*& pRecord,
    OdDb::OpenMode openMode, 
    bool openErasedRec = false) const;

  OdResult seek(OdDbObjectId id);
  OdResult seek(const OdDbViewTableRecord* pRecord);

protected:
  OdDbViewTableIterator();
    
  OdDbViewTableIterator(
    OdDbSymbolTableIteratorImpl* pImpl);
};

typedef OdSmartPtr<OdDbViewTableIterator> OdDbViewTableIteratorPtr;

/** Description:
    This class implements the ViewTable, which represents stored views in an OdDbDatabase instance.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbViewTable: public OdDbAbstractViewTable
{
public:
  ODDB_DECLARE_MEMBERS(OdDbViewTable);

  /** Note:
    Teigha applications typically will not use this constructor, insofar as 
    this class is a base class.
  */
  OdDbViewTable();
  virtual ~OdDbViewTable();

  typedef OdDbViewTableRecord RecordType;

  virtual OdDbSymbolTableRecordPtr getAt(
    const OdChar* recordName,
    OdDb::OpenMode openMode, 
    bool getErasedRecord = false) const
  {
    return OdDbAbstractViewTable::getAt(recordName, openMode, getErasedRecord);
  }

  virtual OdDbObjectId getAt(
    const OdChar* recordName, 
    bool getErasedRecord = false) const
  {
    return OdDbAbstractViewTable::getAt(recordName, getErasedRecord);
  }

  OdResult getAt (
    const OdChar * recordName,
    OdDbObjectId& recordId,
    bool getErasedRecord = false) const
  {
    return OdDbAbstractViewTable::getAt(recordName, recordId, getErasedRecord);
  }

  // 根据基类类似函数重新实现
  OdResult getAt (
    const OdChar * recordName,
    OdDbViewTableRecord*& pRec,
    OdDb::OpenMode openMode,
    bool openErasedRec = false) const;

  bool has(const OdChar* name) const;
  bool has(OdDbObjectId id) const;

  virtual OdDbSymbolTableIteratorPtr newIterator( 
    bool atBeginning = true, 
    bool skipDeleted = true) const;

  // 根据基类类似函数重新实现
  OdResult newIterator (
    OdDbViewTableIterator*& pIterator,
    bool atBeginning = true,
    bool skipDeleted = true) const;

  virtual OdDbObjectId add(
    ODSYSDEFNAME,
    OdDbSymbolTableRecord* pRecord)
  {
    return OdDbAbstractViewTable::add(ODSYSNAME, pRecord);
  }

  OdResult add ( 
    OdDbObjectId& recordId, 
    OdDbViewTableRecord* pRecord);

  OdResult add ( 
    OdDbViewTableRecord* pRecord);
  virtual OdResult subGetClassID(
    CLSID* pClsid) const;
};
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbViewTable object pointers.
*/
typedef OdSmartPtr<OdDbViewTable> OdDbViewTablePtr;

#include "TD_PackPop.h"

#endif // _ODDBVIEWTABLE_INCLUDED

