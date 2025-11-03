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




#ifndef _ODDBBLOCKTABLERECORD_INCLUDED
#define _ODDBBLOCKTABLERECORD_INCLUDED

#include "TD_PackPush.h"

#include "DbSymbolTableRecord.h"
#include "DbObjectIterator.h"
#include "DbXrefGraph.h"
#include "DbDatabase.h"
#include "Ge/GeMatrix3d.h"

class OdDbBlockBegin;
class OdDbBlockEnd;
class OdDbBlockTableRecord;
class OdDbBlockTable;
class OdBinaryData;
class OdDbSortentsTable;
typedef OdSmartPtr<OdDbBlockBegin> OdDbBlockBeginPtr;
typedef OdSmartPtr<OdDbBlockEnd> OdDbBlockEndPtr;
typedef OdSmartPtr<OdDbSortentsTable> OdDbSortentsTablePtr;


/** Gcad(Add): 增加 DD 库缺少的 OdDbBlockTableRecordIterator 类
*/
class TOOLKIT_EXPORT OdDbBlockTableRecordIterator
{
public:
  virtual ~OdDbBlockTableRecordIterator();

  void     start (bool atBeginning = true, bool skipDeleted = true)
  { if(!mIterator.isNull()) mIterator->start(!atBeginning, skipDeleted); }

  void     step  (bool forward = true, bool skipDeleted = true)
  { if(!mIterator.isNull()) mIterator->step(!forward, skipDeleted); }

  bool     done  () const
  { return ( mIterator.isNull() ? true : mIterator->done() ); }

  OdResult getEntityId (OdDbObjectId& entityId) const;
  OdResult getEntity   (OdDbEntity*& pEntity,
                        OdDb::OpenMode openMode,
                        bool openErasedEntity = false) const;

  OdResult seek (OdDbObjectId id);
  OdResult seek (const OdDbEntity* pEntity);

  OdDbBlockTableRecord* blockTableRecord() const
  { return mpBlockTabrec; }

protected:
  friend class OdDbBlockTableRecord;
  OdDbBlockTableRecordIterator();

  OdDbBlockTableRecord* mpBlockTabrec;
  OdDbObjectIteratorPtr mIterator;
};

/** Gcad(Add): 增加 DD 库缺少的 OdDbBlockReferenceIdIterator 类
*/
class OdDbBlockReference;
class TOOLKIT_EXPORT OdDbBlockReferenceIdIterator
{
public:
  virtual ~OdDbBlockReferenceIdIterator();

  void     start () { mPos = 0; }
  void     step  () { mPos++; }
  bool     done  () const { return mPos >= mAry.length(); }

  OdResult getBlockReferenceId (OdDbObjectId& id) const;
  OdResult getBlockReference (OdDbBlockReference*& pBlkRef,
                              OdDb::OpenMode openMode,
                              bool openErasedEntity = false) const;
  OdResult getDatabase (OdDbDatabase*& pDb) const;

  OdResult seek (OdDbObjectId id);

protected:
  friend class OdDbBlockTableRecord;
  OdDbBlockReferenceIdIterator();

  OdSize mPos;
  OdDbObjectIdArray mAry;
};


/** Description:
    This class represents Block records in the OdDbBlockTable in an OdDbDatabase instance.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbBlockTableRecord : public OdDbSymbolTableRecord
{
public:

  ODDB_DECLARE_MEMBERS(OdDbBlockTableRecord);

  OdDbBlockTableRecord();
  virtual ~OdDbBlockTableRecord();

  typedef OdDbBlockTable TableType;
  typedef OdArray<OdUInt8> PreviewIcon;
  
  /** Gcad(Add): 新增兼容非虚函数
    本函数是旧的ARX函数, 功能近似于 getBlockReferenceIds().
    TODO: 需要实现 newBlockReferenceIdIterator 类(封装 OdDbObjectIdArray)
  */
  OdResult newBlockReferenceIdIterator(OdDbBlockReferenceIdIterator*& pIter) const;

  /** Description:
    Appends the specified entity to this Block.

    Arguments:
    pEntity (I) Pointer to the entity.

    Remarks:
    Returns the Object ID of the newly appended entity.

    Gcad(Internal): 冲突, 需要调整DD库
  */
  OdDbObjectId appendOdDbEntity(
    ODSYSDEF,
    OdDbEntity* pEntity);

  /** Gcad(Add): 新增兼容非虚函数
	注意: 本处函数名和 ARX 不一致.
  */
