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


#ifndef OD_GEPNT3D_H
#define OD_GEPNT3D_H /* {Secret} */

#include "../Ge/GeVector3d.h"
#include "../Ge/GePoint2d.h"
#include "../OdArray.h"

class OdGeMatrix3d;
class OdGeLinearEnt3d;
class OdGePlane;
class OdGePlanarEnt;
class OdGeVector3d;
class OdGePoint2d;

#include "../TD_PackPush.h"

/**
    Description:
    This class represents points (locations) in 3D space. 

    Remarks:
    OdGePoint3d may be viewed as an array[3] of doubles.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGePoint3d
{
public:
  /**
    Arguments:
    xx (I) The X-coordinate of this *point*.
    yy (I) The Y-coordinate of this *point*.
    zz (I) The Z-coordinate of this *point*.
    plane (I) Any *plane*.
    pnt2d (I) Any 2D *point*.
    source (I) Object to be cloned.
    
    Remarks:
    plane and pnt2d define a point as follows:
            
            p + uAxis * pnt2d.x + vAxis * pnt2d.y,
            
    where p, uAxis, and vAxis are returned by the function call plane.get (p, uAxis, vAxis);
    
    With no arguments, creates a point at the origin.
  */
  OdGePoint3d() 
    : x (0.0), y (0.0), z (0.0)
  {
  }
  OdGePoint3d(
    const OdGePoint3d& source)
    : x (source.x), y (source.y), z (source.z)
  {
  }
    
  OdGePoint3d(
    double xx, 
    double yy, 
    double zz)
    : x (xx), y (yy), z (zz)
  {
  }
  
  OdGePoint3d(
    const OdGePlanarEnt& plane, 
    const OdGePoint2d& pnt2d);

  GE_STATIC_EXPORT static const OdGePoint3d kOrigin; // Origin (0,0,0).

  friend GE_TOOLKIT_EXPORT OdGePoint3d operator *(
    const OdGeMatrix3d& matrix, 
    const OdGePoint3d& point);
    
  friend GE_TOOLKIT_EXPORT OdGePoint3d operator *(
    double scale, 
    const OdGePoint3d& point)
  {
    return OdGePoint3d(point.x * scale, point.y * scale, point.z * scale);
  }

  /**
    Description:
    Sets this *point* to the product of xfm * point, and returns a reference to this *point*.
    
    Arguments:
    xfm (I) A 3D matrix. 
    point (I) Any 3D *point*. 
  */
  OdGePoint3d& setToProduct(
    const OdGeMatrix3d& xfm, 
    const OdGePoint3d& point);

  /**
    Description:
    Sets this *point* to the result of the matrix multiplication xfm * this *point*.
    Returns a reference to this *point*.

    Arguments:
    xfm (I) A 3D matrix.
  */
  OdGePoint3d& transformBy(
    const OdGeMatrix3d& xfm);
 
  /**
    Description:
    Rotates this *point* about the specified basePoint and axis of rotation by the specified angle. 

    Arguments:
    angle (I) Rotation *angle*.
    basePoint (I) Basepoint.
    vect (I) Axis of rotation.
  */
  OdGePoint3d& rotateBy(
    double angle, 
    const OdGeVector3d& vect, 
    const OdGePoint3d& basePoint = OdGePoint3d::kOrigin);

  /**
    Description:
    Mirrors this *point* about the specified *plane*.

    Arguments:
    line (I) Mirror *Line*.
  */
  OdGePoint3d& mirror(
    const OdGePlane& plane);

  /**
    Description:
    Scales this *point* by the scale factor about the basepoint.

    Arguments:
    scaleFactor (I) Scale Factor. The scale factor must be greater than zero.
    basePoint (I) Basepoint.
  */
  OdGePoint3d& scaleBy(
    double scaleFactor, 
    const OdGePoint3d& basePoint = OdGePoint3d::kOrigin);

  /**
    Description:
    Projects this *point* onto the specified plane.
    
    Arguments:
    plane (I) Any *plane*.
    
    Remarks,
    If no plane is specified, this *point* is projected into the XY *plane*.
  */
  OdGePoint2d convert2d (
    const OdGePlanarEnt& plane) const;
   
  OdGePoint2d convert2d() const
  {
    return OdGePoint2d(x, y);
  }

  OdGePoint3d operator *(
    double scale) const
  {
     return OdGePoint3d (x * scale, y * scale, z * scale);
  }
  
  OdGePoint3d& operator *=(
    double scale)
  {
    x *= scale;
    y *= scale;
    z *= scale;
    return *this;
  }
      
  OdGePoint3d operator /(
    double scale) const
  {
    return OdGePoint3d (x / scale, y / scale, z / scale);
  }
    
  OdGePoint3d& operator /=(
    double scale)
  {
    x /= scale;
    y /= scale;
    z /= scale;
    return *this;
  }
  
  OdGePoint3d operator +(
    const OdGeVector3d& vect) const
  {
    return OdGePoint3d (x + vect.x, y + vect.y, z + vect.z);
  }
    
  OdGePoint3d& operator +=(
    const OdGeVector3d& vect)
  {
    x += vect.x;
    y += vect.y;
    z += vect.z;
    return *this;
  }
      
  OdGePoint3d operator -(
    const OdGeVector3d& vect) const
  {
    return OdGePoint3d (x - vect.x, y - vect.y, z - vect.z);
  }
      
  OdGePoint3d& operator -=(
    const OdGeVector3d& vect)
  {
    x -= vect.x;
    y -= vect.y;
    z -= vect.z;
    return *this;
  }
      
  /**
    Description:
    Sets this *point* to point + vect, and returns a reference to this *point*.
    
    Arguments:
    point (I) Any 3D *point*.
    vect (I) Any 3D vector.
  */  
  OdGePoint3d& setToSum(
    const OdGePoint3d& point, 
    const OdGeVector3d& vect);

  OdGeVector3d operator -(
    const OdGePoint3d& point) const
  {
    return OdGeVector3d (x - point.x, y - point.y, z - point.z);
  }
    
  /**
    Description:
    Returns this *point* as a vector.
  */
  OdGeVector3d asVector() const
  {
    return OdGeVector3d(x, y, z);
  }
 
  /**
    Description:
    Returns the distance from this *point* to the specified *point*.

    Arguments:
    point (I) Any 3D *point*.
  */
  double distanceTo(
    const OdGePoint3d& point) const;

  /**
    Description:
    Projects this *point* onto the specified *plane* along the specified vector.

    Arguments:
    plane (I) Plane on which this *point* is to be projected
    vect (I) Vector defining the projection direction.
  */
  OdGePoint3d project(
    const OdGePlane& plane, 
    const OdGeVector3d& vect) const;
    
  /**
    Description:
    Projects this *point* onto the specified *plane* along the normal to the *plane*.

    Arguments:
    plane (I) Plane on which this *point* is to be projected
  */  
  OdGePoint3d orthoProject(
    const OdGePlane& plane) const;

  bool operator == (
    const OdGePoint3d& point) const
  {
    return isEqualTo (point);
  }
    
  bool operator != (
    const OdGePoint3d& point) const
  {
    return !isEqualTo (point);
  }
    
  /**
    Description:
    Returns true if and only if the distance from this *point* to point is within the 
    specified tolerance.

    Arguments:
    point (I) Any 3D *point*.
    tol (I) Geometric tolerance.
  */
  bool isEqualTo (
    const OdGePoint3d& point,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Arguments:
    i (I) Index of coordinate.
    
    Remarks:
    Returns or references the ith coordinate of this *point*.

    o 0 returns or references the X-coordinate.
    o 1 returns or references the Y-coordinate.
    o 2 returns or references the Z-coordinate.
  */
  double operator [](
    unsigned int i) const
  {
    return * (&x+i);
  }
      
  double& operator [](
    unsigned int i)
  {
    return * (&x+i);
  }
  
  /**
    Description:
    Sets the parameters for this *point* according to the arguments
    
    Arguments:
    xx (I) The X-coordinate of this *point*.
    yy (I) The Y-coordinate of this *point*.
    zz (I) The Z-coordinate of this *point*.
    plane (I) Any *plane*.
    point (I) Any 2D *point*.
    
    Remarks:
    Returns *a* reference to this *point*.

    plane and pnt2d define a point as follows:
            
            p + uAxis * point.x + vAxis * point.y,
            
    where p, uAxis, and vAxis are returned by the function call plane.get (p, uAxis, vAxis);
  */
  OdGePoint3d& set(
    double xx, 
    double yy, 
    double zz)
  {
    x = xx;
    y = yy;
    z = zz;
    return *this;
  }
      
  OdGePoint3d& set(
    const OdGePlanarEnt& plane, 
    const OdGePoint2d& point);

  double x; // X-coordinate
  double y; // Y-coordinate
  double z; // Z-coordinate
};

#include "../TD_PackPop.h"

#endif

