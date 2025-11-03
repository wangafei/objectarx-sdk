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

#ifndef OD_GELNSG3D_H
#define OD_GELNSG3D_H /* {Secret} */

class OdGeLineSeg2d;
class OdGeLineSeg3dImpl;

#include "../Ge/GeLine3d.h"
#include "../Ge/GeInterval.h"
#include "../Ge/GePlane.h"

#include "../TD_PackPush.h"

/**
    Description:
    This class represents line segments in 3D space.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeLineSeg3d : public OdGeLinearEnt3d
{
public:


  /**
    Arguments:
    line (I) Any 3D *line*.
    point (I) Any 3D *point*.
    point1 (I) Any 3D *point*.
    point2 (I) Any 3D *point*.
    vect (I) Any 3D vector.
    source (I) Object to be cloned.

    Remarks:
    point and vect construct a *line* segment between points point and point + vect. vect cannot have a zero *length*.

    point1 and point2 construct a *line* segment between points point1 and point2. The 
    points cannot be coincident.

    If called with no arguments, constructs a *line* segment between the points (0,0) and (1,0).
  */
  OdGeLineSeg3d();
  OdGeLineSeg3d(OdGeLineSeg3dImpl * impl);
  OdGeLineSeg3d(
    const OdGeLineSeg3d& source);
  OdGeLineSeg3d(
    const OdGePoint3d& point, 
    const OdGeVector3d& vect);
  OdGeLineSeg3d(
    const OdGePoint3d& point1, 
    const OdGePoint3d& point2);

   void getBisector(OdGePlane& plane) const;

   OdGePoint3d baryComb(double blendCoeff) const;

  /**
    Description:
    Returns the *start point* of this *line*.
  */
   OdGePoint3d startPoint() const;

  /**
    Description:
    Returns the *midpoint* of this *line*.
  */
   OdGePoint3d midPoint() const;

  /**
    Description:
    Returns the *end point* of this *line*.
  */
   OdGePoint3d endPoint() const;

  /**
    Description:
    Sets the parameters for this *line* according to the arguments, and returns a reference to this *line*.

    Arguments:
    point (I) Any 3D *point*.
    point1 (I) Any 3D *point*.
    point2 (I) Any 3D *point*.
    vect (I) Any 3D vector.

    Remarks:
    point and vect construct a *line* segment between points point and point + vect. vect cannot have a zero *length*.

    point1 and point2 construct a *line* segment between points point1 and point2. The 
    points cannot be coincident.
  */
   OdGeLineSeg3d& set(
    const OdGePoint3d& point, 
    const OdGeVector3d& vect);
   OdGeLineSeg3d& set(
    const OdGePoint3d& point1, 
    const OdGePoint3d& point2);
   OdGeLineSeg3d& set(
    const OdGeCurve3d& curve1,
    const OdGeCurve3d& curve2,
    double& param1, double& param2,
    OdBool& success);
   OdGeLineSeg3d& set(
    const OdGeCurve3d& curve,
    const OdGePoint3d& point,
    double& param,
    OdBool& success);

  OdGeLineSeg3d& operator =(
    const OdGeLineSeg3d& line);

};

#include "../TD_PackPop.h"

#endif

