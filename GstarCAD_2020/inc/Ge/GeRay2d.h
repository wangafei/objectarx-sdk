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

#ifndef OD_GE_RAY_2D_H
#define OD_GE_RAY_2D_H /* {Secret} */

#include "../Ge/GeLinearEnt2d.h"

#include "../TD_PackPush.h"
class OdGeRay3dImpl;

/**
    Description:
    This class represents semi-infinite lines in 2D space.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeRay2d : public OdGeLinearEnt2d
{
public:
  

  /**Arguments:
    line (I) Any 2D *line*.
    point (I) Any 2D *point*.
    vect (I) Any 2D vector
    point1 (I) Any 2D *point*.
    point2 (I) Any 2D *point*.

    Remarks:
    point and vect construct a semi-infinite *line* starting point with 
    a *direction* of vect. vect cannot have a zero *length*.

    point1 and point2 construct a semi-infinite *line* starting at point1, and passing through point2. The 
    points cannnot be coincident.

    If called with no arguments, constructs a semi-infinite *line* starting at (0,0) and passing through (1,0).
  */
  OdGeRay2d();
  OdGeRay2d(OdGeRay3dImpl *);
  OdGeRay2d(const OdGeRay2d& ray);
  OdGeRay2d(
    const OdGePoint2d& point, 
    const OdGeVector2d& vect);
  OdGeRay2d(
    const OdGePoint2d& point1, 
    const OdGePoint2d& point2);
  
  /**
    Description:
    Sets the parameters for this *ray* according to the arguments.

    Arguments:
    point (I) Any 2D *point*.
    vect (I) Any 2D vector
    point1 (I) Any 2D *point*.
    point2 (I) Any 2D *point*.

    Remarks:
    Returns *a* reference to this *ray*.

    point and vect construct a semi-infinite *line* starting point with 
    a *direction* of vect. vect cannot have a zero *length*.

    point1 and point2 construct a semi-infinite *line* starting at point1, and passing through point2. The 
    points cannnot be coincident.
  */
  OdGeRay2d& set(
    const OdGePoint2d& point, 
    const OdGeVector2d& vect);
  OdGeRay2d& set(
    const OdGePoint2d& point1, 
    const OdGePoint2d& point2);

  OdGeRay2d& operator =(const OdGeRay2d& ray);

};

#include "../TD_PackPop.h"

#endif // OD_GE_RAY_2D_H
