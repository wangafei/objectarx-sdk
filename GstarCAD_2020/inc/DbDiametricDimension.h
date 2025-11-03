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




#ifndef _OD_DB_DIAMETRIC_DIMENSION_
#define _OD_DB_DIAMETRIC_DIMENSION_

#include "TD_PackPush.h"

#include "DbDimension.h"

/** Description:
    This class represents Diametric Dimension entities in an OdDbDatabase instance.

    Remarks:
    Diametric Dimension entities require two points defining the diameter of the
    curve being dimensioned. In additional, an optional leaderLength may be 
    used to specify how far the dimension line extends beyond the curve before
    the dogleg to the annotation text. 
    
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDiametricDimension : public OdDbDimension
{
public:

  ODDB_DECLARE_MEMBERS(OdDbDiametricDimension);

  OdDbDiametricDimension();

  OdDbDiametricDimension(
	  const OdGePoint3d& chordPoint,
	  const OdGePoint3d& farChordPoint,
	  double             leaderLength,
	  const OdChar*      dimText = NULL,
	  OdDbObjectId       dimStyle = OdDbObjectId::kNull);

  ~OdDbDiametricDimension();

  /** Description:
    Sets the length from the chordPoint to the dogleg for this Dimension entity
    (DXF 40).
    
    Arguments:
    leaderLength (I) Leader length.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setLeaderLength(
    double leaderLength);

  /** Description:
    Returns the length from the chordPoint to the dogleg for this Dimension entity
    (DXF 40).
  */
  double leaderLength() const; 
  
  /** Description:
    Returns the WCS chord point for this Dimension entity (DXF 15).
    
    Remarks:
    The chord point is the point at which the dimension line for this Dimension entity
    intersects the curve being dimensioned, and would extend beyond it if the annotation
    text is outside the curve.
    
    It is the point on the diameter opposite farChordPoint.
  */
  OdGePoint3d chordPoint() const;

  /** Description:
    Sets the WCS chord point for this Dimension entity (DXF 15).
    
    Arguments:
    chordPoint (I) Chord point.
    
    Remarks:
    The chord point is the point at which the dimension line for this Dimension entity
    intersects the curve being dimensioned, and would extend beyond it if the annotation
    text is outside the curve.

    It is the point on the diameter opposite farChordPoint.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setChordPoint(
    const OdGePoint3d& chordPoint);
  
  /** Description:
    Returns the WCS far chord point for this Dimension entity (DXF 10).
    
    Remarks:
    The far chord point is the point on the diameter opposite chordPoint.  
  */
  OdGePoint3d farChordPoint() const;

  /** Description:
    Sets the WCS far chord point for this Dimension entity (DXF 10).

    Arguments:
    farChordPoint (I) Far chord point.  

    Remarks:
    The far chord point is the point on the diameter opposite chordPoint. 

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setFarChordPoint(
    const OdGePoint3d& farChordPoint);

  // Diametric dimension extension arc
  bool extArcOn() const;

  double extArcStartAngle() const;
  //Gcad(Modify):returns:void->OdResult
  OdResult setExtArcStartAngle(double newAngle);

  double extArcEndAngle() const;
  //Gcad(Modify):returns:void->OdResult
  OdResult setExtArcEndAngle(double newAngle);

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
  This template class is a specialization of the OdSmartPtr class for OdDbDiametricDimension object pointers.
*/
typedef OdSmartPtr<OdDbDiametricDimension> OdDbDiametricDimensionPtr;

#include "TD_PackPop.h"

#endif
