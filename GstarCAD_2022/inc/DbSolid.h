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




#ifndef _OD_DB_SOLID_
#define _OD_DB_SOLID_

#include "TD_PackPush.h"

#include "DbEntity.h"

/** Description:
    This class represents 2D solid-filled (Solid) entities in an OdDbDatabase instance.
  
    Library:
    TD_Db
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbSolid : public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbSolid);

  OdDbSolid();

  OdDbSolid(const OdGePoint3d&  pt0,
			const OdGePoint3d&  pt1,
			const OdGePoint3d&  pt2,
			const OdGePoint3d&  pt3);
  OdDbSolid(const OdGePoint3d&  pt0,
			const OdGePoint3d&  pt1,
			const OdGePoint3d&  pt2);
  ~OdDbSolid();

  /** Description:
    Returns the specified WCS *point* of this Solid entity (DXF 10, 11, 12, or 13).

    Arguments:
    pointIndex (I) Point index [0 .. 3].
    point (O) Receives the specified *point*.    

  */
   OdResult getPointAt(
    int pointIndex, 
    OdGePoint3d& point) const;

  
  /** Description:
    Sets the specified WCS *point* of this Solid entity (DXF 10, 11, 12, or 13).

    Arguments:
    pointIndex (I) Point index [0 .. 3].
    point (I) Point.
    
  */
   OdResult setPointAt(
    int pointIndex, 
    const OdGePoint3d& point);
  
  /** Description:
    Returns the *thickness* of this entity (DXF 39).
    
    Remarks:
    Thickness is the extrusion length along the *normal*.
  */
  double thickness() const;
  
  /** Description:
    Sets the *thickness* of this entity (DXF 39).
    Arguments:
    thickness (I) Thickness.
    Remarks:
    Thickness is the extrusion length along the *normal*.
  */
   OdResult setThickness(
    double thickness);
  
  /** Description:
    Returns the WCS *normal* to the plane of this entity (DXF 210).
  */
  OdGeVector3d normal() const;
  
  /** Description:
    Sets the WCS *normal* to the plane of this entity (DXF 210).
    Arguments:
    normal (I) Normal.
  */
   OdResult setNormal(
    const OdGeVector3d& normal);
 
  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  virtual OdResult subTransformBy(const OdGeMatrix3d& xfm);

  virtual OdResult getPlane(OdGePlane& plane, OdDb::Planarity& planarity) const;

  virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
    const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
    int& numPaths, OdDbFullSubentPath*& subentPaths, 
    int numInserts = 0,
    OdDbObjectId* pEntAndInsertStack = 0) const;

  virtual OdResult subGetGsMarkersAtSubentPath(const OdDbFullSubentPath& subPath, 
    OdGsMarkerArray& gsMarkers) const;

  virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& path) const;
};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbSolid object pointers.
*/
typedef OdSmartPtr<OdDbSolid> OdDbSolidPtr;

#include "TD_PackPop.h"

#endif
