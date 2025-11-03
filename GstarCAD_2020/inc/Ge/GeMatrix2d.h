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




#ifndef OD_GE_MATRIX_2D_H
#define OD_GE_MATRIX_2D_H /* {Secret} */

#include "../Ge/GeGbl.h"
#include "../Ge/GePoint2d.h"

class OdGeVector2d;
class OdGeLine2d;
class OdGeTol;

#include "../TD_PackPush.h"

/**
    Description:
    This class represents 2D transformation matrices that define affine 
    ( *translation*, *rotation*, and/or *scaling* ) transformations.

    Remarks:
    OdGeMatrix2d may be viewed as an array[3][3] of doubles.
    
    An OdGeMatrix2d, M, can be expressed as a 3 * 3 *matrix*, in the form
    
              a00   a01   t0
              a10   a11   t1
                0     0    1
                
    The linear part of M is the *matrix*
                
              a00   a01
              a10   a11
                
    The translational part of M is the column
    
              t0
              t1
              
    The origin of the coordinate system of M is (t0, t1).
    

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeMatrix2d
{
public:
  OdGeMatrix2d();
  OdGeMatrix2d(const OdGeMatrix2d& src);
  OdGeMatrix2d& operator =(const OdGeMatrix2d& src);

  /** Description:
      The identity matrix.
  */
  GE_STATIC_EXPORT static const OdGeMatrix2d kIdentity;

  /**
    Description:
    Sets this *matrix* to the identity *matrix*, and returns a reference to this *matrix*.
  */
  OdGeMatrix2d& setToIdentity();

  /**
    Remarks:
    Returns the product (this *matrix*) * matrix. 
  */
  OdGeMatrix2d operator* (
    const OdGeMatrix2d& matrix) const;
    
  /**
    Remarks:
    Sets this *matrix* to the product (this *matrix*) * matrix, and returns
    a reference to this *matrix*. 
  */
  OdGeMatrix2d& operator*= (
    const OdGeMatrix2d& matrix);

  /**
    Description:
    Sets this *matrix* to the product leftSide * (this *matrix*), and returns
    a reference to this *matrix*.
    
    Arguments:
    leftSide (I) Any 2D *matrix* 
  */
  OdGeMatrix2d& preMultBy(
    const OdGeMatrix2d& leftSide);

  /**
    Description:
    Sets this *matrix* to the product (this *matrix*) * rightSide, and returns
    a reference to this *matrix*. 
    
    Arguments:
    rightSide (I) Any 2D *matrix* 
  */
  OdGeMatrix2d& postMultBy(
    const OdGeMatrix2d& rightSide);

  /**
    Description:
    Sets this *matrix* to the product matrix1 * matrix2, and returns
    a reference to this *matrix*.
     
    Arguments:
    matrix1 (I) Any 2D *matrix* 
    matrix2 (I) Any 2D *matrix* 
  */
  OdGeMatrix2d& setToProduct(
    const OdGeMatrix2d& matrix1, 
    const OdGeMatrix2d& matrix2);

  // Multiplicative inverse.
  //

  /**
    Description:
    Sets this *matrix* to its *inverse*, and returns
    a reference to this *matrix*. 
  */
  OdGeMatrix2d& invert();

  /**
    Description:
    Returns the *inverse* of this *matrix*. 
  */
  OdGeMatrix2d inverse() const;

  /**
    Description:
    Returns true if and only if this *matrix* is singular.
    
    Remarks:
    o A *matrix* is singular if and only if its determinant == 0.
    o A singular *matrix* cannot be inverted.
  */
  OdBool isSingular (const OdGeTol& tol = OdGeContext::gTol) const;
 
  /**
    Description:
    Sets this *matrix* to its *transpose*, and returns
    a reference to this *matrix*. 
  */
  OdGeMatrix2d& transposeIt();

  /**
    Description:
    Returns the *transpose* of this *matrix*. 
  */
  OdGeMatrix2d transpose() const;

  /**
    Description:
    Equality operator. 
  */
  bool operator ==(
    const OdGeMatrix2d& matrix) const;

  /**
    Description:
    Inequality operator. 
  */
  bool operator !=(
    const OdGeMatrix2d& matrix) const;

  /**
    Description:
    Returns true if and only if matrix is identical to this one,
    within the specified tolerance.

    Arguments:
    matrix (I) Matrix to be compared.
    tol (I) Geomentric tolerance.
  */
  bool isEqualTo(
    const OdGeMatrix2d& matrix,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only the columns vectors of the linear part of
    this *matrix* are of equal length and perpendicular
    to each other  within the
    specified tolerance. 

    Arguments:
    tol (I) Geomentric tolerance.
  */
  OdBool isUniScaledOrtho(
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only the column vectors of the linear part of
    this *matrix* are perpendicular
    to each other within the specified tolerance.

    Arguments:
    tol (I) Geomentric tolerance.
  */
  OdBool isScaledOrtho(
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the scale factor of this *matrix*.
    
    Remarks:
    The scale factor is the square root of the longest column vector
    of the linear part of this *matrix*.
  */
  double scale() const;

  // Determinant
  //
  
  /**
    Description:
    Returns the determinant of this *matrix*.
  */
  double det() const;

  /**
    Description:
    Sets the *translation* part of the *matrix* to the specified vector.
    
    Arguments:
    vect (I) Translation vector.
  */
  OdGeMatrix2d& setTranslation(
    const OdGeVector2d& vect);

  /**
    Returns the *translation* vector of this *matrix*,
    or the *matrix* of the translation by vector.
    
    Arguments:
    vect (I) Translation vector.
  */
  OdGeVector2d translation() const;
  static OdGeMatrix2d translation(
    const OdGeVector2d& vector);

  // Retrieve scaling, rotation, mirror components
  //
  
  /**
    Description:
    Returns true if an only if this *matrix* is conformal (isUniScaledOrtho()),
    and returns the *scale* factor, *angle* of *rotation*,
    the presence of a *mirror* component to the *matrix*,
    and the *direction* of reflection.
          
    Arguments:
    scale (O) Receives the scale factor.
    angle (O) Receives the angle of *rotation*.
    isMirror (O) Receives true if andn only if the *matrix* has a mirror component.
    reflex (I) Direction of reflection.
    
    Remarks:
    reflex is valid if and only if isMirror is true.
  */
  OdBool isConformal(
    double& scale, 
    double& angle,
    OdBool& isMirror, 
    OdGeVector2d& reflex) const;


  // Set/get coordinate system
  //
  
  /**
    Description:
    Sets this *matrix* to the *matrix* which maps
    the WCS to the coordinate system 
    defined by origin, X-axis, and Y-axis, and returns a reference
    to this *matrix*.
    
    Arguments:
    origin (I) Origin of the coordinate system.
    xAxis (I) X-axis of the coordinate system.
    yAxis (I) Y-axis of the coordinate system.
  */
  OdGeMatrix2d& setCoordSystem(
    const OdGePoint2d& origin, 
    const OdGeVector2d& xAxis,
    const OdGeVector2d& yAxis);
  /**
    Description:
    Returns the *origin*, X-axis, and Y-axis of the coordinate system 
    to which this *matrix* maps the WCS.
    
    Arguments:
    origin (O) Receives the origin of the coordinate system.
    xAxis (O) Receives the X-axis of the coordinate system.
    yAxis (O) Receives the Y-axis of the coordinate system.
  */
  void getCoordSystem(
    OdGePoint2d& origin, 
    OdGeVector2d& xAxis, 
    OdGeVector2d& yAxis) const;
 
  /**
    Description:
    Sets this *matrix* to the *matrix* which translates
    by vect, and returns a reference
    to this *matrix*.
    
    Arguments:
    vect (I) Translation vector.
  */
  OdGeMatrix2d& setToTranslation(
    const OdGeVector2d& vect);
    
    
  /**
    Description:
    Sets this *matrix* to the *matrix* which rotates
    by angle about center, and returns a reference
    to this *matrix*.
    
    Arguments:
    angle (I) Rotation *angle*.
    center (I) Center of *rotation*.
  */
  OdGeMatrix2d& setToRotation(
    double angle, 
    const OdGePoint2d& center = OdGePoint2d::kOrigin);
    
  /**
    Description:
    Sets this *matrix* to the *matrix* which scales
    by scale about tcenter, and returns a reference
    to this *matrix*.
    
    Arguments:
    scale (I) Scale factor.
    center (I) Center of *scaling*.
  */
  OdGeMatrix2d& setToScaling(
    double scale,
    const OdGePoint2d& center = OdGePoint2d::kOrigin);

  /**
    Description:
    Sets this *matrix* to the *matrix* which mirrors
    about the specified object, and returns a reference
    to this *matrix*.
    
    Arguments:
    mirrorPoint (I) Mirror *point*.
    mirrorLine (I) Mirror line entity.
  */
  OdGeMatrix2d& setToMirroring(
    const OdGePoint2d& mirrorPoint);
  OdGeMatrix2d& setToMirroring(
    const OdGeLine2d& mirrorLine);
    
  /**
    Description:
    Sets this *matrix* to the *matrix* which maps
    the coordinate system defined by fromOrigin, fromXAxis, and fromYAxis,
    to the coordinate system 
    defined by toOrigin, toXAxis, and toYAxis, and returns a reference
    to this *matrix*.
    
    Arguments:
    fromOrigin (I) Origin of the initial coordinate system.
    fromXAxis (I) X-axis of the initial coordinate system.
    fromYAxis (I) Y-axis of the initial coordinate system.
    toOrigin (I) Origin of the initial coordinate system.
    toXAxis (I) X-axis of the initial coordinate system.
    toYAxis (I) Y-axis of the initial coordinate system.
  */
  OdGeMatrix2d& setToAlignCoordSys(
    const OdGePoint2d& fromOrigin,
    const OdGeVector2d& fromXAxis,
    const OdGeVector2d& fromYAxis,
    const OdGePoint2d& toOrigin,
    const OdGeVector2d& toXAxis,
    const OdGeVector2d& toYAxis);
 
//  static OdGeMatrix2d translation (
//     const OdGeVector2d& vect);
    
  /**
    Description:
    Returns the *matrix* which rotates
    by angle about center.
    
    Arguments:
    angle (I) Rotation *angle*.
    center (I) Center of *rotation*.
  */
  static OdGeMatrix2d rotation(
    double angle, 
    const OdGePoint2d& center = OdGePoint2d::kOrigin);
    
  /**
    Description:
    Returns the *matrix* which scales
    by scale about center.
    
    Arguments:
    scale (I) Scale factor.
    center (I) Center of *scaling*.
  */
  static OdGeMatrix2d scaling(
    double scale, 
    const OdGePoint2d& center = OdGePoint2d::kOrigin);

  /**
    Description:
    Returns the *matrix* which mirrors
    about the specified object.
   
    Arguments:
    mirrorPoint (I) Mirror *point*.
    mirrorLine (I) Mirror line entity.
  */
  static OdGeMatrix2d mirroring(
    const OdGePoint2d& mirrorPoint);
  static OdGeMatrix2d mirroring(
    const OdGeLine2d& mirrorLine);

  /**
    Description:
    Returns the *matrix* which maps
    the  coordinate system defined by fromOrigin, fromXAxis, and fromYAxis,
    to the coordinate system 
    defined by toOrigin, toXAxis, and toYAxis.
    
    Arguments:
    fromOrigin (I) Origin of the initial coordinate system.
    fromXAxis (I) X-axis of the initial coordinate system.
    fromYAxis (I) Y-axis of the initial coordinate system.
    toOrigin (I) Origin of the initial coordinate system.
    toXAxis (I) X-axis of the initial coordinate system.
    toYAxis (I) Y-axis of the initial coordinate system.
  */
  static OdGeMatrix2d alignCoordSys(
    const OdGePoint2d& fromOrigin,
    const OdGeVector2d& fromXAxis,
    const OdGeVector2d& fromYAxis,
    const OdGePoint2d& toOrigin,
    const OdGeVector2d& toXAxis,
    const OdGeVector2d& toYAxis);

  // For convenient access to the data.
  //
  
  /**
    Remarks:
    Returns or references entry[row] as matrix[row].

    Arguments:
    row (I) Row.
  */
  const double* operator [](
    int row) const;
  double* operator [](
    int row);

  /**
    Remarks:
    Returns or references entry[row][column] as matrix(row,column).

    Arguments:
    row (I) Row.
    column (I) Column.
  */
  double operator ()(
    int row, 
    int column) const;
  double& operator ()(
    int row, 
    int column);

  // [row][column]
  double entry[3][3];
};

// these operations really decrease rendering performance in non-inline case :

inline const double* OdGeMatrix2d::operator [](int row) const 
{ 
  return entry[row]; 
}

inline double* OdGeMatrix2d::operator [](int row) 
{ 
  return entry[row]; 
}

inline double OdGeMatrix2d::operator ()(int row, int column) const 
{ 
  return entry[row][column]; 
}

inline double& OdGeMatrix2d::operator ()(int row, int column) 
{ 
  return entry[row][column]; 
}

#include "../TD_PackPop.h"

#endif // OD_GE_MATRIX_2D_H
