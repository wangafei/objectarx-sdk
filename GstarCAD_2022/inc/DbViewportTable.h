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




#ifndef _ODDBVIEWPORTTABLE_INCLUDED
#define _ODDBVIEWPORTTABLE_INCLUDED

#include "TD_PackPush.h"

#include "DbAbstractViewTable.h"

class OdDbViewportTableRecord;
class OdDbViewportTableIterator;

class TOOLKIT_EXPORT OdDbViewportTableIterator : public OdDbAbstractViewTableIterator
{
public:
  ODRX_DECLARE_MEMBERS(OdDbViewportTableIterator);

  virtual OdDbSymbolTableRecordPtr getRecord(
    OdDb::OpenMode openMode = OdDb::kForRead,
    bool openErasedRecord = false) const
  {
    return OdDbAbstractViewTableIterator::getRecord(openMode, openErasedRecord);
  }

  OdResult getRecord(
    OdDbViewportTableRecord*& pRecord,
    OdDb::OpenMode openMode, 
    bool openErasedRec = false) const;

  OdResult seek(OdDbObjectId id);
  OdResult seek(const OdDbViewportTableRecord* pRecord);

protected:
  OdDbViewportTableIterator();
    
  OdDbViewportTableIterator(
    OdDbSymbolTableIteratorImpl* pImpl);
};

typedef OdSmartPtr<OdDbViewportTableIterator> OdDbViewportTableIteratorPtr;

/** Description:
    This class implements the ViewportTable, which represents tiled viewports in an OdDbDatabase instance.

    Library:
    TD_Db

    Note:
    Do not derive from this class.
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbViewportTable: public OdDbAbstractViewTable
{
public:
  ODDB_DECLARE_MEMBERS(OdDbViewportTable);

  /** Note:
    Teigha applications typically will not use this constructor, insofar as 
    this class is a base class.
  */
  OdDbViewportTable();
  virtual ~OdDbViewportTable();

  /****************************************
   * Gcad(Add): 新增兼容函数         *
   *--------------------------------------*/
  typedef OdDbViewportTableRecord RecordType;

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
    OdDbViewportTableRecord*& pRec,
    OdDb::OpenMode openMode,
    bool openErasedRec = false) const;

  bool has(const OdChar* name) const;
  bool has(OdDbObjectId id) const;

  virtual OdDbSymbolTableIteratorPtr newIterator( 
    bool atBeginning = true, 
    bool skipDeleted = true) const;

  // 根据基类类似函数重新实现
  OdResult newIterator (
    OdDbViewportTableIterator*& pIterator,
    bool atBeginning = true,
    bool skipDeleted = true) const;

  OdResult add ( 
    OdDbObjectId& recordId, 
    OdDbViewportTableRecord* pRecord);

  OdResult add ( 
    OdDbViewportTableRecord* pRecord);
  /*--------------------------------------*
   *         finish                       *
   ****************************************/

  /** Description:
    Makes the specified viewport the active viewport of this ViewportTable object.

    Arguments:  
    viewportId (I) Object ID of the active viewport.      
  */
  void SetActiveViewport(
    OdDbObjectId viewportId);

  /** Description:
    Returns the active viewport of this ViewportTable object.
  */
  OdDbObjectId getActiveViewportId() const;

  /** Description:
    Deletes the specified configuration from this ViewportTable object.
    
    Arguments:
    configName (I) Configuration *name* to delete.
  */
  void DeleteConfiguration(
    const OdString& configName);

  virtual OdDbObjectId add(
    ODSYSDEF,
    OdDbSymbolTableRecord* pRecord);

  OdResult dxfIn(
    OdDbDxfFiler* pFiler);

  OdResult subGetClassID(
    CLSID* pClsid) const;

  OdResult subClose();
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbTextStyleTable object pointers.
*/
typedef OdSmartPtr<OdDbViewportTable> OdDbViewportTablePtr;

#include "TD_PackPop.h"

#endif // _ODDBVIEWPORTTABLE_INCLUDED

