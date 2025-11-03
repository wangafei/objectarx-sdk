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

#ifndef OD_GESSINT_H
#define OD_GESSINT_H /* {Secret} */

#include "../Ge/GeEntity3d.h"
#include "../Ge/GeGbl.h"
#include "../Ge/GeGblAbb.h"

class OdGeCurve3d;
class OdGeCurve2d;
class OdGeSurface;

#include "../TD_PackPush.h"

/**
    Description:
    This class holds the intersection data of two surfaces.

    Remarks:
    o This object contains references to surface objects but does not own them.
    o Actual intersection calculations are not performed until a query function is called.
    o Any returned objects other than pointers to the referenced surfaces are owned by the called.
      
    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeSurfSurfInt  : public OdGeEntity3d
{
public:


  /**
    Arguments:
    srf1 (I) First surface.
    srf2 (I) Second surface.
    tol (I) Geometric tolerance.
    source (I) Object to be cloned.
  */
  OdGeSurfSurfInt();

  OdGeSurfSurfInt(
    const OdGeSurface& srf1,
    const OdGeSurface& srf2,
    const OdGeTol& tol = OdGeContext::gTol) ;
  OdGeSurfSurfInt(
    const OdGeSurfSurfInt& source);

  /**
    Description:
    Returns the first surface.
  */
   const OdGeSurface* surface1() const;

  /**
    Description:
    Returns the second surface.
  */
   const OdGeSurface* surface2() const;

  /**
    Description:
    Returns the *tolerance* for determining intersections.
  */
   OdGeTol tolerance() const;

  /**
    Description:
    Returns the number of intersections between the two surfaces,
    and the *status* of the intersections.

    Arguments:
    status (O) Receives the *status* of the intersection.

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
   int numResults(
    OdGeIntersectError& status) const;

  /**
    Description:
    Returns the 3D curve representing the specified intersection
    and the *status* of the intersection.

    Arguments:
    intNum (I) The zero-based index of the intersection curve to return.
    isExternal (I) Unknown.
    status (O) Receives the *status* of the intersection.

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
   OdGeCurve3d* intCurve(
    int intNum, 
    OdBool isExternal, 
    OdGeIntersectError& status) const; 

  /**
    Description: 
    Returns the 2D curve representing the specified intersection
    and the *status* of the intersection.

    Arguments:
    intNum (I) The zero-based index of the intersection curve to return.
    isExternal (I) Unknown.
    isFirst (I) If true, returns the curve on the first surface, otherwise it the curve on the second surface.
    status (O) Receives the *status* of the intersection.

    Remarks:
    If the intersection is not a 2d curve, returns 0.

    Possible values for status are as follows:

    @untitled table
    kXXOk
    kXXIndexOutOfRange
    kXXWrongDimensionAtIndex
    kXXUnknown

    Note:
    By default this function throws exception "not Implemented".
  */
   OdGeCurve2d* intParamCurve(
    int intNum, 
    OdBool isExternal, 
    OdBool isFirst, 
    OdGeIntersectError& status) const;

  /**
    Description: 
    Returns the 3d *point* representing the specified intersection,
    and the *status* of the intersection.

    Arguments:
    intNum (I) The zero-based index of the intersection curve to return.
    status (O) Receives the *status* of the intersection.

    Remarks:
    If the intersection is not a 3d *point*, returns 0.

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
    Returns the parameter pairs for the specified intersection point with respect to each surface,
    and the *status* of the intersection.

    Arguments:
    intNum (I) The zero-based index of the intersection curve to return.
    param1 (O) Receives the parameter pair of the intersection point with respect to the first *curve*.
    param2 (O) Receives the parameter pair of the intersection point with respect to the second *curve*.
    status (O) Receives the *status* of the intersection.

    Possible values for status are as follows:

    @untitled table
    kXXOk
    kXXIndexOutOfRange
    kXXWrongDimensionAtIndex
    kXXUnknown

    Note:
    By default this function throws exception "not Implemented".
  */
   void getIntPointParams(
    int intNum,
    OdGePoint2d& param1, 
    OdGePoint2d& param2, 
    OdGeIntersectError& status) const;

  /**
    Description: 
    Returns the configurations on either side of the intersection each surface.

    Arguments:
    intNum (I) The zero-based index of the intersection curve to return.
    surf1Left (O) Receives the configuration for surface 1 on the left side of the intersection.
    surf1Right (O) Receives the configuration for surface 1 on the right side of the intersection.
    surf2Left (O) Receives the configuration for surface 2 on the left side of the intersection.
    surf2Right (O) Receives the configuration for surface 2 on the right side of the intersection.
    status (O) Receives the *status* of the intersection.
    
    Remarks:
    Possible values for surf1Left, surf1Right, surf2Left, and surf2Right are as follows:

    @untitled table
    kSSIUnknown
    kSSIOut            Neighborhood is outside this surface.
    kSSIIn             Neighborhood is inside this surface.
    kSSICoincident     Non-zero area intersection.

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
    OdGe::ssiConfig& surf1Left,  
    OdGe::ssiConfig& surf1Right,
    OdGe::ssiConfig& surf2Left,  
    OdGe::ssiConfig& surf2Right,  
    OdGe::ssiType& intType, 
    int& dim, 
    OdGeIntersectError& status) const; 

  /**
    Description:
    Description Pending.

    Arguments:
    intNum (I) The zero-based index of the intersection curve to return.
    status (O) Receives the *status* of the intersection.

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
   int getDimension(
    int intNum, 
    OdGeIntersectError& status) const;

  /**
    Description:
    Returns the *type* of the specified intersection.

    Arguments:
    intNum (I) The zero-based index of the intersection curve to return.
    status (O) Receives the *status* of the intersection.

    Remarks:
    Possible return values for the configuratons are as follows:

    @untitled table
    kXXOk
    kXXIndexOutOfRange
    kXXWrongDimensionAtIndex
    kXXUnknown

    Note:
    By default this function throws exception "not Implemented".
  */
   OdGe::ssiType getType(
    int intNum, 
    OdGeIntersectError& status) const;

  /**
    Description:
    Sets the surfaces and tolerances whose intersection data is to be determines.
    Returns a reference to this SurfSurfInt.

    Arguments:
    srf1 (I) First surface.
    srf2 (I) Second surface.
    tol (I) Geometric tolerance.
  */
   OdGeSurfSurfInt& set(
    const OdGeSurface& srf1,
    const OdGeSurface& srf2,
    const OdGeTol& tol = OdGeContext::gTol);

  OdGeSurfSurfInt& operator =(
    const OdGeSurfSurfInt& surfSurfInt);

  //////////////////////////////////////////////////////////////////////////

};

#include "../TD_PackPop.h"

#endif // OD_GESSINT_H
