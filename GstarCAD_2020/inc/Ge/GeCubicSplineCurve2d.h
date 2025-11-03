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

#ifndef OD_GE_CUBIC_SPLINE_CURVE_2D_H
#define OD_GE_CUBIC_SPLINE_CURVE_2D_H /* {Secret} */

//
// Description:
//
// This file contains the class OdGeCubicSplineCurve2d - A mathematic
// entity used to represent a 2d interpolation cubic-spline *curve*.
//

#include "../Ge/GeSplineEnt2d.h"
#include "../Ge/GePoint2dArray.h"
#include "../Ge/GeVector2dArray.h"

#include "../TD_PackPush.h"

class OdGeCubicSplineCurve3dImpl;

/**
    Description:
    This class represents 2D interpolation cubic spline curves.

    Library: TD_Ge

   {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeCubicSplineCurve2d : public OdGeSplineEnt2d
{
public:
  /**
    Arguments:
    fitPnts (I) An array of 2D fit points.
    tol (I) Geometric tolerance.
    startDeriv (I) Starting derivative of the cubic *spline* *curve*.
    endDeriv (I) Ending derivative of this cubic *spline* *curve*.
    curve (I) A *curve* to be approximated by this cubic *spline* *curve*.
    knots (I) Knot vector.
    isPeriodic (I) True if and only if the cubic *spline* *curve* is to be periodic (closed).
    firstDerivs (I) Array of first derivatives at the fit points.
    source (I) Object to be cloned.

    Remarks:
    OdGeCubicCplineCurve2d(fitPnts, tol) constructs a periodic (closed)
    cubic *spline* *curve*. The last fit *point* must equal the first.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeCubicSplineCurve2d();
  OdGeCubicSplineCurve2d(
    const OdGeCubicSplineCurve2d& source);
  OdGeCubicSplineCurve2d(
    const OdGePoint2dArray& fitPnts,
    const OdGeTol& tol = OdGeContext::gTol);
  OdGeCubicSplineCurve2d(
    const OdGePoint2dArray& fitPnts,
    const OdGeVector2d& startDeriv,
    const OdGeVector2d& endDeriv,
    const OdGeTol& tol = OdGeContext::gTol);
  OdGeCubicSplineCurve2d(
    const OdGeCurve2d& curve,
    double tol 
#ifndef SWIG
    = OdGeContext::gTol.equalPoint()
#endif
    );
  OdGeCubicSplineCurve2d(
    const OdGeKnotVector& knots,
    const OdGePoint2dArray& fitPnts,
    const OdGeVector2dArray& firstDerivs,
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
  OdGePoint2d fitPointAt(
    int fitPointIndex) const;

  /**
    Description:
    Sets the fit *point* at the specified index, and returns a reference to this *curve*.

    Arguments:
    fitPointIndex (I) Fit *point* *index*.
    point (I) Any 2D *point*.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeCubicSplineCurve2d& setFitPointAt(
    int fitPointIndex, 
    const OdGePoint2d& point);

  /**
    Description:
    Returns the first derivative at the specified index.

    Arguments:
    fitPointIndex (I) Fit *point* *index*.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeVector2d firstDerivAt(
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
  OdGeCubicSplineCurve2d& setFirstDerivAt(
    int fitPointIndex, 
    const OdGeVector2d& deriv);

  /**
    Note:
    By default this function throws exception "not Implemented".
  */  
  OdGeCubicSplineCurve2d&  operator =(
    const OdGeCubicSplineCurve2d& spline);
  OdGeCubicSplineCurve2d(OdGeCubicSplineCurve3dImpl *);
};

#include "../TD_PackPop.h"

#endif // OD_GE_CUBIC_SPLINE_CURVE_2D_H
