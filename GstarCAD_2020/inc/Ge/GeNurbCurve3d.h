/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2012, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2003-2012 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef OD_GENURB3D_H
#define OD_GENURB3D_H /* {Secret} */

class OdGeEllipArc3d;
class OdGeLineSeg3d;
class OdGePolyline3d;
class OdGeKnotVector;

#include "../Ge/GeSplineEnt3d.h"
#include "../OdPlatformSettings.h"

class OdGeNurbCurve3dImpl;

#include "../Ge/GeCurve3d.h"
#include "../Ge/GeInterval.h"
#include "../Ge/GeKnotVector.h"
#include "../Ge/GePoint3d.h"
#include "../Ge/GeVector3d.h"
#include "../Ge/GeSplineEnt3d.h"
#include "../Ge/GePolyline3d.h"
#include "../Ge/GeDoubleArray.h"
#include "../Ge/GePoint3dArray.h"
#include "../Ge/GeVector3dArray.h"
#include "../OdPlatformSettings.h"

#include "../TD_PackPush.h"

/**
    Description:
    This class represents non-uniform rational B-splines (NURBS) in 3D space.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeNurbCurve3d : public OdGeSplineEnt3d
{
public:


  /**
    Arguments:
    degree (I) Degree of spline.
    knots (I) Knot vector.
    controlPoints (I) Array of 3D control points.
    weights (I) Array of *weights*
    isPeriodic (I) True if and only if this spline is to be periodic.
    fitPoints (I) Interpolation points.
    fitTol (I) Geometric tolerance.
    ellipse (I) Any elliptical arc.
    numSpans (I) Number of knot spans in the *curve*.
    lineSeg (I) Any 3D line segment.
    startTangent (I) Starting tangent.
    endTangent (I) Ending tangent.
    startTangentDefined (I) If true, startTangent is used.
    endTangentDefined (I) If true, endTangent is used.
    source (I) Object to be cloned.
    numControlPoints (I) Number of control points.
    numWeights (I) Number of weights.
    
    Remarks:
    o If weights is not specified, a non-rational spline is constructed. 
    o If weights is specified, then a rational spline is constructed, and controlPoints.length() must equal weights.length()
    o If isPeriodic is false, then knots.length() must equal controlPoints.length() + degree + 1
    o If isPeriodic is true, then knots.length() must equal controlPoints.length(), the first and last controlPoints must be equal
      and the first and last weights (if provided) must be equal.
    o If ellipse is specified, a curve identical to the ellipse is created.
    o If lineSeg is specified, a curve identical to the line segment is created.
  */
  OdGeNurbCurve3d();
  OdGeNurbCurve3d(
    const OdGeNurbCurve3d& source);
  OdGeNurbCurve3d(OdGeNurbCurve3dImpl* impl);
  OdGeNurbCurve3d(
    int degree,
    const OdGeKnotVector& knots,
    const OdGePoint3dArray& controlPoints,
	OdBool isPeriodic = kFalse);

  OdGeNurbCurve3d(int degree, 
    const OdGePolyline3d& fitPolyline,
    OdBool isPeriodic = kFalse); 
  OdGeNurbCurve3d (
    int degree,
    const OdGeKnotVector& knots,
    const OdGePoint3dArray& controlPoints,
    const OdGeDoubleArray& weights,
	  OdBool isPeriodic = kFalse);
  // TD Special
  OdGeNurbCurve3d(
    const OdGePoint3dArray& fitPoints,
    const OdGeVector3d& startTangent,
    const OdGeVector3d& endTangent,
	OdBool startTangentDefined = kTrue,
	OdBool endTangentDefined = kTrue,
    const OdGeTol& fitTol = OdGeContext::gTol);
  OdGeNurbCurve3d(
    const OdGePoint3dArray& fitPoints,
    const OdGeTol& fitTolerance = OdGeContext::gTol);
  OdGeNurbCurve3d(
    const OdGePoint3dArray& fitPoints,
    const OdGeVector3dArray& fitTangents,
    const OdGeTol& fitTolerance = OdGeContext::gTol,
    OdBool isPeriodic = false);

  OdGeNurbCurve3d(
    const OdGeEllipArc3d& ellipse);

  OdGeNurbCurve3d(
    const OdGeLineSeg3d& lineSeg);

  // TD Special
  OdGeNurbCurve3d(
    const OdGePoint3d &basePoint,
    const OdGePoint3d &startPoint,
    const OdGeVector3d &axis,
    const double baseRadius,
    const double topRadius,
    bool handness,
    const double turns,
    const double height
    );

  /**
    Description:
    Returns the number of fit points.
  */
   int numFitPoints() const;

  /**
    Description:
    Gets the knot parametrization of the spline created with fit points and returns true if successful.

    Arguments:
    knotParam (O) Receives the knot parametrization.
  */
   OdBool getFitKnotParameterization(OdGeKnotParameterization& knotParam) const;

  /**
    Description:
    Returns true if and only if  0 <= index < numFitPoints(),
    and returns the fit *point* at the specified index.

    Arguments:
    fitPointIndex (I) Fit *point* *index*.
    point (O) Receives the fit *point*. 
  */
  OdBool getFitPointAt (
    int fitPointIndex, 
    OdGePoint3d& point) const;

  /** 
    Description:
    Returns true if and only if this spline was constructed
    with fit points, and returns the fit Tolerance that was
    used to construct this spline.
    
    Arguments:
    fitTolerance (I) Geometric tolerance.
 */
  OdBool getFitTolerance (
    OdGeTol& fitTolerance) const;

  /**
    Descripton:
    Returns true if and only if this spline was constructed with fit data, and
    returns the starting and ending tangents.
    
    Arguments:
    startTangent (O) Receives the starting tangent
    endTangent (O) Receives the ending tangent.
    startTangentDefined (O) Receives the if true, startTangent was used.
    endTangentDefined (O) Receives the if true, endTangent was used.
  */
  OdBool getFitTangents (
    OdGeVector3d& startTangent,
    OdGeVector3d& endTangent) const;
  OdBool getFitTangents (
    OdGeVector3d& startTangent,
    OdGeVector3d& endTangent,
    OdBool& startTangentDefined,
    OdBool& endTangentDefined) const;

  /**
    Description:
    Returns true if and only if this spline was constructed with fit data,
    and returns all the fit data used to construct this spline.
    
    Arguments:
    fitPoints (O) Receives the onterpolation points.
    fitTolerance (O) Receives the geometric tolerance.
    tangentsExist (O) Receives true if and only if tangents were used in constructing this spline.
    startTangent (O) Receives the starting tangent
    endTangent (O) Receives the ending tangent.
 
    Remarks:
    startTangent and endTangent are meaningful if and only if tangentsExist == true.
  */
  OdBool getFitData (
    OdGePoint3dArray& fitPoints,
    OdGeTol& fitTolerance,
    OdBool& tangentsExist,
    OdGeVector3d& startTangent,
    OdGeVector3d& endTangent) const;

  // NURBS data query functions

  /**
    Description:
    Returns the data used to define this spline.

    Arguments:
    degree (O) Receives the degree of spline.
    periodic (O) Receives true if and only if this spline is *periodic*.
    rational (O) Receives true if and only if this spline is *rational*.
    knots (O) Receives the knot vector.
    controlPoints (O) Receives an array of 3D control points.
    weights (O) Receives an array of *weights*
    
    Remarks:
    The weights array will be empty if the spline is not *rational*.
  */
   void getDefinitionData(
    int& degree,
    OdBool& rational,
    OdBool& periodic,
    OdGeKnotVector& knots,
    OdGePoint3dArray& controlPoints,
    OdGeDoubleArray& weights) const;

  /**
    Description:
    Returns the number of weights in the spline.
    
    Remarks:
    Feturns numCurves() if this spline is rational, 0 if it is not.
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

  /**
    Note:
    By default this function throws exception "not Implemented".
  */
   OdBool evalMode() const;
   OdBool getParamsOfC1Discontinuity(
    OdGeDoubleArray& params,
    const OdGeTol& tol = OdGeContext::gTol) const;
   OdBool getParamsOfG1Discontinuity(
    OdGeDoubleArray& params,
    const OdGeTol& tol = OdGeContext::gTol) const;

  // Fit data edit functions

  /**
    Description:
    Sets the fit *point* at the specified index.

    Arguments:
    fitPointIndex (I) Fit *point* *index*.
    point (I) Fit *point*. 
  */
   OdBool setFitPointAt(
    int fitPointIndex, 
    const OdGePoint3d& point);

  /**
    Description:
    Returns true if and only if this spline was created with
    fit data, and inserts the fit *point* at the specified index.

    Arguments:
    fitPointIndex (I) Fit *point* *index*.
    point (I) Fit *point*. 
  */
   OdBool addFitPointAt(
    int fitPointIndex, 
    const OdGePoint3d& point);
