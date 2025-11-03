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

#ifndef   _XREFMAN_H_
#define   _XREFMAN_H_

#include "RxObject.h"
#include "DbLayerTableRecord.h"
#include "DbBlockTableRecord.h"
#include "DbLinetypeTableRecord.h"
#include "DbTextStyleTableRecord.h"
#include "DbSecurity.h"

#include "TD_PackPush.h"

/** Description:
    This class manages External References (Xrefs) in an OdDbDatabase object.
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbXRefMan
{
public:
  static OdDbBlockTableRecordPtr     
    attach(OdDbDatabase* pHostDb, const OdString& pathName, 
    const OdString& blockName, bool overlaid, bool bQuiet,
    const OdPassword& password = OdPassword(),
    OdDbHandle handle = 0);

  static OdResult
    redefine(OdDbBlockTableRecord* pRec, OdDbDatabase* pHostDb, const OdString& pathName, 
    const OdString& blockName, bool overlaid, bool bQuiet,
    const OdPassword& password = OdPassword(),
    OdDbHandle handle = 0);
  /** Description:
    Loads of specified Xref(s) if not currently loaded.
    Arguments:
    pHostDb (I) Pointer to the host *database*.
    xrefBlockname (I) Xref block name to *load*.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  static OdResult load(OdDbDatabase* pHostDb, const OdString& xrefBlockname, bool bQuiet);

  /**
    Arguments:
    xrefBTRids (I) Array of the object IDs of the Block Table Records of the Xrefs to *load*.
  */
  static OdResult load(const OdDbObjectIdArray& xrefBTRids, bool bQuiet);

  /**
    Arguments:
    pBTR (I) Pointer to the Block Table Record of the Xref to *load*.
  */
  static OdResult load(OdDbBlockTableRecord* pBTR, bool bQuiet);

  /** Description:
    Loads of all Xrefs not currently loaded.
    Arguments:
    pHostDb (I) Pointer to the host *database*.
    verify (I) Verify.
    Remarks:
    If verify is true, this function attempts to load those Xrefs that
    are not unloaded, not unresolved, and not resolved.

    Returns eOk if successful, or an appropriate error code if not.
  */
  static OdResult loadAll(OdDbDatabase* pHostDb, bool verify, bool bQuiet);

  /** Description:
    Unloads the specified Xref(s).
    Arguments:
    pBTR (I) Pointer to the Block Table Record of the Xref to *unload*.
  */
  static void unload(OdDbBlockTableRecord* pBTR, bool bQuiet);

  /**
    Arguments:
    xrefBTRids (I) Array of the object IDs of the Block Table Records of the Xrefs to *nload*.
  */
  static void unload(const OdDbObjectIdArray& xrefBTRids, bool bQuiet);

  /** Description:
    Unloads all loaded Xrefs.
    Arguments:
    pHostDb (I) Pointer to the host *database*.
  */
  static void unloadAll(OdDbDatabase* pHostDb, bool bQuiet);

  /** Description:
    Binds the specified Xref.
    Arguments:
    pBTR (I) Pointer to the Block Table Record of the Xref to *bind*.
    insertBind (I) True for Xref Insert, false for Xref Bind.
  */
  static OdResult bind(OdDbBlockTableRecord* pBTR, bool insertBind, bool bQuiet);

  /** Description:
    Detaches the specfied Xref.
    Arguments:
    pBTR (I) Pointer to the Block Table Record of the Xref to *detach*.
  */
  static OdResult detach(OdDbBlockTableRecord* pBTR, bool bQuiet);
};

