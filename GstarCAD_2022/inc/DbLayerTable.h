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




#ifndef _ODDBLAYERTABLE_INCLUDED
#define _ODDBLAYERTABLE_INCLUDED

#include "TD_PackPush.h"

#include "DbSymbolTable.h"

class OdDbLayerTableRecord;
class OdDbLayerTableIterator;

/** Gcad(Add): 增加 DD 库缺少的 OdDbLayerTableIterator 类
  重新实现兼容的 getRecord() 非虚函数
*/
class TOOLKIT_EXPORT OdDbLayerTableIterator : public OdDbSymbolTableIterator
{
public:
  ODRX_DECLARE_MEMBERS(OdDbLayerTableIterator);

  virtual OdDbSymbolTableRecordPtr getRecord(
    OdDb::OpenMode openMode = OdDb::kForRead,
    bool openErasedRecord = false) const
  {
    return OdDbSymbolTableIterator::getRecord(openMode, openErasedRecord);
  }

  OdResult getRecord(
    OdDbLayerTableRecord*& pRecord,
    OdDb::OpenMode openMode, 
    bool openErasedRec = false) const;

  OdResult seek(OdDbObjectId id);
  OdResult seek(const OdDbLayerTableRecord* pRecord);

  bool getSkipHidden() const;
  void setSkipHidden(bool value);

  bool getSkipReconciled() const;
  void setSkipReconciled(bool value);
protected:
  OdDbLayerTableIterator();
    
  OdDbLayerTableIterator(OdDbSymbolTableIteratorImpl* pImpl);
};

typedef OdSmartPtr<OdDbLayerTableIterator> OdDbLayerTableIteratorPtr;

/** Description:
    This class implements the LayerTable, which represents layers in an OdDbDatabase instance.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbLayerTable: public OdDbSymbolTable
{
public:
  ODDB_DECLARE_MEMBERS(OdDbLayerTable);

  /** Note:
    Teigha applications typically will not use this constructor, insofar as 
    the OdDbDatabase class creates its own instance.
  */
  OdDbLayerTable();
  virtual ~OdDbLayerTable();

  /****************************************
   * Gcad(Add): 新增兼容函数         *
   *--------------------------------------*/
  typedef OdDbLayerTableRecord RecordType;

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
    OdDbLayerTableRecord*& pRec,
    OdDb::OpenMode openMode,
    bool openErasedRec = false) const;

  bool has(const OdChar* name) const;
  bool has(OdDbObjectId id) const;

  virtual OdDbSymbolTableIteratorPtr newIterator( 
    bool atBeginning = true, 
    bool skipDeleted = true) const;

  // 根据基类类似函数重新实现
  OdResult newIterator (
    OdDbLayerTableIterator*& pIterator,
    bool atBeginning = true,
    bool skipDeleted = true) const;

  virtual OdDbObjectId add(
    ODSYSDEFNAME,
    OdDbSymbolTableRecord* pRecord);
  
  OdResult add ( 
    OdDbObjectId& recordId, 
    OdDbLayerTableRecord* pRecord);

  OdResult add ( 
    OdDbLayerTableRecord* pRecord);
  /*--------------------------------------*
   *         finish                       *
   ****************************************/
   
  virtual OdResult subGetClassID(
    CLSID* pClsid) const;


  /** Description:
    Generates usage data for each record in this LayerTable object.
    
    Remarks:
    Usage data can be accessed via the OdDbLayerTableRecord::isInUse() method.
  */
  void generateUsageData();

  bool hasUnreconciledLayers() const;

  OdResult getUnreconciledLayers(OdDbObjectIdArray& idArray) const;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbLayerTable object pointers.
*/
typedef OdSmartPtr<OdDbLayerTable> OdDbLayerTablePtr;

#include "TD_PackPop.h"

// DRX
TOOLKIT_EXPORT OdResult applyCurDwgLayerTableChanges();

#endif // _ODDBLAYERTABLE_INCLUDED