/**
    Description:
    Adds a control point at the specified knot.
    
    Arguments:
    newKnot (I) The knot parameter to add the control point at.
    point (I) Coordinates of the control point to be added.
    weight(I) The weight to be assigned to the control point.
    
    Remarks:
    When called for a non-rational spline, weight is ignored.
	
	  Note:
    Returns true if the control point has successfully been added and false otherwise.
  */
   OdBool addControlPointAt(double newKnot, const OdGePoint3d& point, double weight = 1.0);

  /**
    Description:
    Deletes a control point at the specified index.
    
    Arguments:
    index (I) The index of the control point to be deleted.
	
	  Note:
    Returns true if the control point has successfully been deleted and false otherwise.
   */
   OdBool deleteControlPointAt(int index);

  /**
    Description:
    Deletes the fit *point* at the specified index.

    Arguments:
    fitPointIndex (I) Fit *point* *index*.
  */
   OdBool deleteFitPointAt(
    int fitPointIndex);
 /**
    Description:
    Sets the specified knot parameterization if the spline is created by fit points and returns true if the knot parameterization has successfully been set.

    Arguments:
    knotParam (I) The knot parameterization to be set.
   */
   OdBool setFitKnotParameterization(OdGeKnotParameterization knotParam);
  /**
    Description:
    Sets the fit tolerance for this spline.
    
    Arguments:
    fitTol (I) Geometric tolerance.
  */
   OdBool setFitTolerance(
    const OdGeTol& fitTol = OdGeContext::gTol);

  /**
    Description:
    Sets the fit tangents for this spline.
    
    Arguments:
     startTangent (I) Starting tangent.
     endTangent (I) Ending tangent.
  */
   OdBool setFitTangents(
    const OdGeVector3d& startTangent,
    const OdGeVector3d& endTangent);
   OdBool setFitTangents(
    const OdGeVector3d& startTangent,
    const OdGeVector3d& endTangent,
    OdBool startTangentDefined,
    OdBool endTangentDefined);

  /**
    Sets the fit data for this spline.
    
    Arguments:
    fitPoints (I) Interpolation points.
    fitTol (I) Geometric tolerance.
    startTangent (I) Starting tangent.
    endTangent (I) Ending tangent.
  */
  OdGeNurbCurve3d& setFitData(
    const OdGePoint3dArray& fitPoints,
    const OdGeVector3d& startTangent,
    const OdGeVector3d& endTangent,
    const OdGeTol& fitTol = OdGeContext::gTol);

   OdGeNurbCurve3d& setFitData(
    const OdGeKnotVector& fitKnots,
    const OdGePoint3dArray& fitPoints,
    const OdGeVector3d& startTangent,
    const OdGeVector3d& endTangent,
    const OdGeTol& fitTol = OdGeContext::gTol,
    OdBool isPeriodic = false);
   OdGeNurbCurve3d& setFitData(
    int degree,
    const OdGePoint3dArray& fitPoints,
    const OdGeTol& fitTol = OdGeContext::gTol);

   // TD Special
   OdGeNurbCurve3d& setHelixData(
     const OdGePoint3d &basePoint,
     const OdGePoint3d &startPoint,
     const OdGeVector3d &axis,
     const double baseRadius,
     const double topRadius,
     bool handness,
     const double turns,
     const double height

     );

  /**
    Description:
    Returns the geometric *extents* of this elliptical arc.

    Arguments:
    extents (O) Receives the geometric *extents*.
  */
  void getGeomExtents(
    OdGeExtents3d& extents, double fitTol) const ;

  /**
    Description:
    Purges the fit data defining this spline.
    
    Remarks:
    The fit data consists of the fit points, fit tolerance,
    *start* tangent, and *end* tangent.
  */
  OdBool purgeFitData ();

  OdBool updateFitData();

  /**
    Note:
    By default this function throws exception "not Implemented".
  */
   OdGeNurbCurve3d& addKnot(double newKnot);
   OdGeNurbCurve3d& insertKnot(double newKnot);

  /**
    Description:
    Sets the *weight* at the specified index.

    Arguments:
    fitPointIndex (I) Fit *point* *index*.
    weight (I) Weight at the specified fit *point*. 
  */
   OdGeSplineEnt3d& setWeightAt(
    int fitPointIndex, 
    double weight);

  /**
    Note:
    By default this function throws exception "not Implemented".
  */
   OdGeNurbCurve3d& setEvalMode(
    OdBool evalMode = kFalse);
   OdGeNurbCurve3d& joinWith(
    const OdGeNurbCurve3d& curve);
   OdGeNurbCurve3d& hardTrimByParams(
    double newStartParam,
    double newEndParam);

  /**
    Arguments:
    Makes this spline rational (if it is not), and returns a reference to this spline.
    
    Arguments:
    weight (I) Weight to be applied to each control *point*. 
    
    Remarks:
    If this spline was already rational, the *weight* at each control point is multiplied by the
    specified weight.
  */
   OdGeNurbCurve3d& makeRational(
    double weight = 1.0);

  /**
    Note:
    By default this function throws exception "not Implemented".
  */
   OdGeNurbCurve3d& makeClosed();
   OdGeNurbCurve3d& makePeriodic();
   OdGeNurbCurve3d& makeNonPeriodic();
   OdGeNurbCurve3d& makeOpen();
   OdGeNurbCurve3d& elevateDegree(int plusDegree);

  // Assignment operator.
  OdGeNurbCurve3d& operator =(
    const OdGeNurbCurve3d& spline);

  ///////////////////////////////////////////////////////////////////////////
  // TD Special :

  TD_USING(OdGeSplineEnt3d::evalPoint);

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
    const OdGePoint3dArray& controlPoints,
    const OdGeDoubleArray& weights,
	OdBool isPeriodic = kFalse);

   OdGeNurbCurve3d(
     int degree,
     const OdGeKnotVector& knots,
     const OdGePoint3d* controlPoints,
     OdUInt32 numControlPoints,
     const double* weights,
     OdUInt32 numWeights,
     OdBool isPeriodic = kFalse);

	/**
    Description:
    Calculates fit data for the spline constructed by control points. 
        
    Remarks:
    Currently the method calculates fit data only for NURB curves of degree less than or equal to three.  

    Note:
    Returns true if and only if fit data have successfully been calculated.
  */
   OdBool buildFitData(OdGeKnotParameterization knotParam = OdGe::kChord);
protected:
   /**
    Description:
    Modifies the position and tangent of the point with a specified parameter.

    Arguments:
    param (I) Parameter value of the point.
    point (I) New position of the point.
    deriv (I) New value of the tangent vector at the point.
           
    Note:
    Returns true if and only if the point has successfully been adjusted.
  */
   OdBool modifyPositionAndTangent(double param, const OdGePoint3d& point, const OdGeVector3d* deriv);
   void makeClosedFit();
  void setData(int degree, const OdGePoint3dArray& controlPoints, const OdGeKnotVector& knots, const OdGeDoubleArray& weights
    , const OdGePoint3dArray& fitPoints, const OdGeVector3d& startTangent, const OdGeVector3d& endTangent
    , bool isStartTangentDefined, bool isEndTangentDefined, bool isPeriodic, const OdGeTol& fitTol);

   void setKnotTolerance(double tol);
};

#include "../TD_PackPop.h"

#endif // OD_GENURB3D_H

