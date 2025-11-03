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


#ifndef OD_GE_POINT_ON_CURVE_2D_H
#define OD_GE_POINT_ON_CURVE_2D_H /* {Secret} */

#include "../Ge/GePointEnt2d.h"
class OdGeCurve2d;

#include "../TD_PackPush.h"

/**
    Description:
    This class represents points along 2D curves.

    Remarks:
    The *point* representation includes its *parameter* value, its coordinates, and the
    the *derivatives* of the *curve* at that *point*. 

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGePointOnCurve2d : public OdGePointEnt2d
{
public:
  

  /**
    Arguments:
    curve2d (I) Any 2D *curve*.
    param (I) *Parameter* to specify a *point* on curve2d.
    source (I) Object to be cloned.

    Remarks:
    The default constructor constructs a *point* on the *curve* OdGeLine2d::kXAxis with a *parameter* value of 0.
  */
  OdGePointOnCurve2d();

  OdGePointOnCurve2d(
    const OdGeCurve2d& curve2d, 
    double param = 0.0);

  OdGePointOnCurve2d(
    const OdGePointOnCurve2d& source);

  OdGePointOnCurve2d& operator =(
    const OdGePointOnCurve2d& pntOnCurve);

  /**
    Description:
    Returns the *curve* on which the *point* lies.
  */
  const OdGeCurve2d* curve() const;

  /**
    Description:
    Returns the *parameter* value on the *curve* corresponding to the *point*.
  */
  double parameter() const;

  /*
    Description:
    Returns the *point* on the *curve*.

    Arguments:
    param (I) Sets the current *parameter*.
    curve2d (I) Any 2D *curve*. Sets the current *curve*.
  */
  OdGePoint2d point() const;

  OdGePoint2d point(
    double param);

  OdGePoint2d point(
    const OdGeCurve2d& curve2d, 
    double param);

  /**
    Description:
    Returns the derivitive of the *curve* at the *point* on the *curve*.

    Arguments:
    order (I) Specifies the *order* of the derivitive [1-2].
    param (I) Sets the current *parameter*.
    curve2d (I) Any 2D *curve*. Sets the current *curve*.
  */
  OdGeVector2d deriv(
    int order) const;

  OdGeVector2d deriv(
    int order, 
    double param);

  OdGeVector2d deriv(
    int order, 
    const OdGeCurve2d& curve2d,
    double param);

  /**
    Description:
    Returns true if and only if the first derivative *vector* 
    has a length of zero.

    Arguments:
    tol (I) Geometric tolerance.
  */
  OdBool isSingular (
    const OdGeTol& tol = OdGeContext::gTol) const;


  /**
    Description:
    Returns true if and only if the first derivative *vector* has a non-zero length, and
    the *curvature* of the *curve* at the *point* on the *curve*. 

    Arguments:
    param (I) *parameter* to specify a *point* on curve2d.
    res (O) Receives the *curvature* of the *curve* at the specified *point*.
  */
  OdBool curvature (
    double& res);

  OdBool curvature (
    double param, 
    double& res);

  /**
    Description:
    Sets the current *curve*.

    Arguments:
    curve2d (I) Any 2D *curve*.
  */
  OdGePointOnCurve2d& setCurve(
    const OdGeCurve2d& curve2d);

  /**
    Description:
    Sets the current *parameter*.

    Arguments:
    param (I) Sets the current *parameter*.
  */
  OdGePointOnCurve2d& setParameter(
    double param);

};

#include "../TD_PackPop.h"

#endif


