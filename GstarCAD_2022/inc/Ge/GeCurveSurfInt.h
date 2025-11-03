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

#ifndef OD_GECSINT_H
#define OD_GECSINT_H /* {Secret} */

#include "../Ge/GeEntity3d.h"

#include "../TD_PackPush.h"

class OdGeCurve3d;
class OdGeSurface;
class OdGePointOnCurve3d;
class OdGePointOnSurface;

/**
    Description:
    This class represents intersections of 3D curves and surfaces.

    Remarks:
    The intersection object links to curve and surface objects, but does not
	contain them. Calculation of the intersection is performed by a calling 
	function, which owns the intersection output.
	
	If one of the objects is deleted, the intersection must be recalculated.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeCurveSurfInt : public OdGeEntity3d
{
public:


  /**
    Arguments:
    curve (I) Any 3D curve.
    surface (I) Any surface.
    tol (I) Geometric tolerance.
    source (I) Object to be cloned.
  */
  OdGeCurveSurfInt();
  OdGeCurveSurfInt(
    const OdGeCurve3d& curve, 
    const OdGeSurface& surface,
    const OdGeTol& tol = OdGeContext::gTol);
  OdGeCurveSurfInt(
    const OdGeCurveSurfInt& source);

  /**
    Description:
    Returns the 3D curve.
  */
   const OdGeCurve3d* curve() const;

  /**
    Description:
    Returns the surface.
  */
   const OdGeSurface* surface() const;

  /**
    Description:
    Returns the tolerance for determining intersections.
  */
   OdGeTol tolerance() const;

  /**
    Description:
    Returns the number of intersections between the curve and the surface,
    and returns the status of the intersection.

    Arguments:
    status (O) Receives the status of the intersection.

    Remarks:
    Possible values for status are as follows:

    @untitled table
    kXXOk
    kXXIndexOutOfRange
    kXXWrongDimensionAtIndex
    kXXUnknown

    Note:
    By default this function throws exception "not Implemented".
  */
   int numIntPoints(
    OdGeIntersectError& status) const;

  /**
    Description:
    Returns a 3D point representing the specified intersection,
    and returns the status of the intersection.

    Arguments:
    intNum (I) The zero-based index of the intersection curve to return.
    status (O) Receives the status of the intersection.

    Remarks:
    Returns NULL if the dimension of this intersection is not 0 (not a 3D point).

    Possible values for status are as follows:

    @untitled table
    kXXOk
    kXXIndexOutOfRange
    kXXWrongDimensionAtIndex
    kXXUnknown

    Note:
    By default this function throws exception "not Implemented".
  */
   OdGePoint3d intPoint(
    int intNum, 
    OdGeIntersectError& status) const;

  /**
    Description: 
    Returns the parameters of the specified intersection point with respect to the curve and surface,
    and returns the status of the intersection.

    Arguments:
    intNum (I) The zero-based index of the intersection curve to return.
    param1 (O) Receives the parameter of the intersection point with respect to the curve.
    param2 (O) Receives the parameter pair of the intersection point with respect to the surface.
    status (O) Receives the status of the intersection.

    Remarks:
    Possible values for status are as follows:

    @untitled table
    kXXOk
    kXXIndexOutOfRange
    kXXWrongDimensionAtIndex
    kXXUnknown

    Note:
    By default this function throws exception "not Implemented".
  */
   void getIntParams(
    int intNum,
    double& param1,
    OdGePoint2d& param2,
    OdGeIntersectError& status) const;

  /**
    Description: 
    Returns the intersection point on the curve, and returns the 
	status of the intersection.

    Arguments:
    intNum (I) The zero-based index of the intersection pooint to return.
    intPnt (O) Receives the specified intersection point on the curve.
    status (O) Receives the status of the intersection.

    Remarks:
    Possible values for status are as follows:

    @untitled table
    kXXOk
    kXXIndexOutOfRange
    kXXWrongDimensionAtIndex
    kXXUnknown

    Note:
    By default this function throws exception "not Implemented".
  */
   void getPointOnCurve(
    int intNum, 
    OdGePointOnCurve3d& intPnt, 
    OdGeIntersectError& status) const;

  /**
    Description: 
    Returns the intersection point on the surface, and returns the 
	status of the intersection.

    Arguments:
    intNum (I) The zero-based index of the intersection point to return.
    intPnt (O) Receives the specified intersection point on the surface.
    status (O) Receives the status of the intersection.

    Remarks:
    Possible values for status are as follows:

    @untitled table
    kXXOk
    kXXIndexOutOfRange
    kXXWrongDimensionAtIndex
    kXXUnknown

    Note:
    By default this function throws exception "not Implemented".
  */
   void getPointOnSurface(
    int intNum, 
    OdGePointOnSurface& intPnt, 
    OdGeIntersectError& status) const;

  /**
    Description: 
    Returns the configurations on either side of the surface at the intersection.

    Arguments:
    intNum (I) The zero-based index of the intersection curve to return.
    lower (O) Unknown.
    higher (O) Unknown.
    smallAngle (O) Unknown.
    status (O) Receives the status of the intersection.

    Remarks:
    Possible values for lower and higher are as follows:

    @untitled table
    kXUnknown               
    kXOut                   
    kXIn                    
    kXTanOut                
    kXTanIn                 
    kXCoincident            
    kXCoincidentUnbounded   

    Possible values for status are as follows:

    @untitled table
    kXXOk
    kXXIndexOutOfRange
    kXXWrongDimensionAtIndex
    kXXUnknown

    Note:
    By default this function throws exception "not Implemented".
  */
   void getIntConfigs(
    int intNum, 
    OdGe::csiConfig& lower, 
    OdGe::csiConfig& higher, 
	OdBool& smallAngle, 
    OdGeIntersectError& status) const;

  /**
    Description:
    Specifies the 3D curve, surface, and tolerance for determining
	intersections.

    Arguments:      
    curve (I) Any 3D curve.
    surface (I) Any surface.
    tol (I) Geometric tolerance.
  */
   OdGeCurveSurfInt& set(
    const OdGeCurve3d& cvr,
    const OdGeSurface& surface,
    const OdGeTol& tol = OdGeContext::gTol);

  OdGeCurveSurfInt& operator =(
    const OdGeCurveSurfInt& crvSurfInt);

  //////////////////////////////////////////////////////////////////////////

};

#include "../TD_PackPop.h"

#endif

