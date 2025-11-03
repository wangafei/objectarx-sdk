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




#ifndef _OD_DB_RADIAL_DIMENSION_
#define _OD_DB_RADIAL_DIMENSION_

#include "TD_PackPush.h"

#include "DbDimension.h"

/** Description:
    This class represents Radial Dimension entities in an OdDbDatabase instance.

    Library:
    TD_Db

    Remarks:
    Radial Dimension entities require a point the curve being dimensioned and
    a *center* point. In additional, leaderLength specifies
    how far the dimension line extends beyond the curve before
    the dogleg to the annotation text. 
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbRadialDimension : public OdDbDimension
{
public:
  ODDB_DECLARE_MEMBERS(OdDbRadialDimension);

  OdDbRadialDimension();
  
  OdDbRadialDimension(  
	 const OdGePoint3d& center,
	 const OdGePoint3d& chordPoint,
	 double leaderLength,
	 const OdChar * dimText = NULL,
	 OdDbObjectId dimStyle = OdDbObjectId::kNull);
  ~OdDbRadialDimension();

  /** Description:
    Sets the length from the chordPoint to the dogleg for this Dimension entity
    (DXF 40).
    
    Arguments:
    leaderLength (I) Leader length.
  */
  OdResult setLeaderLength(
    double leaderLength);

  /** Description:
    Returns the length from the chordPoint to the dogleg for this Dimension entity
    (DXF 40).
  */
  double leaderLength() const; 
  
  /** Description:
    Returns the WCS *center* of the arc being dimensioned by this Dimension entity (DXF 10).
  */
  OdGePoint3d center() const;

  /** Description:
    Sets the WCS *center* of the arc being dimensioned by this Dimension entity (DXF 10).
    Arguments:
    center (I) Center.
  */
  OdResult setCenter(
    const OdGePoint3d& center);
  
  /** Description:
    Returns the WCS chord point for this Dimension entity (DXF 15).
    
    Remarks:
    The chord point is the point at which the dimension line for this Dimension entity
    intersects the curve being dimensioned.
  */
  OdGePoint3d chordPoint() const;

  /** Description:
    Sets the WCS chord point for this Dimension entity (DXF 15).
    
    Arguments:
    chordPoint (I) Chord point.
    
    Remarks:
    The chord point is the point at which the dimension line for this Dimension entity
    intersects the curve being dimensioned.
  */
  OdResult setChordPoint(
    const OdGePoint3d& chordPoint);

  bool extArcOn() const;
  double extArcStartAngle() const;
  OdResult setExtArcStartAngle(double newAngle);
  double extArcEndAngle() const;
  OdResult setExtArcEndAngle(double newAngle);

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
  This template class is a specialization of the OdSmartPtr class for OdDbRadialDimension object pointers.
*/
typedef OdSmartPtr<OdDbRadialDimension> OdDbRadialDimensionPtr;

#include "TD_PackPop.h"

#endif
