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

#ifndef OD_GEPLIN3D_H
#define OD_GEPLIN3D_H /* {Secret} */

#include "../OdPlatform.h"
#include "../Ge/GeCurve3d.h"
#include "../Ge/GeSplineEnt3d.h"
#include "../Ge/GeKnotVector.h"
#include "../Ge/GePoint3d.h"
#include "../Ge/GeVector3d.h"
#include "../Ge/GePoint3dArray.h"
#include "../Ge/GeSplineEnt3d.h"

#include "../TD_PackPush.h"

class OdGePolyline3dImpl;
/**
    Description:
    This class represents piecewise linear splines in 3D space.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGePolyline3d : public OdGeSplineEnt3d
{
public:


 /**
    Arguments:
    points (I) An OdGePoint3dArray of fit *points*.
    pPoints (I) An array of fit *points*.
    numPoints (I) The number of *points* in pPoints.
    crv (I) A 2D curve to be approximated as a polyline.
    approxEps (I) Approximate geometric tolerance. 
    source (I) Object to be cloned.
  */
  OdGePolyline3d();
  OdGePolyline3d(OdGePolyline3dImpl* impl);
  OdGePolyline3d(const OdGePolyline3d& source);
  OdGePolyline3d(const OdGePoint3dArray& points);
  OdGePolyline3d(const OdGeKnotVector& knots, 
                 const OdGePoint3dArray& controlPoints);
  OdGePolyline3d(const OdGeCurve3d& crv, 
                 double approxEps);
  // TD Special
  OdGePolyline3d(OdInt32 numPoints, 
                 const OdGePoint3d* pPoints);

  /**
    Description:
    Returns the number of fit points.
  */
   int numFitPoints() const;

  /**
    Description:
    Returns the fit *point* at the specified index.

    Arguments:
    fitPointIndex (I) Fit *point* *index*.
  */
   OdGePoint3d fitPointAt(int fitPointIndex) const;

   OdGeSplineEnt3d& setFitPointAt(int index, const OdGePoint3d& point);

  // Assignment operator.
  OdGePolyline3d& operator =(const OdGePolyline3d& polyline);

  ///////////////////////////////////////////////////////////////////////////
  // TD Special :

  void setFitData(const OdGePoint3dArray &fitPnts, bool  isClosed = false);

  void setFitData(const OdGePoint3dArray &fitPnts, const OdGeDoubleArray &bugles, const OdGeVector3d normal, bool isClosed = false);
  /**
  Description:
  Returns the *point* on the specified segment corresponding to the specified parameter value.

  Arguments:
  param (I) Parameter on specified segment.
  numSeg (I) The segment to be queried.
  */
   OdGePoint3d evalPointSeg(
    double param, 
    int& numSeg) const;

   bool hasBulges() const;

   double bugleAt(int idx ) const;
};

#include "../TD_PackPop.h"

#endif // OD_GEPLIN3D_H
