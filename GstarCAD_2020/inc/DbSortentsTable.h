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




#ifndef OD_DBSORTENTSTABLE_H
#define OD_DBSORTENTSTABLE_H

#include "TD_PackPush.h"

#include "DbObject.h"

#define STL_USING_UTILITY
#include "OdaSTL.h"

/** Description:
    This template class is a specialization of the std::pair class for OdDbHandle-OdDbSoftPointerId pairs.
*/
typedef std::pair<OdDbHandle, OdDbSoftPointerId> HandlePair;

/** Description:
    This template class is a specialization of the OdArray class for OdDbHandle-OdDbSoftPointerId pairs.
*/
typedef OdArray<HandlePair> HandlePairsArray;


/** Description:
    This class implements the SortentsTable, which specifies the DrawOrder 
    of entities in an OdDbDatabase instance.

    Remarks:
    Each instance of this class contains the DrawOrder for a single OdDbBlockRecord. 
    
    When drawing entities in a Block Table Record, an iterator traverses the Block Table Record 
    in the order of ascending handles. If there is a HandlePair in the SortentsTable corresponding
    to the *handle* of the object about to be drawn, the entity specified by the entity ID in the *HandlePair* is
    drawn in its stead. If there is no such *HandlePair*, the entity referenced by the iterator is drawn.
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbSortentsTable : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbSortentsTable);

  OdDbSortentsTable();

  virtual ~OdDbSortentsTable();
  
  OdBool sortAs(OdDbObjectId, OdDbHandle&) const;
  void getSortHandle(OdDbObjectId id, OdDbHandle& h) const;
  OdResult remove(OdDbObjectId);
  /** Description:
    Moves the entities with specified entity IDs to the bottom of this SortentsTable.

    Arguments:
    entityIds (I) Entity IDs.
  */
  OdResult moveToBottom(
    const OdDbObjectIdArray& entityIds);

  /** Description:
    Moves the entities with specified entity IDs to the top of this SortentsTable.

    Arguments:
    entityIds (I) Entity IDs.
  */
  OdResult moveToTop(
    const OdDbObjectIdArray& entityIds); 

  /** Description:
    Moves the entities with specified entity IDs below the target entity in this SortentsTable.

    Arguments:
    entityIds (I) Entity IDs.
    targetId (I) Target entity ID.
  */
  OdResult moveBelow(
    const OdDbObjectIdArray& entityIds, 
    OdDbObjectId targetId);

  /** Description:
    Moves the entities with specified entity IDs above  the target entity in this SortentsTable.

    Arguments:
    entityIds (I) Entity IDs.
    targetId (I) Target entity ID.
  */
  OdResult moveAbove(
    const OdDbObjectIdArray& entityIds, 
    OdDbObjectId targetId);

  /** Description:
    Swaps the DrawOrder of the specified entities in this SortentsTable.
    
    Arguments:
    firstId (I) First entity ID.
    secondId (I) Second entity ID.
  */
  OdResult swapOrder(
    OdDbObjectId firstId, 
    OdDbObjectId secondId);

  /** Description:
    Returns the Object ID of the Block Table Record to which this SortentsTable belongs.
  */
  OdDbObjectId  blockId() const; 
        
  OdResult   setBlockId(OdDbObjectId);
  ///  2005 functions
  ///

  /** Description:
    Returns true if and only if the first entity is drawn before the second with this SortentsTable.

    Arguments:
    firstID (I) First entity ID.
    secondID (I) Second entity ID.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  OdResult firstEntityIsDrawnBeforeSecond(
    OdDbObjectId firstID, 
    OdDbObjectId secondID) const;
  OdResult firstEntityIsDrawnBeforeSecond(
    OdDbObjectId first,
    OdDbObjectId second,
    bool& result) const;

  /** Description:
    Returns an array of the entity IDs of the entities in the associated Block Table Record,
    in the DrawOrder for this SortentsTable.

    Arguments:
    entityIds (O) Entity IDs.
    honorSortentsMask (I) SORTENTS mask. 

    Remarks:
    If (honorSortentsMask ^ SORTENTS) != honorSortentsMask, the entities are returned unsorted.
    
    Returns eOk if successful, or an appropriate error code if not.
    
    Note:
    As implemented, honorSortentsMask is ignored.
    It will be fully implemented in a future *release*.
  */
  OdResult getFullDrawOrder(
    OdDbObjectIdArray& entityIds, 
    OdUInt8 honorSortentsMask = 0) const;

  /** Description:
    Rearranges the specified entity IDs into their current relative DrawOrder for this SortentsTable.
    
    Arguments:
    entityIds (I/O) Entity IDs.
    honorSortentsMask (I) SORTENTS mask. 

    Remarks:
    If (honorSortentsMask ^ SORTENTS) != honorSortentsMask, the entities are returned unsorted.

    Returns eOk if successful, or an appropriate error code if not.

    Note:
    As implemented, honorSortentsMask is ignored.
    It will be fully implemented in a future *release*.
  */
  OdResult getRelativeDrawOrder(
    OdDbObjectIdArray& entityIds, 
    OdUInt8 honorSortentsMask = 0) const;


  /** Description:
    Sets the relative DrawOrder for the specified entities in this SortentsTable.

    Arguments:
    entityIds (I) Entity IDs in DrawOrder.

    Remarks:
    The DrawOrder of other entities are unaffected.
    
    Returns eOk if successful, or an appropriate error code if not.
  */
  OdResult setRelativeDrawOrder(
    const OdDbObjectIdArray& entityIds);

  /** Description:
    Sets this SortentsTable from an array of HandlePair pairs.
    
    Arguments:
    handlePairs (I) HandlePairs.
    
    Note:
    Use of this function is not recommended.
  */
  OdResult setAbsoluteDrawOrder(
    const HandlePairsArray& handlePairs);
	
  virtual OdResult  applyPartialUndo(OdDbDwgFiler*, OdRxClass*);
  virtual OdResult  audit(OdDbAuditInfo* pAuditInfo);

  /** Description:
    Returns this SortentsTable as an array of HandlePair pairs.
    
    Arguments:
    handlePairs (O) Receives an array of HandlePairs.
    
    Note:
    Use of this function is not recommended.
  */
  OdResult getAbsoluteDrawOrder(
    HandlePairsArray& handlePairs);

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
    This template class is a specialization of the OdSmartPtr class for OdDbSortentsTable object pointers.
*/
typedef OdSmartPtr<OdDbSortentsTable> OdDbSortentsTablePtr;

#include "TD_PackPop.h"

#endif //OD_DBSORTENTSTABLE_H

