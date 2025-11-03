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

#ifndef OD_GEELL3D_H
#define OD_GEELL3D_H /* {Secret} */

class OdGeEllipArc2d;
class OdGeCircArc3d;
class OdGeLineEnt3d;
class OdGePlanarEnt;
class OdGeExtents3d;
class OdGeEllipArc3dImpl;

#include "../Ge/GeCurve3d.h"
#include "../OdPlatformSettings.h"

#include "../TD_PackPush.h"

/**
    Description:
    This class represents 3D elliptical arcs and full ellipses in 3D space.

    Remarks:
    The angle of a *point* on an ellipse is measured by projecting
    the *point* along a vector perpendicular to the major axis onto a
    circle whose *center* is the *center* of this *ellipse* and whose
    radius is the major radius of this *ellipse*.

    The *angle* between the major axis of the *ellipse*, and a vector from
    the *center* of the *ellipse* to the intersection point with the circle, 
    measured counterclockwise about the crossproduct of the major and minor axes,
    is the *angle* of the *point* on the ellipse.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeEllipArc3d : public OdGeCurve3d
{
public:


  /**
    Arguments:
    center (I) The *center* of the elliptical arc.
    majorAxis (I) The major axis of the elliptical arc.
    minorAxis (I) The minor axis of the elliptical arc.
    majorRadius (I) The major radius of the elliptical arc.
    minorRadius (I) The minor radius of the elliptical arc.
    startAng (I) Starting angle of the elliptical arc.
    endAng (I) Ending angle of the elliptical arc.
    source (I) Object to be cloned.
    Note:
    All angles are expressed in radians.

  */
  OdGeEllipArc3d();
  OdGeEllipArc3d(OdGeEllipArc3dImpl* impl);
  OdGeEllipArc3d(
    const OdGeEllipArc3d& ell);
  OdGeEllipArc3d(
    const OdGeCircArc3d& source);
  OdGeEllipArc3d(
    const OdGePoint3d& center, 
    const OdGeVector3d& majorAxis,
    const OdGeVector3d& minorAxis, 
    double majorRadius,
    double minorRadius);
  OdGeEllipArc3d(
    const OdGePoint3d& center, 
    const OdGeVector3d& majorAxis,
    const OdGeVector3d& minorAxis, 
    double majorRadius,
    double minorRadius, 
    double startAng, 
    double endAng);

  /**
    Description:
    Returns the point on the elliptical arc that is closest to the
    specified plane and the point on the specified plane that is closest
    to the elliptical arc.

    Arguments:
    plane (I) Any plane.
    pointOnPlane (O) Receives the closest point on the plane.
    tol (I) Geometric tolerance.
  */
   OdGePoint3d closestPointToPlane(
    const OdGePlanarEnt& plane,
    OdGePoint3d& pointOnPlane,
    const OdGeTol& tol = OdGeContext::gTol) const ;

  /**
    Description:
    Returns True if the specifed linear entity intersects the arc entity,
	  and returns the number of intersections and points of intersection.

    Arguments:
    line (I) Any 3D linear entity.
    numInt (O) Receives the number of intersections.
    p1 (O) Receives the first intersection point of the elliptical arc.
    p2 (O) Receives the second intersection point of the elliptical arc.
    tol (I) Geometric tolerance.

    Remarks:
    o p1 is valid only if numInt > 0.
    o p2 is valid only if numInt > 1.
  */
  OdBool intersectWith (
    const OdGeLinearEnt3d& line, 
    int& numInt,
    OdGePoint3d& p1, 
    OdGePoint3d& p2,
    const OdGeTol& tol = OdGeContext::gTol) const ;

  /**
    Description:
    Returns True if the specifed plane or linear entity intersects the elliptical 
	arc entity, and returns the number of intersections and points of intersection.

    Arguments:
    plane (I) Any plane entity.
    numInt (O) Receives the number of intersections.
    p1 (O) Receives the first intersection point on the elliptical arc.
    p2 (O) Receives the second intersection point on the elliptical arc. 
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
    const OdGeTol& tol = OdGeContext::gTol) const ;

  /**
    Description:
    Returns True if the projected points of the elliptical arc intersect with the 
	specified linear entity, and returns the number of intersections and points of 
	intersection.

    Arguments:
    line (I) Any 3D linear entity.
    projDir (I) Projection direction.
    numInt (O) Receives the number of intersections.
    pntOnEllipse1 (O) Receives the first intersection point on the elliptical arc. 
    pntOnEllipse2 (O) Receives the second intersection point on the elliptical arc.
    pntOnLine1 (O) Receives the first intersection point on the line.   
    pntOnLine2 (O) Receives the second intersection point on the line.
    tol (I) Geometric tolerance.
  */
  OdBool projIntersectWith (
    const OdGeLinearEnt3d& line,
    const OdGeVector3d& projDir, 
    int& numInt,
    OdGePoint3d& pntOnEllipse1,
    OdGePoint3d& pntOnEllipse2,
    OdGePoint3d& pntOnLine1,
    OdGePoint3d& pntOnLine2,
    const OdGeTol& tol = OdGeContext::gTol) const ;

  /**
    Description:
    Returns the *plane* of the *ellipse*.
  */
   void getPlane(
    OdGePlane& plane) const ;

  /**
    Description:
    Returns true if and only if the major and minor radii of the *ellipse*
    are the same within the specified tolerance.

    Arguments:
    tol (I) Geometric tolerance.
  */
  OdBool isCircular (
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only if the specified *point* lies within
    the full ellipse, and on the *plane* of the *ellipse*.

    Arguments:
    point (I) Any 3D *point*.
    tol (I) Geometric tolerance.
  */
  OdBool isInside (
    const OdGePoint3d& point, 
    const OdGeTol& tol = OdGeContext::gTol) const ;

  /**
    Description:
    Returns the *center* of this elliptical arc.
  */
   OdGePoint3d center() const ; 

  /**
    Description:
    Returns the minor *radius* of this elliptical arc.
  */
   double minorRadius() const ;
  
  /**
    Description:
    Returns the major *radius* of this elliptical arc.
  */
   double majorRadius() const ;

  /**
    Description:
    Returns the minor axis of this elliptical arc as a unit vector.
  */
   OdGeVector3d minorAxis() const ;

  /**
    Description:
    Returns the major axis of this elliptical arc as a unit vector.
  */
   OdGeVector3d majorAxis() const ;

  /**
    Description:
    Returns the *normal* to this elliptical arc as a unit vector. 

    Remarks:
    Positive angles are always drawn counterclockwise about this vector.
  */
   OdGeVector3d normal() const ;

  /**
    Description:
    Returns the start angle measured from the major axis of this elliptical arc in the 
    *plane* of the *arc*.

    Note:
    All angles are expressed in radians.
  */
   double startAng() const ;

  /**
    Description:
    Returns the end angle measured from the major axis of this elliptical arc in the 
    *plane* of the *arc*.

    Note:
    All angles are expressed in radians.
  */
   double endAng() const ;

  /**
    Description:
    Returns the start point of this elliptical arc.
  */
   OdGePoint3d startPoint() const ;

  /**
    Description:
    Returns the end point of this elliptical arc.
  */
   OdGePoint3d endPoint() const ;

  /**
    Description:
    Sets the *center* of the elliptical arc.

    Arguments:
    center (I) The *center* of the elliptical arc.
  */
   OdGeEllipArc3d& setCenter(
    const OdGePoint3d& center) ;

  /**
    Description:
    Sets the minor radius of the elliptical arc.

    Arguments:
    minorRadius (I) The minor radius of the elliptical arc.
  */
   OdGeEllipArc3d& setMinorRadius(
    double rad) ;

  /**
    Description:
    Sets the major radius of the elliptical arc.

    Arguments:
    majorRadius (I) The major radius of the elliptical arc.
  */
   OdGeEllipArc3d& setMajorRadius(
    double rad) ;

  /**
    Description:
    Sets the major and minor axes of the elliptical arc.

    Arguments:
    majorAxis (I) The major axis of the elliptical arc.
    minorAxis (I) The minor axis of the elliptical arc.
  */
   OdGeEllipArc3d& setAxes(
    const OdGeVector3d& majorAxis,
    const OdGeVector3d& minorAxis) ;

  /**
    Description:
    Sets the starting and ending angles of the elliptical arc.

    Arguments:
    startAng (I) Starting angle of the elliptical arc.
    endAng (I) Ending angle of the elliptical arc.
    Note:
    All angles are expressed in radians.
  */
   OdGeEllipArc3d& setAngles(
    double startAng, 
    double endAng) ;

  /**
    Description:
    Sets the parameters for this elliptical arc according to the arguments, 
    and returns a reference to this elliptical arc.

    Arguments:
    arc (I) Any 3D circular *arc*.
    center (I) The *center* of the elliptical arc.
    majorAxis (I) The major axis of the elliptical arc.
    minorAxis (I) The minor axis of the elliptical arc.
    majorRadius (I) The major radius of the elliptical arc.
    minorRadius (I) The minor radius of the elliptical arc.
    startAng (I) Starting angle of the elliptical arc.
    endAng (I) Ending angle of the elliptical arc.
    Note:
    All angles are expressed in radians.

  */
   OdGeEllipArc3d& set(
    const OdGePoint3d& center,
    const OdGeVector3d& majorAxis,
    const OdGeVector3d& minorAxis,
    double majorRadius, 
    double minorRadius) ;
   OdGeEllipArc3d& set(
    const OdGePoint3d& center,
    const OdGeVector3d& majorAxis,
    const OdGeVector3d& minorAxis,
    double majorRadius, 
    double minorRadius,
    double startAng, 
    double endAng) ;
   OdGeEllipArc3d& set(
    const OdGeCircArc3d& arc) ;

  OdGeEllipArc3d& operator =(
    const OdGeEllipArc3d& ell);

  //////////////////////////////////////////////////////////////////////////
  // TD Special :

  // functions making ellipse's axis orthogonal
  // this one requires error flag

  /**
    Description:
    Makes the minor axis orthogonal to the major axis.

    Arguments:
    tol (I) Geometric tolerance.
    flag (O) Receives the *status* of computation.

    Remarks:
    Possible values for flag are as follows:

    @untitled table
    kOk
    kDegenerateGeometry
    
    If flag is not specified, the following exception may be thrown:

    Throws:
    @table
    Exception           
    eDegenerateGeometry 
  */
   void orthogonolizeAxes(
    const OdGeTol& tol, 
    OdGe::ErrorCondition& flag) ;
  void orthogonolizeAxes(
    const OdGeTol& tol = OdGeContext::gTol) ;

  /**
    Description:
    Returns the *tangent* vector at the point specified by param.

    Arguments:
    param (I) Parameter corresponding to the *point* at which to compute the *tangent*.
  */
   OdGeVector3d tangentAt(
    double param) const ;

  /**
    Description:
    Returns the geometric *extents* of this elliptical arc.

    Arguments:
    extents (O) Receives the geometric *extents*.
  */
  void getGeomExtents(
    OdGeExtents3d& extents) const ;

  /** Description:
    Returns the parameters of the points (if any) on the elliptical arc,
    whose *tangents* are parallel to the specified tangent vector.

    Parameters:
    tan (I) A vector defining the tangent direction.
    params (O) Receives the array of tangent point parameters.

    Note:
    The parameters are appended to the specified array. You may wish to 
    initialize the params array with clear().
  */
   OdResult inverseTangent(
    OdGeVector3d tan, 
    OdGeDoubleArray& params) const ;

  /** Description:
    Returns the parameters of the points (if any) on the elliptical arc,
    whose *tangents* are parallel to the specified reference plane.

    Parameters:
    refPlane (I) A reference plane.
    params (O) Receives the array of tangent point parameters.

    Note:
    The parameters are appended to the specified array. You may wish to 
    initialize the params array with clear().
  */
  OdResult inverseTangentPlane(
    const OdGePlane& refPlane, 
    OdGeDoubleArray& params) const ;

};

#include "../TD_PackPop.h"

#endif // OD_GEELL3D_H

