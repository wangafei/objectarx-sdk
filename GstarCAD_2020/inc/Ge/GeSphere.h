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

#ifndef OD_GESPHERE_H
#define OD_GESPHERE_H /* {Secret} */

#include "../Ge/GeGbl.h"
#include "../Ge/GePoint3d.h"
#include "../Ge/GeVector3d.h"
#include "../Ge/GeInterval.h"
#include "../Ge/GeSurface.h"

class OdGeCircArc3d;

#include "../TD_PackPush.h"

/**
    Description:  
    This class represents spheres.  

    Remarks:
    A sphere is defined by its

    o radius
    o center
    o northAxis
    o refAxis

    northAxis defines the *direction* from the center to the north pole. 

    refAxis, a vector orthogonal to northAxis, the prime meridian.

    Latitude is defined by the U parameter, which defaults to 
    [-OdaPI/2, OdaPI/2] for closed spheres.  The lower bound maps to the south
    pole, zero maps to the equator, and the upper bound maps to the north pole.

    Longitude is defined by the V parameter, which defaults to 
    [-OdaPI, OdaPI) for closed spheres.  Zero corresponds to the meridian defined by
    the refAxis of this sphere.

    The sphere is *periodic* in V with a period of Oda2PI.

    [umin, umax] by [vmin, vmax] defines a spherical patch with 4 sides
    bounded by 2 longitudinal arcs and 2 latitudinal arcs.  

    The following constraints apply when defining a patch.

    o umin < umax and |umin - umax| <= Oda2PI.
    o vmin < vmax and |vmin - vmax| <= OdaPI.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeSphere : public OdGeSurface
{
public:


  /* Arguments:
    radius (I) The *radius* of this sphere.
    center (I) The origin of the this sphere.
    northAxis (I) the *direction* to the north pole.
    refAxis (I) the *direction* to the prime meridian.
    startAngleU (I) Starting longitude.
    endAngleU (I) Ending longitude.
    startAngleV (I) Starting latitude.
    endAngleV (I) Ending latitude.
  */
  OdGeSphere();
  OdGeSphere(
    double radius, 
    const OdGePoint3d& center);
  OdGeSphere(
    double radius, 
    const OdGePoint3d& center,
    const OdGeVector3d& northAxis, 
    const OdGeVector3d& refAxis,
    double startAngleU, 
    double endAngleU, 
    double startAngleV, 
    double endAngleV);
  OdGeSphere(const OdGeSphere& sphere);

  /**
    Description:
    Returns the *radius* of this sphere.
  */
   double radius() const;

  /**
    Description:
    Returns the *center* of this sphere.
  */
   OdGePoint3d center() const;

  /**
    Description:
    Returns the start and end longitude.

    Arguments:
    startAngleU (O) Receives the start longitude.
    endAngleU (O) Receives the end longitude.
  */
   void getAnglesInU(
    double& startAngleU, 
    double& endAngleU) const;

  /**
    Description:
    Returns the start and end latitude.

    Arguments:
    startAngleV (O) Receives the start latitude.
    endAngleV (O) Receives the end latitude.
  */
   void getAnglesInV(
    double& startAngleV, 
    double& endAngleV) const;

  /**
    Description:
    Returns the *direction* to the north pole.

    Arguments:
    northAxis (O) Receives the *direction* to the north pole.
  */
   OdGeVector3d northAxis() const;

  /**
    Description:
    Returns the *direction* to the north pole.

    Arguments:
    refAxis (O) Receives the *direction* to the prime meridian.
  */
   OdGeVector3d refAxis() const;

  /**
    Description:
    Returns the location of the north pole.
  */
   OdGePoint3d northPole() const;

  /**
    Description:
    Returns the location of the south pole.
  */
   OdGePoint3d southPole() const;

  /**
    Description:
    Returns true if and only if the *normal* to this surface
    is pointing outward.
  */
  OdBool isOuterNormal () const;

  /**
    Description:
    Returns true if and only if the equator is full circle.

    Arguments:
    tol (I) Geometric tolerance.
  */  
  OdBool isClosed (
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Sets the *radius* of this sphere.

    Arguments:
    radius (I) The *radius* of this sphere.
  */
   OdGeSphere& setRadius(
    double radius);

  /**
    Description:
    Sets the startint and ending longitudes.

    Arguments:
    startAngleU (I) Starting longitude.
    endAngleU (I) Ending longitude.
  */
   OdGeSphere& setAnglesInU(
    double startAngleU, 
    double endAngleU);

  /**
    Description:
    Sets the starting and ending latitudes.

    Arguments:
    startAngleV (I) Starting latitude.
    endAngleV (I) Ending latitude.
  */
   OdGeSphere& setAnglesInV(
    double startAngleV, 
    double endAngleV);

  /**
    Description:
    Sets the parameters for this sphere according to the arguments.

    Arguments:
    radius (I) The *radius* of this sphere.
    center (I) The origin of the this sphere.
    northAxis (I) the *direction* to the north pole.
    refAxis (I) the *direction* to the prime meridian.
    startAngleU (I) Starting longitude.
    endAngleU (I) Ending longitude.
    startAngleV (I) Starting latitude.
    endAngleV (I) Ending latitude.

    Remarks:
    Returns *a* reference to this sphere.
  */
   OdGeSphere& set(
    double radius, 
    const OdGePoint3d& center);
   OdGeSphere& set(
    double radius, 
    const OdGePoint3d& center,
    const OdGeVector3d& northAxis,
    const OdGeVector3d& refAxis,
    double startAngleU,
    double endAngleU,
    double startAngleV,
    double endAngleV);

  OdGeSphere& operator =(const OdGeSphere& sphere);

  /**
    Description:
    Returns true if and only if this cylinder intersects with
    a line entity, and returns the number of intersections and the
    points of intersection.

    Arguments:
    lineEnt (I) Any 3D *line* entity.
    numInt (O) Receives the number of intersections.
    p1 (O) Receives the first intersection *point*.
    p2 (O) Receives the second intersection *point*.
    tol (I) Geometric tolerance.

    Remarks:
    o p1 is valid if and only if numInt >= 1.
    o p2 is valid if and only if numInt = 2.
  */
  OdBool intersectWith (
    const OdGeLinearEnt3d& lineEnt, 
    int& numInt,
    OdGePoint3d& p1, 
    OdGePoint3d& p2,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /** \details
    Returns false if and only if clockwise direction for
    constant u-parameter lines are circles around northAxis,
    but counterclockwise if this is true.
  */
   bool isReverseV() const;

  /** \details
    Sets ReverseV according to the parameter.

    \param isReverseV [in]  Sets ReverseV.
  */
   void setReverseV(
     bool isReverseV);

  //////////////////////////////////////////////////////////////////////////

};

#include "../TD_PackPop.h"

#endif // OD_GESPHERE_H

