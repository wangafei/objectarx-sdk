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

#ifndef OD_GECIRCARC3D_H
#define OD_GECIRCARC3D_H /* {Secret} */

#include "../Ge/GeCurve3d.h"
#include "../Ge/GePlane.h"

#include "../TD_PackPush.h"

class OdGeLine3d;
class OdGeCircArc2d;
class OdGePlanarEnt;
class OdGeExtents3d;
class OdGeCircArc3dImpl;

/**
    Description: 
    A mathematical entity used to represent a circular arc in 3D space.

    Library: TD_Ge

   {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeCircArc3d : public OdGeCurve3d
{
public:


  /**
    Arguments:
    center (I) Center of *arc*.
    normal (I) A vector *normal* to the *plane* of the *arc*
    radius (I) Radius of *arc*.
    startAng (I) Starting angle of *arc*.
    endAng (I) Ending angle of *arc*.
    refVec (I) The reference *vector* defining *arc* angle 0.
    isClockWise (I) If true, the *arc* is drawn clockwise, otherwise, counterclockwise.
    startPoint (I) Startpoint of *arc*.
    secondPoint (I) Second *point* on a 3-point *arc*.
    endPoint (I) Endpoint of *arc*.
    source (I) Object to be cloned.

    Remarks:
    To construct a circle, *set* endAng = startAng + Oda2PI
    
    Note:
    All angles are expressed in radians.
    
    startAng must be less than endAng. 
   */
  OdGeCircArc3d();
  OdGeCircArc3d(OdGeCircArc3dImpl* impl);

  OdGeCircArc3d(
    const OdGeCircArc3d& source);
  OdGeCircArc3d(
    const OdGePoint3d& center, 
    const OdGeVector3d& normal, 
    double radius);
  OdGeCircArc3d(
    const OdGePoint3d& center, 
    const OdGeVector3d& normal,
    const OdGeVector3d& refVec, 
    double radius, double startAng = 0, 
    double endAng = Oda2PI);
  OdGeCircArc3d(
    const OdGePoint3d& startPoint, 
    const OdGePoint3d& secondPoint, 
    const OdGePoint3d& endPoint);

  /**
    Description:
    Returns the *point* on this *circle* closest
    to the specified *plane*, and the point
    on the *plane* closest to this *circle*.

    Arguments:
    plane (I) Any *plane*.
    pointOnPlane (O) Receives the closest *point* on *plane*.
    tol (I) Geometric tolerance.
  */  
  /**
    Note:
    As currently implemented, this function does nothing but
    assert in debug mode, and return the point (0,0,0).
    It will be fully implemented in a future *release*.
  */
   OdGePoint3d closestPointToPlane(
    const OdGePlanarEnt& plane,
    OdGePoint3d& pointOnPlane, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the intersections with other objects.

    Arguments:
    arc (I) Any 3D arc.
    line (I) Any 3D linear entity.
    plane (I) Any plane.
    numInt (O) Receives the number of intersections.
    p1 (O) Receives the first intersection point.
    p2 (O) Receives the second intersection point.
    tol (I) Geometric tolerance.
    
  */
  OdBool intersectWith (
    const OdGeLinearEnt3d& line, 
    int& numInt, 
    OdGePoint3d& p1, 
    OdGePoint3d& p2,        
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns True if the specified arc intersects the arc entity.

    Arguments:
    arc (I) Any 3D arc entity.
    intn (O) Receives the number of intersections.
    p1 (O) Receives the first intersection *point* on the arc.
    p2 (O) Receives the second intersection *point* on the arc. 
    tol (I) Geometric tolerance.   
	
    Remarks:
    o p1 has meaning only if intn > 0. 
    o p2 has meaning only if intn > 1.   
  */
  OdBool intersectWith (
    const OdGeCircArc3d& arc, 
    int& numInt,    
    OdGePoint3d& p1, 
    OdGePoint3d& p2, 
    const OdGeTol& tol = OdGeContext::gTol) const;
 
  /**
    Description:
    Returns True if the specifed plane, line, or arc entity intersects this
	arc entity, and returns the number of intersections and points of intersection.

    Arguments:
    plane (I) Any plane entity.
    numInt (O) Receives the number of intersections.
    p1 (O) Receives the first intersection point on the arc.
    p2 (O) Receives the second intersection point on the arc. 
    tol (I) Geometric tolerance.   
	
    Remarks:
    o p1 has meaning only if numInt > 0. 
    o p2 has meaning only if numInt > 1.   
  */
  OdBool intersectWith (
    const OdGePlanarEnt& plane, 
    int& numInt,    
    OdGePoint3d& p1, 
    OdGePoint3d& p2,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns True if the projected points of the arc intersect with the 
	specified linear entity, and returns the number of intersections 
	and points of intersection.

    Arguments:
    line (I) Any 3D linear entity.
    projDir (I) Projection direction.
    numInt (O) Receives the number of intersections.
    pntOnArc1 (O) Receives the first intersection point on the arc. 
    pntOnArc2 (O) Receives the second intersection point on the arc.
    pntOnLine1 (O) Receives the first intersection point on the line.       
    pntOnLine2 (O) Receives the second intersection point on the line.
    tol (I) Geometric tolerance.   
  */
  OdBool projIntersectWith (
    const OdGeLinearEnt3d& line, 
    const OdGeVector3d& projDir, 
    int& numInt,
    OdGePoint3d& pntOnArc1, 
    OdGePoint3d& pntOnArc2,
    OdGePoint3d& pntOnLine1,        
    OdGePoint3d& pntOnLine2,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /* Description:
    Returns kTrue if and only if the specified *point* is
    on the full circle of this *arc*, the *tangent*
    at that *point*, and the *status* of the query.

    Arguments:
    point (I) The *point* on the full circle.
    line (O) Receives the *tangent* *line* at that *point*.
    tol (I) Geometric tolerance.
    status (O) Receives the *status* of the query.

    Remarks:
    Possible values for status are as follows:

    @untitled table
    kArg1TooBig
    kArg1InsideThis
    kArg1OnThis
    
    Note:
    As implemented, this function does nothing but
    assert in debug mode, and return kFalse.
    It will be fully implemented in a future *release*.
  */
  OdBool tangent (
    const OdGePoint3d& point, 
    OdGeLine3d& line, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  OdBool tangent (
    const OdGePoint3d& point, 
    OdGeLine3d& line, 
    const OdGeTol& tol, 
    OdGeError& status) const;

  /**
    Description:
    Returns the *plane* of the *arc*.

    Arguments:
    plane (O) Receives the *plane* of the *arc*.
  */
   void getPlane(
    OdGePlane& plane) const;

  /**
    Description:
    Returns kTrue if and only if the specified *point* lies inside the full *circle* of this *arc*, and is
    on the same plane as this *arc*.

    Arguments:
    point (I) Any 3D *point*.
    tol (I) Geometric tolerance.
  */
  OdBool isInside (
    const OdGePoint3d& point, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the *center* of this *arc*.
  */
   OdGePoint3d center() const;

  /**
    Description:
    Returns the *vector* *normal* to the plane of this *arc*.
  */
   OdGeVector3d normal() const; 

  /**
    Description:
    Returns the reference *vector* as a unit vector.
  */
   OdGeVector3d refVec() const;

  /**
    Description:
    Returns the *radius* of this *arc*.
  */
   double radius() const;

  /**
    Description:
    Returns the starting angle measured from the reference *vector* in the *arc* direction.
    Note:
    All angles are expressed in radians.
  */
   double startAng() const;

  /**
    Description:
    Returns the ending angle measured from the reference *vector* in the *arc* direction.
    Note:
    All angles are expressed in radians.
  */
   double endAng() const;

  /**
    Description:
    Returns the start point of this *arc*.
  */
   OdGePoint3d startPoint() const;

  /**
    Description:
    Returns the end point of this *arc*.
  */
   OdGePoint3d endPoint() const;

  /**
    Description:
    Sets the *center* of this *arc*, and returns a reference to this *arc*. 
    
    Arguments:
    center (I) Center of *arc*.
  */
   OdGeCircArc3d& setCenter(
    const OdGePoint3d& center); 

  /** 
    Description:
    Sets the *normal* and reference vectors for this *arc*. Returns a reference
    to this arc.

    Arguments:
    normal (I) A vector *normal* to the *plane* of the *arc*.
    refVec (I) The reference *vector* defining *arc* angle 0.
  */
   OdGeCircArc3d& setAxes(
    const OdGeVector3d& normal, 
    const OdGeVector3d& refVec);

  /**
    Description:
    Sets the *radius* of this *arc*, and returns a reference to this *arc*.

    Arguments:
    radius (I) Radius of *arc*.
  */
   OdGeCircArc3d& setRadius(
    double radius);

  /**
    Description:
    Sets the starting and ending angles of this *arc*, and returns a reference to this *arc*.

    Arguments:
    startAng (I) Starting angle of *arc*.
    endAng (I) Ending angle of *arc*.
    Note:
    All angles are expressed in radians.
  */
   OdGeCircArc3d& setAngles(
    double startAng, 
    double endAng);

  /**
    Description:
    Sets the parameters for this *arc* according to the arguments, and returns a reference to this *arc*.

    Arguments:
    center (I) Center of *arc*.
    normal (I) A vector *normal* to the *plane* of the *arc*
    radius (I) Radius of *arc*.
    startAng (I) Starting angle of *arc*.
    endAng (I) Ending angle of *arc*.
    refVec (I) The reference *vector* defining *arc* angle 0.
    startPoint (I) Startpoint of *arc*.
    secondPoint (I) Second *point* on a 3-point *arc*.
    endPoint (I) Endpoint of *arc*.
    curve1 (I) First curve to define a *tangent* *arc*.
    curve2 (I) Second curve to define a *tangent* *arc*.
    curve3 (I) Third curve to define a *tangent* *arc*.
    status (O) Receives status of set().
    param1 (I) Parameter corresponding tangency *point* on curve1.
    param2 (I) Parameter corresponding tangency *point* on curve2.
    param3 (I) Parameter corresponding tangency *point* on curve3.
    success (O) Receives kTrue if and only if the tan-tan-radius or
    tan-tan-tan curve could be constructed. If kFalse,
    this *arc* is unmodified.

    Remarks:
    To construct a circle, set endAng = startAng + Oda2PI

    If bulgeFlag == kTrue, then *bulge* is the maximum distance from the *arc* to a
    chord between the start and endpoints.

    If bulgeFlag == kFalse, the *bulge* is the *tangent* of 1/4 the included angle of the *arc*.
   
    Note:
    All angles are expressed in radians.

    startAng must be less than endAng. 
  */
   OdGeCircArc3d& set(
    const OdGePoint3d& center,   
    const OdGeVector3d& normal, 
    double radius);

   OdGeCircArc3d& set(
    const OdGePoint3d& center, 
    const OdGeVector3d& normal,
    const OdGeVector3d& refVec, 
    double radius,  
    double startAng, 
    double endAng);

   OdGeCircArc3d& set(
    const OdGePoint3d& startPoint, 
    const OdGePoint3d& secondPoint,
    const OdGePoint3d& endPoint);

   OdGeCircArc3d& set(
    const OdGePoint3d& startPoint, 
    const OdGePoint3d& secondPoint,
    const OdGePoint3d& endPoint, 
    OdGeError& status);

   OdGeCircArc3d& set(
    const OdGeCurve3d& curve1,
    const OdGeCurve3d& curve2,
    double radius, 
    double& param1, 
    double& param2, 
    OdBool& success);

   OdGeCircArc3d& set(
    const OdGeCurve3d& curve1,   
    const OdGeCurve3d& curve2,
    const OdGeCurve3d& curve3, 
    double& param1, 
    double& param2, 
    double& param3, 
    OdBool& success);

  OdGeCircArc3d& operator =(
    const OdGeCircArc3d& arc);

  //////////////////////////////////////////////////////////////////////////

  /**
  Description:
  Returns the geometric *extents* of this *arc*.

  Arguments:
  extents (O) Receives the geometric *extents*.
  */
   void getGeomExtents(
    OdGeExtents3d& extents) const;
};

#include "../TD_PackPop.h"

#endif