/** Description:
    This class is the Xref Manager Extenstion class.
    
    Remarks:
    This class creates and augments Xref blocks in OdDbDatabase instances. 
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbXRefManExt
{
public:
  /** Description:
    Creates an Xref block in the specified *database*.

    Arguments:
    pDb (I) Pointer to the *database*.
    pathName (I) Path and filename for Xref block.
    blockName (I) Name of Xref block.
    overlaid (I) True for Xref Overlay, false for Xref Attach.
    password (I) Password for file.
    handle (I) Handle for Xref block.
    
    Remarks:
    Returns a SmartPointer to the newly added Block Table Record.
  */
  static OdDbBlockTableRecordPtr     
    addNewXRefDefBlock(OdDbDatabase* pDb, const OdString& pathName, 
                        const OdString& blockName, bool overlaid, 
                        const OdPassword& password = OdPassword(),
                        OdDbHandle handle = 0);

  /** Description:
    Adds an Xref dependent layer to the specified Xref block.
    
    Arguments:
    pXRefBlock (I) Pointer to the Xref Block Table Record.
    layerName (I) Name of the *layer*.

    Remarks:
    Returns a SmartPointer to the newly added Layer Table Record.
  */
  static OdDbLayerTableRecordPtr     
    addNewXRefDependentLayer(const OdDbBlockTableRecord* pXRefBlock, const OdString& layerName);

  /**
    Arguments:
    xRefBlockId (I) Object ID of the Xref Block Table Record.
  */
  static OdDbLayerTableRecordPtr addNewXRefDependentLayer(OdDbObjectId xRefBlockId, const OdString& layerName)
  { return addNewXRefDependentLayer(OdDbBlockTableRecordPtr(xRefBlockId.safeOpenObject()), layerName); }

  /** Description:
    Adds an Xref dependent linetype to the specified Xref block.
    
    Arguments:
    pXRefBlock (I) Pointer to the Xref Block Table Record.
    linetypeName (I) Name of the linetype.

    Remarks:
    Returns a SmartPointer to the newly added Linetype Table Record.
  */
  static OdDbLinetypeTableRecordPtr     
    addNewXRefDependentLinetype(const OdDbBlockTableRecord* pXRefBlock, const OdString& linetypeName);

  /**
    Arguments:
    xRefBlockId (I) Object ID of the Xref Block Table Record.
  */
  static OdDbLinetypeTableRecordPtr
    addNewXRefDependentLinetype(OdDbObjectId xRefBlockId, const OdString& linetypeName)
  { return addNewXRefDependentLinetype(OdDbBlockTableRecordPtr(xRefBlockId.safeOpenObject()), linetypeName); }

  /** Description:
    Adds an Xref dependent text style to the specified Xref block.
    
    Arguments:
    pXRefBlock (I) Pointer to the Xref Block Table Record.
    textStyleName (I) Name of the text style.

    Remarks:
    Returns a SmartPointer to the newly added Text Style Table Record.
  */
  static OdDbTextStyleTableRecordPtr     
    addNewXRefDependentTextStyle(const OdDbBlockTableRecord* pXRefBlock, const OdString& textStyleName);

  /**
    Arguments:
    xRefBlockId (I) Object ID of the Xref Block Table Record.
  */
  static OdDbTextStyleTableRecordPtr
    addNewXRefDependentTextStyle(OdDbObjectId xRefBlockId, const OdString& textStyleName)
  { return addNewXRefDependentTextStyle(OdDbBlockTableRecordPtr(xRefBlockId.safeOpenObject()), textStyleName); }

  /** Description:
    Adds nested XRef Id to parent block.
  */
  static void addNestedXRefId(OdDbBlockTableRecord* pXRefBlock, OdDbObjectId nestedBlockId);

  /** Description:
    Gets nested XRef Ids.
  */
  static void getNestedXRefIds(OdDbBlockTableRecord* pXRefBlock, OdDbObjectIdArray& ids);

  /** Description:
    Gets block Id for a table record.
  */
  static OdDbObjectId getSymbolTableRecordXrefBlockId(const OdDbSymbolTableRecord* pRec);

  /** Description:
    Controls the reference type fo the specified Xref.
    Arguments:
    pBTR (I) Pointer to the Block Table Record of the Xref to detach.
    overlaid (I) True for Xref Overlay, false for Xref Attach.
  */
  static void setOverlaid(OdDbBlockTableRecord* pBTR, bool  overlaid = true);
};

/**
 * OdDbXrefObjectId
 */
class OdDbXrefObjectId 
{
public:
  OdDbXrefObjectId() : m_localId(), m_handle() {}
  OdDbXrefObjectId(const OdDbXrefObjectId& other) : m_localId(other.m_localId), m_handle(other.m_handle) {}

  OdDbXrefObjectId& operator= (const OdDbXrefObjectId& other)
  { m_localId = other.m_localId; m_handle = other.m_handle; return *this; }

  bool operator == (const OdDbXrefObjectId& other) const
  { return (m_localId == other.m_localId && m_handle == other.m_handle); }

  bool operator != (const OdDbXrefObjectId& other) const
  { return ( m_localId != other.m_localId || m_handle != other.m_handle); }

  bool isValid(void) const
  {
    if(m_handle.isNull())
      return !m_localId.isNull();
    // TODO: 要处理 1. 打开m_localId的BLKREC  2. 找到对应的DB  3. 检验DB里面是否含有 m_handle
    return false;
  }

  bool isXref(void) const 
  { return !m_handle.isNull(); }

  bool isNull(void) const 
  { return m_localId.isNull(); }

  OdResult setNull(void)
  {
    m_handle.setNull();
    m_localId.setNull();
    return Oda::eOk;
  }

  OdResult setXrefId(OdDbObjectId xrefBlkId, const OdDbHandle& hObject)
  { 
    if(xrefBlkId.isNull())
      return Oda::eNullObjectId;
    if(hObject.isNull())
      return Oda::eNotApplicable;//eNullHandle;
    m_localId = xrefBlkId; 
    m_handle = hObject;
    return Oda::eOk; 
  }

  OdResult getXrefId(OdDbObjectId& xrefBlkId, OdDbHandle& hObject) const
  { 
    if(m_handle.isNull())
      return Oda::eNotApplicable;//eInvalidXrefObjectId;
    xrefBlkId = m_localId; 
    hObject = m_handle;
    return Oda::eOk; 
  }

  OdResult setLocalId(OdDbObjectId objId)
  { 
    m_localId = objId; 
    m_handle.setNull();
    return Oda::eOk; 
  }

  OdResult getLocalId(OdDbObjectId& objId) const
  { 
    if(!m_handle.isNull())
      return Oda::eNotApplicable;//eInvalidXrefObjectId;
    objId = m_localId; 
    return Oda::eOk; 
  }

  OdResult resolveObjectId(OdDbObjectId& /*id*/) const
  { 
    if(m_handle.isNull())
      return Oda::eNotApplicable;//eInvalidXrefObjectId;
    // TODO: 要处理 1. 打开m_localId的BLKREC  2. 找到对应的Xref-DB  3. 获取Xref-DB里面 m_handle 对应的 OdDbObjectId
    return Oda::eNotImplementedYet; //eOk; 
  }

  //OdResult serializeToResbuf(resbuf*& pResBuf, resbuf*& pEndOfChain) const;
  //OdResult serializeFromResbuf(const resbuf* pResBuf, resbuf*& pNextInChain);

private:

  OdDbObjectId   m_localId;    // if m_handle.isNull(), this is a local objId
                               // otherwise, it is the block table record of the xref

  OdDbHandle     m_handle;     // handle of the object we refer
                               // to within the Xref
};

#include "TD_PackPop.h"

#endif //_XREFMAN_H_


