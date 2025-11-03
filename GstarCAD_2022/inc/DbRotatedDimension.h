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




#ifndef _DB_ROTATED_DIMENSION_
#define _DB_ROTATED_DIMENSION_

#include "TD_PackPush.h"

#include "DbDimension.h"

/** Description
    This class represents Rotated Dimension entities in an OdDbDatabase instance.

    Remarks:
    A Rotated Dimension entity dimensions the distance between between any two points in space
    as projected onto a line at the specfied rotation angle in the plane of the dimension.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbRotatedDimension : public OdDbDimension
{
public:
  ODDB_DECLARE_MEMBERS(OdDbRotatedDimension);

  OdDbRotatedDimension();
  
  OdDbRotatedDimension(
       double rotation,
       const OdGePoint3d& xLine1Point,
       const OdGePoint3d& xLine2Point,
       const OdGePoint3d& dimLinePoint,
	   const OdChar * dimText = NULL,
       OdDbObjectId dimStyle = OdDbObjectId::kNull);
  ~OdDbRotatedDimension();

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
  */
  OdResult setOblique(
    double oblique);
  
  /** Description:
    Returns the *rotation* angle for this Dimension entity (DXF 50).
    
    Remarks:
    The *rotation* angle is measured from the OCS X-axis to the dimension line of
    this Dimension entity.

    Note:
    All angles are expressed in radians.
  */
  double rotation() const;

  /** Description:
    Sets the *rotation* angle for this Dimension entity (DXF 50).
    
    Arguments:
    rotation (I) Rotation angle.

    Remarks:
    The *rotation* angle is measured from the OCS X-axis to the dimension line of
    this Dimension entity.

    Note:
    All angles are expressed in radians.
  */
  OdResult setRotation(double rotation);

  bool jogSymbolOn() const;
  OdResult setJogSymbolOn(bool value);

  OdGePoint3d jogSymbolPosition() const;
  OdResult setJogSymbolPosition(const OdGePoint3d& pt);

  double jogSymbolHeight();
  OdResult setJogSymbolHeight(double value);

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
  This template class is a specialization of the OdSmartPtr class for OdDbRotatedDimension object pointers.
*/
typedef OdSmartPtr<OdDbRotatedDimension> OdDbRotatedDimensionPtr;

#include "TD_PackPop.h"

#endif
