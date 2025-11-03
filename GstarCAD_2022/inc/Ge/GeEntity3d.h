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


#ifndef _OD_GEENTITY3D_H_
#define _OD_GEENTITY3D_H_ /* {Secret} */


#include "../Ge/GeGbl.h"
#include "../Ge/GePoint3d.h"
#include "../Ge/GeEntity2d.h"
#include "../Ge/GeInterval.h"
#include "../OdHeap.h"

#include "../TD_PackPush.h"

class OdGeMatrix3d;
class OdGePlane;
class OdGeEntity3dImpl;

/**
    Description:
    This class is the base class for all OdGe 3D geometric operations.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeEntity3d
{
public:
  ODRX_HEAP_OPERATORS();

  ~OdGeEntity3d();

  // Run time type information.

  /**
    Description:
    Returns true if and only if this entity is of *type* (or is derived from) entType.

    Arguments:
    entType (I) Entity *type* to test. 
  */
   OdBool isKindOf(
    OdGe::EntityId entType) const;

  /**
    Description:
    Returns the entity *type*.
  */
   OdGe::EntityId type() const;

  /**
    Description:
    Returns a *copy* of this entity.

    Remarks:
  The returned object is created with the new operator, and it is the responsibility of the caller to delete it.
  */
   OdGeEntity3d* copy() const;

  OdGeEntity3d& operator =(
    const OdGeEntity3d& entity);

  OdBool operator ==(
    const OdGeEntity3d& entity) const;
  OdBool operator !=(
    const OdGeEntity3d& entity) const;

  /**
    Returns true if the specified entity is equal to this one.

    Remarks:
    Returns true if and only if both entities are of the same *type*, have the same point *set* within the 
    specified tolerance, and have the same parameterization.

    Arguments:
    other (I) Entity to be compared
    tol (I) Geometric tolerance.
  */
   OdBool isEqualTo(
    const OdGeEntity3d& object, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Applies the 3D transformation matrix to this entity, and returns
    a reference to this entity.

    Arguments:
    xfm (I) 3D transformation matrix.
  */
   OdGeEntity3d& transformBy(
    const OdGeMatrix3d& xfm);

  /**
    Description:
    Applies the 3D translation vector to this entity, and returns
    a reference to this entity.

    Arguments:
    translateVec (I) Translation Vector.
  */
   OdGeEntity3d& translateBy(
    const OdGeVector3d& translateVec);

  /**
    Description:
    Rotates this entity by the specified *angle* about the axis
    defined by the point and the vector, and returns
    a reference to this entity.

    Arguments:
    angle (I) Rotation *angle*.
    vect (I) Vector about which entitiy is rotated. 
    basePoint (I) Basepoint.
  */
   OdGeEntity3d& rotateBy(
    double angle, 
    const OdGeVector3d& vect,
    const OdGePoint3d& basePoint = OdGePoint3d::kOrigin);

  /**
    Description:
    Mirrors this entity about the specified *plane*, and returns
    a reference to this entity.

    Arguments:
    plane (I) Plane about which entity is to be mirrored.
  */
   OdGeEntity3d& mirror(
    const OdGePlane& plane);

  /**
    Description:
    Scales this entity by the scale factor about the basepoint, and returns
    a reference to this entity.

    Arguments:
    scaleFactor (I) Scale Factor. Must be greater than 0.
    basePoint (I) Basepoint.
  */
   OdGeEntity3d& scaleBy(
    double scaleFactor,
    const OdGePoint3d& basePoint = OdGePoint3d::kOrigin);

  /**
    Description:
    Returns true if and only if the specified *point* is on this entity, 
    as determined by the tolerance.

    Arguments:
    point (I) Point to be queried.
    tol (I) Geometric tolerance.
  */
   OdBool isOn(
    const OdGePoint3d& point,
    const OdGeTol& tol = OdGeContext::gTol) const;

protected:
  OdGeEntity3d();
  OdGeEntity3d(const OdGeEntity3d&);
  OdGeEntity3d(OdGeEntity3dImpl*);
  void connectTo(OdGeEntity3dImpl*);

private:
  OdGeEntity3dImpl* m_pImpl;
  friend class OdGeEntity3dImpl;
};

#include "../TD_PackPop.h"

#endif //_OD_GEENTITY3D_H_

