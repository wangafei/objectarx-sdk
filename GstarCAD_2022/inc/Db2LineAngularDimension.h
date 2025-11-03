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




#ifndef _OD_DB_2LINEANGULAR_DIMENSION_
#define _OD_DB_2LINEANGULAR_DIMENSION_

#include "TD_PackPush.h"

#include "DbDimension.h"

/** Description:
    This class represents 2-Line Angular Dimension entities in an OdDbDatabase instance.
    
    Remarks:
    A 2-Line Angular Dimension entity dimensions the angle defined by two lines.
    
    See also:
    OdDb3PointAngularDimension
    
    Library:
    TD_Db

    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDb2LineAngularDimension : public OdDbDimension
{
public:
  ODDB_DECLARE_MEMBERS(OdDb2LineAngularDimension);

  OdDb2LineAngularDimension();

  OdDb2LineAngularDimension(
	  const OdGePoint3d& xLine1Start,
	  const OdGePoint3d& xLine1End,
	  const OdGePoint3d& xLine2Start,
	  const OdGePoint3d& xLine2End,
	  const OdGePoint3d& arcPoint,
	  const OdChar*      dimText = NULL,
	  OdDbObjectId       dimStyle = OdDbObjectId::kNull);

  ~OdDb2LineAngularDimension();

  /** Description:
    Returns the point defining the location of dimension arc for this Dimension entity (DXF 16 as WCS).
  */
  OdGePoint3d arcPoint() const;

  /** Description:
    Sets the point defining the location of dimension arc for this Dimension entity (DXF 16 as WCS).
    Arguments:
    arcPoint (I) Arc point.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setArcPoint(
    const OdGePoint3d& arcPoint);
  
  /** Description:
    Returns the WCS start point of the first extension line of this Dimension entity (DXF 13).
  */
  OdGePoint3d xLine1Start() const;

  /** Description:
    Sets the WCS start point of the first extension line of this Dimension entity (DXF 13).
    Arguments:
    xLine1Start (I) Start point.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setXLine1Start(
    const OdGePoint3d& xLine1Start);
  
  /** Description:
    Returns the WCS end point of the first extension line of this Dimension entity (DXF 14).
  */
  OdGePoint3d xLine1End() const;

  /** Description:
    Sets the WCS end point of the first extension line of this Dimension entity (DXF 14).
    Arguments:
    xLine1End (I) End point.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setXLine1End(
    const OdGePoint3d& xLine1End);
  
  /** Description:
    Returns the WCS start point of the second extension line of this Dimension entity (DXF 15).
  */
  OdGePoint3d xLine2Start() const;

  /** Description:
    Sets the WCS start point of the second extension line of this Dimension entity (DXF 15).
    Arguments:
    xLine2Start (I) Start point.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setXLine2Start(
    const OdGePoint3d& xLine2Start);
  
  /** Description:
    Returns the WCS end point of the second extension line of this Dimension entity (DXF 10).
  */
  OdGePoint3d xLine2End() const;

  /** Description:
    Sets the WCS end point of the second extension line of this Dimension entity (DXF 10).
    Arguments:
    xLine2End (I) End point.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setXLine2End(
    const OdGePoint3d& xLine2End);

  bool extArcOn() const;
  //Gcad(Modify):returns:void->OdResult
  OdResult setExtArcOn(bool value);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  // Gcad(Modify):returns:void->OdResult
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  // Gcad(Modify):returns:void->OdResult
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDb2LineAngularDimension object pointers.
*/
typedef OdSmartPtr<OdDb2LineAngularDimension> OdDb2LineAngularDimensionPtr;

#include "TD_PackPop.h"

#endif
