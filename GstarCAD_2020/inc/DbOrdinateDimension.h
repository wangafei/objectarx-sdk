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




#ifndef _OD_DB_ORDINATE_DIMENSION_
#define _OD_DB_ORDINATE_DIMENSION_

#include "TD_PackPush.h"

#include "DbDimension.h"

/** Description:
    This class represents Ordinate Dimension entities in an OdDbDatabase instance.

    Remarks:
    An Ordinate Dimension entity dimensions the horizontal or vertical distance between 
    between the specified *origin* and the specified defining point.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbOrdinateDimension : public OdDbDimension
{
public:
  ODDB_DECLARE_MEMBERS(OdDbOrdinateDimension);

  OdDbOrdinateDimension();
  
  OdDbOrdinateDimension(
	  OdBool				  useXAxis,
	  const OdGePoint3d&  definingPoint,
	  const OdGePoint3d&  leaderEndPoint,
	  const OdChar *      dimText = NULL,
	  OdDbObjectId		  dimStyle  = OdDbObjectId::kNull);
  ~OdDbOrdinateDimension();

  /** Description:
    Returns true if and only if this Dimension entity measures the OCS X-axis distance
    between the *origin* and the defining point. 
    (DXF 70, bit 0x40 set).
  */
  bool isUsingXAxis() const;

  /** Description:
    Returns true if and only if this Dimension entity measures the OCS Y-axis distance
    between the *origin* and the defining point. 
    (DXF 70, bit 0x40 cleared).
  */
  bool isUsingYAxis() const;

  /** Description:
    Sets this Dimension entity to measure the OCS X-axis distance
    between the *origin* and the defining point. 
    (DXF 70, bit 0x40 set).
  */
  OdResult useXAxis();

  /** Description:
    Sets this Dimension entity to measure the OCS Y-axis distance
    between the *origin* and the defining point. 
    (DXF 70, bit 0x40 cleared).
  */
  OdResult useYAxis();
  
  /** Description:
    Returns the WCS *origin* and primary definition point of this Dimension entity (DXF 10).
    
    Remarks:
    This Dimension entity measures the OCS X-axis or OCS Y-axis distance from the *origin* to the defining point.    
  */
  OdGePoint3d origin() const;

  /** Description:
    Sets the WCS *origin* and primary definition point of this Dimension entity (DXF 10).

    Arguments:
    origin (I) Origin.
  
    Remarks:
    This Dimension entity measures the OCS X-axis or OCS Y-axis distance from the *origin* to the defining point.    
  */
  OdResult setOrigin(
    const OdGePoint3d& origin);
  
  /** Description:
    Returns the WCS defining point for this Dimension entity (DXF 13).
    Remarks:
    This Dimension entity measures the OCS X-axis or OCS Y-axis distance from the *origin* to the defining point.    
  */
  OdGePoint3d definingPoint() const;

  /** Description:
    Sets the WCS defining point for this Dimension entity (DXF 13).
    
    Arguments:
    definingPoint (I) Defining point.
    
    Remarks:
    This Dimension entity measures the OCS X-axis or OCS Y-axis distance from the *origin* to the defining point.    
  */
  OdResult setDefiningPoint(
    const OdGePoint3d& definingPoint);
  
  /** Description:
    Returns the WCS leader end point for this Dimension entity (DXF 14).
  */
  OdGePoint3d leaderEndPoint() const;

  /** Description:
    Sets the WCS leader end point for this Dimension entity (DXF 14).
   
    Arguments:
    leaderEndPoint (I) Leader end point. 
  */
  OdResult setLeaderEndPoint(
    const OdGePoint3d& leaderEndPoint);

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

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
  This template class is a specialization of the OdSmartPtr class for OdDbOrdinateDimension object pointers.
*/
typedef OdSmartPtr<OdDbOrdinateDimension> OdDbOrdinateDimensionPtr;

#include "TD_PackPop.h"

#endif
