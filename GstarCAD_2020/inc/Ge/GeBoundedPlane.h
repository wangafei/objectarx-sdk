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

#ifndef OD_GEBNDPLN_H
#define OD_GEBNDPLN_H  /* {Secret} */

#include "../Ge/GePlanarEnt.h"
#include "../Ge/GePlane.h"
#include "../Ge/GeVector3d.h"

class OdGePlane;
class OdGeVector3d;
class OdGePoint3d;
class OdGePoint2d;
class OdGeLineSeg3d;

#include "../TD_PackPush.h"

/**
    Description:
    This class represents bounded planes in 3D space.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeBoundedPlane : public OdGePlanarEnt
{
public:


  /**
    Arguments:
    origin (I) Origin of the bounded plane. 
    uAxis (I) u axis.
    vAxis (I) v axis.
    uPnt (I) A point at the end of the U-axis.
    vPnt (I) A point at the end of the V-axis.

    Remarks:
    Bounded planes can be specified with an *origin* and two vectors, or 
    with an *origin* and two points.

    With no arguments, constructs an infinite plane parallel to the XY plane.
  */
  OdGeBoundedPlane();
  OdGeBoundedPlane(const OdGeBoundedPlane& plane);
  OdGeBoundedPlane(
    const OdGePoint3d& origin,
    const OdGeVector3d& uAxis,
    const OdGeVector3d& vAxis);
  OdGeBoundedPlane(
    const OdGePoint3d& uPnt,
    const OdGePoint3d& origin,
    const OdGePoint3d& vPnt);

   bool intersectWith(
    const OdGeLinearEnt3d& linEnt, OdGePoint3d& point,
    const OdGeTol& tol = OdGeContext::gTol) const;
   bool intersectWith(
    const OdGePlane& plane, 
    OdGeLineSeg3d& intLine,
    const OdGeTol& tol = OdGeContext::gTol) const;
   bool intersectWith(
    const OdGeBoundedPlane& plane, 
    OdGeLineSeg3d& intLine,
    const OdGeTol& tol = OdGeContext::gTol) const;

   OdGeBoundedPlane& set(
    const OdGePoint3d& origin, 
    const OdGeVector3d& uAxis, 
    const OdGeVector3d& vAxis);
   OdGeBoundedPlane& set(
    const OdGePoint3d& uPnt,
    const OdGePoint3d& origin,
    const OdGePoint3d& vPnt);

  OdGeBoundedPlane& operator =(const OdGeBoundedPlane& plane);

  //////////////////////////////////////////////////////////////////////////
  TD_USING(OdGePlanarEnt::isOn);

};

#include "../TD_PackPop.h"

#endif // OD_GEBNDPLN_H

