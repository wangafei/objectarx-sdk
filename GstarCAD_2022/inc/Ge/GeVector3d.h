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




#ifndef OD_GEVEC3D_H
#define OD_GEVEC3D_H /* {Secret} */

#include "../Ge/GeGbl.h"
#include "../Ge/GeGblAbb.h"
#include "../Ge/GeVector2d.h" // for convert2d

class OdGeMatrix3d;
class OdGePlane;
class OdGePlanarEnt;
class OdGePoint3d;

#include "../TD_PackPush.h"

/**
    Description:
    This class represents vectors in 3D space. 

    Remarks:
    OdGeVector3d may be viewed as an array[3] of doubles.
    
    Library: TD_Ge

   {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeVector3d
{
public:
  /**
    Arguments:
    source (I) Object to be cloned.
    xx (I) X-coordinate.
    yy (I) Y-coordinate.
    zz (I) Z-coordinate.
    vect (I) Any 2D vector.
    plane (I) Any *plane*.
    
    Remarks:
    When called with no arguments, constructs a zero-length vector.

    When called with plane and vect, constructs 
    the 3D vector correspoponding to the 2D vector
    in the coordinates of the plane:
    
            uAxis * vect.x + vAxis * vect.y
    
    where uAxis and vAxis are returned by
    
            plane.get(origin, uAxis, vAxis)
            
    The 3D vector will be parallel to the 2D vector.
  */
  OdGeVector3d () : x(0.0), y(0.0), z(0.0) {}
  OdGeVector3d (
    const OdGeVector3d& source) : x(source.x), y(source.y), z(source.z) {}
  OdGeVector3d (
    double xx, 
    double yy, 
    double zz) : x(xx), y(yy), z(zz) {}
  OdGeVector3d(
    const OdGePlanarEnt& plane, 
    const OdGeVector2d& vector2d);

  OdGeVector3d& operator  = (
    const OdGeVector3d& vect)
  {
    x = vect.x;
    y = vect.y;
    z = vect.z;
    return *this;
  }    

  GE_STATIC_EXPORT static const OdGeVector3d kIdentity; // Additive identity vector.
  GE_STATIC_EXPORT static const OdGeVector3d kXAxis; // X-Axis vector.
  GE_STATIC_EXPORT static const OdGeVector3d kYAxis; // Y-Axis vector.
  GE_STATIC_EXPORT static const OdGeVector3d kZAxis; // Z-Axis vector.

  /**
    Description:
    Sets this vector to the product matrix * vector or  scale * vector, and returns
    a reference to this vector. 
    
    Arguments:
    matrix (I) Any 3D *matrix* 
    vect (I) Any 3D vector.
    scale (I) Scale factor.
  */
  OdGeVector3d& setToProduct (
    const OdGeMatrix3d& matrix, 
    const OdGeVector3d& vect);
  OdGeVector3d& setToProduct(
    const OdGeVector3d& vect, 
    double scale)
  {
    x = scale * vect.x;
    y = scale * vect.y;
    z = scale * vect.z;
    return *this;
  }
      

  /**
    Description:
    Applies the 3D transformation matrix to this vector.

    Arguments:
    xfm (I) 3D transformation matrix.
  */
  OdGeVector3d& transformBy (
    const OdGeMatrix3d& xfm);
    
  /**
    Description:
    Rotates this vector the specified *angle*
    about the specified *axis*,
    and returns a reference to this vector.

    Arguments:
    angle (I) Rotation *angle*.
    axis (I) Axis of rotation.
  */
  OdGeVector3d& rotateBy (
    double angle, 
    const OdGeVector3d& axis);
    
  /**
    Description:
    Mirrors the entity about the *plane* passing through the
    origin with the specified normal, and returns
    a reference to the entity.

    Arguments:
    normalToPlane (I) Normal to Plane.
  */
  OdGeVector3d& mirror (
    const OdGeVector3d& normalToPlane);

  /**
    Description:
    Returns the 2D vector, in the coordinate system
    of the *plane*, corresponding to the 3D vector.
    
    Remarks:
    The 3D vector must be parallel to the *plane*.
    
    If no *plane* is specified, the XY *plane* is used.
  */
  OdGeVector2d convert2d (
    const OdGePlanarEnt& plane) const;
  OdGeVector2d convert2d () const { return OdGeVector2d(x, y); } 
  
  OdGeVector3d operator * (
    double scale) const
  { return OdGeVector3d (x * scale, y * scale, z * scale); }
  
  OdGeVector3d& operator *= (
    double scale)
  {
    x *= scale;
    y *= scale;
    z *= scale;
    return *this;
  }
    
  OdGeVector3d operator / (
      double scale) const
  {
    return OdGeVector3d (x/scale, y/scale, z/scale);
  }

  OdGeVector3d& operator /= (
      double scale)
  {
    x /= scale;
    y /= scale;
    z /= scale;
    return *this;
  }

  OdGeVector3d operator + (
    const OdGeVector3d& vect) const
  { return OdGeVector3d (x + vect.x, y + vect.y, z + vect.z);}    
  OdGeVector3d operator += (
    const OdGeVector3d& vect)
  { return OdGeVector3d (x += vect.x, y += vect.y, z += vect.z);}    

  OdGeVector3d operator - (
    const OdGeVector3d& vect) const
  { return OdGeVector3d (x - vect.x, y - vect.y, z - vect.z);}    
  OdGeVector3d operator -= (
    const OdGeVector3d& vect)
  { return OdGeVector3d (x -= vect.x, y -= vect.y, z -= vect.z);}    

  /** \details
  Returns this vector as a point.
  */
  const OdGePoint3d& asPoint() const;

  /** \details
  Returns this vector as a point.
  */
  OdGePoint3d& asPoint();

  /** \details
    Sets this vector to vector1 + vector1, and returns a reference to this vector.
    
    \param vector1 [in]  Any 3D vector.
    \param vector2 [in]  Any 3D vector.
  */
  OdGeVector3d& setToSum (
    const OdGeVector3d& vector1, 
    const OdGeVector3d& vector2)
  {
    x = vector1.x + vector2.x;
    y = vector1.y + vector2.y;
    z = vector1.z + vector2.z;
    return *this;
  }    

  OdGeVector3d operator - () const { return OdGeVector3d (-x, -y, -z); }
  
  /**
    Description:
    Negates this vector (-x, -y, -z), and returns a reference to this vector.
  */
  OdGeVector3d& negate ()
  {
    x = -x;
    y = -y;
    z = -z;
    return *this;
  }
  

  /**
    Description:
    Returns a vector perpendicular to this one.
    
    Remarks:
    The orthogonal vector is determined by function AcGeContext::gOrthoVector()
  */
  OdGeVector3d perpVector () const;


  /**
    Description:
    Returns the *angle* to the specified vector.
    
    Arguments:
    vect (I) Any 3D vector.

    Remarks:
    If refVector is not specified:

      o Returns a value in the range [0.0 .. OdaPI].

      o This function is commutative.
   
    If refVector is specified:

      o Returns a value in the range [0.0 .. Oda2PI].
      o If (refVector.dotProduct(crossProduct(vect)) >= 0.0, the return value is angleTo(vect).
      o If (refVector.dotProduct(crossProduct(vect)) < 0.0, the return value is Oda2PI - angleTo(vect)
  */
  double angleTo (
    const OdGeVector3d& vect) const;
  double angleTo (
    const OdGeVector3d& vect,
    const OdGeVector3d& refVector) const;

  /**
    Description:
    Returns the angle of this vector projected onto
    the specified *plane*
    
    Arguments:
    plane (I) Any 3D *plane*.
    
    Remarks:
    This vector is projected orthogonally onto the 
    *plane* through its origin, and is measured with
    respect to axis1 as returned by
    
            plane.getCoordSystem(origin, axis1, axis2)
  */
  double angleOnPlane(
    const OdGePlanarEnt& plane) const;

  /**
    Description:
    Returns the unit vector codirectional with this vector.
    
    Arguments:
    tol (I) Geometric tolerance.
        
    Remarks:
    If the *length*() < tol, this vector is returned.
  */
  OdGeVector3d normal (
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Sets this vector to the unit vector codirectional with this vector,
    and returns a reference to this vector
    
    Arguments:
    tol (I) Geometric tolerance.
    status (O) Receives the *status* of normalization.

    Remarks:
    If this.length() < tol, this vector is unchanged, and kThis is returned in status.

    Possible values for status are as follows:

    @untitled table
    kOk       
    k0This    
  */
  OdGeVector3d& normalize (
    const OdGeTol& tol = OdGeContext::gTol);
  OdGeVector3d& normalize (
    const OdGeTol& tol, 
    OdGe::ErrorCondition& status);

  /**
    Description:
    Sets this vector to the unit vector codirectional with this vector,
    and returns the *length* prior to normalization.
    
    Remarks:
    If this.length() <= 0.0, this vector is unchanged.
  */
  double normalizeGetLength();


  /**
    Description:
    Returns the *length* of this vector.
  */      
  double length () const;

  /**
    Description:
    Returns the square of the *length* of this vector.
  */      
  double lengthSqrd () const { return x*x + y*y + z*z; }


  /**
    Description:
    Returns true if and only if the *length* of this vector is 1.0 within the specified tolerance.

    Arguments:
    tol (I) Geometric tolerance.
  */      
  OdBool isUnitLength (
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only if the *length* of this vector is 0.0 within the specified tolerance.

    Arguments:
    tol (I) Geometric tolerance.
  */      
  OdBool isZeroLength (
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only if the specified vector is parallel to this vector within the specified tolerance.

    Arguments:
    vect (I) Any 3D vector.
    tol (I) Geometric tolerance.
    status (O) Receives the *status* of test.

    Remarks:
    If the *length* of either vector is < tol, kThis is returned in status.

    Possible values for status are as follows:

    @untitled table
    kOk       
    k0This    
    k0Arg1    
  */      
  OdBool isParallelTo (
    const OdGeVector3d& vect,
    const OdGeTol& tol = OdGeContext::gTol) const;
  OdBool isParallelTo(
    const OdGeVector3d& vect,
    const OdGeTol& tol, 
    OdGeError& status) const;

  /**
    Description:
    Returns true if and only if the specified vector is codirectional to this vector within the specified tolerance.

    Arguments:
    vect (I) Any 3D vector.
    tol (I) Geometric tolerance.
    status (O) Receives the *status* of test.

    Remarks:
    If the *length* of either vector is < tol, kThis is returned in status.

    Possible values for status are as follows:

    @untitled table
    kOk       
    k0This    
    k0Arg1    
  */      
  OdBool isCodirectionalTo (
    const OdGeVector3d& vect,
    const OdGeTol& tol = OdGeContext::gTol) const;
  OdBool isCodirectionalTo (
    const OdGeVector3d& vect,
    const OdGeTol& tol,
    OdGeError& status) const;
    

  /**
    Description:
    Returns true if and only if the specified vector is perpendicular to this vector within the specified tolerance.

    Arguments:
    vect (I) Any 3D vector.
    tol (I) Geometric tolerance.
    status (O) Receives the *status* of test.

    Remarks:
    If the *length* of either vector is < tol, kThis is returned in status.

    Possible values for status are as follows:

    @untitled table
    kOk       
    k0This    
    k0Arg1    
  */      
  OdBool isPerpendicularTo (
    const OdGeVector3d& vect,
    const OdGeTol& tol = OdGeContext::gTol) const;
  OdBool isPerpendicularTo(
    const OdGeVector3d& vect,
    const OdGeTol& tol, 
    OdGeError& status) const;
    
  /**
    Description:
    Returns the dot product of this vector and the specified vector.
    
    Arguments:
    vect (I) Any 3D vector.
  */
  double dotProduct (
    const OdGeVector3d& vect) const
  { return x * vect.x + y * vect.y + z * vect.z; }    
    
    
  /**
    Description:
    Returns the cross product of this vector and the specified vector.
    
    Arguments:
    vect (I) Any 3D vector.
  */
  OdGeVector3d crossProduct (
    const OdGeVector3d& vect) const;
    
  OdGeMatrix3d rotateTo (const OdGeVector3d& vector,
    const OdGeVector3d& axis = OdGeVector3d::kIdentity) const;

  OdGeVector3d project (
    const OdGeVector3d& planeNormal,
    const OdGeVector3d& projectDirection) const;
  OdGeVector3d project (
    const OdGeVector3d& planeNormal,
    const OdGeVector3d& projectDirection, 
    const OdGeTol& tol, OdGeError& flag) const;
  
  OdGeVector3d orthoProject (const OdGeVector3d& planeNormal) const;
  OdGeVector3d orthoProject (const OdGeVector3d& planeNormal, 
   const OdGeTol& tol, OdGeError& flag) const;

  bool operator == (
    const OdGeVector3d& vect) const;
  bool operator != (
    const OdGeVector3d& vect) const;
    
  /**
    Description:
    Returns true if and only if vect is identical to this vector,
    within the specified tolerance.

    Arguments:
    vect (I) Any 3D vector.
    tol (I) Geometric tolerance.
  */
  bool isEqualTo (
    const OdGeVector3d& vect,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Arguments:
    i (I) Index of coordinate.

    Remarks:
    Returns or references the ith coordinate of this vector.

    o 0 returns or references the X-coordinate.
    o 1 returns or references the Y-coordinate.
    o 2 returns or references the Z-coordinate.
  */
  double operator [] (
    unsigned int i) const {return * (&x + i); }
  double& operator [] (
    unsigned int i) {return * (&x + i); }
  /**
    Description:
    Returns the index of the largest absolute coordinate of this vector.
  */  
  unsigned int largestElement() const;
  
  /**
    Description:
    Sets this vector to the specified arguments, 
    and returns a reference to this vector.

    Arguments:
    source (I) Object to be cloned.
    xx (I) X-coordinate.
    yy (I) Y-coordinate.
    zz (I) Z-coordinate.
    vect (I) Any 2D vector.
    plane (I) Any *plane*.
    
    Remarks:
    When called with *plane* and vector, constructs 
    the 3D vector correspoponding to the 2D vector
    in the coordinates of the plane:
    
            uAxis * vect.x + vAxis * vect.y
    
    where uAxis and vAxis are returned by
    
            plane.get(origin, uAxis, vAxis)
            
    The 3D vector will be parallel to the 2D vector.
  */
  OdGeVector3d& set (
    double xx, 
    double yy, 
    double zz)
  {
    x = xx;
    y = yy;
    z = zz;
    return *this;
  }    
  OdGeVector3d& set (
    const OdGePlanarEnt& plane, 
    const OdGeVector2d& vect);

  /**
    Remarks:
    Returns the equivalent 3D tranformation matrix.
  */
  operator OdGeMatrix3d () const;
  	double Determinant(OdGeVector3d &u ,OdGeVector3d&v ,const OdGeVector3d &nor)
	{
		return u.x * v.y * nor.z + 
		   u.y * v.z * nor.x + 
		   u.z * v.x * nor.y - 
		   u.z * v.y * nor.x - 
		   u.y * v.x * nor.z - 
		   u.x * v.z * nor.y;
	}
  
/*
  static OdGeVector3d givePerp (
    const OdGeVector2d& vector1, 
    const OdGeVector2d& vector2);
*/

  double x; //  X-coordinate.
  double y; //  Y-coordinate.
  double z; //  Z-coordinate.
};


/*
    Description:
    Returns the product matrix * vect or scale * vect  
    
    Arguments:
    matrix (I) Any 3D *matrix*.
    vect (I) Any 3D vector.
    scale (I) Scale factor.
*/

GE_TOOLKIT_EXPORT OdGeVector3d operator * (
    const OdGeMatrix3d& matrix, 
    const OdGeVector3d& vect);
GE_TOOLKIT_EXPORT OdGeVector3d operator * (
    double scale, 
    const OdGeVector3d& vect);

#include "../TD_PackPop.h"


#include "GePoint3d.h"

inline const OdGePoint3d& OdGeVector3d::asPoint() const
{
  return *reinterpret_cast<const OdGePoint3d*>(this);
}

inline OdGePoint3d& OdGeVector3d::asPoint()
{
  return *reinterpret_cast<OdGePoint3d*>(this);
}

#endif

