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

#ifndef OD_GE_CURVE_CURVE_INT_2D_H
#define OD_GE_CURVE_CURVE_INT_2D_H /* {Secret} */

#include "../Ge/GeEntity2d.h"
#include "../Ge/GeInterval.h"
#include "../Ge/GeCurve2d.h"
#include "../Ge/GePointOnCurve2d.h"

#include "../TD_PackPush.h"

/**
    Description:
    This class represents intersections of 2D curves.

    Remarks:
    The intersection object links to 2D curve objects but does not contain
	them. Calculation of the intersection is performed by a calling function, 
	which owns the intersection output.
	
	If one of the curve objects is deleted, the intersection must be recalculated.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeCurveCurveInt2d : public OdGeEntity2d
{
public:
  

  /**
    Description:
    Constructors.

    Arguments:
    curve1 (I) First 2D curve.
    curve2 (I) Second 2D curve.
    range1 (I) Range of first curve.
    range2 (I) Range of second curve.
    tol (I) Geometric tolerance.
    source (I) Object to be cloned.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeCurveCurveInt2d();
  OdGeCurveCurveInt2d(
    const OdGeCurve2d& curve1, 
    const OdGeCurve2d& curve2,
    const OdGeTol& tol = OdGeContext::gTol);
  OdGeCurveCurveInt2d(
    const OdGeCurve2d& curve1, 
    const OdGeCurve2d& curve2,
    const OdGeInterval& range1, 
    const OdGeInterval& range2,
    const OdGeTol& tol = OdGeContext::gTol);
  OdGeCurveCurveInt2d(
    const OdGeCurveCurveInt2d& source);

  // General query functions.
  //

  /**
    Description:
    Returns the first curve.

    Note:
    By default this function throws exception "not Implemented".
  */
  const OdGeCurve2d  *curve1() const;

  /**
    Description:
    Returns the second curve.

    Note:
    By default this function throws exception "not Implemented".
  */
  const OdGeCurve2d  *curve2() const;

  /**
    Description:
    Returns the ranges of the two curves.

    Arguments:
    range1 (O) Receives the range of the first curve.
    range2 (O) Receives the range of the second curve.

    Note:
    By default this function throws exception "not Implemented".
  */
  void getIntRanges(
    OdGeInterval& range1,
    OdGeInterval& range2) const;

  /**
    Description:
    Returns the tolerance for determining intersections.

    Note:
    By default this function throws exception "not Implemented".
  */
 OdGeTol tolerance() const;

  // Intersection query methods.
  //

  /**
    Description:
    Returns the number of intersections between the curves within the specified ranges.

    Note:
    By default this function throws exception "not Implemented".
  */
  int numIntPoints() const;

  /**
    Description:
    Returns the specified intersection point.

    Arguments:
    intNum (I) The zero-based index of the intersection point to return.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGePoint2d intPoint(
    int intNum) const;

  /**
    Description:
    Returns the curve parameters at the specified intersection point.

    Arguments:
    intNum (I) The zero-based index of the intersection point to return.
    param1 (O) Receives the parameter of the first curve at the intersection point.
    param2 (O) Receives the parameter of the second curve at the intersection point.

    Note:
    By default this function throws exception "not Implemented".
  */
  void getIntParams(
    int intNum,
    double& param1, 
    double& param2) const;

  /**
    Description:
    Returns the specified intersection point as an OdGePointOnCurve2d on the first curve.

    Arguments:
    intNum (I) The zero-based index of the intersection point to return.
    intPnt (O) Receives the specified intersection point on the first curve.

    Note:
    By default this function throws exception "not Implemented".
  */
  void getPointOnCurve1(
    int intNum, 
    OdGePointOnCurve2d& intPnt) const;

  /**
    Description:
    Returns the specified intersection point as an OdGePointOnCurve2d on the second curve.

    Arguments:
    intNum (I) The zero-based index of the intersection point to return.
    intPnt (O) Receives the specified intersection point on the second curve.

    Note:
    By default this function throws exception "not Implemented".
  */
  void getPointOnCurve2(
    int intNum, 
    OdGePointOnCurve2d& intPnt) const;

  /**
    Description:
    Returns the configuration of the intersecion point of
    the first curve with respect to the second, and vice versa.

    Arguments:
    intNum (I) The zero-based index of the intersection point to query.
    config1wrt2 (O) Receives the configuration of the first curve with respect to the second.
    config2wrt1 (O) Receives the configuration of the second curve with respect to the first.

    Remarks:
    The possible values for config1wrt2 and config2wrt1 are as follows

    @untitled table
    kNotDefined
    kUnknown
    kLeftRight
    kRightLeft
    kLeftLeft
    kRightRight
    kPointLeft
    kPointRight
    kLeftOverlap
    kOverlapLeft
    kRightOverlap
    kOverlapRight
    kOverlapStart
    kOverlapEnd,
    kOverlapOverlap

    Note:
    By default this function throws exception "not Implemented".
  */
  void getIntConfigs(
    int intNum, 
    OdGe::OdGeXConfig& config1wrt2,
    OdGe::OdGeXConfig& config2wrt1) const;

  /**
    Description:
    Returns true if and only if the curves are tangential at specified intersection point 

    Arguments:
    intNum (I) The zero-based index of the intersection point to query.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool isTangential (
    int intNum) const;

  /**
    Description:
    Returns true if and only if the curves are transversal (cross) at specified intersection point 

    Arguments:
    intNum (I) The zero-based index of the intersection point to query.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool isTransversal (
    int intNum) const;

  /**
    Description:
    Returns the tolerance used to compute the specified intersection point. 

    Arguments:
    intNum (I) The zero-based index of the intersection point to query.

    Note:
    By default this function throws exception "not Implemented".
  */
  double intPointTol(
    int intNum) const;

  /**
    Description:
    Returns the number of intervals of overlap for the two curves. 

    Note:
    By default this function throws exception "not Implemented".
  */
  int overlapCount() const;

  /**
    Description:
    Returns true if and only if the curves are oriented in the same direction
    where they overlap. 

    Remarks:
    This value has meaning only if overlapCount() > 0

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool overlapDirection () const;

  /**
    Description:
    Returns the ranges for each curve a the specified overlap. 

    Arguments:
    overlapNum (I) The zero-based index of the overlap range to query.
    range1 (O) Receives the range of the first curve for the specified overlap.
    range2 (O) Receives the range of the second curve for the specified overlap.

    Note:
    By default this function throws exception "not Implemented".
  */
  void getOverlapRanges(
    int overlapNum,
    OdGeInterval& range1,
    OdGeInterval& range2) const;

  /**
    Description:
    Makes the first curve the second, and vice versa.

    Note:
    By default this function throws exception "not Implemented".
  */
  void changeCurveOrder(); 

  /**
    Description:
    Orders the intersection points so they correspond to
    increasing parameter values of the first curve.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeCurveCurveInt2d& orderWrt1();

  /**
    Description:
    Orders the intersection points so they correspond to
    increasing parameter values of the second curve.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeCurveCurveInt2d& orderWrt2();

  /**
    Description:
    Sets the curves, ranges and tolerance for which to
    determine intersections

    Arguments:
    curve1 (I) First 2D curve.
    curve2 (I) Second 2D curve.
    range1 (I) Range of first curve.
    range2 (I) Range of second curve.
    tol (I) Geometric tolerance.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeCurveCurveInt2d& set(
    const OdGeCurve2d& curve1,
    const OdGeCurve2d& curve2,
    const OdGeTol& tol = OdGeContext::gTol);
  OdGeCurveCurveInt2d& set(
    const OdGeCurve2d& curve1,
    const OdGeCurve2d& curve2,
    const OdGeInterval& range1,
    const OdGeInterval& range2,
    const OdGeTol& tol = OdGeContext::gTol);

  /**
    Note:
    This function is not implemented, and will generate a link error if you reference it.
    It will be implemented in a future release.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeCurveCurveInt2d& operator =(
    const OdGeCurveCurveInt2d& crvCrvInt);

  //////////////////////////////////////////////////////////////////////////
};

#include "../TD_PackPop.h"

#endif // OD_GE_CURVE_CURVE_INT_2D_H
