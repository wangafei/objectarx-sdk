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




#ifndef _OD_DB_POINT_
#define _OD_DB_POINT_

#include "TD_PackPush.h"

#include "DbEntity.h"

/** Description:
    This class represents point (Point) entities in an OdDbDatabase instance.
  
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbPoint : public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbPoint);

  OdDbPoint();

  /** Arguments:
    position (I) WCS *position* for this Point entity (DXF 10).
  */
  OdDbPoint(
    const OdGePoint3d& position);

  ~OdDbPoint();
	
  /** Description:
    Returns the WCS *position* of this entity (DXF 10).
  */
  OdGePoint3d position() const;

  /** Description:
    Sets the WCS *position* of this entity (DXF 10).
    Arguments:
    position (I) WCS *position*.
  */
  OdResult setPosition(
    const OdGePoint3d& position);

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
    normal (I) Normal vector.
  */
  OdResult setNormal(
    const OdGeVector3d& normal);

  /** Description:
    Returns the between the OCS X-axis and the X-axis used for displaying this Point entity (DXF 50).
    
    Remarks:
    Used when PDMODE != 0
  */
  double ecsRotation() const;

  /** Description:
    Sets the between the OCS X-axis and the X-axis used for displaying this Point entity (DXF 50).
    
    Arguments:
    rotation (I) Rotation angle.
    
    Remarks:
    Used when PDMODE != 0

    Note:
    All angles are expressed in radians.    
  */
  OdResult setEcsRotation(
    double rotation);

  virtual OdBool isPlanar() const { return ::kTrue; }

  virtual OdResult getPlane(
    OdGePlane& plane,
    OdDb::Planarity& planarity) const;

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

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm);

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  virtual void subViewportDraw(
    OdGiViewportDraw* pVd);

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
    OdGePoint3dArray& points, OdGsMarker thisGsMarker = 0,
    OdGsMarker otherGsMarker = 0) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
    const OdGePlane& projPlane, OdGePoint3dArray& points,
    OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;

  virtual int getUnknown(int type) const;
};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbPoint object pointers.
*/
typedef OdSmartPtr<OdDbPoint> OdDbPointPtr;

#include "TD_PackPop.h"

#endif