#ifdef ODARXDEF
  OdResult appendOdDbEntity(
    OdDbEntity* pEntity);
  OdResult appendOdDbEntity(
    OdDbObjectId& pOutputId, 
    OdDbEntity* pEntity);
#endif

  void removeOdDbEntity(OdDbObjectId &id);
  /** Description:
    Returns an Iterator that can be used to traverse this Block.

    Arguments:
    atBeginning (I) True to start at the beginning, false to start at the end. 
    skipDeleted (I) If and only if true, deleted records are skipped.
    sorted (I) If and only if true, the iterator will traverse the Block as *sorted* by this Block's SortentsTable.
  */
  OdDbObjectIteratorPtr newIterator(
    bool atBeginning = true, 
    bool skipDeleted = true, 
    bool sorted = false) const;

  /** Gcad(Add): 新增兼容非虚函数
	注意 OdDbBlockTableRecordIterator 需自己实现
  */
  OdResult newIterator(
    OdDbBlockTableRecordIterator*& pIterator,
    bool atBeginning = true,
    bool skipDeleted = true) const;

  /** Description:
    Returns the description text associated with this Block (DXF 4).
  */
  OdString comments() const;

  /** Gcad(Add): 新增兼容非虚函数
  */
  OdResult comments(OdChar*& pString) const;
  OdResult comments(const OdChar*& pString) const;

  /** Description:
    Sets the description text associated with this Block (DXF 4).
    Arguments:
    comments (I) Description text.

    Gcad(Modify): 返回值 void -> OdResult
  */
  OdResult setComments(const OdChar * comments);

  /** Description:
    Returns the path and filename for the Xref drawing (DXF 1).
    
    Remarks:
    Returns an empty string for non-Xref blocks.
  */
  OdString pathName() const;

  /** Gcad(Add): 新增兼容非虚函数
  */
  OdResult pathName(OdChar*& pPath) const;
  OdResult pathName(const OdChar*& pPath) const;

  virtual const OdChar * activeFileName() const;

  /** Description:
    Sets the path and filename for the Xref drawing (DXF 1).
    Arguments:
    pathName (I) Path and filename.

    Gcad(Modify): 返回值 void -> OdResult
  */
  OdResult setPathName(const OdChar * pathName);
  
  /** Description:
    Returns the WCS *origin* of this Block (DXF 10).
  */
  OdGePoint3d origin() const;

  /** Description:
    Sets the WCS *origin* of this Block (DXF 10).
    Arguments:
    origin (I) Origin.

    Gcad(Modify): 返回值 void -> OdResult
  */
  OdResult setOrigin(const OdGePoint3d& origin);

  /** Description:
    Opens and returns the OdDbBlockBegin object associated with this Block.

    Arguments:
    openMode (I) Mode in which to open the object.

    Remarks:
    This function allows Teigha applications to access the OdDbBlockBegin object 
    to store and retrieve Xdata in a manner compatible with AutoLISP applications.
  */
  OdDbBlockBeginPtr openBlockBegin(OdDb::OpenMode openMode = OdDb::kForRead);

  /** Gcad(Add): 新增兼容非虚函数
  */
  OdResult openBlockBegin(OdDbBlockBegin*& pBlockBegin, OdDb::OpenMode openMode);

  /** Description:
    Opens and returns the OdDbBlockEnd object associated with this Block.

    Arguments:
    openMode (I) Mode in which to open the object.

    Remarks:
    This function allows Teigha applications to access the OdDbBlockEnd object 
    to store and retrieve Xdata in a manner compatible with AutoLISP applications.
  */
  OdDbBlockEndPtr openBlockEnd(OdDb::OpenMode openMode = OdDb::kForRead);

  /** Gcad(Add): 新增兼容非虚函数
  */
  OdResult openBlockEnd(OdDbBlockEnd*& pBlockEnd, OdDb::OpenMode openMode);

  /** Description:
    Returns true if and only if this Block contains Attribute definitions.

    See Also:
    OdDbAttributeDefinition
  */
  bool hasAttributeDefinitions() const;

  /** Description:
    Returns true if and only if this Block is anonymous (DXF 70, bit 0x01).
  */
  bool isAnonymous() const;

  /** Description:
    Returns true if and only if this Block is an Xref (DXF 70, bit 0x04).
  */
  bool isFromExternalReference() const;

  /** Description:
    Returns true if and only if this Block is an overlaid Xref (DXF 70, bit 0x08).
  */
  bool isFromOverlayReference() const;

  /** Description:
    Returns true if and only if this Block represents a layout.
  */
  bool isLayout() const;

  /** Description:
    Returns the Object ID of the OdDbLayout associated with this Block.
  */
  OdDbObjectId getLayoutId() const;

  /** Description:
    Sets the Object ID of the OdDbLayout associated with this Block.
    
    Arguments:
    layoutId (I) Layout ID.

    Gcad(Modify): 返回值 void -> OdResult
  */
  OdResult setLayoutId(const OdDbObjectId& layoutId);

  /** Description:
    Returns the Object ID's of all OdDbBlockReference entities that reference this Block.

    Arguments:
    referenceIds (O) Receives the BlockReference Object ID's.
    directOnly (I) If true, returns only direct references.
    forceValidity (I) If true, forces the loading of partially loaded drawings.

    Remarks:
    If this Block is nested, references to the parent block(s) will be included if and only if directOnly is false.
    
    Older drawings do not explicitly store this information, and hence must be completely loaded.

    See also:
    getErasedBlockReferenceIds

    Gcad(Modify): 返回值 void -> OdResult
  */
  OdResult getBlockReferenceIds(
    OdDbObjectIdArray& referenceIds,
    bool directOnly = true, 
    bool forceValidity = false) const;

  /** Description:
    Returns the Object ID's of all *erased* OdDbBlockReference entities that directly reference this Block.

    Arguments:
    referenceIds (O) Receives the BlockReference Object ID's.

    See also:
    getBlockReferenceIds

    Gcad(Modify): 返回值 void -> OdResult
  */
  OdResult getErasedBlockReferenceIds(OdDbObjectIdArray& referenceIds);

  /** Description:
    Returns true if and only if this Xref is unloaded (DXF 71).
  */
  bool isUnloaded() const;

  /** Description:
    Sets the unloaded status of this Xref (DXF 71).

    Arguments:
    isUnloaded (I) Unloaded status.

    Gcad(Modify): 返回值 void -> OdResult
  */
  OdResult setIsUnloaded(bool isUnloaded);

  virtual OdBool subWorldDraw(OdGiWorldDraw* pWd) ODRX_OVERRIDE;

  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits) ODRX_OVERRIDE;

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler) ODRX_OVERRIDE;

  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const ODRX_OVERRIDE;

  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler) ODRX_OVERRIDE;

  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const ODRX_OVERRIDE;

  virtual OdResult subClose() ODRX_OVERRIDE;

  virtual OdResult subGetClassID(CLSID* pClsid) const ODRX_OVERRIDE;

  virtual OdResult subErase(OdBool erasing) ODRX_OVERRIDE;

  virtual OdResult subHandOverTo(OdDbObject* pNewObject) ODRX_OVERRIDE;

  virtual OdResult copyFrom(const OdRxObject* p) ODRX_OVERRIDE;
  
  /** Description:
    Returns the *database* that defines this Xref.
    Arguments:
    includeUnresolved (I) Include unresolved Xrefs.
  */
  OdDbDatabase* xrefDatabase(bool includeUnresolved = false) const;

  /** Description:
    Returns the Xref status of this Block.
    Remarks:
    xrefStatus() returns one of the following:
    
    @table
    Name                      Value   Description
    OdDb::kXrfNotAnXref       0       Not an Xref
    OdDb::kXrfResolved        1       Resolved
    OdDb::kXrfUnloaded        2       Unloaded
    OdDb::kXrfUnreferenced    3       Unreferenced
    OdDb::kXrfFileNotFound    4       File Not Found
    OdDb::kXrfUnresolved      5       Unresolved
    
  */
  OdDb::XrefStatus xrefStatus() const;

  /** Description:
    Returns true if and only if this Block has a preview icon.
  */
  bool hasPreviewIcon() const;

  /** Description:
    Returns the preview icon associated with this Block.
    Arguments:
    previewIcon (O) Receives the Preview icon.

    Gcad(Modify): 返回值 void -> OdResult
  */
  OdResult getPreviewIcon(PreviewIcon &previewIcon) const;

  /** Description:
    Sets the preview icon associated with this Block.
    Arguments:
    previewIcon (I) Preview icon.

    Gcad(Modify): 返回值 void -> OdResult
  */
  OdResult setPreviewIcon(const PreviewIcon &previewIcon);

  OdResult subWblockClone(OdRxObject* pOwnerObject,
    OdDbObject*& pClonedObject,
    OdDbIdMapping& idMap,
    OdBool isPrimary) const;

  /** Description:
    Returns the SortentsTable associated with this block.

    Arguments:
    createIfNotFound (I) Create the SortentsTable if not found. 

    Note:
    The SortentsTable is opened for write.
    
    See also:
    OdDbSortentsTable
  */
  OdDbSortentsTablePtr getSortentsTable(bool createIfNotFound = true);

  //Gcad(Add)
  OdResult getSortentsTable(OdDbSortentsTable*& pSortents,
							OdDb::OpenMode openMode,
							bool createIfNecessary=false);

  OdGiDrawable* drawable();

	/* Gcad(TODO): 以下函数DD库没有实现，估计用户也很少用，暂不实现 
      void viewportDraw(OdGiViewportDraw* pVd);
  */
  void setGsNode(OdGsNode* pNode);
  OdGsNode* gsNode() const;

  virtual OdResult decomposeForSave(OdDb::DwgVersion ver,
                                    OdDbObject*& replaceObj,
                                    OdDbObjectId& replaceId,
                                    OdBool& exchangeXData);

  OdResult postProcessAnnotativeBTR(int& stripCnt,
    const bool bqueryOnly = false,
    const bool bScale = true);

  OdResult addAnnoScalestoBlkRefs(const bool bScale = false);

  /** Description:
    Returns the WCS geometric *extents* of this object.

    Arguments:
    extents (O) Receives the *extents*.

    Remarks:
    Returns eOk if successful, or eInvalidExtents if not.

    The *extents* are the WCS corner points of a box, aligned with the 
    WCS axes, that encloses the 3D *extents* of this Block. 
  */
  virtual OdResult getGeomExtents(OdDbExtents& extents) const; //Gcad(Modify) OdGeExtents3d=>OdDbExtents

  OdResult geomExtentsBestFit(OdDbExtents& extents,
                              const OdGeMatrix3d& parentXform = OdGeMatrix3d::kIdentity) const;

  /** Description:
    This method causes the invoked block table record to assume the ownership of all 
    the entities listed in the input entitiesToMove array, and provides an optimized 
    way of moving entities between block table records. 
  */
  virtual OdResult assumeOwnershipOf(OdArray<OdDbObjectId> entitiesToMove);

  enum BlockScaling {
    kAny            = 0, // Block references can be non-uniformly scaled.
    kUniform        = 1  // Block references can be scaled only uniformly.
  };

  /** Description:
    Returns the scaling characteristics of references to this Block.

    Remarks:
    blockScaling() returns one of the following:
    
    @table
    Name        Value    Description
    kAny        0        Block references can be non-uniformly scaled.
    kUniform    1        Block references can be scaled only uniformly.
  */
  BlockScaling blockScaling() const;
  
  /** Description:
    Sets the scaling characteristics of references to this Block.

    Arguments:
    blockScaling (I) Block scaling.
    
    Remarks:
    blockScaling can be one of the following:
    
    @table
    Name     Value    Description
    kAny     0        Block references can be non-uniformly scaled.
    kUniform 1        Block references can be scaled only uniformly.
  */
  OdResult setBlockScaling(BlockScaling blockScaling);//Gcad(Modify)


  /** Description:
    Controls if references to this Block can be exploded.
    Arguments:
    explodable (I) Explodable. 
  */
  OdResult setExplodable(bool explodable);//Gcad(Modify)
  
  /** Description:
    Returns true if and only if references to this Block can be exploded.
  */
  bool explodable() const;

  /** Description:
    Sets the block insertion units for this Block.
    Arguments:
    blockInsertUnits (I) Block insert units. 
  */
  OdResult setBlockInsertUnits(OdDb::UnitsValue blockInsertUnits);//Gcad(Modify)
  
  /** Description:
    Returns the block insertion units for this Block. 
  */
  OdDb::UnitsValue blockInsertUnits() const;

  OdResult applyPartialUndo(OdDbDwgFiler* pFiler, OdRxClass* pClass);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbBlockTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbBlockTableRecord> OdDbBlockTableRecordPtr;

#include "TD_PackPop.h"

#endif 

