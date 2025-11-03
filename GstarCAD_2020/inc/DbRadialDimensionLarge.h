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



#ifndef _OD_DB_RADIALDIMENSIONLARGE_DIMENSION_
#define _OD_DB_RADIALDIMENSIONLARGE_DIMENSION_

#include "TD_PackPush.h"

#include "DbDimension.h"

/** Description:
    This class represents Large (Jogged) Radial Dimension entities in an OdDbDatabase instance.

    Library:
    TD_Db

    Remarks:
    Jogged Radial Dimension entities are used to dimension arcs with large radii.
    They require a point the curve being dimensioned and along with an overridden 
    *center* point, a jog point, and a jog angle. 

    {group:OdDb_Classes}

*/
class TOOLKIT_EXPORT OdDbRadialDimensionLarge : public OdDbDimension
{
public:
  ODDB_DECLARE_MEMBERS(OdDbRadialDimensionLarge);

  OdDbRadialDimensionLarge();
  OdDbRadialDimensionLarge(
	  const OdGePoint3d& center,
	  const OdGePoint3d& chordPoint,
	  const OdGePoint3d& overrideCenter,
	  const OdGePoint3d& jogPoint,
	  double             jogAngle,
	  const OdChar *      dimText = NULL,
	  OdDbObjectId       dimStyle = OdDbObjectId::kNull);
  ~OdDbRadialDimensionLarge();

  /** Description:
    Returns the WCS *center* of the arc being dimensioned by this Dimension entity (DXF 10).
  */
  OdGePoint3d center() const;
  
  /** Description:
    Sets the WCS *center* of the arc being dimensioned by this Dimension entity (DXF 10).
    Arguments:
    center (I) Center.
  */
  OdResult setCenter(const OdGePoint3d& center);

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
  OdResult setChordPoint(const OdGePoint3d & chordPoint);

  /** Description:
    Returns the WCS override  *center* of the arc being dimensioned by this Dimension entity.
  */
  OdGePoint3d overrideCenter() const;

  /** Description:
    Sets the WCS override *center* of the arc being dimensioned by this Dimension entity.
    Arguments:
    overrideCenter (I) Override *center*.
  */
  OdResult   setOverrideCenter(const OdGePoint3d& overrideCenter);

  /** Description:
    Returns the jog point for this Dimension entity.
  */
  OdGePoint3d jogPoint() const;

  /** Description:
    Sets the jog point for this Dimension entity.
    Arguments:
    jogPoint (I) Jog point.
  */
  OdResult   setJogPoint(const OdGePoint3d& jogPoint);

  /** Description:
    Returns the jog angle for this Dimension entity.
    Note:
    All angles are expressed in radians.
  */
  double jogAngle() const;

  /** Description:
    Sets the jog angle for this Dimension entity.
    Arguments:
    jogAngle (I) Jog angle.
    Note:
    All angles are expressed in radians.
  */
  OdResult  setJogAngle(const double jogAngle);

  // void   setOverrideCenterPP(const OdGePoint3d& p);
  // void   setJogPointPP(const OdGePoint3d& p);
  // void   setTextPositionPP(const OdGePoint3d& p);

   OdResult   setOverrideCenterPP(const OdGePoint3d& overrideCenterPointPP);
  /** Description:
      Returns status of extension arc property.
  */
  OdResult   setJogPointPP(const OdGePoint3d& jogPointPP);
   OdResult   setTextPositionPP(const OdGePoint3d& textPointPP);
  bool extArcOn() const;

  double extArcStartAngle() const;
  OdResult setExtArcStartAngle(double newAngle);

  double extArcEndAngle() const;
  OdResult setExtArcEndAngle(double newAngle);

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

  /*
  OdDbRadialDimensionLarge(
  const OdGePoint3d& center,
  const OdGePoint3d& chordPnt,
  const OdGePoint3d& overrideCenter,
  const OdGePoint3d& jogPnt,
  double             jogAng,
  const OdString*    dimText = 0,
  OdDbObjectId       dimStyle = OdDbObjectId::kNull);
  */
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbRadialDimensionLarge object pointers.
*/
typedef OdSmartPtr<OdDbRadialDimensionLarge> OdDbRadialDimensionLargePtr;

#include "TD_PackPop.h"

#endif
