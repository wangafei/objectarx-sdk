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

#ifndef OD_GEPLANE_H
#define OD_GEPLANE_H /* {Secret} */

#include "../Ge/GePlanarEnt.h"
#include "../TD_PackPush.h"

class OdGeBoundedPlane;
class OdGeLine3d;
class OdGeLineSeg3d;

/**
    Description:
    This class represents infinite planes in 3D space.

    Library: TD_Ge

   {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGePlane : public OdGePlanarEnt
{
public:


  GE_STATIC_EXPORT static const OdGePlane kXYPlane; // XY *plane*.
  GE_STATIC_EXPORT static const OdGePlane kYZPlane; // YZ *plane*.
  GE_STATIC_EXPORT static const OdGePlane kZXPlane; // ZY *plane*.

  /**
    Arguments:
    origin (I)  Origin of *plane*.
    normal (I)  The *normal* to the *plane*.
    uPnt (I) A point at the end of the U-axis.
    vPnt (I) A point at the end of the V-axis.
    uAxis (I) The U-axis.
    vAxis (I) The V-axis.
    a (I) Coefficient *a*.
    b (I) Coefficient *b*.
    c (I) Coefficient *c*.
    d (I) Coefficient *d*.

    Remarks:
    A parametric *point* on the *plane* with parameters u and v maps to the *point* S(u,v) as follows

            S(u,v) = originOfPlanarEntity + (u * uAxis) + (v * vAxis)

    uAxis and vAxis need not be either normalized or perpendicular, but they must
    not be collinear.

    The orthonormal canonical coordinate system associated with *a* *plane* defined follows

    @untitled table
    *origin*        Origin of *plane*.                            originOfPlanarEntiity                 
    axis1           A unit vector in the *plane*.                 uAxis.normal()                        
    axis2           A unit vector perpendicular to the *plane*.   uAxis.crossProduct(vAxis).normal()   

    The *plane* equation for this *plane* is as follows

            a * X + b * Y + c * Z + d = 0
  */
  OdGePlane();
  OdGePlane(
    const OdGePlane& plane);
  OdGePlane(
    const OdGePoint3d& origin, 
    const OdGeVector3d& normal);
  OdGePlane(
    const OdGePoint3d& uPnt, 
    const OdGePoint3d& origin, 
    const OdGePoint3d& vPnt);
  OdGePlane(
    const OdGePoint3d& origin, 
    const OdGeVector3d& uAxis, 
    const OdGeVector3d& vAxis);
  OdGePlane(
    double a, 
    double b, 
    double c, 
    double d);

  /**
    Description:
    Returns true and the intersection *point* or *line*, if and only 
    if the specified *line* or *plane* intersects with this *plane*.

    Arguments:
    line (I) Any 3D linear entity.
    plane (I) Any *plane*.
    intLine (O) Receives the intersection *line*.
    point (O) Receives the intersection *point*. 
    tol (I) Geometric tolerance.
  */
  TD_USING(OdGePlanarEnt::intersectWith);
  OdBool intersectWith (
    const OdGePlane& plane, 
    OdGeLine3d& intLine,
    const OdGeTol& tol = OdGeContext::gTol) const;
  OdBool intersectWith (
    const OdGeBoundedPlane& plane, 
    OdGeLineSeg3d& intLine,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the signed distance to (elevation of) the specified *point*.

    Arguments:
    point (I) Any 3D *point*.
  */
   double signedDistanceTo(
    const OdGePoint3d& point) const;

   /**
    Description:
    Sets the parameters for this *plane* according to the arguments. 

    Arguments:
    origin (I)  Origin of *plane*.
    normal (I)  The *normal* to the *plane*.
    uPnt (I) A point at the end of the U-axis.
    vPnt (I) A point at the end of the V-axis.
    uAxis (I) The U-axis.
    vAxis (I) The V-axis.
    a (I) Coefficient *a*.
    b (I) Coefficient *b*.
    c (I) Coefficient *c*.
    d (I) Coefficient *d*.

    Remarks:
    Returns *a* reference to this *plane*.

    A parametric *point* on the *plane* with parameters u and v maps to the *point* S(u,v) as follows

            S(u,v) = originOfPlanarEntity + (u * uAxis) + (v * vAxis)

    uAxis and vAxis need not be either normalized or perpendicular, but they must
    not be collinear.

    The orthonormal canonical coordinate system associated with *a* *plane* defined follows

    @untitled table
    *origin*        Origin of *plane*.                            originOfPlanarEntiity                 
    axis1           A unit vector in the *plane*.                 uAxis.normal()                        
    axis2           A unit vector perpendicular to the *plane*.   uAxis.crossProduct(vAxis).normal()   

    The *plane* equation for this *plane* is as follows

            a * X + b * Y + c * Z + d = 0
  */
   OdGePlane& set(
    const OdGePoint3d& point, 
    const OdGeVector3d& normal);
   OdGePlane& set(
    const OdGePoint3d& uPnt, 
    const OdGePoint3d& origin, 
    const OdGePoint3d& vPnt);
   OdGePlane& set(
    double a, 
    double b, 
    double c, 
    double d);
   OdGePlane& set(
    const OdGePoint3d& origin, 
    const OdGeVector3d& uAxis, 
    const OdGeVector3d& vAxis);

  OdGePlane& operator =(
    const OdGePlane& plane);

private:
  OdGePlane(OdGeEntity3dImpl*);
};


#include "../TD_PackPop.h"

#endif // OD_GEPLANE_H

