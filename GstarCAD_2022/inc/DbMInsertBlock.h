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




#ifndef _OD_DB_MINSERT_BLOCK_
#define _OD_DB_MINSERT_BLOCK_

#include "TD_PackPush.h"

#include "DbBlockReference.h"

class OdDbMInsertBlockImpl;

/** Description:
    This class represents arrayed instances of block references (MInserts) in an OdDbDatabase instance.

    Library:
    TD_Db

    Remarks:
    Creating an OdDbMInsertBlock instance with exactly one row and column creates an OdDbBlockReference instance. 
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbMInsertBlock : public OdDbBlockReference
{
public:
  ODDB_DECLARE_MEMBERS(OdDbMInsertBlock);

  OdDbMInsertBlock();
  
  OdDbMInsertBlock(
	  const OdGePoint3d&  position,
	  OdDbObjectId        blockTableRec,
	  OdUInt16			  columns,
	  OdUInt16			  rows,
	  double              colSpacing,
	  double              rowSpacing);

  ~OdDbMInsertBlock();

  /** Description:
    Returns the number of *columns* for this MInsert (DXF 70).
  */
  OdUInt16 columns() const;

  /** Description:
    Sets the number of *columns* for this MInsert (DXF 70).
    Arguments:
    numColumns (I) Number of *columns*.
  */
  OdResult setColumns(OdUInt16 numColumns);
  
  /** Description:
    Returns the number of *rows* for this MInsert (DXF 71).
  */
  OdUInt16 rows() const;

  /** Description:
    Sets the number of *rows* for this MInsert (DXF 71).
    Arguments:
    numRows (I) Number of *rows*.
  */
  OdResult setRows(OdUInt16 numRows);
  
  /** Description:
    Returns the column spacing for this MInsert (DXF 44).
  */
  double columnSpacing() const;

  /** Description:
    Sets the column spacing for this MInsert (DXF 44).
    Arguments:
    colSpacing (I) Column spacing.
  */
  OdResult setColumnSpacing(double colSpacing);
  
  /** Description:
    Returns the row spacing for this MInsert (DXF 45).
  */
  double rowSpacing() const;

  /** Description:
    Sets the row spacing for this MInsert (DXF 45).
    Arguments:
    rowSpacing (I) Row spacing.
  */
  OdResult setRowSpacing(double rowSpacing);
  
  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm);

  OdResult explodeToBlock(
    OdDbBlockTableRecord *pTargetBlkRec, 
    OdDbObjectIdArray *pResIdArray);

  OdResult subGetGeomExtents(
    OdDbExtents& extents) const;

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  virtual OdResult subExplode(OdDbVoidPtrArray& entitySet) const;
};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbMInsertBlock object pointers.
*/
typedef OdSmartPtr<OdDbMInsertBlock> OdDbMInsertBlockPtr;

#include "TD_PackPop.h"

#endif
