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

#ifndef OD_GE_POLYLINE_2D_H
#define OD_GE_POLYLINE_2D_H /* {Secret} */

#include "../OdPlatform.h"
#include "../Ge/GeCurve2d.h"
#include "../Ge/GeSplineEnt2d.h"
#include "../Ge/GeKnotVector.h"
#include "../Ge/GePoint2d.h"
#include "../Ge/GeVector2d.h"
#include "../Ge/GePoint2dArray.h"
#include "../Ge/GeSplineEnt2d.h"

#include "../TD_PackPush.h"

class OdGePolyline3dImpl;
/**
    Description:
    This class represents piecewise linear splines in 2D space.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGePolyline2d : public OdGeSplineEnt2d
{
public:
  

  OdGePolyline2d();
  OdGePolyline2d(OdGePolyline3dImpl *);
  /**
    Arguments:
    source (I) Object to be cloned.
  */
  OdGePolyline2d(
    const OdGePolyline2d& source);
  /**
    Arguments:
    points (I) Array of fit *points*.
    knots (I) Knot vector.
    crv (I) A 2D curve to be approximated as a polyline.
    approxEps (I) Approximate geometric tolerance. 
  */
  OdGePolyline2d(
    const OdGePoint2dArray& fitpoints);
  OdGePolyline2d(
    const OdGeKnotVector& knots,
    const OdGePoint2dArray& points);
  OdGePolyline2d(
    const OdGeCurve2d& crv, 
    double approxEps);

  /**
    Description:
    Returns the number of fit *points*.
  */
  int numFitPoints() const;

  /**
    Description:
    Returns the fit *point* at the specified index.

    Arguments:
    fitPointIndex (I) Fit *point* *index*.
  */
  OdGePoint2d fitPointAt(
    int fitPointIndex) const;

  /**
    Description:
    Sets the fit *point* at the specified index, and returns a reference to this *curve*.

    Arguments:
    fitPointIndex (I) Fit *point* *index*.
    point (I) Any 2D *point*.
  */
  OdGeSplineEnt2d& setFitPointAt(
    int fitPointIndex, 
    const OdGePoint2d& point);

  OdGePolyline2d& operator =(const OdGePolyline2d& pline);

  // TD Special
  void setFitData(const OdGePoint2dArray &fitPnts, bool isClosed = false);

  void setFitData(const OdGePoint2dArray &fitPnts, const OdGeDoubleArray &bugles, bool isClosed = false);

  void setClosed( bool flag );

  bool hasBulges() const;

  double bugleAt(int idx ) const;

  bool removeDuplicatePoints( bool needRemove, bool &hasDupPoint );
};

#include "../TD_PackPop.h"

#endif // OD_GE_POLYLINE_2D_H

