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

#ifndef OD_GELENT3D_H
#define OD_GELENT3D_H /* {Secret} */

class OdGeLine3d;
class OdGeCircArc3d;
class OdGePlanarEnt;
class OdGeLinearEnt3dImpl;

#include "../OdPlatform.h"

#include "../Ge/GeCurve3d.h"
#include "../Ge/GePoint3d.h"
#include "../Ge/GeVector3d.h"

#include "../TD_PackPush.h"

/**
    Description:
    This class is the base class for OdGe 3D linear entities.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeLinearEnt3d : public OdGeCurve3d
{
public:

  ///////////////////////////////////////////////////////////////////////////

  /**
    Description:
    Returns true and the intersection point, if and only 
    if the specified *line* or *plane* intersects with this *line*.

    Arguments:
    line (I) Any 3D linear entity.
    plane (I) Any planar entity.
    intPnt (O) Receives the intesection *point*.
    tol (I) Geometric tolerance.
  */
  OdBool intersectWith (
    const OdGeLinearEnt3d& line,
    OdGePoint3d& intPt,
    const OdGeTol& tol = OdGeContext::gTol) const;

  OdBool intersectWith (
    const OdGePlanarEnt& plane, 
    OdGePoint3d& intPnt,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the projected intersection of the specified *line* with this *line*.

    Arguments:
    line (I) Any 3D *line*.
    projDir (I) Projection *direction*.
    pntOnThisLine (O) Receives the intersection *point* on this *line*.   
    pntOnOtherLine (O) Receives the intersection *point* on the other *line*. 
    tol (I) Geometric tolerance.
    */
  OdBool projIntersectWith (
    const OdGeLinearEnt3d& line,
    const OdGeVector3d& projDir,
    OdGePoint3d& pntOnThisLine,
    OdGePoint3d& pntOnOtherLine,
    const OdGeTol& tol = OdGeContext::gTol) const;

   OdBool overlap(
    const OdGeLinearEnt3d& line,
    OdGeLinearEnt3d*& overlap,
    const OdGeTol& tol = OdGeContext::gTol) const;

  TD_USING(OdGeCurve3d::isOn);
   OdBool isOn(
    const OdGePlane& plane,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only 
    if the specified entity is parallel to this *line*.

    Arguments:
    line (I) Any 3D linear entity.
    plane (I) Any *plane*.
    tol (I) Geometric tolerance.
  */
   OdBool isParallelTo(
    const OdGeLinearEnt3d& line,
    const OdGeTol& tol = OdGeContext::gTol) const;
   OdBool isParallelTo(
    const OdGePlanarEnt& plane,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only 
    if the specified entity is perpendicular to this *line*.

    Arguments:
    line (I) Any 3D linear entity.
    plane (I) Any *plane*.
    tol (I) Geometric tolerance.
  */
   OdBool isPerpendicularTo(
    const OdGeLinearEnt3d& line,
    const OdGeTol& tol = OdGeContext::gTol) const;
   OdBool isPerpendicularTo(
    const OdGePlanarEnt& plane,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /** 
    Description:
    Returns true if and only if the specified *line* is colinear with this one. 

    Arguments:
    line (I) Any 3D linear entity.
    tol (I) Geometric tolerance.
  */
   OdBool isColinearTo(
    const OdGeLinearEnt3d& line,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /** 
    Description:
    Returns a *plane*, containing the specified *point*, perpendicular to this *line*.

    Arguments:
    point (I) Any 3D *point*.
    plane (O) Receives the perpendicular *plane*.

    Remarks:
    The returned plane is created with the new method. It is up to the caller to delete it.
  */
   void getPerpPlane(
      const OdGePoint3d& point, 
      OdGePlane& plane) const;

  /**
    Description:
    Returns an arbitrary *point* on this *line*.
  */
   OdGePoint3d pointOnLine() const;

  /**
    Description:
    Returns a unit vector parallel to this *line*, 
    and pointing in the *direction* of increasing parametric value.
  */
   OdGeVector3d direction() const;

  /**
    Description:
    Returns a reference to an infinite line colinear with this one.

    Arguments:
    line (O) Receives the infinite *line*.
  */
   void getLine(OdGeLine3d& line) const;

  OdGeLinearEnt3d& operator =(
      const OdGeLinearEnt3d& line);
protected:
  OdGeLinearEnt3d(); 
  OdGeLinearEnt3d(OdGeLinearEnt3dImpl* impl);
  OdGeLinearEnt3d(
    const OdGeLinearEnt3d& source);
};

#include "../TD_PackPop.h"

#endif // OD_GELENT3D_H
