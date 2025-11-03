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

#ifndef OD_GE_ARC2D_H
#define OD_GE_ARC2D_H /* {Secret} */

class OdGeLine2d;
class OdGeLinearEnt2d;
class OdGeExtents2d;
class OdGeCircArc3dImpl;

#include "../Ge/GeCurve2d.h"
#include "../Ge/GePoint2d.h"
#include "../Ge/GeVector2d.h"

#include "../TD_PackPush.h"

/**
    Description:
    This class represents arcs and full circles in 2D space.

    Library: TD_Ge

   {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeCircArc2d : public OdGeCurve2d
{
public:
  

  /**
    Arguments:
    center (I) Center of arc.
    radius (I) Radius of arc.
    startAng (I) Starting angle of arc.
    endAng (I) Ending angle of arc.
    refVec (I) The reference vector defining arc angle 0.
    startPoint (I) Startpoint of arc.
    secondPoint (I) Second *point* on a 3-point arc.
    endPoint (I) Endpoint of arc.
    bulge (I) Specifies the *bulge* of the arc.
    bulgeFlag (I) Specifies how *bulge* is to be interpreted.
    source (I) Object to be cloned.

    Remarks:
    The default constructor creates a circle with a *center* of (0,0) and a *radius* of 1.
    
    To construct a circle, *set* endAng = startAng + Oda2PI

    If bulgeFlag == true, then *bulge* is the maximum distance from the arc perpendicular to a
    chord between the start and endpoints.

    If bulgeFlag == false, the *bulge* is the *tangent* of 1/4 the included 
    angle of the arc, measured counterclockwise.

    Note:
    All angles are expressed in radians.
        
    startAng must be less than endAng. 

  */
  OdGeCircArc2d();
  OdGeCircArc2d(OdGeCircArc3dImpl * );
  OdGeCircArc2d(
    const OdGeCircArc2d& source);
  OdGeCircArc2d(
    const OdGePoint2d& center, 
    double radius);
  OdGeCircArc2d(
    const OdGePoint2d& center, 
    double radius, 
    double startAng,
    double endAng, 
    const OdGeVector2d& refVec = OdGeVector2d::kXAxis,
    bool isClockWise = false);
  OdGeCircArc2d(
    const OdGePoint2d& startPoint,
    const OdGePoint2d& secondPoint,
    const OdGePoint2d& endPoint);
  OdGeCircArc2d(
    const OdGePoint2d& startPoint, 
    const OdGePoint2d& endPoint, 
    double bulge, 
    bool bulgeFlag = true);

  /**
    Description:
    Returns True if the specified arc or linear entity intersects the arc entity,
	and returns the number of intersections and points of intersection.

    Arguments:
    line (I) Any 2D linear entity.
    circarc (I) Any 2D arc entity.
    numInt (O) Receives the number of intersections with this curve.
    p1 (O) Receives the first intersection point.
    p2 (O) Receives the second intersection point.
    tol (I) Geometric tolerance.

    Remarks:
    o p1 has meaning only if numInt > 0. 
    o p2 has meaning only if numInt > 1.   
  */
  OdBool intersectWith (
    const OdGeLinearEnt2d& line, 
    int& numInt,
    OdGePoint2d& p1, 
    OdGePoint2d& p2, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  OdBool intersectWith (
    const OdGeCircArc2d& circarc, 
    int& numInt,
    OdGePoint2d& p1, 
    OdGePoint2d& p2, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /* Description:
    Returns true if and only if the specified *point* is
    on the full circle of this arc, the *tangent*
    at that *point*, and the *status* of the query.

    Arguments:
    point (I) The *point* on the full circle.
    line (O) Receives the *tangent* at that *point*.
    tol (I) Geometric tolerance.
    status (O) Receives the *status* of the query.

    Remarks:
    Possible values for status are as follows:

    @untitled table
    kArg1TooBig
    kArg1InsideThis
    kArg1OnThis
  */
  OdBool tangent (
    const OdGePoint2d& point, 
    OdGeLine2d& line,
    const OdGeTol& tol = OdGeContext::gTol) const;

  OdBool tangent (
    const OdGePoint2d& point, 
    OdGeLine2d& line,
    const OdGeTol& tol, 
    OdGeError& status) const;

  /**
    Description:  
    Returns true if and only if the input *point* lies within
    the full circle of this arc.

    Arguments:
    point (I) Any 2D *point*.
    tol (I) Geometric tolerance.
  */
  OdBool isInside (
    const OdGePoint2d& point, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the *center* of this arc.
  */
  OdGePoint2d center() const;

  /**
    Description:
    Returns the *radius* of this arc.
  */
  double radius() const;

  /**
    Description:
    Returns the starting angle measured from the reference vector in the arc direction.
    Note:
    All angles are expressed in radians.

  */
  double startAng() const;

  /**
    Description:
    Returns the ending angle measured from the reference vector in the arc direction.
    Note:
    All angles are expressed in radians.

  */
  double endAng() const;

  /**
    Description:
    Returns true if and only if this arc is drawn clockwise from start point to end point.
  */
  OdBool isClockWise() const;

  /**
    Description:
    Returns the reference vector as a unit vector.
  */
  OdGeVector2d refVec() const;

  /**
    Description:
    Returns the start point of this arc.
  */
  OdGePoint2d startPoint() const;

  /**
    Description:
    Returns the end point of this arc.
  */
  OdGePoint2d endPoint() const;

  /**
    Description:
    Sets the *center* of this arc, and returns a reference to this arc.

    Arguments:
    center (I) Center of arc.
  */
  OdGeCircArc2d& setCenter(
    const OdGePoint2d& center);

  /**
    Description:
    Sets the *radius* of this arc, and returns a reference to this arc.

    Arguments:
    radius (I) Radius of arc.
  */
  OdGeCircArc2d& setRadius(
    double radius);

  /**
    Description:
    Sets the starting and ending angles of this arc, and returns a reference to this arc.

    Arguments:
    startAng (I) Starting angle of arc.
    endAng (I) Ending angle of arc.
    Note:
    All angles are expressed in radians.

  */
  OdGeCircArc2d& setAngles(
    double startAng, 
    double endAng);

  /**
    Description:
    Reverses the *direction* of this arc while maintaining its endpoints, and returns a reference to this arc.
  */
  OdGeCircArc2d& setToComplement();

  /**
    Description:
    Sets the reference vector of this arc, and returns a reference to this arc.

    Arguments:
    refVec (I) The reference vector defining arc angle 0.
  */
  OdGeCircArc2d& setRefVec(
    const OdGeVector2d& vect);

  /**
    Description:
    Sets the parameters for this arc according to the arguments, and returns a reference to this arc.

    Arguments:
    center (I) Center of arc.
    radius (I) Radius of arc.
    startAng (I) Starting angle of arc.
    endAng (I) Ending angle of arc.
    status (O) Receives the *status* for this method.
    refVec (I) The reference vector defining arc angle 0.
    isClockWise (I) If true, the arc is drawn clockwise, otherwise, counterclockwise.
    startPoint (I) Startpoint of arc.
    secondPoint (I) Second *point* on a 3-point arc.
    endPoint (I) Endpoint of arc.
    bulge (I) Specifies the *bulge* of the arc.
    bulgeFlag (I) Specifies how *bulge* is to be interpreted.
    curve1 (I) First curve to define a *tangent* arc.
    curve2 (I) Second curve to define a *tangent* arc.
    curve3 (I) Third curve to define a *tangent* arc.
    param1 (O) Receives the parameter corresponding tangency *point* on curve1.
    param2 (O) Receives the parameter corresponding tangency *point* on curve2.
    param3 (O) Receives the parameter corresponding tangency *point* on curve2.
    success (O) Receives true if and only if the tan-tan-radius or
    tan-tan-tan curve could be constructed. If false,
    this arc is unmodified.

    Remarks:
    To construct a circle, set endAng = startAng + Oda2PI

    If bulgeFlag == true, then *bulge* is the maximum distance from the arc to a
    chord between the start and endpoints.

    If bulgeFlag == false, the *bulge* is the *tangent* of 1/4 the included angle of the arc.

    Possible values for status are as follows

    @untitled table
    kEqualArg1Arg2
    kEqualArg1Arg3
    kEqualArg2Arg3
    kLinearlyDependentArg1Arg2Arg3.
    
    Note:
    startAng must be less than endAng. 
    All angles are expressed in radians.
  */
  OdGeCircArc2d& set(
    const OdGePoint2d& center, 
    double radius);
  OdGeCircArc2d& set(
    const OdGePoint2d& center, 
    double radius, 
    double startAng, 
    double endAng,
    const OdGeVector2d& refVec = OdGeVector2d::kXAxis, 
    OdBool isClockWise = kFalse);
  OdGeCircArc2d& set(
    const OdGePoint2d& startPoint, 
    const OdGePoint2d& secondPoint,
    const OdGePoint2d& endPoint);
  OdGeCircArc2d& set(
    const OdGePoint2d& startPoint,
    const OdGePoint2d& secondPoint,
    const OdGePoint2d& endPoint, 
    OdGeError& status);
  OdGeCircArc2d& set(
    const OdGePoint2d& startPoint, 
    const OdGePoint2d& endPoint, 
    double bulge, 
    OdBool bulgeFlag = kTrue);
  OdGeCircArc2d& set(
    const OdGeCurve2d& curve1, 
    const OdGeCurve2d& curve2,
    double radius, 
    double& param1, 
    double& param2, 
    OdBool& success);
  OdGeCircArc2d& set(
    const OdGeCurve2d& curve1,
    const OdGeCurve2d& curve2, 
    const OdGeCurve2d& curve3,
    double& param1, 
    double& param2, 
    double& param3, 
    OdBool& success);

  OdGeCircArc2d& operator =(const OdGeCircArc2d& arc);

  /**
    Description:
    Returns the geometric *extents* of this arc.
	Not implemented; for third-party use only.

    Arguments:
    extents (O) Receives the geometric *extents*.
  */
  void getGeomExtents(
    OdGeExtents2d& extents) const;

  /**
    Description:
    Returns the starting angle measured from the X-axis in the arc direction.
	Not implemented; for third-party use only.
    
    Note:
    All angles are expressed in radians.
  */
  double startAngFromXAxis() const;

  /**
    Description:
    Returns the ending angle measured from the X-axis in the arc direction.
	Not implemented; for third-party use only.

    Note:
    All angles are expressed in radians.
  */
  double endAngFromXAxis() const;
  
};

#include "../TD_PackPop.h"

#endif // OD_GE_ARC2D_H

