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


#ifndef OD_GEPNT2D_H
#define OD_GEPNT2D_H /* {Secret} */

#include "../Ge/GeVector2d.h"
#include "../OdArray.h"
#if defined(WIN32) || defined(_WIN32_WCE) || defined(__MWERKS__)
#include <math.h>
#else
#include <complex>
#endif

class OdGeMatrix2d;
class OdGeVector2d;
class OdGeLinearEnt2d;
class OdGeLine2d;

#include "../TD_PackPush.h"

/**
    Description:
    This class represents points (locations) in 2D space. 

    Remarks:
    OdGePoint2d may be viewed as an array[2] of doubles.
    
    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGePoint2d
{
public:
  /**
    Arguments:
    xx (I) The X-coordinate of this *point*.
    yy (I) The Y-coordinate of this *point*.
    source (I) Object to be cloned.
  */
  OdGePoint2d()
    : x (0.0), y (0.0)
  {
  }

  OdGePoint2d(
    const OdGePoint2d& source) 
    : x (source.x), y (source.y)
  {
  }

  OdGePoint2d(
    double xx, 
    double yy) 
    : x (xx), y (yy)
  {
  }

  GE_STATIC_EXPORT static const OdGePoint2d kOrigin; // Origin (0,0).

  /**
    Remarks:
    Sets this *point* to the result of the matrix multiplication matrix * point,
    or the point scaled by a factor of scale. 

    Arguments:
    matrix (I) Any 2D *matrix*.
    scale (I) Scale factor.
    point (I) The *point* to be multiplied.
  */
  friend GE_TOOLKIT_EXPORT OdGePoint2d operator *(
    const OdGeMatrix2d& matrix, 
    const OdGePoint2d& point);

  friend GE_TOOLKIT_EXPORT OdGePoint2d operator *(
    double scale, 
    const OdGePoint2d& point);

  /**
    Description:
    Sets this *point* to the result of the *matrix* multiplication (matrix * point).
    Returns a reference to this *point*.

    Arguments:
    matrix (I) A 2D *matrix*.
    point (I) The *point* to be multiplied.
  */
  OdGePoint2d& setToProduct(
    const OdGeMatrix2d& matrix, 
    const OdGePoint2d& point);

  /**
    Description:
    Sets this *point* to the result of the matrix multiplication xfm * this *point*.
    Returns a reference to this *point*.

    Arguments:
    xfm (I) A 2D matrix.
  */
  OdGePoint2d& transformBy(
    const OdGeMatrix2d& xfm);

  /**
    Description:
    Rotates this *point* about the specified basePoint by the specified angle. 

    Arguments:
    angle (I) Rotation *angle*.
    basePoint (I) Basepoint.
  */
  OdGePoint2d& rotateBy(
    double angle, 
    const OdGePoint2d& basePoint = kOrigin);

  /**
    Description:
    Mirrors this *point* about the specified 2D *line*.

    Arguments:
    line (I) Mirror *Line*.
  */
  OdGePoint2d& mirror(
    const OdGeLine2d& line);

  /**
    Description:
    Scales this *point* by the scale factor about the basepoint.

    Arguments:
    scaleFactor (I) Scale Factor. The scale factor must be greater than zero.
    basePoint (I) Basepoint.
  */
  OdGePoint2d& scaleBy(
    double scaleFactor, 
    const OdGePoint2d& basePoint = kOrigin);

  OdGePoint2d operator *(
    double scale) const
  {
    return OdGePoint2d (x*scale, y*scale);
  }

  OdGePoint2d& operator *=(
    double scale)
  {
    x *= scale;
    y *= scale;
    return *this;
  }

  OdGePoint2d operator /(
    double scale) const
  {
    return OdGePoint2d (x/scale, y/scale);
  }

  OdGePoint2d& operator /=(
    double scale)
  {
    x /= scale;
    y /= scale;
    return *this;
  }

  OdGePoint2d operator +(
    const OdGeVector2d& vect) const
  {
    return OdGePoint2d (x + vect.x, y + vect.y);
  }

  OdGePoint2d& operator +=(
    const OdGeVector2d& vect)
  {
    x += vect.x;
    y += vect.y;
    return *this;
  }

  OdGePoint2d operator -(
    const OdGeVector2d& vect) const
  {
    return OdGePoint2d (x - vect.x, y - vect.y);
  }

  OdGePoint2d& operator -=(
    const OdGeVector2d& vect)
  {
    x -= vect.x;
    y -= vect.y;
    return *this;
  }

  /**
    Description:
    Sets this *point* to point + vect, and returns a reference to this *point*.

    Arguments:
    point (I) Any 2D *point*.
    vect (I) A 2D vector.
  */
  OdGePoint2d& setToSum(
    const OdGePoint2d& point, 
    const OdGeVector2d& vect)
  {
    x = point.x + vect.x;
    y = point.y + vect.y;
    return *this;
  }

  OdGeVector2d operator -(
    const OdGePoint2d& point) const
  {
    return OdGeVector2d (x - point.x, y - point.y);
  }

  /**
    Description:
    Returns this *point* as a vector.
  */
  OdGeVector2d asVector() const
  {
    return OdGeVector2d(x, y);
  }
  
  /**
    Description:
    Returns the distance from this *point* to the specified *point*.

    Arguments:
    point (I) Any 2D *point*.
  */
  double distanceTo(
    const OdGePoint2d& point) const
  {
    return sqrt ( (x-point.x)* (x-point.x)+ (y-point.y)* (y-point.y));
  }

  bool operator == (
    const OdGePoint2d& point) const
  {
    return isEqualTo (point);
  }
  bool operator != (
    const OdGePoint2d& point) const
  {
    return !isEqualTo (point);
  }

  /**
    Description:
    Returns true if and only if the distance from this *point* to point is within the 
    specified tolerance.

    Arguments:
    point (I) Any 2D *point*.
    tol (I) Geometric tolerance.
  */
  bool isEqualTo (
    const OdGePoint2d& point, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**

    Arguments:
    i (I) Index of coordinate.

    Remarks:
    Returns or references the ith coordinate of this *point*.
    
    o 0 returns or references the X-coordinate.
    o 1 returns or references the Y-coordinate.
  */
  double& operator [](
    unsigned int i)
  {
    return * (&x+i);
  }
  double operator [](
    unsigned int i) const
  {
    return * (&x+i);
  }

  /**
    Description:
    Sets this *point* to the specified X and Y coordinates. 
    Returns a reference to this *point*.

    Arguments:
    xx (I) The X-coordinate of this *point*.
    yy (I) The Y-coordinate of this *point*.
  */
  OdGePoint2d& set(
    double xx, 
    double yy)
  {
    x = xx;
    y = yy;
    return *this;
  }

  double x; // X-coordinate
  double y; // Y-coordinate
};

#include "../TD_PackPop.h"

#endif

