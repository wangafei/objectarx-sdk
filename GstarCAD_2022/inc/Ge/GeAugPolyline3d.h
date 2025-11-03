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

#ifndef OD_GEAPLN3D_H
#define OD_GEAPLN3D_H  /* {Secret} */

#include "../Ge/GePolyline3d.h"
#include "../Ge/GePoint3d.h"
#include "../Ge/GeVector3dArray.h"
#include "../Ge/GeKnotVector.h"

#include "../TD_PackPush.h"

class OdGeAugPolyline3dImpl;
/**
    Description:
    This class represents mathematical entities used to support various types of spline curves in 3D space.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeAugPolyline3d : public OdGePolyline3d
{
public:


  /**
    Arguments:
    curve (I) Any 3D *curve*.
    fromParam (I) Starting parameter value.
    toParam (I) Ending parameter value.
    approxEps (I) Approximate spacing along a *curve*.
    knots (I) Knot vector.
    controlPoints (I) Control *point* array.
    vecBundle (I) Vector array. 
    source (I) Object to be cloned.
  */
  OdGeAugPolyline3d();
  OdGeAugPolyline3d(OdGeAugPolyline3dImpl* impl);
  OdGeAugPolyline3d(
    const OdGeAugPolyline3d& apline);
  OdGeAugPolyline3d(
    const OdGeKnotVector& knots,
    const OdGePoint3dArray& controlPoints,
    const OdGeVector3dArray& vecBundle);
  OdGeAugPolyline3d(
    const OdGePoint3dArray& controlPoints,
    const OdGeVector3dArray& vecBundle);
  OdGeAugPolyline3d(
    const OdGeCurve3d& curve,
    double fromParam, 
    double toParam, 
    double approxEps);

  OdGeAugPolyline3d& operator =(
    const OdGeAugPolyline3d& apline);

  /**
    Description:
    Returns the control *point* at the specified index.

    Arguments:
    cpIndex (I) Control *point* *index*.

    Note:
    By default this function throws exception "not Implemented".
  */
   OdGePoint3d getPoint(
    int index) const;

  /**
    Description:
    Sets the control *point* at the specified index, and returns a reference to this *curve*.

    Arguments:
    controlpointIndex (I) Control *point* *index*.
    point (I) Any 3D *point*.
  */
   OdGeAugPolyline3d& setPoint(
    int controlpointIndex, 
    OdGePoint3d point);

  /**
    Description:
    Returns the array of control *points*.

    Arguments:
    controlPoints (O) Receives an array of control *points*.
  */
   void getPoints(
    OdGePoint3dArray& controlPoints) const;

  /**
    Description:
    Returns the vector at the specified index.

    Arguments:
    vectorIndex (I) Vector *index*.
  */
   OdGeVector3d getVector(
    int vectorIndex) const;

  /**
    Description:
    Sets the vector at the specified index, and returns a reference to this *curve*.

    Arguments:
    vectorIndex (I) Vector *index*.
    vect (I) Any 3D vector.
  */
   OdGeAugPolyline3d& setVector(
    int vectorIndex, 
    OdGeVector3d vect);

  /**
    Description:
    Returns an array of the *tangents* (first derivative vectors) to the curve at each control *point*.

    Arguments:
    tangents (O) Receives an array of *tangents*.
  */
   void getD1Vectors(
    OdGeVector3dArray& tangents) const;

  /**
    Description:
    Returns the second derivative vector at the specified index.

    Arguments:
    vectorIndex (I) Vector *index*.
  */
   OdGeVector3d getD2Vector(
    int vectorIndex) const;

  /**
    Description:
    Sets the second derivative vector at the specified index, and returns a reference to this *curve*.

    Arguments:
    vectorIndex (I) Vector *index*.
    vect (I) Second derivative vector.
  */
   OdGeAugPolyline3d& setD2Vector(
    int vectorIndex, 
    OdGeVector3d vect);

  /**
    Description:
    Returns an array of the second derivative vectors to the curve at each control *point*.

    Arguments:
    d2Vectors Returns an array of second derivative cectors.
  */
   void getD2Vectors(
    OdGeVector3dArray& d2Vectors) const;

  /** 
    Description:
    Returns the approximate tolerance that was used to construct the polyline.
  */
   double approxTol() const;

  /** 
    Description:
    Sets the approximate tolerance to be used to construct the polyline, and returns
    a reference to this polyline.

    Remarks:
    This method recomputes the polyline.
  */
   OdGeAugPolyline3d& setApproxTol(
    double approxTol);
};

#include "../TD_PackPop.h"

#endif // OD_GEAPLN3D_H

