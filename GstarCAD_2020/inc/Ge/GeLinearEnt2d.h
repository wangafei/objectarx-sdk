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

#ifndef OD_GE_LINEAR_ENT_2D_H
#define OD_GE_LINEAR_ENT_2D_H /* {Secret} */

class OdGeCircArc2d;

#include "../Ge/GeCurve2d.h"
#include "../Ge/GePoint2d.h"
#include "../Ge/GeVector2d.h"
#include "../OdPlatformSettings.h"
#include <memory.h> // for memcpy

#include "../TD_PackPush.h"
class OdGeLinearEnt3dImpl;

/**
    Description:
    This class is the base class for OdGe 2D linear entities.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeLinearEnt2d : public OdGeCurve2d
{
public:
  

  /**
    Description:
    Returns true and the intersection point, if and only 
    if the specified linear entity intersects with this one.

    Arguments:
    line (I) Any 2D linear entity.
    intPnt (O) Receives the intesection *point*.
    tol (I) Geometric tolerance.
  */
  OdBool intersectWith(
    const OdGeLinearEnt2d& line, 
    OdGePoint2d& intPnt,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Determines if two lines overlap and if so returns 
    the line that coincides with their region of overlap. 

    Arguments:
    line (I) Any 2D linear entity.
    overlap (O) Output linear entity that is coincident with region of overlap  
    tol (I) Input tolerance.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdBool overlap(
    const OdGeLinearEnt2d& line, 
    OdGeLinearEnt2d*& overlap,
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only 
    if the specified linear entity is parallel to this one.

    Arguments:
    line (I) Any 2D linear entity.
    tol (I) Geometric tolerance.
  */
  OdBool isParallelTo(
    const OdGeLinearEnt2d& line, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only 
    if the specified linear entity is perpendicular to this one.

    Arguments:
    line (I) Any 2D linear entity.
    tol (I) Geometric tolerance.
  */
  OdBool isPerpendicularTo(
    const OdGeLinearEnt2d& line, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only 
    if the specified linear entity is colinear to this one.

    Arguments:
    line (I) Any 2D linear entity.
    tol (I) Geometric tolerance.
  */
  OdBool isColinearTo(
    const OdGeLinearEnt2d& line, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns a reference to a 2D *line* perpendicular to this one,
    and passing through the specified *point*.

    Arguments:
    point (I) Any 2D *point*.
    perpLine (O) Receives a reference to the perpendicular *line*.

    Remarks:
    It is up to the caller to delete the returned *line*.
  */
  void getPerpLine(
    const OdGePoint2d& point, 
    OdGeLine2d& perpLine) const;

  /**
    Description:
    Returns an arbitrary *point* on this linear entity.
  */
  OdGePoint2d pointOnLine() const;

  /**
    Description:
    Returns a unit vector parallel to this linear entity, 
    and pointing in the *direction* of increasing parametric value.
  */
  OdGeVector2d direction() const;

  /**
    Description:
    Returns a reference to an infinite *line* colinear with this linear entity.

    Arguments:
    line (O) Receives the infinite *line*.

    Remarks:
    It is up to the caller to delete the returned *line*.
  */
  void getLine(
    OdGeLine2d& line) const;

  OdGeLinearEnt2d& operator =(const OdGeLinearEnt2d& line);

  //////////////////////////////////////////////////////////////////////////
  // Overrides :

  //////////////////////////////////////////////////////////////////////////
  // TD Special overrides :

protected:
  /**
    Arguments:
    source (I) Object to be cloned.
  */
  OdGeLinearEnt2d(); 
  OdGeLinearEnt2d(OdGeLinearEnt3dImpl *);
  OdGeLinearEnt2d(const OdGeLinearEnt2d& source); 
};

#include "../TD_PackPop.h"

#endif

