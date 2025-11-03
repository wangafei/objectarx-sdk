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




#ifndef _OD_DB_3POINTANGULAR_DIMENSION_
#define _OD_DB_3POINTANGULAR_DIMENSION_

#include "TD_PackPush.h"

#include "DbDimension.h"

/** Description:
    This class represents 3-Point Angular Dimension entities in an OdDbDatabase instance.

    Remarks:
    A 3-Point Angular Dimension entity dimensions the angle defined by three points.
    
    See also:
    OdDb2LineAngularDimension
    
    Library:
    TD_Db

    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDb3PointAngularDimension : public OdDbDimension
{
public:

  ODDB_DECLARE_MEMBERS(OdDb3PointAngularDimension);

  OdDb3PointAngularDimension();
  /** 
  Gcad(Add):增加兼容接口	
  */
  OdDb3PointAngularDimension(
	  const OdGePoint3d& centerPoint,
	  const OdGePoint3d& xLine1Point,
	  const OdGePoint3d& xLine2Point,
	  const OdGePoint3d& arcPoint,
	  const OdChar*      dimText = NULL,
	  OdDbObjectId       dimStyle = OdDbObjectId::kNull);
  /** 
  Gcad(Add):增加兼容接口	
  */
  ~OdDb3PointAngularDimension();

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
      
    Remarks:
    This point and the centerPoint define one side of 
    the angle being dimensioned.
  */
  OdGePoint3d xLine1Point() const;

  /** Description:
    Sets the WCS start point of the first extension line of this Dimension entity (DXF 13).
  
    Arguments:
    xLine1Point (I) Start point.
        
    Remarks:
    This point and the centerPoint define one side of 
    the angle being dimensioned.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setXLine1Point(
    const OdGePoint3d& xLine1Point);

  /** Description:
    Returns the WCS start point of the second extension line of this Dimension entity (DXF 14).
      
    Remarks:
    This point and the centerPoint define one side of 
    the angle being dimensioned.
  */
  OdGePoint3d xLine2Point() const;

  /** Description:
    Sets the WCS start point of the second extension line of this Dimension entity (DXF 14).
  
    Arguments:
    xLine2Point (I) Start point.
        
    Remarks:
    This point and the centerPoint define one side of 
    the angle being dimensioned.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setXLine2Point(
    const OdGePoint3d& xLine2Point);

  
  /** Description:
    Returns the WCS vertex of the angle being dimensioned by this Dimension entity (DXF 15).
    Remarks:
    The vertex of the angle being dimensioned is the center of the dimension arc.
  */
  OdGePoint3d centerPoint() const;

  // Angular dimension extension arc for quadrant
  bool extArcOn() const;
  //Gcad(Modify):returns:void->OdResult
  OdResult setExtArcOn(bool value);

  /** Description:
    Sets the WCS vertex of the angle being dimensioned by this Dimension entity (DXF 15).
    Arguments:
    centerPoint (I) Center point.
    Remarks:
    The vertex of the angle being dimensioned is the center of the dimension arc.

	Gcad(Modify):returns:void->OdResult
 */
  OdResult setCenterPoint(
    const OdGePoint3d& centerPoint);

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
  This template class is a specialization of the OdSmartPtr class for OdDb3PointAngularDimension object pointers.
*/
typedef OdSmartPtr<OdDb3PointAngularDimension> OdDb3PointAngularDimensionPtr;

#include "TD_PackPop.h"

#endif
