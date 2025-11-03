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

#ifndef OD_GECSPL3D_H
#define OD_GECSPL3D_H /* {Secret} */

#include "../Ge/GeSplineEnt3d.h"

#include "../TD_PackPush.h"
class OdGeCubicSplineCurve3dImpl;

/**
    Description:
    This class represents 3D interpolation cubic spline curves.

    Library: TD_Ge

   {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeCubicSplineCurve3d : public OdGeSplineEnt3d
{
public:


  /**
  Arguments:
    fitPnts (I) An array of 3D fit points.
    tol (I) Geometric tolerance.
    startDeriv (I) Starting derivative of the cubic *spline* *curve*.
    endDeriv (I) Ending derivative of this cubic *spline* *curve*.
    curve (I) A *curve* to be approximated by this cubic *spline* *curve*.
    knots (I) Knot vector.
    isPeriodic (I) True if and only if the cubic *spline* *curve* is to be periodic (closed).
    firstDerivs (I) Array of first derivatives at the fit points.
    source (I) Object to be cloned.

    Remarks:
    OdGeCubicCplineCurve3d(fitPnts, tol) constructs a periodic (closed)
    cubic *spline* *curve*. The last fit *point* must equal the first.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeCubicSplineCurve3d();
  OdGeCubicSplineCurve3d(
    const OdGeCubicSplineCurve3d& source);
  OdGeCubicSplineCurve3d(OdGeCubicSplineCurve3dImpl* impl);
  OdGeCubicSplineCurve3d(
    const OdGePoint3dArray& fitPnts,
    const OdGeTol& tol = OdGeContext::gTol);
  OdGeCubicSplineCurve3d(
    const OdGePoint3dArray& fitPnts,
    const OdGeVector3d& startDeriv,
    const OdGeVector3d& endDeriv,
    const OdGeTol& tol = OdGeContext::gTol);
  OdGeCubicSplineCurve3d(
    const OdGeCurve3d& curve,
    double epsilon = OdGeContext::gTol.equalPoint());
  OdGeCubicSplineCurve3d(
    const OdGeKnotVector& knots,
    const OdGePoint3dArray& fitPnts,
    const OdGeVector3dArray& firstDerivs,
	OdBool isPeriodic = kFalse);

  /**
    Description:
    Returns the number of fit points.

    Note:
    By default this function throws exception "not Implemented".
  */
   int numFitPoints() const;

  /**
  Description:
    Returns the fit *point* at the specified index.

    Arguments:
    fitPointIndex (I) Fit *point* *index*.

    Note:
    By default this function throws exception "not Implemented".
  */
   OdGePoint3d fitPointAt(
    int fotPointIndex) const;

  /**
    Description:
    Sets the fit *point* at the specified index, and returns a reference to this *curve*.

    Arguments:
    fitPointIndex (I) Fit *point* *index*.
    point (I) Any 3D *point*.

    Note:
    By default this function throws exception "not Implemented".
  */
   OdGeCubicSplineCurve3d& setFitPointAt(
    int fitPointIndex, 
    const OdGePoint3d& point);

  /**
    Description:
    Returns the first derivative at the specified index.

    Arguments:
    fitPointIndex (I) Fit *point* *index*.

    Note:
    By default this function throws exception "not Implemented".
  */
   OdGeVector3d firstDerivAt(
    int fitPointIndex) const;

  /**
    Description:
    Sets the first derivative at the specified index, and returns a reference to this *curve*.

    Arguments:
    fitPointIndex (I) Fit *point* *index*.
    deriv (I) The first derivative at the fit *point*.

    Note:
    By default this function throws exception "not Implemented".
  */
   OdGeCubicSplineCurve3d& setFirstDerivAt(
    int fitPointIndex, 
    const OdGeVector3d& deriv);

  OdGeCubicSplineCurve3d&  operator =(
    const OdGeCubicSplineCurve3d& spline);
};

#include "../TD_PackPop.h"

#endif

