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

#ifndef OD_GE_BOUND_BLOCK2D_H
#define OD_GE_BOUND_BLOCK2D_H /* {Secret} */

#include "../Ge/GeEntity2d.h"
#include "../Ge/GeExtents2d.h"

#include "../TD_PackPush.h"

/**
    Description:
    This class implements a 2D bounding area.

    Library: TD_Ge

    {group:OdGe_Classes}
*/
class GE_TOOLKIT_EXPORT OdGeBoundBlock2d : public OdGeEntity2d
{
public:
  

  /**
    Arguments:
    point1 (I) First *point* of a coordinate-aligned box.
    point2 (I) Second *point* of a coordinate-aligned box.
    base (I) Base of parallelogram bounding *block*.
    dir1 (I) First side of parallelogram bounding *block*.
    dir2 (I) Second side of parallelogram bounding *block*.
    source (I) Object to be cloned.
    
    Remarks:
    The default constructor constructs a parallelogram reduced to the coordinate origin.
  */
  OdGeBoundBlock2d();
  OdGeBoundBlock2d(
    const OdGePoint2d& point1, 
    const OdGePoint2d& point2);

  OdGeBoundBlock2d(
    const OdGePoint2d& base, 
    const OdGeVector2d& dir1, 
    const OdGeVector2d& dir2);
  OdGeBoundBlock2d(
    const OdGeBoundBlock2d& source);

  /**
    Description
    Returns the extents of the bounding block.

    Arguments:
    p1 (O) Receives the first corner of the extents.
    p2 (O) Receives the second corner of the extents.
  */
  void getMinMaxPoints(
    OdGePoint2d& p1, 
    OdGePoint2d& p2) const;

  /**
    Description:
    Returns *base* and sides of bounding block.

    Arguments:
    base (O) Receives the *base* of bounding block.
    side1 (O) Receives the first side of bounding block.
    side2 (O) Receives the second side of bounding block.
  */
  void get(
    OdGePoint2d& base, 
    OdGeVector2d& side1, 
    OdGeVector2d& side2) const;

  /**
    Description:
    Sets the bounding block to a coordinate-aligned box or to
    a parallelogram bounding block.

    Arguments:
    p1 (I) First *point* of a coordinate-aligned box.
    p2 (I) Second *point* of a coordinate-aligned box.
    base (I) Base of parallelogram bounding block.
    side1 (I) First side of parallelogram bounding block.
    side2 (I) Second side of parallelogram bounding block.
  */
  OdGeBoundBlock2d& set(
    const OdGePoint2d& p1, 
    const OdGePoint2d& p2);

  OdGeBoundBlock2d& set(
    const OdGePoint2d& base, 
    const OdGeVector2d& side1, 
    const OdGeVector2d& side2);

  /**
    Description:
    Extends the bounding block to contain
    the specified *point*.

    Arguments:
    point (I) Any 2D *point*.
  */
  OdGeBoundBlock2d& extend(
    const OdGePoint2d& point);

  /**
    Description:
    Moves the walls of the bounding block the specified *distance*.

    Arguments:
    distance (I) Distance.
  */
  OdGeBoundBlock2d& swell(
    double distance);

  /**
    Description:
    Returns kTrue if and only if the *point* is
    contained in the bounding block.

    Arguments:
    point (I) Any 2D *point*.
  */
  OdBool contains (
    const OdGePoint2d& point) const;

  /**
    Description:
    Returns kTrue if and only if specified bounding *block*
    does not intersect this bounding *block*.

    Arguments:
    block (I) Any 2D bounding *block*.
  */
  OdBool isDisjoint (
    const OdGeBoundBlock2d& block) const;

  OdGeBoundBlock2d& operator =(
    const OdGeBoundBlock2d& block);

  /**
    Description:
    Returns kTrue if and only if this bounding block is a
    coordinate-aligned box.
  */
  OdBool isBox () const;

  /**
    Description:
  Sets this bounding block to a coordinate-aligned box, or a
    parallelogram bounding block. Returns a reference to this 
    bounding block.

    Arguments:
    toBox (I) If kTrue, sets this bounding block to a 
      coordinate-aligned box; otherwise, sets it to a 
      parallelogram bounding block.
  */
  OdGeBoundBlock2d& setToBox (
    OdBool toBox);
};

#include "../TD_PackPop.h"

#endif // OD_GE_BOUND_BLOCK2D_H

