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

#ifndef OD_GE_LINE_SEG_2D_H
#define OD_GE_LINE_SEG_2D_H /* {Secret} */

#include "../Ge/GeLine2d.h"
#include "../Ge/GeLinearEnt2d.h"

#include "../TD_PackPush.h"

class OdGeLineSeg3dImpl;
/**
    Description:
    This class represents line segments in 2D space.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeLineSeg2d : public OdGeLinearEnt2d
{
public:
  

  /**
    Arguments:
    line (I) Any 2D *line*.
    point (I) Any 2D *point*.
    point1 (I) Any 2D *point*.
    point2 (I) Any 2D *point*.
    vect (I) Any 2D vector
    source (I) Object to be cloned.

    Remarks:
    point and vect construct a *line* segment between points point and point + vect. vect cannot have a zero *length*.

    point1 and point2 construct a *line* segment between points point1 and point2. The 
    points cannot be coincident.

    If called with no arguments, constructs a *line* segment between the points (0,0) and (1,0).
  */
  OdGeLineSeg2d();
  OdGeLineSeg2d(OdGeLineSeg3dImpl *);
  OdGeLineSeg2d(
    const OdGeLineSeg2d& source);
  OdGeLineSeg2d(
    const OdGePoint2d& point1, 
    const OdGePoint2d& point2);
  OdGeLineSeg2d(
    const OdGePoint2d& point, 
    const OdGeVector2d& vect);

  /**
    Description:
    Sets the parameters for this *line* according to the arguments, and returns a reference to this *line*.

    Arguments:
    point (I) Any 2D *point*.
    point1 (I) Any 2D *point*.
    point2 (I) Any 2D *point*.
    vect (I) Any 2D vector
    curve (I) Any 2D *curve*.
    curve1 (I) Any 2D *curve* 
    curve2 (I) Any 2D *curve* 
    param (I) Point on curve1 where this *line* segment is tangent to curve 
    param1 (I) Point on curve1 where this *line* segment is tangent to curve1 
    param2 (I) Point on curve2 where this *line* segment is tangent to curve2 
    success (O) Receives true if and only if the tangent was constructed. If false, this *line* segment is unchanged.

    Remarks:
    point and vect construct a *line* segment between points point and point + vect. vect cannot have a zero *length*.

    point1 and point2 construct a *line* segment between points point1 and point2. The 
    points cannot be coincident.
    
    curve1 and curve2 construct a tangent *line* segment between curve1 and curve2. param1 and param2 are  
    the approximate tangent points on curve1 and curve2, respectively.
    
    curve and point construct a *line* segment starting at point, and tangent to *curve*. 
    param is the approximate tangent point on *curve*.
  */
  OdGeLineSeg2d& set(
    const OdGePoint2d& point, 
    const OdGeVector2d& vect);
  OdGeLineSeg2d& set(
    const OdGePoint2d& point1, 
    const OdGePoint2d& point2);
  OdGeLineSeg2d& set(
    const OdGeCurve2d& curve1, 
    const OdGeCurve2d& curve2,
    double& param1, 
    double& param2, 
    OdBool& success);
  OdGeLineSeg2d& set(
    const OdGeCurve2d& curve, 
    const OdGePoint2d& point, 
    double& param, 
    OdBool& success);

  /**
    Description:
    Returns the infinite perpendicular bisector of this *line* segment.
    
    Arguments:
    line (O) Receives the perpendicular bisector.
  */
  void getBisector(
    OdGeLine2d& line) const;
    
  /**
    Description:
    Returns the weighted average of the start point and end point of this *line* segment.
    
    Arguments:
    blendCoeff (I) Blend coefficient.
    
    Remarks:
    @table
    blendCoeff      Returns
    0               start point
    1               end point
    0 to 1          *point* on this *line* segment
    < 0 or > 1      *point* not on this *line* segment, but colinear with it.
  */
  OdGePoint2d baryComb(
    double blendCoeff) const;


  /**
    Description:
    Returns the start point of this *line* segment.
  */
  OdGePoint2d startPoint() const;
  
  /**
    Description:
    Returns the midpoint of this *line* segment.
  */
  OdGePoint2d midPoint() const;
  
  /**
    Description:
    Returns the end point of this *line* segment.
  */
  OdGePoint2d endPoint() const; 

  double length() const;
  double length(double fromParam, double toParam,
    double tol = OdGeContext::gTol.equalPoint());

  OdGeLineSeg2d& operator =(const OdGeLineSeg2d& line);
};

#include "../TD_PackPop.h"

#endif // OD_GE_LINE_SEG_2D_H

