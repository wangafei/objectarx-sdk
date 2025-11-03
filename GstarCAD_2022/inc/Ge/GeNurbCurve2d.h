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


#ifndef OD_GENURB2d_H
#define OD_GENURB2d_H /* {Secret} */

#include "../Ge/GeSplineEnt2d.h"
#include "../OdPlatformSettings.h"

class OdGeNurbCurve3dImpl;
class OdGePolyline2d;
class OdGeEllipArc2d;
class OdGeLineSeg2d;
class OdGeKnotVector;

#include "../Ge/GeCurve2d.h"
#include "../Ge/GeInterval.h"
#include "../Ge/GeKnotVector.h"
#include "../Ge/GeVector2d.h"
#include "../Ge/GeVector2dArray.h"
#include "../Ge/GePoint2d.h"
#include "../Ge/GePoint2dArray.h"
#include "../Ge/GePolyline2d.h"
#include "../Ge/GeDoubleArray.h"
#include "../TD_PackPush.h"

/**
    Description:
    This class represents non-uniform rational B-splines (NURBS) in 2D space.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeNurbCurve2d : public OdGeSplineEnt2d
{
public:
  

  /**
    Arguments:
    degree (I) Degree of spline.
    knots (I) Knot vector.
    controlPoints (I) Array of 2D control points.
    weights (I) Array of *weights*
    isPeriodic (I) True if and only if the spline is to be periodic.
    source (I) Object to be cloned.
    
    Remarks:
    o If weights is not specified, a non-rational spline is constructed. 
    o If weights is specified, then a rational spline is constructed, and controlPoints.length() must equal weights.length()
    o If isPeriodic is false, then knots.length() must equal controlPoints.length() + degree + 1
    o If isPeriodic is true, then knots.length() must equal controlPoints.length(), the first and last controlPoints must be equal
      and the first and last weights (if provided) must be equal.
  */
  OdGeNurbCurve2d();

  OdGeNurbCurve2d(OdGeNurbCurve3dImpl *);

  OdGeNurbCurve2d(const OdGeNurbCurve2d& source);
  OdGeNurbCurve2d(
    int degree, 
    const OdGeKnotVector& knots,
    const OdGePoint2dArray& controlPoints,
	OdBool isPeriodic = kFalse);
  OdGeNurbCurve2d (
    int degree, 
    const OdGeKnotVector& knots,
    const OdGePoint2dArray& controlPoints,
    const OdGeDoubleArray& weights,
    OdBool isPeriodic = false);
  OdGeNurbCurve2d(
    int degree, 
    const OdGePolyline2d& fitPolyline,
    OdBool isPeriodic = false);
  OdGeNurbCurve2d(
    const OdGePoint2dArray& fitPoints,
    const OdGeVector2d& startTangent,
    const OdGeVector2d& endTangent,
    OdBool startTangentDefined = kTrue,
    OdBool endTangentDefined = kTrue,
    const OdGeTol& fitTolerance = OdGeContext::gTol);
  OdGeNurbCurve2d(
    const OdGePoint2dArray& fitPoints,
    const OdGeTol& fitTolerance = OdGeContext::gTol);
  OdGeNurbCurve2d(const OdGePoint2dArray& fitPoints,
    const OdGeVector2dArray& fitTangents,
    const OdGeTol& fitTolerance = OdGeContext::gTol,
    OdBool isPeriodic = false);
  OdGeNurbCurve2d(
    const OdGeEllipArc2d& ellipse);
  OdGeNurbCurve2d(
    const OdGeLineSeg2d& linSeg);

  int numFitPoints() const;
  OdBool getFitPointAt(
    int index, 
    OdGePoint2d& point) const;
  OdBool getFitTolerance(
    OdGeTol& fitTolerance) const;
  OdBool getFitTangents(
    OdGeVector2d& startTangent,
    OdGeVector2d& endTangent) const;
  OdBool getFitData(
    OdGePoint2dArray& fitPoints,
    OdGeTol& fitTolerance,
    OdBool& tangentsExist,
    OdGeVector2d& startTangent,
    OdGeVector2d& endTangent) const;
 
  OdBool getFitData(
    OdGePoint2dArray& fitPoints,
    OdGeTol& fitTolerance,
    OdBool& tangentsExist,
    OdGeVector2d& startTangent, 
    OdGeVector2d& endTangent,
    OdGeKnotParameterization& knotParam) const;


  /** 
    Description:
    Returns all the data that define the spline.
    
    Arguments:
    degree (O) Receives the *degree* of spline.
    knots (O) Receives the knot vector.
    controlPoints (O) Receives an array of 2D control points.
    weights (O) Receives an array of *weights*.
    rational (O) Receives true if and only if the spline is *rational*.
    periodic (O) Receives true true if and only if the spline is *periodic*.
  */
  void getDefinitionData(
    int& degree, 
    OdBool& rational,
    OdBool& periodic,
    OdGeKnotVector& knots,
    OdGePoint2dArray& controlPoints,
    OdGeDoubleArray& weights) const;

  /**
    Description:
    Returns the number of weights in the spline.
    
    Remarks:
    Feturns numControlPoints() if this spline is rational, 0 if it is not.
  */
  int numWeights() const;

  /**
    Description:
    Returns the weight at the specified index.

    Arguments:
    weightIndex (I) Weight *index*.
  */
  double weightAt(
    int weightIndex) const;

  OdBool evalMode() const;

  OdBool getParamsOfC1Discontinuity(
    OdGeDoubleArray& params,
    const OdGeTol& tol = OdGeContext::gTol) const;

  OdBool getParamsOfG1Discontinuity(
    OdGeDoubleArray& params,
    const OdGeTol& tol = OdGeContext::gTol) const;

  OdBool setFitPointAt(
    int index, 
    const OdGePoint2d& point);

  OdBool addFitPointAt(
    int index, 
    const OdGePoint2d& point);

  OdBool deleteFitPointAt(
    int index);

  OdBool setFitTolerance(
    const OdGeTol& fitTol = OdGeContext::gTol);

  OdBool setFitTangents(
    const OdGeVector2d& startTangent,
    const OdGeVector2d& endTangent);

  bool setFitKnotParameterization(OdGeKnotParameterization knotParam);

  OdGeNurbCurve2d& setFitData(
    const OdGePoint2dArray& fitPoints,
    const OdGeVector2d& startTangent,
    const OdGeVector2d& endTangent,
    const OdGeTol& fitTol = OdGeContext::gTol);
  OdGeNurbCurve2d& setFitData(
    const OdGeKnotVector& fitKnots,
    const OdGePoint2dArray& fitPoints,
    const OdGeVector2d& startTangent,
    const OdGeVector2d& endTangent,
    const OdGeTol& fitTol = OdGeContext::gTol,
    OdBool isPeriodic = kFalse);
  OdGeNurbCurve2d& setFitData(
    int degree,
    const OdGePoint2dArray& fitPoints,
    const OdGeTol& fitTol = OdGeContext::gTol);

  OdGeNurbCurve2d& setFitData(
    const OdGePoint2dArray& fitPoints,                                             
    const OdGeVector2d& startTangent, 
    const OdGeVector2d& endTangent,
    OdGeKnotParameterization knotParam,
    const OdGeTol& fitTol = OdGeContext::gTol);


  
  /**
    Description:
    Deletes all the fit data used to construct this *spline*. 
    Returns true if and only if the *spline* was constructed with fit data.

    Remarks:
    The definition of the *spline* is unchanged. 
  */
  OdBool purgeFitData();
  
  OdGeNurbCurve2d& addKnot(
    double newKnot);

  OdGeNurbCurve2d& insertKnot(
    double newKnot);

  /**
    Description:
    Sets the *weight* at the specified control *point*.
    
    Arguments:
    controlPointIndex (I) Control *point* *index*.
    weight (I) The *weight* to be assigned to that control *point*.
  */
  OdGeSplineEnt2d& setWeightAt(
    int controlPointIndex, 
    double weight);

  OdGeNurbCurve2d& setEvalMode(
    OdBool evalMode = kFalse);

  OdGeNurbCurve2d& joinWith(
    const OdGeNurbCurve2d& curve);

  OdGeNurbCurve2d& hardTrimByParams(
    double newStartParam,
    double newEndParam);

  /**
    Description:
    Makes this spline rational.
    
    Arguments:
    weight (I) The *weight* to be assigned to each control *point*.
    
    Remarks:
    When called for a non-rational spline, this spline is made rational, and the specified weight is assigned to each control *point*.
    
    When called for a rational spline, the *weight* at each control *point* is multiplied by the specified weight. 
  */
  OdGeNurbCurve2d& makeRational(
    double weight = 1.0);

  OdGeNurbCurve2d& makeClosed();

  OdGeNurbCurve2d& makePeriodic();

  OdGeNurbCurve2d& makeNonPeriodic();

  OdGeNurbCurve2d& makeOpen();

  OdGeNurbCurve2d& elevateDegree(
    int plusDegree);

  OdGeNurbCurve2d& operator =(
    const OdGeNurbCurve2d& spline);

  // NURBS data edit functions

  /**
    Description:
    Sets the parameters for this spline according to the arguments. 

    Arguments:
    degree (I) Degree of spline.
    knots (I) Knot vector.
    controlPoints (I) Array of 3D control points.
    weights (I) Array of *weights*
    isPeriodic (I) True if and only if this spline is to be periodic.
    
    Remarks:
    Returns *a* reference to this spline.
    
    o A rational spline is constructed, and controlPoints.length() must equal weights.length()
    o If isPeriodic is false, then knots.length() must equal controlPoints.length() + degree + 1
    o If isPeriodic is true, then knots.length() must equal controlPoints.length(), the first and last controlPoints must be equal
      and the first and last weights (if provided) must be equal.
  */
   void set(
    int degree,
    const OdGeKnotVector& knots,
    const OdGePoint2dArray& controlPoints,
    const OdGeDoubleArray& weights,
	OdBool isPeriodic = kFalse);

  // TD Special
   void set(
     int degree, 
     const OdGeKnotVector &knots,
     const OdGePoint2dArray &controlPoints,
     OdGeDoubleArray &weights,
     bool isPeriodic,
     const OdGePoint2dArray &fitPoints,
     const OdGeVector2d &startTangent,
     const OdGeVector2d &endTangent);

  OdBool intersectWith(
    const OdGeLine2d &line2d, 
    OdGePoint2dArray &pnts2d, 
    const OdGeTol& tol = OdGeContext::gTol, 
    OdGeDoubleArray *params = NULL) const;

  /**
  Description:
  Sets the parameters for this spline according to the arguments, 
  and returns a reference to this spline.

  Arguments:
  degree (I) Degree of spline.
  knots (I) Knot vector.
  controlPoints (I) Array of 2D control points.
  weights (I) Array of *weights*
  isPeriodic (I) True if and only if the spline is to be periodic (closed).

  Remarks:
  o If weights is not specified, a non-rational spline is constructed. 
  o If weights is specified, then a rational spline is constructed, and controlPoints.length() must equal weights.length()
  o If isPeriodic is false, then knots.length() must equal controlPoints.length() + degree + 1
  o If isPeriodic is true, then knots.length() must equal controlPoints.length(), the first and last controlPoints must 
  be equal, and the first and last weights (if provided) must be equal.
  */
    void setData(
      int degree, 
      const OdGeKnotVector& knots, 
      const OdGePoint2dArray& controlPoints, 
      const OdGeDoubleArray& weights,
      OdBool isPeriodic, 
      const OdGePoint2dArray& fitPoints,
      const OdGeVector2d& startTangent, 
      const OdGeVector2d& endTangent);
    
    void setKnotTolerance(double tol);

protected:
  friend class OdDbGeEdgesDwgIO;
  friend class OdDbGeEdgesDxfIO;

};

#include "../TD_PackPop.h"

#endif

