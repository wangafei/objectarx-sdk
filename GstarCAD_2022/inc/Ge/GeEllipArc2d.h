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

#ifndef OD_GE_ELLIP_ARC_2D_H
#define OD_GE_ELLIP_ARC_2D_H /* {Secret} */

class OdGeCircArc2d;
class OdGePlanarEnt;
class OdGeEllipArc2d;
class OdGeLinearEnt2d;
class OdGeExtents2d;
class OdGeEllipArc3dImpl;

#include "../OdPlatform.h"
#include "../Ge/GeCurve2d.h"

#include "../TD_PackPush.h"

/**
    Description:
    This class represents elliptical arcs and full ellipses in 2D space.

    Remarks:
    The angle of a *point* on an ellipse is measured by projecting
    the *point* along a vector perpendicular to the major axis onto a
    circle whose *center* is the *center* of this *ellipse* and whose
    radius is the major radius of this *ellipse*.

    The angle between the major axis of this ellipse, and a vector from
    the *center* of this *ellipse* to the intersection point with the circle, 
    measured counterclockwise, is the angle of this *point* on the ellipse.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeEllipArc2d : public OdGeCurve2d
{
public:
  

  /**
    Arguments:
    center (I) The *center* of this elliptical arc.
    majorAxis (I) The major axis of this elliptical arc.
    minorAxis (I) The minor axis of this elliptical arc.
    majorRadius (I) The major radius of this elliptical arc.
    minorRadius (I) The minor radius of this elliptical arc.
    startAng (I) Starting angle of this elliptical arc.
    endAng (I) Ending angle of this elliptical arc.
    source (I) Object to be cloned.

    Note:
    All angles are expressed in radians.
  */
  OdGeEllipArc2d();
  OdGeEllipArc2d(OdGeEllipArc3dImpl *);
  OdGeEllipArc2d(
    const OdGeEllipArc2d& ell);
  OdGeEllipArc2d(
    const OdGeCircArc2d& arc);
  OdGeEllipArc2d(
    const OdGePoint2d& center, 
    const OdGeVector2d& majorAxis,
    const OdGeVector2d& minorAxis, 
    double majorRadius, 
    double minorRadius);
  OdGeEllipArc2d(
    const OdGePoint2d& center,
    const OdGeVector2d& majorAxis,
    const OdGeVector2d& minorAxis, 
    double majorRadius, 
    double minorRadius, 
    double startAng, 
    double endAng);

  /**
    Description:
    Determines if the input line intersects the ellipse.

    Arguments:
    line (I) Input any 2D linear entity  
    intn (O) Output number of intersection points  
    p1 (0) Output first intersection point  
    p2 (0) Output second intersection point  
    tol (I) Output tolerance for tangent intersections  

    Note:
    This function throws exception "not Implemented" now.
  */
  bool intersectWith(
    const OdGeLinearEnt2d& line, 
    int& numInt,
    OdGePoint2d& p1, 
    OdGePoint2d& p2,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Determines if an ellipse is a circular arc.

    Arguments:
    tol (I) Input tolerance  

    Note:
    This function throws exception "not Implemented" now.
  */
  bool isCircular(
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description: 
    Returns kTrue if and only if the specified *point* lies within
    the full ellipse.

    Arguments:
    point (I) Any 2D *point*.
    tol (I) Geometric tolerance.
  */
  OdBool isInside (
    const OdGePoint2d& point, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the *center* of this elliptical arc.
  */
  OdGePoint2d center() const;

  /**
    Description:
    Returns the minor *radius* of this elliptical arc.
  */
  double minorRadius() const;

  /**
    Description:
    Returns the major *radius* of this elliptical arc.
  */
  double majorRadius() const;

  /**
    Description:
    Returns the minor axis of this elliptical arc as a unit vector.
  */
  OdGeVector2d minorAxis() const;

  /**
    Description:
    Returns the major axis of this elliptical arc as a unit vector.
  */
  OdGeVector2d majorAxis() const;

  /**
    Description:
    Returns the start angle measured from major axis of this elliptical arc.
    Note:
    All angles are expressed in radians.

  */
  double startAng() const;

  /**
    Description:
    Returns the end angle measured from major axis of this elliptical arc.
    Note:
    All angles are expressed in radians.

  */
  double endAng() const;

  /**
    Description:
    Returns the start point of this elliptical arc.
  */
  OdGePoint2d startPoint() const;

  /**
    Description:
    Returns the end point of this elliptical arc.
  */
  OdGePoint2d endPoint() const;

  /**
    Description:
    Returns kTrue if and only if this elliptical arc is drawn clockwise from start point to end point.
  */
  OdBool isClockWise () const;

  /**
    Description:
    Sets the *center* of this elliptical arc.

    Arguments:
    center (I) The *center* of this elliptical arc.
  */
  OdGeEllipArc2d& setCenter(
  const OdGePoint2d& center);

  /**
    Description:
    Sets the minor radius of this elliptical arc.

    Arguments:
    minorRadius (I) The minor radius of this elliptical arc.
  */
  OdGeEllipArc2d& setMinorRadius(
    double rad);

  /**
    Description:
    Sets the major radius of this elliptical arc.

    Arguments:
    majorRadius (I) The major radius of this elliptical arc.
  */
  OdGeEllipArc2d& setMajorRadius(
    double rad);

  /**
    Description:
    Sets the major and minor axes of this elliptical arc.

    Arguments:
    majorAxis (I) The major axis of this elliptical arc.
    minorAxis (I) The minor axis of this elliptical arc.
  */
  OdGeEllipArc2d& setAxes(
    const OdGeVector2d& majorAxis,
    const OdGeVector2d& minorAxis);

  /**
    Description:
    Sets the starting and ending angles of this elliptical arc.

    Arguments:
    startAng (I) Starting angle of this elliptical arc.
    endAng (I) Ending angle of this elliptical arc.
    Note:
    All angles are expressed in radians.

  */
  OdGeEllipArc2d& setAngles(
    double startAng, 
    double endAng);

  /**
    Description:
    Sets the parameters for this elliptical arc according to the arguments, and returns a reference to this elliptical arc.

    Arguments:
    arc (I) Any 2D circular *arc*.
    center (I) The *center* of this elliptical arc.
    majorAxis (I) The major axis of this elliptical arc.
    minorAxis (I) The minor axis of this elliptical arc.
    majorRadius (I) The major radius of this elliptical arc.
    minorRadius (I) The minor radius of this elliptical arc.
    startAng (I) Starting angle of this elliptical arc.
    endAng (I) Ending angle of this elliptical arc.

    Note:
    All angles are expressed in radians.
  */
  OdGeEllipArc2d& set(
    const OdGePoint2d& center,
    const OdGeVector2d& majorAxis,
    const OdGeVector2d& minorAxis,
    double majorRadius, 
    double minorRadius);
  OdGeEllipArc2d& set(
    const OdGePoint2d& center,
    const OdGeVector2d& majorAxis,
    const OdGeVector2d& minorAxis,
    double majorRadius, 
    double minorRadius,
    double startAng, 
    double endAng);
  OdGeEllipArc2d& set(
    const OdGeCircArc2d& arc);

  OdGeEllipArc2d& operator =(
    const OdGeEllipArc2d& ell);

  //////////////////////////////////////////////////////////////////////////
  // Overrides :

  //////////////////////////////////////////////////////////////////////////
  // TD Special :

  /**
  Description:    
  Returns the geometric *extents* of this elliptical arc.
  Not implemented; for third-party use only.

  Arguments:
  extents (O) Receives the geometric *extents*.
  */
  void getGeomExtents(
    OdGeExtents2d& extents) const;

  // returns the parameter of elliptical arc points (if any) which have tangent 
  // co-directional to "tan" vector. Parameters are returned in params array.
  // Note that this function doesn't clear array - only appends items.

  /** Description:
    Returns the parameters of the points (if any) on the elliptical arc,
    whose *tangents* are parallel to the specified tangent vector.
	Not implemented; for third-party use only.

    Parameters:
    tan (I) A vector defining the tangent direction.
    params (O) Receives the array of tangent point parameters.

    Note:
    The parameters are appended to the specified array. You may wish to 
    initialize the params array with clear().
  */
  void inverseTangent(
    OdGeVector2d tan, 
    OdGeDoubleArray& params);
  
};

#include "../TD_PackPop.h"

#endif // OD_GE_ELLIP_ARC_2D_H
