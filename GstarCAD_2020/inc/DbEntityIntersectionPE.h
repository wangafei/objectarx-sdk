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


#ifndef _OD_DB_INTERSECTIONPE_
#define _OD_DB_INTERSECTIONPE_


#include "DbEntity.h"

/** Description:
    This class defines the interface for the Entity Intersection Protocol Extension classes.
    
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class ODRX_ABSTRACT TOOLKIT_EXPORT OdDbEntityIntersectionPE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbEntityIntersectionPE);

  /**
    Description:
    Intersects this entity with other entity if possible.
    
    Arguments:
    pEnt   (I) Pointer to other entity
    inType (I) Determines type of intersection to be calculated
  */
  virtual OdResult intersectWith(
    const OdDbEntity* pThisEnt, const OdDbEntity* pEnt, 
    OdDb::Intersect intType, OdGePoint3dArray& points, 
    OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const = 0;

  virtual OdResult intersectWith(
    const OdDbEntity* pThisEnt, const OdDbEntity* pEnt, 
    OdDb::Intersect intType, const OdGePlane& projPlane, OdGePoint3dArray& points,
    OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const = 0;

  /**
    Description:
    Uses the bounding box of this object to determine an intersection array of points.
  */
  virtual OdResult boundingBoxIntersectWith(
    const OdDbEntity* pThisEnt, const OdDbEntity* pEnt, 
    OdDb::Intersect intType, OdGePoint3dArray& points, 
    OdGsMarker thisGsMarker, OdGsMarker otherGsMarker) const = 0;

  virtual OdResult boundingBoxIntersectWith(
    const OdDbEntity* pThisEnt, const OdDbEntity* pEnt, 
    OdDb::Intersect intType, const OdGePlane& projPlane, OdGePoint3dArray& points,
    OdGsMarker thisGsMarker, OdGsMarker otherGsMarker) const = 0;

  virtual bool isApplicable() const = 0;

  virtual OdResult getGeometryEntity(const OdDbEntity* pThis,
    OdDbVoidPtrArray& ents,
    bool bExtend, 
    int thisGsMarker = 0) const = 0;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class
  for OdDbEntityIntersectionPE object pointers.
*/
typedef OdSmartPtr<OdDbEntityIntersectionPE> OdDbEntityIntersectionPEPtr;

#endif //_OD_DB_INTERSECTIONPE_
