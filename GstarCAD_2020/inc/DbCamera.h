/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2012, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2003-2012 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef __OD_DB_CAMERA__
#define __OD_DB_CAMERA__

#include "DbEntity.h"

#include "TD_PackPush.h"

class OdDbViewTableRecord;
typedef OdSmartPtr<OdDbViewTableRecord> OdDbViewTableRecordPtr;

/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbCamera : public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbCamera);

  OdDbCamera();

  ~OdDbCamera();
  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  virtual OdResult subErase(OdBool erasing);
  virtual OdResult subOpen(OdDb::OpenMode openMode);
  virtual OdResult subClose();

  OdDbObjectId view() const;
  OdResult setView(const OdDbObjectId viewId);

  // Some helpful methods for NDBRO editing (required for grip points implementation for example)
  // For internal use
  OdDbViewTableRecordPtr openView(OdDb::OpenMode openMode = OdDb::kForRead) const;
  // For internal use
  void updateView();

protected:

  virtual OdResult subTransformBy(const OdGeMatrix3d& xfm);

  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);
  virtual OdBool subWorldDraw(OdGiWorldDraw* pWd);
  virtual void subViewportDraw(OdGiViewportDraw* pVd);

  virtual OdResult subGetGeomExtents(OdGeExtents3d& extents) const;

  virtual OdResult subHighlight(const OdDbFullSubentPath& subId = kNullSubent,
    const OdBool highlightAll = false) const;

  virtual OdResult subUnhighlight(const OdDbFullSubentPath& subId = kNullSubent,
    const OdBool highlightAll = false) const;
  virtual OdResult subGetClassID(
	  CLSID* pClsid) const;
  virtual void subList() const;

  virtual OdResult subGetGripPoints(OdDbGripDataPtrArray& grips,
    const double curViewUnitSize,
    const int gripSize,
    const OdGeVector3d& curViewDir,
    const int bitflags) const;

  virtual OdResult subMoveGripPointsAt(const OdDbVoidPtrArray& gripAppData,
    const OdGeVector3d& offset,
    const int bitflags);

  virtual OdResult subGetStretchPoints(OdGePoint3dArray&  stretchPoints)const;

  virtual OdResult subMoveStretchPointsAt(const OdDbIntArray& indices,
    const OdGeVector3d&     offset);

  virtual OdResult subDeepClone(OdDbObject* pOwnerObject,
    OdDbObject*& pClonedObject,
    OdDbIdMapping& idMap,
    OdBool isPrimary= kTrue) const;

  virtual OdResult subWblockClone(OdRxObject* pOwnerObject,
    OdDbObject*& pClonedObject,
    OdDbIdMapping& idMap,
    OdBool isPrimary= kTrue) const;
};

typedef OdSmartPtr<OdDbCamera> OdDbCameraPtr;

#include "TD_PackPop.h"

#endif // __OD_DB_CAMERA__
