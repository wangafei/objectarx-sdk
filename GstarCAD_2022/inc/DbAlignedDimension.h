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




#ifndef _OD_DB_ALIGNED_DIMENSION_
#define _OD_DB_ALIGNED_DIMENSION_

#include "TD_PackPush.h"

#include "DbDimension.h"

/** Description
    This class represents Aligned Dimension entities in an OdDbDatabase instance.

    Remarks:
    An Aligned Dimension entity dimensions the distance between between any two points in space.
    The *normal* of the Dimension entity must be perpendicular to the line between said points. 

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbAlignedDimension : public OdDbDimension
{
public:
  ODDB_DECLARE_MEMBERS(OdDbAlignedDimension);
  
  OdDbAlignedDimension();
  /** 
  Gcad(Add):增加兼容接口	
  */
  OdDbAlignedDimension(
	  const OdGePoint3d& xLine1Point,
	  const OdGePoint3d& xLine2Point,
	  const OdGePoint3d& dimLinePoint,
	  const OdChar*      dimText = NULL,
	  OdDbObjectId       dimStyle = OdDbObjectId::kNull);
  /** 
  Gcad(Add):增加兼容接口	
  */
  ~OdDbAlignedDimension();

  /** Description:
    Returns the WCS start point of the first extension line of this Dimension entity (DXF 13).
  */
  OdGePoint3d xLine1Point() const;

  /** Description:
    Sets the WCS start point of the first extension line of this Dimension entity (DXF 13).
  
    Arguments:
    xLine1Point (I) Start point.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setXLine1Point(
    const OdGePoint3d& xLine1Point);

  /** Description:
    Returns the WCS start point of the second extension line of this Dimension entity (DXF 14).
  */
  OdGePoint3d xLine2Point() const;

  /** Description:
    Sets the WCS start point of the second extension line of this Dimension entity (DXF 14).
  
    Arguments:
    xLine2Point (I) Start point.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setXLine2Point(
    const OdGePoint3d& xLine2Point);
  
  /** Description:
    Returns the WCS point defining the location of dimension line for this Dimension entity (DXF 10).
  */
  OdGePoint3d dimLinePoint() const;

  /** Description:
    Sets the WCS point defining the location of dimension line for this Dimension entity (DXF 10).
    
    Arguments:
    dimLinePoint (I) Dimension line point.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setDimLinePoint(
    const OdGePoint3d& dimLinePoint);
  
  /** Description:
    Returns the obliquing angle for this Dimension entity (DXF 52).
    
    Note:
    All angles are expressed in radians.
  */
  double oblique() const;

  /** Description:
    Sets the obliquing angle for this Dimension entity (DXF 52).
    
    Arguments:
    oblique (I) Obliquing angle.
    
    Note:
    All angles are expressed in radians.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setOblique(
    double oblique);

  bool jogSymbolOn() const;
  //Gcad(Modify):returns:void->OdResult
  OdResult setJogSymbolOn(bool value);

  OdGePoint3d jogSymbolPosition() const;
  //Gcad(Modify):returns:void->OdResult
  OdResult setJogSymbolPosition(const OdGePoint3d& pt);

  double jogSymbolHeight();
  //Gcad(Modify):returns:void->OdResult
  OdResult setJogSymbolHeight(double value);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  //Gcad(Modify):returns:void->OdResult
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  //Gcad(Modify):returns:void->OdResult
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
  This template class is a specialization of the OdSmartPtr class for OdDbAlignedDimension object pointers.
*/
typedef OdSmartPtr<OdDbAlignedDimension> OdDbAlignedDimensionPtr;

#include "TD_PackPop.h"

#endif
