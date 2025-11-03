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

#ifndef OD_GE_CURVE_2D_H
#define OD_GE_CURVE_2D_H /* {Secret} */

class OdGePointOnCurve2d;
class OdGeInterval;
class OdGeMatrix2d;
class OdGeLine2d;
class OdGePointOnCurve2dData;
class OdGeBoundBlock2d;
class OdGeCurve3dImpl;

#include "../Ge/GeEntity2d.h"
#include "../Ge/GeIntArray.h"
#include "../Ge/GePoint2d.h"
#include "../Ge/GePoint2dArray.h"
#include "../Ge/GeVector2d.h"
#include "../Ge/GeVector2dArray.h"
#include "../Ge/GeCurve2dPtrArray.h"
#include "../Ge/GeDoubleArray.h"
#include "../Ge/GeVoidPointerArray.h"

#include "../TD_PackPush.h"

/**
    Description:
    This class is the base class for all OdGe 2D curves.

    Library: TD_Ge

   {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeCurve2d : public OdGeEntity2d
{
public:
  

  /**
    Description:
    Returns the parametric *interval* of the *curve*.

    Arguments:
    interval (O) Receives the parametric *interval* of the *curve*.

    Note:
    By default this function throws exception "not Implemented".
  */
  void getInterval(
    OdGeInterval& interval) const;

  /**
    Description:
    Returns the parametric *interval* of the *curve*.

    Arguments:
    interval (O) Receives the parametric *interval* of the *curve*.
    start (O) Receives the start point of interval.
    end (O) Receives the end point of interval. 

    Note:
    By default this function throws exception "not Implemented".
  */
  void getInterval(
    OdGeInterval& interval, 
    OdGePoint2d& start,
    OdGePoint2d& end) const;

  /**
    Description:
    Reverses the parameter *direction* this *curve*.   

    Remarks:
    The *point* *set* of this *curve* is unchanged.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeCurve2d& reverseParam();
  
  /**
    Description:
    Sets to natural domain of the curve

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeCurve2d& setInterval();

  /**
    Description:
    Sets the parametric *interval* of this *curve*.

    Arguments:
    interval (I) Parametric *interval* of this *curve*

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool setInterval (
    const OdGeInterval& interval);

  /**
    Description:
    Returns the distance between the input point and the closest 
    point on this curve.

    Note:
    By default this function throws exception "not Implemented".
  */
  double distanceTo(
    const OdGePoint2d& point,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the distance between the closest points between this 
    curve and the input curve.

    Note:
    By default this function throws exception "not Implemented".
  */
  double distanceTo(
    const OdGeCurve2d& otherCur,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Finds the closest point on this curve to the input point. 

    Note:
    This function is the same as getClosestPointTo().
  */
  OdGePoint2d closestPointTo(
    const OdGePoint2d& point,
    const OdGeTol& tol = OdGeContext::gTol) const;
  
  /**
    Description:
    Finds the closest points between this curve and the input curve.

    Note:
    This function is the same as getClosestPointTo().
  */
  OdGePoint2d closestPointTo(
    const OdGeCurve2d& curve2d,
    OdGePoint2d& pntOnOtherCrv,
    const OdGeTol& tol= OdGeContext::gTol) const;

  /**
    Description:
    Finds the closest point on this curve to the input point. 

    Note:
    By default this function throws exception "not Implemented".
  */
  void getClosestPointTo(
    const OdGePoint2d& point,
    OdGePointOnCurve2d& pntOnCrv,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Finds the closest points between this curve and the input curve.

    Note:
    By default this function throws exception "not Implemented".
  */
  void getClosestPointTo(
    const OdGeCurve2d& curve2d,
    OdGePointOnCurve2d& pntOnThisCrv,
    OdGePointOnCurve2d& pntOnOtherCrv,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Finds the point on the input curve whose normal passes through the input point. 

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool getNormalPoint(
    const OdGePoint2d& point,
    OdGePointOnCurve2d& pntOnCrv,
    const OdGeTol& tol = OdGeContext::gTol) const;

  TD_USING(OdGeEntity2d::isOn);

  /**
    Description:
    Determines if pnt lies on curve. 
    The param parameter is only set to a meaningful value 
    if this function returns true.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool isOn(
    const OdGePoint2d& point, 
    double& param,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Determines if input parameter value is within valid parametric range of curve.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool isOn(
    double param,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the parameter value of a *point*.

    Arguments:
    point (I) Input point on the curve.
    tol (I) Geometric tolerance.

    Remarks:
    The returned parameters specify a *point* within tol of point.
    If point is not on the *curve*, the results are unpredictable.
    If you are not sure the *point* is on the *curve*, use 
    isOn () instead of this function.

    Note:
    By default this function throws exception "not Implemented".
  */
  double paramOf(
    const OdGePoint2d& point,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Return the offset of the curve.

    Note:
    By default this function throws exception "not Implemented".
  */
  void getTrimmedOffset(
    double distance,
    OdGeVoidPointerArray& offsetCurveList,
    OdGe::OffsetCrvExtType extensionType = OdGe::kFillet,
    const OdGeTol& tol = OdGeContext::gTol) const;
	
  /**
    Description:
    Returns true if and only if the *curve* is closed within the specified tolerance.

    Arguments:
    tol (I) Geometric tolerance.
  */
  OdBool isClosed(
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Determines if the curve is periodic. The curve is periodic if and 
    only if it is closed and the two points evalPoint(t) and 
    evalPoint(t+period) are always the same point for all values of t. 

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool isPeriodic(
    double& period) const;

  /**
    Description:
    Returns true, and a linear entity coincident with this *curve*,
    if and only if this *curve* is linear.

    Arguments:
    line (O) Receives the *line* coincident with this *curve*.
    tol (I) Geometric tolerance.

    Remarks:
    An infinite *line* is returned, even if this *curve* is bounded.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool isLinear(
    OdGeLine2d& line, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the arc length of the curve between the two parameter values.

    Note:
    By default this function throws exception "not Implemented".
  */
  double length(
    double fromParam, 
    double toParam,
    double tol
#ifndef SWIG
    = OdGeContext::gTol.equalPoint()
#endif
    ) const;
  
  double length(
    double tol 
#ifndef SWIG
    = OdGeContext::gTol.equalPoint()
#endif
    ) const;

  /**
    Description:
    Returns the parameter value of the point whose arc length distance.

    Note:
    By default this function throws exception "not Implemented".
  */
  double paramAtLength(
    double datumParam, 
    double length,
    bool posParamDir 
#ifndef SWIG
    = true
#endif
    , double tol 
#ifndef SWIG
    = OdGeContext::gTol.equalPoint()
#endif
    ) const;

  /**
    Description:
    Returns the area of the interval of the curve defined by 
    startParam and endParam. 

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool area(
    double startParam, double endParam,
    double& value, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Determines if the curve is degenerate and if so 
    returns type of entity that the curve degenerates 

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool isDegenerate(
    OdGe::EntityId& degenerateType,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Determines if the curve is degenerate and if so returns 
    the entity that the curve degenerates into.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool isDegenerate(
    OdGeEntity2d*& pConvertedEntity,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns two segments that are obtained by splitting the curve 
    at the input parameter value. If the specified parameter value
    does not lie within the parametric interval of the curve or if
    it corresponds to the start or endpoint of the curve, then piece1
    and piece2 are set to null.

    Note:
    By default this function throws exception "not Implemented".
  */
  void getSplitCurves(
    double param, 
    OdGeCurve2d*& piece1,
    OdGeCurve2d*& piece2) const;

  /**
    Description:
    Explode curve into its component sub-curves.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool explode(
    OdGeVoidPointerArray& explodedCurves,
    OdGeIntArray& newExplodedCurve,
    const OdGeInterval* interval = NULL) const;

  /**
    Description:
    Local closest points.

    Note:
    By default this function throws exception "not Implemented".
  */
  void getLocalClosestPoints(
    const OdGePoint2d& point,
    OdGePointOnCurve2d& approxPnt,
    const OdGeInterval* nbhd = NULL,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:

    Note:
    By default this function throws exception "not Implemented".
  */
  void getLocalClosestPoints(
    const OdGeCurve2d& otherCurve,
    OdGePointOnCurve2d& approxPntOnThisCrv,
    OdGePointOnCurve2d& approxPntOnOtherCrv,
    const OdGeInterval* nbhd1 = NULL,
    const OdGeInterval* nbhd2 = NULL,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    oriented bounding box of curve.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeBoundBlock2d boundBlock() const;
  OdGeBoundBlock2d boundBlock(
    const OdGeInterval& range) const;

  /**
    Description:
    bounding box whose sides are parallel to coordinate axes.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeBoundBlock2d orthoBoundBlock() const;
  OdGeBoundBlock2d orthoBoundBlock(
    const OdGeInterval& range) const;

  /**
    Description:
    Returns true, and the start point, if and only if the parametric *interval* of the *curve* has a lower bound.

    Arguments:
    startPoint (O) Receives the start point of the interval.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool hasStartPoint(
    OdGePoint2d& startPoint) const;

  /**
    Description:
    Returns true, and the end point, if and only if the parametric *interval* of the *curve* has an upper bound.

    Arguments:
    endPoint (O) Receives the end point of the interval.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool hasEndPoint(
    OdGePoint2d& endPoint) const;

  /**
    Description:
    Returns the *point* on the *curve* corresponding to the specified parameter value, and the derviatives at that *point*.

    Arguments:
    param (I) Parameter to be evaluated.
    numDeriv (I) The number of *derivatives* to be computed 
                 (should not be set larger than 2). 
    derivatives (O) Receives an array of *derivatives* at the point corresponding to param.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGePoint2d evalPoint(
    double param) const;
  OdGePoint2d evalPoint(
    double param, 
    int numDeriv,
    OdGeVector2dArray& derivatives) const;

  /**
    Description:
    Returns sample points along this *curve* and their parameter values in the specified arrays.

    Arguments:
    fromParam (I) Starting parameter value.
    toParam (I) Ending parameter value.
    approxEps (I) Approximate spacing along a *curve*.
    pointArray Returns an array of sample points.
    paramArray Returns an array of parameters at each *point*.
  */
  void getSamplePoints(
    double fromParam, 
    double toParam, 
    double approxEps, 
    OdGePoint2dArray& pointArray, 
    OdGeDoubleArray& paramArray) const;
  void getSamplePoints(
    int numSample, 
    OdGePoint2dArray& pointArray) const;

  void appendSamplePoints(
    int numSample,
    OdGePoint2dArray& pointArray
    ) const;
  void appendSamplePoints(
    double fromParam,
    double toParam,
    double approxEps,
    OdGePoint2dArray& pointArray) const;
  void appendSamplePoints(
    double fromParam, 
    double toParam, 
    double approxEps, 
    OdGePoint2dArray& pointArray, 
    OdGeDoubleArray& paramArray) const;

  OdGeCurve2d& operator =(const OdGeCurve2d& curve);

protected:
  /**
    Arguments:
    source (I) Object to be cloned.
  */
  OdGeCurve2d();
  OdGeCurve2d(OdGeCurve3dImpl *);
  OdGeCurve2d(
    const OdGeCurve2d& source);
};

#include "../TD_PackPop.h"

#endif // OD_GE_CURVE_2D_H

