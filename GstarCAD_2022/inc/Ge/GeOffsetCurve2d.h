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

#ifndef OD_GE_OFFSET_CURVE_2D_H
#define OD_GE_OFFSET_CURVE_2D_H /* {Secret} */

#include "../Ge/GeCurve2d.h"

#include "../TD_PackPush.h"

/**
    Description:
    This class represents 2D curves that are exact offsets of other curves.

    Remarks:
    Every GeOffsetCurve2d contains a pointer to the *curve* from which it is offest.
    Modifying the base *curve* modifies the offset *curve*. Modifying the offset *curve*
    does not modify the base *curve*. setInterval() for an offset *curve* result create a *curve* that
    is an offset of the specified interval in the base *curve*.

    This *curve* may be self-intersecting, even if the base *curve* is not.

    Positive offset *distance*s at any *point* on the base *curve* are defined as 90?counterclockwise
    from the tangent of the base *curve* at that *point*.

    An offset *curve* with a 0.0 offset *distance* is exact replica of the base *curve*. An offseet *curve* with
    a non-zero 0.0 offset *distance* has a continuity of one less than that of the base *curve*. 
    To insure that the offset *curve* is a valid *curve*, the base *curve* must have a continuity
    of at least 1.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeOffsetCurve2d : public OdGeCurve2d
{
public:
  

  /**
    Arguments:
    baseCurve (I) Any 2D *curve*.
    offsetDistance (I) Offset *distance*.
    source (I) Object to be cloned.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeOffsetCurve2d(
    const OdGeCurve2d& baseCurve, 
    double offsetDistance);
  OdGeOffsetCurve2d(
    const OdGeOffsetCurve2d& source);

  /**
    Description:
    Returns the base *curve*. 

    Note:
    By default this function throws exception "not Implemented".
  */
  const OdGeCurve2d* curve() const;

  /**
    Description:
    Returns the offset *distance* of this *curve*. 

    Note:
    By default this function throws exception "not Implemented".
  */
  double offsetDistance() const;

  /**
    Description:
    Returns true if and only if this *curve* has the same parameter *direction* as the base *curve*.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool paramDirection() const;

  /**
    Description:
    Returns the concatenation of the *transformation* matrices applied to this *curve* with transformBy(). 

    Remarks:
    If no *transformation* matrices have been applied to this *curve*, returns the identity matrix.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeMatrix2d transformation() const;

  /**
    Description: 
    Sets the base *curve* for this *curve*.

    Arguments:
    baseCurve (I) Any 2D *curve*.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeOffsetCurve2d& setCurve(
    const OdGeCurve2d& baseCurve);

  /**
    Description: 
    Sets the offset *distance* for this *curve*.

    Arguments:
    offsetDistance (I) Offset *distance*.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeOffsetCurve2d& setOffsetDistance(
    double distance);

  OdGeOffsetCurve2d& operator = (
    const OdGeOffsetCurve2d& offsetCurve);

 
  //////////////////////////////////////////////////////////////////////////
  // TD Special overrides :
};

#include "../TD_PackPop.h"

#endif // OD_GE_OFFSET_CURVE_2D_H
