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

#ifndef OD_GE_ENTITY_2D_H
#define OD_GE_ENTITY_2D_H /* {Secret} */

class OdGeMatrix2d;
class OdGeLine2d;
class OdGeEntity3dImpl;

#include "../Ge/GeGbl.h"
#include "../Ge/GePoint2d.h"
#include "../Ge/GeInterval.h"
#include "../OdHeap.h"

#include "../TD_PackPush.h"

/**
    Description:
    This class is the base class for all OdGe 2D geometric operations.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeEntity2d
{
public:
  ODRX_HEAP_OPERATORS();

  /**
    Description:
    Returns true if and only if this entity is of  *type* (or is derived from) entType.

    Arguments:
    entType (I) Entity *type* to test. 
  */
  OdBool isKindOf(
    OdGe::EntityId entType) const;

  /**
    Description:
    Returns the entity *type* of this entity.
  */
  OdGe::EntityId type() const;

  /**
    Description:
    Returns a *copy* of this entity.

    Remarks:
    The returned object is created with the new operator, and it is the responsibility of the caller to delete it.
  */
  OdGeEntity2d* copy() const;

  OdGeEntity2d& operator =(
    const OdGeEntity2d& entity);

  OdBool operator ==(
    const OdGeEntity2d& entity) const;

  OdBool operator !=(
    const OdGeEntity2d& entity) const;

  /**
    Description:
    Returns true if the specified entity is equal to this one.

    Remarks:
    Returns true if and only if both entities are of the same *type*, have the same point *set* within the 
    specified tolerance, and have the same parameterization.

    Arguments:
    other (I) Entity to be compared
    tol (I) Geometric tolerance.
  */
  OdBool isEqualTo(
    const OdGeEntity2d& other, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Applies the 2D transformation matrix to this entity, and returns
    a reference to this entity.

    Arguments:
    xfm (I) 2D transformation matrix.
  */
  OdGeEntity2d& transformBy(
    const OdGeMatrix2d& xfm);

  /**
    Description:
    Applies the 2D translation vector to this entity, and returns
    a reference to this entity.

    Arguments:
    translateVec (I) Translation Vector.
  */
  OdGeEntity2d& translateBy(
    const OdGeVector2d& translateVec);

  /**
    Description:
    Rotates this entity about the specified *point* by the specified *angle*, and returns
    a reference to this entity.

    Arguments:
    angle (I) Rotation *angle*.
    basePoint (I) Basepoint.
  */
  OdGeEntity2d& rotateBy(
    double angle, 
    const OdGePoint2d& basePoint = OdGePoint2d::kOrigin);

  /**
    Description:
    Mirrors this entity about the specified 2D *line*, and returns
    a reference to this entity.

    Arguments:
    line (I) Mirror *Line*.
  */
  OdGeEntity2d& mirror(
    const OdGeLine2d& line);

  /**
    Description:
    Scales this entity by the scale factor about the basepoint, and returns
    a reference to this entity.

    Arguments:
    scaleFactor (I) Scale Factor. The scale factor must be greater than zero.
    basePoint (I) Basepoint.
  */
  OdGeEntity2d& scaleBy(
    double scaleFactor, 
    const OdGePoint2d& basePoint = OdGePoint2d::kOrigin);

  /**
    Description:
    Returns true if and only if the specified *point* is on this entity, as determined by the tolerance.

    Arguments:
    point (I) Point to be queried.
    tol (I) Geometric tolerance.
  */
  OdBool isOn(
    const OdGePoint2d& point, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  ~OdGeEntity2d();
protected:
  OdGeEntity2d();
  // Following the method of ARX, use 3dImpl class
  // to implement the 2d version entity.
  OdGeEntity2d(OdGeEntity3dImpl*);
  OdGeEntity2d(const OdGeEntity2d&);
  void connectTo(OdGeEntity3dImpl*);
private:
  
  OdGeEntity3dImpl* m_pImpl;
  friend class OdGeEntity3dImpl;
};

#include "../TD_PackPop.h"

#endif // OD_GE_ENTITY_2D_H

