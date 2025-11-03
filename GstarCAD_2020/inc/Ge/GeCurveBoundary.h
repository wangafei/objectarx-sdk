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


#ifndef OD_GE_CURVE_BOUNDARY_H
#define OD_GE_CURVE_BOUNDARY_H /* {Secret} */

#include "../Ge/GeEntity3d.h"

class OdGeCurve2d;
class OdGeEntity3d;
class OdGePosition3d;

#include "../TD_PackPush.h"
/**
    Description:
    This class represents the boundary geometry (face loops) on a bounded surface.

    Remarks:
    Each face loop consists of four arrays:
    
    o 3D curve or position pointers
    o 2D parameter space curve pointers
    o 3D orientations
    o 2D orientations
    
    There is a one-to-one correspondence between elements in the arrays, although certain 
    elements of a given array could be NULL, or meaningless.

    Loop degeneracies are represented as follows:
    
    o The entire loop degenerates to a single model space point, which is
      represented by the tuple (numElements = 1, position3d, curve2d).
      The curve2d may be NULL. The edge sense, and the curve2d sense are
      irrelevant. isDegenerate() method allows the determination of this
      condition on a loop.
    o A loop consisting of one or more model space degeneracies
      is represented as the general case with those edges that are
      degenerate represented by position3d. This implies that in the
      general case, model space geometry of a curve boundary may consist of
      curve3d and/or position3d pointers. Consequently, this geometry is
      obtained by the user as entity3d pointers. The degeneracy of a
      constituent edge can be detected by the type of the model space
      geometry.
   
    This class also supports the ownership of its geometry. Being the
    owner of its geometry would cause it to remove the geometry on
    destruction of an instance of the class.
       
    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeCurveBoundary
{
public:
  /**
    Arguments:
    numCurves (I) Number of curves in the curve boundary.
    crv3d (I) Array of 3D curves of each element in the curve boundary.
    crv2d (I) Array of 2D curves of each element in the curve boundary.
    orientation3d (I) Orientation for each 3D curve element. 
    orientation2d (I) Orientation for each 2D curve element.
    makeCopy (I)  If true, makes a copy of 3D and 2D curves. 
    source (I) Object to be cloned.

    Note:
    This function is not implemented and will generate a link error if you reference it.
    It will be implemented in a future release.
  */
  OdGeCurveBoundary();
  OdGeCurveBoundary(
    int numCurves, 
    const OdGeEntity3d *const * crv3d,
    const OdGeCurve2d *const * crv2d, 
    OdBool* orientation3d,
    OdBool* orientation2d, 
	OdBool makeCopy = kTrue);
  OdGeCurveBoundary(const OdGeCurveBoundary& source);

  ~OdGeCurveBoundary();

  OdGeCurveBoundary& operator =(
    const OdGeCurveBoundary& crvBoundary);

  // Query the data.
  //

  /**
    Description:
    Returns true if and only if the curve boundary degenerates to a single 3D point.
    
    Arguments:
    degenPoint (O) Receives the point to which the boundary degenerates.
    paramCurve (O) Receives the paramater curve corresponding to degenPoint.
    
    Remarks:
    If this method returns true, paramCurve is created with the new operator, and it is the responsibility of the caller to delete it.

    Note:
    This function throws exception "not Implemented".
  */
  OdBool isDegenerate() const;
  OdBool isDegenerate(
    OdGePosition3d& degenPoint, 
    OdGeCurve2d** paramCurve) const;
    
  /**
    Description:
    Returns the number of elements in the curve boundary.
  */
  int numElements() const;

  /**
    Description:
    Returns the paramaters for the curve boundary.
    
    Arguments:
    numCurves (O) Receives the number of curves in the curve boundary.
    crv3d (I/O) Array of 3D curves for each element in the curve boundary.
    crv2d (I/O) Array of 2D curves for each element in the curve boundary.
    orientation3d (I/O) Orientation for each 3D curve element. Valid only if crv3d is not NULL; if NULL, the caller must delete allocated memory that was intended for numCurves.
    orientation2d (I/O) Orientation for each 2D curve element. Valid only if crv2d is not NULL; if NULL, the caller must delete allocated memory that was intended for numCurves.
    
    Remarks:
    For each array, provide memory for the array or allow getCountour to allocate it, and delete the elements of the array. 
    If an array is NULL, getCountour allocates memory and the caller must also delete the corresponding array. 
    
    Note:
    This function is not implemented and will generate a link error if you reference it.
    It will be implemented in a future release.
  */
  void getContour(
    int& numCurves, 
    OdGeEntity3d*** crv3d,
    OdGeCurve2d*** crv2d,
    OdBool** orientation3d,
    OdBool** orientation2d) const;

  /**
    Description:
    Sets the parameters for the curve boundary and returns a reference to it.
    
    Arguments:
    numCurves (I) Number of curves in the curve boundary.
    crv3d (I) Array of 3D curves of each element in the curve boundary.
    crv2d (I) Array of 2D curves of each element in the curve boundary.
    orientation3d (I) Orientation for each 3D curve element. 
    orientation2d (I) Orientation for each 2D curve element.
    makecopy (I)  If true, makes a copy of each 3D and 2D curve. 

    Note:
    This function is not implemented and will generate a link error if you reference it.
    It will be implemented in a future release.
  */
  OdGeCurveBoundary& set(
    int numCurves, 
    const OdGeEntity3d *const * crv3d,
    const OdGeCurve2d *const * crv2d, 
    OdBool* orientation3d,
    OdBool* orientation2d, 
	OdBool makeCopy = kTrue);

  // Curve ownership.
  //
  
  /**
    Description:
    Returns true if and only if the curve boundary is the owner of the 
    curve boundary parameters.

    Note:
    This function is not implemented and will generate a link error if you reference it.
    It will be implemented in a future release.
  */
  OdBool isOwnerOfCurves() const;

  /**
    Description:
    Makes the curve boundary own the curve data and returns a reference to the boundary.

    Remarks:
    If the external boundary owns the data, it will be destroyed when
    the boundary is destroyed.

    Note:
    This function is not implemented and will generate a link error if you reference it.
    It will be implemented in a future release.
  */
  OdGeCurveBoundary& setToOwnCurves();

protected:
  int m_iNumCurves;
  OdGeEntity3d** m_pArrCrv3d;
  OdGeCurve2d** m_pArrCrv2d;
  OdBool* m_bArrOrientation3d;
  OdBool* m_bArrOrientation2d; 
  OdBool m_bMakeCopy;
};

#include "../TD_PackPop.h"

#endif // OD_GE_CURVE_BOUNDARY_H

