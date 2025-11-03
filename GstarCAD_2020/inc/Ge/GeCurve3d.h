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

#ifndef _OD_GECURVE3D_H_
#define _OD_GECURVE3D_H_ /* {Secret} */

#include "../Ge/GeEntity3d.h"
#include "../Ge/GePointOnCurve3d.h"
#include "../Ge/GeDoubleArray.h"
#include "../Ge/GeVector3dArray.h"
#include "../Ge/GeIntArray.h"
#include "../Ge/GeInterval.h"
#include "../Ge/GeBoundBlock3d.h"
#include "../Ge/GeVoidPointerArray.h"
class OdGeCurve2d;
class OdGeSurface;
class OdGePoint3d;
class OdGePlane;
class OdGeVector3d;
class OdGeLinearEnt3d;
class OdGeLine3d;
class OdGePointOnCurve3d;
class OdGePointOnSurface;
class OdGeMatrix3d;
class OdGePointOnCurve3dData;
class OdGeCurve3dImpl;

#include "../TD_PackPush.h"

/**
    Description: 
    This class is the base class for all OdGe 3D curves.

    Library: TD_Ge

   {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeCurve3d : public OdGeEntity3d
{
public:

  /**
    Description:
      Returns the parametric *interval* of this *curve*.

    Arguments:
      interval (O) Receives the parametric *interval* of this *curve*.
  */ 
   void getInterval(
    OdGeInterval& interval) const;
   void getInterval(
    OdGeInterval& interval, 
    OdGePoint3d& start, 
    OdGePoint3d& end) const;

  /**
    Description:
    Reverses the parameter *direction* this *curve*.   

    Remarks:
    The *point* *set* of this *curve* is unchanged.

    Note:
    By default this function throws exception "not Implemented".

    Throws:
    @table
    Exception    
    eNotImplemented
  */
   OdGeCurve3d& reverseParam();

  /**
    Description:
    Sets the parametric *interval* of this *curve*.

    Arguments:
    interval (I) Parametric *interval* of this *curve*
    
    Note:
    By default this function throws exception "not Implemented".

    Throws:
    @table
    Exception    
    eNotImplemented
  */      
   OdGeCurve3d& setInterval();
   OdBool setInterval(
    const OdGeInterval& interval);

  /**
    Description:
    Returns the distance to the *point* on this *curve* closest to the specified *point* or *curve*.

    Arguments:
    point (I) Any 3D *point*.
    curve (I) Any 3D *curve*.
    tol (I) Geometric tolerance.
  */
   double distanceTo(
    const OdGePoint3d& point, 
    const OdGeTol& tol = OdGeContext::gTol) const;
   double distanceTo(
    const OdGeCurve3d& curve, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the *point* on this *curve* closest to the specified *point* or *curve*, and the *point*
    on the other *curve* closest to this *curve*.

    Arguments:
    point (I) Any 3D *point*.
    curve (I) Any 3D *curve*.
    pntOnOtherCrv (O) Receives the closest *point* on other *curve*.
    tol (I) Geometric tolerance.
  */
   OdGePoint3d closestPointTo(
    const OdGePoint3d& point, 
    const OdGeTol& tol = OdGeContext::gTol) const;
   OdGePoint3d closestPointTo(
    const OdGeCurve3d& curve, 
    OdGePoint3d& pntOnOtherCrv, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
  Description:
    Returns the *point* on this *curve* closest to the specified *point* or *curve*, 
    and the *point* on the other *curve* closest to this *curve*.

    Arguments:
    point (I) Any 3D *point*.
    curve (I) Any 3D *curve*.
    pntOnThisCrv (O) Receives the closest *point* on this *curve*.
    pntOnOtherCrv (O) Receives the closest *point* on other *curve*.
    tol (I) Geometric tolerance.
  */
   void getClosestPointTo(
    const OdGePoint3d& point, 
    OdGePointOnCurve3d& pntOnCrv, 
    const OdGeTol& tol = OdGeContext::gTol) const;
   void getClosestPointTo(
    const OdGeCurve3d& curve, 
    OdGePointOnCurve3d& pntOnThisCrv, 
    OdGePointOnCurve3d& pntOnOtherCrv, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the *point* on this *curve* closest to the specified *point* or *curve*, 
    and the *point* on the other *curve* closest to this *curve*, when this *curve*
    is projected in the specified direction.

    Arguments:
    point (I) Any 3D *point*.
    curve (I) Any 3D *curve*.
    projectDirection (I) Projection Direction.
    pntOnOtherCrv (O) Receives the closest *point* on other *curve*.
    tol (I) Geometric tolerance.
   
    Note:
    As implemented, this function does nothing but
    throw an eNotImplemented error. 
    It will be fully implemented in a future *release*.

    Throws:
    @table
    Exception    
    eNotImplemented
  */
   OdGePoint3d projClosestPointTo(
    const OdGePoint3d& point, 
    const OdGeVector3d& projectDirection, 
    const OdGeTol& tol = OdGeContext::gTol) const;
   OdGePoint3d projClosestPointTo(
    const OdGeCurve3d& curve, 
    const OdGeVector3d& projectDirection, 
    OdGePoint3d& pntOnOtherCrv, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the *point* on this *curve* closest to the specified *point* or *curve*, 
    and the *point* on the other *curve* closest to this *curve*, when this *curve*
    is projected in the specified direction.

    Arguments:
    point (I) Any 3D *point*.
    curve (I) Any 3D *curve*.
    projectDirection (I) Projection Direction.
    pntOnCrv (O) Receives the closest *point* on this *curve*.
    pntOnOtherCrv (O) Receives the closest *point* on other *curve*.
    tol (I) Geometric tolerance.
   
    Note:
    As implemented, this function does nothing but
    throw an eNotImplemented error. 
    It will be fully implemented in a future *release*.

    Throws:
    @table
    Exception    
    eNotImplemented
  */
   void getProjClosestPointTo(
    const OdGePoint3d& point, 
    const OdGeVector3d& projectDirection, 
    OdGePointOnCurve3d& pntOnCrv, 
    const OdGeTol& tol = OdGeContext::gTol) const;
   void getProjClosestPointTo(
    const OdGeCurve3d& curve,
    const OdGeVector3d& projectDirection,
    OdGePointOnCurve3d& pntOnThisCrv,
    OdGePointOnCurve3d& pntOnOtherCrv,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true, and the *point* on this *curve* whose *normal* vector passes through the specified *point*,
    if and only if a normal *point* was found.

    Arguments:
    point (I) Any 3D *point*.
    pntOnCrv (O) Receives the normal *point*.
    tol (I) Geometric tolerance.

    Throws:
    @table
    Exception    
    eNotImplemented
  */
   OdBool getNormalPoint(
    const OdGePoint3d& point, 
    OdGePointOnCurve3d& pntOnCrv, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
   Description
   Returns the tangent *point* on this *curve*, whose *tangent* vector passes through the specified *point*,
   if and only if a tangent *point* was found.
   
   Arguments:
   point (I) Any 3D *point*.
   pntOnCrv (O) Receives the tangent *point*.
   tol (I) Geometric tolerance.
   */
   OdBool getTangentPoint(
    const OdGePoint3d &point,
    OdGePointOnCurve3d &pntOnCrv,
    const OdGeTol &tol = OdGeContext::gTol) const;

  /**     
    Description
    Returns the oriented bounding box of *curve*.

    Arguments:
    range (I) Sub-interval of this *curve* to be bounded.

    Throws:
    @table
    Exception    
    eNotImplemented
  */
   OdGeBoundBlock3d boundBlock() const;
   OdGeBoundBlock3d boundBlock(
    const OdGeInterval& range) const;

  /**
    Description:
    Returns the bounding box whose edges are aligned with the coordinate axes.

    Arguments:
    range (I) Interval of this *curve* to be bounded.
  */
   OdGeBoundBlock3d orthoBoundBlock() const;
   OdGeBoundBlock3d orthoBoundBlock(
    const OdGeInterval& range) const;

   OdGeEntity3d* project(
    const OdGePlane& projectionPlane,
    const OdGeVector3d& projectDirection,
    const OdGeTol& tol = OdGeContext::gTol) const;
  
   OdGeEntity3d* orthoProject(
    const OdGePlane& projectionPlane,
    const OdGeTol& tol = OdGeContext::gTol) const;

  // Tests if point is on *curve*.
  TD_USING(OdGeEntity3d::isOn);
   OdBool isOn(
    const OdGePoint3d& point, 
    double& param,
    const OdGeTol& tol = OdGeContext::gTol) const;
   OdBool isOn(
    double param, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the parameter *value* of a *point*.

    Arguments:
    point (I) Point to be evaluated.
    tol (I) Geometric tolerance.

    Remarks:
    The returned parameters specify a *point* within tol of point.
    If point is not on this *curve*, the results are unpredictable.
    If you are not sure the *point* is on this *curve*, use 
    isOn () instead of this function.
    
    Throws:
    @table
    Exception    
    eNotImplemented
  */
   double paramOf(
    const OdGePoint3d& point, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
  Description:
    Returns one or more trimmed offset curves.

    Arguments:
    distance (I) Offset *distance*.
    planeNormal (I) A normal to the plane of this *curve*.
    offsetCurveList (O) Receives an array of trimmed offset curves.
    extensionType (I) How curves will be extended at discontinuities of *type* C1.
    tol (I) Geometric tolerance.

    Remarks:
    The offsets are trimmed to eliminate self-intersecting loops.

    The *curve* is assumed to be planar, and planeNomal is assumed to be 
    normal to the *curve* plane.

    the *direction* of positive offset at any *point* on this *curve*
    is the cross product of planeNormal and the tangent to the
    *curve* at that *point*.

    The new operator is used to create the curves returned by 
    offsetCurveList. It is up to the caller to delete these curves. 

    Throws:
    @table
    Exception    
    eNotImplemented
  */
   void getTrimmedOffset(
    double distance, 
    const OdGeVector3d& planeNormal, 
    OdGeVoidPointerArray& offsetCurveList, 
    OdGe::OffsetCrvExtType extensionType = OdGe::kFillet, 
    const OdGeTol& tol = OdGeContext::gTol) const;
	
  /**
    Description:
    Returns true if and only if this *curve* is closed within the specified tolerance.

    Arguments:
    tol (I) Geometric tolerance.
  */
   OdBool isClosed(
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only if this *curve* is planar, and returns
    the *plane* of this *curve*.

    Arguments:
    plane (O) Receives the *plane* of this *curve*.
    tol (I) Geometric tolerance.

    Remarks:
    Lines are considered planar the returned *plane* is an
    arbitrary *plane* containing the *line*.
  */
   OdBool isPlanar(
    OdGePlane& plane, 
    const OdGeTol& tol = OdGeContext::gTol) const;

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
    As implemented, this function does nothing but
    return false.
    It will be fully implemented in a future *release*.
    
  */
   OdBool isLinear(
    OdGeLine3d& line,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns True if the specified curve entity is coplanar with 
    this curve and returns the common plane.

    Arguments:
    curve (I) Any 3D curve.
    plane (O) Receives the plane of the curves.
    tol (I) Geometric tolerance.
  */
   OdBool isCoplanarWith(
    const OdGeCurve3d& curve, 
    OdGePlane& plane, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only if this *curve* is *periodic* for the specified *period*.

    Arguments:
    period (O) Receives the period of this *curve*. 
  */
   OdBool isPeriodic(
    double& period) const;

  /**
    Description:
    Returns the *length* of this *curve* over the specified parameter range.

    Arguments:
    fromParam (I) Starting parameter *value*.
    toParam (I) Ending parameter *value*.
    tol (I) Geometric tolerance.
    
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
    Returns the parameter of the *point* a specified distance 
    from the starting point corresponding to datumParam.

    Arguments:
    datumParam (I) Parameter corresponding to the start point.
    length (I) Distance along *curve* from the start point.
    posParamDir (I) True if and only if returned parameter is to be greater than dataParam.
    tol (I) Geometric tolerance.
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
    Determines the *area* of this *curve* between the specified parameters. 
    Returns true (and a value) if and only if this *curve* is planar. 

    Arguments:
    startParam (I) Starting parameter *value*.
    endParam (I) Ending parameter *value*.
    value (O) Receives the *area*.
    tol (I) Geometric tolerance.
  */      
   OdBool area(
    double startParam, 
    double endParam, 
    double& value, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
  Description:
    Returns true if and only if this *curve* degenerates, and returns
    the entity or *type* of entity to which this *curve* degenerates.

    Arguments:
    degenerateType (O) Receives the *type* of *curve* to which this *curve* degenerates.
    pConvertedEntity (O) Receives a pointer to the object to which this *curve* degenerates.
    tol (I) Geometric tolerance.

    Remarks:
    If isDegenerate returns true, the returned object was created with the new operator, and it is the responsibility of the caller to delete it.
  */      
   OdBool isDegenerate(
    OdGe::EntityId& degenerateType, 
    const OdGeTol& tol = OdGeContext::gTol) const;
   OdBool isDegenerate(
    OdGeEntity3d*& pConvertedEntity, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns pointers to the two curves that result from splitting this *curve* at the *point* corresponding 
    to param.

    Arguments:
    param (I) The parameter *value* corresponding to the split *point*.
    piece1 (O) Receives a pointer to the first *curve*.
    piece2 (O) Receives a pointer to the second *curve*.

    Remarks:
    If param corresponds to a *point* not on this *curve*,
    or to the start point or end point of this *curve*,
    piece1 and piece2 are set to NULL.

    The curves pointed to by piece1 and piece2 
    are created with the new command, and must be deleted by the caller. 
  */      
   void getSplitCurves(
    double param, 
    OdGeCurve3d*& piece1,
    OdGeCurve3d*& piece2) const;

  /**
    Description:
    Explodes this *curve* over the specified interval.

    Arguments:
    explodedCurves (O) Receives an array of pointers to the subcurves from the explosion.
    newExplodedCurves (O) Receives an array of flags which, if true, correspond to those explodedCurves the caller must delete.
    pInterval (I) Pointer to the interval to be exploded. Defaults to entire *curve*.

    Remarks:
    The original *curve* is not changed.
  */      
   OdBool explode(
    OdGeVoidPointerArray& explodedCurves, 
    OdGeIntArray& newExplodedCurves, 
    const OdGeInterval* pInterval = NULL) const;

  /**
    Description:
    Returns the *point* on this *curve* locally closest to the specified *point*
    or *curve*, and the *point* on the other *curve* locally closest to this *curve*.

    Arguments:
    point (I) Any 3D *point*.
    curve (I) Any 3D *curve*.
    approxPntOnThisCrv (I/O) Approximate *point* on this *curve*.
    approxPntOnOtherCrv (I/O) Approximate *point* on other *curve*.
    pInterval1 (I) Pointer to the interval in which the *point* on this *curve* must lie.
    pInterval2 (I) Pointer to the interval in which the *point* on the other *curve* must lie.
    tol (I) Geometric tolerance.
  */      
   void getLocalClosestPoints(
    const OdGePoint3d& point,
    OdGePointOnCurve3d& approxPntOnThisCrv,
    const OdGeInterval* pInterval1 = NULL,
    const OdGeTol& tol = OdGeContext::gTol) const;

   void getLocalClosestPoints(
    const OdGeCurve3d& curve,
    OdGePointOnCurve3d& approxPntOnThisCrv,
    OdGePointOnCurve3d& approxPntOnOtherCrv,
    const OdGeInterval* pInterval1 = NULL,
    const OdGeInterval* pInterval2 = NULL,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true, and the start point, if and only if the parametric *interval* of this *curve* has a lower bound.

    Arguments:
    startPoint (O) Receives the start point.
  */
   OdBool hasStartPoint(
    OdGePoint3d& startPoint) const;

  /**
    Description:
    Returns true, and the end point,  if and only if the parametric *interval* of this *curve* has an upper bound.

    Arguments:
    endPoint (O) Receives the end point.
  */
   OdBool hasEndPoint(
    OdGePoint3d& endPoint) const;

  /**
  Description:
    Returns the *point* on this *curve* corresponding to the specified parameter *value*,
    and the *derivatives* at that *point*.

    Arguments:
    param (I) Parameter to be evaluated.
    numDeriv (I) Number of *derivatives* to be computed.
    derivatives (O) Receives an array of *derivatives* at the *point* corresponding to param.

  */
   OdGePoint3d evalPoint(
    double param) const;
   OdGePoint3d evalPoint(
    double param, 
    int numDeriv, 
    OdGeVector3dArray& derivatives) const;

  /**
    Description:
    Returns sample points along this *curve* and their parameter values in the specified arrays.

    Arguments:
    fromParam (I) Starting parameter *value*.
    toParam (I) Ending parameter *value*.
    paramInterval (I) Pointer to the parametric interval.
    approxEps (I) Approximate spacing along a *curve*.
    numSample (I) Number of samples.
    pointArray (O) Receives an array of sample points.
    paramArray (O) Receives an array of parameters at each *point*.
    forceResampling (I) sample points are forced to be regenerated
  */
   void getSamplePoints(
    double fromParam, 
    double toParam, 
    double approxEps, 
    OdGePoint3dArray& pointArray, 
    OdGeDoubleArray& paramArray,
    bool forceResampling = false) const;
   void getSamplePoints(
    int numSample, 
    OdGePoint3dArray& pointArray) const;
   void getSamplePoints(
    int numSample, 
    OdGePoint3dArray& pointArray,
    OdGeDoubleArray& paramArray) const;
   void getSamplePoints(double fromParam, 
     double toParam, 
     double approxEps, 
     OdGePoint3dArray& pointArray, 
     OdGeDoubleArray* paramArray = NULL) const;
  
   void getPolylinePoints(int precision, OdGePoint3dArray &pointArray) const;

  // Assignment operator.
  OdGeCurve3d& operator =(const OdGeCurve3d& curve);

  // TD: Special
  void getSamplePoints(
    const OdGeInterval *paramInterval,
    double approxEps,
    OdGePoint3dArray& pointArray,
    OdGeDoubleArray *paramArray = NULL,
    bool forceResampling = false) const;

  void appendSamplePoints(int numSample, OdGePoint3dArray& pointArray,
    OdGeDoubleArray& paramArray) const;
  void appendSamplePoints(int numSample, OdGePoint3dArray& pointArray) const;

  void appendSamplePoints(double fromParam, double toParam, double approxEps, OdGePoint3dArray& pointArray, 
    OdGeDoubleArray* paramArray = NULL) const;


protected:
  OdGeCurve3d();
  OdGeCurve3d(
    const OdGeCurve3d& source);
  OdGeCurve3d(OdGeCurve3dImpl* impl);
};

#include "../TD_PackPop.h"

#endif

