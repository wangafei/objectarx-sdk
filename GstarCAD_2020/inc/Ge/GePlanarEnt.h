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

#ifndef OD_GEPLANAR_H
#define OD_GEPLANAR_H /* {Secret} */

#include "../Ge/GeSurface.h"
#include "../Ge/GeVector3d.h"
#include "../Ge/GeInterval.h"
#include "../OdPlatformSettings.h"

class OdGeLinearEnt3d;

#include "../TD_PackPush.h"

/**
    Description:
    This class is the base class for all OdGe planes in 3D space.

    Remarks:
    A parametric *point* on the *plane* with parameters u and v maps to the *point* S(u,v) as follows

              S(u,v) = originOfPlanarEntity + (u * uAxis) + (v * vAxis)

    uAxis and vAxis need not be either normalized or perpendicular, but they must
    not be colinear.

    @table
    Parameter       Description                                   Computed as
    *origin*        Origin of *plane*.                            *origin*              
    axis1           A unit vector in the *plane*.                 uAxis.normal()                        
    axis2           A unit vector perpendicular to the *plane*.   uAxis.crossProduct(vAxis).normal()   

    The *plane* equation for *a* *plane* is as follows

              a * X + b * Y + c * Z + d = 0

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGePlanarEnt : public OdGeSurface
{
public:


  /**
    Description:
    Returns true and the intersection with the specified linear entity,
    if and only if the specified linear entity intersects with this *plane*.

    Arguments:
    line (I) Any 3D linear entity.
    point (O) Receives the *point* of intersection. 
    tol (I) Geometric tolerance.
  */
  OdBool intersectWith (
    const OdGeLinearEnt3d& line, 
    OdGePoint3d& point,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the point on this plane that is closest to the specified linear entity, 
	and the point on the linear entity that is closest to this plane.

    Arguments:
    line (I) Any 3D linear entity.
    pointOnLine (O) Receives the closest point on the linear entity.
    tol (I) Geometric tolerance.
  */
   OdGePoint3d closestPointToLinearEnt(
    const OdGeLinearEnt3d& line,
    OdGePoint3d& pointOnLine, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the point on this plane that is closest to the specified plane, and the point
    on the specified plane that is closest to this plane.

    Arguments:
    plane (I) Any plane.
    pointOnOtherPlane (O) Receives the closest point on the plane.
    tol (I) Geometric tolerance.
  */
   OdGePoint3d closestPointToPlanarEnt(
    const OdGePlanarEnt& plane,
    OdGePoint3d& pointOnOtherPlane, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only if the specified entity is parallel to this one.

    Arguments:
    line (I) Any 3D linear entity.
    plane (I) Any *plane*.
    tol (I) Geometric tolerance.
  */
  OdBool isParallelTo (
    const OdGeLinearEnt3d& line, 
    const OdGeTol& tol = OdGeContext::gTol) const;
  OdBool isParallelTo (
    const OdGePlanarEnt& plane,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only if the specified entity is perpendicular to this one.

    Arguments:
    line (I) Any 3D linear entity.
    plane (I) Any *plane*.
    tol (I) Geometric tolerance.
  */
  OdBool isPerpendicularTo (
    const OdGeLinearEnt3d& line,
    const OdGeTol& tol = OdGeContext::gTol) const;
  OdBool isPerpendicularTo (
    const OdGePlanarEnt& plane,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only 
    the specified *plane* is colinear with this one.

    Arguments:
    plane (I) Any *plane*.
    tol (I) Geometric tolerance.
  */
  OdBool isCoplanarTo (
    const OdGePlanarEnt& plane,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the parameters of this *plane*.

    Arguments:
    origin (I) The *origin* of this *plane*.
    uAxis (I) The U-axis.
    vAxis (I) The V-axis.
    uPnt (I) A *point* at the end of the U-axis.
    vPnt (I) A *point* at the end of the V-axis.

    Remarks:
    The U-axis and V-axis cannot be colinear, and are defined as follows

            uAxis=uPnt-origin
            vAxis=vPnt-origin
  */
   void get(
    OdGePoint3d& origin, 
    OdGeVector3d& uAxis, 
    OdGeVector3d& vAxis) const;
   void get(
    OdGePoint3d& uPnt, 
    OdGePoint3d& origin, 
    OdGePoint3d& vPnt) const;

  /**
    Description:
    Returns an arbitrary *point* on the *plane*.
  */
   OdGePoint3d pointOnPlane() const;

  /**
    Description:
    Returns the *normal* to the plane as a unit vector. 
  */
   OdGeVector3d normal() const;

  /**
    Description
    Returns the coefficients of the *plane* equation for this *plane*.

    Arguments:
    a (O) Receives the coefficient *a*.
    b (O) Receives the coefficient *b*.
    c (O) Receives the coefficient *c*.
    d (O) Receives the coefficient *d*.

    Remarks:
    The *plane* equation for this *plane* is as follows

            a * x + b * y + c * z + d = 0
  */
   void getCoefficients(
    double& a, 
    double& b, 
    double& c, 
    double& d) const;

  /**
    Description:
    Returns the orthonormal canonical coordinate system of this *plane*.

    Arguments:
    origin (O) Receives the origin of this *plane*
    axis1 (O) Receives a unit vector in the *plane*.
    axis2 (O) Receives a unit vector perpendicular to the *plane*.

    Remarks
    The orthonormal canonical coordinate system associated with *a* *plane* defined follows

    @table
    Parameter       Description                                           Computed as
    *origin*        Origin of *plane*.                                    *origin*              
    axis1           A unit vector in the *plane*.                         uAxis.normal()                        
    axis2           A unit vector in the *plane* perpendicular to axis1.  normal.crossProduct(axis1)   
  */
   void getCoordSystem(
    OdGePoint3d& origin, 
    OdGeVector3d& axis1, 
    OdGeVector3d& axis2) const;

  OdGePlanarEnt& operator =(
    const OdGePlanarEnt& plane);

  //////////////////////////////////////////////////////////////////////////
  // TD Special :

  /**
    Description:
    Set the rectangle in parameter space that defines the parameter
    domain of this surface.

    Arguments:
    intrvlU (O) u interval
    intrvlV (O) v interval
  */
   bool setEnvelope(
    const OdGeInterval& intrvlU, 
    const OdGeInterval& intrvlV);

  /**
    Description:
    Returns projP and true,
    if and only if there is *a* *point* on this surface, projP, where
    the this surface *normal* or unitDir (if specified) passes through the point p.

    Arguments:
    p (I) Any 3D *point*.
    projP (O) Receives the *point* on the *plane*.
    unitDir (I) Unit vector specifying the projection direction.
    tol (I) Geometric tolerance.
  */
  TD_USING(OdGeSurface::project);
  OdBool project(
    const OdGePoint3d& p, 
    const OdGeVector3d& unitDir, 
    OdGePoint3d& projP, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  //////////////////////////////////////////////////////////////////////////

protected:
  OdGePlanarEnt();
  OdGePlanarEnt(const OdGePlanarEnt& plane);
};

#include "../TD_PackPop.h"

#endif // OD_GEPLANAR_H

