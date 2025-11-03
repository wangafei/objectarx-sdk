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

#ifndef _DBENTITYOVRRULE_H_INCLUDED_
#define _DBENTITYOVRRULE_H_INCLUDED_

#include "RxOverrule.h"
#include "DbEntity.h"

/* TODO
OdDbHighlightStateOverrule 
OdDbSubentityOverrule
OdDbVisibilityOverrule
OdGiDrawableOverrule
OdDbDimensionStyleOverrule
*/

/** Description:
    
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbOsnapOverrule : public OdRxOverrule
{
public:
  ODRX_DECLARE_MEMBERS(OdDbOsnapOverrule);

  OdDbOsnapOverrule();

  virtual OdResult getOsnapPoints(
    const OdDbEntity* pSubject,
    OdDb::OsnapMode osnapMode,
    OdGsMarker gsSelectionMark,
    const OdGePoint3d& pickPoint,
    const OdGePoint3d& lastPoint,
    const OdGeMatrix3d& xWorldToEye,
    OdGePoint3dArray& snapPoints ,
    OdDbIntArray &   geomIds);

  virtual OdResult getOsnapPoints(
    const OdDbEntity* pSubject,
    OdDb::OsnapMode osnapMode,
    OdGsMarker gsSelectionMark,
    const OdGePoint3d& pickPoint,
    const OdGePoint3d& lastPoint,
    const OdGeMatrix3d& xWorldToEye,
    OdGePoint3dArray& snapPoints,
    OdDbIntArray &   geomIds,
    const OdGeMatrix3d& insertionMat);

  virtual bool isContentSnappable(const OdDbEntity* pSubject);
};

/** Description:
    
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbTransformOverrule : public OdRxOverrule
{
public:
  ODRX_DECLARE_MEMBERS(OdDbTransformOverrule);
  OdDbTransformOverrule();
  virtual OdResult transformBy(OdDbEntity* pSubject, const OdGeMatrix3d& xform);
  virtual OdResult getTransformedCopy(const OdDbEntity* pSubject, const OdGeMatrix3d& xform, OdDbEntity*& pEnt);
  virtual OdResult explode(const OdDbEntity* pSubject, OdDbVoidPtrArray& entitySet);
  virtual OdBool cloneMeForDragging(OdDbEntity* pSubject);
  virtual bool hideMeForDragging(const OdDbEntity* pSubject);
};

/** Description:
    
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbGripOverrule : public OdRxOverrule
{
public:
  ODRX_DECLARE_MEMBERS(OdDbGripOverrule);

  OdDbGripOverrule();
  virtual OdResult getGripPoints( const OdDbEntity* pSubject, 
    OdGePoint3dArray& gripPoints,
    OdDbIntArray &     osnapModes,//not currently in use
    OdDbIntArray &  geomIds );

  virtual OdResult getGripPoints(const OdDbEntity* pSubject, 
    OdDbGripDataPtrArray& gripsData,
    const double curViewUnitSize,
    const int gripSize,
    const OdGeVector3d& curViewDir,
    const int bitFlags );

  virtual OdResult moveGripPointsAt(OdDbEntity* pSubject, 
    const OdIntArray& indices,
    const OdGeVector3d& offset );

  virtual OdResult moveGripPointsAt(OdDbEntity* pSubject,
    const OdDbVoidPtrArray& grips,
    const OdGeVector3d& offset,
    const int bitFlags );

  virtual OdResult getStretchPoints(const OdDbEntity* pSubject,
    OdGePoint3dArray& stretchPoints);

  virtual OdResult moveStretchPointsAt(OdDbEntity* pSubject,
    const OdIntArray & indices,
    const OdGeVector3d& offset);

   virtual void gripStatus(OdDbEntity* pSubject, const OdDb::GripStat status);
};

/** Description:
    
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbSubentityOverrule : public OdRxOverrule
{
public:
  ODRX_DECLARE_MEMBERS(OdDbSubentityOverrule);
  OdDbSubentityOverrule();
  virtual OdResult deleteSubentPaths(OdDbEntity* pSubject, const OdDbFullSubentPathArray& paths);
  virtual OdResult addSubentPaths(OdDbEntity* pSubject, const OdDbFullSubentPathArray& paths);
  virtual OdResult transformSubentPathsBy(OdDbEntity* pSubject,
    const OdDbFullSubentPathArray& paths,
    const OdGeMatrix3d&            xform);
  virtual OdResult getGripPointsAtSubentPath(
    const OdDbEntity*              pSubject,
    const OdDbFullSubentPath&      path,
    OdDbGripDataPtrArray&          grips,
    const double                   curViewUnitSize,
    const int                      gripSize,
    const OdGeVector3d&            curViewDir,
    const OdUInt32                 bitflags);

  virtual OdResult moveGripPointsAtSubentPaths(
    OdDbEntity*                    pSubject,
    const OdDbFullSubentPathArray& paths,
    const OdDbVoidPtrArray&        gripAppData,
    const OdGeVector3d&            offset,
    const OdUInt32                 bitflags);

  virtual  OdResult getSubentPathsAtGsMarker(
    const OdDbEntity*      pSubject,
    OdDb::SubentType       type,
    OdGsMarker             gsMark, 
    const OdGePoint3d&     pickPoint,
    const OdGeMatrix3d&    viewXform, 
    int&                   numPaths,
    OdDbFullSubentPath*&   subentPaths, 
    int                    numInserts = 0,
	  OdDbObjectId*    pEntAndInsertStack = 0);

  virtual  OdResult getGsMarkersAtSubentPath(
    const OdDbEntity*         pSubject,
    const OdDbFullSubentPath& subPath, 
    OdGsMarkerArray& gsMarkers);

  virtual OdDbEntity* subentPtr(const OdDbEntity* pSubject, const OdDbFullSubentPath& id);
  
  virtual OdResult getCompoundObjectTransform(const OdDbEntity* pSubject, OdGeMatrix3d & xMat);

  virtual OdResult getSubentPathGeomExtents(const OdDbEntity* pSubject,
    const OdDbFullSubentPath& path, 
    OdGeExtents3d& extents);

  virtual OdResult getSubentPathGeomExtents(const OdDbEntity* pSubject,
    const OdDbFullSubentPath& path,
    OdDbExtents& extents);

  virtual void subentGripStatus(OdDbEntity* pSubject, const OdDb::GripStat status,
    const OdDbFullSubentPath& subentity);

  virtual OdResult getSubentClassId(const OdDbEntity* pSubject,
    const OdDbFullSubentPath& path,
    void*                    clsId);

  virtual OdResult getSubentClassId(const OdDbEntity* pSubject,
    const OdDbFullSubentPath& path,
    CLSID* clsId);
};

/** Description:
    
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbHighlightOverrule : public OdRxOverrule
{
public:
  ODRX_DECLARE_MEMBERS(OdDbHighlightOverrule);
  OdDbHighlightOverrule();
  virtual OdResult highlight(const OdDbEntity* pSubject, const OdDbFullSubentPath& subId = kNullSubent,
    const OdBool highlightAll = false);

  virtual OdResult unhighlight(const OdDbEntity* pSubject, const OdDbFullSubentPath& subId = kNullSubent,
    const OdBool highlightAll = false);
};

/** Description:
    
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbGeometryOverrule : public OdRxOverrule
{
public:
  ODRX_DECLARE_MEMBERS(OdDbGeometryOverrule);

  OdDbGeometryOverrule();

  virtual OdResult intersectWith(const OdDbEntity* pThisEnt,
    const OdDbEntity* pEnt, OdDb::Intersect intType,
    OdGePoint3dArray& points, OdGsMarker thisGsMarker = 0,
    OdGsMarker otherGsMarker = 0);

  virtual OdResult intersectWith(const OdDbEntity* pThisEnt,
    const OdDbEntity* pEnt, OdDb::Intersect intType,
    const OdGePlane& projPlane, OdGePoint3dArray& points,
    OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0);
  virtual OdResult getGeomExtents(const OdDbEntity* pSubject, OdDbExtents& extents);
};

#endif //_DBENTITYOVRRULE_H_INCLUDED_
