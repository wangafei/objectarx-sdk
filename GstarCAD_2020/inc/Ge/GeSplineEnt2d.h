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

#ifndef OD_GE_SPLINE_ENT_2D_H
#define OD_GE_SPLINE_ENT_2D_H /* {Secret} */

class OdGeKnotVector;

#include "../Ge/GeCurve2d.h"
#include "../Ge/GeKnotVector.h"
#include "../Ge/GePoint2d.h"
#include "../Ge/GeVector2d.h"
#include "../Ge/GePoint2dArray.h"

#include "../TD_PackPush.h"

class OdGeSplineEnt3dImpl;
/**
    Description:
    This class represents various spline objects in 2D space.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeSplineEnt2d : public OdGeCurve2d
{
public:

  /**
    Description:
    Returns true if and only if the spline is *rational* or a polynomial.

    Remarks:
    This function is meaningful only for AcGeNurbCurve2d objects derived from OdGeSplineEnt2d.
  */
  OdBool isRational () const;

  /**
    Description:
    Returns the *degree* of the spline.
  */
  int degree () const;

  /**
    Description:
    Returns the *order* of the spline.
  */
  int order () const;

  /**
    Description:
    Returns the number of *knots* in the knot vector.
  */
  int numKnots () const;

  /**
    Description:
    Returns the knot vector.
  */
 const OdGeKnotVector& knots () const;

  /**
    Description:
    Returns the number of *points* in the control *point* array.
  */
 int numControlPoints () const;

  /**
    Description:
    Returns the *degree* of the highest derivative that is defined at a specified knot.

    Arguments:
    knotIndex (I) Knot *index*.
    tol (I) Geometric tolerance.
  */
  int continuityAtKnot (
    int knotIndex, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns the parameter corresponding to the start point of this spline.
  */
  double startParam () const;

  /**
    Description:
    Returns the parameter corresponding to the end point of this spline.
  */
 double endParam () const;

  /**
    Description:
    Returns the start point of this spline.
  */
  OdGePoint2d startPoint () const;

  /**
    Description:
    Returns the end point of this spline.
  */
  OdGePoint2d endPoint () const;

  /**
    Description:
    Returns true if and only if the spline is constructed using fit points.
  */
  OdBool hasFitData () const;

  /**
    Description:
    Returns a knot value for the specified knot.

    Arguments:
    knotIndex (I) Knot *index*.
  */
  double knotAt (
    int knotIndex) const;

  /**
    Description:
    Sets the knot value for the specified knot.

    Arguments:
    knotIndex (I) Knot *index*.
    val (I) The new value for the knot.
  */
  OdGeSplineEnt2d& setKnotAt (
    int knotIndex, 
    double val);

  /**
    Description:
    Returns the specified control *point* in the control *point* array.

    Arguments:
    controlPointIndex (I) Control *point* *index*.
  */
  OdGePoint2d controlPointAt (
    int controlPointIndex) const;

  /**
    Description:
    Sets the specified control *point* in the control *point* array.

    Arguments:
    controlPointIndex (I) Control *point* *index*.
  */
  OdGeSplineEnt2d& setControlPointAt (
    int controlPointIndex, 
    const OdGePoint2d& point);

  OdGeSplineEnt2d& operator =(const OdGeSplineEnt2d& spline);

  //////////////////////////////////////////////////////////////////////////

protected:
  OdGeSplineEnt2d();
  OdGeSplineEnt2d(
    const OdGeSplineEnt2d& spline);
  OdGeSplineEnt2d(OdGeSplineEnt3dImpl *);
};

#include "../TD_PackPop.h"

#endif // OD_GE_SPLINE_ENT_2D_H
