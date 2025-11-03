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




#ifndef OD_GESCL2D_H
#define OD_GESCL2D_H /* {Secret} */

#include "../Ge/GeGbl.h"

class OdGeMatrix2d;
class OdGeScale3d;

#include "../TD_PackPush.h"

/**
    Description:
    This class represents scaling transformations (scale vectors) in 2D space.

    Remarks:
    OdGeScale2d may be viewed as an array[2] of doubles.

    Library: TD_Ge

    {group:OdGe_Classes}
*/
class GE_TOOLKIT_EXPORT OdGeScale2d
{
public:
  /**
    Arguments:
    factor (I) Uniform scale *factor*.
    xFactor (I) The X scale *factor*.
    yFactor (I) The Y scale *factor*.
    source (I) Object to be cloned.
  */
  OdGeScale2d();
  OdGeScale2d(
    const OdGeScale2d& source);
  OdGeScale2d(
    double factor);
  OdGeScale2d(
    double xFactor,
    double yFactor);

  GE_STATIC_EXPORT static const   OdGeScale2d kIdentity; // Multplicitive identity vector.

  /**
    Arguments:
    scaleVec (I) Any 2D scale vector.
    factor (I) Uniform scale *factor*.
  */
  OdGeScale2d operator * (
    const OdGeScale2d& scaleVec) const;

  friend OdGeScale2d operator * (
    double factor,
    const OdGeScale2d& scaleVec);

  /**
    Arguments:
    scaleVec (I) Any 2D scale vector.
    factor (I) Uniform scale *factor*.

    Remarks:
    Multiplication of scale vectors is defined as follows:

              scl * [xs ys]          = [scl*xs scl*ys]
              [xs1 ys1] * [xs2 ys2]  = [xs1*xs2 ys1*ys2]
  */
  OdGeScale2d& operator *= (
    const OdGeScale2d& scaleVec);

  /**
    Description:
    Sets this scale vector to the product leftSide * (this scale vector), and returns
    a reference to this scale vector.

    Arguments:
    leftSide (I) Any 2D scale vector.

    Remarks:
    Scale muliplications is commutative.
  */
  OdGeScale2d& preMultBy (
    const OdGeScale2d& leftSide);

  /**
    Description:
    Sets this scale vector to the product (this scale vector) * (rightSide), and returns
    a reference to this scale vector.

    Arguments:
    rightSide (I) Any 2D scale vector.

    Remarks:
    Scale muliplications is commutative.
  */
  OdGeScale2d& postMultBy (
    const OdGeScale2d& rightSide);


  /**
    Description:
    Sets this scale vector to the product scaleVec1 * scaleVec2 or factor * scaleVec, and returns
    a reference to this scale vector.

    Arguments:
    factor (I) Uniform scale *factor*.
    scaleVec (I) Any 2D scale vector.
    scaleVec1 (I) Any 2D scale vector.
    scaleVec2 (I) Any 2D scale vector.

    Remarks:
    Multiplication of scale vectors is defined as follows:

              scl * [xs1 ys1]        = [scl*xs1 scl*ys1]
              [xs1 ys1 ] * [xs2 ys2] = [xs1*xs2 ys1*ys2]
  */
  OdGeScale2d& setToProduct(
    const OdGeScale2d& scaleVec, double factor);

  OdGeScale2d& setToProduct(
    const OdGeScale2d& scaleVec1,
    const OdGeScale2d& scaleVec2);

  /**
    Arguments:
    factor (I) Uniform scale *factor*.
    Remarks:
    Multiplication of scale vectors is defined as follows:

              scl * [xs1 ys1]        = [scl*xs1 scl*ys1]
              [xs1 ys1 ] * [xs2 ys2] = [xs1*xs2 ys1*ys2]
  */
  OdGeScale2d operator * (
    double factor) const;


  /**
    Arguments:
    factor (I) Uniform scale *factor*.
  */
  OdGeScale2d& operator *= (
    double factor);



  /**
    Description:
    Returns the *inverse* of this scale vector.
  */
  OdGeScale2d inverse () const;

  /**
    Description:
    Sets this scale vector to its *inverse*, and returns
    a reference to this scale vector.
  */
  OdGeScale2d& invert ();

  /**
    Description:
    Returns true if and only if the scaling matrix corresponding to this scale vector isUniScaledOrtho().

    Arguments:
    tol (I) Geometric tolerance.
  */
  OdBool isProportional(
    const OdGeTol& tol = OdGeContext::gTol) const;

  bool operator == (
    const OdGeScale2d& scaleVec) const;
  bool operator != (
    const OdGeScale2d& scaleVec) const;

  /**
    Description:
    Returns true if and only if scaleVec is identical to this one,
    within the specified tolerance.

    Arguments:
    scaleVec (I) Any 2D scale vector.
    tol (I) Geometric tolerance.
  */
  bool isEqualTo (
    const OdGeScale2d& scaleVec,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns or references the ith component of the scale vector.
    
    Arguments:
    i (I) Index of component.
    
    Remarks:
    o 0 returns or references the X scale factor.
    o 1 returns or references the Y scale factor.
  */
  double& operator [] (
    unsigned int i)
  {
    return * (&sx + i);
  }
  double operator [] (
    unsigned int i) const
  {
    return * (&sx + i);
  }

  /**
    Description:
    Sets this scale vector to the specified X and Y factors, 
    and returns a reference to this vector.

    Arguments:
    xFactor (I) The X scale *factor*.
    yFactor (I) The Y scale *factor*.
  */
  OdGeScale2d& set (
    double xFactor, 
    double yFactor);


  /**
    Description:
    Returns the transformation matrix equivalent to this scale vector.
    
    Arguments:
    xfm (O) Receives the 2D transformation matrix.
    
  */
  void getMatrix (
    OdGeMatrix2d& xfm) const;
    
  /**
    Description:
    Returns the scale vector corresponding to the
    lengths of the column vectors of the transformation matrix.  
    
    Arguments:
    xfm (O) Receives the 2D transformation matrix.
    
    Remarks:
    xfm must be scaled ortho; i.e., xfm.isScaledOrtho() == true.   
  */  
  OdGeScale2d& extractScale (
    const OdGeMatrix2d& xfm);
    
  /**
    Description:
    Returns the scale vector corresponding to the
    lengths of the column vectors of the transformation matrix,
    and sets the scale factor of the matrix to 1 .  
    
    Arguments:
    xfm (O) Receives the 2D transformation matrix.
    
    Remarks:
    xfm must be scaled ortho; i.e., xfm.isScaledOrtho() == true.   
  */  
  OdGeScale2d& removeScale (
    OdGeMatrix2d& xfm);

  /**
    Remarks:
    Returns the equivalent 2D tranformation matrix.
    or a 3D scale vector [sx sy 1].
  */
  operator OdGeMatrix2d () const;
  operator OdGeScale3d () const;

  double sx; // X scale *factor*.
  double sy; // Y scale *factor*.
};

#include "../TD_PackPop.h"

#endif // OD_GESCL2D_H

